#include "DataManager.h"
#include "tools.h"

/*static*/ DataMap DataManager::m_abilityMap;
/*static*/ DataMap DataManager::m_attributeMap;
/*static*/ DataMap DataManager::m_classMap;
/*static*/ DataMap DataManager::m_raceMap;

/*private*/ DataManager::DataManager()
{}

DataManager::~DataManager()
{}

void DataManager::clearAll()
{
    m_abilityMap.clearDataMap();
    m_attributeMap.clearDataMap();
    m_classMap.clearDataMap();
    m_raceMap.clearDataMap();
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
    return dynamic_cast<Ability*>(m_abilityMap.getDataByKey(key));
}

Attribute* DataManager::getAttributeByKey(std::string key)
{
    return dynamic_cast<Attribute*>(m_attributeMap.getDataByKey(key));
}

Class* DataManager::getClassByKey(std::string key)
{
    return dynamic_cast<Class*>(m_classMap.getDataByKey(key));
}

Race* DataManager::getRaceByKey(std::string key)
{
    return dynamic_cast<Race*>(m_raceMap.getDataByKey(key));
}

std::vector<Race*> DataManager::getRaceVector()
{
    std::vector<Race*> raceVector;
    std::vector<Data*> dataVector = m_raceMap.toVector();
    for(unsigned int i=0; i<dataVector.size(); i++)
        if(Race* race = dynamic_cast<Race*>(dataVector.at(i)))
            raceVector.push_back(race);

    return raceVector;
}
