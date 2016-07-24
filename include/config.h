#ifndef CONFIG_H
#define CONFIG_H

#include <string>

#define MY_MAX(x,y) ((x)>(y)?(x):(y))
#define MY_MIN(x,y) ((x)<(y)?(x):(y))

static const int ATTRIBUTES_SET_SIZE = 6;
static std::string ATTRIBUTES_SET_ATTRIBUTE_NAME[ATTRIBUTES_SET_SIZE] =
    {"Strength"
    ,"Dexterity"
    ,"Constitution"
    ,"Intelligence"
    ,"Wisdom"
    ,"Charisma"};

static const int ATTRIBUTE_DEFAULT_LOW_BOUNDARY = 3;
static const int ATTRIBUTE_DEFAULT_HIGH_BOUNDARY = 18;

#endif // CONFIG_H
