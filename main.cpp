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
            
            int x;
            string line;
            
            getline(inputFile, line);
            istringstream iss(line);
            while (iss >> x) {
                cout << x << endl;
            }

        }
    }
}
