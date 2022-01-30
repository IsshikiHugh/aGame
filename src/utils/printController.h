#ifndef __Print_Controller__
#define __Print_Controller__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

ostream &tab(ostream &ostr);

// Be used to print everything in str[] with a `std::endl` between each string.
void printAll(vector<string> str);

#endif