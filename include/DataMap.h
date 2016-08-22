#ifndef DATAMAP_H
#define DATAMAP_H

#include <map>
#include <vector>
#include "Data.h"

namespace rpcc
{
    template <typename T=Data>
    class DataMap
    {
        public:
            DataMap();

            virtual ~DataMap();
            void flushMap();

            bool isKeyFormatValid(std::string key);
            void insereDataToMap(T* data);
            T* getDataByKey(std::string key);

            std::vector<T*> toVector();

        protected:
            std::map<std::string,T*> m_map;
    };

    #include "../src/DataMap.tpp"
}

#endif // DATAMAP_H
