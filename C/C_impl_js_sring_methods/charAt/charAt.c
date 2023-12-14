#include <stdio.h>
#include <string.h>

char charAt(char str[], int index)
{

  printf("%c \n", str[index]);
  return str[index];

}

int main()
{
  char str[] = "hello world";
  int index = 1;
  int result = charAt(str, index);
  return 0;
}
