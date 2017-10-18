//
//  main.cpp
//  project2
//
//  Created by Rachael So on 10/10/17.
//  Copyright © 2017 Rachael So. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "Polynomial.h"
#include "Element.h"

using namespace std;

int main(int argc, const char * argv[])
{
    //variable declarations
    string fName = argv[1];
    ifstream inputFile;
    
    if (argc < 2) {
        cout << "ERROR: NEED INPUT FILE";
    }
    else {
        //start of program
        //get file from command line argument
        inputFile.open(fName.c_str());
        
        //check if file opens
        if (!inputFile) {
            cout << "Failed to open file" << endl;
        }
        else if (inputFile) {
            cout << "opened file!" << endl;
            
            int coeff;
            int pow;
            string line;
            Polynomial poly1;
            Polynomial poly2;
            Polynomial poly3;
            Polynomial poly4;
            
            getline(inputFile, line);
            istringstream iss1(line);
            while (iss1 >> coeff >> pow) {
                Element x(coeff, pow);
//                cout << x.print() << endl;
                poly1.insert(x);
            }
//            poly1.mergeSort(poly1.head);
            poly1.print(); cout << endl;
            cout << poly1.evaluate(10) << endl;
            poly3 = poly1^2;
//            poly3.print();
//            cout << poly3.evaluate(10) << endl;
            
            getline(inputFile, line);
            istringstream iss2(line);
            while (iss2 >> coeff >> pow) {
                Element x(coeff, pow);
//                cout << x.print() << endl;
                poly2.insert(x);
            }
//            poly2.print();
//            
//            poly4 = poly1 + poly2;
//            poly4.print();
            
        } //END else if (inputFile) statement
    } //END if/else statement
} //END main
