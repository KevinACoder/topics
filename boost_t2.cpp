#include "define.h"
#include <fstream>
#include <ostream>
#include <boost/progress.hpp>
#include <boost/static_assert.hpp>
#include <boost/date_time.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/make_shared.hpp>
#include <memory>
#include <string>

using namespace std;
using namespace boost;

void progress_display_demo()
{
	vector<string> v(10000);
	ofstream fs("./test.txt");

	progress_display pd(v.size());
	for(auto &i : v){
		fs << i <<endl;
	}
}

class cfoo
{
public:
	cfoo() = default;
	cfoo(int a, string b):_a(a),_b(b)
	{

	}
	cfoo(const cfoo &c) = default;
	cfoo &operator=(const cfoo &c) = default;
	~cfoo()
	{
		cout<<"cfoo deleted: "<<_a<<" "
			<<_b<<endl;
	}

	int   	_a;
	string	_b;
};

class bridge
{
class impl
{
public:
	void print(){
		cout<<"impl print"<<endl;
	}
};
private:
	class impl;
	boost::shared_ptr<impl> p;
public:
	bridge():p(new impl){}
	void print(){p->print();}
};
void memory_demo()
{
	cout<<"scoped ptr"<<endl;
	{
		auto_ptr<cfoo> p1(new cfoo(11, "11"));
		auto_ptr<cfoo> p2(p1);
		assert(p1.get() == nullptr); //p1 do not have the pointer
	
		p2.reset(new cfoo(12, "12"));

		scoped_ptr<cfoo> p3(new cfoo(13, "13"));
		//scoped_ptr<cfoo> p4(p3); //do not allow copy
		cout<<"copy p3"<<endl;

		scoped_array<cfoo> arr1(new cfoo[10]);
	}

	cout<<"shared ptr"<<endl;
	{
		boost::shared_ptr<cfoo> p1(new cfoo(111, "111"));
		assert(p1);
		p1->_a *= 3;
		if(p1.unique()){
			cout<<"p1 is unique owner"<<endl;
		}

		//shared_ptr<cfoo> p2 = p1;
		//*p2->_b += "1";

		cout<<"p1 "<<p1->_a<<" "<<p1->_b<<endl;
		boost::shared_ptr<cfoo> p2(p1);
		cout<<"use count: "<<p2.use_count()<<endl;

		//boost::shared_ptr<std::string> p3 = make_shared<std::string>("make shared");
		//cout<<"string: "<<p3->size()<<" "<<*p3<<endl;

		bridge b;
		b.print();
	}

}
