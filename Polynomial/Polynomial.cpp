//
//  Polynomials.cpp
//  Polynomials
//
//  Created by Francisco Sanchez on 11/18/19.
//  Copyright © 2019 Francisco Sanchez. All rights reserved.
//

#include <iostream>
#include "Polynomial.hpp"

Polynomial::Polynomial()
{
    head = new Term(0, 0);
    head->setNext(head);
    head->setPrev(head);
}

Polynomial::Polynomial(const Polynomial &o) : Polynomial()
{
    Term* current = o.head->getNext();
    Term* prev = head;
    while (current != o.head) {
        Term* t = new Term(current->getCoefficient(), current->getPower());
        t->setNext(head);
        t->setPrev(prev);
        prev->setNext(t);
        head->setPrev(t);
        
        prev = t;
        current = current->getNext();
    }
}

bool Polynomial::insert(Term* pos, double coefficient, int power)
{
    if (pos && coefficient && power) {
        Term* t = new Term(coefficient, power);
        if (!t) {
            return false;
        }
        Term* prev = pos->getPrev();
        t->setNext(pos);
        t->setPrev(prev);
        prev->setNext(t);
        pos->setPrev(t);
        return true;
    }
    return false;
}
bool Polynomial::remove(Term *pos)
{
    if (pos && pos != head) {
        Term* prev = pos->getPrev();
        Term* next = pos->getNext();
        prev->setNext(pos->getNext());
        next->setPrev(prev);
        delete pos;
        return true;
    }
    return false;
}

bool Polynomial::changeCoefficient(double coefficient, int power)
{
    if (power > 0) {
        Term* current = head->getNext();
        while(current)
        {
            if (power == current->getPower()) {
                if (coefficient == 0) {
                    return remove(current);
                } else {
                    current->setCoefficient(coefficient);
                    return true;
                }
            } else {
                if (power > current->getPower()) {
                    return insert(current, coefficient, power);
                } else {
                    current = current->getNext();
                }
            }
        }
    }
    return false;
}

bool Polynomial::isEmpty()
{
    return head->getNext() == head->getPrev();
}

bool operator==(const Polynomial &p1, const Polynomial &p2)
{
    Term* left;
    Term* right;
    
    for(left = p1.head->getNext(),
        right = p2.head->getNext();
        
        left != p1.head && right != p2.head;
        
        left = left->getNext(),
        right = right->getNext()) {
        if (left->getCoefficient() != right->getCoefficient() ||
            left->getPower() != right->getPower())
            return false;
    }
    return true;
}

Term* advance(Polynomial &res, Term* one, Term* two)
{
    while (one->getPower() > two->getPower()) {
        res.changeCoefficient(one->getCoefficient(), one->getPower());
        one = one->getNext();
    }
    return one;
}

Term* copyTerm(Polynomial &result, Term* term)
{
    result.changeCoefficient(term->getCoefficient(), term->getPower());
    term = term->getNext();
    return term;
}

Polynomial Polynomial::operator+(const Polynomial& rhs)
{
    Polynomial result;
    Term* left = head->getNext();
    Term* right = rhs.head->getNext();
    while(left != head && right != rhs.head) {
        if (left->getPower() == right->getPower()) {
            result.changeCoefficient( left->getCoefficient() + right->getCoefficient(), left->getPower());
            left = left->getNext();
            right = right->getNext();
        }
        left = advance(result, left, right);
        right = advance(result, right, left);
    }
    while(right != rhs.head) {
        right = copyTerm(result, right);
    }
    while(left != head) {
        left = copyTerm(result, left);
    }
    return result;

}

std::ostream& operator<<(std::ostream &os, const Polynomial &o)
{
    Term* current = o.head->getNext();
    bool first = true;
    while(current != o.head) {
        os << ' ';
        if (!first) {
            if(current->getCoefficient() >=0 ) {
                os << '+';
            }
        }
        os << *current;
        first = false;
        current = current->getNext();
    }
    os << std::endl;
    return os;
}

