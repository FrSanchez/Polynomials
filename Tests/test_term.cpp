//
//  test_class.cpp
//  Polynomial
//
//  Created by Francisco Sanchez on 11/18/19.
//  Copyright © 2019 Francisco Sanchez. All rights reserved.
//


#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream
#include "catch.hpp"
#include "Term.hpp"

TEST_CASE("Testing term") {
    Term *term;
    
    SECTION("Print zero") {
        term = new Term(0,0);
        INFO("Using term");
        std::stringstream ss;
        ss << *term;
        CHECK(ss.str() == "");
    }
    
    SECTION("Possitive power") {
        term = new Term(1,1);
        std::stringstream ss;
        ss << *term;
        CHECK(ss.str() == "x");
    }
    
    SECTION("Higher power") {
        term = new Term(1,10);
        std::stringstream ss;
        ss << *term;
        CHECK(ss.str() == "x^10");
    }
    
    SECTION("-1") {
        term = new Term(-1,10);
        std::stringstream ss;
        ss << *term;
        CHECK(ss.str() == "-x^10");
    }

    SECTION("-10") {
        term = new Term(-10,10);
        std::stringstream ss;
        ss << *term;
        CHECK(ss.str() == "-10x^10");
    }
}
