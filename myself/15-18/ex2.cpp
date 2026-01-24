#include <iostream>
#include <string>

using namespace std;

class Character {
    protected:
        string name;
        int health;
        int damage;
    public:
        Character(string n, int h, int d) : name(n), health(h), damage(d) {}

        virtual ~Character(){};

        string getName() { return name; }

        bool isAlive() { return health > 0; }

        void takeDamage(int damage) {
            health -= damage;
            if (health <= 0) {
                health = 0;
            }
            cout << name << " took " << damage << " damage. HP left: " << health << endl;
        }

        virtual void attack(Character& target) = 0;
};

class Warrior : public Character {
    public:
    Warrior(string n, int h, int d) : Character(n, h, d) {}

    void attack (Character& target) {
        cout << name << " swing a sword at " << target.getName() << "!" << endl;

        target.takeDamage(damage);
    }
};

class Mage : public Character {
    public:
    Mage(string n, int h, int d) : Character(n, h, d) {}

    void attack(Character& target) {
        cout << "Mage " << name << " push fireball at " << target.getName() << "!" << endl;

        target.takeDamage(damage);
    }
};

int main() {
    Character* w = new Warrior("Arthur", 100, 15);
    Character* m = new Mage("Merlin", 60, 25);

    cout << "--- Battle Start! ---" << endl;

    while (w->isAlive() && m->isAlive()) {

        w->attack(*m);
        if (!m->isAlive()) break;

        m->attack(*w);
        if (!w->isAlive()) break;
    }

    cout << "--- Battle Over ---" << endl;

    if (w->isAlive()) {
        cout << "Winner is: " << w->getName() << "!" << endl;
    } else {
        cout << "Winner is: " << m->getName() << "!" << endl;
    }

    delete m;
    delete w;

    return 0;
}