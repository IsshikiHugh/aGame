#include "dataReader.h"

// ====================================================================
// QWQAnalyzer 

/* 
 * <key words>
 * # { } : , ;
 */
int QWQAnalyzer::analyze(){
    int ret = 1; // nothing wrong
    ifstream data;
    data.open(this->path,ios::in);
    cout << "open\n";

    string str , tag , key;
    bool isIgnore = false;

    bool afterTag = false;
    bool isInTag = false;

    bool afterKey = false;

    bool isInVals = false;
    bool newVal = false;
    while(!data.eof()){
        data >> str;
        // cerr << "now" << isIgnore << afterTag << isInTag << afterKey << isInVals << newVal << "\n";
        // cerr << "read in 『" <<str<<"』" << "\n";

        // Deal codes notes.
        if(isIgnore){
            if(str == "#") isIgnore = false;
            continue;
        } else if(str == "#"){
            isIgnore = true;
            continue;
        }

        // Deal error.
        bool error = (!isInTag) && (isInVals || newVal || afterKey);
        error = error || ( !isInVals && newVal );
        if( error ){
            ret = 0;
            data.close();
            return ret;
        }
        // Deal key words.
        if(str == "{"){
            if(isInTag || !afterTag){
                ret = 0;
                data.close();
                return ret;
            } else {
                afterKey = false;
                isInTag = true;
                continue;
            }
        } else if(str == "}"){
            if(isInTag){
                isInTag = false;
                continue;
            } else {
                ret = 0;
                data.close();
                return ret;
            }
        } else if(str == ":"){
            if(afterKey){
                afterKey = false;
                isInVals = true;
                newVal = true;
                continue;
            } else {
                ret = 0;
                data.close();
                return ret;
            }
        } else if(str == ","){
            if(isInVals && !newVal){
                newVal = true;
                continue;
            } else {
                ret = 0;
                data.close();
                return ret;
            }
        } else if(str == ";"){
            if(isInVals && (!newVal)){
                isInVals = false;
                continue;
            } else {
                ret = 0;
                data.close();
                return ret;
            }
        }


        // Deal data.
        if(!afterTag && !isInTag){
            tag = str;
            afterTag = true;
            continue;
        }
        if(afterTag && !isInTag){
            tag.append(" ");
            tag.append(str);
            continue;
        }


        if(!afterKey && !isInVals){
            key = str;
            afterKey = true;
            continue;
        }
        if(afterKey){
            key.append(" ");
            key.append(str);
            continue;
        }

        // There only has two situations out of val.
        if(!isInVals){
            ret = 0;
            data.close();
            return ret;
        }

        if(newVal){
            newVal = false;
            // cerr << "push [" << tag << "][" << key << "] = " << str << "\n";
            dic[tag][key].push_back(str);
            continue;
        }
        if(!newVal){
            if(dic[tag][key].empty()){
                ret = 0;
                data.close();
                return ret;
            }
            auto it = dic[tag][key].end()-1;
            string tmp = *(it);
            tmp.append(" ");
            tmp.append(str);
            dic[tag][key].erase(it);
            dic[tag][key].push_back(tmp);
            // cerr << "push [" << tag << "][" << key << "] = " << tmp << "\n";
        }
    }
    data.close();
    return ret;
}

// ====================================================================
