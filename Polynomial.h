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
    string print1();
    string print2();
    string addedPoly();
    string multPoly();
    int evaluate(Polynomial);
    Polynomial sort(Polynomial);
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
    //    cout << "MTFList::~MTFList() Entered destructor for class MTFList\n";
    if ( head != NULL ) {
        //        unsigned long oldCount = sz;
        //        cout << "calling member function clear() ";
        //        cout << "to deallocate memory for all objects on the list\n";
        
        clear();
        
        //        cout << "number of elements on the list was: " << oldCount << std::endl;
        //        cout << "number of elements on list now is:  " << sz << std::endl;
        
        head = NULL;
    }
    
    //    cout << "MTFList::~MTFList() Exiting destructor for class MTFList\n";

}

void Polynomial::insert(Element value)
{
        cout << "entering insert\n";
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
        cout << "exiting insert\n";
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

void Polynomial::clear()
{
    Node *current = head;
    //    int i = 0;
    
    //    cout << "\tMTFList::clear() preparing to remove " << sz;
    //    cout << " Nodes from the linked list\n";
    
    while (head != NULL)
    {
        //        i++;
        head = head->next;
        delete [] current;
        current = head;
        sz--;
    }
    
    
    //    cout << "\tMTFList::clear() removed " << i << " Nodes from the list\n";
    //    cout << "\tMTFList::clear() new count is: " << sz << endl;
}


#endif /* Polynomial_h */
