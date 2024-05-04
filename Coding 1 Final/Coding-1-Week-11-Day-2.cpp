#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

// an emuperator is a custom variable type that evaluates to an integer
enum itemType {
// equal to 0, 1, and 2, respectively
  weapon, tool, consumable
};

enum elementalType {
  basic = 0, fire = 1 , ice = 2, candy = 3, slime = 4
};

// a class is a custom variable type that contains data and functions
class enemy {

};

class item {
public:
    itemType type;
    int damage;
    string name;
    elementalType element;
    int remainingUses;
    int healingAmount;

  // build a fancy constructor
    item(string n, itemType t) {
      name = n;     // assign the name of the item to the given name
      type = t;
    
      if(type == weapon) {
        // calculate damage and elemental
        damage = rand() % 5 + 3;
        element = (elementalType)(rand() % 4);  // typecast an int into an elemental type
        remainingUses = 9999;
        healingAmount = 0;
      }
      else if(type == tool) {
        damage = 1;
        element = basic;
        remainingUses = rand() % 5 + 1;
        healingAmount = 0;
      }

    else if(type == consumable) {
      healingAmount = rand() % 5 + 1;
      damage = -healingAmount;
      element = basic;
      remainingUses = 1;
    }    
   } // end of constructor

  void Inspect() {
    cout << name << " has damage of " << damage << ", it's element is " << elementToString(element) << "\n";
    cout << "It can be used " << remainingUses << " more times, heals for " << healingAmount << " HP\n";
    cout << "It's item type is a " << typeToString(type) << "\n";
  }

  string typeToString(itemType type) {
    switch(type) {
      case weapon: 
        return "weapon"; 
        break;
      case tool: 
        return "tool"; 
        break;
      case consumable: 
        return "consumable";
        break;
      default: 
        return "unknown";
        break;
    }
  }

string elementToString(elementalType element) {
  switch(element) {
    case basic: return "basic"; break;
    case fire: return "fire"; break;
    case ice: return "ice"; break;
    case candy: return "candy"; break;
    case slime: return "slime"; break;
    default: return "unknown"; break;
  }
}

};



int main() {
  srand(time(0));
  cout << "More Classes!\n";

 
  vector<string> weaponNames = { "Excalibur", "Masamune", "Frostmourne", "Anduril", "Sting", "Caladbolg", "Zulfiqar", "Glamdring", "Chrysaor", "Durandal" };
  random_shuffle(weaponNames.begin(), weaponNames.end()); // #include <algorithm>


  item sword("Sword", weapon);
  sword.Inspect();

  vector<item> weapons;

  for(int i = 0; i < weaponNames.size(); i++) {
    weapons.push_back(item(weaponNames[i], weapon));  // create a weapon
    weapons[i].Inspect();  // display the newly created weapon
  }

/* RECAP
enumerators are a custom variable type  with a limited number of possible values
switch statements map all the possible outcimes to a single test
classes can have other classes inside of them (enemy can hold and item)
typecasting is when we want the compiler to change a variable into a another variable
AI is great for generating a vector of names
*/

/* HOMEWORK
create BASIC adventure functionality using the enemy class for each encounter
each enemy must use a weapon
each enemy must has health
player has option of using weapon or consumable

Grading based on enemt class, does it have the functionailty that it needs to interact with the player
*/
  
}