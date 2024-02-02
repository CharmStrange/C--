#ifndef ITEMS_H
# define ITEMS_H

# include <iostream>
# include <vector>
# include <string>
# include <map>

# include "CONTAINER.h"

using namespace std;

// Define your Item_Structure
struct Item_Structure {
    string Name;
    unsigned short lbs;
    unsigned char Type;
};

// itemsMap
// Type of healingItemsMap : H
map<UC, Item_Structure> healingItemsMap = {
    {1, {"Health Potion", 1, 'H'}},
    {2, {"Healing Elixir", 2, 'H'}},
    {3, {"Revitalizing Herb", 1, 'H'}},
    {4, {"Rejuvenation Tonic", 1, 'H'}},
    {5, {"Recovery Salve", 1, 'H'}},
    {6, {"Renewal Potion", 2, 'H'}},
    {7, {"Restorative Elixir", 2, 'H'}},
    {8, {"Vitality Extract", 1, 'H'}},
    {9, {"Healing Crystal", 1, 'H'}},
    {10, {"Revive Syrup", 2, 'H'}},
    // ... add more healing items
};

// Type of utilityItemsMap : U
map<UC, Item_Structure> utilityItemsMap = {
    {1, {"Adaptive Camouflage Cloak", 3, 'U'}},
    {2, {"Ethereal Teleportation Stone", 4, 'U'}},
    {3, {"Invisibility Potion", 1, 'U'}},
    {4, {"Dimensional Pocket Watch", 1, 'U'}},
    {5, {"Gravity-defying Boots", 2, 'U'}},
    {6, {"Energy-boosting Gauntlet", 2, 'U'}},
    {7, {"Mind-controlling Amulet", 1, 'U'}},
    {8, {"Illusionary Smoke Bomb", 1, 'U'}},
    {9, {"Temporal Distortion Device", 2, 'U'}},
    {10, {"Lunar Phase Shifter", 2, 'U'}},
    // ... add more utility items
};

// Type of buffItemsMap : B
map<UC, Item_Structure> buffItemsMap = {
    {1, {"Strength-Enhancing Elixir", 1, 'B'}},
    {2, {"Agility-boosting Serum", 2, 'B'}},
    {3, {"Intellect-boosting Potion", 1, 'B'}},
    {4, {"Fortitude Tonic", 1, 'B'}},
    {5, {"Luck Infusion Elixir", 1, 'B'}},
    {6, {"Speed Booster Serum", 2, 'B'}},
    {7, {"Resistance-boosting Draught", 2, 'B'}},
    {8, {"Wisdom Amplification Elixir", 1, 'B'}},
    {9, {"Evasion Elixir", 1, 'B'}},
    {10, {"Focus Enhancement Brew", 2, 'B'}},
    // ... add more buff items
};

// Type of weaponsMap : W
map<UC, Item_Structure> weaponsMap = {
    {1, {"Legendary Sword of Justice", 5, 'W'}},
    {2, {"Enchanted Bow of Precision", 4, 'W'}},
    {3, {"Arcane Staff of Destruction", 6, 'W'}},
    {4, {"Mystical Dagger of Shadows", 2, 'W'}},
    {5, {"Thunderstrike Hammer", 8, 'W'}},
    {6, {"Venomous Crossbow", 3, 'W'}},
    {7, {"Firebrand Greatsword", 7, 'W'}},
    {8, {"Frostbite Wand", 4, 'W'}},
    {9, {"Soulbound Katana", 6, 'W'}},
    {10, {"Celestial Scepter", 5, 'W'}},
    // ... add more weapons
};

// Type of armorSetsMap : A
map<UC, Item_Structure> armorSetsMap = {
    {1, {"Dragonscale Armor", 10, 'A'}},
    {2, {"Celestial Robes", 8, 'A'}},
    {3, {"Shadow Veil Cloak", 3, 'A'}},
    {4, {"Titanic Plate Mail", 12, 'A'}},
    {5, {"Stealth Assassin Garb", 6, 'A'}},
    {6, {"Frozen Heart Plate", 11, 'A'}},
    {7, {"Ethereal Silk Robes", 7, 'A'}},
    {8, {"Inferno Battlegear", 9, 'A'}},
    {9, {"Guardian's Aegis", 15, 'A'}},
    {10, {"Nature's Embrace Ensemble", 8, 'A'}},
    // ... add more armor sets
};

// Type of accessoriesMap : C
map<UC, Item_Structure> accessoriesMap = {
    {1, {"Amulet of Stealth", 1, 'C'}},
    {2, {"Ring of Elemental Resistance", 2, 'C'}},
    {3, {"Bracelet of Time Distortion", 1, 'C'}},
    {4, {"Necklace of Teleportation", 2, 'C'}},
    {5, {"Gloves of Power", 1, 'C'}},
    {6, {"Earrings of Wisdom", 1, 'C'}},
    {7, {"Belt of Strength", 1, 'C'}},
    {8, {"Boots of Speed", 2, 'C'}},
    {9, {"Crown of Arcane Mastery", 1, 'C'}},
    {10, {"Brooch of Luck", 1, 'C'}},
    // ... add more accessories
};

// Type of magicalArtifactsMap : M
map<UC, Item_Structure> magicalArtifactsMap = {
    {1, {"Crystal of Time Manipulation", 3, 'M'}},
    {2, {"Orb of Elemental Mastery", 2, 'M'}},
    {3, {"Aegis of Divine Protection", 5, 'M'}},
    {4, {"Amulet of Ancient Wisdom", 4, 'M'}},
    {5, {"Phoenix Feather Talisman", 1, 'M'}},
    {6, {"Chalice of Eternal Youth", 2, 'M'}},
    {7, {"Starlight Prism Pendant", 3, 'M'}},
    {8, {"Scepter of Arcane Power", 6, 'M'}},
    {9, {"Oculus of Astral Vision", 2, 'M'}},
    {10, {"Eternal Flame Relic", 4, 'M'}},
    // ... add more magical artifacts
};

#endif
