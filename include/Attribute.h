#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <string>

class Attribute
{
    public:
        Attribute(std::string nm);
        Attribute();

        virtual ~Attribute();

    protected:
        std::string m_name, m_description;

};

#endif // ATTRIBUTE_H
