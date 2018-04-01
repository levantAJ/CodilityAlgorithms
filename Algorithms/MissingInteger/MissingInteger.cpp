//
//  MissingInteger.cpp
//  Algorithms
//
//  Created by levantAJ on 31/3/18.
//  Copyright © 2018 levantAJ. All rights reserved.
//

/*
 Write a function:
 
 int solution(vector<int> &A);
 
 that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.
 
 For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.
 
 Given A = [1, 2, 3], the function should return 4.
 
 Given A = [−1, −3], the function should return 1.
 
 Assume that:
 
 N is an integer within the range [1..100,000];
 each element of array A is an integer within the range [−1,000,000..1,000,000].
 Complexity:
 
 expected worst-case time complexity is O(N);
 expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
 */

#include "MissingInteger.hpp"

#include <algorithm>
#include <vector>

using namespace std;

int missingInteger(vector<int> &A) {
    vector<bool> v;
    for (int i = 0; i < A.size(); i++) {
        int element = A[i];
        if (element < 0) {
            continue;
        }
        if (element >= v.size()) {
            v.resize(element + 1);
        }
        v[element] = true;
    }
    if (v.empty()) {
        return 1;
    }
    for (int i = 1; i < v.size(); i++) {
        if (!v[i]) {
            return i;
        }
    }
    return (int)v.size();
}
