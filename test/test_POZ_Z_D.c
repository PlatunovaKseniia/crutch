#include <stdlib.h>
#include "mathematics.h"

typedef struct {
	int result;
	WholeNumber whole;
} Test;

int main() {

	Test tests[5] = {
		{0, {0 , NULL}},
		{1, {1 , NULL}},
		{2, {2 , NULL}},
		{0, {0, NULL}},
		{1, {1 , NULL}}
	};


	tests[0].whole.sign = 0;
	tests[1].whole.sign = 1;
	tests[2].whole.sign = 2;
	tests[3].whole.sign = 0;
	tests[4].whole.sign = 1;

	int flag = 1, i, g;

	for (i = 0; i < 5 && flag; i++) {
		if ((g = POZ_Z_D(&tests[i].whole)) != tests[i].result) {
			flag = 0;
		}
	}

	i--;
	if (flag) {
		printf("%s -> %s\n", "POZ_Z_D", "pass");
	} else {
		printf("%s -> %s ", "POZ_Z_D", "error");
		printf("in %d ", i);
		printf("-> %d\n", g);
	}

	return 0;
}
