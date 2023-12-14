#include <iostream>

#include "hero.hpp"

int main() {
    Hero hero;
    Weapon* tank = new Tank;
    Weapon* gun = new Gun;
    Weapon* knife = new Knife;

    hero.set_weapon(tank);
    hero.attack();

    hero.set_weapon(gun);
    hero.attack();

    hero.set_weapon(knife);
    hero.attack();
    

    delete tank;
    delete gun;
    delete knife;
}