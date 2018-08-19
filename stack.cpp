#include "define.h"

void stack_demo()
{
	stack* s = new stack();
	const int len = 10;

	for(int i = 0; i < len; ++i)
	{
		int val = rand()%100;
		s->push(val);
		cout<<val<<" ";
	}
	cout<<endl;

	for(int i = 0; i < len; ++i)
	{
		cout<<s->pop()<<" ";
	}
	cout<<endl;

	delete s;
	s = nullptr;
}

sl_node *stack::new_node(val_type data)
{
	return new sl_node(data);
}

bool stack::is_empty()
{
	return _list == nullptr;
}

void stack::push(val_type data)
{
	if(is_empty())
		_list = new_node(data);
	else
	{
		sl_node *tail = get_tail(_list);
		tail->_next = new_node(data);
	}
}

val_type stack::pop()
{
	if(is_empty())
		return INT_MIN;

	sl_node *tail = get_tail(_list);
	val_type ret = tail->_val;
	sl_node *bef_tail = find_prev_node(_list, tail);

	if(bef_tail == nullptr)
	{
		delete _list;
		_list = nullptr;
	}
	else
	{
		delete tail;
		tail = nullptr;
		bef_tail->_next = nullptr;
	}

	return ret;
}

val_type stack::peek()
{
	if(is_empty())
		return INT_MIN;
	else
		return get_tail(_list)->_val;

}