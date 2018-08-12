#ifndef INC_SORT_METHODS
#define INC_SORT_METHODS

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
using std::cout;
using std::endl;
using std::string;
using std::pair;
using std::make_pair;
using std::priority_queue;
using std::vector;

typedef double F;
typedef int I;
typedef std::vector<F> ARR_1D_F;

void normalize(F*& arr, const int len); //to [0,1]
void bucket_sort(F*& arr, const int len);
void cocktail_sort(F*& arr, const int len);
void count_sort(I*& arr, I*& count, I low, I up, const int len);
void merge_sort(F*& arr, int low, int up);
string frequency_sort(string str);

template<typename X>
void print(X* arr, int len)
{
	int ix = 0;
	while(len--)
	{
		cout<<"["<<ix<<"] "<<arr[ix]<<endl;
		++ix;
	}
}

#endif