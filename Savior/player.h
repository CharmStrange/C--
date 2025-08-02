#ifndef PLAYER_H
#define PLAYER_H

#define FaithThreshold 0
#define rageThreshold 0

#include <iostream>

#include <string>

#include <vector>

using namespace std;

class Player {
private:
	string name;
	unsigned short energy;
	short faith;
	unsigned short rage;
	unsigned short power;
	
public:
	Player(const string& name, unsigned short energy, short faith, unsigned short rage, unsigned short power) : name(name), energy(energy), faith(faith), rage(rage), power(power) {}
	
	void showStatus() const {
        cout << "\n--- Player Status ---\n";
        cout << "Name: " << name << "\n";
        cout << "Energy: " << energy << "\n";
        cout << "Faith: " << faith << "\n";
        cout << "Rage: " << rage << "\n";
        cout << "Power: " << power << "\n";
        cout << "---------------------\n\n";
	}
	
    // 플레이어의 액션을 나타내는 메서드
    void pray(int amount);     // 신앙심에 따라 효과가 달라짐
    void confront();           // 타락한 성직자와 대면
    void useAbility(const string& abilityName);
	
    void loseFaith(int amount) {
        faith -= amount;
        if (faith < FaithThreshold) faith = 0;
        /// cout << "당신의 신앙이 흔들립니다. (" << amount << " 감소)\n";
    }

    void gainRage(int amount) {
        rage += amount;
        if (rage > rageThreshold) rage = 100;
        // cout << "분노가 솟아오릅니다. (" << amount << " 증가)\n";
    }

    void acquirePower(int amount) {
        power += amount;
        // cout << "잠재된 힘이 커집니다. (" << amount << " 증가)\n";
    }

    void useRageAbility() {
        if (rage >= rageThreshold) {
            // cout << "분노를 소모하여 강력한 힘을 사용합니다!\n";
            rage -= 20;
            // ... 능력 발동 로직
        } else {
            /// std::cout << "분노가 충분하지 않습니다.\n";
        }
    }
};

#endif