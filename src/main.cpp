#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "Character.h"
#include "Dice.h"

int main(int argc, char* argv[])
{
    Race rc1 = Race("Human");
    Race rc2 = Race("Elf");
    Race rc3 = Race("Dwarf");

    Class cl1 = Class("Fighter");
    Class cl2 = Class("Mage");
    Class cl3 = Class("Thief");

    cl1.setAttributeBounds(0,9,18);
    cl2.setAttributeBounds(3,9,18);
    cl3.setAttributeBounds(1,9,18);

    rc1.addAvailableClass(&cl1);
    rc1.addAvailableClass(&cl2);
    rc1.addAvailableClass(&cl3);

    rc2.addAvailableClass(&cl2);
    rc2.addAvailableClass(&cl3);
    rc2.setAttributeBounds(1,7,18);
    rc2.setAttributeBounds(2,6,18);
    rc2.setAttributeBounds(3,8,18);
    rc2.setAttributeBounds(5,8,18);

    rc3.addAvailableClass(&cl1);
    rc3.addAvailableClass(&cl3);
    rc3.setAttributeBounds(0,8,18);
    rc3.setAttributeBounds(1,4,18);
    rc3.setAttributeBounds(2,11,18);
    rc3.setAttributeBounds(5,4,18);

    //AttributesSet as1 = AttributesSet(&rc1,&cl2);
    //AttributesSet as2 = AttributesSet(&rc3,&cl1);

    Character ch1 = Character();
    ch1.setName("Julien");
    ch1.setRace(&rc1);
    ch1.setGender(Gender::MALE);
    ch1.setClass(&cl1);
    std::cout << ch1.toString();
}
