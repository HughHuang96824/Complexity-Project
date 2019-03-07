//
//  main.cpp
//  Complexity
//
//  Created by Hugh on 2019/1/9.
//  Copyright © 2019 Yaojia Huang. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <map>
#include "Oslo.hpp"

using std::cout;
using std::endl;
using std::map;

int main() {
    
    
    /////////////////////////// TASK 1 //////////////////////////
    // System of size 3
    int n = 3;
    // Probability of get threshold slope = 1 is 100%
    Oslo t1(n, 1);
    
    for (int i = 0; i < 1000; i++) {
        t1.InsertGrain();
        cout << "Height: " << t1.Height() << ",  Avalanche: ";
        cout << t1.AvalancheSize() << endl;
    }
    
    // System of size 3
    n = 32;
    Oslo t2(n);
    
    // Insert 200000 grains
    int loop = 20000;
    // Start collecting statistics at t = 10000
    int steady = 2000;
    
    // Calculate average height
    double height = 0;
    for (int i = 0; i <= loop; i++) {
        t2.InsertGrain();
        if (i > steady)
            height += t2.Height();
    }
    cout << "Average height: " << height / (double)(loop - steady) << endl;
    
    
    
    /*
     
    // CODE THAT RECORDS DATA AND WRITES COLUMN FILE
    path = "Path of your choice";

    std::ofstream myfile;
    myfile.open(path);
    
    int N = 101000000;
    int steady = 1000000;
    Oslo t(256);

    for (int i = 0; i < N; i++) {
        t.InsertGrain();
        
        if (i >= steady) {
            // An example of writing two-column files
            // the first column is avalanche size and the second is height
            myfile << t.AvalancheSize() << "\n" << t.Height();
            if (i % 5000000 == 0)
                cout << i << endl;
        }
    }
    */
}
