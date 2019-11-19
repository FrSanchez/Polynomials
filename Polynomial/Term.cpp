//
//  Term.cpp
//  Polynomials
//
//  Created by Francisco Sanchez on 11/18/19.
//  Copyright © 2019 Francisco Sanchez. All rights reserved.
//

#include "Term.hpp"

Term::Term() : Term(0,0)
{
    
}

Term::Term(double coeff, int pwr)
{
    coefficient = coeff;
    power = pwr;
    next = nullptr;
    prev = nullptr;
}

bool operator==(const Term &t1, const Term &t2)
{
    return (t1.coefficient == t2.coefficient && t1.power == t2.power);
}

bool operator!=(const Term &t1, const Term &t2)
{
    return (t1.coefficient != t2.coefficient || t1.power != t2.power);
}

std::ostream& operator<<(std::ostream &os, const Term &o)
{
    if (o.coefficient != 0) {
        if (o.coefficient != 1.0) {
            if (o.coefficient == -1.0) {
                os << "-";
            } else {
                os << o.coefficient;
            }
        }
        if(o.power > 0) {
            os << "x";
            if (o.power != 1) {
                os << "^" << o.power;
            }
        }
    }
    return os;
}
