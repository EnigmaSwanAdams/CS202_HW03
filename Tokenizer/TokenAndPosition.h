/*
* CS 202 homework 3
* 3/11/2022
*
* TokenAndPosition struct declaration/header file
*
*
*/



#include <iostream>
#include <string>
#include <vector>
#include <ostream>

using std::ostream;
using std::istream;
using std::vector;
using std::string;

#ifndef TOKENANDPOSITION_H_
#define TOKENANDPOSITION_H_

struct TokenAndPosition {
	string _token = "TOKEN NOT FOUND";
	int _line  = -1;
	unsigned int _column;

};

vector<string> lineToTokens(const string& line);
vector<TokenAndPosition> readLines(istream& is);
void printTokens(ostream& os, const vector<TokenAndPosition>& tokens);





#endif /* TOKENANDPOSITION_H_ */