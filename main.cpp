#include <iostream>
#include <limits>
#include "GroceryTracker.h"

using namespace std;

void DisplayMenu() {
	cout << endl;
	cout <<"=====Corner Grocer Menu=====" << endl;
	cout << "1.Search for item frequency" << endl;
	cout <<"2.Display all item frequencies" << endl;
	cout << "3.Display histogram" << endl;
	cout << "4.Exit" << endl;
	cout << "Choose an option: ";
}
int main() {
	GroceryTracker tracker;

	tracker.LoadData("CS210_Project_Three_input_File.txt");
	tracker.CreateBackupFile("frequency.dat");

	int choice = 0;
	while (choice != 4) {
		DisplayMenu();

		cin >> choice;

		while (cin.fail() || choice < 1 || choice > 4) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Invalid option. Try again: ";
			cin >> choice;
		}

		switch (choice) {
		case 1: {
			string item;

			cout << "Enter item name:";
			cin >> item;

			cout << item << "purchased"
				<< tracker.GetItemFrequency(item)
				<< "time(s)." << endl;
			break;

		}

		case 2:
			tracker.PrintAllFrequencies();
			break;

		case 3:
			tracker.PrintHistogram();
			break;
		case 4:
			cout << "Program terminated." << endl;
			break;
		}

	}

	return 0;

}