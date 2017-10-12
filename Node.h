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
    int info;
    Node *next;
    Node *previous;
    
    Node(int, Node*, Node*);
};

Node::Node( int value, Node *n, Node *p )
{
    info = value;
    next = n;
    previous = p;
    
} // END default constructor for Node class


#endif /* Node_h */
