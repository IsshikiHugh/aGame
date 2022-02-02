#include <iostream>
#include "printController.h"

using namespace std;
using namespace printController;

int main(){
    vector<string> kkk,ttt;
    string str;
    while(1){
        cin >> str;
        if(str == "#") break;
        else kkk.push_back(str);
    }
    
    ttt = generateIntoFrame(kkk);
    printAll(ttt);
}