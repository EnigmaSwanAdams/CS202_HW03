#include <iostream>

#ifndef MONEY_H_
#define MONEY_H_

class Money {
public:
    // defualt constructor
    Money();
    // cents and dollars constructor 
    Money(int, int=0);
    // one double for both cents and dollars
    Money(double);

    // ostream handler for printing 
    friend std::ostream& operator<<(std::ostream& out, const Money& a);
    bool operator==(const Money& a) const;
    bool operator!=( const Money& a) const; 
    bool operator<=( const Money& a) const;
    bool operator>(const Money& a) const;
    bool operator>=(const Money& a) const;
    bool operator<(const Money& a) const;
    Money operator+=(const Money& rhs);
    Money operator*=(const Money& rhs);
    friend Money operator*(const Money& lhs, const Money& rhs);
    friend Money operator+(const Money& lhs, const Money& rhs);
    Money operator-=(const Money& rhs);
    Money operator/=(const Money& rhs);
    friend Money operator/(const Money& lhs, const Money& rhs);
    friend Money operator-(const Money& lhs, const Money& rhs);


private:
    int _cents;
};

#endif /* TOKENANDPOSITION_H_ */


