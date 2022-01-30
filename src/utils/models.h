#ifndef __Option_Model__
#define __Option_Model__

#include <iostream>
#include <string>

using namespace std;


class OptionModel{
public:
    OptionModel();
    OptionModel(string &&modelType);
private:

};

#endif

//==============================================================================//

#ifndef __Model__
#define __Model__

struct Model{
    OptionModel openerModel("opener");

};


#endif
