#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "functions.hpp"

using namespace std;

int main() {

	cout << "Welcome to 'ToDoList'" << endl;
	cout << "Heres the list of commands: " << endl;
	cout << "showlist" << endl;
	cout << "addNewTask" << endl;
	cout << "editTask" << endl;
	cout << "deleteTask" << endl;
	cout << "help" << endl;
	cout << "stop" << endl;
	cout << endl;
	while (true) {
		cout << endl;
		cout << "write the command: " << endl;
		string command;
		cin >> command;
		cout << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (command == "showlist") {
			showlist();
		}
		if (command == "stop") {
			break;
		}
		if (command == "help") {
			help();
		}
		if (command == "addNewTask") {
			addNewTask();
		}
		if (command == "deleteTask") {
			deleteTask();
		}
		if (command == "editTask") {
			editTask();
		}
	}
	cout << endl;
	cout << "thank you for using!" << endl;

	return 0;
}
