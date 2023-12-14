#include <stdio.h>
#include  <string.h>
char* toLowerCase( char str[], int len) {
  int ascii_diff = 32;
  for (int i = 0; i < len; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] = str[i] + ascii_diff;
    }
  }
  return str;
}

int main() {
  char str[] = "ARMAN MIKOYAN";
  int len = strlen(str);
  printf("%s\n",toLowerCase(str,len)); 
  return 0;
}
