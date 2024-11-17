#include "bankers.hpp"

void calculateNeed(int need[][Max_Resources], int max[][Max_Resources], int allocation[][Max_Resources]) {
    for (int i = 0; i < Max_Processes; i++) {
        for (int j = 0; j < Max_Resources; j++) {
            need[i][j] = max[i][j] - allocation[i][j];  // Calculate the need for each process
        }
    }
}

bool safe_check(int available[], int maximum[][Max_Resources], int allocated[][Max_Resources]) {
    int need[Max_Processes][Max_Resources];
    calculateNeed(need, maximum, allocated);  // Calculate the need matrix

    bool finish[Max_Processes] = {false};  // Initialize finish array to false
    std::vector<int> safe_sequence;        // Vector to store safe sequence
    int work[Max_Resources];               // Work array to keep track of available resources

    // Initialize work with available resources
    for (int i = 0; i < Max_Resources; i++) {
        work[i] = available[i];
    }

    int completed = 0;  // Counter for completed processes
    while (completed < Max_Processes) {
        bool found = false;
        for (int i = 0; i < Max_Processes; i++) {
            if (!finish[i]) {  // If process i is not finished
                bool can_allocate = true;
                // Check if the process can be allocated the necessary resources
                for (int j = 0; j < Max_Resources; j++) {
                    if (need[i][j] > work[j]) {  // If need exceeds available work, it cannot be allocated
                        can_allocate = false;
                        break;
                    }
                }

                if (can_allocate) {
                    // If the process can be allocated, update work array and finish the process
                    for (int j = 0; j < Max_Resources; j++) {
                        work[j] += allocated[i][j];  // Add allocated resources back to work
                    }
                    safe_sequence.push_back(i);  // Add process to the safe sequence
                    finish[i] = true;            // Mark the process as finished
                    completed++;                 // Increment the completed counter
                    found = true;                // Mark that we found a process to allocate
                }
            }
        }

        if (!found) {
            std::cout << "System is not in a safe state, Banker's algorithm cannot be applied.\n";
            return false;
        }
    }

    // Print the safe sequence
    std::cout << "System is in a safe state, safe sequence is: ";
    for (std::vector<int>::size_type i = 0; i < safe_sequence.size(); ++i) {
        std::cout << "P" << safe_sequence[i];
        
        if (i < safe_sequence.size() - 1) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;

    return true;  // Return true if the system is in a safe state
}
