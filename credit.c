//  Author: Aykut Şahin
//  This program takes a credit card number as an input from the user 
//  and determines if it's a legit one or not. Also my individual way of
//  implementation of the Luhn's Algorithm.
//  Works for only three types of credit card. AMEX, VISA and MASTERCARD.

#include <stdio.h>

int main(void)
{
    unsigned long long int number;
    
    printf("Number: ");
    scanf("%llu", &number);
    
    unsigned long long int number1 = number;
    
    //  to count how many digits does the credit card number consists of -0
    
    int countdigit = 0;
    
    while (number1 != 0)
    {  
        number1 /= 10;
        countdigit++;
    }
    
    // end -0
    
    int result = 0; // to hold the final calculation's result
    int count = 0;
    int k = 0;  // to hold the leftover '1' when the 2 digits number is separated
    int b = 0;  // to hold the sum of the odd number of digits
    int c = 0;  // to hold the sum of the even number of digits
    
    int numberArray[16];        // to define an array to store each digits of
                                // the credit card number respectively    
    
    while (number != 0)
    {
        numberArray[count] = number % 10;
        
        if (count % 2 == 0)
        {
            c = c + numberArray[count];
        }
        
        else
        {
            if (numberArray[count] * 2 >= 10)
            {
                b = b + (numberArray[count] * 2) % 10;
                k++;
            }
            
            else
            {
                b = b + numberArray[count] * 2;
            }
        }
        
        number /= 10;
        count++;
    }    
    
    result = b + c + k;
    
    if (result % 10 == 0)
    {
        if (countdigit == 16 && numberArray[15] == 5 && (numberArray[14] == 1 || numberArray[14] == 2 || numberArray[14] == 3 || numberArray[14] == 4 || numberArray[14] == 5))
        {
            printf("MASTERCARD!\n");
            return 0;
        }
        
        if (countdigit == 15 && numberArray[14] == 3 && (numberArray[13] == 4 || numberArray[13] == 7))
        {
            printf("AMEX!\n");
            return 0;
        }
        
        if ((countdigit == 13 || countdigit == 14 || countdigit == 15 || countdigit == 16) && numberArray[countdigit - 1] == 4)
        {
            printf("VISA!\n");
            return 0;
        }
        
        else
        {
            printf("INAPPROPRIATE OR INVALID CARD!\n");
            return 0;
        }
    }
    
    else
    {
        printf("INVALID CARD NUMBER!\n");
        return 0;
    }
    
}