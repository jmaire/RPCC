#include "DataManager.h"
#include "tools.h"

/*static*/ std::map<std::string,Race*> DataManager::m_raceMap;
/*static*/ std::map<std::string,Class*> DataManager::m_classMap;
/*static*/ std::map<std::string,Attribute*> DataManager::m_attributeMap;

DataManager::DataManager()
{}

DataManager::~DataManager()
{}

void DataManager::load()
{
    loadAttribute();
    loadClass();
    loadRace();
}

void DataManager::loadAttribute()
{
    Attribute* at;

    at = new Attribute("Strength");
    m_attributeMap["str"] = at;

    at = new Attribute("Dexterity");
    m_attributeMap["dex"] = at;

    at = new Attribute("Constitution");
    m_attributeMap["con"] = at;

    at = new Attribute("Intelligence");
    m_attributeMap["int"] = at;

    at = new Attribute("Wisdom");
    m_attributeMap["wis"] = at;

    at = new Attribute("Charisma");
    m_attributeMap["cha"] = at;
}

void DataManager::loadClass()
{
    Class* cl;

    cl = new Class("Fighter");
    cl->setAttributeBounds(0,9,18);
    m_classMap["fighter"] = cl;

    cl = new Class("Mage");
    cl->setAttributeBounds(3,9,18);
    m_classMap["mage"] = cl;

    cl = new Class("Thief");
    cl->setAttributeBounds(1,9,18);
    m_classMap["thief"] = cl;
}

void DataManager::loadRace()
{
    Race* rc;

    rc = new Race("Human");
    rc->addAvailableClass(getClassByKey("fighter"));
    rc->addAvailableClass(getClassByKey("mage"));
    rc->addAvailableClass(getClassByKey("thief"));
    m_raceMap["human"] = rc;

    rc = new Race("Dwarf");
    rc->setAttributeBounds(0,8,18);
    rc->setAttributeBounds(1,3,17);
    rc->setAttributeBounds(2,12,19);
    rc->setAttributeBounds(5,2,16);
    rc->addAvailableClass(getClassByKey("fighter"));
    rc->addAvailableClass(getClassByKey("thief"));

    m_raceMap["dwarf"] = rc;

    rc = new Race("Elf");
    rc->setAttributeBounds(1,7,19);
    rc->setAttributeBounds(2,6,17);
    rc->setAttributeBounds(3,8,18);
    rc->setAttributeBounds(5,8,18);
    rc->addAvailableClass(getClassByKey("mage"));
    rc->addAvailableClass(getClassByKey("thief"));
    m_raceMap["elf"] = rc;
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



