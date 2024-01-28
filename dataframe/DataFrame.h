#ifndef DATAFRAME_H
#define DATAFRAME_H
#include <iostream>
#include <string>
#include <vector>

class DataFrame {
	std::vector<std::string> headings{};
	std::vector<std::vector<std::string>> cols{};
public:
	DataFrame() {};
	bool readCSV(const std::string& fileName);
	std::ostream & display(std::ostream & os) const;
};

std::ostream& operator<<(std::ostream& os, const DataFrame& df);

#endif