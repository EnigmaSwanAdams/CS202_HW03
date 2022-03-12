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


using std::string;
using std::ifstream;
using std::cin;
using std::cout;
using std::endl;


int main() { // later the main needs to take a comand line argument

	
	string fileName = "test.txt";
	int lineNum = 0; // eventual line counter (maybe)
	vector<TokenAndPosition> tokens;
	
	
		// open file
		ifstream fin(fileName);

		// error checking
		if (!fin) { cout << "Error opening " << fileName << endl; return 1; }
		cout << "Opened " << fileName << endl;

		// process file
		tokens = readLines(fin);

		//print tokens
		//printTokens(ostream & os, const vector<TokenAndPosition>&tokens)
	

	/*
	string lineTest = "HELLO my guy :> what is up? ! WHAT";
	vector<string> vecTest = lineToTokens(lineTest);
	for (auto i : vecTest) {
		cout << i << endl;
	}
	*/

	return 0;
}