#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <map>
#include <string>

class GroceryTracker {
private:
	std::map<std::string, int> itemFrequency;

public: 
	void LoadData(const std::string& filename);
	void CreateBackupFile(const std::string& filename);

	int GetItemFrequency(const std::string& item);
	void PrintAllFrequencies();
	void PrintHistogram();
};

#endif
