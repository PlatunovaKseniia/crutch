#include <stdio.h>
#include "structs.h"

typedef struct {
	const char* str;
	int lenght;
	NaturalNumber naturalNumber;
} Test;

void ungetcString(const char* str, int lenght) {
	ungetc('\n', stdin);
	for (int i = lenght - 1; i > -1; i--) {
		ungetc(str[i], stdin);
	}
}

int main() {

	Test tests[5] = {
		{"123456789"  ,  9, { 9, NULL}},
		{"00123456789", 11, { 9, NULL}},
		{"123"        ,  3, { 3, NULL}},
		{"00000"      ,  5, { 1, NULL}},
		{"12300002321", 11, {11, NULL}}
	};

	int array0[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int array2[3] = {1, 2, 3};
	int array3[1] = {0};
	int array4[11] = {1, 2, 3, 0, 0, 0, 0, 2, 3, 2, 1};
	tests[0].naturalNumber.numbers = array0;
	tests[1].naturalNumber.numbers = array0;
	tests[2].naturalNumber.numbers = array2;
	tests[3].naturalNumber.numbers = array3;
	tests[4].naturalNumber.numbers = array4;

	int flag = 1, i;

	NaturalNumber* naturalNumber;
	for (i = 0; i < 5 && flag; i++) {
		ungetcString(tests[i].str, tests[i].lenght);
		naturalNumber = readNaturalNumber();
		if (naturalNumber->lenght == tests[i].naturalNumber.lenght) {
			for (int j = 0; j < naturalNumber->lenght && flag; j++) {
				if (naturalNumber->numbers[j] != tests[i].naturalNumber.numbers[j]) {
					flag = 0;
				}
			}
		} else {
			flag = 0;
		}
	}

	i--;
	if (flag) {
		printf("%s -> %s\n", "readNaturalNumber", "pass");
	} else {
		printf("%s -> %s ", "readNaturalNumber", "error");
		printf("in %d: %s -> ", i, tests[i].str);
		printf("%s: %d, %s: ", "lenght", naturalNumber->lenght, "numbers");
		for (int j = 0; j < naturalNumber->lenght; j++) {
			printf("%d", naturalNumber->numbers[j]);
		}
		puts("");
	}

	return 0;
}
