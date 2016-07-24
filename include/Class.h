#ifndef CLASS_H
#define CLASS_H

#include <vector>
#include "config.h"
#include "Alignment.h"

#define RESTRICTED_ALIGNMENT_FROM_CLASS 1

class Class
{
    public:
        Class(std::string n);
        Class(void);

        virtual ~Class(void);

        std::vector<Alignment*> getAvailableAlignment(void);
        std::pair<unsigned int,unsigned int> getAttributeBounds(unsigned int ind);

        void addAvailableAlignment(Alignment* al);
        void setAttributeBounds(unsigned int ind, unsigned int lb, unsigned int hb);

    protected:
        std::string m_name;
        std::vector<Alignment*> m_alignment_restriction;
        std::pair<unsigned int,unsigned int> ma_attributesBounds[ATTRIBUTES_SET_SIZE];

};

#endif // CLASS_H
