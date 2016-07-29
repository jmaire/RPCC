#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <map>
#include "DataLoader.h"

class DataManager
{
    public:
        virtual ~DataManager();

        static void load();

        static Race* getRaceByKey(std::string key);
        static Class* getClassByKey(std::string key);

    protected:
        static std::map<std::string,Race*> m_raceMap;
        static std::map<std::string,Class*> m_classMap;

    private:
        DataManager();
};

#endif // DATAMANAGER_H
