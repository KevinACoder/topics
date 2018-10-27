#include <iostream>
#include "defines.h"
#include "../topics_config.h"

extern void date_demo();
extern void date_time_demo();
extern void scope_ptr_demo();
extern void shared_ptr_demo();
extern void weak_ptr_demo();
extern void mem_pool_demo();
int main()
{
	cout<<"ok"<<endl;
	cout<<"sw version"<<TOPICS_VERSION_MAJOR<<"."<<TOPICS_VERSION_MINOR<<endl;
	
	//date_demo();
	//date_time_demo();
	//scope_ptr_demo();
	//shared_ptr_demo();
	//weak_ptr_demo();
	mem_pool_demo();
	return 0;
}