#include "../inc/defines.h"
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>

using namespace boost;
static void string_cast()
{
    int a1 = lexical_cast<int>("100");
    float a2 = lexical_cast<float>("3.14e5");

    cout<<a1<<" "<<a2<<endl;
    cout<<lexical_cast<string>(0x10)<<endl;
    cout<<((lexical_cast<bool>("1") == true)?"true":"false")<<endl;

    //catch exception on cast
    try{
        cout<<lexical_cast<bool>("false")<<endl;
    }catch(bad_lexical_cast &e){
        cout<<"error: "<<e.what()<<endl;
    }
}

/*
 * check if number is validate
*/
template<typename T>
static bool is_num_valid(const char *s)
{
    try{
        lexical_cast<T>(s);
        return true;
    }catch(bad_lexical_cast &e){
        return false;
    }
}

class castable
{
friend ostream &operator<<(ostream &os, const castable &x)
{
    os << typeid(x).name();//"castable class";
    return os;
}
};

static void string_format()
{
    cout << (format("%s:%d")%"format"%123)<<endl;
    format fmt("%d+%d=%d");
    fmt%2%3%5;
    cout<<fmt.str()<<endl;
}

static void string_algo()
{
    string str("readme.txt");
    if(ends_with(str, "txt")){
        cout<<"UPCASE TXT: "<<to_upper_copy(str)<<endl;
    }

    replace_first(str, "readme", "followme");
    cout<<str<<endl;

    vector<char> v(str.begin(), str.end());
    //del string
    vector<char> v2 = to_upper_copy(erase_first_copy(v, "txt"));
    for(auto c : v2){
        cout<<c;
    }
    cout<<endl;
}

void string_demo()
{
    string_cast();
    if(is_num_valid<float>("3.5e4")){
        cout<<"valid num"<<endl;
    }
    cout<<lexical_cast<string>(castable())<<endl;
    string_format();
    string_algo();
}