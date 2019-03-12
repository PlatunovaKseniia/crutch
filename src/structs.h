#pragma once

typedef struct {
	int lenght;
	int* numbers;
} NaturalNumber;

NaturalNumber* readNaturalNumber();
void freeNaturalNumber(NaturalNumber*);

typedef struct {
	int sign;
	NaturalNumber* naturalNumber;
} WholeNumber;

WholeNumber*   readWholeNumber();
void freeWholeNumber(WholeNumber*);

typedef struct {
	NaturalNumber* naturalNumber;
	WholeNumber* WholeNumber;
} RationNumber;

typedef struct {
	int lenght;
	RationNumber* rationNumbers;
} Multinomial;
