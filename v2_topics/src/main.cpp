#include <iostream>
#include "defines.h"
#include "../topics_config.h"

extern void date_demo();
extern void date_time_demo();
int main()
{
	cout<<"ok"<<endl;
	cout<<"sw version"<<TOPICS_VERSION_MAJOR<<"."<<TOPICS_VERSION_MINOR<<endl;
	
	//date_demo();
	date_time_demo();
	return 0;
}