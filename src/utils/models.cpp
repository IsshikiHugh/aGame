#include "models.h"

//==============================================================================//

Model::Model(){
    this->openerOptionPtr = new OptionModel("openerOperation");
}

Model::~Model(){
    delete this->openerOptionPtr;
}

OptionModel Model::openerOption(){
    return *(this->openerOptionPtr);
}

//==============================================================================//

OptionModel::OptionModel(){}

OptionModel::OptionModel( string &&modelType ){


}

//==============================================================================//
