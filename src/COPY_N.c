#include "mathematics.h"

// функция копирования натурального числа
// функция возвращает указатель на натуральное число
// в случае ошибки функция вернёт NULL
NaturalNumber* COPY_N(NaturalNumber* digit)
{
    int i;
    NaturalNumber* new_digit;

    if ((new_digit=(NaturalNumber*)malloc(sizeof(NaturalNumber))) != NULL) {
        if((new_digit->numbers=(int*)malloc((digit->length)*sizeof(NaturalNumber))) != NULL)
        {
            new_digit->length=digit->length;
            for(i=0;i<(digit->length);i++)
                new_digit->numbers[i]=digit->numbers[i];
        }

    }

    return new_digit;
}
