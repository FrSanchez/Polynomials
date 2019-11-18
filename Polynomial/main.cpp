//
//  main.cpp
//  Polynomial
//
//  Created by Francisco Sanchez on 11/18/19.
//  Copyright © 2019 Francisco Sanchez. All rights reserved.
//

#include <iostream>
#include "Polynomial.hpp"

using namespace std;

void printEq(Polynomial &p1, Polynomial& p2)
{
    cout << "P1 == P2? " << ((p1 == p2) ? "true": "false") << std::endl;
}

int main(int argc, const char * argv[]) {
    
    Polynomial *p1 = new Polynomial();
    p1->changeCoefficient(4, 2);
    p1->changeCoefficient(5, 7);
    p1->changeCoefficient(-1, 1);
    p1->changeCoefficient(2, 0);
    
    Polynomial *p2 = new Polynomial(*p1);
    cout << *p1;
    cout << *p2;
    printEq(*p1, *p2);
    p2->changeCoefficient(-10, 1);
    
    Polynomial *p3 = new Polynomial();
    p3->changeCoefficient(1, 4);

    cout << *p1;
    cout << *p2;
    
    cout << *p1 + *p3;
    
    printEq(*p1, *p2);
        
    delete p1;
    return 0;
}
