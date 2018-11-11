#include "../inc/defines.h"
//#include <memory>
#include <boost/smart_ptr.hpp>
#include <algorithm>
#include <boost/make_shared.hpp>
#include <boost/pool/pool.hpp>
#include <boost/pool/object_pool.hpp>
#include <boost/pool/singleton_pool.hpp>
#include <boost/pool/pool_alloc.hpp>

class foo
{
public:
    foo() = default;
    ~foo() {cout<<_s<<" deleted"<<endl;}
    foo(const foo& f) = default;
    foo &operator=(const foo& f) = default;

    foo(const char *s):_s(s){}
    string  _s;
};

void scope_ptr_demo()
{
    using namespace boost;
    //std::auto_ptr<foo> p0(new foo("p0"));

    //scoped ptr
    scoped_ptr<foo> p1(new foo("p1"));
    cout<<p1->_s<<" "<<(*p1)._s<<endl;

    //transfer
    //scoped_ptr<foo> p2 = p1;
    //p2->_s = "p1->p2"; //can not transfer
    p1.reset();
    if(p1 == nullptr){
        cout<<"p1 already released"<<endl;
    }

    //scoped array
    scoped_array<foo> arr1(new foo[2]);
    scoped_array<int> arr2(new int[100]);
    arr1[0]._s = "i0"; arr1[1]._s = "i1";
    std::fill_n(&arr2[0], 100, 5);

    cout<<arr1[0]._s<<" "<<arr1[1]._s<<endl;
    cout<<arr2[0]<<endl;
}

void shared_ptr_demo()
{
    using namespace boost;
    //create shared ptr
    shared_ptr<foo> sp1(new foo("sp1"));
    if(sp1 != nullptr){
        cout<<sp1->_s<<endl;
    }

    //reference count
    shared_ptr<foo> sp2(sp1);
    sp2->_s += "+sp2";
    cout<<"user ref: "<<sp1.use_count()<<endl;
    if(!sp1.unique()){
        cout<<"has mutiply ptr"<<endl;
    }

    //make shared ptr
    shared_ptr<foo> sp3 = make_shared<foo>("maked sp3");
    cout<<sp3->_s<<endl;

    //shared ptr with container
    vector<shared_ptr<foo>> sarr1(3);
    for(auto it = sarr1.begin(); it != sarr1.end(); ++it){
        size_t ix = it - sarr1.begin();
        string name = "foo" + std::to_string(ix);
        *it = make_shared<foo>(name.c_str());
        cout<<sarr1[ix]->_s<<endl;
    }

    //shared array
    int *p = new int[100]{0};
    shared_array<int> sarr3(p);
    shared_array<int> sarr4 = sarr3;
    sarr4[10] = 14;
    cout<<sarr3[10]<<endl;
}

void weak_ptr_demo()
{
    using namespace boost;
    shared_ptr<int> sp(new int[10]);
    weak_ptr<int> wp(sp);
    cout<<"weak ptr do not add ref count, "<<
        sp.use_count()<<" "<<wp.use_count()<<endl;

    if(!wp.expired()){
        //get a observing ptr to operate
        shared_ptr<int> sp2 = wp.lock();
        *sp2 = 100;
        cout<<"use ref :"<<wp.use_count()<<" "<<
            sp.use_count()<<endl;
    }

    sp.reset();
    if(wp.expired()){
        cout<<"shared ptr expire"<<endl;
    }

    if(!wp.lock()){
        cout<<"empty ptr"<<endl;
    }
}

struct pool_tag{};
void mem_pool_demo()
{
    using namespace boost;
    pool<> p(sizeof(int)); //used on POD types
    int *p1 = (int*)p.malloc();
    if(p.is_from(p1)){
        cout<<"allocate from pool"<<endl;
    }

    for(int i = 0; i < 100; ++i){
        p.ordered_malloc(10); //allocate 10
    }

    //object pool
    object_pool<foo> fpool;
    foo *p2 = fpool.construct("p2 foo");
    if(fpool.is_from(p2)){
        cout<<"allocate from obj pool"<<endl;
    }
    cout<<p2->_s<<endl;

    //singleton pool, contains all kinds static member
    //tag struct, request size
    typedef singleton_pool<pool_tag, sizeof(int)> s_int;
    int *p3 = (int*)s_int::malloc();

    s_int::release_memory();//deallocate mem

    //special mem allocator for containers
    vector<int, pool_allocator<int>> v;
    v.push_back(10);
    cout<<v.size()<<endl;


}