#include <algorithm>
#include "Class.h"

Class::Class(std::string n)
{
    m_name = n;
    for(int i=0; i<ATTRIBUTES_SET_SIZE; i++)
    {
        ma_attributesBounds[i].first = ATTRIBUTE_DEFAULT_LOW_BOUNDARY;
        ma_attributesBounds[i].second = ATTRIBUTE_DEFAULT_HIGH_BOUNDARY;
    }
}


Class::Class(void)
: Class("#UNDEFINED")
{}

/*virtual*/ Class::~Class(void)
{}

std::string* Class::getName(void)
{
    return &m_name;
}

std::pair<unsigned int,unsigned int> Class::getAttributeBounds(unsigned int ind)
{
    return ma_attributesBounds[ind];
}

void Class::setAttributeBounds(unsigned int ind, unsigned int lb, unsigned int hb)
{
    ma_attributesBounds[ind].first = lb;
    ma_attributesBounds[ind].second = hb;
}

