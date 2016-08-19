#include "TraitsSet.h"

TraitsSet::TraitsSet(std::vector<std::string> a_traitID)
: CharacteristicSet(a_traitID)
{}

TraitsSet::TraitsSet()
: TraitsSet(std::vector<std::string>())
{}

TraitsSet::~TraitsSet()
{}
