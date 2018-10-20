#ifndef DATA_STRUCTURE_HPP_
#define DATA_STRUCTURE_HPP_

#include <iostream>

namespace data_structure
{
	template<typename x>
	struct list_node
	{
		x			_val;
		list_node	*_next;
		list_node	*_prev;

		list_node(const x &val):_val(val),_next(nullptr),_prev(nullptr)
		{}
	};

	template<typename x>
	struct bst_node
	{
		x			_val;
		bst_node	*_left;
		bst_node	*_right;

		bst_node(const x &val):_val(val),_left(nullptr),_right(nullptr)
		{}
	};

	template<typename x>
	class double_linked_list
	{
	public:
		double_linked_list() = default;
		~double_linked_list()
		{ release();}
		double_linked_list(const double_linked_list &lst) = delete;
		double_linked_list &operator=(const double_linked_list &lst) = delete;

		void insert_head(const x &val)
		{
			if(_head == nullptr){
				_head = alloc_node(val);
				_head->_prev = _head;
				_head->_next = _head;
			}else{
				list_node<x> *nn = alloc_node(val);
				list_node<x> *tail = _head->_prev;
				nn->_prev = tail;
				nn->_next = _head;
				tail->_next = nn;
				_head->_prev = nn;
				_head = nn; //replace head
			}
			++_num;
		}

		void insert_tail(const x &val)
		{
			if(_head == nullptr){
				_head = alloc_node(val);
				_head->_prev = _head;
				_head->_next = _head;
			}else{		
				list_node<x> *nn = alloc_node(val);
				list_node<x> *tail = _head->_prev;
				nn->_prev = tail;
				nn->_next = _head;
				tail->_next = nn;
				_head->_prev = nn;
			}
			++_num;
		}

		void release()
		{
			list_node<x> *curr = _head;
			while(curr != nullptr){
				curr = dealloc_node(curr);
				--_num;
			}
			_head = nullptr;
		}

		bool is_empty() const
		{
			if(_head == nullptr && _num == 0)
				return true;
			else
				return false;
		}

		friend std::ostream &operator<<(std::ostream &os, 
							const double_linked_list &lst)
		{
			list_node<x> *curr = lst._head;
			do
			{
				os<<curr->_val<<endl;
				curr = curr->_next;
			}while(curr != lst._head);
			return os;
		}

	private:
		list_node<x> *alloc_node(const x &val)
		{return new list_node<x>(val);}

		list_node<x> *dealloc_node(list_node<x> *cur)
		{
			if(cur->_next == cur){
				delete cur;
				cur = nullptr;
			}else{
				list_node<x> *nn = cur->_next;
				list_node<x> *prev = cur->_prev;
				prev->_next = nn;
				nn->_prev = prev;
				delete cur;
				cur = nn;
			}
			return cur;
		}		
	private:
		list_node<x> *_head = nullptr;
		size_t		  _num = 0;
	};

};

#endif