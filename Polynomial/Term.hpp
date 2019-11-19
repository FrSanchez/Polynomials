//
//  Term.hpp
//  Polynomials
//
//  Created by Francisco Sanchez on 11/18/19.
//  Copyright © 2019 Francisco Sanchez. All rights reserved.
//

#ifndef Term_hpp
#define Term_hpp

#include <iostream>

class Term
{
public:
    Term() ;
    Term(double, int);

    double getCoefficient() { return coefficient; }
    double getPower() { return power; }
    void setCoefficient(double value) { coefficient = value; }
    void setPower(int value) { power = value; }
    Term* getNext() { return next; }
    Term* getPrev() { return prev; }
    void setNext(Term* value) { next = value; }
    void setPrev(Term *value) { prev = value; }
    
    friend std::ostream& operator<<(std::ostream &os, const Term &o);
    friend bool operator==(const Term &t1, const Term &t2);
    friend bool operator!=(const Term &t1, const Term &t2);
private:
    double coefficient;
    int power;
    Term* next;
    Term* prev;
};

#endif /* Term_hpp */
