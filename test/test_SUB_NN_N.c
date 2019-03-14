#include <stdio.h>
#include "mathematics.h"

typedef struct {
	NaturalNumber result;
	NaturalNumber in1;
	NaturalNumber in2;
} Test;

int main() {

	Test tests[5] = {
		{{2, NULL}, {2, NULL}, {2, NULL}},
		{{1, NULL}, {2, NULL}, {1, NULL}},
		{{2, NULL}, {3, NULL}, {2, NULL}},
		{{1, NULL}, {3, NULL}, {2, NULL}},
		{{1, NULL}, {1, NULL}, {1, NULL}}
	};

	int array01[2] = {2, 3};
	int array02[2] = {1, 2};
	int array03[2] = {1, 1};
	tests[0].in1.numbers = array01;
	tests[0].in2.numbers = array02;
	tests[0].result.numbers = array03;

	int array11[2] = {1, 2};
	int array12[1] = {4};
	int array13[1] = {8};
	tests[1].in1.numbers = array11;
	tests[1].in2.numbers = array12;
	tests[1].result.numbers = array13;

	int array21[3] = {1, 2, 2};
	int array22[2] = {2, 3};
	int array23[2] = {9, 9};
	tests[2].in1.numbers = array21;
	tests[2].in2.numbers = array22;
	tests[2].result.numbers = array23;

	int array31[3] = {1, 0, 0};
	int array32[2] = {9, 9};
	int array33[1] = {1};
	tests[3].in1.numbers = array31;
	tests[3].in2.numbers = array32;
	tests[3].result.numbers = array33;

	int array41[1] = {0};
	int array42[1] = {0};
	int array43[1] = {0};
	tests[4].in1.numbers = array41;
	tests[4].in2.numbers = array42;
	tests[4].result.numbers = array43;

	int flag = 1, i;
	NaturalNumber* result;

	for (i = 0; i < 5 && flag; i++) {
		result = SUB_NN_N(&tests[i].in1, &tests[i].in2);
		if (result->length == tests[i].result.length) {
			for (int j = 0; j < result->length && flag; j++)
				if (result->numbers[j] != tests[i].result.numbers[j])
					flag = 0;
		} else {
			flag = 0;
		}
	}

	i--;
	if (flag) {
		printf("%s -> %s\n", "SUB_NN_N", "pass");
	} else {
		printf("%s -> %s ", "SUB_NN_N", "error");
		printf("in %d: ", i);
		for (int j = 0; j < tests[i].in1.length; j++) {
			printf("%d", tests[i].in1.numbers[j]);
		}
		printf(" - ");
		for (int j = 0; j < tests[i].in2.length; j++) {
			printf("%d", tests[i].in2.numbers[j]);
		}
		printf(" == ");
		for (int j = 0; j < result->length; j++) {
			printf("%d", result->numbers[j]);
		}
		puts("");
	}

	return 0;
}
