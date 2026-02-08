#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

fstream f;

template<typename T>
void vectorPrint(vector<T> vect) {
	for (int i = 0; i < vect.size(); i++) {
		cout << vect[i] << endl;
	}
}

vector<string> takeFromFile(const string& file) {
	f.open(file, ios_base::in);
	if (!f.is_open()) {
		vector<string> error;
		error.push_back("error");
		return error;
	}

	string line;
	vector<string> items;
	while (getline(f, line)) {
		if (!line.empty() && line.front() == '[') line.erase(0, 1);
		if (!line.empty() && line.back() == ']') line.pop_back();

		istringstream ss(line);
		string item;
		while (getline(ss, item, ',')) {
			while (!item.empty() && item.front() == ' ') item.erase(0, 1);
			while (!item.empty() && item.back() == ' ') item.pop_back();

			items.push_back(item);
		}
	}

	f.close();
	return items;
}

void savelist(const vector<string>& list, const string& file) {
	f.open(file, ios_base::out);
	if (!f.is_open()) {
		cerr << "error of saving to file" << endl;
	}

	f << "[";

	for (size_t i = 0; i < list.size(); i++) {
		f << list[i];
		if (i + 1 < list.size()) {
			f << ", ";
		}
	}

	f << "]";
	f.close();
}

void deletelist(const string& file) {
	f.open(file, ios::out | ios::trunc);
	f.close();
}
