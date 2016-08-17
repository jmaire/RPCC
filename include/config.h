#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <stdlib.h>
#include <string>

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

static const std::string UNDEFINED_ID = "";

///////////////////////////////////////////////////////

enum CharacterCreationStep
{
    CREATION_START,
    RACE_SELECTION,
    GENDER_SELECTION,
    CLASS_SELECTION,
    ATTRIBUTES_SETTING,
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

static const int TRAIT_NEUTRAL_SCORE = 0;
static const int TRAIT_SCORE_ABSOLUTE_BOUNDARY = 100;


#endif // CONFIG_H
