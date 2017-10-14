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
    ~Polynomial();
    //Polynomial(int, unsigned, Polynomial*);
    void insert(Element);
    void print();
    string addedPoly(Polynomial);
    string multPoly(Polynomial);
    int evaluate();
    Polynomial sort();
    void clear();
    
private:
    int sz;
    Node *head;
};

Polynomial::Polynomial()
{
    this->sz = 0;
    this->head = NULL;
}

Polynomial::~Polynomial()
{
//        cout << "Polynomial::~Polynomial() Entered destructor for class Polynomial\n";
    if ( head != NULL ) {
//                unsigned long oldCount = sz;
//                cout << "calling member function clear() ";
//                cout << "to deallocate memory for all objects on the list\n";
        
        clear();
        
//                cout << "number of elements on the list was: " << oldCount << endl;
//                cout << "number of elements on list now is:  " << sz << endl;
        
        head = NULL;
    }
    
//        cout << "Polynomial::~Polynomial() Exiting destructor for class Polynomial\n";

}

void Polynomial::insert(Element value)
{
//        cout << "entering insert\n";
    Node *addMe = new Node(value, NULL, NULL);
    
    if (sz == 0) {
        // this is first object to be added to the list
        head = addMe;
        sz = 1;
    }
    else {
        addMe->next = head;
        head->previous = addMe;
        addMe->previous = NULL;
        head = addMe;
        sz++;
    }
//        cout << "exiting insert\n";
}

void Polynomial::print()
{
    Node *current = head;
    
    for (int i = 0; i < sz-1; i++) {
        cout << current->info[0] << "x^" << current->info[1] << " + ";
        current = current->next;
    }
    cout << current->info[0] << "x^" << current->info[1] << endl;
}

string Polynomial::addedPoly(Polynomial poly)
{
    return "return";
}

string Polynomial::multPoly(Polynomial poly)
{
    return "return";
}

int Polynomial::evaluate()
{
    return 0;
}

Polynomial Polynomial::sort()
{
    Polynomial returnMe;
    return returnMe;
}

void Polynomial::clear()
{
    Node *current = head;
//        int i = 0;
    
//        cout << "\tPolynomial::clear() preparing to remove " << sz;
//        cout << " Nodes from the linked list\n";
    
    while (head != NULL)
    {
//        i++;
        head = head->next;
        delete [] current;
        current = head;
        sz--;
    }
    
    
//        cout << "\tPolynomial::clear() removed " << i << " Nodes from the list\n";
//        cout << "\tPolynomial::clear() new count is: " << sz << endl;
}


#endif /* Polynomial_h */
