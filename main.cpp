#include <iostream>
#include <string>

#include "HEADERS\BEGIN.h"
#include "HEADERS\MAIN.h"
#include "HEADERS\DATA.h"

#include "SYSTEM\CONTAINER.h"

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
   PLAYER_SAVE a("Aa");
   a.display_saves();

   PLAYER_SAVE b("Bb");
   b.display_saves();

   PLAYER_SAVE c("Cc");
   c.display_saves();
}
