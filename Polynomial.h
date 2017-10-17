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
//    ~Polynomial();
    //Polynomial(int, unsigned, Polynomial*);
    void insert(Element);
    void print();
    Polynomial operator+(Polynomial);
    Polynomial operator*(Polynomial);
    int evaluate(int);
//    void mergeSort(Node*);
//    Node* merge(Node*, Node*);
//    void split(Node**, Node**);
//    void clear();
    Node *head;
    
private:
    int sz;
};

Polynomial::Polynomial()
{
    this->sz = 0;
    this->head = NULL;
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
        if (current->info.coeff != 1)
            cout << current->info.coeff;
        if (current->info.pow != 0)
            cout << "x";
        if (current->info.pow != 1)
            cout << "^" << current->info.pow;
        if (current->next->info.coeff > 0)
            cout << "+";
        current = current->next;
    }
    cout << current->info.coeff << "x^" << current->info.pow << endl;
}

Polynomial Polynomial::operator+(Polynomial p2)
{
    Node *curr1 = head;
    Node *curr2 = p2.head;
    
    while (curr1 != NULL) {
        while (curr2 != NULL && (curr2->info.pow != curr1->info.pow)) {
            curr2 = curr2->next;
        }
        if (curr2 != NULL) {
            curr1->info.coeff += curr2->info.coeff;
        }
        curr2 = p2.head;
        curr1 = curr1->next;
    }
    
    curr1 = head;
    
    //add rest of curr2
    while (curr2 != NULL) {
        while (curr1 != NULL && (curr2->info.pow != curr1->info.pow)) {
            curr1 = curr1->next;
        }
        if (curr1 == NULL) {
            insert(curr2->info);
        }
        curr2 = curr2->next;
    }
    
    curr1 = curr2 = NULL;
    
    return *this;
}

Polynomial Polynomial::operator*(Polynomial p2)
{
    Polynomial p3;
    Node *curr1 = head;
    Node *curr2 = p2.head;
    
    while (curr1 != NULL) {
        while (curr2 != NULL) {
            int coeff = curr1->info.coeff * curr2->info.coeff;
            int pow = curr1->info.pow + curr2->info.pow;
            Element multEl(coeff, pow);
            p3.insert(multEl);
            cout << p3.head->info.coeff;
            curr2 = curr2->next;
        }
        curr2 = p2.head;
        curr1 = curr1->next;
    }
    curr1 = curr2 = NULL;
    
    Node *current = p3.head;
    Node *temp = p3.head;
    
    while (current != NULL) {
        while (temp != NULL) {
            if (temp->info.pow == current->info.pow) {
                //add and delete
                current->info.coeff += temp->info.coeff;
                delete [] temp;
            }
            temp = temp->next;
        }
        temp = p3.head;
        current = current->next;
    }
    
    temp = current = NULL;
    
    return p3;
}

int Polynomial::evaluate(int x)
{
    Node *current = head;
    int ans = 0;
    for (int i = 0; i < sz; i++) {
        ans += current->info.coeff*pow(x, current->info.pow);
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
//    if (b->info.pow <= a->info.pow)
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

//void Polynomial::clear()
//{
//    Node *current = head;
////        int i = 0;
//    
////        cout << "\tPolynomial::clear() preparing to remove " << sz;
////        cout << " Nodes from the linked list\n";
//    
//    while (head != NULL)
//    {
////        i++;
//        head = head->next;
//        delete [] current;
//        current = head;
//        sz--;
//    }
////        cout << "\tPolynomial::clear() removed " << i << " Nodes from the list\n";
////        cout << "\tPolynomial::clear() new count is: " << sz << endl;
//}


#endif /* Polynomial_h */
