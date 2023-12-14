#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *concat(const char *str1, const char *str2, const char symbol)
{
  char *concated_arr = (char*) malloc(strlen(str1) + strlen(str2) + 1);
  char *tmp = concated_arr;
  while (*str1)
  {
    *tmp = *str1;
    tmp++;
    str1++;
  }

  *tmp = symbol;
  tmp++;
  while (*str2)
  {
    *tmp = *str2;
    tmp++;
    str2++;
  }

  return concated_arr;
}

int main()
{
  const char *str1 = "hello";
  const char *str2 = "world";
  const char symbol = '_';
  const char *result = concat(str1, str2, symbol);
  printf("%s\n", result);
  return 0;
}
