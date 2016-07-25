#ifndef WEAPON_H
#define WEAPON_H

enum class WeaponType
{
    AXE
    , BOW
    , CLUB
    , CROSSBOW
    , DAGGER
    , SPEAR
    , STAFF
    , SWORD
};

enum class WeaponAncor
{
    ONE_HANDED
    , TWO_HANDED
    , MAIN_HAND
    , OFF_HAND
};

class Weapon
{
    public:
        Weapon();
        virtual ~Weapon();

    protected:

    private:
};

#endif // WEAPON_H
