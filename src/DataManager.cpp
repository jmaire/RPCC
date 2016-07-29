#include "DataManager.h"
#include "tools.h"

/*static*/ std::map<std::string,Race*> DataManager::m_raceMap;
/*static*/ std::map<std::string,Class*> DataManager::m_classMap;

DataManager::DataManager()
{}

DataManager::~DataManager()
{}

void DataManager::load()
{
    Class* c1 = new Class("Fighter");
    Class* c2 = new Class("Mage");
    Class* c3 = new Class("Thief");

    Race* r1 = new Race("Human");
    Race* r2 = new Race("Dwarf");
    Race* r3 = new Race("Elf");

    r1->addAvailableClass(c1);
    r1->addAvailableClass(c2);
    r1->addAvailableClass(c3);
    r2->addAvailableClass(c1);
    r2->addAvailableClass(c3);
    r3->addAvailableClass(c2);
    r3->addAvailableClass(c3);

    r2->setAttributeBounds(0,8,18);
    r2->setAttributeBounds(1,3,17);
    r2->setAttributeBounds(2,12,19);
    r2->setAttributeBounds(5,2,16);
    r3->setAttributeBounds(1,7,19);
    r3->setAttributeBounds(2,6,17);
    r3->setAttributeBounds(3,8,18);
    r3->setAttributeBounds(5,8,18);

    c1->setAttributeBounds(0,9,18);
    c2->setAttributeBounds(3,9,18);
    c3->setAttributeBounds(1,9,18);

    m_classMap["fighter"] = c1;
    m_classMap["mage"] = c2;
    m_classMap["thief"] = c3;
    m_raceMap["human"] = r1;
    m_raceMap["dwarf"] = r2;
    m_raceMap["elf"] = r3;
}

Race* DataManager::getRaceByKey(std::string key)
{
    return m_raceMap.at(key);
}

Class* DataManager::getClassByKey(std::string key)
{
    return m_classMap.at(key);
}

