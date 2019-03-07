//
//  Oslo.hpp
//  Complexity
//
//  Created by Hugh on 2019/1/9.
//  Copyright © 2019 Yaojia Huang. All rights reserved.
//

#ifndef Oslo_hpp
#define Oslo_hpp

#include <vector>
#include <random>
using std::vector;

class Oslo {
private:
    int size;               // System size
    vector<int> config;     // Configuration of the system
    vector<int> slope;      // Local slopes
    vector<int> criti_slope;// Local critical slopes
    int avalanche_size;     // Sizes of avalanches triggered between consecutive states
    int amount;             // Number of grains in the pile
    int tc;                 // Time when first grain leaves the system
    int p;                  // Probability of setting the thresold slope to be 1
    bool new_insert;        // Flag for newly inserted grain
    
    std::mt19937 mt;        // MT19937 Mersenne Twister
    std::uniform_real_distribution<double> critical; // Threshold slope generator
    
    // Function that relaxes the system
    bool RelaxSystem();

public:
    // Default system size
    static int default_size;
    void DefaultSize(const int& size);
    
    // Constructor and destructor
    Oslo();
    Oslo(const int& L, const double& p = 0.5);
    ~Oslo();

    // Get the configuration of the system
    const vector<int>& Configuration() const;
    
    // Get the height of the pile
    int Height();
    
    // Get the size of the avalanche triggered by the previous insertion
    int AvalancheSize();
    
    // Get the total number of grains in the system
    int Amount();
    
    // Get the time when first grain leaves the system
    int Tc();
    
    // Add one grain at the first site
    void InsertGrain();
};


#endif /* Oslo_hpp */
