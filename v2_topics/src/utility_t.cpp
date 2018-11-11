#include "../inc/defines.h"
#include <boost/utility.hpp>
#include <boost/noncopyable.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/optional.hpp>

class do_not_copy : private boost::noncopyable
{
public:
    do_not_copy() = default;
    do_not_copy(string s):_s(s){}
    ~do_not_copy(){
        cout<<_s<<" deleted"<<endl;
    }
    friend ostream &operator<<(ostream &os, const do_not_copy &d){
        os<<d._s<<endl;
        return os;
    }

private:
    string _s;
};

//register type
#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()
struct foo
{
    int     _a;
    string  _s;
};
BOOST_TYPEOF_REGISTER_TYPE(foo);
#define auto_t  BOOST_AUTO
void utility_demo()
{
    using namespace boost;
    //no copyable class
    do_not_copy d1("d1");
    //do_not_copy d2 = d1;

    cout<<d1<<endl;
    
    //typeof
    vector<int> v;
    typeof(v) v2(10, 12);
    for(auto i : v2){
        cout<<i<<" ";
    }
    cout<<endl;
    
    BOOST_TYPEOF(2*3.0) x = 2 * 3.0;
    BOOST_AUTO(y, 2 + 3);
    cout<<"x, y: "<<x<<" "<<y<<endl;

    //user defined type
    //BOOST_AUTO(p , std::make_pair("test1", foo));
    //cout<<typeid(p).name()<<endl;
    /*pair<string, foo> p;
    p.second._a = 10;
    p.second._s = "10";
    cout<<p.second._a<<" "<<p.second._s<<endl;*/

    //optional
    /*optional<string> op1("op1");
    //cout<<*op1<<endl;
    if(!(op1 == none)){
        cout<<"meaningful value"<<endl;
    }*/

    //op1 = none;
}