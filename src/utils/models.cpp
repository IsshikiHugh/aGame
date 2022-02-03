#include "models.h"


//==============================================================================//



//==============================================================================//
void optionsModel::set(QWQRecorder aimRecorder){
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
