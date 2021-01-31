#include <stdio.h>
#include <stdlib.h>

/*
 
 Program: Finding largest and smallest number from a linked list.
 
 This program is written by Muhammad Farasat Hussain.

*/

// A List of one variable.
typedef struct number
{
    int value;
    struct number *nextNumber;

} number;

// Getting value from user, which should be inserted in the list.
int getNumber()
{
    int value;

    printf("\nEnter a number: ");
    scanf("%d", &value);

    return value;
}

// Getting the length of list. ( But we can store infinite times in our list. ) :D
int getListLength()
{
    int length;

    printf("\nEnter list length: ");
    scanf("%d", &length);

    return length;
}

// Adding value in list.
number *addNumber(number *numberList, int value)
{
    number *head = (number *)malloc(sizeof(number));

    head->value = value;

    head->nextNumber = numberList;

    return head;
}

// Getting largest number from list.
int findLargestNumber(number *numberList)
{
    number *pointerA = numberList;
    number *pointerB;

    int largestNumber = 0;

    largestNumber = pointerA->value;

    if (pointerA != NULL)
    {
        pointerB = pointerA->nextNumber;
    }

    while (pointerB != NULL)
    {
        if (largestNumber < pointerB->value)
        {
            largestNumber = pointerB->value;
        }

        pointerB = pointerB->nextNumber;
    }

    return largestNumber;
}

// Getting smallest number from list.
int findSmallestNumber(number *numberList)
{
    number *pointerA = numberList;
    number *pointerB;

    int smallestNumber = 0;

    smallestNumber = pointerA->value;

    if (pointerA != NULL)
    {
        pointerB = pointerA->nextNumber;
    }

    while (pointerB != NULL)
    {
        if (smallestNumber > pointerB->value)
        {
            smallestNumber = pointerB->value;
        }

        pointerB = pointerB->nextNumber;
    }

    return smallestNumber;
}

number *deleteList(number *head)
{
    number *temp;

    while(head != NULL)
    {
        temp = head;
        head = head->nextNumber;
        free(temp);
    }

    return head;
}

// Main function of a class / project
int main()
{
    number *list = NULL; // Initialization.

    int value = 0; // A value, which is taken by user and inserted in list.

    int times = 0; // A list length, which is taken by user.

    times = getListLength(); // Initialization.

    // Initialization of a for loop.
    for (int i = 0; i < times; i++)
    {
        value = getNumber(); // Initialization.

        list = addNumber(list, value); // Initialization.
    }

    int largestNumber = findLargestNumber(list);   // Initialization.
    int smallestNumber = findSmallestNumber(list); // Initialization.

    printf("\nLargest number is: %d", largestNumber);   // Printing.
    printf("\nSmallest number is: %d", smallestNumber); // Printing.

    list = deleteList(list);

    return 0;
};