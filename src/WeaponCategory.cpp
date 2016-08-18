#include "WeaponCategory.h"

WeaponCategory::WeaponCategory(std::string id)
: Data(id)
{}

WeaponCategory::WeaponCategory()
: WeaponCategory(UNDEFINED_ID)
{}

WeaponCategory::~WeaponCategory()
{}

std::string WeaponCategory::getName()
{
    return m_name;
}
