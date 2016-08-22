#ifndef DATALOADER_H
#define DATALOADER_H

#include "DataManager.h"

namespace rpcc
{
    class DataLoader
    {
        public:
            virtual ~DataLoader();

            static void loadData();
            static void loadAttribute();
            static void loadClass();
            static void loadRace();
            static void loadTrait();
            static void loadWeaponCategory();

        private:
            DataLoader();
    };
}

#endif // DATALOADER_H
