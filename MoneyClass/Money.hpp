/*
* CS 202 homework 3
* 3/18/2022
*
* file containing class declaration for Money class
* header for Money.cpp
* 
*/


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

    // comparison operator overloads 
    // work as expected and compare the provate members _cents
    bool operator==(const Money& a) const;
    bool operator!=(const Money& a) const; 
    bool operator<=(const Money& a) const;
    bool operator>(const Money& a) const;
    bool operator>=(const Money& a) const;
    bool operator<(const Money& a) const;
    Money & operator+=(const Money& rhs);
    Money & operator*=(const Money& rhs);

    // mathmatic operator overloads 
    // work as expected on the _cents member 
        // attempts to convert to a Money type performs operation on the _cents memeber
    friend Money operator*(const Money& lhs, const Money& rhs);
    friend Money operator+(const Money& lhs, const Money& rhs);
    Money & operator-=(const Money& rhs);
    Money & operator/=(const Money& rhs);
    friend Money operator/(const Money& lhs, const Money& rhs);
    friend Money operator-(const Money& lhs, const Money& rhs);
        // ensures that a double will not be interpreted as Money object with that many _cents
        // and will instead be interpreted as that many dollars 
    Money & operator*=(const double rhs); 
    Money & operator/=(const double rhs);


private:
    int _cents;
};

#endif /* TOKENANDPOSITION_H_ */


