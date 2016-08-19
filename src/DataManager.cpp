#include "DataManager.h"
#include "tools.h"

DataMap<Ability> DataManager::m_abilityMap;
DataMap<Attribute> DataManager::m_attributeMap;
DataMap<Class> DataManager::m_classMap;
DataMap<Race> DataManager::m_raceMap;
DataMap<Trait> DataManager::m_traitMap;
DataMap<WeaponCategory> DataManager::m_weaponCategoryMap;

DataManager::DataManager()
{}

DataManager::~DataManager()
{}

void DataManager::clearAll()
{
    m_abilityMap.flushMap();
    m_attributeMap.flushMap();
    m_classMap.flushMap();
    m_raceMap.flushMap();
}



void DataManager::insereDataToMap(Ability* data)
{
    m_abilityMap.insereDataToMap(data);
}

void DataManager::insereDataToMap(Attribute* data)
{
    m_attributeMap.insereDataToMap(data);
}

void DataManager::insereDataToMap(Class* data)
{
    m_classMap.insereDataToMap(data);
}

void DataManager::insereDataToMap(Race* data)
{
    m_raceMap.insereDataToMap(data);
}

void DataManager::insereDataToMap(Trait* data)
{
    m_traitMap.insereDataToMap(data);
}

void DataManager::insereDataToMap(WeaponCategory* data)
{
    m_weaponCategoryMap.insereDataToMap(data);
}

///////////////////////////////////////////////////////////////

Ability* DataManager::getAbilityByKey(std::string key)
{
    return m_abilityMap.getDataByKey(key);
}

Attribute* DataManager::getAttributeByKey(std::string key)
{
    return m_attributeMap.getDataByKey(key);
}

Class* DataManager::getClassByKey(std::string key)
{
    return m_classMap.getDataByKey(key);
}

Race* DataManager::getRaceByKey(std::string key)
{
    return m_raceMap.getDataByKey(key);
}

Trait* DataManager::getTraitByKey(std::string key)
{
    return m_traitMap.getDataByKey(key);
}

WeaponCategory* DataManager::getWeaponCategoryByKey(std::string key)
{
    return m_weaponCategoryMap.getDataByKey(key);
}

///////////////////////////////////////////////////////////////

std::vector<Race*> DataManager::getRaceVector()
{
    return m_raceMap.toVector();
}

std::vector<WeaponCategory*> DataManager::getWeaponCategoryVector()
{
    return m_weaponCategoryMap.toVector();
}
