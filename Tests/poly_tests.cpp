//
//  poly_tests.cpp
//  Polynomial
//
//  Created by Francisco Sanchez on 11/18/19.
//  Copyright © 2019 Francisco Sanchez. All rights reserved.
//


#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream
#include "catch.hpp"
#include "Polynomial.hpp"

TEST_CASE("Testing plynomial") {
    Polynomial p1;
    std::stringstream ss;
    
    SECTION("single coef") {
        p1.changeCoefficient(10, 0);
        ss << p1;
        CHECK(ss.str() == " 10");
    }
    
    SECTION("single") {
        p1.changeCoefficient(10, 2);
        p1.changeCoefficient(10, 0);
        ss << p1;
        CHECK(ss.str() == " 10x^2 +10");
    }
    
    SECTION("0") {
        p1.changeCoefficient(0, 0);
        ss << p1;
        CHECK(ss.str() == "");
    }
    
    SECTION("delete term") {
        p1.changeCoefficient(10, 2);
        p1.changeCoefficient(10, 0);
        ss << p1;
        CHECK(ss.str() == " 10x^2 +10");
        ss.str("");
        p1.changeCoefficient(0, 2);
        ss << p1;
        CHECK(ss.str() == " 10");
    }
    
    SECTION("add between") {
        p1.changeCoefficient(10, 3);
        p1.changeCoefficient(10, 0);
        ss << p1;
        CHECK(ss.str() == " 10x^3 +10");
        p1.changeCoefficient(-10, 2);
        ss.str("");
        ss << p1;
        CHECK(ss.str() == " 10x^3 -10x^2 +10");
    }
    
    SECTION("order") {
        p1.changeCoefficient(10, 0);
        p1.changeCoefficient(10, 3);
        ss << p1;
        CHECK(ss.str() == " 10x^3 +10");
    }
    
    SECTION("+") {
        p1.changeCoefficient(5, 2);
        Polynomial p2;
        p2.changeCoefficient(10, 2);
        
        p1+=p2;
        ss << p1;
        CHECK(ss.str() == " 15x^2");
    }

    SECTION("+") {
        p1.changeCoefficient(5, 2);
        Polynomial p2;
        p2.changeCoefficient(-10, 2);
        
        p1+=p2;
        ss << p1;
        CHECK(ss.str() == " -5x^2");
    }
    
    SECTION("+") {
        p1.changeCoefficient(-5, 2);
        Polynomial p2;
        p2.changeCoefficient(10, 2);
        
        p1+=p2;
        p1.changeCoefficient(22, 3 );
        ss << p1;
        CHECK(ss.str() == " 22x^3 +5x^2");
    }
    
    SECTION( "+") {
        p1.changeCoefficient(-5, 4);
        Polynomial p2;
        p2.changeCoefficient(10, 2);
        p2.changeCoefficient(20, 0);
        p1+=p2;
        ss << p1;
        CHECK(ss.str() == " -5x^4 +10x^2 +20");
    }
    
    SECTION("*") {
        p1.changeCoefficient(-5, 4);
        p1.changeCoefficient(1, 2);
        Polynomial p2;
        p2.changeCoefficient(2, 2);
        ss << p1 * p2;
        CHECK(ss.str() == " -10x^6 +2x^4");
    }

    SECTION("binomial sq") {
        p1.changeCoefficient(2, 1);
        p1.changeCoefficient(5, 0);
        Polynomial *p2 = new Polynomial(p1);
        ss << p1 * *p2;
        CHECK(ss.str() == " 4x^2 +20x +25");
    }

    SECTION("binomial sq") {
        p1.changeCoefficient(2, 1);
        p1.changeCoefficient(5, 0);
        Polynomial *p2 = new Polynomial(p1);
        p1*=*p2;
        ss << p1;
        CHECK(ss.str() == " 4x^2 +20x +25");
    }
    
    SECTION("=") {
        p1.changeCoefficient(2, 1);
        p1.changeCoefficient(5, 0);
        Polynomial p2 = p1;
        ss << p2;
        CHECK(ss.str() == " 2x +5");

    }
}
