#ifndef __Models__
#define __Models__

#include <iostream>
#include <string>
#include <map>

using namespace std;

//==============================================================================//

class OptionModel{
public:
    OptionModel();
    OptionModel(string &&modelType);
private:

};



//==============================================================================//

class Model {
public:
    Model();
    ~Model();
    
    OptionModel openerOption();
private:
    OptionModel *openerOptionPtr;
};

//==============================================================================//

#endif
