#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <map>
#include "DataLoader.h"

class DataManager
{
    public:
        virtual ~DataManager(void);

        static void load(void);

    protected:
        static std::map<unsigned int,Race*> m_raceMap;
        static std::map<unsigned int,Class*> m_classMap;

    private:
        DataManager(void);
};

#endif // DATAMANAGER_H
