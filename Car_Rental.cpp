#include <iostream>
#include <string>
using namespace std;

struct Car {
    int id;
    string brand;
    string model;
    int year;
    float rentPerDay;
    bool available;
};

const int MAX_CARS = 10;
Car cars[MAX_CARS] = {
    {1, "Toyota", "Hilux", 2020, 65.0, true},
    {2, "Honda", "Civic", 2019, 45.0, true},
    {3, "Ford","Mustang",2021, 300.0, true},
    {4, "Hyundai", "Creta", 2023, 50.0, true},
    {5, "BMW", "X1", 2022, 150.0, true},
    {6, "Audi", "Q8", 2024, 180.0, true},
    {7, "kia","Seltos", 2023, 40.0, true},
    {8, "jeep","Compass", 2025, 55.0, true},
    {9, "skoda","slavia", 2025, 30.0, true},
    {10,"Tata", "Harrier", 2024, 60.0, true}
};

void showAvailableCars() {
    cout << "\nAvailable Cars:\n";
    cout << "ID\tBrand\tModel\tYear\tPrice/Day\n";
    for (int i = 0; i < MAX_CARS; i++) {
        if (cars[i].available) {
            cout << cars[i].id << "\t" << cars[i].brand << "\t"
                 << cars[i].model << "\t" << cars[i].year << "\t$"
                 << cars[i].rentPerDay << endl;
        }
    }
}

void rentCar() {
    int carId, days;
    showAvailableCars();
    cout << "\nEnter Car ID to rent: ";
    cin >> carId;
    cout << "Enter number of days: ";
    cin >> days;

    bool found = false;
    for (int i = 0; i < MAX_CARS; i++) {
        if (cars[i].id == carId && cars[i].available) {
            float total = days * cars[i].rentPerDay;
            cars[i].available = false;
            cout << "\nYou have rented " << cars[i].brand << " " << cars[i].model << " for " << days << " days.\n";
            cout << "Total amount: $" << total << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Car not available or invalid ID.\n";
    }
}

void returnCar() {
    int carId;
    cout << "\nEnter Car ID to return: ";
    cin >> carId;
    bool found = false;
    for (int i = 0; i < MAX_CARS; i++) {
        if (cars[i].id == carId && !cars[i].available) {
            cars[i].available = true;
            cout << "Car returned successfully.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Invalid ID or car was not rented.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== Car Rental System =====\n";
        cout << "1. Show Available Cars\n";
        cout << "2. Rent a Car\n";
        cout << "3. Return a Car\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: showAvailableCars(); break;
            case 2: rentCar(); break;
            case 3: returnCar(); break;
            case 4: cout << "Thank you for using the system.\n"; break;
            default: cout << "Invalid option. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
