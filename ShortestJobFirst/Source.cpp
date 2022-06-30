#include<iostream>
using namespace std;
struct Process{
	int num;
	int arrival_time;
	int burst_time;
	int waiting_time;
	int turn_around_time;
};
int main() {
	cout << "Enter Number of Processes: ";
	int size;
	cin >> size;
	cin.ignore();
	Process* process = new Process[size];
	cout << "Enter Process details\n";
	for (int i = 0; i < size; i++) {
		cout << "P" << i << "A.T: ";
		cin >> process[i].arrival_time;
		cin.ignore();
		cout << "P" << i << "B.T: ";
		cin >> process[i].burst_time;
		cin.ignore();
		process[i].num = i;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size-i; j++) {
			if (process[i].burst_time > process[j].burst_time) {
				Process temp = process[i];
				process[i] = process[j];
				process[j] = temp;
			}
		}
	}
	process[0].waiting_time = 0;
	for (int i = 0; i < size; i++) {
		process[i].waiting_time += process[i].burst_time;
		process[i].turn_around_time = process[i].burst_time + process[i].waiting_time;
	}
}