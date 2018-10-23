#include <stdlib.h>
#include "define.h"
//#include <boost/progress.hpp>
#include "progress_timer.hpp"

extern void data_structure_demo();

int main(int argc, char const *argv[])
{
	/* code */
	//boost::progress_timer pt;
	progress_timer_ex<10> pt;
	srand(time(NULL));
	//sort_demo();
	//linked_list_demo();
	//stack_demo();
	//queue_demo();
	//graph_demo();
	boost_demo();
	//data_structure_demo();
	return 0;
}