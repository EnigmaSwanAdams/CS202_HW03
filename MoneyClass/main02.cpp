


#include "Money.h"
#include <iostream>

using std::cout;
using std::endl;


int main() {

	// test output 
	Money a = Money(5.5);
	cout << "a: " << a << endl;
	Money b;
	cout << "b: " << b << endl;

	auto c = a;
	cout << "c: " << c;
	if (c == a) {
		cout << "\nthey are correctly equal\n";
	}
	return 0;
}