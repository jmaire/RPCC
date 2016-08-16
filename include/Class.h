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
        std::pair<int,int> getAttributeBounds(std::string key);

        void setAttributeBounds(std::string key, int lb, int hb);

    protected:
        std::string m_name;
        std::map<std::string,std::pair<int,int>> m_attributesBounds;

};

#endif // CLASS_H
