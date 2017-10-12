# Project-2

Classes: Polynomial, Element, Node

Element:
    private-
        int coeff
        unsigned pow
        int *a

Polynomial:
    private-
        Polynomial *next
    public-
        void insert(int, unsigned)
        string print()
        string addedPoly()
        string multPoly()
        double evaluate()

Node:
    public-
        int info
        Node<int> *next
        Node<int> *previous
        Node<int>(int, Node<int>* = NULL, Node<int>* = NULL)
