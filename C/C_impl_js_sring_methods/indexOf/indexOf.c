#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int includes(const char* str, const char* target) {
    int strLen = strlen(str);
    int targetLen = strlen(target);

    for (int i = 0; i <= strLen - targetLen; ++i) {
        int count = 0;
        for (int j = 0; j < targetLen; ++j) {
            if (str[j + i] == target[j]) {
                count++;
                if (count == targetLen) {
                    return i;
                }
            }
        }
    }

    return -1;
}

int main() {
    const char* str = "hello world";
    const char* target = "orld";
    int result = includes(str, target);
    printf("%d\n", result);

    return 0;
}

