//
//  MinAvgTwoSlice.cpp
//  Algorithms
//
//  Created by levantAJ on 1/4/18.
//  Copyright © 2018 levantAJ. All rights reserved.
//

/*
 A non-empty zero-indexed array A consisting of N integers is given. A pair of integers (P, Q), such that 0 ≤ P < Q < N, is called a slice of array A (notice that the slice contains at least two elements). The average of a slice (P, Q) is the sum of A[P] + A[P + 1] + ... + A[Q] divided by the length of the slice. To be precise, the average equals (A[P] + A[P + 1] + ... + A[Q]) / (Q − P + 1).
 
 For example, array A such that:
 
 A[0] = 4
 A[1] = 2
 A[2] = 2
 A[3] = 5
 A[4] = 1
 A[5] = 5
 A[6] = 8
 contains the following example slices:
 
 slice (1, 2), whose average is (2 + 2) / 2 = 2;
 slice (3, 4), whose average is (5 + 1) / 2 = 3;
 slice (1, 4), whose average is (2 + 2 + 5 + 1) / 4 = 2.5.
 The goal is to find the starting position of a slice whose average is minimal.
 
 Write a function:
 
 int solution(vector<int> &A);
 
 that, given a non-empty zero-indexed array A consisting of N integers, returns the starting position of the slice with the minimal average. If there is more than one slice with a minimal average, you should return the smallest starting position of such a slice.
 
 For example, given array A such that:
 
 A[0] = 4
 A[1] = 2
 A[2] = 2
 A[3] = 5
 A[4] = 1
 A[5] = 5
 A[6] = 8
 the function should return 1, as explained above.
 
 Assume that:
 
 N is an integer within the range [2..100,000];
 each element of array A is an integer within the range [−10,000..10,000].
 Complexity:
 
 expected worst-case time complexity is O(N);
 expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
 */

#include "MinAvgTwoSlice.hpp"

#include <limits>
#include <vector>

using namespace std;

int minAvgTwoSlice(vector<int> &A) {
    if (A.size() == 2) {
        return 0;
    }
    
    int index = 0;
    double min = numeric_limits<double>::max();
    double avg;
    
    for (unsigned int i = 0; i < A.size() - 2; i++) {
        avg = (A[i] + A[i + 1]) * 1.0 / 2;
        if (avg < min) {
            min = avg;
            index = i;
        }
        
        avg = (A[i] + A[i + 1] + A[i + 2]) * 1.0 / 3;
        if (avg < min) {
            min = avg;
            index = i;
        }
    }
    
    avg = (A[A.size() - 2] + A[A.size() - 1]) * 1.0 / 2;
    if (avg < min) {
        min = avg;
        index = A.size() - 2;
    }
    
    return index;
}


