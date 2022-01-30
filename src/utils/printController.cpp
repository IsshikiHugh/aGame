#include "printController.h"

ostream &tab(ostream &ostr){
    return ostr << "      ";
}

void printAll(vector<string> str){
    for(int i = 0;i < str.size();++i){
        cout << tab << str[i] << endl;
    }
}