// Program that converts a decimal number to a base i number, where i is between 2 and 16.
// Nathan Dale Haskins
// HSKNAT002
// 22/08/22

#include <stdlib.h>                                 /* header that contains 'malloc()' dynamic memory allocation (on the HEAP opposed to Stack) function.
                                                    malloc(number of bytes) and sizeof(type) can be used to find the size of 'int' 'float' etc. Malloc returns
                                                    a memory address to that block of memory. */
#include <stdio.h>
#include <math.h>                                   // imported to use log2 function


// Defining Variables
#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Nathan Haskins"
#define YEAR 2022

void Dec2RadixI(int decValue, int radValue)
{
    char* array = malloc(sizeof(char) * 100);                                                       /* allocates size of 100 bytes on the Heap. Allocating space for 100 chars. 
                                                                                                    (Dynamically allocated array). Char* creates list as a pointer at some address
                                                                                                    in stack memory (Reserves Storage Block). Malloc() returns a pointer
                                                                                                    to the reserved space. */                     
    int i = 0, number, remainder = 0;                                                               // initialising variables.                                                  
    number = decValue;

    while(number > 0)                                                                               /* loop terminates when number reaches zero, which indicates completion of decimal conversion to
                                                                                                    radix base.*/                                              
    {
        remainder = number % radValue;   
        if (remainder >= 0 && remainder <= 9)    {array[i] = remainder + '0';}                      // if 0 <= rem <= 9, store simplly as ASCII value. To do this add a NULL type Dec ('0') value to rem.                        
        if (remainder >= 10 && remainder < 16)   {array[i] = remainder +'A' - 10;}                  /* converts rem value to ASCII letter {A, B, ..., F}. Note in our largest radix case,
                                                                                                    radix is 16 (Hexidecimal) which is {0,1,2 ..., 15 (F)}, whose index ends at 15. Therefore
                                                                                                    the boundard condition for rem is <16, hence 15 and NOT <= 16.*/                               
        i++;                                                                                        // increment counter.                                                   
        number = number / radValue;                                                                 // truncated division of the number divided by the radix.                                     
    }

    array[i] = '\0';                                                                                // As per the lecture slides: the last value in the char string needs to be a null character.
    int length = i;                                                                                 // length of of array, because i is at the final index of the array + 1 afer while loop.
    i = 0;
    char temp = 0;                                                                                  // initialise a temporary variable.
    
    while(i < length / 2)                                                                           // The following swops the characters in the array. 
    {
        temp = array[i];                                                                            // sets element at index i (initially zero) in the array to the temporary variable.
        array[i] = array[length - i- 1];                                                            // sets element i to the value at the element at the end of the array.
        array[length - i- 1] = temp;                                                                // sets the last element to the value of the temporary variable.
        i++;                                                                                        // increment i so as to swap all the interior characters in the array.
    }
    printf("\nThe radix-2 value is %s", array);                                                     /* Void function has no return type, however the final line with the radix answer
                                                                                                    is printed once the Dec2RadixI() function is called in the main() function.*/ 
}

int main()
{
    int num = 0, radix = 0, result = 0, rem = 0;                                                   // Initialising variables.       

    printf("*****************************");
    printf("\n %s", TITLE); 
    printf("\n Written by: %s", AUTHOR);                  
    printf("\n Date: %d", YEAR);                         
    printf("\n*****************************");
    
    while (num >= 0)
    {
        printf("\nEnter a decimal number: ");
        scanf("%d", &num);
        if (num < 0) {break;}                                                                      // Terminates program if decimal input is smaller than zero.
        printf("The number you have entered is %d", num);
        printf("\nEnter a radix for the converter between 2 and 16: ");
        scanf("%d", &radix);
        printf("The radix you have entered is %d", radix); 
        printf("\nThe Log2 of the number is %.2f", log2(num));

        result = num / radix;                                                                     
        rem = num % radix;

        printf("\nThe integer result of the number divided by %d is %d", radix, result);
        printf("\nThe remainder is %d", rem);
        
        if (num != 0) {Dec2RadixI(num, radix);}                                                     // Condition to consider if zero is inputted into the programme.  
        else {char ans = '0'; printf("\nThe radix-2 value is %c", ans);}   
    }
    printf("EXIT");  
} 

    



    
