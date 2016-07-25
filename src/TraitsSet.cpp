#include "TraitsSet.h"

TraitsSet::TraitsSet(std::vector<Trait*> trts)
{
    for(std::vector<Trait*>::iterator it = trts.begin() ; it != trts.end(); ++it)
    {
        m_traits.push_back(TraitScore(*it));
    }
}


TraitsSet::TraitsSet(void)
{}

/*virtual*/ TraitsSet::~TraitsSet(void)
{}
