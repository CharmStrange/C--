#include <iostream>
#include <string>

#include "HEADERS\BEGIN.h"
#include "HEADERS\MAIN.h"
#include "HEADERS\DATA.h"
#include "HEADERS\CONTAINER.h"

using namespace std;

class BEGIN_CONTAINER;
class MAIN_CONTAINER;
class DATA_CONTAINER;

// Definition of static member variables : CONTAINER.h
US PLAYER_SAVE::number_of_player_saves = 0;
vector<PLAYER_SAVE> PLAYER_SAVE::PLAYER_SAVES;

int main() {
    /*
    RUN_BEGIN(); // "HEADERS\BEGIN.h"
    RUN_MAIN(); // "HEADERS\MAIN.h"
    RUN_DATA(); // "HEADERS\DATA.h"
    */

    // Testing
   INVENTORY inv;
   inv.add_ITEMS(healingItemsMap, inv.Inventory, 1);

   RUN_BEGIN();

}
