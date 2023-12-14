
class Color {
public:
    virtual ~Color() = default;
    virtual void coloring () const = 0;
};

class Red : public Color {
public:
    void coloring() const override 
    {
        std::cout << "Redding \n";
    }
};

class Green : public Color {
public:
    void coloring() const override 
    { 
        std::cout << "Blueing \n";
    }
};

