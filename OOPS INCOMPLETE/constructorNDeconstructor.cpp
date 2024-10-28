#include <iostream>
using namespace std;

class vehicle {
    static int speed; // Static member declaration
private:
    int tyresize;
    int motor;

public:
    // Constructor with all parameters
    vehicle(int tyresize, int motor, int speed) {
        this->tyresize = tyresize;
        this->motor = motor;
        vehicle::speed = speed; // Access the static member using the class name
        cout << "constructor called\n";
    }

    // Constructor with two parameters (overloading)
    vehicle(int tyresize, int motor) : tyresize(tyresize), motor(motor) {
        cout << "function2 called\n";
    }

    // Copy constructor
    vehicle( vehicle &v) { // & used to prevent infinite loop
        this->tyresize = v.tyresize;
        this->motor = v.motor;
        // The static member `speed` is not copied because it's shared across all instances
        cout << "copy constructor called\n";
    }

    ~vehicle() {
        cout << "destructor called\n";
    }

    // Static member function to access speed
    static int getSpeed() {
        return speed;
    }

    // Function to display vehicle details
    void display() const {
        cout << "Tyresize: " << tyresize << ", Motor: " << motor << ", Speed: " << speed << endl;
    }
};

// Static member definition
int vehicle::speed = 10; // Initialization outside the class

int main() {
    cout << "Current speed (before creating car): " << vehicle::getSpeed() << endl;

    vehicle car(4, 180, 300);
    cout << "Current speed (after creating car): " << vehicle::getSpeed() << endl;

    vehicle bike(2, 100, 150);
    cout << "Current speed of bike(after creating bike): " << vehicle::getSpeed() << endl;
    cout << "Current speed of car(after creating bike): " << car.getSpeed() << endl;
    cout << "Current speed vehicle(after creating bike): " << bike.getSpeed() << endl;

    // Using the copy constructor
    vehicle copyOfCar(car); // Explicitly calling the copy constructor (deep copy)
    copyOfCar.display();

    return 0;
}
