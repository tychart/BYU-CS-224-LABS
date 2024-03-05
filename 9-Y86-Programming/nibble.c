#include <stdio.h>

int main()
{
    //Initialize our byte
    unsigned char c = 0xab;

    //Extract the first nibble (least significant, or b)
    unsigned char firstNibble = c & 0x0f; //CHANGE THIS LINE
    

    //Extract the second nibble (most significant, or a)
    unsigned char secondNibble = (c >> 4) & 0xf ; //CHANGE THIS LINE

    //Print out each in hex to ensure correctness
    printf("First nibble : %x\n", firstNibble);
    printf("Second nibble: %x\n", secondNibble);
    //If each matches what it should be above, good work!

    return 0;
}

