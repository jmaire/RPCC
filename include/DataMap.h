#ifndef DATAMAP_H
#define DATAMAP_H

#include <map>
#include <vector>
#include "Data.h"

class DataMap
{
    public:
        DataMap();

        virtual ~DataMap();
        void clearDataMap();

        bool isKeyFormatValid(std::string key);

        void insereDataToMap(Data* data);

        Data* getDataByKey(std::string key);

        std::vector<Data*> toVector();

    protected:
        std::map<std::string,Data*> m_dataMap;
};

#endif // DATAMAP_H
