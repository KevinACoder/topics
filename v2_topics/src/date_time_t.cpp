#include "defines.h"
//dependices of date time
#define BOOST_DATE_TIME_SOURCE
/*#include <libs/date_time/src/gregorian/greg_names.hpp>
#include <libs/date_time/src/gregorian/date_generators.cpp>
#include <libs/date_time/src/gregorian/greg_month.cpp>
#include <libs/date_time/src/gregorian/greg_weekday.cpp>
#include <libs/date_time/src/gregorian/gregorian_types.cpp>*/
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::gregorian;

void date_demo()
{
	//create a date
	date d1(2018, 1, 1);
	printf("%d-%d-%d %d\n", d1.year(), d1.month(),
		d1.day(), d1.week_number());

	//calc current date
 	cout<<day_clock::local_day() <<endl;
	date d2 = day_clock::local_day();
	d2 += days(10);
	if(!d2.is_not_a_date()){
		cout<<d2<<endl;
	}

	//date period
	date_period dp1(d1, d2);
	date_period dp2(day_clock::local_day() - days(10), day_clock::local_day());
	if(!dp1.is_null()){
		cout<<"begin: "<<dp1.begin()<<endl;
		cout<<"last: "<<dp1.last()<<endl;
		cout<<"length: "<<dp1.length().days()<<endl;
	}
	if(dp1.contains(dp2)){
		cout<<dp1<<" contains "<<dp2<<endl;
		cout<<dp1.intersection(dp2)<<endl;
	}

	//day iter
	date d3(day_clock::local_day() - days(10));
	day_iterator itd(d3);
	int count = 0;
	while(*itd < day_clock::local_day()){
		cout<<"day"<<(++count)<<*itd<<endl;
		++itd;
	}
}

#define BOOST_DATE_TIME_STD_CONFIG
using namespace boost::posix_time;
void date_time_demo()
{
	//time span
	time_duration td1(1, 10, 0, 0);	
	time_duration td2 = hours(1) + minutes(10);
	time_duration td3 = duration_from_string("1:10:00:000");
	if(td1.resolution() == boost::date_time::nano){
		cout<<"nano clock"<<endl;
	}else{
		cout<<"micro clock"<<endl;
	}

	if(!td3.is_not_a_date_time() && td1 == td2 && td2 == td3){
		cout<<td1<<endl;
		cout<<"ns: "<<td1.total_nanoseconds()<<endl;
	}

	//time pt
	ptime p1(day_clock::local_day(), hours(8));
	ptime p2(microsec_clock::universal_time());
	if(!p1.is_not_a_date_time() && !p2.is_not_a_date_time()){
		cout<<p1<<endl;
		cout<<p2<<endl;
	}
}