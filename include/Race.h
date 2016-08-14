#ifndef RACE_H
#define RACE_H

#include <vector>
#include "config.h"
#include "Class.h"

#define RESTRICTED_CLASS_FROM_RACE 1

class Race
{
    public:
        Race(std::string id, std::string name);
        Race();

        virtual ~Race();

        std::string getID();
        std::string getName();
        std::vector<std::string> getAvailableClass();
        std::pair<int,int> getAttributeBounds(std::string key);
        int getAttributeBonus(std::string key);

        void setIDToUndefined();
        void addAvailableClass(std::string key);
        void setAttributeBounds(std::string key, int lb, int hb);
        void setAttributeBonus(std::string key, int bonus);

    protected:
        std::string m_id, m_name;
        std::vector<std::string> m_class_restriction;
        std::map<std::string,std::pair<int,int>> m_attributesBounds;
        std::map<std::string,int> m_attributesBonus;

};

#endif // RACE_H
