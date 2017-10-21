//
//  main.cpp
//  project2
//
//  Created by Rachael So on 10/10/17.
//  Copyright © 2017 Rachael So. All rights reserved.
//

#include <fstream>
#include "Polynomial.h"

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
        try {
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
                unsigned pow;
                string line;
                Polynomial poly1;
                Polynomial poly2;
                Polynomial poly3;
                
                getline(inputFile, line);
                istringstream iss1(line);
                while (iss1 >> coeff >> pow) {
                    Element x(coeff, pow);
    //                cout << x.print() << endl;
                    poly1.insert(x);
                }
    //            poly3 = poly1^2;
    //            poly3.print();
    //            cout << poly3.evaluate(10) << endl;
                
                getline(inputFile, line);
                istringstream iss2(line);
                while (iss2 >> coeff >> pow) {
                    Element x(coeff, pow);
    //                cout << x.print() << endl;
                    poly2.insert(x);
                }
                
                cout << "Polynomial 1: ";
                poly1.print();
                cout << "evaluated at x=10" << poly1.evaluate(10) << endl << endl;
                
                cout << "Polynomial 2: ";
                poly2.print();
                cout << "evaluated at x=10: " << poly2.evaluate(10) << endl << endl;
                
                cout << "Polynomial 1 and 2 added: ";
                poly3 = poly1+poly2;
                poly3.print();
                cout << "evaluated at x=10: " << poly3.evaluate(10) << endl << endl;
          
                cout << "Polynomial 1 and 2 multiplied: ";
                poly3 = poly1*poly2;
                poly3.print();
                cout << "evaluated at x=2: " <<  poly3.evaluate(2) << endl << endl;
                
                cout << "Polynomial 1 raised to the 3rd: ";
                poly3 = poly1^3;
                poly3.print();
                cout << endl;
                
                cout << "Polynomial 1 raised to the value of Polynomial 2 evaluated at 5:\n";
                int p2eval5 = poly2.evaluate(5);
                poly3 = poly1^p2eval5;
                poly3.print();
                
            } //END else if (inputFile) statement
        } //END try statement
        catch (overflow_error &e){
            cout << e.what() << endl;
        }
    } //END if/else statement
} //END main
