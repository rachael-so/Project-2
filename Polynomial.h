//
//  Polynomial.h
//  project2
//
//  Created by Rachael So on 10/10/17.
//  Copyright © 2017 Rachael So. All rights reserved.
//

#ifndef Polynomial_h
#define Polynomial_h

#include<iostream>
#include "Element.h"
#include "Node.h"

using namespace std;

/****************************************************************************
 ****************************************************************************
 *                                                                          *
 *                     class Polynomial declaration                         *
 *                                                                          *
 ****************************************************************************
 ****************************************************************************/

class Polynomial
{
public:
    Polynomial();
    //Polynomial(int, unsigned, Polynomial*);
    void insert(Element);
    string print1();
    string print2();
    string addedPoly();
    string multPoly();
    int evaluate(Polynomial);
    Polynomial sort(Polynomial);
    
private:
    int sz;
    Node *head;
};

Polynomial::Polynomial()
{
    this->sz = 0;
    this->head = NULL;
}

void Polynomial::insert(Element value)
{
    
}

string Polynomial::print1()
{
    return "return";
}

string Polynomial::print2()
{
    return "return";
}

string Polynomial::addedPoly()
{
    return "return";
}

string Polynomial::multPoly()
{
    return "return";
}

int Polynomial::evaluate(Polynomial poly)
{
    return 0;
}

Polynomial Polynomial::sort(Polynomial sortMe)
{
    return sortMe;
}


#endif /* Polynomial_h */
