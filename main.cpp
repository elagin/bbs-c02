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
#include <windows.h>

using namespace std;

bool checkFile( const string & fileName )
{
	HANDLE hFile;
	hFile = CreateFileA( fileName.c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL );
	if( hFile == INVALID_HANDLE_VALUE )
	{
		return true;
	}
	else
	{
		CloseHandle(hFile);
		cout << "File " << fileName << " exist" << endl;
		return false;
	}
}

string setCell(const string & aSrt, const bool isPref)
{
	string res;
	res.append("\"");
	if(isPref)
	{
		res.append("A");
	}
	res.append(aSrt);
	if(isPref)
	{
		res.append("A");
	}
	res.append("\"");
	return res;
}

int main(int argc, char** argv)
{
	if( argc == 6 )
    {
		if(checkFile(argv[1]))
		{ 
			int firstStart = lexical_cast<int>(argv[2]);
			int firstEnd = lexical_cast<int>(argv[3]);
			int secondStart = lexical_cast<int>(argv[4]);
			int secondEnd = lexical_cast<int>(argv[5]);

			ofstream os(argv[1], ios::app);
			os << "Number #1;Formatted #1;Number #2;Formatted #2" << endl;

			if( firstEnd > firstStart )
			{
				int count = firstEnd - firstStart;

				int j = secondStart;
				for(int i = firstStart; i <= (firstStart + count); i++ )
				{
					os << setCell(lexical_cast<string>(i), true)
						<< ";"
						<< setCell(lexical_cast<string>(i), false)
						<< ";"
						<< setCell(lexical_cast<string>(j), true)
						<< ";"
						<< setCell(lexical_cast<string>(j), false)
						<< endl;
					j++;
				}
			}
		}
	}
    else
    {
		cout << "Invalid params, usage:\n";
		cout << "c:\\out.csv 10793360000 10793360200 10793420100 10793420300\n";
		return false;
    }
    return 0;
}

