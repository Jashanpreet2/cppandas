#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <string>

class Utilities {
	size_t m_widthField{ 1 };
	static char m_delimiter;
public:
	std::string trim(std::string str) const;
	void setFieldWidth(size_t newWidth);
	size_t getFieldWidth() const;
	std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(char newDelimiter);
	static char getDelimiter();
};


char Utilities::m_delimiter = 'a';
#endif

