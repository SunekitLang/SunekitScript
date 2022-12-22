#pragma once
#ifndef SUNE_TEST_SUITE
#define SUNE_TEST_SUITE
#include <stdio.h>

typedef struct {
	const char* name;
	void (*func)();
} sune_Test;

sune_Test sune_NewTest(const char* test_name, void (*f)()) {
	sune_Test out;
	out.name = test_name;
	out.func = f;
	return out;
}

void sune_RunTest(sune_Test* test) {
	printf("%s....  ", test->name);
	(test->func)();
	printf("\033[0;32mok\033[0m\n");
}

#endif // SUNE_TEST_SUITE