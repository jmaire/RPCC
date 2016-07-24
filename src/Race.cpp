#include <algorithm>
#include "Race.h"

Race::Race(std::string n)
{
    m_name = n;
    m_class_restriction.clear();
    for(int i=0; i<ATTRIBUTES_SET_SIZE; i++)
    {
        ma_attributesBounds[i].first = ATTRIBUTE_DEFAULT_LOW_BOUNDARY;
        ma_attributesBounds[i].second = ATTRIBUTE_DEFAULT_HIGH_BOUNDARY;
    }
}

Race::Race()
: Race("#UNDEFINED")
{}

/*virtual*/ Race::~Race()
{}

std::pair<unsigned int,unsigned int> Race::getAttributeBounds(unsigned int ind)
{
    return ma_attributesBounds[ind];
}

void Race::addAvailableClass(Class* cl)
{
    if(std::find(m_class_restriction.begin(), m_class_restriction.end(), cl) == m_class_restriction.end())
    {
        m_class_restriction.push_back(cl);
    }
}

void Race::setAttributeBounds(unsigned int ind, unsigned int lb, unsigned int hb)
{
    ma_attributesBounds[ind].first = lb;
    ma_attributesBounds[ind].second = hb;
}

