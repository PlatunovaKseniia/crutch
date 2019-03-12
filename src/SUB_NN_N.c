#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

//Зайков Дмитрий
//Функция для Вычитания из первого большего
//натурального числа второго меньшего или равного
//Возвращает укзатель на натуральное число 
//или NULL, если произошла ошибка

NaturalNumber* SUB_NN_N(NaturalNumber *first, NaturalNumber *second)
{
    int b, // переменная, отвечающая за сравнение двух чисел
        n, // количество цифр в результате
        m, // Дополнительная перменная для занятия разряда
        i;  //Счетчик цикла
    NaturalNumber *result = NULL;

    //Сравниваются два исходных числа
    b = COM_NN_D(first, second);

    if(b == 2)
        n = first->lenght;
    if(b == 1)
        n = second->lenght;
    if(b == 0)
        n = 1;
    
    //Выделение памяти
    result = (NaturalNumber*)malloc(sizeof(NaturalNumber));
    result->numbers = (int*)malloc(n * sizeof(int));

    if(result != NULL && result->numbers != NULL )
    {
        m = 0;
        //Если первое больше второго
        if(b == 2)
        {
            for (i = n - 1; i >= 0; i--)
            {   
                if(m == 1)//Если разряд был занят
                {
                    if(first->numbers[i] - 1 < second->numbers[i])
                        result->numbers[i] = first->numbers[i] - second->numbers[i] + 9;
                    else
                    {
                        result ->numbers[i] = first->numbers[i] - second->numbers[i] - 1;
                        m = 0;
                    }
                }
                else
                {
                    if (first->numbers[i]< second->numbers[i])
                    {       
                            result->numbers[i] = first->numbers[i] - second->numbers[i] + 10;
                            m = 1;
                    }
                    else
                        result->numbers[i] = first->numbers[i] - second->numbers[i];
                } 
            }
        }
        //Если второе больше первого
        if( b == 1)
        {
            for (i = n - 1; i >=0; i--)
            {
                if(m == 1)
                {
                    if(second->numbers[i] - 1 < first->numbers[i])
                        result->numbers[i] = second->numbers[i] - first->numbers[i] + 9;
                    else
                    {
                        result ->numbers[i] = second->numbers[i] - first->numbers[i] - 1;
                        m = 0;
                    }
                }
                else
                {
                    if (second->numbers[i] < first->numbers[i])
                    {
                            result->numbers[i] = second->numbers[i] - first->numbers[i] + 10;
                            m = 1;
                    }
                    else
                        result->numbers[i] = second->numbers[i] - first->numbers[i];
                } 
                
            }
        }
        //Если они равны
        if(b == 0)
        {
            result->lenght = 1;
            result->numbers[0] = 0;
        }
        else
            result->lenght = n;
    }
    else
        puts("memory error!");
    
    return result;
}
