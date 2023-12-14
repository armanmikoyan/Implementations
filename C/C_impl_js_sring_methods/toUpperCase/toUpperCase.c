#include <stdio.h>
#include  <string.h>
char* toUpperCase( char str[], int len) {
  int ascii_diff = 32;
  for (int i = 0; i < len; i++) {
    if (str[i] > 96 && str[i] < 122) {
      str[i] = str[i] - ascii_diff;
    }
  }
  return str;
}

int main() {
  char str[] = "Arman Mikoyan";
  int len = strlen(str);
  printf("%s\n",toUpperCase(str,len)); 
  return 0;
}

