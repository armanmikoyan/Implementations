#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool endsWith(const char *str, int endpos, const char *target)
{
  int size = strlen(str);
  const char *end = &str[endpos];
  const char *start = end - strlen(target);
  while (*start)
  {
    if (*start != *target)
    {
      printf("false \n");
      return false;
    }

    start++;
    target++;
  };

  printf("true\n");
  return true;
}

int main()
{
  const char *string = "hello world";
  const int endpos = 11;
  const char *target = "world";
  int res = endsWith(string, endpos, target);

  return 0;
}
