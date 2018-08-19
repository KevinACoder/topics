#include "define.h"

void queue_demo()
{
	queue* q = new queue();
	const int len = 10;

	for(int i = 0; i < len; ++i)
	{
		int val = rand()%100;
		q->enqueue(val);
		cout<<val<<" ";
	}
	cout<<endl;

	for(int i = 0; i < len; ++i)
	{
		cout<<q->dequeue()<<" ";
	}
	cout<<endl;

	delete q;
	q = nullptr;
}

void queue::enqueue(val_type data)
{
	_stack_in.push(data);
}

val_type queue::dequeue()
{
	if(is_empty())
		return INT_MIN;
	
	val_type x;
	if(_stack_out.is_empty())
	{
		while(!_stack_in.is_empty())
		{
			x = _stack_in.pop();
			_stack_out.push(x);
		}
	}

	x = _stack_out.pop();
	return x;
}

bool queue::is_empty()
{
	return _stack_in.is_empty() && _stack_out.is_empty();
}