#ifndef RACE_H
#define RACE_H

#include <vector>
#include "config.h"
#include "Class.h"

#define RESTRICTED_CLASS_FROM_RACE 1

class Race
{
    public:
        Race(std::string n);
        Race(void);

        virtual ~Race(void);

        std::string* getName(void);
        std::vector<Class*>* getAvailableClass(void);
        std::pair<int,int> getAttributeBounds(std::string key);

        void addAvailableClass(Class* cl);
        void setAttributeBounds(std::string key, int lb, int hb);

    protected:
        std::string m_name;
        std::vector<Class*> m_class_restriction;
        std::map<std::string,std::pair<int,int>> m_attributesBounds;
        //std::pair<unsigned int,unsigned int> ma_attributesBounds[ATTRIBUTES_SET_SIZE];

};

#endif // RACE_H
