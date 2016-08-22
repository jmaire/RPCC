#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <stdlib.h>
#include <string>

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

#define CONSOLE_UI 0
#define WINDOWS_GUI 1
#define USED_UI CONSOLE_UI

static const std::string UNDEFINED_ID = "";

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

enum CharacterCreationStep
{
    CREATION_START,
    RACE_SELECTION,
    GENDER_SELECTION,
    CLASS_SELECTION,
    ATTRIBUTES_SETTING,
    WEAPONPROFICIENCY_SETTING,
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

static const int TRAIT_NEUTRAL_SCORE = 0;
static const int TRAIT_SCORE_ABSOLUTE_BOUNDARY = 100;

#define WEAPON_PROFICIENCY_GLOBAL_BOUNDARY
static const int WEAPON_PROFICIENCY_MAX_BOUNDARY = 5;


///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////


#endif // CONFIG_H
