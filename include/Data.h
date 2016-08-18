#ifndef DATA_H
#define DATA_H

#include "config.h"

class Data
{
    public:
        virtual ~Data();
        Data();

        std::string getID();
        void setIDToUndefined();

    protected:
        std::string m_id;

        Data(std::string id);

};

#endif // DATA_H
