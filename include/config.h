#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <stdlib.h>
#include <string>

#define MY_MAX(x,y) ((x)>(y)?(x):(y))
#define MY_MIN(x,y) ((x)<(y)?(x):(y))

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

#define ATTRIBUTES_NON_CONSTANT_COST 0

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

static const std::string UNDEFINED_STRING = "#UNDEFINED";
static const std::string UNDEFINED_ID = "";

///////////////////////////////////////////////////////

enum CharacterCreationStep
{
    CREATION_START,
    RACE_SELECTION,
    GENDER_SELECTION,
    CLASS_SELECTION,
    //
    NAME_SELECTION,
    //PORTRAIT_SELECTION,
    CREATION_DONE
};

///////////////////////////////////////////////////////

static const int ATTRIBUTE_NEUTRAL_SCORE = 10;
static const int ATTRIBUTE_DEFAULT_LOW_BOUNDARY = 3;
static const int ATTRIBUTE_DEFAULT_HIGH_BOUNDARY = 18;
static const int ATTRIBUTE_STARTING_UNASSIGNED_POINTS = 15;

#if ATTRIBUTES_NON_CONSTANT_COST == 1
static const int ATTRIBUTE_POSSIBLE_VALUES = ATTRIBUTE_DEFAULT_HIGH_BOUNDARY-ATTRIBUTE_DEFAULT_LOW_BOUNDARY+1;
static const int ATTRIBUTES_COST[ATTRIBUTE_POSSIBLE_VALUES] = {-4,-3,-2,-2,-1,-1,-1,0,1,1,1,2,2,3,4,5};
static const int ATTRIBUTES_UNASSIGNED[ATTRIBUTE_POSSIBLE_VALUES];
//static const int ATTRIBUTES_UNASSIGNED[ATTRIBUTE_POSSIBLE_VALUES] = {-14,-10,-7,-5,-3,-2,-1,0,1,2,3,5,7,10,14,19};
#endif // ATTRIBUTES_NON_CONSTANT_COST


static const int TRAITS_SET_SIZE = 7;
static std::pair<std::string,std::string> TRAITS_SET_TRAIT_NAMES[TRAITS_SET_SIZE] =
    {std::make_pair("Lawful","Chaotic")
    ,std::make_pair("Spiritual","Materialistic")
    ,std::make_pair("Independent","Obedient")
    ,std::make_pair("Compassionate","Heartless")
    ,std::make_pair("Forgiving","Vindictive")
    ,std::make_pair("Altruistic","Egotistical")
    ,std::make_pair("Thoughtful","Impulsive")
    };

//static std::vector<Trait*> TRAITS_LIST;

static const int TRAIT_SCORE_ABSOLUTE_BOUNDARY = 100;


#endif // CONFIG_H
