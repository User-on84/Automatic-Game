
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Player {
private:
    string username;
    int health = 100;
    int score = 0;

public:
    Player(string player) {
        username = player;
    }

    void takeDamage(int damage) {
        health -= damage;

        if (health < 0) {
            health = 0;
        }

        cout << "Your new health is: " << health << endl;
    }

    void heal(int amount) {
        health += amount;

        if (health > 100) {
            health = 100;
        }

        cout << "After recovery: " << health
             << " health points" << endl;
    }

    void addScore(int points) {
        score += points;
        cout << "Your overall points: " << score << endl;
    }

    void playerStatus() {
        if (health >= 80) {
            cout << "Player is fine!" << endl;
        }
        else if (health >= 60) {
            cout << "Problems are incoming!" << endl;
        }
        else if (health >= 40) {
            cout << "Serious problem!" << endl;
        }
        else if (health >= 20) {
            cout << "Severely injured!" << endl;
        }
        else {
            cout << username << " is dead!" << endl;
        }
    }

    bool isAlive() {
        return health > 0;
    }
};

int main() {
    srand(time(0));

    Player p1("Khem");
    int wave = 1;

    while (p1.isAlive()) {
        cout << "\n========== Wave "
             << wave << " ==========" << endl;

        int d = rand() % 20 + 1;
        cout << "Enemy dealt " << d << " damage!" << endl;

        p1.takeDamage(d);

        if (!p1.isAlive()) {
            p1.playerStatus();
            break;
        }

        int e = rand() % 8 + 1;
        cout << "You healed " << e << " hit points!" << endl;

        p1.heal(e);
        p1.addScore(20);
        p1.playerStatus();

        wave++;
        cout << "Next wave is incoming..." << endl;
    }

    cout << "\n========== GAME OVER ==========" << endl;
    cout << "Thanks for playing!" << endl;

    return 0;
}

