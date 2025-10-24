// Dataanalys IOT 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "data_manager.h"
#include <iostream>
#include <string>
#include <limits>
#define NOMINMAX
#include <windows.h>
#include <clocale>

using namespace std;

int main() {

    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    setlocale(LC_ALL, "en_US");

    DataManager dm;
    const string filename = "temperatures.csv";
    dm.readFile(filename);
    dm.saveFile(filename);

    while (true) {
        cout << "\n--- MENU ---\n"
            << "1) Add temperature\n"
            << "2) Show statistics\n"
            << "3) Show all\n"
            << "4) Save\n"
            << "5) Sort\n"
            << "6) Exit\n"
            << "Choice: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.\n";
            continue;
        }

        switch (choice) {
        case 1: {
            cout << "How many temperatures do you want to add? ";
            int count;
            if (!(cin >> count) || count <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid number.\n";
            }

            for (int i = 0; i < count; ++i) {
                cout << "Enter temperature " << (i + 1) << ": ";
                double value;
                if (!(cin >> value)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                dm.add(value, DataManager::currentTime());
            }
            break;

        }
        case 2: {
            auto s = dm.calculate();
            if (s.count == 0) {
                cout << "No data.\n";
                break;
            }
            cout << "Count: " << s.count << "\n"
                << "Sum: " << s.sum << "\n"
                << "Average: " << s.average << "\n"
                << "Min:   " << s.min << "\n"
                << "Max:   " << s.max << "\n"
                << "StdDev: " << s.stddev << "\n";
            break;
        }
        case 3:
            dm.showAll();
            break;
        case 4:
            dm.saveFile(filename);
            cout << "Saved.\n";
            break;
        case 5: {
            cout << "Sort (1=ascending, 0=descending): ";
            int order;
            if (!(cin >> order)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input.\n";
                break;
            }
            dm.sort(order != 0);
            cout << "Sorted.\n";
            break;
        }
        case 6:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
