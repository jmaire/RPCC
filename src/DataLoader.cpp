#include "DataLoader.h"

/*private*/ DataLoader::DataLoader()
{}

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
    cl->setAttributeBounds("str",9,18);
    DataManager::insereClassToMap(cl);

    cl = new Class("mage","Mage");
    cl->setAttributeBounds("int",9,18);
    DataManager::insereClassToMap(cl);

    cl = new Class("thief","Thief");
    cl->setAttributeBounds("dex",9,18);
    DataManager::insereClassToMap(cl);
}

void DataLoader::loadRace()
{
    Race* rc;
    rc = new Race("human","Human");
    rc->addAvailableClass(DataManager::getClassByKey("fighter"));
    rc->addAvailableClass(DataManager::getClassByKey("mage"));
    rc->addAvailableClass(DataManager::getClassByKey("thief"));
    DataManager::insereRaceToMap(rc);

    rc = new Race("dwarf","Dwarf");
    rc->setAttributeBounds("str",8,18);
    rc->setAttributeBounds("dex",3,17);
    rc->setAttributeBounds("con",12,19);
    rc->setAttributeBounds("cha",2,16);
    rc->addAvailableClass(DataManager::getClassByKey("fighter"));
    rc->addAvailableClass(DataManager::getClassByKey("thief"));
    DataManager::insereRaceToMap(rc);

    rc = new Race("elf","Elf");
    rc->setAttributeBounds("dex",7,19);
    rc->setAttributeBounds("con",6,17);
    rc->setAttributeBounds("int",8,18);
    rc->setAttributeBounds("cha",8,18);
    rc->addAvailableClass(DataManager::getClassByKey("mage"));
    rc->addAvailableClass(DataManager::getClassByKey("thief"));
    DataManager::insereRaceToMap(rc);
}
