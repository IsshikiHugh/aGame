#ifndef __Print_Controller__
#define __Print_Controller__

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


namespace printController{

    ostream &tab(ostream &ostr);
    

    // Be used to print everything in str[] with a `std::endl` between each string.
    void printAll(vector<string> &str);

    // Be used to count the numbers of short character and long character.
    int calWidth(string &str);
    // Be used to cut the string to slices whose elements are never longer than limited length.
    void lineCut(string &str, vector<string> &slices, int len);
    // Be used to put all messages into a frame.
    vector<string> generateIntoFrame(vector<string> &str);


};



#endif