#include "Data.h"

Data::Data(std::string id)
: m_id(id)
{}

Data::Data()
: Data(UNDEFINED_ID)
{}

Data::~Data()
{
    //dtor
}

std::string Data::getID()
{
    return m_id;
}

void Data::setIDToUndefined()
{
    m_id = UNDEFINED_ID;
}
