#include "WeaponCategory.h"

namespace rpcc
{
    WeaponCategory::WeaponCategory(std::string id, std::string name)
    : Data(id)
    , m_name(name)
    {}

    WeaponCategory::WeaponCategory()
    : WeaponCategory(UNDEFINED_ID,"")
    {}

    WeaponCategory::~WeaponCategory()
    {}

    std::string WeaponCategory::getName()
    {
        return m_name;
    }
}
