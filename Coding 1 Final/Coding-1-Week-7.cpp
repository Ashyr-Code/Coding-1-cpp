// Coding 1 Week 7


#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// declaring and defining a function
// calling a function
// retun types and returning values
// input parameters

// functions are reuable blocks of code that can be called into another function

// declaring and defining our function
// void means that it does not return a value

void SayHello() {
  cout << "Hello!\n";
}

void ShowVector(vector<string> vec) {
  for(int i = 0; i < vec.size(); i++) {
    cout << vec[i] << ". \n";
  }
}
// declaring and defining a new function named "CastDamage"
// it has  two input parameters, min and max, which are both integers.
// it's return type is int, which means it will send back an integer value.

int CastDamage(int min, int max) {
  // roll for damage
  int damage = rand() % (max - min) + min;

  //crit check. if rand() is 5, double damage
  int critRoll = rand() % 5;
  if (critRoll == 4) {
    // double damage
    cout << "Critical Hit!\n";
    damage += damage;
  }

  return damage;
}

string BossFight() {
  cout << "You are fighting a boss!\n";
  cout << "How much health do you have?.\n";
  int playerHealth;
  cin >> playerHealth;

  playerHealth -= CastDamage(5, playerHealth);

  if (playerHealth > 0) {
    cout << "alive\n";
    return "alive";
  }
  else {
    cout << "dead\n";
    return "dead";
  }
}


int main() {
  srand(time(0));
  SayHello(); // calling our function
  string playerState = BossFight();
  cout << "The player is " << playerState << "!\n";

  for (int i = 0; i < 10; i++) {
      cout << "The enemy has done " << CastDamage(5, 10) << " damage!\n";
  }
  
  vector<string> hateFoods = {"egg yolk, mushrooms, raw onion, dog food, steak"};

  ShowVector(hateFoods);

  cout << "Right, so those are the foods that I hate. OH! I forgot, I also hate soggy bread. \n";
  hateFoods.push_back("soggy bread");
  
  ShowVector(hateFoods);

  cout << "I also don't care for small rodents... they don't taste very good. \n";
  hateFoods.push_back("humans");

  ShowVector(hateFoods);

  
  
}