#ifndef BANKERS_ALGORITHM_HPP
#define BANKERS_ALGORITHM_HPP

#include <fstream>
#include <iostream>
#include <vector>

// Constants
const int Max_Processes = 5;
const int Max_Resources = 3;

// Function declarations
void calculate_need(int needed[][Max_Processes], int maximum[][Max_Processes], int allocated[][Max_Processes]);

bool safe_check(int available[], int maximum[][Max_Processes], int allocated[][Max_Processes]);

#endif // BANKERS_ALGORITHM_HPP
