#include "define.h"

template<typename X>
void print(X* arr, int len)
{
	int ix = 0;
	while(len--)
	{
		cout<<"["<<ix<<"] "<<arr[ix]<<endl;
		++ix;
	}
	cout<<endl;
}

void sort_demo()
{
	/*int test_time = 1;
	const int test_len = 100;

	while(test_time-->0)
	{
		val_type* arr = new val_type[test_len];
		for(int i = 0; i < test_len; ++i)
		{
			arr[i] = ((val_type)rand()/RAND_MAX);
		}

		//normalize(arr, test_len);
		//bucket_sort(arr, test_len);
		//merge_sort(arr, 0, test_len-1);
		bst_sort(arr, test_len);
		print(arr, test_len);

		string raw_text = "asdcfedstfgtsdasedvgf";
		string sort_text = frequency_sort(raw_text);
		printf("sorted: %s\n", sort_text.c_str());
	}*/

	const int len = 10;
	val_type arr[len] = {10};
	for(int i = 0; i < len; ++i)
	{
		arr[i] = rand()%100;
	}
	print(arr, len);
	//bubble_sort(arr, len);
	//selection_sort(arr, len);
	//insert_sort(arr, len);
	//quick_sort(arr, 0, len-1);
	merge_sort(arr, 0, len-1);
	print(arr, len);
}

template<typename M>
void swap(M &a, M &b)
{
	M tmp = a;
	a = b;
	b = tmp;
}

void cocktail_sort(val_type*& arr, const int len)
{
	if(nullptr == arr)
		return;

	bool swapped = true;
	int start = 0;
	int end = len - 1;
	val_type*& a = arr;

	while (swapped) 
	{
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

//https://www.geeksforgeeks.org/bucket-sort-2/
void bucket_sort(val_type*& arr, const int n)
{
	if(nullptr == arr)
		return;

    // 1) Create n empty buckets
    std::vector<double> b[n];
    
    // 2) Put array elements in different buckets
    for (int i=0; i<n; i++)
    {
       int bi = n*arr[i]; // Index in bucket
       b[bi].push_back(arr[i]);
    }
 
    // 3) Sort individual buckets
    for (int i=0; i<n; i++)
       std::sort(b[i].begin(), b[i].end());
 
    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (size_t i = 0; i < (size_t)n; i++)
        for (size_t j = 0; j < b[i].size(); j++)
          arr[index++] = b[i][j];

}


string frequency_sort(string str)
{
	string result;
	if(str.size() < 2)
		return str;

	const int arr_len = 256;
	vector<int> char_cnt(arr_len, 0);
	priority_queue<pair<int, char>> pq;

	for(auto s : str)
	{
		//char_cnt[(int)str[i]]++;
		char_cnt[(int)s]++;
	}

	for(int i = 0; i < arr_len; ++i)
	{
		if(char_cnt[i] > 0)
			pq.push(make_pair(char_cnt[i], (char)i));
	}

	while(!pq.empty())
	{
		pair<int, char> cnt_pair = pq.top();
		//num of char , char
		result.append(cnt_pair.first, cnt_pair.second);
		pq.pop();
	}

	return result;

}

void merge(val_type arr[], int low, int middle, int up)
{
	int len1 = middle - low + 1;
	int len2 = up - middle;
	val_type first_half[len1], second_half[len2];

	for(int i = 0; i < len1; ++i)
		first_half[i] = arr[low + i];

	for(int i = 0; i < len2; ++i)
		second_half[i] = arr[middle + 1 + i];

	int i = 0, j = 0, k = low; //ix to first_half, second_half and whole array

	while(i < len1 && j < len2)//both halves exist
	{
		if(first_half[i] <= second_half[j])
		{
			arr[k] = first_half[i];
			++i;
		}
		else
		{
			arr[k] = second_half[j];
			++j;
		}
		++k;
	}

	while(i < len1)
	{
		arr[k] = first_half[i];
		++i;
		++k;
	}

	while(j < len2)
	{
		arr[k] = second_half[j];
		++j;
		++k;
	}
}

void merge_sort(val_type arr[], int low, int up)
{
	if(low < up)
	{
		int middle = low + (up-low)/2;

		merge_sort(arr, low, middle);
		merge_sort(arr, middle+1, up);

		merge(arr, low, middle, up);
	}

}

bst_node* insert_bst(bst_node *root, val_type key)
{
	if(nullptr == root)
		root = new bst_node(key);
	else if(key < root->_val)
		root->_left = insert_bst(root->_left, key);
	else
		root->_right = insert_bst(root->_right, key);

	return root;
}

void inorder_visit(bst_node *root, val_type*& arr, int& ix)
{
	if(root == nullptr)
		return;

	inorder_visit(root->_left, arr, ix);
	arr[ix] = root->_val;
	++ix;
	inorder_visit(root->_right, arr, ix);
}

void bst_sort(val_type*& arr, const int len)
{
	bst_node *root = nullptr;
	for(int i = 0; i < len; ++i)
	{
		root = insert_bst(root, arr[i]);
	}

	int ix = 0;
	inorder_visit(root, arr, ix);
}

void bubble_sort(val_type arr[], const int len)
{
	for(int i = 0; i < len - 1; ++i)
		for(int j = 0; j < len - i - 1; ++j)//reduce unsorted region by i
		{
			if(arr[j] > arr[j+1]) //!!
				swap(arr[j], arr[j+1]);
		}
}

void selection_sort(val_type arr[], const int len)
{
	for(int i = 0; i < len-1; ++i) //0...len-1, sorted region is 0 at start
	{
		int min_ix = i; //find the min index
		for(int j = i+1; j < len; ++j)//1...len
		{
			if(arr[j] < arr[min_ix])
				min_ix = j;
		}

		swap(arr[min_ix], arr[i]);
	}
}

void insert_sort(val_type arr[], const int len)
{
	int val = INT_MIN;
	for(int i = 1; i < len; ++i)
	{
		val = arr[i];

		int j = i-1;
		while(j >= 0 && arr[j] > arr[j+1])
		{
			swap(arr[j], arr[j+1]);
			--j;
		}

		arr[j] = val;
	}

}

void quick_sort(val_type arr[], int low, int high)
{
	if(low < high)
	{
		int pi = partition(arr, low, high);

		quick_sort(arr, low, pi-1);
		quick_sort(arr, pi+1, high);
	}
}

int partition(val_type arr[], int low, int high)
{
  int pivot = arr[high];    // pivot
  int i = low-1;  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}