#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int length;   // длина массива цифр
	int* numbers; // массив из цифр
} NaturalNumber;

// Илья Баталев
// Функция, возращает соотношение чисел
// Возвращает:
// 2 - первое больше
// 1 - второе больше
// 0 - они равны
int COM_NN_D(NaturalNumber* a, NaturalNumber* b);

int NZER_N_B(NaturalNumber*);

NaturalNumber* ADD_1N_N(NaturalNumber*);

NaturalNumber* ADD_NN_N(NaturalNumber*, NaturalNumber*);

// Илья Баталев
// Функция, находящая разность двух чисел
// Возвращает указатель на натуральное число
// Или NULL, если произошла ошибка
NaturalNumber* SUB_NN_N(NaturalNumber*, NaturalNumber*);

NaturalNumber* MUL_ND_N(NaturalNumber*, unsigned int);

NaturalNumber* MUL_Nk_N(NaturalNumber*, unsigned int);

NaturalNumber* MUL_NN_N(NaturalNumber*, NaturalNumber*);

NaturalNumber* SUB_NDN_N(NaturalNumber*, NaturalNumber*, unsigned int);

NaturalNumber* DIV_NN_N(NaturalNumber*, NaturalNumber*);

NaturalNumber* MOD_NN_N(NaturalNumber*, NaturalNumber*);

NaturalNumber* GCF_NN_N(NaturalNumber*, NaturalNumber*);

NaturalNumber* LCM_NN_N(NaturalNumber*, NaturalNumber*);

// Илья Баталев
// Функция, считывающая натуральное число
// Возвращает указатель на натуральное число
// Или NULL, если произошла ошибка
NaturalNumber* readNaturalNumber();

// Илья Баталев
// Функция освобождает память из под натурального числа
void freeNaturalNumber(NaturalNumber*);

typedef struct {
	int sign;                     // знак числа
								  // 0 - ноль
								  // 1 - отрицательное
							 	  // 2 - положительное
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
