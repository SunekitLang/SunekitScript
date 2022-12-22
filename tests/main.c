#include "testsuite.h"
#include "../src/sunekits.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void sizeof_exp_array() {
	const char control[3][2] = {"5", "2", "\0"};
	int control_len = sizeof(control);
	const char** test = (const char**)malloc(control_len);
	test[0] = "5";
	test[1] = "2";
	test[2] = "\0";
	printf("%d", sune_SizeofExpArray(&test));
	assert(sune_SizeofExpArray(&test) == control_len);
}

void fix_expression_array(void) {
	const char* source[] = {"34", "+", "1", "*", "78", "(", "124", "/", "8", ")", "-", "9", "^", "0", "<", "=", "38"};
	const char* target[] = {"34", "+", "1", "*", "78", "(124/8)", "-", "9", "^", "0", "<=", "38"};
	// assert here
}

int main() {
	sune_Test sizeof_exp_array_test = sune_NewTest("sizeof exp array", &sizeof_exp_array);
	sune_Test fix_expression_array_test = sune_NewTest("fix expression array", &fix_expression_array);
	sune_RunTest(&sizeof_exp_array_test);
	sune_RunTest(&fix_expression_array_test);
}