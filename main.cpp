#include <stdlib.h>
#include "define.h"
#include "data_structure.hpp"

void data_structure_demo()
{
	using namespace data_structure;
	using namespace std;

	//list_node<int> *node = new list_node<int>(3);
	//cout<<node->_val<<endl;

	double_linked_list<int> list;
	vector<int> v{1, 2, 3, 4};
	for(auto i : v){
		//list.insert_head(i);
		list.insert_tail(i);
	}
	cout<<list<<endl;
	//list.release();
	//cout<<(list.is_empty() ? "empty" : "is not empty")<<endl;
}

int main(int argc, char const *argv[])
{
	/* code */
	srand(time(NULL));
	//sort_demo();
	//linked_list_demo();
	//stack_demo();
	//queue_demo();
	//graph_demo();
	//boost_demo();
	data_structure_demo();
	return 0;
}