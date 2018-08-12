#include "../inc/sort_methods.h"
#include <time.h>


int main(int argc, char const *argv[])
{
	/* code */
	srand(time(NULL));
	int test_time = 1;
	const int test_len = 100;

	while(test_time-->0)
	{
		F* arr = new F[test_len];
		for(int i = 0; i < test_len; ++i)
		{
			arr[i] = ((F)rand()/RAND_MAX);
		}

		//normalize(arr, test_len);
		//bucket_sort(arr, test_len);
		merge_sort(arr, 0, test_len-1);
		print(arr, test_len);

		string raw_text = "asdcfedstfgtsdasedvgf";
		string sort_text = frequency_sort(raw_text);
		printf("sorted: %s\n", sort_text.c_str());
	}

	return 0;
}