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
	auto lastIt = line.begin(); // the last iterator before i

	for (auto i = line.begin(); i < line.end(); i++) {

		if (*lastIt == ' ') {
			pos = i - line.begin();
			len = 0;
			// and move on...
		}

		else if(*i == ' '){
			string newToken = line.substr(pos, len);
			vec.push_back(newToken);
			len = 0;
			pos = i - line.begin() + 1;
		}

		len++;
		lastIt = i;
	}

	if (line.back() != ' ') {
		vec.push_back(line.substr(pos)); // get the last word 
	}
	

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
		if (size(line) > 0) {
			vecStrs = lineToTokens(line); // break line into token
			int found = -1; // place the token was found at 
			int pos = 0; // starting position the find looks from


			for (int i = 0; i < vecStrs.size(); i++) { // process tokens 
			
					found = line.find(vecStrs.at(i), pos);
					size_t column = found + 1; 
					vecStuff.push_back(TokenAndPosition(vecStrs.at(i), counter, column));
					pos = found + 1; // can always do this since the strings in line will be in 
					// the same order in vecStrs
				
			}

		}

	}
	return vecStuff;
}


void printTokens(ostream& os, const vector<TokenAndPosition>& tokens) {
	// find largest line number and largest column number
	int lineMax = 0;
	int columnMax = 0;
	for (int i = 0; i < tokens.size(); i++) {
		if (tokens.at(i)._line > lineMax) { 
			lineMax = tokens.at(i)._line; 
		}
		if (tokens.at(i)._column > columnMax) {
			columnMax = tokens.at(i)._column;
		}
	}

	// find the number of digits in each 
	int lineMaxDige = findNumDigits(lineMax);
	int columnMaxDige = findNumDigits(columnMax);

	// print stuff 
	for (int i = 0; i < tokens.size(); i++) {
		os << "Line ";
		
		// find number of digits in current line and column number 
		int lineDigits = findNumDigits(tokens.at(i)._line);
		int columnDigits = findNumDigits(tokens.at(i)._column);
		// find the number of spaces we need to print
		int spacesL = lineMaxDige - lineDigits;
		int spacesC = columnMaxDige - columnDigits;
		
		while (spacesL > 0) {
			os << " ";
			spacesL--;
		}

		os << tokens.at(i)._line << ", Column ";

		while (spacesC > 0) {
			os << " ";
			spacesC--;
		}
		
		os << tokens.at(i)._column << ": \"" << tokens.at(i)._token << "\"" << endl;

	}

	return;
}


int findNumDigits(int num) {
	int numDigits = 0;
	while (num != 0) {
		num = num / 10;
		numDigits++;
	}
	return numDigits;
}

vector<string> reformat(int maxChr, const vector<TokenAndPosition>& tokens) {
	vector<string> lines;
	lines.push_back("");
	int j = 0;

	for (int i = 0; i < tokens.size(); i++) {
		
		// ask if we can add a token to the line
		//(i.e. line wont' be over maxChr length if we do)

		if ((lines.at(j).size() + tokens.at(i)._token.size()) <= maxChr) {
			// add a token to the line
			lines.at(j) = lines.at(j) + tokens.at(i)._token + " ";
		}
		else {
			// create a new line
			lines.push_back("");
			j++;
			// add the token to the new line 
			lines.at(j) = lines.at(j) + tokens.at(i)._token + " ";
		}

	}

	return lines;
}
