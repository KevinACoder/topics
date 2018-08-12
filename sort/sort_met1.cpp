#include <iostream>
#include <time.h>

class sort_method;
typedef int T;
using std::cout;
using std::endl;
using std::ostream;

struct list_node
{
	T _val;
	list_node *_next;
	list_node(T x):_val(x),_next(nullptr){}
};

void release_list(list_node *head)
{
	if(nullptr == head) 
		return;
	else if(head->_next == nullptr) //base condition
	{
		delete head;
		head = nullptr;
		return;
	}
	else
		return release_list(head->_next);
}

size_t get_len_of_list(list_node *head)
{
	size_t len = 0;
	while(nullptr != head)
	{
		++len;
		head = head->_next;
	}
	return len;
}

template<typename M>
void safe_create(M*& ptr, const size_t len)
{
	if(nullptr != ptr)
	{
		delete[] ptr;
		ptr = nullptr;
	}

	ptr = new M[len];
}

template<typename M>
void safe_destory(M*& ptr)
{
	if(nullptr != ptr)
	{
		delete[] ptr;
		ptr = nullptr;
	}
}

template<typename M>
M* copy_array(const M* src_arr, const size_t len)//do not use return reference
{
	M *dst_src = nullptr; 
	if(src_arr != nullptr)
	{
		dst_src = new M[len];
		for(size_t i = 0; i < len; ++i)
		{
			dst_src[i] = src_arr[i];
		}
	}
	return dst_src;
}

template<typename M>
void swap(M &a, M &b)
{
	M tmp = a;
	a = b;
	b = tmp;
}

