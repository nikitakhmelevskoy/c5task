#include <iostream>
using namespace std;

struct Machine {
    char Case;

    union {
        struct {double Diesel; char model;} Toyota;
        struct {double Fuel; char model;} Bmw;
    };
};

Machine inputInformationAboutCar(char cs) {

    Machine machine;
    machine.Case = cs;

    if (machine.Case == 1) {
        cout << "Diesel consumption";
        cin >> machine.Toyota.Diesel;
        cout << "Model of car: ";
        cin >> machine.Toyota.model;
    } else {
        cout << "Fuel consumption";
        cin >> machine.Bmw.Fuel;
        cout << "Model of car: ";
        cin >> machine.Bmw.model;
    }

    return machine;
}

void outputInformationAboutCar(Machine machine) {
    if (machine.Case == 1) {
        cout << "Diesel consumption" << machine.Toyota.Diesel << endl;
        cout << "Model of car: " << machine.Toyota.model << endl;
    } else {
        cout << "Fuel consumption" << machine.Bmw.Fuel << endl;
        cout << "Model of car: " << machine.Bmw.model << endl;
    }
}

int main() {
    Machine DataBase[10],
            machine = {0, {0, 0}};

    int i, j;
    for (i = 0; i < sizeof(DataBase) / sizeof(Machine); i++)
        DataBase[i] = machine;

    while (true) {
        cout << "Menu:" << endl
        << "1. Enter information about car." << endl
        << "2. Output of information about car." << endl
        << "3. Output of all information." << endl
        << "4. Delete information about car." << endl
        << "5. Delete of all information." << endl
        << "6. Finish the job." << endl
        << ">";
        cin >> i;

        switch (i) {
            case 1:
                cout << "Number: ";
                cin >> i;
                cout << "Option (1-Toyota, 2-Bmw): ";
                cin >> j;
                DataBase[i] = inputInformationAboutCar(j);
                break;

            case 2:
                cout << "Number: ";
                cin >> i;
                outputInformationAboutCar(DataBase[i]);
                break;

            case 3:
                for (i = 0; i < sizeof(DataBase) / sizeof(Machine); i++) {
                    if (DataBase[i].Case != 0) {
                        cout << "Car number " << i << ":" << endl;
                        outputInformationAboutCar(DataBase[i]);
                    }
                }
                break;

            case 4:
                cout << "Number: ";
                cin >> i;
                DataBase[i] = machine;
                break;

            case 5:
                for (i = 0; i < sizeof(DataBase) / sizeof(Machine); i++) {
                    DataBase[i] = machine;
                    cout << endl;
                }
                break;

            case 6:
                return 1;
            default:
                cout << "Try again, please!" << endl;
        }
    }
}