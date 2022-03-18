#include <iostream>

#ifndef MONEY_H_
#define MONEY_H_

class Money {
public:
    // defualt constructor
    Money();
    // cents and dollars constructor 
    Money(int, int = 0);
    // one double for both cents and dollars
    Money(double);

    // ostream handler for printing 
    friend std::ostream& operator<<(std::ostream& out, const Money& a);
    friend bool operator==(const Money& b, const Money& a); // it says it can't find a definition, but it compiles 
    friend bool operator!=(const Money& b, const Money& a); // presumably this one too
    friend bool operator<=(const Money& b, const Money& a);
    friend bool operator>(const Money& b, const Money& a);
    friend bool operator>=(const Money& b, const Money& a);
    friend bool operator<(const Money& b, const Money& a);
    Money operator+=(const Money& rhs);
    Money operator*=(const Money& rhs);
    friend Money operator*(const Money& lhs, const Money& rhs);
    friend Money operator+(const Money& lhs, const Money& rhs);
    Money operator-=(const Money& rhs);
    Money operator/=(const Money& rhs);


private:
    int _cents;
};

#endif /* TOKENANDPOSITION_H_ */


