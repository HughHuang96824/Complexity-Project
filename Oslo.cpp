//
//  Oslo.cpp
//  Complexity
//
//  Created by Hugh on 2019/1/9.
//  Copyright © 2019 Yaojia Huang. All rights reserved.
//

#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <numeric>
#include "Oslo.hpp"


int Oslo::default_size = 16;              // Set default Oslo size (L) to 32

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// PRIVATE FUNCTIONS ///////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////// Set default system size //////////////////////////////////////
void Oslo::DefaultSize(const int& size) { // Set the default Oslo size
    Oslo::default_size = size;
}

////////////////////////////// Function that relaxes the system //////////////////////////////////
bool Oslo::RelaxSystem() {
    bool sOslo = true;

    for (int i = 0; i < size; i++){             // For all sites
        int pos = i;

        if (slope[pos] > criti_slope[pos]) {    // If the site is not sOslo
            sOslo = false;
            config[pos]--;                      // One grain at this site topples
            slope[pos]--;                       // The slope at this site decreases
            if (pos)                            // if this is not the first site
                slope[pos - 1]++;               // The slope at the previous site increases
            
            // While the slope at the current site is not less than its threshold slope
            // or the current is not equal to the system size, which means the grain is still in
            // the system.
            while (slope[pos] >= criti_slope[pos] && pos != size) {
                avalanche_size++;               // Avalanche size increases

                if ((int)critical(mt) > p)      // Resetting the threshold slope of this site
                    criti_slope[pos] = 2;
                else criti_slope[pos] = 1;
                
                pos++;                          // Move to the next site
            }

            if (pos == size) {                  // If current site is out of the system
                amount--;                       // Total number of grains decreases
                if (!tc)                        // If tc is still 0 (previously initialsed)
                    tc = -1;                    // Flag tc
            } else {
                config[pos]++;                  // The height of the current site increases
                slope[pos]++;                   // The slope of the current site increases
                slope[pos - 1]--;               // The slope of the previous site decreases
            }
        }
    }
    return sOslo;                              // Tell whether the system is sOslo
}


//////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// PUBLIC FUNCTIONS ///////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////// Default Constructor ////////////////////////////////////////
Oslo::Oslo(): Oslo(default_size, 0.5) {}

////////////////////// Constructor that sets system size and probability /////////////////////////
Oslo::Oslo(const int& L, const double& prob):
size(L), avalanche_size(0), amount(0), new_insert(false), tc(0), p(prob * 100),
config(vector<int>(L)), slope(vector<int>(L)), criti_slope(vector<int>(L)) {
    std::random_device rd;
    mt.seed(rd());
    
    // Generate integer in [1, 100]
    critical = std::uniform_real_distribution<double>(1, 101);
    
    // Randomly assign threshold slope according to the probability p
    for (int i = 0; i < size; i++) {
        if ((int)critical(mt) > p)
            criti_slope[i] = 2;
        else criti_slope[i] = 1;
    }
}

///////////////////////////////////////// Destructor /////////////////////////////////////////////
Oslo::~Oslo() {};


/////////////////////////////////// Get the configuration //////////////////////////////////////
const vector<int>& Oslo::Configuration() const {
    for (int i = 0; i < config.size(); i++)
        std::cout << config[i] << " ";
    return config;
}

////////////////////////////////// Get the height of the pile ////////////////////////////////////
int Oslo::Height() {
    return config[0];
}

/////////////// Get the size of the avalanche triggered by the previous insertion ////////////////
int Oslo::AvalancheSize() {
    return avalanche_size;
}

/////////////////////////// Get the total number of grains in the system /////////////////////////
int Oslo::Amount() {
    return amount;
}

////////////////////////// Get the time when first grain leaves the system ///////////////////////
int Oslo::Tc() {
    return tc;
}

//////////////////////////////// Add one grain at the first site /////////////////////////////////
void Oslo::InsertGrain() {
    int pre_amount = amount;        // Record the number of grains before insertion
    new_insert = true;              // This is a new insertion
    config[0]++;                    // The grain is added to the first site
    slope[0]++;                     // The slope of the first site increases by 1
    amount++;                       // Total number of grain increases by 1
    avalanche_size = 0;             // No avalanche so far

    while (!Oslo::RelaxSystem())    // While not all slopes are less than the threshold slopes
        continue;                   // Keep relaxing
    
    if (tc == -1)                   // If the tc is changed to -1
        tc = pre_amount;            // It means that the system reaches the first recurrent state
}

