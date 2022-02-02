#include "printController.h"


int zhChWidth;
int enChWidth = 1;

int getLocalZhChWidth(){
    int size;
    string str;
    cout << "[正在校准] 请输入一个任意中文汉字：\n";
    cin >> str;
    size = str.size();
    cout << "[正在校准] 请再输入两个任意中文汉字:\n";
    cin >> str;
    if(size != str.length()/2) return -1;
    return size;
}

void printController::zhInit(){
    while(true){
        int resp = getLocalZhChWidth();
        if(resp == -1){
            cout << "校准失败！请重新校准！\n";
        } else {
            cout << "校准成功！[" << resp << "]\n";
            zhChWidth = resp;
            return;
        }
    }
}



ostream &printController::tab(ostream &ostr){
    return ostr << "      ";
}

void printController::printAll(vector<string> &str){
    for(int i = 0;i < str.size();++i){
        cout << printController::tab << str[i] << endl;
    }
}

int printController::calWidth(string &str){
    int res = 0;
    for(auto it = str.begin();it != str.end();++it){
        if( (int)(*it) < 0 ){
            it += zhChWidth - 1;
            res += 2;
        } else {
            it += enChWidth - 1;
            res += 1;
        }
    }
    return res;
}

void printController::lineCut(string &str, vector<string> &slices, int len){
    int lp,rp,cntLen;
    slices.clear();
    lp = rp = cntLen = 0;

    // It only try to push_back while you fail to add more character. 
    for(auto it = str.begin();it < str.end();){
        int step = ( (int)(*it) < 0 || (int)(*it) >= 128 ) ? zhChWidth : enChWidth ;
        int width = ( (int)(*it) < 0 || (int)(*it) >= 128 ) ? 2 : 1 ;
        cntLen += width;
        if(cntLen > len){
            slices.push_back( str.substr(lp,rp-lp) );
            // cout << "slices : " << str.substr(lp,rp-lp) << "\n";
            lp = rp;
            cntLen = width;
        }
        rp += step;
        it += step;
    }
    slices.push_back( str.substr(lp,rp-lp) );
    // cout << "slices : " << str.substr(lp,rp-lp) << "\n";
}

vector<string> printController::generateIntoFrame(vector<string> &str){
    vector<string> tmp;
    vector<string> ret;
    string line{""};
    const int frameWidth = 58;

    ret.push_back("##================================================================##");
    ret.push_back("[]                                                                []");

    for(auto it = str.begin();it != str.end();++it){
        vector<string> slices;
        lineCut(*it, slices, frameWidth);
        for(auto it_ = slices.begin();it_ != slices.end();++it_){
            tmp.push_back(*it_);
        }
    }
    for(auto it = tmp.begin();it != tmp.end();++it){
        int free = frameWidth - calWidth(*it);
        line = "";
        line.append("[]   ");
        line.append(*it);
        for(int i = 1;i <= free;++i){
            line.append(" ");
        }
        line.append("   []");
        ret.push_back(line);
    }

    ret.push_back("[]                                                                []");
    ret.push_back("##================================================================##");

    return ret;
}