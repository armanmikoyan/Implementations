class Singleton {
public:
    static Singleton* create() 
    {
        if (!_instance)
        {
            _instance = new Singleton;
        }
        return _instance;
    }

private:
    Singleton() 
    {
        std::cout << "Created\n";
    }
private:
    static Singleton* _instance;
};


