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

using std::string;
using std::ifstream;
using std::cin;
using std::cout;
using std::endl;


int main() { // later the main needs to take a comand line argument
	string fileName = "test.txt";
	int lineNum = 0; // eventual line counter 
	
		// open file
		ifstream fin(fileName);
		// error checking
		if (!fin) { cout << "Error opening " << fileName << endl; return 1; }
		cout << "Opened " << fileName << endl;

		// read in a file line my line 
		// call readlines here????
		while (true) {
			string line;
			getline(fin, line);

			if (!fin) { // error checking
				//if there is a problem with getline
				if (fin.eof()) { cout << "Finished reading (reached eof)" << endl; }
				else { cout << "Error reading" << endl; }
				break;
			}
			
			 
			// process line here 
			 
		}

		// then print with printTokens function

	return 0;
}