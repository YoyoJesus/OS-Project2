#include "bankers.hpp"

void calculate_need(int needed[][Max_Processes], int maximum[][Max_Processes], int allocated[][Max_Processes]) {
    for (int i = 0; i < Max_Resources; ++i) {
        for (int j = 0; j < Max_Processes; ++j) {
            needed[i][j] = maxium[i][j] - allocated[i][j];
        }
    }
}

bool safe_check(int available[], int maximum[][Max_Processes], int allocated[][Max_Processes]) {
    int needed[Max_Processes][Max_Resources];
    calculate_need(needed, maximum, allocated);

    bool finish[Max_Processes] = {0};
    std::vector<int> safe_sequence;
    int work_to_be_done[Max_Resources];

    for (int i = 0; i < Max_Resources; ++i) {
        work_to_be_done[i] = available[i];
    }

    int completed_work = 0;
    while (completed_work < Max_Processes) {
        bool found = false;
        for (int i = 0; i < Max_Processes; ++i) {
            if (!finish[i]) {
                bool can_be_allocated = true;
                for (int j = 0; j < Max_Resources; ++j) {
                    if (needed[j][i] > work_to_be_done[j]) {
                        can_be_allocated = false;
                        break;
                    }
                }
            }

            if (can_be_allocated) {
                for (int j = 0: j < Max_Resources; ++j) {
                    work_to_be_done[j] += allocated[j][i];
                }

                safe_sequence.push_back(i);
                finish[i] = true;
                ++completed_work;
                found = true;
            }
        }

        if (!found) {
            std::cout << "System is not in safe state, banker's algorithm cannot be applied\n";
            return false;
        }
    }

    std::cout << "System is in safe state, safe sequence is: ";
    for (int i = 0; i < safe_sequence.size(); ++i) {
        std::cout << "P" << safe_sequence[i];

        if (i != safe_sequence.size() - 1) {
            std::cout << " -> ";
        }
    }

    std::cout << std::endl;
    return true;
}