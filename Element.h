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
public:
    int coeff;
    unsigned pow;
    Element *next;
    Element();
    Element(int, unsigned);
    string print();
};

Element::Element()
{
    this->coeff = 0;
    this->pow = 0;
    this->next = NULL;
}

Element::Element(int coeff, unsigned pow)
{
    this->coeff = coeff;
    this->pow = pow;
    this->next = NULL;
}

string Element::print()
{
    string num1 = to_string(coeff);
    string num2 = to_string(pow);
    return num1 + "x^" + num2;
}

#endif /* Element_h */
