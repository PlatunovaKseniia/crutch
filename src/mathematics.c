#include "mathematics.h"

// Илья Баталев
// Функция, возращает соотношение чисел
// Возвращает:
// 2 - первое больше
// 1 - второе больше
// 0 - они равны
int COM_NN_D(NaturalNumber* first, NaturalNumber* second) {
	int result = 0;
	if (first->length > second->length)      result = 2;
	else if (second->length > first->length) result = 1;
	else
		for (int i = first->length - 1; i >= 0 && !result; i--) {
			if (first->numbers[i] > second->numbers[i])
				result = 2;
			else if (second->numbers[i] > first->numbers[i])
				result = 1;
			else
				result = 0;
		}
	return result;
}

// Илья Баталев
// Функция, находящая разность двух чисел
// Возвращает указатель на натуральное число
// Или NULL, если произошла ошибка
NaturalNumber* SUB_NN_N(NaturalNumber* first, NaturalNumber* second) {
	NaturalNumber* naturalNumber = NULL;
	if (COM_NN_D(first, second) == 2) { // если первое число больше второго
		naturalNumber = (NaturalNumber*)malloc(sizeof(NaturalNumber));
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
		naturalNumber->length = length;
		naturalNumber->numbers = (int*)malloc(sizeof(int) * length);
		for (int i = length - 1; i >= 0; i--) {
			naturalNumber->numbers[i] = array[length - 1 - i];
		}
		free(array);
	}

	return naturalNumber;
}

// Илья Баталев
// Функция, считывающая натуральное число
// Возвращает указатель на натуральное число
// Или NULL, если произошла ошибка
NaturalNumber* readNaturalNumber() {
	NaturalNumber* naturalNumber = (NaturalNumber*)malloc(sizeof(NaturalNumber));
	naturalNumber->numbers = NULL;
	naturalNumber->length  = 0;
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
			freeNaturalNumber(naturalNumber);
			naturalNumber = NULL;
			break;
		}
	}

	return naturalNumber;
}

// Илья Баталев
// Функция освобождает память из под натурального числа
void freeNaturalNumber(NaturalNumber* naturalNumber) {
	if (naturalNumber != NULL) {
		if (naturalNumber->numbers != NULL)
			free(naturalNumber->numbers);
		free(naturalNumber);
	}
}

// Илья Баталев
// Функция, считывающая целое число
// Возвращает указатель на целое число
// Или NULL, если произошла ошибка
WholeNumber* readWholeNumber() {
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
	if ((wholeNumber->naturalNumber = readNaturalNumber()) == NULL) {
		freeWholeNumber(wholeNumber);
		wholeNumber = NULL;
	} else if (wholeNumber->naturalNumber->length == 1 && wholeNumber->naturalNumber->numbers[0] == 0) {
		wholeNumber->sign = 0;
	}

	return wholeNumber;
}

// Илья Баталев
// Функция освобождает память из под целого числа
void freeWholeNumber(WholeNumber* wholeNumber) {
	if (wholeNumber != NULL) {
			if (wholeNumber->naturalNumber != NULL)
				freeNaturalNumber(wholeNumber->naturalNumber);
		free(wholeNumber);
	}
}
