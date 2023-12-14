#include <stdio.h>
#include <string.h>

char at(char str[], int index)
{
  int size = strlen(str) - 1;
  if (index < 0)
  {
    int tmp = ~index + 1;

    printf("%c \n", str[size - tmp + 1]);
    return str[size - tmp];
  }

  printf("%c \n", str[index]);
  return str[index];

}

int main()
{
  char str[] = "hello world";
  int index = -1;
  int result = at(str, index);
  return 0;
}
