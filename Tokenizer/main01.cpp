/*
* CS 202 homework 3
* 3/11/2022
*
* file containing main for the 
* Main Program 1: A Simple Tokenizer
*/


#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include "TokenAndPosition.h"
#include "StopWatch.h"
#include <stdio.h>


using std::string;
using std::ifstream;
using std::cin;
using std::cout;
using std::endl;

//dummy function
int myPrint(vector<string> &num) {
	cout << num.at(0) << endl;
	return 0;
}

int main(int argc, char *argv[]) {

	/* // some testing for when I wrote a shell in cs 321 
	* // with a vector holding function pointers etc.  (unrelated to the rest of this assignment/solution
	//void (*functPtr) = &myPrint;
	vector<int(*)(vector<string>& )> v{ &myPrint };
	//v.push_back(&myPrint);

	/*
	string hi = "hi";
	char **hello;

	(*myPrint)(hi);
	cout << "done\n";
	v.at(0)(hi);
	myPrint(hi);
	

	vector<string> vec{ "hi", "hello" };
	(*myPrint)(vec);
	v.at(0)(vec);
	myPrint(vec);

	cout << vec.size();
	cout << vec.at(1).c_str();
	char** args[6];
	//strdup(*args[0]);
	*/


	
	// stopwatch object to time it
	// only times the readlines and or printlines function 
	StopWatch sw; 

	if (argc < 2 || argc > 3) {
		cout << "\nIncorrect number of arguments specified\n";
	}

	else {

		if (argc == 3) {
			string com = argv[2];

			if ((argc == 3) && (com == "--lineonly")) {
				// continue...
			}
			else {
				cout << "incorrect third command specified\n";
				argc--; // edit it so it looks like no third argument was specifed
			}
		}
		
		
		string fileName = argv[1]; // second arguments should be the filename 
		vector<TokenAndPosition> tokens;

		// open file
		ifstream fin(fileName);

		// get file size in bytes
		fin.seekg(0, std::ios::end);
		int fileSize = fin.tellg();
		// go back to the begining 
		fin.seekg(0);

		// error checking
		if (!fin) { cout << "Error opening " << fileName << endl; return 1; }
		cout << "Opened " << fileName << endl;

		sw.Start();
		// process file
		tokens = readLines(fin);

		//print tokens if there is no third argument specified
		if (argc == 2) {
			printTokens(cout, tokens);
		}
		sw.Stop();
        
		
		cout << "Total time in milliseconds: " << sw.TimeMilliSec();

		//print it in MB/seconds to process it 
		cout << "\nProcessed at " << fileSize/1000/sw.TimeSec() << " KB per second"; 
	}
	

	return 0;
}
