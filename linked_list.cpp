#include "define.h"

void linked_list_demo()
{
	sl_node *head = nullptr;
	const int len = 10;
	int count = 0;
	while(count++ < len)
	{
		head = sorted_insert(head, rand()%100);
	}
	print_list(head);

	head = del_by_key(head, head->_next->_val);
	print_list(head);
	count = 0;
	int tmp_len = get_length_recursive(head);
	cout<<"aft reverse"<<endl;
	head = rev_list(head);
	print_list(head);
	sl_node *head2 = cp_list(head);
	cout<<"copy a new list"<<endl;
	print_list(head2);
	head2 = rm_duplicate_node(head2);
	cout<<"remove duplicate node"<<endl;
	print_list(head2);
	cout<<"len: "<<tmp_len<<endl;
	cout<<"element 32 "<<(search_list_recursive(head, 32)?"exist":"not exist")<<endl;
	/*while(count++ < tmp_len)
	{
		head = del_by_pos(head, 0);
	}*/
	cout<<"the 3rd node is "<<(get_the_nth_node(head, 3)->_val)<<endl;
	cout<<"the last 4th node is "<<(get_the_nth_node_from_tail(head, 4)->_val)<<endl;
	cout<<"the mid node is "<<(get_mid_node(head)->_val)<<endl;
	cout<<"is list palindrome: "<<(is_list_palindrome2(head)?"Yes":"No")<<endl;
	swap_nodes(&head, head, head->_next->_next);
	cout<<"aft swap list"<<endl;
	print_list(head);
	del_list(&head);
	print_list(head);
	del_list(&head);

}

sl_node *sorted_insert(sl_node *head, val_type data)
{
	sl_node dummy(INT_MIN);
	dummy._next = head; //a dummy head, which merge case 1, 2, 3

	sl_node *curr = dummy._next;
	sl_node *prev = &dummy;

	//case 1: add at the front
	//case 2: add at middle
	//case 3: add at tail
	while(curr && curr->_val < data)
	{
		prev = curr;
		curr = curr->_next;
	}

	sl_node *nn = new sl_node(data);
	prev->_next = nn;
	nn->_next = curr;

	return dummy._next;
}

void print_list(sl_node *head)
{
	while(head)
	{
		cout<<head->_val<<" ";
		head = head->_next;
	}
	cout<<endl;
}

sl_node *del_by_key(sl_node *head, val_type key)
{
	sl_node dummy(INT_MIN);
	dummy._next = head;
	sl_node *curr = head;
	sl_node *prev = &dummy;

	while(curr && curr->_val != key)
	{
		prev = curr;
		curr = curr->_next;
	}

	if(curr)
	{
		prev->_next = curr->_next;
		delete curr;
		curr = nullptr;
	}

	return dummy._next;
}

sl_node *del_by_pos(sl_node *head, int pos)
{
	sl_node dummy(INT_MIN);
	dummy._next = head;	
	sl_node *curr = head;
	sl_node *prev = &dummy;

	while(curr && pos--)
	{
		prev = curr;
		curr = curr->_next;
	}

	if(curr)
	{
		prev->_next = curr->_next;
		delete curr;
		curr = nullptr;
	}

	return dummy._next;
}

int get_length(sl_node *head)
{
	int len = 0;
	while(head)
	{
		head = head->_next;
		len++;
	}
	return len;
}

void del_list(sl_node **head_ref)
{
	if(head_ref == nullptr || *head_ref == nullptr)
		return;

	sl_node dummy(INT_MIN);
	dummy._next = *head_ref;

	sl_node *curr = *head_ref;
	sl_node *next = nullptr;

	while(curr)
	{
		next = curr->_next;
		delete curr;
		curr = next;
	}

	*head_ref = nullptr;
}

int get_length_recursive(sl_node *head)
{
	if(head == nullptr)
		return 0;
	else
		return get_length_recursive(head->_next) + 1;
}

bool search_list_recursive(sl_node *head, val_type key)
{
	if(head == nullptr)
		return false;
	else 
		return head->_val == key ? true : search_list_recursive(head->_next, key);

}

sl_node *get_the_nth_node(sl_node *head, int n)
{
	while(head && n--)
		head = head->_next;

	return head;
}

sl_node *get_the_nth_node_from_tail(sl_node *head, int n)
{
	sl_node *slow = head;
	sl_node *fast = head;

	while(fast && n--)
		fast = fast->_next;

	if(!fast)
		return nullptr;
	else
	{
		while(fast)
		{
			slow = slow->_next;
			fast = fast->_next;
		}
	}
	return slow;
}

