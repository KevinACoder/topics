#include "../inc/defines.h"
#include <boost/io/ios_state.hpp>

#define BOOST_SYSTEM_NO_LIB
#define BOOST_FILESYSTEM_NO_LIB
#include <boost/filesystem.hpp>
/*#include <libs/filesystem/src/utf8_codecvt_facet.hpp>
#include <libs/filesystem/src/utf8_codecvt_facet.cpp>
#include <libs/filesystem/src/path.cpp>
#include <libs/filesystem/src/operations.cpp>
#include <libs/filesystem/src/portability.cpp>*/

static void logging(const char *msg)
{
    cout<< msg <<endl;
}
static void logging(double f)
{
    cout<< f <<endl;
}
void io_state_demo()
{
    using namespace boost::io;
    string filename("../bin/test.txt");
    if(!filename.empty()){
        ofstream fs(filename.c_str());
        //save state of stream
        ios_all_saver ifs(cout);
        cout.setf(std::ifstream::fixed,
         std::istream::floatfield);
        cout.precision(3);
        cout.rdbuf(fs.rdbuf());
        logging("fatal msg");
        logging(1234.5678912);
    }
    //recover stream to std out
    cout<<"log finished"<<endl;
}

void filesystem_demo()
{
    using namespace boost::filesystem;
    path p1("../bin");
    if(!p1.empty()){
        cout<<"not empty path"<<endl;
    }
    //p1 /= "data";
    //cout<<system_complete(p1)<<endl;
}