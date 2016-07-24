#ifndef CLASS_H
#define CLASS_H

#include <vector>
#include "config.h"

class Class
{
    public:
        Class(std::string n);
        Class(void);

        virtual ~Class(void);

        std::pair<unsigned int,unsigned int> getAttributeBounds(unsigned int ind);

        void setAttributeBounds(unsigned int ind, unsigned int lb, unsigned int hb);

    protected:
        std::string m_name;
        std::pair<unsigned int,unsigned int> ma_attributesBounds[ATTRIBUTES_SET_SIZE];

};

#endif // CLASS_H
