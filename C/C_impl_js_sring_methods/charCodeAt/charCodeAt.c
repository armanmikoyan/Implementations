#include <stdio.h>
#include <string.h>

int charCodeAt(const char* str, int index)
{
 
  printf("%d \n", (int)str[index]);
  return (int)str[index];

}

int main()
{
const  char* str = "hello world";
  int index = 5;
  int result = charCodeAt(str, index);
  return 0;
}
