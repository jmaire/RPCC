#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <map>
#include "DataMap.h"
#include "Ability.h"
#include "Attribute.h"
#include "Class.h"
#include "Race.h"

class DataManager
{
    public:
        virtual ~DataManager();

        static void clearAll();
        //static bool checkDataIntegrity(); //TODO

        static void insereAbilityToMap(Ability* ab);
        static void insereAttributeToMap(Attribute* att);
        static void insereClassToMap(Class* cl);
        static void insereRaceToMap(Race* rc);

        static Ability* getAbilityByKey(std::string key);
        static Attribute* getAttributeByKey(std::string key);
        static Class* getClassByKey(std::string key);
        static Race* getRaceByKey(std::string key);

        static std::vector<Race*> getRaceVector();

    protected:
        static DataMap m_abilityMap;
        static DataMap m_attributeMap;
        static DataMap m_classMap;
        static DataMap m_raceMap;

    private:
        DataManager();
};

#endif // DATAMANAGER_H
