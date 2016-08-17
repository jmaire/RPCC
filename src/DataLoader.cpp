#include "DataLoader.h"

/*private*/ DataLoader::DataLoader() {}

DataLoader::~DataLoader()
{}

void DataLoader::load()
{
    loadAttribute();
    loadClass();
    loadRace();
}

void DataLoader::loadAttribute()
{
    Attribute* att;
    att = new Attribute("str","Strength");
    DataManager::insereAttributeToMap(att);

    att = new Attribute("dex","Dexterity");
    DataManager::insereAttributeToMap(att);

    att = new Attribute("con","Constitution");
    DataManager::insereAttributeToMap(att);

    att = new Attribute("int","Intelligence");
    DataManager::insereAttributeToMap(att);

    att = new Attribute("wis","Wisdom");
    DataManager::insereAttributeToMap(att);

    att = new Attribute("cha","Charisma");
    DataManager::insereAttributeToMap(att);
}

void DataLoader::loadClass()
{
    Class* cl;
    cl = new Class("fighter","Fighter");
    cl->setAttributeLowBoundary("str",9);
    DataManager::insereClassToMap(cl);

    cl = new Class("mage","Mage");
    cl->setAttributeLowBoundary("int",9);
    DataManager::insereClassToMap(cl);

    cl = new Class("thief","Thief");
    cl->setAttributeLowBoundary("dex",9);
    DataManager::insereClassToMap(cl);
}

void DataLoader::loadRace()
{
    Race* rc;
    rc = new Race("human","Human");
    rc->addAvailableClass("fighter");
    rc->addAvailableClass("mage");
    rc->addAvailableClass("thief");
    DataManager::insereRaceToMap(rc);

    rc = new Race("dwarf","Dwarf");
    rc->setAttributeLowerBoundary("str",8);
    rc->setAttributeHigherBoundary("dex",17);
    rc->setAttributeBounds("con",12,19);
    rc->setAttributeBounds("cha",2,16);
    rc->setAttributeBonus("dex",-1);
    rc->setAttributeBonus("con",1);
    rc->setAttributeBonus("cha",-2);
    rc->addAvailableClass("fighter");
    rc->addAvailableClass("thief");
    DataManager::insereRaceToMap(rc);

    rc = new Race("elf","Elf");
    rc->setAttributeBounds("dex",7,19);
    rc->setAttributeBounds("con",6,17);
    rc->setAttributeLowerBoundary("int",8);
    rc->setAttributeLowerBoundary("cha",8);
    rc->setAttributeBonus("dex",1);
    rc->setAttributeBonus("con",-1);
    rc->addAvailableClass("mage");
    rc->addAvailableClass("thief");
    DataManager::insereRaceToMap(rc);
}
