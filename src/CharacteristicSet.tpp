template <typename T>
CharacteristicSet<T>::CharacteristicSet()
{}

template <typename T>
CharacteristicSet<T>::~CharacteristicSet()
{}

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
