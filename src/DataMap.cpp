#include "DataMap.h"

DataMap::DataMap()
{}

DataMap::~DataMap()
{}

void DataMap::clearDataMap()
{
    std::map<std::string,Data*>::iterator it;
    while(!m_dataMap.empty())
    {
        it = m_dataMap.begin();
        m_dataMap.erase(it);
        delete it->second;
    }
}

bool DataMap::isKeyFormatValid(std::string key)
{
    return key != UNDEFINED_ID;
}

void DataMap::insereDataToMap(Data* data)
{
    std::string id = data->getID();

    if(!isKeyFormatValid(id))
        return;

    if(m_dataMap.find(id) != m_dataMap.end())
        m_dataMap[id]->setIDToUndefined();

    m_dataMap[id] = data;
}

Data* DataMap::getDataByKey(std::string key)
{
    if(m_dataMap.find(key) == m_dataMap.end())
        return nullptr;
    return m_dataMap.at(key);
}

std::vector<Data*> DataMap::toVector()
{
    std::vector<Data*> dataVector;
    for(std::map<std::string,Data*>::iterator it=m_dataMap.begin(); it!=m_dataMap.end(); ++it)
        dataVector.push_back(it->second);

    return dataVector;
}

