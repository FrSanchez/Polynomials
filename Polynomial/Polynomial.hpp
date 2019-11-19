//
//  Polynomials.hpp
//  Polynomials
//
//  Created by Francisco Sanchez on 11/18/19.
//  Copyright © 2019 Francisco Sanchez. All rights reserved.
//

#pragma once

#ifndef Polynomial_H
#define Polynomial_H

/* The classes below are exported */
#pragma GCC visibility push(default)

#include <vector>
#include "Term.hpp"

class Polynomial
{
public:
    Polynomial();
    Polynomial(const Polynomial &o);
    ~Polynomial();
    
    bool changeCoefficient(double coefficient, int power);
    bool changeCoefficient(Term &term);
    Polynomial operator+(const Polynomial& rhs);
    Polynomial operator+=(const Polynomial& rhs);
    Polynomial operator*(const Polynomial& rhs);
    Polynomial operator*=(const Polynomial& rhs);
    Polynomial operator*=(const double rhs);
    int getDegree();
    std::vector<int> getCoefficients();
    
    friend std::ostream& operator<<(std::ostream &os, const Polynomial &o);
    friend bool operator==(const Polynomial &p1, const Polynomial &p2);
    friend bool operator!=(const Polynomial &p1, const Polynomial &p2);
private:
    Term* head;
    bool insert(Term* pos, double coefficient, int power);
    bool remove(Term *pos);
    void clear();
    void init();
};

#pragma GCC visibility pop
#endif
