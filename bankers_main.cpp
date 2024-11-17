#include "bankers.hpp"

int main() {
    int available[Max_Resources];
    int maximum[Max_Processes][Max_Resources];
    int allocated[Max_Processes][Max_Resources];

    std::string filename;
    std::cout << "Enter the input file name: ";
    std::cin >> filename;
    std::ifstream bankers_file(filename);

    if (!bankers_file) {
        std::cerr << "Error opening file\n";
        return 1;
    }

    // Read allocated resources matrix
    for (int i = 0; i < Max_Processes; ++i) {
        for (int j = 0; j < Max_Resources; ++j) {
            bankers_file >> allocated[i][j];
        }
    }

    // Read maximum resources matrix
    for (int i = 0; i < Max_Processes; ++i) {
        for (int j = 0; j < Max_Resources; ++j) {
            bankers_file >> maximum[i][j];
        }
    }

    // Read available resources
    for (int i = 0; i < Max_Resources; ++i) {
        bankers_file >> available[i];
    }

    bankers_file.close();

    // Call safe_check function
    safe_check(available, maximum, allocated);

    return 0;
}
