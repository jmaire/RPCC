#include "DataLoader.h"

namespace rpcc
{
    DataLoader::DataLoader()
    {}

    DataLoader::~DataLoader()
    {}

    void DataLoader::loadData()
    {
        loadAttribute();
        loadClass();
        loadRace();
        loadWeaponCategory();
    }

    void DataLoader::loadAttribute()
    {
        Attribute* att;
        att = new Attribute("str","Strength");
        DataManager::insereDataToMap(att);

        att = new Attribute("dex","Dexterity");
        DataManager::insereDataToMap(att);

        att = new Attribute("con","Constitution");
        DataManager::insereDataToMap(att);

        att = new Attribute("int","Intelligence");
        DataManager::insereDataToMap(att);

        att = new Attribute("wis","Wisdom");
        DataManager::insereDataToMap(att);

        att = new Attribute("cha","Charisma");
        DataManager::insereDataToMap(att);
    }

    void DataLoader::loadClass()
    {
        Class* cl;
        cl = new Class("fighter","Fighter");
        cl->setAttributeLowBoundary("str",9);
        cl->setWeaponProficiencyMaxBoundary(5);
        cl->setStartingWeaponProficiency(4);
        cl->addAvailableWC("axe");
        cl->addAvailableWC("bow");
        cl->addAvailableWC("dagger");
        cl->addAvailableWC("hammer");
        cl->addAvailableWC("sword");
        DataManager::insereDataToMap(cl);

        cl = new Class("mage","Mage");
        cl->setAttributeLowBoundary("int",9);
        cl->setWeaponProficiencyMaxBoundary(1);
        cl->setStartingWeaponProficiency(1);
        cl->addAvailableWC("dagger");
        cl->addAvailableWC("wand");
        DataManager::insereDataToMap(cl);

        cl = new Class("thief","Thief");
        cl->setAttributeLowBoundary("dex",9);
        cl->setWeaponProficiencyMaxBoundary(1);
        cl->setStartingWeaponProficiency(2);
        cl->addAvailableWC("bow");
        cl->addAvailableWC("dagger");
        cl->addAvailableWC("sword");
        DataManager::insereDataToMap(cl);
    }

    void DataLoader::loadRace()
    {
        Race* rc;
        rc = new Race("human","Human");
        rc->addAvailableClass("fighter");
        rc->addAvailableClass("mage");
        rc->addAvailableClass("thief");
        DataManager::insereDataToMap(rc);

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
        DataManager::insereDataToMap(rc);

        rc = new Race("elf","Elf");
        rc->setAttributeBounds("dex",7,19);
        rc->setAttributeBounds("con",6,17);
        rc->setAttributeLowerBoundary("int",8);
        rc->setAttributeLowerBoundary("cha",8);
        rc->setAttributeBonus("dex",1);
        rc->setAttributeBonus("con",-1);
        rc->addAvailableClass("mage");
        rc->addAvailableClass("thief");
        DataManager::insereDataToMap(rc);
    }

    void DataLoader::loadWeaponCategory()
    {
        WeaponCategory* wc;
        wc = new WeaponCategory("axe","Axe");
        DataManager::insereDataToMap(wc);

        wc = new WeaponCategory("bow","Bow");
        DataManager::insereDataToMap(wc);

        wc = new WeaponCategory("dagger","Dagger");
        DataManager::insereDataToMap(wc);

        wc = new WeaponCategory("hammer","Hammer");
        DataManager::insereDataToMap(wc);

        wc = new WeaponCategory("sword","Sword");
        DataManager::insereDataToMap(wc);

        wc = new WeaponCategory("wand","Wand");
        DataManager::insereDataToMap(wc);
    }
}
