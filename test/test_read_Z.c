#include "structs.h"
#include "stdio.h"

typedef struct {
	const char* str;
	int lenght;
	WholeNumber wholeNumber;
} Test;

void ungetcString(const char* str, int lenght) {
	ungetc('\n', stdin);
	for (int i = lenght - 1; i > -1; i--) {
		ungetc(str[i], stdin);
	}
}

int main() {

	Test tests[5] = {
		{"-123456789"  , 10, {-1, NULL}},
		{"00123456789" , 11, { 1, NULL}},
		{"-123"        ,  4, {-1, NULL}},
		{"00000"       ,  5, { 1, NULL}},
		{"-12300002321", 12, {-1, NULL}}
	};

	int array0[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int array2[3] = {1, 2, 3};
	int array3[1] = {0};
	int array4[11] = {1, 2, 3, 0, 0, 0, 0, 2, 3, 2, 1};

	NaturalNumber naturalNumber0 = {9 , array0};
	NaturalNumber naturalNumber1 = {9 , array0};
	NaturalNumber naturalNumber2 = {3 , array2};
	NaturalNumber naturalNumber3 = {1 , array3};
	NaturalNumber naturalNumber4 = {11, array4};

	tests[0].wholeNumber.naturalNumber = &naturalNumber0;
	tests[1].wholeNumber.naturalNumber = &naturalNumber1;
	tests[2].wholeNumber.naturalNumber = &naturalNumber2;
	tests[3].wholeNumber.naturalNumber = &naturalNumber3;
	tests[4].wholeNumber.naturalNumber = &naturalNumber4;

	int flag = 1, i;

	WholeNumber* wholeNumber;
	for (i = 0; i < 5 && flag; i++) {
		ungetcString(tests[i].str, tests[i].lenght);
		wholeNumber = readWholeNumber();
		if (wholeNumber->sign == tests[i].wholeNumber.sign &&
			wholeNumber->naturalNumber->lenght == tests[i].wholeNumber.naturalNumber->lenght) {
			for (int j = 0; j < wholeNumber->naturalNumber->lenght && flag; j++) {
				if (wholeNumber->naturalNumber->numbers[j] != tests[i].wholeNumber.naturalNumber->numbers[j]) {
					flag = 0;
				}
			}
		} else {
			flag = 0;
		}
	}

	i--;
	if (flag) {
		printf("%s -> %s\n", "readWholeNumber", "pass");
	} else {
		printf("%s -> %s ", "readWholeNumber", "error");
		printf("in %d:, %s -> ", i , tests[i].str);
		printf("%s: %d, %s: %d, %s: ", "sign", wholeNumber->sign, "lenght", wholeNumber->naturalNumber->lenght, "numbers");
		for (int j = 0; j <  wholeNumber->naturalNumber->lenght; j++) {
			printf("%d",  wholeNumber->naturalNumber->numbers[j]);
		}
		puts("");
	}

	return 0;
}
