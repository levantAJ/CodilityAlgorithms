//
//  BinaryGap.cpp
//  Algorithms
//
//  Created by levantAJ on 30/3/18.
//  Copyright © 2018 levantAJ. All rights reserved.
//

#include <iostream>
#include "BinaryGap.hpp"

using namespace std;

int binaryGap(int N) {
    int currentGap = 0;
    int gap = 0;
    int n = N;
    int remainder = 0;
    bool shouldCount = false;
    while (n > 0) {
        remainder = n % 2;
        if (remainder) {
            if (currentGap > 0) {
                gap = max(gap, currentGap);
                currentGap = 0;
            }
            shouldCount = true;
        } else if (shouldCount) {
            currentGap++;
        }
        n = n / 2;
    }
    return max(gap, currentGap);
}
