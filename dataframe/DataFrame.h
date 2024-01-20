#ifndef DATAFRAME_H
#define DATAFRAME_H
#include <string>


class DataFrame {
	string** headers{};
	string** ptr{};
	size_t numColumns{};
public:
	DataFrame();
	bool readCSV(const std::string& fileName);

};

#endif