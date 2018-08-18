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
	cout<<"len: "<<tmp_len<<endl;
	cout<<"element 32 "<<(search_list_recursive(head, 32)?"exist":"not exist")<<endl;
	/*while(count++ < tmp_len)
	{
		head = del_by_pos(head, 0);
	}*/
	cout<<"the 3rd node is "<<(get_the_nth_node(head, 3)->_val)<<endl;
	cout<<"the last 4th node is "<<(get_the_nth_node_from_tail(head, 4)->_val)<<endl;
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