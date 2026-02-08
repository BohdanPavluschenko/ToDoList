#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "technical.hpp"

using namespace std;

void help() {
	cout << "Heres the list of commands: " << endl;
	cout << "showlist" << endl;
	cout << "addNewTask" << endl;
	cout << "editTask" << endl;
	cout << "deleteTask" << endl;
	cout << "help" << endl;
	cout << "stop" << endl;
}

void showlist() {
	string file;
	cout << "enter the path fo file (without quoutes): ";
	getline(cin, file);
	cout << endl;
	vector<string> list = takeFromFile(file);
	vectorPrint(list);
}

void addNewTask() {
	string file, task;
	cout << "enter the path to file (without quoutes): ";
	getline(cin, file);
	vector<string> list = takeFromFile(file);
	deletelist(file);
	cout << "enter the task that you want to add to the list: ";
	getline(cin, task);
	list.push_back(task);
	savelist(list, file);
	cout << "a new task's added! " << endl;
	cout << endl;
	cout << "here's the updated list: " << endl;
	vectorPrint(list);
}

void deleteTask() {
	string file;
	cout << "enter the path to file (without quoutes): ";
	getline(cin, file);
	vector<string> list = takeFromFile(file);
	deletelist(file);
	cout << "enter the number of position of task that you want to delete: ";
	int pos;
	cin >> pos;
	if (pos >= 0 && pos <= list.size()) {
		list.erase(list.begin() + (pos - 1));
	}
	savelist(list, file);
	cout << "task's deleted sucesesful!" << endl;
	cout << endl;
	cout << "Here's updated list: " << endl;
	vectorPrint(list);
}

void editTask() {
	string file;
	cout << "enter the path to file (without quoutes): ";
	getline(cin, file);
	vector<string> list = takeFromFile(file);
	deletelist(file);
	string newtask;
	int pos;
	cout << "write the position of task you want edit: ";
	cin >> pos;
	cout << "write new name of task: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, newtask);
	list[pos - 1] = newtask;
	savelist(list, file);
	cout << "task's edited sucesesful!" << endl;
	cout << endl;
	cout << "Here's updated list: " << endl;
	vectorPrint(list);
}
