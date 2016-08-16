#ifndef DATA_H
#define DATA_H

#include "config.h"

class Data
{
    public:
        virtual ~Data();

        std::string getID();
        void setIDToUndefined();

    protected:
        std::string m_id;

        Data(std::string id);
        Data();

};

#endif // DATA_H
