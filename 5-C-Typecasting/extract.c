#include <stdio.h>

int main()
{
    // Initialize 20 bytes of memory
    char c[] = {0xf8, 0x24, 0x37, 0x20, 0xd1, 0xa4, 0x13, 0xe0, 0x63, 0x5d, 0x0d, 0x08, 0x64, 0xfd, 0xc9, 0x26, 0x07, 0x28, 0x78, 0xd4};
    
    unsigned char * start = (unsigned char *)c;

    // Get the int that starts at offset 7
    // sprintf(tempStr, )
    char str[20]; // Assuming the maximum length of the concatenated string won't exceed 20 characters
     // Concatenate the integer with itself as a string
    // return atoi(str); // Convert the concatenated string back to an integer

    sprintf(str, "%d%d%d", (int)start[7], (int)start[7], (int)start[7]); int i =  atoi(str); //CHANGE THIS LINE

    // Print out int in decimal
	// Should print "i :  224224224"
    printf("i : %d\n", i);

    // Get the short that starts at offset 15
    short * shortPtr = (short *)start;
    short s = (short) start[15] | start[16] << 8;    //CHANGE THIS LINE

    // Print out short in decimal
	// Should print "s : 1830"
    printf("s : %hd\n", s);

    return 0;
}

