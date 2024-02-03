#ifndef BIT_VECOTR_HPP
#define BIT_VECOTR_HPP

#define SIZEOF_UINT (sizeof(uint32_t) * 8)

namespace armanstd{
  class bitvector {
    private: 
    	std::vector < uint32_t > bits;
  
    public:   
    	bitvector(int n)
      {
          if (n <= 0) 
          {
              std::cout << "size too small \n";
          }
          if ((sizeof(uint32_t) * 8) / n > 0) 
          {
              bits.resize(1, 0);
          } 
          else 
          {
            if (!(n % 32)) 
            {
                bits.resize(n / SIZEOF_UINT, 0);
      
            } 
            else 
            {
                bits.resize((n / SIZEOF_UINT) + 1, 0);
            }
          }
    }
  
    void printBits() const 
    {
      for (int i = this -> bits.size() - 1; i >= 0; --i) 
      {
          for (int j = 31; j >= 0; --j) 
          {
              std::cout << (bool)(this -> bits[i] & (1 << j)) << " ";
          }
          std::cout << std::endl;
      }
    }
  
    void set(int n) 
    {
        if (n < 0 || n > this -> bits.size() * SIZEOF_UINT) 
        {
            std::cout << "out of bounds \n";
        }
        int index = n / SIZEOF_UINT;
        int bit = n % SIZEOF_UINT;
        this->bits[index] |= (1 << bit);
    }
    
    void reset(int n) 
    {
      if (n < 0 || n > this -> bits.size() * SIZEOF_UINT) 
      {
        std::cout << "out of bounds \n";
      }
      int index = n / SIZEOF_UINT;
      int bit = n % SIZEOF_UINT;
      this -> bits[index] &= ~(1 << bit);
    }

};

}
#endif
