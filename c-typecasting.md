# Lab 5 - Typecasting in C

This lab will give you practice typecasting pointers and working with memory in different ways. 
This lab is intended to prepare you to succesfully complete project 2. 

## Typecasting and Extracting Values from Memory

Typecasting, as we have covered in class, is the process of changing the type of a pointer, or in other words, creating a new pointer with some specific address of whatever type we desire. 

This new pointer can be used to interpret certain bytes in memory in some specific way.  For example, in project 2, you are given a pointer to the beginning of a huge chunk of memory, the contents of which are the bytes that encode an image that was input to the program. 
The first portion of the file contains header information, which is a mixture of different kind of information, each stored in the bytes of the file.  One of your first tasks with project 1 will be to determine, from the provided details about the header file, where certain values are stored in the bytes of the header. 
By *where* we mean the number of bytes from the beginning of the file, or in other words the number of bytes that must be added to the pointer you are given pointing to the first address of the file to get to the bytes storing the specific value you want.  

Once you know where in the header these are stored, the next task is to extract the relevant bytes from memory, interpreted as the correct type.  That is what the first part of this lab will focus on. 

Your first task is to work with the following code.
This code first initializes 20 bytes of memory using a `char` array. 
We then get an `unsigned char *` pointer `start` which points to the beginning of the array, just like you will have an `unsigned char *` pointer to the beginning of the bytes of your image file in project 2 (the pointer is called `bmpFileAsBytes`). 

Your task is to extract two values from these 20 bytes of memory, as follows. 
1) An `int` from the 4 bytes of memory that start at byte 7 from `start`. 
2) A `short` from the 2 bytes of memory that start at byte 15. 

For each of these you only need to change one line of code, indicated in the starter code below. 
You should only reference `start` in your line of code.
The code then prints out the `int` and `short` values that you extracted as decimal numbers.  

To pass off this portion of the lab, show your TA the two decimal numbers that got printed out.  If they are correct, then you are done. 

```c
#include <stdio.h>

int main()
{
    //Initialize 20 bytes of memory
    char c[] = {0xf8, 0x24, 0x37, 0x20, 0xd1, 0xa4, 0x13, 0xe0, 0x63, 0x5d, 0x0d, 0x08, 0x64, 0xfd, 0xc9, 0x26, 0x07, 0x28, 0x78, 0xd4};
    
    unsigned char * start = (unsigned char *)c;

    //Get the int that starts at byte 7
    int i = 0; //CHANGE THIS LINE

    //Print out int in decimal
    printf("i : %d\n", i);

    //Get the short that starts at byte 15
    short s = 0;    //CHANGE THIS LINE
    //Print out short in decimal
    printf("s: %d\n", s);

    return 0;
}
```

## Padding in the pixel array

As the project description specifies, in the array of pixels you will encounter during the project, each row of pixels in our 2-D array must have a size (in bytes) that is a multiple of 4. 
Since each pixel takes up 3 bytes of memory, sometimes there is some *padding*, or unused memory, that is skipped over before the bytes of the next row of pixels starts. 

In this part of the lab you will determine how to compute the number of padding bytes correctly. 
This will be useful for you as you more forward on the project. 

You are told the number of pixels in each row (`width` of the image).  
You know that each pixel takes up 3 bytes. 
Your task, compute how many bytes must be skipped over at the end of each row before the next row of pixels can start at a multiple of 4.

The code provided below will test your computation and let you know if it works correctly. 

To pass off this part of the lab, you simply need to show your TA that you can run the following code and get no errors. 

```c
#include <stdio.h>

int getPadding(int width)
{
    //COMPUTE THE PADDING HERE AND RETURN IT
    return 0; //CHANGE THIS LINE
}

int main()
{
    //The test widths
    int w[] = {20, 400, 273, 750, 1200, 6, 7, 8};
    //The correct paddings
    int p[] = {0, 0, 1, 2, 0, 2, 3, 0};

    int examples = 8;
    int numberWrong = 0;

    for(int i=0; i<examples; i++){
        int padding = getPadding(w[i]);
        if(padding != p[i]){
            numberWrong += 1;
            printf(" Incorrect for width %d\n Correct padding : %d\n You computed: %d\n", w[i], p[i], padding);
        }
    }

    if(numberWrong){
        printf("Your solution is incorrect.  You missed %d of %d\n", numberWrong, examples);
    }
    else{
        printf("Congratulations, you got them all correct!\n");
    }

    return 0;
}
```

## Starter Code Organization

Look through the starter code and understand how it is organized.  
Which function(s) do you need to call from each other function? 