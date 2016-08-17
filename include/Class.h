#ifndef CLASS_H
#define CLASS_H

#include <map>
#include "Data.h"

class Class : public Data
{
    public:
        Class(std::string id, std::string name);
        Class();

        virtual ~Class();

        std::string getName();
        bool haveAttributeLowBoundary(std::string key);
        int getAttributeLowBoundary(std::string key);

        void setAttributeLowBoundary(std::string key, int boundary);

    protected:
        std::string m_name;
        std::map<std::string,int> m_attributesLowBoundary;

};

#endif // CLASS_H
