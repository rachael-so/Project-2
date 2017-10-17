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
//    ~Polynomial();
    //Polynomial(int, unsigned, Polynomial*);
    void insert(Element);
    void print();
    Polynomial operator+(Polynomial);
    Polynomial operator*(Polynomial);
    int evaluate(int);
//    void mergeSort(Element*);
//    Element* merge(Element*, Element*);
//    void split(Element**, Element**);
//    void clear();
    
private:
    int sz;
    Element *head;
    Element *tail;
};

Polynomial::Polynomial()
{
    this->sz = 0;
    this->head = NULL;
    this->tail = NULL;
}

//Polynomial::~Polynomial()
//{
////        cout << "Polynomial::~Polynomial() Entered destructor for class Polynomial\n";
//    if ( head != NULL ) {
////                unsigned long oldCount = sz;
////                cout << "calling member function clear() ";
////                cout << "to deallocate memory for all objects on the list\n";
//        
//        clear();
//        
////                cout << "number of elements on the list was: " << oldCount << endl;
////                cout << "number of elements on list now is:  " << sz << endl;
//        
//        head = NULL;
//    }
//    
////        cout << "Polynomial::~Polynomial() Exiting destructor for class Polynomial\n";
//
//}
;
void Polynomial::insert(Element value)
{
    Element *addMe = new Element(value.coeff, value.pow);
    
    if (sz == 0) {
        // this is first object to be added to the list
        head = tail = addMe;
    }
    else if (addMe->pow > head->pow) {
        addMe->next = head;
        head = addMe;
    }
    else if (addMe->pow < tail->pow) {
        tail->next = addMe;
        tail = addMe;
        tail->next = NULL;
    }
    else {
        Element *current = head;
        while (current->next != NULL && addMe->pow < current->next->pow) {
            current = current->next;
        }
        if (current->next != NULL && addMe->pow > current->next->pow) {
            Element *after = current;
            after = after->next;
            current->next = addMe;
            addMe->next = after;
            after = NULL;
        }
        else if ( current->next != NULL && addMe->pow == current->next->pow) {
            current = current->next;
            current->coeff += addMe->coeff;
            delete addMe;
        }
        
        current = NULL;
    }
    sz++;
//        cout << "exiting insert\n";
}

void Polynomial::print()
{
    Element *current = head;
    
    while (current->next != NULL) {
        if (current->coeff != 1)
            cout << current->coeff;
        
        cout << "x^" << current->pow;
        
        if (current->next->coeff > 0)
            cout << "+";
        current = current->next;
    }
    
    //for last term
    if (current->coeff != 1)
        cout << current->coeff;
    if (current->pow != 0) {
        cout << "x";
        if (current->pow != 1)
            cout << "^" << current->pow;
    }
    cout << endl;
}

Polynomial Polynomial::operator+(Polynomial p2)
{
    Element *curr1 = head;
    Element *curr2 = p2.head;
    
    while (curr1 != NULL) {
        while (curr2 != NULL && (curr2->pow != curr1->pow)) {
            curr2 = curr2->next;
        }
        if (curr2 != NULL) {
            curr1->coeff += curr2->coeff;
        }
        curr2 = p2.head;
        curr1 = curr1->next;
    }
    
    curr1 = head;
    
    //add rest of curr2
    while (curr2 != NULL) {
        while (curr1 != NULL && (curr2->pow != curr1->pow)) {
            curr1 = curr1->next;
        }
        if (curr1 == NULL) {
            insert(*curr2);
        }
        curr2 = curr2->next;
    }
    
    curr1 = curr2 = NULL;
    
    return *this;
}

Polynomial Polynomial::operator*(Polynomial p2)
{
    Polynomial p3;
    Element *curr1 = head;
    Element *curr2 = p2.head;
    
    while (curr1 != NULL) {
        while (curr2 != NULL) {
            int coeff = curr1->coeff * curr2->coeff;
            int pow = curr1->pow + curr2->pow;
            Element multEl(coeff, pow);
            p3.insert(multEl);
            curr2 = curr2->next;
        }
        curr2 = p2.head;
        curr1 = curr1->next;
    }
    curr1 = curr2 = NULL;
    
//    Element *current = p3.head;
//    Element *temp = p3.head;
//    
//    while (current != NULL) {
//        while (temp != NULL) {
//            if (temp->pow == current->pow) {
//                //add and delete
//                current->coeff += temp->coeff;
//                delete temp;
//            }
//            temp = temp->next;
//        }
//        temp = p3.head;
//        current = current->next;
//    }
//    
//    temp = current = NULL;
    
    return p3;
}

int Polynomial::evaluate(int x)
{
    Element *current = head;
    int ans = 0;
    for (int i = 0; i < sz; i++) {
        ans += current->coeff*pow(x, current->pow);
        current = current->next;
    }
    return ans;
}

//void Polynomial::mergeSort(Element* headRef)
//{
//    head = headRef;
//    Element* a;
//    Element* b;
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
//Element* Polynomial::merge(Element *a, Element *b)
//{
//    Element *result = NULL;
//    
//    if (a == NULL)
//        return b;
//    else if (b == NULL)
//        return a;
//
//    if (b->pow <= a->pow)
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
//void Polynomial::split(Element** a, Element** b)
//{
//    Element* fast;
//    Element* slow;
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

//void Polynomial::clear()
//{
//    Element *current = head;
////        int i = 0;
//    
////        cout << "\tPolynomial::clear() preparing to remove " << sz;
////        cout << " Elements from the linked list\n";
//    
//    while (head != NULL)
//    {
////        i++;
//        head = head->next;
//        delete [] current;
//        current = head;
//        sz--;
//    }
////        cout << "\tPolynomial::clear() removed " << i << " Elements from the list\n";
////        cout << "\tPolynomial::clear() new count is: " << sz << endl;
//}


#endif /* Polynomial_h */
