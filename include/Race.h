#ifndef RACE_H
#define RACE_H

#include <vector>
#include "Data.h"
#include "Class.h"

#define RESTRICTED_CLASS_FROM_RACE 1

class Race : public Data
{
    public:
        Race(std::string id, std::string name);
        Race();

        virtual ~Race();

        void setRacePlayable(bool playable);

        std::string getName();
        bool isPlayable();
        std::vector<std::string> getAvailableClass();
        std::pair<int,int> getAttributeBounds(std::string key);
        int getAttributeBonus(std::string key);

        void addAvailableClass(std::string key);
        void setAttributeBounds(std::string key, int lb, int hb);
        void setAttributeBonus(std::string key, int bonus);

    protected:
        std::string m_name;
        bool m_playable;
        std::vector<std::string> m_class_restriction;
        std::map<std::string,std::pair<int,int>> m_attributesBounds;
        std::map<std::string,int> m_attributesBonus;

};

#endif // RACE_H
