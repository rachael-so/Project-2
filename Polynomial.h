//
//  Polynomial.h
//  project2
//
//  Created by Rachael So on 10/10/17.
//  Copyright © 2017 Rachael So. All rights reserved.
//

#ifndef Polynomial_h
#define Polynomial_h

#include <cmath>
#include <stdexcept>
#include <climits>
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
    ~Polynomial();
    void insert(Element);
    void print();
    Polynomial& operator=(const Polynomial &rhs);
    Polynomial operator+(Polynomial&);
    Polynomial operator*(Polynomial&);
    Polynomial operator^(unsigned);
    int evaluate(int);
    void clear();
    
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
        
//        head = tail = NULL;
    }


//        cout << "Polynomial::~Polynomial() Exiting destructor for class Polynomial\n";

}

//My insert method self-organizes the list so that when elements are added in it is automatically
//organized into standard polynomial form. Therefore, if the element being added in is being
//inserted into the middle of the list the step count is linear, otherwise it is just a constant
//step count.
void Polynomial::insert(Element value)
{
    overflow_error e("ERROR: Overflow in Polynomial::insert");
//    cout << "entering insert: coeff=" << value.coeff << " pow=" << value.pow << endl;
    Element *addMe = new Element(value.coeff, value.pow);
    try {
        if (addMe->coeff > INT_MAX) {
            addMe->coeff = INT_MAX;
            throw e;
        }
        else if (addMe->pow > INT_MAX) {
            addMe->pow = INT_MAX;
            throw e;
        }
        if (head == NULL) {
            // this is first object to be added to the list
            head = tail = addMe;
        }
        else if (addMe->pow > head->pow) {
            addMe->next = head;
            head = addMe;
        }
        else if (addMe->pow < tail->pow) {
            tail->next = addMe;
            addMe->next = NULL;
            tail = addMe;
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
            }
            else if ( current->next != NULL && addMe->pow == current->next->pow) {
                current = current->next;
                current->coeff += addMe->coeff;
                
                if (current->coeff > 0 && (current->coeff - addMe->coeff) < 0 && addMe->coeff < 0) {
                    current->coeff = INT_MAX;
                    throw e;
                }
                
                else if (current->coeff < 0 && (current->coeff - addMe->coeff) > 0
                         && addMe->coeff > 0) {
                    current->coeff = INT_MAX;
                    throw e;
                }
                
                delete addMe;
                addMe = NULL;
                sz--;
            }
        }
    }
    catch (overflow_error &e) {
        cout << "ERROR: Overflow in Polynomial::insert" << endl;
        throw e;
    }
    sz++;
    
//    cout << "exiting insert\n";
}


//print method just traverses and uses cout statements to print out the polynomial
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

//Overloaded assignment operator step count is the insert step count twice plus the traversal.
Polynomial& Polynomial::operator=(const Polynomial &rhs)
{
    Element *temp;
    temp = rhs.head;
    
    clear();
    
    try {
        while (temp) {
            insert(*temp);
            temp = temp->next;
        }
    }
    catch (overflow_error &e) {
        cout << "ERROR: Overflow in Polynomial::operator=" << endl;
        cout << e.what() << endl;
        throw e;
    }
    
    return *this;
}

//Step count is insert operator twice plus the traversal
Polynomial Polynomial::operator+(Polynomial &p2)
{
    Polynomial p;
    p = *this;
    Element *current = p2.head;
    
    try {
        while (current != NULL) {
            p.insert(*current);
            current = current->next;
        }
    }
    catch (overflow_error &e) {
        cout << "ERROR: Overflow in Polynomial::operator+" << endl;
        cout << e.what() << endl;
    }
    
    return p;
}
//This has a O(n^2) step count plus the step count for insert.
Polynomial Polynomial::operator*(Polynomial &p2)
{
    overflow_error e("ERROR: Overflow in Polynomial::operator*");
    Polynomial p;
    Element *curr1 = head;
    Element *curr2 = p2.head;
    
    try {
        while (curr1 != NULL) {
            while (curr2 != NULL) {
//                cout << "curr1->coeff=" << curr1->coeff << " curr2->coeff=" << curr2->coeff << endl;
//                cout << "curr1->pow=" << curr1->pow << " curr2->pow=" << curr2->pow << endl;
                int coeff = curr1->coeff * curr2->coeff;
                unsigned pow = curr1->pow + curr2->pow;
//                cout << "coeff=" << coeff << endl;
//                cout << "pow=" << pow << endl << endl;
                Element multEl(coeff, pow);
                p.insert(multEl);
                
                if ((curr1->coeff > 0 && curr2->coeff > 0 && coeff < 0) ||
                    (curr1->coeff < 0 && curr2->coeff < 0 && coeff < 0)) {
                    throw e;
                }
                
                curr2 = curr2->next;
            }
            curr2 = p2.head;
            curr1 = curr1->next;
        }
        curr1 = curr2 = NULL;
    }
    catch (overflow_error &e) {
        cout << "ERROR: Overflow in Polynomial::operator*" << endl;
        cout << e.what() << endl;
        throw e;
    }

    return p;
}

//I used the speed up from class in order to do this method. This makes it so that the the answer
//doesn't multiply the original number but the exponentiated number on top of the exponentiated
//answer. This just speeds up the steps because there are less multiplications having to be done.
Polynomial Polynomial::operator^(unsigned pow)
{
    Polynomial p;
    Polynomial temp;
    
    try {
        p = *this;
        
        if (pow % 2 == 0) {
            for (int i = 1; i <= pow/2; i++) {
                temp = p * p;
                p = temp;
            }
        }
        else {
            for (int i = 1; i <= pow/2; i++) {
                temp = p * p;
                p = temp;
            }
            //one more time
            temp = p * *this;
            p = temp;
        }
    }
    catch (overflow_error &e) {
        cout << "ERROR: Overflow in Polynomial::operator^" << endl;
        cout << e.what() << endl;
    }
    
    return p;
}

//This just calls the the addition and assignment operator and traverses the list.
int Polynomial::evaluate(int x)
{
    overflow_error e("ERROR: Overflow in Polynomial::evaluate");
    Element *current = head;
    int ans = 0;
    
    try {
        while (current != NULL) {
            
            ans += current->coeff*pow(x, current->pow);
            
//            cout << "here: " << ans-(current->coeff*pow(x, current->pow)) << endl;
//            cout << "next: " << current->coeff*pow(x, current->pow) << endl;
            
            if (ans-(current->coeff*pow(x, current->pow)) > 0
                && current->coeff*pow(x, current->pow) > 0 && ans < 0) {
                throw e;
            }
            else if (ans-(current->coeff*pow(x, current->pow)) < 0
                     && current->coeff*pow(x, current->pow) < 0 && ans > 0) {
                throw e;
            }
            
            current = current->next;
        }
    }
    catch (overflow_error &e) {
        cout << "ERROR: Overflow in Polynomial::evaluate" << endl;
        throw e;
    }
    
    return ans;
}

//This just traverses the list and deletes.
void Polynomial::clear()
{
    Element *current = head;
//        int i = 0;

//        cout << "\tPolynomial::clear() preparing to remove " << sz;
//        cout << " Elements from the linked list\n";
    
    while (head != NULL)
    {
//        cout << "deleting node with: " + current->print() << endl;
//        i++;
        head = head->next;
        delete current;
        current = head;
        sz--;
    }
    
    current = NULL;
//        cout << "\tPolynomial::clear() removed " << i << " Elements from the list\n";
//        cout << "\tPolynomial::clear() new count is: " << sz << endl;
}


#endif /* Polynomial_h */
