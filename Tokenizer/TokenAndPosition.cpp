/*
* CS 202 homework 3
* 3/11/2022
* 
* TokenAndPosition struct definition file
* 
* 
*/



#include "TokenAndPosition.h"
#include <vector>
#include <istream>
#include <ostream>

using std::vector;
using std::istream;
using std::ostream;
using std::endl;
using std::cout;



vector<string> lineToTokens(const string& line) {
	vector<string> vec;
	int len = 0; // the length of the current word
	int pos = 0; // the position we recorded the last space at (+1 to avoid copying the space character)

	for (auto i = line.begin(); i < line.end(); i++) {
		if(*i == ' '){ 
			vec.push_back(line.substr(pos, len));
			len = 0;
			pos = i - line.begin() + 1;
		}
		len++;
	}

	vec.push_back(line.substr(pos)); // get the last word 

	return vec;
}

vector<TokenAndPosition> readLines(istream& is) {
	vector<TokenAndPosition> vecStuff;
	int counter = 0; // counts number of lines

	while (true) {
		vector<string> vecStrs;
		string line;
		counter++; // starts from line 1 

		getline(is, line);

		if (!is) { // error checking
			//if there is a problem with getline
			if (is.eof()) { cout << "Finished reading (reached eof)" << endl; }
			else { cout << "Error reading" << endl; }
			break;
		}


		// process line 
		vecStrs = lineToTokens(line); // break line into tokens
		for (int i = 0; i < vecStrs.size(); i++) { // process tokens 
			vecStuff.push_back(TokenAndPosition(vecStrs.at(i), counter, i+1));
		}


	}
	return vecStuff;
}


void printTokens(ostream& os, const vector<TokenAndPosition>& tokens) {


	return;
}

/*
string _token = "TOKEN NOT FOUND";
int _line = -1;
unsigned int _column;
*/