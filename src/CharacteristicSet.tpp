
template <typename T>
CharacteristicSet<T>::CharacteristicSet(std::vector<std::string> a_id)
{
    for(unsigned int i=0; i<a_id.size(); i++)
        m_csMap[a_id.at(i)] = T(a_id.at(i));
}

template <typename T>
CharacteristicSet<T>::CharacteristicSet()
: CharacteristicSet(std::vector<std::string>())
{}

template <typename T>
CharacteristicSet<T>::~CharacteristicSet()
{}

template <typename T>
void CharacteristicSet<T>::insereID(std::string id)
{
    m_csMap[id] = T(id);
}

template <typename T>
bool CharacteristicSet<T>::isKeyUsed(std::string id)
{
    return m_csMap.find(id) != m_csMap.end();
}

template <typename T>
bool CharacteristicSet<T>::isIncreasable(std::string id, int inc)
{
    return isKeyUsed(id);
}
