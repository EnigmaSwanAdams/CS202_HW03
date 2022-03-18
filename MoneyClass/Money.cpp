


#include "Money.hpp"
#include <iomanip>
#include <cmath>

// can be declared with either a float representing dollars and cents, 
// or an int representing cents and an int representing dollars
// dAndc does include fractions of a penny, but those are rounded out when we print (hope thats okay)

// defualt constructor
Money::Money() : _cents{ 0 } {}
// cents and dollars constructor 
Money::Money(int cents, int dollars) : _cents{ cents + 100 * dollars } {}
// one double for both cents and dollars
Money::Money(double dAndc) : _cents{ static_cast<int>(std::round(dAndc * 100))} {}





std::ostream& operator<<(std::ostream& out, const Money& a) {
    if (a < 0) { out << "-"; }
    out << "$" << std::fixed << std::setprecision(2) <<  abs(a._cents) / 100.0;// NOT SURE THIS WORKS !!!
    return out;
}

// comparison operators
// local so I think we can't compare Money objects to non Money objects
bool Money::operator==(const Money& a) const {
    return _cents == a._cents;
}

bool Money::operator!=( const Money& a) const {
    return !(a == *this);
}

bool Money::operator<=( const Money& a) const {
    return (_cents <= a._cents);
}

bool Money::operator>( const Money& a)const {
    return !(*this <= a);
}

bool Money::operator>=( const Money& a) const {
    return (_cents >= a._cents);
}

bool Money::operator<( const Money& a) const {
    return !(*this >= a);
}

// shorthand mathmatic operators 
// local since the lhs will always be type Money
Money Money::operator*=(const Money& rhs) {
    _cents = _cents * rhs._cents;
    return *this;
}

// multiplication version for a double so 2 cents * 2.0  = 4 cents insead of 
// 4 dollars (with only the above += operand the double gets converted to a Money object so 
// 2 cents * 2.0 = 400 cents since 2.0 get converted to a Money object with _cent = 200 
Money Money::operator*=(const double rhs) {
    Money temp{ static_cast<int>(std::round(rhs)) }; \
    *this *= temp;
    return *this;
}

// multiplication for a MOney object with a float
Money Money::operator/=(const double rhs) {
    Money temp{ static_cast<int>(std::round(rhs)) }; 
        *this /= temp;
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

Money operator/(const Money& lhs, const Money& rhs) {
    auto temp{ lhs };
    temp /= rhs;
    return temp;
}

Money operator-(const Money& lhs, const Money& rhs) {
    auto temp{ lhs };
    temp -= rhs;
    return temp;
}









