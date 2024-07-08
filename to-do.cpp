// to-do list 
// i/o in list.txt

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void Tasks(const vector<string>&tasks) {
	if (tasks.empty()) {
		cout << "Nothing to do!\n";
	}
	else {
		cout << "\n---------To-Do---------" << endl;
		for (int i = 0; i < tasks.size();i++) {
			cout << i + 1 << ". " << tasks[i] << endl;
		}
		cout << "-----------------------\n";
	}
}

int main() {
	cout << "\033[93m";
	vector<string>tasks;
	string task;
	char menu;
	int num;
	int num1;

	ifstream inputFile("list.txt");
	while (getline(inputFile, task)) {
		tasks.push_back(task);
	}
	inputFile.close();
	do {
		cout << "\nA - Add task\n" << "C - Clear completed task\n"<<"V - View To-Do List\nR - Remove all\n" << "Q - Quit\n";
		cout << "\nEnter choice: ";
		cin >> menu;
		if (menu != 'A' and menu != 'a' and menu != 'r' and menu != 'R' and menu != 'q' and menu != 'Q' and menu !='v' and menu != 'V' and menu != 'c' and menu !='C') {
			cout << "Invalid input\n";
		}
		else if (menu == 'r' or menu == 'R') {
			tasks.clear();
			cout << "Nothing to do!\n";
		}
		else if (menu == 'v' or menu == 'V') {
			if (tasks.empty()) {
				cout << "Nothing to do!\n";
			}
			else
				Tasks(tasks);
		}
		else if (menu == 'A' or menu == 'a') {
			cout << "Enter task to add: ";
			cin.ignore();
			getline(cin, task);
			tasks.push_back(task);
			cout << "Added to list!\n";
			Tasks(tasks);
		}
		else if (menu == 'C' or menu == 'c') {
			cout << "Enter task number to clear task: ";
			cin >> num;
			if (tasks.empty()) {
				cout << "Nothing to do!\n";
			}
			else if (num > tasks.size()) {
				cout << "Task number isn't in list!\n";
			}
			else {
				if (num == 1) {
					tasks.erase(tasks.begin());
				}
				else {
					tasks.erase(tasks.begin() + 1);
				}
				cout << "Removed from list!\n";
				Tasks(tasks);
			}
		}
	} while (menu != 'Q' and menu != 'q');
	ofstream outputFile("list.txt");
	for (const auto& t : tasks) {
		outputFile << t << endl;
	}
	outputFile.close();
	return 0;
}