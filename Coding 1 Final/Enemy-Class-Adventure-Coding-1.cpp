#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;


enum itemType {
  weapon, tool, consumable
};

class item {
public:
    itemType type;
    int damage;
    string name;
    int remainingUses;
    int healingAmount;

  // build a fancy constructor
    item(string n, itemType t) {
      name = n;
      type = t;

      if(type == weapon) {
        damage = rand() % 5 + 3;
        healingAmount = 0;
      }

    else if(type == consumable) {
      healingAmount = rand() % 5 + 1;
      damage = -healingAmount;
      remainingUses = 1;
    }    
   } // end of constructor

  void Inspect() {
    cout << name << " has damage of " << damage << "\n";
    cout << "It heals for " << healingAmount << " HP\n";
    cout << "This is a " << typeToString(type) << "\n";
  }

  string typeToString(itemType type) {
    switch(type) {
      case weapon: 
        return "weapon"; 
        break;
      case consumable: 
        return "consumable";
        break;
      default: 
        return "unknown";
        break;
    }
  }

};

class enemy {
  public:
    string name;
    int health;
    int damage;
    item equippedItem;
    item consumableItem;

  enemy() : name(""), health(0), damage(0), equippedItem("", weapon), consumableItem("", consumable) {}

  void equipItem(item i) {
      if (i.type == consumable) {
          consumableItem = i;
          cout << name << " is now carrying a " << consumableItem.name << "\n";
      } else {
          equippedItem = i;
          cout << name << " is equipped with " << equippedItem.name << "\n";
      }
  }

  void useConsumable() {
    if (consumableItem.remainingUses > 0) {
        health += consumableItem.healingAmount;
        consumableItem.remainingUses--;
      cout << name << " used " << consumableItem.name << " and heals for " << consumableItem.healingAmount << " HP!\n";
    }
    else {
      cout << name << " has no remaining uses of " << consumableItem.name << "\n";
    }
  }

  void attack() {
    cout << name << " attacks you for " << equippedItem.damage << " damage!\n";

  
  }
};


int main() {
  srand(time(0));

  item sword("Sword", weapon);
  sword.Inspect();

  item healthPotion("Health Potion", consumable);
  healthPotion.Inspect();

  enemy orc;
  orc.name = "Orc";
  orc.health = 10;
  orc.equipItem(healthPotion);
  orc.equipItem(sword);
  orc.useConsumable();
  orc.attack();

  return 0;
  }