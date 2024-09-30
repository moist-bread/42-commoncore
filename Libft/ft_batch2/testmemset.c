#include <string.h>
#include <stdio.h>

#define BUF_SIZE 20

int main(void)
{
    char buffer[BUF_SIZE + 1];
    char *string;

    memset(buffer, 0, sizeof(buffer));
    string = (char *)memset(buffer, 'A', 10);
    printf("\nBuffer contents: %s\n", string);
    memset(buffer + 10, 'B', 10);
    printf("\nBuffer contents: %s\n", buffer);
}

/*******************  Output should be similar to:  ***************

Buffer contents: AAAAAAAAAA

Buffer contents: AAAAAAAAAABBBBBBBBBB
*/