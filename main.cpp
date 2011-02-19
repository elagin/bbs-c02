/* 
 * File:   main.cpp
 * Author: elagin
 *
 * Created on 19 Февраль 2011 г., 23:24
 */
#include "boost/lexical_cast.hpp"

    using boost::lexical_cast;
    using boost::bad_lexical_cast;

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

/*
 * 
 */

string getPref(const string & aStr)
{
    string res;
    for(int i = 0; i < aStr.length(); i++ )
    {
        try
        {
            lexical_cast<int>(aStr[i]);
            return res;
        }
        catch(bad_lexical_cast &)
        {
            res.append(&aStr[i],1);
        }
    }
    return res;
}

string getPostf(const string & aStr, const int startPos)
{
    string res;
    cout << "0123456789" << endl;
    cout << aStr << endl;
    for(int i = startPos; i < aStr.length(); i++ )
    {
        cout << i << aStr[i] << endl;
        try
        {
            lexical_cast<int>(aStr[i]);
        }
        catch(bad_lexical_cast &)
        {
            int size = aStr.length()-i;
//            cout << "I:" << i << " Len: " << size  << endl;
            res = aStr.substr( i, aStr.length()-i);
            return res;
        }
    }
    return res;
}

int main(int argc, char** argv) {

    if( argc == 6 )
    {
        int firstStart = lexical_cast<int>(argv[2]);
        int firstEnd = lexical_cast<int>(argv[3]);
        int secondStart = lexical_cast<int>(argv[4]);
        int secondEnd = lexical_cast<int>(argv[5]);

        string test = "JUabc456gggAD";
        string pref = getPref(test);

        string postf = getPostf(test, pref.length());
        
        cout << "pref: " << pref << endl;
        cout << "post: " << postf << endl;

    //    ofstream os(argv[5], ios::app);
        ofstream os("new.csv",ios::app);

        os << "Number #1;Formatted #1;Number #2;Formatted #2" << endl;

        if( firstEnd > firstStart )
        {
            int count = firstEnd - firstStart;

            int j = secondStart;
            for(int i = firstStart; i <= (firstStart + count); i++ )
            {

                os << pref << i << postf << ";" << i << ";" << j << ";" << j << endl;
                j++;
            }
        }
    }
    else
    {
        cout << "Error" << endl;
    }
    return 0;
}

