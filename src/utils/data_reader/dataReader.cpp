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
    if(!data.is_open()){
        ret = -1;
        data.close();
        return ret;
    }
    // cerr << "analyzing~\n";
    // TODO: Change it to status code.
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
// QWQReader

void QWQReader::dealReader(int code){
    switch (code) {
    case 1:
        return;
    case 0:
        cerr << "[Fail] Reader initialize failed.\n";
        cerr << "[Fail] There is something wrong with the index.qwq.\n";
        exit(0);
        break;
    case -1:
        cerr << "[Fail] Reader initialize failed.\n";
        cerr << "[Fail] can't find index.qwq.\n";
        exit(0);
        break;
    }
}

// ====================================================================
// QWQRecorder

void QWQRecorder::init(map < string , map < string , vector<string> > > &dic){
    this->dic = dic;
}

map< string , vector<string> > &QWQRecorder::getTag(string tag){
    return dic[tag];
}
vector<string> &QWQRecorder::getVal(string tag , string key){
    return dic[tag][key];
}

// ====================================================================


int QWQReader::init(string path){ // Don't change it to reference.
    int ret = 1;
    QWQAnalyzer indexAnalyzer(path);
    dealReader( indexAnalyzer.analyze() );
    auto &mv = indexAnalyzer.getTag("Path");

    path = mv["static"].front();

    QWQAnalyzer staticDataAnalyzer(path);
    staticDataAnalyzer.analyze();
    auto vv = staticDataAnalyzer.dic;
    staticData.init(staticDataAnalyzer.dic);

    // TODO: find a way to init() each dic.

    logs.info("QWQReader initialized successfully.");
    return ret;
}

QWQRecorder &QWQReader::getStaticData(){
    return this->staticData;
}
QWQRecorder &QWQReader::getArchiveData(){
    return this->archiveData;
}
QWQRecorder &QWQReader::getItemDictionary(){
    return this->itemDictionary;
}
QWQRecorder &QWQReader::getMonsterDictionary(){
    return this->monsterDictionary;
}
QWQRecorder &QWQReader::getNpcDictionary(){
    return this->npcDictionary;
}
QWQRecorder &QWQReader::getRoomDictionary(){
    return this->roomDictionary;
}