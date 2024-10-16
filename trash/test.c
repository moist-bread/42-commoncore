#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch;

    for (ch = 126; ch <= 170; ch++)
    {
        printf("%d    ", ch);
        if (isascii(ch) != 0)
            printf("The character is %c\n", ch);
        else
            printf("Cannot be represented by an ASCII character\n");
    }
    return 0;
}
/************************************************
   The output should be:

0x7c    The character is @
0x7d    The character is '
0x7e    The character is =
0x7f    The character is "
0x80    Cannot be represented by an ASCII character
0x81    The character is a
0x82    The character is b

************************************************/
