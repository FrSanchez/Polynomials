//
//  Polynomials.hpp
//  Polynomials
//
//  Created by Francisco Sanchez on 11/18/19.
//  Copyright © 2019 Francisco Sanchez. All rights reserved.
//

#pragma once

#ifndef Polynomials_
#define Polynomials_

/* The classes below are exported */
#pragma GCC visibility push(default)

#include "Term.hpp"

class Polynomial
{
public:
    Polynomial();
    Polynomial(const Polynomial &o);
    
    bool changeCoefficient(double coefficient, int power);
    Polynomial operator+(const Polynomial& right);
    
    bool isEmpty();

    friend std::ostream& operator<<(std::ostream &os, const Polynomial &o);
    friend bool operator==(const Polynomial &p1, const Polynomial &p2);
private:
    Term* head;
    bool insert(Term* pos, double coefficient, int power);
    bool remove(Term *pos);
};

#pragma GCC visibility pop
#endif
