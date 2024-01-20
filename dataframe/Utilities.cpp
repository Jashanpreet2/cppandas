/*
Name: Jashanpreet Singh
Email : jsingh1009@myseneca.ca
Student ID : 112454228
Date completed : 7 November, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include <string>
#include "Utilities.h"
using namespace std;

string Utilities::trim(string str) const {
	size_t numWhitespaces = 0;
	bool nonWhitespaceFound{};
	for (size_t i = 0; i < str.length() && !nonWhitespaceFound; i++) {
		if (str[i] == ' ') {
			numWhitespaces++;
		}
		else {
			nonWhitespaceFound = true;
		}
	}
	str.erase(0, numWhitespaces);
	numWhitespaces = 0;
	for (size_t i = str.length() - 1; str[i] == ' '; i--) {
		numWhitespaces++;
	}
	if (numWhitespaces >= 1) {
		str.erase(str.length() - numWhitespaces, numWhitespaces);
	}
	return str;
}

void Utilities::setFieldWidth(size_t newWidth) {
	m_widthField = newWidth;
}

size_t Utilities::getFieldWidth() const {
	return m_widthField;
}

std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
	if (str[next_pos] == m_delimiter) {
		more = false;
		throw "The value at next position is the same as the delimiter";
	}
	string token = trim(str.substr(next_pos, str.find_first_of(m_delimiter, next_pos) - next_pos));
	if (str.find_first_of(m_delimiter, next_pos) != string::npos) {
		next_pos = str.find_first_of(m_delimiter, next_pos) + 1;
		more = true;
	}
	else {
		more = false;
	}
	if (m_widthField < token.length()) {
		setFieldWidth(token.length());
	}
	return token;
}

void Utilities::setDelimiter(char newDelimiter) {
	m_delimiter = newDelimiter;
}

char Utilities::getDelimiter() {
	return m_delimiter;
}
