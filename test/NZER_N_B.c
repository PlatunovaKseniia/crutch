#include "NZER_N_B.h"

//Панарин Александр
//Функция проврки на ноль
//Функция вернёт 1,если число не равно нулю, ионаче 0
int NZER_N_B(NaturalNumber* digit)
{
    return !(digit->length == 1 && digit->numbers[0] == 0);
}
