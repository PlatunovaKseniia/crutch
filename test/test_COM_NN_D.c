#include <stdio.h>
#include "mathematics.h"

typedef struct {
	int result;
	NaturalNumber in1;
	NaturalNumber in2;
} Test;

int main() {

	Test tests[5] = {
		{2, {2, NULL}, {2, NULL}},
		{2, {2, NULL}, {1, NULL}},
		{1, {3, NULL}, {3, NULL}},
		{1, {2, NULL}, {3, NULL}},
		{0, {1, NULL}, {1, NULL}}
	};

	int array01[2] = {1, 2};
	int array02[2] = {1, 1};
	tests[0].in1.numbers = array01;
	tests[0].in2.numbers = array02;

	int array11[2] = {1, 2};
	int array12[1] = {0};
	tests[1].in1.numbers = array11;
	tests[1].in2.numbers = array12;

	int array21[3] = {1, 2, 2};
	int array22[3] = {1, 2, 8};
	tests[2].in1.numbers = array21;
	tests[2].in2.numbers = array22;

	int array31[2] = {1, 2};
	int array32[3] = {1, 2, 9};
	tests[3].in1.numbers = array31;
	tests[3].in2.numbers = array32;

	int array41[1] = {0};
	int array42[1] = {0};
	tests[4].in1.numbers = array41;
	tests[4].in2.numbers = array42;

	int flag = 1, i, g;

	for (i = 0; i < 5 && flag; i++) {
		if ((g = COM_NN_D(&tests[i].in1, &tests[i].in2)) != tests[i].result) {
			flag = 0;
		}
	}

	i--;
	if (flag) {
		printf("%s -> %s\n", "COM_NN_D", "pass");
	} else {
		printf("%s -> %s ", "COM_NN_D", "error");
		printf("in %d: ", i);
		for (int j = 0; j < tests[i].in1.length; j++) {
			printf("%d", tests[i].in1.numbers[j]);
		}
		if (g == 0) {
			printf(" == ");
		} else if (g == 1) {
			printf(" < ");
		} else {
			printf(" > ");
		}
		for (int j = 0; j < tests[i].in2.length; j++) {
			printf("%d", tests[i].in2.numbers[j]);
		}
		puts("");
	}

	return 0;
}
