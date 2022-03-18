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
#include <stdio.h>


using std::string;
using std::ifstream;
using std::cin;
using std::cout;
using std::endl;


int main(int argc, char *argv[]) { // later the main needs to take a comand line argument

	if (argc < 2 || argc > 3) {
		cout << "\nIncorrect number of arguments specified\n";
	}

	else {
		string fileName = argv[1]; // second arguments should be the filename 
		vector<TokenAndPosition> tokens;


		// open file
		ifstream fin(fileName);

		// error checking
		if (!fin) { cout << "Error opening " << fileName << endl; return 1; }
		cout << "Opened " << fileName << endl;

		// process file
		tokens = readLines(fin);

		//print tokens
		if (argc == 3) {
			if (argv[2] == "--lineonly") {
				printTokens(cout, tokens); // I think it works I just need to add the option for a comand line argument
			}
			else {
				cout << "\nInvalid third argument specified\n";
			}
		}
	}

	/*
	string lineTest = "HELLO my guy :> what is up?   ! WHAT";
	vector<string> vecTest = lineToTokens(lineTest);
	for (auto i : vecTest) {
		cout << i << endl;
	}
	*/

	return 0;
}