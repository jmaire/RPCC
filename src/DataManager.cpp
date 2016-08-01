#include "DataManager.h"
#include "tools.h"

/*static*/ std::map<std::string,Attribute*> DataManager::m_attributeMap;
/*static*/ std::map<std::string,Class*> DataManager::m_classMap;
/*static*/ std::map<std::string,Race*> DataManager::m_raceMap;

/*private*/ DataManager::DataManager()
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
    Attribute* att;

    att = new Attribute("Strength");
    m_attributeMap["str"] = att;

    att = new Attribute("Dexterity");
    m_attributeMap["dex"] = att;

    att = new Attribute("Constitution");
    m_attributeMap["con"] = att;

    att = new Attribute("Intelligence");
    m_attributeMap["int"] = att;

    att = new Attribute("Wisdom");
    m_attributeMap["wis"] = att;

    att = new Attribute("Charisma");
    m_attributeMap["cha"] = att;
}

void DataManager::loadClass()
{
    Class* cl;

    cl = new Class("Fighter");
    cl->setAttributeBounds("str",9,18);
    m_classMap["fighter"] = cl;

    cl = new Class("Mage");
    cl->setAttributeBounds("int",9,18);
    m_classMap["mage"] = cl;

    cl = new Class("Thief");
    cl->setAttributeBounds("dex",9,18);
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
    rc->setAttributeBounds("str",8,18);
    rc->setAttributeBounds("dex",3,17);
    rc->setAttributeBounds("con",12,19);
    rc->setAttributeBounds("cha",2,16);
    rc->addAvailableClass(getClassByKey("fighter"));
    rc->addAvailableClass(getClassByKey("thief"));
    m_raceMap["dwarf"] = rc;

    rc = new Race("Elf");
    rc->setAttributeBounds("dex",7,19);
    rc->setAttributeBounds("con",6,17);
    rc->setAttributeBounds("int",8,18);
    rc->setAttributeBounds("cha",8,18);
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



