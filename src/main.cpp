#include <iostream>
#include <string>
#include "sensorapp.hpp"

using namespace std;

void printMenu() {
    cout << "\n===== MENU =====" << endl;
    cout << "1 - Register Sensor" << endl;
    cout << "2 - Update Reading" << endl;
    cout << "3 - Search Sensor" << endl;
    cout << "4 - Remove Sensor" << endl;
    cout << "5 - Display Sensors" << endl;
    cout << "0 - Exit" << endl;
    cout << "Choose an option: ";
}

int main(int argc, char* argv[]) {
    TableMode mode = TableMode::CHAINING;

    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "--open" || arg == "-o") {
            mode = TableMode::OPEN_ADDRESSING;
        } else if (arg == "--chaining" || arg == "-c") {
            mode = TableMode::CHAINING;
        }
    }

    SensorApp sensorApp(mode);
    int iOption;

    do {
        printMenu();
        cin >> iOption;

        switch (iOption) {
            case 1:
                sensorApp.registerSensor();
                break;
            case 2:
                sensorApp.updateReading();
                break;
            case 3:
                sensorApp.searchSensor();
                break;
            case 4:
                sensorApp.removeSensor();
                break;
            case 5:
                sensorApp.displaySensors();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
        }

    } while (iOption != 0);

    return 0;
}
