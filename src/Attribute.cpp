#include "Attribute.h"

Attribute::Attribute(std::string nm)
: m_name(nm)
, m_description("")
{}

Attribute::Attribute()
: Attribute("")
{}

Attribute::~Attribute()
{}
