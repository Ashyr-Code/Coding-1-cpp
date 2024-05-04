#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int RollDie(int sides = 6) {
    return rand() % sides + 1;
}

string askYesNo(string question) {
    string response;
    cout << question << " (yes/no): ";
    cin >> response;
    return response;
}

int main() {
    srand(time(0));

    int playerHealth = 10;
    int goldFound = 0;
    int turnsSurvived = 0;

    do {
        string response = askYesNo("Would you like to go adventuring?");
        if (response == "yes") {
            int orcAttack = RollDie(10); // Orc's attack (1-10)
            int playerBlock = RollDie(); // Player's block (1-6)

            cout << "You encounter a very muscular orc!\n";
            cout << "The bodacious orc attacks with a strength of: " << orcAttack << endl;
            cout << "You, a feeble adventurer, attempt to block the attack coming forthright...\n";

            if (playerBlock >= orcAttack) {
                cout << "You, somehow, successfully block the attack! ";
                playerHealth--;
                goldFound += RollDie(20); // Random gold found (1-20)
                cout << "You lose 1 health point and escape with " << goldFound << " gold.\n";
            } else {
                cout << "You miserably fail to block the attack!\n";
                playerHealth -= orcAttack;
                if (playerHealth > 0)
                    cout << "You lose " << orcAttack << " health points and barely escape with the skin on your back.\n";
            }

            turnsSurvived++;
        } else {
            break;
        }

    } while (playerHealth > 0);

    if (playerHealth <= 0) {
        cout << "You are dead. Figures. You managed to collect " << goldFound << " gold.\n";
    } else {
        cout << "You are alive!";
        cout << "You survived " << turnsSurvived << " turns and collected " << goldFound << " gold.\n";
        if (playerHealth < 5)
            cout << "You should REALLY consider going to the doctor, your health is low and you don't look so good.\n";
    }

    return 0;
}