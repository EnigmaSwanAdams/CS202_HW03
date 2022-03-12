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


// member functions
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
	vector<TokenAndPosition> vec;

	while (true) {
		string line;
		getline(is, line);

		if (!is) { // error checking
			//if there is a problem with getline
			if (is.eof()) { cout << "Finished reading (reached eof)" << endl; }
			else { cout << "Error reading" << endl; }
			break;
		}


		// process line here 

	}
	return vec;
}

void printTokens(ostream& os, const vector<TokenAndPosition>& tokens) {


	return;
}
