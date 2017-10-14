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
            
            getline(inputFile, line);
            istringstream iss1(line);
            while (iss1 >> coeff >> pow) {
                Element x(coeff, pow);
//                cout << x.print() << endl;
                Polynomial poly1;
                poly1.insert(x);
                poly1.print();
            }
            
            getline(inputFile, line);
            istringstream iss2(line);
            while (iss2 >> coeff >> pow) {
                Element x(coeff, pow);
//                cout << x.print() << endl;
                Polynomial poly2;
                poly2.insert(x);
                poly2.print();
            }

        } //END else if (inputFile) statement
    } //END if/else statement
} //END main
