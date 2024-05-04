#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class robot {
  public:
  // define variables
  // data numbers
  string name;
  int charge;
  // member functions
  void status() {
    cout << "[robot: " << name << ", charge: " << charge << "]\n";
  }
  // constructors (like BeginPLay)
  // a constructor runs when a new instance is created
  robot(string givenName = "Rob", int givenCharge = 10) {
    cout << "A new robot has been created!\n";
    name = givenName;
    charge = givenCharge;
    status();
  }
  // getters and setters
  void SetName(string givenName) {
    name = givenName;
  }
  void SetCharge(int givenCharge) {
    if(givenCharge < 0) {
      charge = givenCharge;

    }
    else {
      charge = 0;
        
      }
  }
  // getters
  string GetName() { return name; }
  string GetCharge() { return std::string(); }
};

int main() {
  srand(time(0));
  cout << "Let's make some classes!\n";
  // creating a new variable of the type "robot" named "robalobba"
  robot robalobba;  // this is where the constructor function is called
  robalobba.name = "Robalobba Danielson";
  robalobba.charge = 19;
  cout << "My robot's name is " << robalobba.name << ".\n";
  cout << "My robot's charge is " << robalobba.charge << ".\n";
  robalobba.status();

  // create a new robot intstance and use the constructor to five it a custom name and charge
  robot robert("Robert Robotson", 5);
  robot robby("Robby Robotnik", 12);

  vector<robot> bots;
  vector<string> names {"Rob", "Robalobba", "Robert", "Robby", "Roberta", "Robotie", "Robertus", "Robnus"};

  for(int i = 0; i < 10; i++) {
    string tempName = names[rand() % 4];
    int tempCharge = rand() % 5 + 5;
    bots.push_back(robot(tempName, tempCharge));
    
  }

  cout << "Our first bot in the list is: \n";
  bots[0].status();
}