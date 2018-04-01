//
//  FrogJump.cpp
//  Algorithms
//
//  Created by levantAJ on 31/3/18.
//  Copyright © 2018 levantAJ. All rights reserved.
//

#include "FrogJump.hpp"

int frogJump(int X, int Y, int D) {
    int distance = Y - X;
    int step = distance / D;
    if (distance % D != 0) {
        step++;
    }
    return step;
}
