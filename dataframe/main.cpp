#include <iostream>
#include <ctype.h>
#include <string>
#include "DataFrame.h"
using namespace std;
int main() {
	DataFrame frame;
	frame.readCSV("example.txt");
	frame.display(cout);
}