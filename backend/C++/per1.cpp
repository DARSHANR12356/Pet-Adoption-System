#include <iostream>
#include <string>

using namespace std;

class Pet {
private:
    string type;
    string breed;
    double price;

public:
    Pet(string _type, string _breed, double _price) : type(_type), breed(_breed), price(_price) {}

    string getType() const {
        return type;
    }

    string getBreed() const {
        return breed;
    }

    double getPrice() const {
        return price;
    }
};

int main() {
    Pet pets[] = {
        Pet("Dog", "Husky", 15000),
        Pet("Dog", "Rottweiler", 15000),
        Pet("Dog", "Golden Retriever", 15000),
        Pet("Dog", "Pug", 15000),
        Pet("Cat", "Siamese Cat", 12000),
        Pet("Cat", "Persian Cat", 12000),
        Pet("Cat", "Bombay Cat", 12000),
        Pet("Cat", "American Shorthair Cat", 12000),
        Pet("Bird", "Dove", 11000),
        Pet("Bird", "Canary", 11000),
        Pet("Bird", "Cockatiel", 11000),
        Pet("Bird", "Love Birds", 11000),
        Pet("Fish", "Goldfish", 7000),
        Pet("Fish", "Diano", 7000),
        Pet("Fish", "Cherry Barb", 7000),
        Pet("Fish", "Angelfish", 7000)
    };

    cout << "Welcome to the Pet Adoption Center!" << endl;
    cout << "Choose a pet type:" << endl;
    cout << "1. Dog" << endl;
    cout << "2. Cat" << endl;
    cout << "3. Bird" << endl;
    cout << "4. Fish" << endl;

    int petChoice;
    cout << "Enter your choice: ";
    cin >> petChoice;

    if (petChoice >= 1 && petChoice <= 4) {
        cout << "You have chosen a " << pets[(petChoice - 1) * 4].getType() << "." << endl;
        cout << "Choose a breed:" << endl;

        for (int i = 0; i < 4; ++i) {
            cout << i + 1 << ". " << pets[(petChoice - 1) * 4 + i].getBreed() << " (" << pets[(petChoice - 1) * 4 + i].getPrice() << ")" << endl;
        }

        int breedChoice;
        cout << "Enter your choice of breed: ";
        cin >> breedChoice;

        if (breedChoice >= 1 && breedChoice <= 4) {
            cout << "You have chosen a " << pets[(petChoice - 1) * 4 + breedChoice - 1].getType() << " of breed " << pets[(petChoice - 1) * 4 + breedChoice - 1].getBreed() << " with a price of " << pets[(petChoice - 1) * 4 + breedChoice - 1].getPrice() << endl;

            double totalCost = pets[(petChoice - 1) * 4 + breedChoice - 1].getPrice();
            char addFood;
            cout << "Do you want to add food for your pet? (y/n): ";
            cin >> addFood;

            if (addFood == 'y' || addFood == 'Y') {
                cout << "Here are the available food options:" << endl;
                cout << "1. Premium food (90000)" << endl;
                cout << "2. Standard food (30000)" << endl;
                cout << "3. Economy food (10000)" << endl;
                cout << "4. No food" << endl;

                int foodChoice;
                cout << "Enter your choice of food: ";
                cin >> foodChoice;

                switch (foodChoice) {
                    case 1:
                        cout << "You have chosen Premium food." << endl;
                        totalCost += 90000;
                        break;
                    case 2:
                        cout << "You have chosen Standard food." << endl;
                        totalCost += 30000;
                        break;
                    case 3:
                        cout << "You have chosen Economy food." << endl;
                        totalCost += 10000;
                        break;
                    case 4:
                        cout << "No food will be added." << endl;
                        break;
                    default:
                        cout << "Invalid food choice." << endl;
                        break;
                }
            } else {
                cout << "No food will be added." << endl;
            }

            cout << "Total cost:" << totalCost << endl;
        } else {
            cout << "Invalid breed choice. Please choose a number between 1 and 4." << endl;
        }
    } else {
        cout << "Invalid pet type choice. Please choose a number between 1 and 4." << endl;
    }

    return 0;
}
