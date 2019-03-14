#include "structs.h"

//Сендеркина Арина
//Функция умножения целого на (-1)
//функция возвращает указатель на целое число или NULL

WholeNumber *MUL_ZM_Z(WholeNumber *digit)
{
    int i;
    WholeNumber *result=(WholeNumber*)malloc(sizeof(WholeNumber));
    if(result!=NULL)
    {
        result->naturalNumber=(NaturalNumber*)malloc(sizeof(NaturalNumber));
        result->naturalNumber->number = (int*)malloc(digit->naturalNumber->length*sizeof(int));
        if(result->naturalNumber!=NULL && result->naturalNumber->numbers != NULL)
        {
            result->sign=digit->sign;
            for(i=0;i<result->naturalNumber->length;i++)
                result->naturalNumber->numbers[i]=digit->naturalNumber->numbers[i];
            //изменение значения поля знака
            //на противоположный знак(число не ноль)
            if(result->sign==2)
               result->sign=1;
            else if(result->sign==1)
                    result->sign=2;
        }
    }
    return result;
}
