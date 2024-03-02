#ifndef MAIN_H
# define MAIN_H

// ESSENTIAL HEADERS
# include <iostream>

// other HEADERS
# include "CONTAINER.h"
# include "GAME_ALGORITHM.h"

using namespace std;


void compare_stats();
void versus(const string& player, const string& ENTITY) {
    compare_stats();
}

#endif