class sort_method
{
public:
	sort_method()
	:_raw_arr(nullptr), _sorted_arr(nullptr), _raw_list_h(nullptr){}
	sort_method(const T *raw, const size_t size)
	:_raw_arr(nullptr),_sorted_arr(nullptr), _raw_list_h(nullptr)
	{
		_raw_arr = new T[size];
		_raw_arr[0] = *raw;
		_raw_list_h = new list_node(*raw);

		list_node *raw_node = _raw_list_h;
		for(size_t i = 1; i < size; ++i)
		{
			_raw_arr[i] = *(raw + i);
			raw_node->_next = new list_node(*(raw+i)); 
			raw_node = raw_node->_next;
		}
	}
	sort_method(const sort_method& sm)
	:_raw_arr(nullptr),_sorted_arr(nullptr), _raw_list_h(nullptr)
	{
		if(&sm != this)
		{
			//release memory for pervious raw data
			if(this->_raw_arr != nullptr)
			{
				delete[] this->_raw_arr;
				this->_raw_arr = nullptr;
			}
			if(this->_raw_list_h != nullptr)
			{
				release_list(this->_raw_list_h);
			}
			//declare memory to copy
			size_t len = get_len_of_list(sm._raw_list_h);
			if(len > 0)
			{
				this->_raw_arr = new T[len];
				this->_raw_list_h = new list_node(*sm._raw_arr);
				this->_raw_arr[0] = *sm._raw_arr;
				this->_raw_list_h = new list_node(*sm._raw_arr);
				list_node *raw_node = _raw_list_h;
				for(size_t i = 1; i < len; ++i)
				{
					this->_raw_arr[i] = *(sm._raw_arr + i);
					raw_node->_next = new list_node(*(sm._raw_arr+i)); 
					raw_node = raw_node->_next;
				}
			}
		}
	}
	sort_method& operator= (const sort_method& sm)
	{
		if(&sm != this)
		{
			//release memory for pervious raw data
			if(this->_raw_arr != nullptr)
			{
				delete[] this->_raw_arr;
				this->_raw_arr = nullptr;
			}
			if(this->_raw_list_h != nullptr)
			{
				release_list(this->_raw_list_h);
			}
			//declare memory to copy
			size_t len = get_len_of_list(sm._raw_list_h);
			if(len > 0)
			{
				this->_raw_arr = new T[len];
				this->_raw_list_h = new list_node(*sm._raw_arr);
				this->_raw_arr[0] = *sm._raw_arr;
				this->_raw_list_h = new list_node(*sm._raw_arr);
				list_node *raw_node = _raw_list_h;
				for(size_t i = 1; i < len; ++i)
				{
					this->_raw_arr[i] = *(sm._raw_arr + i);
					raw_node->_next = new list_node(*(sm._raw_arr+i)); 
					raw_node = raw_node->_next;
				}
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream& os, const sort_method& sm);

	~sort_method()
	{
		if(nullptr != _raw_arr)
		{
			delete[] _raw_arr;
			_raw_arr = nullptr;
		}
		
		if(nullptr != _sorted_arr)
		{
			delete[] _sorted_arr;
			_sorted_arr = nullptr;
		}
		
		release_list(_raw_list_h);
	}

	T* bubble_sort()
	{
		size_t len = get_len_of_list(_raw_list_h);
		safe_destory(_sorted_arr);
		_sorted_arr = copy_array(_raw_arr, len);
		if(nullptr != _sorted_arr)
		{
			T* arr = _sorted_arr;
			T tmp;
			for(size_t i = 0; i < len - 1; ++i)
			{
				for(size_t j = 0; j < len - 1 - i; ++j)
				{
					if(arr[j] > arr[j+1])//if greater, exchange 
					{
						tmp = arr[j];
						arr[j] = arr[j+1];
						arr[j+1] = tmp; 
					}
				}
			}
		}

		return _sorted_arr;
	}

	T* cocktail_sort()//https://www.geeksforgeeks.org/cocktail-sort/
	{
		size_t n = get_len_of_list(_raw_list_h);
		safe_destory(_sorted_arr);
		_sorted_arr = copy_array(_raw_arr, n);
		T *a = _sorted_arr;
		if(nullptr != _sorted_arr)
		{
			bool swapped = true;
			int start = 0;
			int end = n - 1;

			while (swapped) {
		// reset the swapped flag on entering
		// the loop, because it might be true from
		// a previous iteration.
				swapped = false;

		// loop from left to right same as
		// the bubble sort
				for (int i = start; i < end; ++i) {
					if (a[i] > a[i + 1]) {
						swap(a[i], a[i + 1]);
						swapped = true;
					}
				}

		// if nothing moved, then array is sorted.
				if (!swapped)
					break;

		// otherwise, reset the swapped flag so that it
		// can be used in the next stage
				swapped = false;

		// move the end point back by one, because
		// item at the end is in its rightful spot
				--end;

		// from right to left, doing the
		// same comparison as in the previous stage
				for (int i = end - 1; i >= start; --i) {
					if (a[i] > a[i + 1]) {
						swap(a[i], a[i + 1]);
						swapped = true;
					}
				}

		// increase the starting point, because
		// the last stage would have moved the next
		// smallest number to its rightful spot.
				++start;
			}
		}

		return _sorted_arr;
	}
	
private:
	T         *_raw_arr;
	T         *_sorted_arr;
	list_node *_raw_list_h;  
};

ostream& operator<<(ostream& os, const sort_method& sm)
{
	size_t len = get_len_of_list(sm._raw_list_h);
	list_node *node = sm._raw_list_h;
	for(size_t i = 0; i < len && node != nullptr; ++i)
	{
		if(sm._sorted_arr == nullptr)
			os << "[" << i << "]: " << sm._raw_arr[i] <<" "
		<< node->_val << endl;
		else
			os << "[" << i << "]: " << sm._raw_arr[i] <<" "
		<< node->_val << " " << sm._sorted_arr[i] << endl;

		node = node->_next;
	}
	return os;
}

int main(int argc, char const *argv[])
{
	/* code */
	srand(time(NULL));
	cout<<"Start"<<endl;

	{
		const int len = 101;
		int* arr = new T[len];
		for(size_t i = 0; i < len; ++i)
		{
			arr[i] = rand() % 100 + 1;
		}

		sort_method sm(arr, len);
		sort_method sm2(sm);
		sort_method sm3 = sm2;
		//sm.bubble_sort();
		sm.cocktail_sort();
		cout << sm;
	}

	cout<<"Done"<<endl;
	return 0; 
}