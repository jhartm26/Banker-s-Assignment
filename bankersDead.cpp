//C++ program to illustrate Banker's Algorithm
//Operating Systems Programming Assignment #2
//Jacob Hartmann
//11/29/2021

#include <iostream>
#include <fstream>
using namespace std;

//Number of processes
const int P = 5;
//Number of resources
const int R = 3;

//Function to find the need of each process
void calculateNeed(int need[P][R], int maxm[P][R], int allot[P][R]) {
	for (int i = 0 ; i < P ; i++) {
		for (int j = 0 ; j < R ; j++) {
			//Need of instance = maxm instance - allocated instance
			need[i][j] = maxm[i][j] - allot[i][j];
		}
	}
}

//Function to find the system is in safe state or not
bool isSafe(int processes[], int avail[], int maxm[][R], int allot[][R]) {
	int need[P][R];
	calculateNeed(need, maxm, allot);

	//Mark all processes as infinish
	bool finish[P] = {0};
	//To store safe sequence
	int safeSeq[P];

	//Make a copy of available resources
	int work[R];
	for (int i = 0; i < R ; i++){
		work[i] = avail[i];
	}

	//While all processes are not finished or system is not in safe state.
	int count = 0;
	while (count < P) {
		//Find a process which is not finish and whose needs can be satisfied with current work[] resources.
		bool found = false;
		for (int p = 0; p < P; p++) {
			//First check if a process is finished, if no, go for next condition
			if (finish[p] == 0) {
				//Check if for all resources of current P need is less than work
				int j;
				for (j = 0; j < R; j++) {
					if (need[p][j] > work[j]) {
						break;
					}
				}
				//If all needs of p were satisfied.
				if (j == R) {
					//Add the allocated resources of current P to the available/work resources i.e.free the resources
					for (int k = 0 ; k < R ; k++) {
						work[k] += allot[p][k];
					}
					//Add this process to safe sequence.
					safeSeq[count++] = p;
					finish[p] = 1;
					found = true;
				}
			}
		}

		//If we could not find a next process in safe sequence.
		if (found == false) {
			cout << "System is not in safe state";
			return false;
		}
	}

	//If system is in safe state then safe sequence will be as below
	cout << "System is in safe state.\nSafe sequence is: ";
	for (int i = 0; i < P ; i++) {
		cout << safeSeq[i] << " ";
	}
	cout << endl;
	return true;
}

//Driver code
int main()
{
	int processes[] = {0, 1, 2, 3, 4};

	std::ifstream file ("input.txt");
    if(!file.is_open()) {
        std::cout << "Unable to open file\n";
    }

    while(!file.eof()) {
		//Available instances of resources
		int avail[R];
		for (int j = 0; j < R; j++) {
  			file >> avail[j];
		}

		//Resources allocated to processes
		int allot[P][R];
		for (int i = 0; i < P; i++) {
			for (int j = 0; j < R; j++) {
  				file >> allot[i][j];
			}
		}

		//Maximum R that can be allocated to processes
		int maxm[P][R];
		for (int i = 0; i < P; i++) {
			for (int j = 0; j < R; j++) {
  				file >> maxm[i][j];
			}
		}
	
		//Check system is in safe state or not
		isSafe(processes, avail, maxm, allot);
	}
    file.close();
	return 0;
}
