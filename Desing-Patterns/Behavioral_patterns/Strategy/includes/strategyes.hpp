class Weapon {
public:
    virtual ~Weapon() {}
    virtual void action() const = 0;
};

class Gun : public Weapon {
public:
    void action() const override 
    {
        std::cout << "Attaced by Gun\n";
    }
};

class Knife : public Weapon {
public:
    void action() const override 
    { 
        std::cout << "Attaced by Knife\n";
    }
};

class Tank : public Weapon {
public:
    void action() const override 
    {
        std::cout << "Attaced by Tank\n";
    }
};
