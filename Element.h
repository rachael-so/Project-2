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
    Element(int, unsigned);
    ~Element();
};

Element::Element(int coeff, unsigned pow)
{
    this->coeff = coeff;
    this-> pow = pow;
    this->a = new int[2];
    
    a[0] = coeff;
    a[1] = pow;
}

Element::~Element()
{
    delete [] a;
}

#endif /* Element_h */
