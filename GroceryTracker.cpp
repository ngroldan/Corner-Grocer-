#include "GroceryTracker.h"
#include <fstream>
#include <iostream>

using namespace std;

void GroceryTracker::LoadData(const string& filename) {
	ifstream inputFile(filename);

	string item;

	while (inputFile >> item) {
		itemFrequency[item]++;
	}

	inputFile.close();
}

void GroceryTracker::CreateBackupFile(const string& filename) {
	ofstream outFile(filename);


	for (auto item : itemFrequency) {
		outFile << item.first << ""
			<< item.second << endl;
	}
	outFile.close();
}

int GroceryTracker::GetItemFrequency(const string& item) {
	if (itemFrequency.find(item) != itemFrequency.end()) {
		return itemFrequency[item];
	}
	return 0;
}

void GroceryTracker::PrintAllFrequencies() {
	for (auto item :itemFrequency) {
		cout << item.first << ""
			<< item.second << endl;
	}
}

void GroceryTracker::PrintHistogram() {
	for (auto item : itemFrequency) {
		cout << item.first << "";

		for (int i = 0; i < item.second; i++) {
			cout << "*";
		}

		cout << endl;
	}
}