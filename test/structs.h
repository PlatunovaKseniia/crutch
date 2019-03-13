#pragma once

typedef struct {
	int lenght;
	int* numbers;
} NaturalNumber;

typedef struct {
	int sign;
	NaturalNumber naturalNumber;
} WholeNumber;

typedef struct {
	NaturalNumber naturalNumber;
	WholeNumber WholeNumber;
} RationNumber;

typedef struct {
	int lenght;
	RationNumber* rationNumbers;
} Multinomial;
