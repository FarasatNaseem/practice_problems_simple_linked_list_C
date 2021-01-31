#include <stdio.h>
#include <stdlib.h>

/*
 
 Program: Ascending to descending & descending to ascending order a linked list.
 
 This program is written by Muhammad Farasat Hussain.

*/

// A List of one variable.
typedef struct inOrderNumber
{
    int number;
    struct inOrderNumber *next;

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

// Adding value in list
number *addNumber(number *numberList, int value)
{
    number *head = (number *)malloc(sizeof(number));

    head->number = value;

    head->next = numberList;

    return head;
}

// Getting an ascending order list.
number *getAscendingOrder(number *head)
{
    number *pointerA = head;
    number *pointerB = pointerA->next;
    number *pointerC;

    if (pointerB != NULL)
    {
        pointerC = pointerB->next;
    }

    int biggerValue;
    int smallerValue;

    if (pointerB != NULL)
    {
        while (pointerA != NULL)
        {
            while (pointerB != NULL)
            {
                if (pointerA->number < pointerB->number)
                {
                    biggerValue = pointerB->number;

                    smallerValue = pointerA->number;

                    pointerB->number = smallerValue;

                    pointerA->number = biggerValue;
                }

                if (pointerB->next != NULL)
                {
                    pointerB = pointerB->next;
                }
                else
                {
                    break;
                }
            }

            pointerA = pointerA->next;

            pointerB = pointerC;

            if (pointerC != NULL)
            {
                pointerC = pointerC->next;
            }
        }
    }

    return head;
}

// Getting a descending order list.
number *getDescendingOrder(number *head)
{
    number *pointerA = head;
    number *pointerB = pointerA->next;
    number *pointerC;

    if (pointerB != NULL)
    {
        pointerC = pointerB->next;
    }

    int biggerValue;
    int smallerValue;

    if (pointerB != NULL)
    {
        while (pointerA != NULL)
        {
            while (pointerB != NULL)
            {
                if (pointerA->number > pointerB->number)
                {
                    smallerValue = pointerB->number;

                    biggerValue = pointerA->number;

                    pointerB->number = biggerValue;

                    pointerA->number = smallerValue;
                }

                if (pointerB->next != NULL)
                {
                    pointerB = pointerB->next;
                }
                else
                {
                    break;
                }
            }

            pointerA = pointerA->next;

            pointerB = pointerC;

            if (pointerC != NULL)
            {
                pointerC = pointerC->next;
            }
        }
    }

    return head;
}

// Printing the list on console.
void printList(number *list)
{
    number *numberList = list;

    while (numberList != NULL)
    {
        printf("\n%d", numberList->number);

        numberList = numberList->next;
    }
}

number *deleteList(number *head)
{
    number *temp;

    while(head != NULL)
    {
        temp = head;
        head = head->next
        free(temp);
    }

    return head;
}

// Main function.
int main()
{
    system("cls"); // To clear the console screen.

    number *numberList = NULL; // Initializing a pointer of list.

    int value = 0; // A value, which is taken by user and inserted in list.

    int times = 0; // A list length, which is taken by user.

    times = getListLength(); 

    // Initialization of a for loop.
    for (int i = 0; i < times; i++)
    {
        value = getNumber(); 

        numberList = addNumber(numberList, value); 
    }

    numberList = getAscendingOrder(numberList); 

    printf("\nAscending order"); // Printing.

    printList(numberList); 

    printf("\n\nDescending order"); // Printing.

    numberList = getDescendingOrder(numberList); 

    printList(numberList); 

    numberList = deleteList(numberList);

    return 0;
};