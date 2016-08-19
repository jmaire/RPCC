#include "TraitSet.h"

TraitSet::TraitSet(std::vector<std::string> a_traitID)
: CharacteristicSet(a_traitID)
{}

TraitSet::TraitSet()
: TraitSet(std::vector<std::string>())
{}

TraitSet::~TraitSet()
{}
