#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "DataMap.h"
#include "Ability.h"
#include "Attribute.h"
#include "Class.h"
#include "Race.h"
#include "Trait.h"
#include "WeaponCategory.h"

class DataManager
{
    public:
        void initDataManager();

        virtual ~DataManager();

        static void clearAll();
        //static bool checkDataIntegrity(); //TODO

        static void insereDataToMap(Ability* data);
        static void insereDataToMap(Attribute* data);
        static void insereDataToMap(Class* data);
        static void insereDataToMap(Race* data);
        static void insereDataToMap(Trait* data);
        static void insereDataToMap(WeaponCategory* data);

        static Ability* getAbilityByKey(std::string key);
        static Attribute* getAttributeByKey(std::string key);
        static Class* getClassByKey(std::string key);
        static Race* getRaceByKey(std::string key);
        static Trait* getTraitByKey(std::string key);
        static WeaponCategory* getWeaponCategoryByKey(std::string key);

        static std::vector<Race*> getRaceVector();

    protected:
        static DataMap<Ability> m_abilityMap;
        static DataMap<Attribute> m_attributeMap;
        static DataMap<Class> m_classMap;
        static DataMap<Race> m_raceMap;
        static DataMap<Trait> m_traitMap;
        static DataMap<WeaponCategory> m_weaponCategoryMap;

    private:
        DataManager();
};

#endif // DATAMANAGER_H
