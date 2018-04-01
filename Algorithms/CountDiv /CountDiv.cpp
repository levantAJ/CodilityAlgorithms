//
//  CountDiv.cpp
//  Algorithms
//
//  Created by levantAJ on 1/4/18.
//  Copyright © 2018 levantAJ. All rights reserved.
//

/*
 Write a function:
 
 int solution(int A, int B, int K);
 
 that, given three integers A, B and K, returns the number of integers within the range [A..B] that are divisible by K, i.e.:
 
 { i : A ≤ i ≤ B, i mod K = 0 }
 
 For example, for A = 6, B = 11 and K = 2, your function should return 3, because there are three numbers divisible by 2 within the range [6..11], namely 6, 8 and 10.
 
 Assume that:
 
 A and B are integers within the range [0..2,000,000,000];
 K is an integer within the range [1..2,000,000,000];
 A ≤ B.
 Complexity:
 
 expected worst-case time complexity is O(1);
 expected worst-case space complexity is O(1).
 */

#include "CountDiv.hpp"

#include <vector>

using namespace std;

int solution(int A, int B, int K) {
    int count = B / K;
    if (A > K) {
        count = count - A / K;
    }
    if (A % K == 0 && A != K) {
        count++;
    }
    return count;
}

