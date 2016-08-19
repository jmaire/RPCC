#ifndef CHARACTERISTICSET_H
#define CHARACTERISTICSET_H

#include <map>
#include <vector>
#include "CharacteristicScore.h"

template <typename T=CharacteristicScore>
class CharacteristicSet
{
    public:
        virtual ~CharacteristicSet();

        virtual bool isIncreasable(std::string id, int inc);

        void insereID(std::string id);

    protected:
        std::map<std::string,T> m_csMap;

        CharacteristicSet(std::vector<std::string> a_id);
        CharacteristicSet();

        bool isKeyUsed(std::string id);
};

#include "../src/CharacteristicSet.tpp"

#endif // CHARACTERISTICSET_H
