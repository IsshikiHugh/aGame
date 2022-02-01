#include "printController.h"

ostream &tab(ostream &ostr){
    return ostr << "      ";
}

void printController::printAll(vector<string> &str){
    for(int i = 0;i < str.size();++i){
        cout << tab << str[i] << endl;
    }
}


vector<string> printController::generateIntoFrame(vector<string> &str){
    vector<string> ret;
    string line{""};
    const int capacity = 58;
    ret.push_back("##================================================================##");
    ret.push_back("[]                                                                []");
    for(auto it = str.begin();it != str.end();++it){
        line = "";
        line.append("[]   ");

        line.append("   []");
    }
    ret.push_back("[]                                                                []");
    ret.push_back("##================================================================##");
    return ret;
    
}