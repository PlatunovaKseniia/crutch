#include "structs.h"

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
	if (wholeNumber != NULL) freeNaturalNumber(wholeNumber->naturalNumber);
}
