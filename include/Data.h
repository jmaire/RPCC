#ifndef DATA_H
#define DATA_H

#include "config.h"

class Data
{
    public:
        Data(std::string id);
        Data();

        virtual ~Data();

        std::string getID();
        void setIDToUndefined();

    protected:
        std::string m_id;

};

#endif // DATA_H
