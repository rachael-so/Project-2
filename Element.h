//
//  Element.h
//  project2
//
//  Created by Rachael So on 10/12/17.
//  Copyright © 2017 Rachael So. All rights reserved.
//

#ifndef Element_h
#define Element_h

using namespace std;

/****************************************************************************
 ****************************************************************************
 *                                                                          *
 *                      class Element declaration                           *
 *                                                                          *
 ****************************************************************************
 ****************************************************************************/

class Element
{
private:
    int coeff;
    unsigned pow;
    int *a;
public:
    Element();
    Element(int, unsigned);
//    ~Element();
    string print();
    int& operator[] (int);
};

Element::Element()
{
    this->coeff = 0;
    this->pow = 0;
    this->a = NULL;
}

Element::Element(int coeff, unsigned pow)
{
    this->coeff = coeff;
    this-> pow = pow;
    this->a = new int[2];
    
    a[0] = coeff;
    a[1] = pow;
}

//Element::~Element()
//{
//    delete [] a;
//}

string Element::print()
{
    string num1 = to_string(coeff);
    string num2 = to_string(pow);
    return num1 + "x^" + num2;
}

int& Element::operator[] (int i)
{
    return a[i];
}

#endif /* Element_h */
