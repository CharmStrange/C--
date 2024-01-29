#ifndef CONTAINER_H
# define CONTAINER_H

// MACROS
# define UC unsigned char // 1B, 0~255
# define US unsigned short // 2B, 0~65535 
# define MAX_SAVES 3
# define MAX_LOGS 10

// ESSENTIAL HEADERS
# include <iostream>
# include <string>
# include <deque>  // Using deque for easy insertion and removal at both ends
# include <vector>

using namespace std;

class PLAYER_SAVE;

// [Container]: Player saves
class PLAYER_SAVE {
private:
    static vector<PLAYER_SAVE> PLAYER_SAVES;
    static US number_of_player_saves;

    US player_save_id;
    string save_data;

public:
    PLAYER_SAVE(const string& data) : player_save_id(number_of_player_saves++), save_data(data) {
        // If the container is full, remove the oldest save
        if (PLAYER_SAVES.size() == MAX_SAVES) {
            PLAYER_SAVES.erase(PLAYER_SAVES.begin());
        }
        PLAYER_SAVES.push_back(*this);
    }

    static void display_saves() {
        cout << "[ Player Save ] : [";
        for (const auto& player_save : PLAYER_SAVES) {
            cout << player_save.save_data;
            if (&player_save != &PLAYER_SAVES.back()) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    ~PLAYER_SAVE() {}

    friend class PLAYER_LOG;
};

// [ Container ] : player logs
class PLAYER_LOG {
public:
    PLAYER_LOG() = default;

    deque<string> player_logs;  // Using deque for easy insertion and removal

    void add_log(const string& log) {
        if (player_logs.size() == MAX_LOGS) {
            // If the container is full, remove the oldest log
            player_logs.pop_front();
        }
        player_logs.push_back(log);
    }

    void display_logs() const {
        cout << "[ Player Log ] :";
        for (const auto& player_log : player_logs) {
            cout << " | " << player_log;
        }
    }

    ~PLAYER_LOG() {}
};

// [ Container ] : Entities
struct Entity_friendly {
    string Name;
    US Type;
    UC Level;
    US Health;
    US Energy;
    US Defense;
    US Power;
    US Dexterity;
    US Intelligence;
    US Wariness;
};

struct Entity_neutral {
    string Name;
    US Type;
    UC Level;
    US Health;
    US Energy;
    US Defense;
    US Power;
    US Dexterity;
    US Intelligence;
    US Wariness;
};

struct Entity_hostile {
    string Name;
    US Type;
    UC Level;
    US Health;
    US Energy;
    US Defense;
    US Power;
    US Dexterity;
    US Intelligence;
    US Wariness;
};

#endif
