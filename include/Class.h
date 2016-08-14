#ifndef CLASS_H
#define CLASS_H

#include <map>
#include "config.h"

class Class
{
    public:
        Class(std::string id, std::string name);
        Class();

        virtual ~Class();

        std::string getID();
        std::string getName();
        std::pair<int,int> getAttributeBounds(std::string key);

        void setID(std::string id);
        void setAttributeBounds(std::string key, int lb, int hb);

    protected:
        std::string m_id, m_name;
        std::map<std::string,std::pair<int,int>> m_attributesBounds;

};

#endif // CLASS_H
