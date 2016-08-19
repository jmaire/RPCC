#ifndef DATA_H
#define DATA_H

#include <vector>
#include "config.h"

class Data
{
    public:
        virtual ~Data();

        std::string getID();
        void setIDToUndefined();

    protected:
        std::string m_id;

        Data();
        Data(std::string id);
};

#endif // DATA_H
