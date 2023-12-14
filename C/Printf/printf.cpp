#include <stdarg.h>
#include <iostream>

namespace arm 
{
  void printf(const char* format, ...)
  {
    va_list list;
    va_start(list,format);
    while (*format != '\0') {
    if (*format == 'd')
    {
        std::cout << va_arg(list,int);
    }
    else if (*format == 'c')
    {
        std::cout << static_cast<char>(va_arg(list, int));
    }
    else if (*format == '\n')
    {
        std::cout << std::endl;
    }
    else 
    {
      throw;
    }
    format++;
  }

    va_end(list);
  }
}



int main() {
  arm::printf("dddcccd\n", 1, 2, 3, 97, 98, 99, 100);
}
