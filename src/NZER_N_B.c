#include "NZER_N_B.h"

//Панарин Александр
//Фуекция проврки на ноль
//Функция вернёт 1,если число не равно нулю, ионаче 0
int NZER_N_B(NaturalNumber* digit)
{
    return !(digit->lenght == 1 && digit->numbers[0] == 0);
}
