#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <map>
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

        static bool isKeyFormatValid(std::string key);

        static void insereAbilityToMap(Ability* ab);
        static void insereAttributeToMap(Attribute* att);
        static void insereClassToMap(Class* cl);
        static void insereRaceToMap(Race* rc);

        static Ability* getAbilityByKey(std::string key);
        static Attribute* getAttributeByKey(std::string key);
        static Class* getClassByKey(std::string key);
        static Race* getRaceByKey(std::string key);

    protected:
        static std::map<std::string,Ability*> m_abilityMap;
        static std::map<std::string,Attribute*> m_attributeMap;
        static std::map<std::string,Class*> m_classMap;
        static std::map<std::string,Race*> m_raceMap;

    private:
        DataManager();
};

#endif // DATAMANAGER_H
