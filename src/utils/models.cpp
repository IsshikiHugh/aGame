#include "models.h"


//==============================================================================//

// ====================================================================
// recorderModel

void recorderModel::init(map < string , map < string , vector<string> > > &dic){
    this->dic = dic;
}

map< string , vector<string> > &recorderModel::getTag(string tag){
    return dic[tag];
}
vector<string> &recorderModel::getVal(string tag , string key){
    return dic[tag][key];
}


//==============================================================================//
void optionsModel::set(recorderModel aimRecorder){
    logs.info("start set optionModel");
    vector<string> &use = aimRecorder.getVal("o_0","use");
    for(auto useIt = use.begin();useIt != use.end();++useIt){
        optionModel newOption;
        map < string , vector<string> > &option = aimRecorder.getTag(*useIt);
        newOption.desZh = option["des_zh"].front();
        newOption.desEn = option["des_en"].front();
        newOption.button = option["button"].front();
        newOption.level = option["level"].front();
        newOption.type = option["target_type"].front();
        newOption.targetPage = option["target"].front();
        options.push_back(newOption);
    } 
    logs.info("finish set optionModel");     
}

const vector< optionModel > &optionsModel::getOptions(){
    return options;
}

//==============================================================================//


void pagesModel::set(recorderModel aimRecorder){
    logs.info("start set pageModel");
    vector<string> &use = aimRecorder.getVal("l_0","use");
    if(!aimRecorder.getVal("l_0","options").empty()){
        optionsName = aimRecorder.getVal("l_0","options").front();
    }
    for(auto useIt = use.begin();useIt != use.end();++useIt){
        pageLineModel newLine;
        map < string , vector<string> > &option = aimRecorder.getTag(*useIt);
        newLine.desZh = option["des_zh"];
        newLine.desEn = option["des_en"];
        pageMsgs.push_back(newLine);
    } 
    logs.info("finish set pageModel"); 
}

const vector<pageLineModel> &pagesModel::getPage(){
    return pageMsgs;
}

const string &pagesModel::getOptions(){
    return optionsName;
}