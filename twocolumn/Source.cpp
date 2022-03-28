/*
* CS 202 midterm question 2
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
	if (argc != 5) {
		cout << "incorect number of command line arguments specified" << endl;
	}

	else {
		// extract number of lines in page
		int lineNum = strToIntAscii(argv[2]);
		//extract the wrap length (int maxChr)
		int maxChr = strToIntAscii(argv[3]);
		// extract number of spaces between lines 
		int extraSpaces = strToIntAscii(argv[4]);


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
		int pageNum = correctedLines.size() / (2 * lineNum) - 1;
		int j = 0;


		cout << "Printing in two columns of up to " << maxChr << " characters...\n" << endl;
		// for each page 
		for (int i = 0; i < pageNum; i++) {
			// creat columns
			vector<string> column1(&correctedLines[j], &correctedLines[lineNum + j]);
			j += lineNum;
			vector<string> column2(&correctedLines[j], &correctedLines[lineNum + j]);
			j += lineNum;

			// print columns for one page
			for (int i = 0; i < lineNum; i++) {
				int numSpaces = maxChr - column1.at(i).size() + extraSpaces;

				cout << column1.at(i);
				for (int i = 0; i < numSpaces; i++) {
					cout << " ";
				}

				cout << column2.at(i) << endl;
			}

			// print page break 
			for (int i = 0; i < maxChr * 2; i++) {
				cout << "-";
			}
			cout << endl;
		}
		
	}

	return 0;
}