#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "DataFrame.h"
#include "Utilities.h"

using namespace std;
char Utilities::m_delimiter = ',';
bool DataFrame::readCSV(const string& fileName) {
	bool successful{};
	size_t nextPos{};
	bool more{ true };
	string line{};
	ifstream file{ fileName };
	Utilities util{};
	getline(file, line, '\n');
	while (more) {
		headings.push_back(util.extractToken(line, nextPos, more));
	}
	cols = std::vector<std::vector<std::string>>(headings.size());
	while (!file.eof()) {
		nextPos = 0;
		more = 1;
		getline(file, line, '\n');
		for (int i = 0; i < headings.size(); i++) {
			cols[i].push_back(util.extractToken(line, nextPos, more));
		}
	}
	return successful;
}

ostream& DataFrame::display(std::ostream& os) const {
	for_each(headings.begin(), headings.end(), [&os](string heading) {
		os << left << setw(15) << heading;
		});
	os << endl;
	//Cols might be 0 length. Add validation.
	//To note: All columns might not be of the same length. Enforce that they are same length in read_csv
	for (int i = 0; i < cols[0].size(); i++) {
		for_each(cols.begin(), cols.end(), [&os, &i](const std::vector<std::string>& col) {
			os << setw(15) << col[i];
			});
		os << endl;
	}
	os.unsetf(ios::left);
	return os;
}
ostream& operator<<(ostream& os, const DataFrame& df) {
	return df.display(os);
}