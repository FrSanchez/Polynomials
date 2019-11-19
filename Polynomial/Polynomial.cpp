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

Polynomial::~Polynomial()
{
    Term* pos = head->getNext();
    Term* first=pos;
    do {
        Term *t = pos;
        pos = pos->getNext();
        delete t;
    } while(pos != first);
}

Polynomial::Polynomial(const Polynomial &o) : Polynomial()
{
    Term* current = o.head->getNext();
    Term* prev = head;
    while(current != o.head) {
        Term* t = new Term(current->getCoefficient(), current->getPower());
        t->setNext(head);
        t->setPrev(prev);
        prev->setNext(t);
        head->setPrev(t);
        
        prev = t;
        current = current->getNext();
    };
    head->setCoefficient(o.head->getCoefficient());
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

bool Polynomial::changeCoefficient(Term &term)
{
    return changeCoefficient(term.getCoefficient(), term.getPower());
}

bool Polynomial::changeCoefficient(double coefficient, int power)
{
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
    return false;
}

bool operator==(const Polynomial &p1, const Polynomial &p2)
{
    Term* left = p1.head->getNext();
    Term* right = p2.head->getNext();
    Term* left1 = left;
    Term* right1 = right;
    
    while(*left == *right) {
        left = left->getNext();
        right = right->getNext();
        if (left == left1 && right == right1) {
            return true;
        }
    }
    return false;
}

Term* moveAndCopy(Polynomial &result, Term* one, Term* two)
{
    while (one->getPower() > two->getPower()) {
        result.changeCoefficient(one->getCoefficient(), one->getPower());
        one = one->getNext();
    }
    return one;
}

Polynomial Polynomial::operator*(const Polynomial& rhs)
{
    Polynomial result;
    Term *left = head->getNext();
    Term *left1 = left;
    do {
        Polynomial *tp = new Polynomial();
        Term *right = rhs.head->getNext();
        Term *rightf = right;
        do {
            double c = left->getCoefficient() * right->getCoefficient();
            int p = left->getPower() + right->getPower();
            tp->changeCoefficient(c, p);
            right = right->getNext();
        } while(right != rightf);
        result += *tp;
        delete tp;
        left = left->getNext();
    } while(left != left1);
    return result;
}

Polynomial Polynomial::operator+=(const Polynomial& rhs)
{
    Term* left = head->getNext();
    Term* right = rhs.head->getNext();
    while(left != head && right != rhs.head) {
        if (left->getPower() == right->getPower()) {
            changeCoefficient( left->getCoefficient() + right->getCoefficient(), left->getPower());
            left = left->getNext();
            right = right->getNext();
        }
        while (left->getPower() > right->getPower()) {
            left = left->getNext();
        }
        moveAndCopy(*this, right, left);
    }
    for(; right != rhs.head; right = right->getNext()) {
        changeCoefficient(*right);
    }
    head->setCoefficient(head->getCoefficient() + rhs.head->getCoefficient());
    return *this;
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
        left = moveAndCopy(result, left, right);
        right = moveAndCopy(result, right, left);
    }
    for(; right != rhs.head; right = right->getNext()) {
        result.changeCoefficient(*right);
    }
    for(; left != head; left = left->getNext()) {
        result.changeCoefficient(*left);
    }
    result.head->setCoefficient(head->getCoefficient() + rhs.head->getCoefficient());
    return result;
}

std::ostream& operator<<(std::ostream &os, const Polynomial &o)
{
    Term* current = o.head->getNext();
    Term* high = current;
    bool first = true;
    do {
        os << ' ';
        if (!first) {
            if(current->getCoefficient() >0 ) {
                os << '+';
            }
        }
        os << *current;
        first = false;
        current = current->getNext();
    } while(current != high);
    os << std::endl;
    return os;
}

