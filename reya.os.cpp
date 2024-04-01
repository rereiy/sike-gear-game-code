#include <iostream>
using namespace std;

double calculateMealTotal(int mealChoice, int mealQty) {
    double Fries = 49.00;
    double CheeseBurger = 59.00;
    double Pizza = 150.00;

    switch (mealChoice) {
        case 1:
            return Fries * mealQty;
        case 2:
            return CheeseBurger * mealQty;
        case 3:
            return Pizza * mealQty;
        default:
            return 0;
    }
}

double calculateDrinksTotal(int drinksChoice, int drinksQty) {
    double Soda = 30.00;
    double Juice = 20.00;
    double Shake = 50.00;

    switch (drinksChoice) {
        case 1:
            return Soda * drinksQty;
        case 2:
            return Juice * drinksQty;
        case 3:
            return Shake * drinksQty;
        default:
            return 0;
    }
}

double calculateDessertTotal(int dessertChoice, int dessertQty) {
    double Cake = 70.00;
    double IceCream = 50.00;
    double Donuts = 60.00;

    switch (dessertChoice) {
        case 1:
            return Cake * dessertQty;
        case 2:
            return IceCream * dessertQty;
        case 3:
            return Donuts * dessertQty;
        default:
            return 0;
    }
}

int main() {
    char order_again;
    int menu = 0;
    int Meal = 0;
    int MealQty = 0;
    int Drinks = 0;
    int DrinksQty = 0;
    int Dessert = 0;
    int DessertQty = 0;
    int cash = 0;
    double mealTotal = 0;
    double drinksTotal = 0;
    double dessertTotal = 0;
    double total = 0;
    string MealName;
	string DrinksName;
	string DessertName;
	
    jump_main:

    cout << "           +==========Menu=========+   " << endl;
    cout << "           |                       |   " << endl;
    cout << "           |  [1] Meal             |   " << endl;
    cout << "           |  [2] Drinks           |   " << endl;
    cout << "           |  [3] Dessert          |   " << endl;
    cout << "           |                       |   " << endl;
    cout << "           +=======================+   " << endl;
    cout << "           Choose from the Menu: ";
    cin >> menu;

    switch (menu) {
        case 1:
            jump_Meal:
            cout << "       +=============Meal=============+" << endl;
            cout << "       |                              |" << endl;
            cout << "       |   Products           Price   |" << endl;
            cout << "       |  [1] Fries         PHP49.00  |" << endl;
            cout << "       |  [2] CheeseBurger  PHP59.00  |" << endl;
            cout << "       |  [3] Pizza         PHP150.00 |" << endl;
            cout << "       |                              |" << endl;
            cout << "       +==============================+" << endl;
            cout << "            Choose your Meal: ";
            cin >> Meal;

            if (Meal == 1) {
                MealName = "Fries";
            } else if (Meal == 2) {
                MealName = "CheeseBurger";
            } else if (Meal == 3) {
                MealName = "Pizza";
            } else {
                cout << "Invalid Option! " << endl;
                break;
            }

            cout << "            How many?: ";
            cin >> MealQty;
            mealTotal += calculateMealTotal(Meal, MealQty);
            break;

        case 2:
            jump_Drinks:
            cout << "      +============Drinks==========+" << endl;
            cout << "      |                            |" << endl;
            cout << "      |   Products         Price   |" << endl;
            cout << "      |  [1] Soda         PHP30.00 |" << endl;
            cout << "      |  [2] Juice        PHP20.00 |" << endl;
            cout << "      |  [3] Shake        PHP50.00 |" << endl;
            cout << "      |                            |" << endl;
            cout << "      +============================+" << endl; 
            cout << "             Choose your Drinks: ";
            cin >> Drinks;

            if (Drinks == 1) {
                DrinksName = "Soda";
            } else if (Drinks == 2) {
                DrinksName = "Juice";
            } else if (Drinks == 3) {
                DrinksName = "Shake";
            } else {
                cout << "Invalid Option! " << endl;
                break;
            }

            cout << "             How many?: ";
            cin >> DrinksQty;
            drinksTotal += calculateDrinksTotal(Drinks, DrinksQty);
            break;

        case 3:
            jump_Dessert:
            cout << "     +===========Dessert==========+" << endl;
            cout << "     |                            |" << endl;
            cout << "     |   Products         Price   |" << endl;
            cout << "     |  [1] Cake         PHP70.00 |" << endl;
            cout << "     |  [2] IceCream     PHP50.00 |" << endl;
            cout << "     |  [3] Donuts       PHP60.00 |" << endl;
            cout << "     |                            |" << endl;
             cout <<"     +============================+" << endl;
            cout << "             Choose your Dessert: ";
            cin >> Dessert;

            if (Dessert == 1) {
                DessertName = "Cake";
            } else if (Dessert == 2) {
                DessertName = "Ice Cream";
            } else if (Dessert == 3) {
                DessertName = "Donuts";
            } else {
                cout << "Invalid Option! " << endl;
                break;
            }

            cout << "              How many?: ";
            cin >> DessertQty;
            dessertTotal += calculateDessertTotal(Dessert, DessertQty);
            break;

        default:
            cout << "Invalid Option! " << endl;
            break;
    }

    cout << "     Do you want to order again?[Y/N]:";
    cin >> order_again;
    if (order_again == 'Y' || order_again == 'y') {
        goto jump_main;
    } else if (order_again == 'N' || order_again == 'n') {
        total = mealTotal + drinksTotal + dessertTotal;
		
		cout << "                " << endl;
        cout << "           ORDER LIST" << endl;
        cout << "               " << endl;

        if (MealQty > 0) {
            cout <<          MealName << " x" << MealQty << " ........... " << mealTotal << " PHP" << endl;
        }
        if (DrinksQty > 0) {
            cout <<          DrinksName << " x" << DrinksQty << " ........... " << drinksTotal << " PHP" << endl;
        }
        if (DessertQty > 0) {
            cout <<          DessertName << " x" << DessertQty << " ........... " << dessertTotal << " PHP" << endl;
        }
		
		cout << "                           "<< endl;
		cout << "                           "<<endl;
        cout << "Total Price for All Items: " << total << " PHP" << endl;

        cout << "Please enter cash amount: ";
        cin >> cash;
        double change = cash - total;
        cout << "Change: " << change << " PHP" << endl;
    }

    return 0;
}