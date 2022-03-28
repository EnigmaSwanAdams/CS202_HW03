/*
* CS 202 midterm question 1
* 3/27/2022
*
* file containing main
*/

#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include "TokenAndPosition.h"
#include <stdio.h>


using std::string;
using std::ifstream;
//using std::cin;
using std::cout;
using std::endl;


int main(int argc, char* argv[]) {

	// error checking 
	if (argc != 3) {
		cout << "incorect number of command line arguments specified" << endl;
	}

	else {
		//extract the wrap length (int maxChr)
		int maxChr = strToIntAscii(argv[2]);

		string fileName = argv[1];
		vector<TokenAndPosition> tokens;

		// open file
		ifstream fin(fileName);

		// error checking
		if (!fin) { cout << "Error opening " << fileName << endl; return 1; }
		cout << "Opened " << fileName << endl;


		// process file
		tokens = readLines(fin);

		//reformat
		vector<string> correctedLines = reformat(maxChr, tokens);

		// problem 1
		// print reformatted lines 
		cout << "printing with a wrap length of " << maxChr << "...\n" << endl;
		for (auto i : correctedLines) {
			cout << i << "\n";
		}
	}

	return 0;
}