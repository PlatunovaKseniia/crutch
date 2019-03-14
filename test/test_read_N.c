#include <stdio.h>
#include "mathematics.h"

typedef struct {
	const char* str;
	int length;
	NaturalNumber naturalNumber;
} Test;

void ungetcString(const char* str, int length) {
	ungetc('\n', stdin);
	for (int i = length - 1; i > -1; i--) {
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
	tests[0].naturalNumber.numbers = array0;
	tests[1].naturalNumber.numbers = array0;

	int array2[3] = {1, 2, 3};
	tests[2].naturalNumber.numbers = array2;

	int array3[1] = {0};
	tests[3].naturalNumber.numbers = array3;

	int array4[11] = {1, 2, 3, 0, 0, 0, 0, 2, 3, 2, 1};
	tests[4].naturalNumber.numbers = array4;

	int flag = 1, i;

	NaturalNumber* naturalNumber;
	for (i = 0; i < 5 && flag; i++) {
		ungetcString(tests[i].str, tests[i].length);
		naturalNumber = READ_N();
		if (naturalNumber->length == tests[i].naturalNumber.length) {
			for (int j = 0; j < naturalNumber->length && flag; j++) {
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
		printf("%s -> %s\n", "READ_N", "pass");
	} else {
		printf("%s -> %s ", "READ_N", "error");
		printf("in %d: %s -> ", i, tests[i].str);
		printf("%s: %d, %s: ", "length", naturalNumber->length, "numbers");
		for (int j = 0; j < naturalNumber->length; j++) {
			printf("%d", naturalNumber->numbers[j]);
		}
		puts("");
	}

	return 0;
}
