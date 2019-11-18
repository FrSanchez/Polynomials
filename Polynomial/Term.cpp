//
//  Term.cpp
//  Polynomials
//
//  Created by Francisco Sanchez on 11/18/19.
//  Copyright © 2019 Francisco Sanchez. All rights reserved.
//

#include "Term.hpp"

Term::Term(double coeff, int pwr)
{
    coefficient = coeff;
    power = pwr;
    next = nullptr;
    prev = nullptr;
}

std::ostream& operator<<(std::ostream &os, const Term &o)
{
    if (o.coefficient != 1.0) {
        if (o.coefficient == -1.0) {
            os << "-";
        } else {
            os << o.coefficient;
        }
    }
    os << "x";
    if (o.power != 1) {
        os << "^" << o.power;
    }
    return os;
}
