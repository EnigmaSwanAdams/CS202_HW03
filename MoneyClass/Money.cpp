


#include "Money.h"
#include <iomanip>

// can be declared with either a float representing dollars and cents, 
// or an int representing cents and an int representing dollars
// dAndc does include fractions of a penny, but those are rounded out when we print (hope thats okay)

// defualt constructor
Money::Money() : _cents{ 0 } {}
// cents and dollars constructor 
Money::Money(int dollars, int cents) : _cents{ cents + 100 * dollars } {}
// one double for both cents and dollars
Money::Money(double dAndc) : _cents{ static_cast<int>(dAndc * 100) } {}





std::ostream& operator<<(std::ostream& out, const Money& a) {
    if (a < 0) { out << "-"; }
    out << "$" << std::fixed << std::setprecision(2) <<  a._cents / 100.0;// NOT SURE THIS WORKS !!!
    return out;
}

// comparison operators
// global since I want to compare with numbers (int and float) on either side
bool operator==(const Money& b, const Money& a){
    return a._cents == b._cents;
}

bool operator!=(const Money& b, const Money& a) {
    return !(a == b);
}

bool operator<=(const Money& b, const Money& a) {
    return (b._cents <= a._cents);
}

bool operator>(const Money& b, const Money& a) {
    return !(b <= a);
}

bool operator>=(const Money& b, const Money& a) {
    return (b._cents >= a._cents);
}

bool operator<(const Money& b, const Money& a) {
    return !(b >= a);
}

// shorthand mathmatic operators 
// local since the lhs will always be type Money
Money Money::operator*=(const Money& rhs) {
    _cents = _cents * rhs._cents;
    return *this;
}

Money Money::operator+=(const Money& rhs) {
    _cents = _cents + rhs._cents;
    return *this;
}

Money Money::operator/=(const Money& rhs) {
    _cents = _cents / rhs._cents;
    return *this;
}

Money Money::operator-=(const Money& rhs) {
    *this += rhs * (-1);
    return *this;
}


// regular mathmatical operators
// global since I want to compare with numbers (int and float) on either side
// (even though the homework seems to imply these should be member functions)
Money operator*(const Money& lhs, const Money& rhs) {
    auto temp{ lhs };
    temp *= rhs;
    return temp;
}

Money operator+(const Money& lhs, const Money& rhs) {
    auto temp{ lhs };
    temp += rhs;
    return temp;
}

Money operator-(const Money& lhs, const Money& rhs) {
    auto temp{ lhs };
    temp -= rhs;
    return temp;
}









