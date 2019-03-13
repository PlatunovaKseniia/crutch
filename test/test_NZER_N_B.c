#include <stdio.h>
#include <stdlib.h>
#include "mathematics.h"

typedef struct {
	int result;
	NaturalNumber naturalNumber;
} Test;

int main() {

	Test tests[5] = {
		{1, {9 , NULL}},
		{0, {1 , NULL}},
		{1, {3 , NULL}},
		{1, {11, NULL}},
		{1, {1 , NULL}}
	};

	int array0[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int array2[3] = {1, 2, 3};
	int array3[1] = {0};
	int array1[1] = {1};
	int array4[11] = {1, 2, 3, 0, 0, 0, 0, 2, 3, 2, 1};
	tests[0].naturalNumber.numbers = array0;
	tests[1].naturalNumber.numbers = array3;
	tests[2].naturalNumber.numbers = array2;
	tests[3].naturalNumber.numbers = array4;
	tests[4].naturalNumber.numbers = array1;

	int flag = 1, i, g;

	for (i = 0; i < 5 && flag; i++) {
		if ((g = NZER_N_B(&tests[i].naturalNumber)) != tests[i].result) {
			flag = 0;
		}
	}

	i--;
	if (flag) {
		printf("%s -> %s\n", "NZER_N_B", "pass");
	} else {
		printf("%s -> %s ", "NZER_N_B", "error");
		printf("in %d ", i);
		for (int j = 0; j < tests[i].naturalNumber.length; j++) {
			printf("%d", tests[i].naturalNumber.numbers[j]);
		}
		printf("-> %d\n", g);
	}

	return 0;
}
