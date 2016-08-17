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

    while(ind<0 || ind>=raceVector.size())
    {
        std::cout << "Erreur, le numéro " << ind << " n'est pas une entrée valide.\n";
        std::cout << "Sélectionnez la race: ";
        std::cin >> ind;
    }

    std::cout << "Vous avez choisi la race " << raceVector.at(ind)->getName() << ".\n";
    ch->setRace(raceVector.at(ind));
}
