template <typename T>
DataMap<T>::DataMap()
{}

template <typename T>
DataMap<T>::~DataMap()
{}

template <typename T>
void DataMap<T>::flushMap()
{
    typename std::map<std::string,T*>::iterator it;
    while(!m_map.empty())
    {
        it = m_map.begin();
        m_map.erase(it);
        delete it->second;
    }
}

template <typename T>
bool DataMap<T>::isKeyFormatValid(std::string key)
{
    return key != UNDEFINED_ID;
}

template <typename T>
void DataMap<T>::insereDataToMap(T* data)
{
    std::string id = data->getID();

    if(!isKeyFormatValid(id))
        return;

    if(m_map.find(id) != m_map.end())
        m_map[id]->setIDToUndefined();

    m_map[id] = data;
}

template <typename T>
T* DataMap<T>::getDataByKey(std::string key)
{
    if(m_map.find(key) == m_map.end())
        return nullptr;
    return m_map.at(key);
}

template <typename T>
std::vector<T*> DataMap<T>::toVector()
{
    std::vector<T*> a_vector;
    for(typename std::map<std::string,T*>::iterator it=m_map.begin(); it!=m_map.end(); ++it)
        a_vector.push_back(it->second);

    return a_vector;
}

