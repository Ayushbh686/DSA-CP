#include <iostream>
using namespace std;

class Gun {
    private:
        string name;
        int scope;
        int ammo;
        int damage;
    public:
        void setName(string name) {
            this->name = name;
        }

        void setScope(int scope) {
            this->scope = scope;
        }

        void setDamage(int damage) {
            this->damage = damage;
        }

        void setAmmo(int ammo) {
            this->ammo = ammo;
        }

        void getName() {
            cout << "Gun Name: " << this->name << endl;
        }

        void getScope() {
            cout << "Scope: " << this->scope << endl;
        }

        void getDamage() {
            cout << "Damage: " << this->damage << endl;
        }

        void getAmmo() {
            cout << "Ammo: " << this->ammo << endl;
        }
};

class player {
    class Hand {
        private:
            string name;
            int damage;
            int life;
        public:
            void setName(string name) {
                this->name = name;
            }

            void setDamage(int damage) {
                this->damage = damage;
            }

            void setLife(int life) {
                this->life = life;
            }

            void getName() {
                cout << "Hand Name: " << this->name << endl;
            }

            void getDamage() {
                cout << "Hand Damage: " << this->damage << endl;
            }

            void getLife() {
                cout << "Hand Life: " << this->life << endl;
            }
    };
    private:
        int HP;
        int Speed;
        string name;
        bool isAlive;
        Gun* gun[2];  // Dynamic allocation for Gun objects
        Hand* hand;   // Dynamic allocation for Hand object
        
    public:
        void allocateResources() { // can be done using constructor
            // Allocate memory for guns and hand
            for (int i = 0; i < 2; ++i) {
                gun[i] = new Gun();
            }
            hand = new Hand();
        }

        void deallocateResources() { // can be done using destructor
            // Deallocate memory for guns and hand
            for (int i = 0; i < 2; ++i) {
                delete gun[i];
            }
            delete hand;
        }

        void setHealth(int Hp) {
            this->HP = Hp;
        }

        void setSpeed(int speed) {
            this->Speed = speed;
        }

        void setname(string name) {
            this->name = name;
        }

        void setisAlive() {
            if (this->HP == 100) this->isAlive = true;
            else this->isAlive = false;
        }

        void setGun1(string name, int scope, int ammo, int damage) {
            this->gun[0]->setName(name);
            this->gun[0]->setAmmo(ammo);
            this->gun[0]->setScope(scope);
            this->gun[0]->setDamage(damage);
        }

        void setGun2(string name, int scope, int ammo, int damage) {
            this->gun[1]->setName(name);
            this->gun[1]->setAmmo(ammo);
            this->gun[1]->setScope(scope);
            this->gun[1]->setDamage(damage);
        }

        void setHand(string name, int damage, int life) {
            this->hand->setName(name);
            this->hand->setLife(life);
            this->hand->setDamage(damage);
        }

        void getHealth() {
            cout << "Health: " << this->HP << endl;
        }

        void getSpeed() {
            cout << "Speed: " << this->Speed << endl;
        }

        void getName() {
            cout << "Name: " << this->name << endl;
        }

        void getisAlive() {
            cout << "Is Alive: " << (this->isAlive ? "Yes" : "No") << endl;
        }

        void getGun1() {
            cout << "Gun 1 Details:" << endl;
            this->gun[0]->getName();
            this->gun[0]->getAmmo();
            this->gun[0]->getScope();
            this->gun[0]->getDamage();
        }

        void getGun2() {
            cout << "Gun 2 Details:" << endl;
            this->gun[1]->getName();
            this->gun[1]->getAmmo();
            this->gun[1]->getScope();
            this->gun[1]->getDamage();
        }

        void getHand() {
            cout << "Hand Details:" << endl;
            this->hand->getName();
            this->hand->getLife();
            this->hand->getDamage();
        }
};

void playerDetails(player &p) {
    p.getName();
    p.getHealth();
    p.getSpeed();
    p.getisAlive();
    p.getGun1();
    p.getGun2();
    p.getHand();
}

int main() {
    // Dynamic allocation of player object
    player* Ayush = new player();
    
    Ayush->allocateResources();  // Allocate resources for guns and hand

    Ayush->setname("Ashu");
    Ayush->setHealth(90);
    Ayush->setisAlive();
    Ayush->setSpeed(150);
    Ayush->setGun1("Awm", 8, 15, 150);
    Ayush->setGun2("Tamancha", 1, 10, 1000);
    Ayush->setHand("knife", 20, 50);
    playerDetails(*Ayush);

    Ayush->deallocateResources();  // Deallocate resources for guns and hand
    delete Ayush;  // Deallocate player object
    
    return 0;
}

// nested classes , array of class , passing class in function , dynamic allocation 