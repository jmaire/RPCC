#ifndef DATALOADER_H
#define DATALOADER_H

#include "DataManager.h"

class DataLoader
{
    public:
        virtual ~DataLoader();

        static void load();
        static void loadAttribute();
        static void loadClass();
        static void loadRace();

    private:
        DataLoader();
};

#endif // DATALOADER_H
