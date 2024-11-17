# OS-Project1 - The Consumer Producer Problem
- *Tested on CentOS via Kent State University's Wasp/Hornet Servers*

## Project Assignment:

In this programming assignment, you are required to provide the source codes, documents, and examples in detail on github. You only need to submit your GitHub project to me.  

### Requirements:

You are required to use C/C++ in Linux/Unix. You can consider installing virtualBox in your non-Linux environment.
Programs must succeed in compilation and execution as required (80 points)
Readme, documentation, and example are required (20 points).

### Banker’s Algorithm for deadlock avoidance.

Considering a system with five processes P0 through P4 and three resources of type A, B, C. Resource type A has 10 instances, B has 5 instances and type C has 7 instances.

### Implement the Banker’s algorithm to answer the following question： 

Is the system in a safe state? If Yes, then what is the safe sequence?

### What should be included in the submission:
- Source codes (C/C++)
- Input file (you should create an input file, e.g., .txt, with your customized format that stores the data that is provided in the table).  
- Your code should print out the safe sequence if the system is safe.
- Documents and readme.

## Running this Code:

After cloning the repository locally, this program can be compiled and executed using the following command:
```{bash}
make run
```

To clean-up the files made to run the program, enter the command:
```{bash}
make clean
```

When you run the program, you will then be prompted to enter a input file for the code to test. This file must be in the same root directory of the codebase.
```{bash}
./bankers
Enter the input file name: 
```

There are a few pre-made files to use as tests
- data1.txt
- data2.txt
- data3.txt

### Example Input (data3.txt):
```
0 1 2
2 0 1
1 2 1
3 0 0
1 1 1
7 5 3
6 4 2
5 3 3
4 3 3
4 2 2
3 3 2
```
- The first 5 rows represent the Allocation Matrix.
- The next 5 rows represent the Maximum Demand Matrix.
- The last row represents the Available Resources.

## Expected Outputs:

### data1.txt:
```{bash}
./bankers
Enter the input file name: data1.txt
System is in a safe state, safe sequence is: P1 -> P3 -> P4 -> P0 -> P2
```

### data2.txt:
```{bash}
./bankers
Enter the input file name: data2.txt
System is not in a safe state, Banker's algorithm cannot be applied.
```
### data3.txt:
```{bash}
./bankers
Enter the input file name: data3.txt
System is in a safe state, safe sequence is: P4 -> P1 -> P2 -> P3 -> P0
```

## Alternative way to compile, run, & cleanup

You can also run the code manually using the following commands:
```{bash}
g++ bankers_main.cpp bankers_math.cpp -o bankers
./bankers
```

Then to clean up the create files, run these commands:
```{bash}
rm bankers
```

## Full Example Execution:
```{bash}
[asternb1@wasp OS-Project2]$ make run
g++ -std=c++11 -Wall -c bankers_main.cpp
g++ -std=c++11 -Wall -c bankers_math.cpp
g++ -std=c++11 -Wall -o bankers bankers_main.o bankers_math.o
./bankers
Enter the input file name: data3.txt
System is in a safe state, safe sequence is: P4 -> P1 -> P2 -> P3 -> P0
[asternb1@wasp OS-Project2]$ make clean
rm -f bankers bankers_main.o bankers_math.o
```

- *An additional photo of running code can be found with the example.png file*