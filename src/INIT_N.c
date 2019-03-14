#include "mathematics.h"

// Панарин Александр
// функция создания натурального числа с заданной длиной
// функция возвращает указатель на натуральное число
// в случае ошибки функция вернёт NULL
NaturalNumber* INIT_N(usigned int len)
{
    NaturalNumber* new_digit = NULL;

    if((new_digit=(NaturalNumber*)malloc(sizeof(NaturalNumber))) != NULL)
    {
        if((new_digit->numbers=(int*)malloc(len*sizeof(int))) != NULL)
            new_digit->length=len;
        else
            FREE_N(& new_digit);
    }

    return new_digit;
}
