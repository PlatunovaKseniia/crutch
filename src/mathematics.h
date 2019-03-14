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
int COM_NN_D(NaturalNumber*, NaturalNumber*);

// Панарин Александр
// Функция проврки на ноль
// Функция вернёт
// 1 - если число не равно нулю
// 0 - если число равно нулю
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

// Панарин Александр
// Функция копирования натурального числа
// Функция возвращает указатель на натуральное число
// В случае ошибки функция вернёт NULL
NaturalNumber* COPY_N(NaturalNumber*);

// Панарин Александр
// Функция создания натурального числа с заданной длиной
// Функция возвращает указатель на натуральное число
// В случае ошибки функция вернёт NULL
NaturalNumber* INIT_N(unsigned int);

// Илья Баталев
// Функция, считывающая натуральное число
// Возвращает указатель на натуральное число
// Или NULL, если произошла ошибка
NaturalNumber* READ_N();

// Илья Баталев
// Функция освобождает память из под натурального числа
// И делает указатель равным NULL
void FREE_N(NaturalNumber**);

typedef struct {
	int sign;                     // знак числа
								  // 0 - ноль
								  // 1 - отрицательное
							 	  // 2 - положительное
	NaturalNumber* naturalNumber; // натуральное число
} WholeNumber;

// Илья Баталев
// Функция, считывающая целое число
// Возвращает указатель на целое число
// Или NULL, если произошла ошибка
WholeNumber* READ_Z();

// Илья Баталев
// Функция освобождает память из под целого числа
// И делает указатель равным NULL
void FREE_Z(WholeNumber**);

typedef struct {
	WholeNumber* wholeNumber;     // числитель
	NaturalNumber* naturalNumber; // знаменатель
} RationNumber;

int POZ_Z_D(WholeNumber*);

typedef struct {
	int length; 				  // степень многочлена
	RationNumber* rationNumbers;  // коэффиценты многочлена
} Multinomial;
