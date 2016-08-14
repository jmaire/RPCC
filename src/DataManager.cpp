#include "DataManager.h"
#include "tools.h"

/*static*/ std::map<std::string,Attribute*> DataManager::m_attributeMap;
/*static*/ std::map<std::string,Class*> DataManager::m_classMap;
/*static*/ std::map<std::string,Race*> DataManager::m_raceMap;

/*private*/ DataManager::DataManager() {}

DataManager::~DataManager()
{}

void DataManager::clearAll()
{
    //TODO
    std::map<std::string,Attribute*>::iterator it;
    while(!m_attributeMap.empty())
    {
        it = m_attributeMap.begin();
        m_attributeMap.erase(it);
        delete it->second;
    }
}


void DataManager::insereAttributeToMap(Attribute* att)
{
    std::string id = att->getID();
    if("" == id)
        return;

    if(m_attributeMap.find(id) != m_attributeMap.end())
        m_attributeMap[id]->setIDToUndefined();

    m_attributeMap[id] = att;
}

void DataManager::insereClassToMap(Class* cl)
{
    std::string id = cl->getID();
    if("" == id)
        return;

    if(m_classMap.find(id) != m_classMap.end())
        m_classMap[id]->setIDToUndefined();

    m_classMap[id] = cl;
}

void DataManager::insereRaceToMap(Race* rc)
{
    std::string id = rc->getID();
    if("" == id)
        return;

    if(m_raceMap.find(id) != m_raceMap.end())
        m_raceMap[id]->setIDToUndefined();

    m_raceMap[id] = rc;
}

Attribute* DataManager::getAttributeByKey(std::string key)
{
    return m_attributeMap.at(key);
}

Class* DataManager::getClassByKey(std::string key)
{
    return m_classMap.at(key);
}

Race* DataManager::getRaceByKey(std::string key)
{
    return m_raceMap.at(key);
}



