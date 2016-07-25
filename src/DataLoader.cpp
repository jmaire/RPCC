#include "DataLoader.h"

DataLoader::DataLoader(void)
{}

/*virtual*/ DataLoader::~DataLoader(void)
{}

/*static*/ void DataLoader::load(void)
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

    allClassList.push_back(c1);
    allClassList.push_back(c2);
    allClassList.push_back(c3);
    allRaceList.push_back(r1);
    allRaceList.push_back(r2);
    allRaceList.push_back(r3);
    allRaceList.push_back(r4);

}
