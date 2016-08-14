#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <map>
#include "DataLoader.h"

class DataManager
{
    public:
        virtual ~DataManager();

        static void load();
        static void loadAttribute();
        static void loadClass();
        static void loadRace();

        //static void destroy();

        static void insereAttributeToMap(Attribute* att);
        static void insereClassToMap(Class* cl);
        static void insereRaceToMap(Race* rc);

        static Attribute* getAttributeByKey(std::string key);
        static Class* getClassByKey(std::string key);
        static Race* getRaceByKey(std::string key);

    protected:
        static std::map<std::string,Attribute*> m_attributeMap;
        static std::map<std::string,Class*> m_classMap;
        static std::map<std::string,Race*> m_raceMap;

    private:
        DataManager();
};

#endif // DATAMANAGER_H
