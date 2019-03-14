#include "mathematics.h"

//Панарин Александр
//функция умножения двух натуральных чисел
//функция возвращает указатель на натуральное число
//в случае ошибки возвращается NULL
NaturalNumber* MUL_NN_N(NaturalNumber* first, NaturalNumber* second)
{
    int k=0, //степень десятки
        i;  //счётчик цикла
    NaturalNumber* result=NULL;  //результат
    NaturalNumber* a=NULL;  //промежуточная структура для вычисления результата

    //инициализация результата, как ноль
    result=(NaturalNumber*)malloc(sizeof(NaturalNumber));
    result->numbers=(int*)malloc(sizeof(int));
    result->numbers[0]=0;
    result->length=1;

    if(result!=NULL)
        for(i=0;i<second->length;i++)
        {
            a=MUL_ND_N(first, second->numbers[i]);
            a=MUL_Nk_N(a,k);
            result=ADD_NN_N(result,a);
            k++;
            FREE_N(&a);
        }

    return result;
}
