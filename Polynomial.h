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
#include <cmath>
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
    int evaluate(int);
//    void mergeSort(Node*);
//    Node* merge(Node*, Node*);
//    void split(Node**, Node**);
    void clear();
    Node *head;
    
private:
    int sz;
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
        cout << "here"; 
        cout << current->info[0] << "x^" << current->info[1] << " + ";
        current = current->next;
    }
    cout << current->info[0] << "x^" << current->info[1] << endl;
}

string Polynomial::addedPoly(Polynomial poly2)
{
    return "return";
}

string Polynomial::multPoly(Polynomial poly2)
{
    return "return";
}

int Polynomial::evaluate(int x)
{
    Node *current = head;
    int ans = 0;
    for (int i = 0; i < sz; i++) {
        ans += current->info[0]*pow(x, current->info[1]);
        current = current->next;
    }
    return ans;
}

//void Polynomial::mergeSort(Node* headRef)
//{
//    head = headRef;
//    Node* a;
//    Node* b;
//    
//    if ((head == NULL) || (head->next == NULL))
//    {
//        return;
//    }
//    
//    split(&a, &b);
//    
//    mergeSort(a);
//    mergeSort(b);
//    
//    head = merge(a, b);
//}
//
//Node* Polynomial::merge(Node *a, Node *b)
//{
//    Node *result = NULL;
//    
//    if (a == NULL)
//        return b;
//    else if (b == NULL)
//        return a;
//
//    if (b->info[1] <= a->info[1])
//    {
//        result = a;
//        result->next = merge(a->next, b);
//    }
//    else
//    {
//        result = b;
//        result->next = merge(a, b->next);
//    }
//    
//    return result;
//}
//
//void Polynomial::split(Node** a, Node** b)
//{
//    Node* fast;
//    Node* slow;
//    
//    if (head == NULL || head->next == NULL)
//    {
//        *a = head;
//        *b = NULL;
//    }
//    else
//    {
//        slow = head;
//        fast = head->next;
//        
//        while (fast != NULL)
//        {
//            fast = fast->next;
//            if (fast != NULL)
//            {
//                slow = slow->next;
//                fast = fast->next;
//            }
//        }
//        
//        *a = head;
//        *b = slow->next;
//        slow->next = NULL;
//    }
//}

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
