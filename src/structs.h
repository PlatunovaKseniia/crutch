#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int length;   // длина массива цифр
	int* numbers; // массив из цифр
} NaturalNumber;

NaturalNumber* readNaturalNumber();
void freeNaturalNumber(NaturalNumber*);

typedef struct {
	// знак числа
	// 0 - ноль
	// 1 - отрицательное
	// 2 - положительное
	int sign;
	NaturalNumber* naturalNumber; // натуральное число
} WholeNumber;

WholeNumber*   readWholeNumber();
void freeWholeNumber(WholeNumber*);

typedef struct {
	WholeNumber* wholeNumber;     // числитель
	NaturalNumber* naturalNumber; // знаменатель
} RationNumber;

typedef struct {
	int length; 				  // степень многочлена
	RationNumber* rationNumbers;  // коэффиценты многочлена
} Multinomial;
