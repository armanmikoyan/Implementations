#include "strategyes.hpp"

class Hero {
public:
    void set_weapon(Weapon* weapon) 
    {
        _weapon = weapon;
    }

    void attack()
    {
        _weapon->action();
    }
    
private:
    Weapon* _weapon;
};