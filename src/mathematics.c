#include "mathematics.h"

// Илья Баталев
// Функция, возращает соотношение чисел
// Возвращает:
// 2 - первое больше
// 1 - второе больше
// 0 - они равны
int COM_NN_D(NaturalNumber* first, NaturalNumber* second) {
	int result = 0;
	// Если первое число длиннее, то оно больше
	if (first->length > second->length)      result = 2;
	// Если второе число длиннее, то оно больше
	else if (second->length > first->length) result = 1;
	// Иначе сравниваем все цифры
	else
		for (int i = first->length - 1; i >= 0 && !result; i--)
			if (first->numbers[i] > second->numbers[i])
				result = 2;
			else if (second->numbers[i] > first->numbers[i])
				result = 1;
			else
				result = 0;
	return result;
}

// Панарин Александр
// Функция проврки на ноль
// Функция вернёт
// 1 - если число не равно нулю
// 0 - если число равно нулю
int NZER_N_B(NaturalNumber* number) {
    return !(number->length == 1 && number->numbers[0] == 0);
}

// Панарин Александр
// Функция возврата знака натурального числа
// 2 - положительное
// 0 — равное нулю
// 1 - отрицательное
int POZ_Z_D(WholeNumber* whole) {
    return whole->sign;
}

// Илья Баталев
// Функция, находящая разность двух чисел
// Возвращает указатель на натуральное число
// Или NULL, если произошла ошибка
NaturalNumber* SUB_NN_N(NaturalNumber* first, NaturalNumber* second) {
	NaturalNumber* naturalNumber = NULL;
	int com;
	if ((com = COM_NN_D(first, second)) == 2) { // если первое число больше второго
		int* array = (int*)malloc(sizeof(int) * first->length); // цифры числа в обратном порядке
		int length = first->length;  						    // длина массива array
		int prev   = 0;    										// является ли следующее число занятым

		// просчет всех символов числа в обратном порядке
		for (int i = 1; i <= first->length; i++) {
			array[i - 1] = first->numbers[first->length - i] - (second->length - i > -1 ? second->numbers[second->length - i] : 0) - prev;
			if (array[i - 1] >= 0) {
				prev = 0;           // не занимаем у разряда
			} else {
				array[i - 1] += 10; // занимаем у следущего разряда
				prev = 1;			// поэтому prev = 1
			}
		}

		// убераем незначащие разряды
		while (array[length - 1] == 0) length--;

		// переворачиваем массив
		naturalNumber = INIT_N(length);
		for (int i = length - 1; i >= 0; i--)
			naturalNumber->numbers[i] = array[length - 1 - i];
		free(array);
	} else if (com == 0) {
		// Создать число ноль
		naturalNumber = INIT_N(1);
		naturalNumber->numbers[0] = 0;
	}

	return naturalNumber;
}

// Илья Баталев
// Функция, считывающая натуральное число
// Возвращает указатель на натуральное число
// Или NULL, если произошла ошибка
NaturalNumber* READ_N() {
	NaturalNumber* naturalNumber = INIT_N(0);
	unsigned char c;
	int zero = 0;

	if ((c = getchar()) == '0') zero = 1;
	else ungetc(c, stdin);
	// пропускаем первые нули
	while ((c = getchar()) == '0');
	// возвращаем '\n'
	ungetc(c, stdin);
	// если ничего кроме нулей, то возвращаем 1 ноль
	if (c == '\n' && zero) ungetc('0', stdin);

	while ((c = getchar()) != '\n') {
		// если c -= 48 < 10, то это значит, что это цифра
		if ((c -= 48) < 10 && (naturalNumber->numbers = (int*)realloc(naturalNumber->numbers, sizeof(int) * ++naturalNumber->length)) != NULL) {
			naturalNumber->numbers[naturalNumber->length - 1] = c;
		} else {
			FREE_N(&naturalNumber);
			break;
		}
	}

	return naturalNumber;
}

// Илья Баталев
// Функция освобождает память из под натурального числа
void FREE_N(NaturalNumber** naturalNumber) {
	if (*naturalNumber != NULL) {
		if ((*naturalNumber)->numbers != NULL)
			free((*naturalNumber)->numbers);
		free(*naturalNumber);
		*naturalNumber = NULL;
	}
}

// Панарин Александр
// Функция создания натурального числа с заданной длиной
// Функция возвращает указатель на натуральное число
// В случае ошибки функция вернёт NULL
NaturalNumber* INIT_N(unsigned int len) {
    NaturalNumber* new_digit = NULL;

    if((new_digit = (NaturalNumber*)malloc(sizeof(NaturalNumber))) != NULL) {
        if((new_digit->numbers = (int*)malloc(len * sizeof(int))) != NULL) {
            new_digit->length = len;
        } else FREE_N(&new_digit);
    }

    return new_digit;
}

// Панарин Александр
// Функция копирования натурального числа
// Функция возвращает указатель на натуральное число
// В случае ошибки функция вернёт NULL
NaturalNumber* COPY_N(NaturalNumber* digit) {
    NaturalNumber* new_digit = NULL;

    if ((new_digit = (NaturalNumber*)malloc(sizeof(NaturalNumber))) != NULL) {
        if((new_digit->numbers = (int*)malloc((digit->length) * sizeof(int))) != NULL) {
            new_digit->length = digit->length;
            for(int i=0; i < digit->length; i++)
                new_digit->numbers[i] = digit->numbers[i];
        } else FREE_N(& new_digit);
    }

    return new_digit;
}

// Илья Баталев
// Функция, считывающая целое число
// Возвращает указатель на целое число
// Или NULL, если произошла ошибка
WholeNumber* READ_Z() {
	WholeNumber* wholeNumber = (WholeNumber*)malloc(sizeof(WholeNumber));
	wholeNumber->naturalNumber = NULL;
	unsigned char c;
	// Если первый символ '-', то чило отрицательное, иначе положитеьлное
	if ((c = getchar()) == '-') wholeNumber->sign = 1;
	else {
		wholeNumber->sign = 2;
		ungetc(c, stdin);
	}

	// Считываем оставшуюся часть
	if ((wholeNumber->naturalNumber = READ_N()) == NULL)
		FREE_Z(&wholeNumber);
	else if (wholeNumber->naturalNumber->length == 1 && wholeNumber->naturalNumber->numbers[0] == 0)
		wholeNumber->sign = 0;

	return wholeNumber;
}

// Илья Баталев
// Функция освобождает память из под целого числа
void FREE_Z(WholeNumber** wholeNumber) {
	if (*wholeNumber != NULL) {
			if ((*wholeNumber)->naturalNumber != NULL)
				FREE_N(&(*wholeNumber)->naturalNumber);
		free(*wholeNumber);
		*wholeNumber = NULL;
	}
}
