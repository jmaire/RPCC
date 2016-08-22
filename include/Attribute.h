#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include "Data.h"

namespace rpcc
{
    class Attribute : public Data
    {
        public:
            Attribute(std::string id, std::string name);
            Attribute();

            virtual ~Attribute();

            std::string getName();

        protected:
            std::string m_name, m_description;

    };
}

#endif // ATTRIBUTE_H
