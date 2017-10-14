//
//  Node.h
//  project1
//
//  Created by Rachael So on 10/12/17.
//  Copyright © 2017 Rachael So. All rights reserved.
//

#ifndef Node_h
#define Node_h

/****************************************************************************
 *                        class Node declaration                            *
 ****************************************************************************/

class Node
{
public:
    Element info;
    Node *next;
    Node *previous;
    
    Node(Element, Node*, Node*);
};

Node::Node(Element value, Node *n, Node *p)
{
    info = value;
    next = n;
    previous = p;
    
} // END default constructor for Node class


#endif /* Node_h */