sl_node *get_mid_node(sl_node *head)
{
	sl_node *slow = head;
	sl_node *fast = head;

	while(fast && fast->_next)
	{
		slow = slow->_next;
		fast = fast->_next->_next;
	}

	return slow;
}

sl_node *rev_list(sl_node *head)
{
	if(head == nullptr || head->_next == nullptr)
		return head;

	sl_node *curr = head;
	sl_node *next = nullptr;
	sl_node *prev = nullptr;

	while(curr)
	{
		next = curr->_next; //store next node
		curr->_next = prev; //reverse link
		prev = curr; //move backward
		curr = next;
	}

	return prev;
}

sl_node *cp_list(sl_node *head)
{
	if(head == nullptr)
		return nullptr;

	sl_node *nhead = nullptr;
	nhead = new sl_node(head->_val);
	head = head->_next;
	sl_node *curr = nhead;
	while(head)
	{
		//nhead = sorted_insert(nhead, head->_val);
		curr->_next = new sl_node(head->_val);
		curr = curr->_next;
		head = head->_next;
	}

	return nhead;
}

sl_node *find_prev_node(sl_node *head, sl_node *target)
{
	while(head && head->_next != target)
		head = head->_next;

	if(head == nullptr)
		return nullptr;
	else
		return head;
}

bool is_list_palindrome(sl_node *head)
{
	if(head == nullptr || head->_next == nullptr)
		return true;

	sl_node *nhead = cp_list(head);
	sl_node *mid = get_mid_node(nhead);
	sl_node *bef_mid = find_prev_node(nhead, mid);
	mid = rev_list(mid);
	if(bef_mid != nullptr)
		bef_mid->_next = mid;

	sl_node *first_half = head;
	sl_node *second_half = mid;
	while(first_half && second_half)
	{
		if(first_half->_val != second_half->_val)
		{
			del_list(&nhead);
			return false;
		}

		first_half = first_half->_next;
		second_half = second_half->_next;
	}

	del_list(&nhead);
	return true;
}

bool is_list_palindrome2(sl_node *head)
{
	if(head == nullptr || head->_next == nullptr)
		return true;

	sl_node* nhead = cp_list(head);
	nhead = rev_list(nhead);
	sl_node* second = nhead;
	sl_node* first = head;
	while(first && second)
	{
		if(first->_val != second->_val)
		{
			del_list(&nhead);
			return false;
		}

		first = first->_next;
		second = second->_next;
	}

	del_list(&nhead);
	return true;
}

sl_node *rm_duplicate_node(sl_node *head)
{
	if(head == nullptr || head->_next == nullptr)
		return head;

	sl_node *curr = head;
	sl_node *next = nullptr;
	sl_node *next_next = nullptr;

	while(curr->_next)
	{
		next = curr->_next;
		next_next = curr->_next->_next;

		if(next_next && next->_val == next_next->_val)
		{
			curr->_next = next_next;
			delete next;
			next = nullptr;
		}

		curr = curr->_next;
	}

	return head;
}

bool node_exist(sl_node *head, sl_node *node)
{
	if(node == nullptr)
		return false;

	while(head && head->_val != node->_val)
		head = head->_next;

	return head == nullptr ? false : true;
}

void swap_nodes(sl_node **head_ref, sl_node *node1, sl_node *node2)
{
	if(head_ref == nullptr || *head_ref == nullptr || (*head_ref)->_next == nullptr 
		|| node1 == node2)
		return;

	if(!node_exist(*head_ref, node1) || !node_exist(*head_ref, node2))
		return;

	sl_node *bef_node1 = find_prev_node(*head_ref, node1);
	sl_node *bef_node2 = find_prev_node(*head_ref, node2);
	sl_node *aft_node1 = node1->_next;
	sl_node *aft_node2 = node2->_next;

	if(bef_node1 && bef_node2)
	{
		bef_node1->_next = node2;
		node2->_next = aft_node1;

		bef_node2->_next = node1;
		node1->_next = aft_node2;
	}
	else if(!bef_node1 && bef_node2)
	{
		bef_node2->_next = node1;
		node1->_next = aft_node2;

		*head_ref = node2;
		node2->_next = aft_node1;
	}
	else
	{
		bef_node1->_next = node2;
		node2->_next = aft_node1;

		*head_ref = node1;
		node1->_next = aft_node2;
	}
}

sl_node *get_tail(sl_node *head)
{
	if(head == nullptr)
		return head;

	while(head->_next)
		head = head->_next;

	return head;
}