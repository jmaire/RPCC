#include "Data.h"

namespace rpcc
{
    Data::Data(std::string id)
    : m_id(id)
    {}

    Data::Data()
    : Data(UNDEFINED_ID)
    {}

    Data::~Data()
    {}

    std::string Data::getID()
    {
        return m_id;
    }

    void Data::setIDToUndefined()
    {
        m_id = UNDEFINED_ID;
    }
}
