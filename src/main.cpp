#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "AttributesSet.h"
#include "Dice.h"


int main(int argc, char* argv[])
{
    Race rc1 = Race("Humain");
    Race rc2 = Race("Elfe");
    Race rc3 = Race("Nain");

    Class cl1 = Class("Guerrier");
    Class cl2 = Class("Mage");
    Class cl3 = Class("Voleur");

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
    AttributesSet as3 = AttributesSet(&rc2,&cl3);
    as3.randomAssignment();
    as3.display();
}
