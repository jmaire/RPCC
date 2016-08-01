#ifndef CLASS_H
#define CLASS_H

#include <map>
#include "config.h"

class Class
{
    public:
        Class(std::string n);
        Class(void);

        virtual ~Class(void);

        std::string* getName(void);
        std::pair<int,int> getAttributeBounds(std::string key);

        void setAttributeBounds(std::string key, int lb, int hb);

    protected:
        std::string m_name;
        std::map<std::string,std::pair<int,int>> m_attributesBounds;

};

#endif // CLASS_H
