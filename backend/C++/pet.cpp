// Experimental Code.
#include <iostream>
#include <string>

using namespace std;

struct Pet {
    string type;
    string breed;
    double price;

    Pet(string _type, string _breed, double _price) : type(_type), breed(_breed), price(_price) {}
};

int main() {
    Pet pets[] = {
        Pet("Dog", "Labrador", 500),
        Pet("Dog", "German Shepherd", 600),
        Pet("Dog", "Golden Retriever", 550),
        Pet("Dog", "Bulldog", 450),
        Pet("Cat", "Siamese", 400),
        Pet("Cat", "Persian", 450),
        Pet("Cat", "Maine Coon", 500),
        Pet("Cat", "Sphynx", 550),
        Pet("Bird", "Parrot", 300),
        Pet("Bird", "Canary", 250),
        Pet("Bird", "Cockatiel", 200),
        Pet("Bird", "Finch", 150),
        Pet("Fish", "Goldfish", 20),
        Pet("Fish", "Betta", 15),
        Pet("Fish", "Guppy", 10),
        Pet("Fish", "Angelfish", 25)
    };

    cout << "Welcome to the Pet Adoption Center!" << endl;
    cout << "Choose a pet type:" << endl;
    cout << "1. Dog" << endl;
    cout << "2. Cat" << endl;
    cout << "3. Bird" << endl;
    cout << "4. Fish" << endl;

    int petChoice;
    cout << "Enter your choice (1-4): ";
    cin >> petChoice;

    if (petChoice >= 1 && petChoice <= 4) {
        cout << "You have chosen a " << pets[(petChoice - 1) * 4].type << "." << endl;
        cout << "Choose a breed:" << endl;

        for (int i = 0; i < 4; ++i) {
            cout << i + 1 << ". " << pets[(petChoice - 1) * 4 + i].breed << " ($" << pets[(petChoice - 1) * 4 + i].price << ")" << endl;
        }

        int breedChoice;
        cout << "Enter your choice of breed (1-4): ";
        cin >> breedChoice;

        if (breedChoice >= 1 && breedChoice <= 4) {
            cout << "You have chosen a " << pets[(petChoice - 1) * 4 + breedChoice - 1].type << " of breed " << pets[(petChoice - 1) * 4 + breedChoice - 1].breed << " with a price of $" << pets[(petChoice - 1) * 4 + breedChoice - 1].price << endl;

            double totalCost = pets[(petChoice - 1) * 4 + breedChoice - 1].price;
            char addFood;
            cout << "Do you want to add food for your pet? (y/n): ";
            cin >> addFood;

            if (addFood == 'y' || addFood == 'Y') {
                cout << "Here are the available food options:" << endl;
                cout << "1. Premium food ($50)" << endl;
                cout << "2. Standard food ($30)" << endl;
                cout << "3. Economy food ($20)" << endl;
                cout << "4. No food" << endl;

                int foodChoice;
                cout << "Enter your choice of food (1-4): ";
                cin >> foodChoice;

                switch (foodChoice) {
                    case 1:
                        cout << "You have chosen Premium food." << endl;
                        totalCost += 50;
                        break;
                    case 2:
                        cout << "You have chosen Standard food." << endl;
                        totalCost += 30;
                        break;
                    case 3:
                        cout << "You have chosen Economy food." << endl;
                        totalCost += 20;
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

            cout << "Total cost: $" << totalCost << endl;
        } else {
            cout << "Invalid breed choice. Please choose a number between 1 and 4." << endl;
        }
    } else {
        cout << "Invalid pet type choice. Please choose a number between 1 and 4." << endl;
    }

    return 0;
}
