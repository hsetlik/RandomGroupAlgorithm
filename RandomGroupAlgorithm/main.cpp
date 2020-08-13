//
//  main.cpp
//  RandomGroupAlgorithm
//
//  Created by Hayden on 8/11/20.
//  Copyright © 2020 Hayden Setlik. All rights reserved.
//

#include <iostream>
#include "RandomGroupClasses.hpp"

int main(int argc, const char * argv[]) {
    Grid grid;
    grid.init(16, 16);
    printf("Grid initialized\n");
    Space firstSpace = grid.memberSpaces[4][3];
    Group group;
    group.init(firstSpace, grid);
    printf("BEGINNING GROUP FILLING \n");
    group.fillGroup(7);
    group.printGroup();
    return 0;
}
