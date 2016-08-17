#include "CharacterCreatorConsoleUI.h"

#include <iostream>

CharacterCreatorConsoleUI::CharacterCreatorConsoleUI()
: CharacterCreatorBaseUI()
{}

CharacterCreatorConsoleUI::~CharacterCreatorConsoleUI()
{}

void CharacterCreatorConsoleUI::selectRace(Character* ch)
{
    std::cout << "Races disponibles: \n";
    std::vector<Race*> raceVector = DataManager::getRaceVector();
    for(unsigned int i=0; i<raceVector.size(); i++)
    {
        std::cout << "\t[" << i << "]: " << raceVector.at(i)->getName() << "\n";
    }

    std::cout << "Sélectionnez la race: ";
    unsigned int ind;
    std::cin >> ind;

    while(0>ind || ind>=raceVector.size())
    {
        std::cout << "Erreur, le numéro " << ind << " n'est pas une entrée valide.\n";
        std::cout << "Sélectionnez la race: ";
        std::cin >> ind;
    }

    std::cout << "Vous avez choisi " << raceVector.at(ind)->getName() << ".\n";
    ch->setRace(raceVector.at(ind));
}

void CharacterCreatorConsoleUI::selectGender(Character* ch)
{
    std::cout << "Sexes disponibles: \n";
    for(unsigned int i=0; i<(unsigned int)Gender::GENDER_SIZE; i++)
    {
        std::cout << "\t[" << i << "]: " << GENDER_NAME[i] << "\n";
    }

    std::cout << "Sélectionnez le sexe: ";
    unsigned int ind;
    std::cin >> ind;

    while(0>ind || ind>=(unsigned int)Gender::GENDER_SIZE)
    {
        std::cout << "Erreur, le numéro " << ind << " n'est pas une entrée valide.\n";
        std::cout << "Sélectionnez le sexe: ";
        std::cin >> ind;
    }

    std::cout << "Vous avez choisi " << GENDER_NAME[ind] << ".\n";
    ch->setGender((Gender)ind);
}

void CharacterCreatorConsoleUI::selectClass(Character* ch)
{
    std::cout << "Classes disponibles: \n";
    std::vector<std::string> classIDVector = ch->getAvailableClass();
    std::vector<Class*> classVector;
    for(unsigned int i=0; i<classIDVector.size(); i++)
    {
        classVector.push_back(DataManager::getClassByKey(classIDVector.at(i)));
        std::cout << "\t[" << i << "]: " << classVector.at(i)->getName() << "\n";
    }

    std::cout << "Sélectionnez la classe: ";
    unsigned int ind;
    std::cin >> ind;

    while(0>ind || ind>=classVector.size())
    {
        ind = -1;
        std::cout << "Erreur, le numéro " << ind << " n'est pas une entrée valide.\n";
        std::cout << "Sélectionnez la classe: ";
        std::cin >> ind;
    }

    std::cout << "Vous avez choisi " << classVector.at(ind)->getName() << ".\n";
    ch->setClass(classVector.at(ind));
}

void CharacterCreatorConsoleUI::selectName(Character* ch)
{
    std::cout << "Entrez le nom: ";
    std::string name;
    std::cin >> name;

    std::cout << "Vous avez choisi " << name << ".\n";
    ch->setName(name);
}
