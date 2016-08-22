#ifndef RACE_H
#define RACE_H

#include <vector>
#include "Data.h"
#include "Class.h"

namespace rpcc
{
    class Race : public Data
    {
        public:
            Race(std::string id, std::string name);
            Race();

            virtual ~Race();

            std::string getName();

            void setRacePlayable(bool playable);
            bool isPlayable();

            bool haveAttributeLowerBoundary(std::string key);
            bool haveAttributeHigherBoundary(std::string key);

            int getAttributeLowerBoundary(std::string key);
            int getAttributeHigherBoundary(std::string key);

            void setAttributeLowerBoundary(std::string key, int boundary);
            void setAttributeHigherBoundary(std::string key, int boundary);
            void setAttributeBounds(std::string key, int lowerBoundary, int higherBoundary);

            int getAttributeBonus(std::string key);
            void setAttributeBonus(std::string key, int bonus);

            std::vector<std::string> getAvailableClass();
            void addAvailableClass(std::string key);

        protected:
            std::string m_name;
            bool m_playable;
            std::vector<std::string> m_classRestriction;
            std::map<std::string,int> m_attributesLowerBoundary;
            std::map<std::string,int> m_attributesHigherBoundary;
            std::map<std::string,int> m_attributesBonus;

    };
}

#endif // RACE_H
