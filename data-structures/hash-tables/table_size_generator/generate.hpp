#ifndef GEN
#define GEN

bool is_prime(int num) 
{
    if (num <= 1) 
    {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) 
    {
        if (num % i == 0) 
        {
            return false;
        }
    }
    return true;
}

size_t generate_prime_size(int curr_prime = 0) 
{
    int nextNumber = curr_prime + 1;
    while (!is_prime(nextNumber)) 
    {
        ++nextNumber;
    }
    return nextNumber;
}

#endif //GEN
