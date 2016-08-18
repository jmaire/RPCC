#include "DataManager.h"
#include "tools.h"

/*static*/ DataMap<Ability> DataManager::m_abilityMap;
/*static*/ DataMap<Attribute> DataManager::m_attributeMap;
/*static*/ DataMap<Class> DataManager::m_classMap;
/*static*/ DataMap<Race> DataManager::m_raceMap;

/*private*/ DataManager::DataManager()
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

void DataManager::insereAbilityToMap(Ability* ab)
{
    m_abilityMap.insereDataToMap(ab);
}

void DataManager::insereAttributeToMap(Attribute* att)
{
    m_attributeMap.insereDataToMap(att);
}

void DataManager::insereClassToMap(Class* cl)
{
    m_classMap.insereDataToMap(cl);
}

void DataManager::insereRaceToMap(Race* rc)
{
    m_raceMap.insereDataToMap(rc);
}

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

std::vector<Race*> DataManager::getRaceVector()
{
    return m_raceMap.toVector();
}
