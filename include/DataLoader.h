#ifndef DATALOADER_H
#define DATALOADER_H

#include "data.h"

class DataLoader
{
    public:
        virtual ~DataLoader(void);

        static void load(void);

    private:
        DataLoader(void);
};

#endif // DATALOADER_H
