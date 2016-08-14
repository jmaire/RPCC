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

    att = new Attribute("str","Strength");
    insereAttributeToMap(att);

    att = new Attribute("dex","Dexterity");
    insereAttributeToMap(att);

    att = new Attribute("con","Constitution");
    insereAttributeToMap(att);

    att = new Attribute("int","Intelligence");
    insereAttributeToMap(att);

    att = new Attribute("wis","Wisdom");
    insereAttributeToMap(att);

    att = new Attribute("cha","Charisma");
    insereAttributeToMap(att);
}

void DataManager::loadClass()
{
    Class* cl;

    cl = new Class("fighter","Fighter");
    cl->setAttributeBounds("str",9,18);
    insereClassToMap(cl);

    cl = new Class("mage","Mage");
    cl->setAttributeBounds("int",9,18);
    insereClassToMap(cl);

    cl = new Class("thief","Thief");
    cl->setAttributeBounds("dex",9,18);
    insereClassToMap(cl);
}

void DataManager::loadRace()
{
    Race* rc;

    rc = new Race("human","Human");
    rc->addAvailableClass(getClassByKey("fighter"));
    rc->addAvailableClass(getClassByKey("mage"));
    rc->addAvailableClass(getClassByKey("thief"));
    insereRaceToMap(rc);

    rc = new Race("dwarf","Dwarf");
    rc->setAttributeBounds("str",8,18);
    rc->setAttributeBounds("dex",3,17);
    rc->setAttributeBounds("con",12,19);
    rc->setAttributeBounds("cha",2,16);
    rc->addAvailableClass(getClassByKey("fighter"));
    rc->addAvailableClass(getClassByKey("thief"));
    insereRaceToMap(rc);

    rc = new Race("elf","Elf");
    rc->setAttributeBounds("dex",7,19);
    rc->setAttributeBounds("con",6,17);
    rc->setAttributeBounds("int",8,18);
    rc->setAttributeBounds("cha",8,18);
    rc->addAvailableClass(getClassByKey("mage"));
    rc->addAvailableClass(getClassByKey("thief"));
    insereRaceToMap(rc);
}

void DataManager::insereAttributeToMap(Attribute* att)
{
    std::string id = att->getID();
    if("" == id)
        return;

    if(m_attributeMap.find(id) != m_attributeMap.end())
        m_attributeMap[id]->setID("");

    m_attributeMap[id] = att;
}

void DataManager::insereClassToMap(Class* cl)
{
    std::string id = cl->getID();
    if("" == id)
        return;

    if(m_classMap.find(id) != m_classMap.end())
        m_classMap[id]->setID("");

    m_classMap[id] = cl;
}

void DataManager::insereRaceToMap(Race* rc)
{
    std::string id = rc->getID();
    if("" == id)
        return;

    if(m_raceMap.find(id) != m_raceMap.end())
        m_raceMap[id]->setID("");

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



