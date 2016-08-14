#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <string>

class Attribute
{
    public:
        Attribute(std::string id, std::string name);
        Attribute();

        virtual ~Attribute();

        std::string getID();
        std::string getName();

        void setID(std::string id);

    protected:
        std::string m_id, m_name, m_description;

};

#endif // ATTRIBUTE_H
