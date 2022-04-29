/*
* CS 202 final question 5
* 4/28/2022
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
	if (argc != 6) {
		cout << "incorect number of command line arguments specified, expected 6" << endl;
	}

	else {
		// extract number of lines in page
		int lineNum = strToIntAscii(argv[2]);
		//extract the wrap length 
		int totalChr = strToIntAscii(argv[3]);
		// extract number of columns per page
		int columnNum = strToIntAscii(argv[4]);
		// extract number of spaces between lines 
		int extraSpaces = strToIntAscii(argv[5]);


		// calculate the wrap length relative to the number of columns 
		int maxChr = (totalChr - extraSpaces*(columnNum - 1)) / columnNum;


		// extract filename
		string fileName = argv[1];
		vector<TokenAndPosition> tokens;
		// open file
		ifstream fin(fileName);

		// error checking
		if (!fin) { cout << "Error opening " << fileName << endl; return 1; }
		cout << "Opened " << fileName << endl;


		// process file
		tokens = readLines(fin);

		//reformat to one long column
		vector<string> correctedLines = reformat(maxChr, tokens);
		int pageNum = correctedLines.size() / (2 * lineNum) - 1;
		vector<vector<string>> columns; // hold lineNum length columns at each index 


		cout << "Printing in two columns of up to " << maxChr << " characters...\n" << endl;
		// for each page 
		for (int i = 0; i < pageNum; i++) {

			// divide into lineNum length columns
			for (int j = 0; j < lineNum * columnNum; j += lineNum){
				vector<string> newColumn(&correctedLines[j], &correctedLines[lineNum + j]);
				columns.push_back(newColumn);
			}

			
			// print columns for one page
			for (int i = 0; i < lineNum; i++) {
				for (int j = 0; j < columnNum; j++) {

					// print one line of one column
					cout << columns.at(j).at(i);
					// print in between spaces
					int numSpaces = maxChr - columns.at(j).at(i).size() + extraSpaces;
					for (int i = 0; i < numSpaces; i++) {
						cout << " ";
					}

				}
				cout << endl;
			}
			
			// print page break 
			for (int i = 0; i < totalChr; i++) {
				cout << "-";
			}
			cout << endl;
		}
	}
	

	return 0;
}