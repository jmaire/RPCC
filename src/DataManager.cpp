#include "DataManager.h"
#include "tools.h"

/*static*/ std::map<unsigned int,Race*> DataManager::m_raceMap;
/*static*/ std::map<unsigned int,Class*> DataManager::m_classMap;

DataManager::DataManager(void)
{}

DataManager::~DataManager(void)
{}

/*static*/ void DataManager::load(void)
{
    Class* c1 = new Class("Fighter");
    Class* c2 = new Class("Mage");
    Class* c3 = new Class("Thief");

    Race* r1 = new Race("Human");
    Race* r2 = new Race("Dwarf");
    Race* r3 = new Race("Elf");
    Race* r4 = new Race("Orc");

    r1->addAvailableClass(c1);
    r1->addAvailableClass(c2);
    r1->addAvailableClass(c3);

    r2->addAvailableClass(c1);
    r2->addAvailableClass(c3);

    r3->addAvailableClass(c2);
    r3->addAvailableClass(c3);

    r4->addAvailableClass(c1);

    m_classMap[0] = c1;
    m_classMap[1] = c2;
    m_classMap[10] = c3;
    m_raceMap[0] = r1;
    m_raceMap[1] = r2;
    m_raceMap[4] = r3;
    m_raceMap[57] = r4;
}

