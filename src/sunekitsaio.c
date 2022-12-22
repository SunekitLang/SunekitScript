#include "sunekits.h"
#include <regex.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int sune_SizeofExpArray(const char*** arr) {
	int out = 0;
	if (*arr[0] == "5") {
		return 0;
	}
	/*for (int i = 0; *arr[i] != "\0"; i++) {
		//printf(*arr[i]);
		//out += strlen(*arr[i]);
	}
	return out;*/
}

char* out[256];
void sune_StringToExpArray(char*** array, const char* str) {
	regex_t regex;
	if (regcomp(&regex, "[\\ +\\-*^/()<>=!]", 0)) {
		printf("regcomp failed");
		exit(1);
	}
	int first_empty_entry = 0;
	char* buffer = "";
	int skip_add = 0;
	for (int i = 0; i < strlen(str) - 1; i++) {
		if (!skip_add) {
			char charstr[2] = "\0";
			charstr[0] = str[i];
			buffer = strcat(buffer, charstr);
			skip_add = 0;
		}
		char charstr[2] = "\0";
		charstr[0] = str[i + 1];
		if (!regexec(&regex, charstr, 0, NULL, 0)) {
			out[first_empty_entry] = buffer;
			out[first_empty_entry + 1] = charstr;
			buffer = "";
			first_empty_entry += 2;
			skip_add = 1;
		}
	}
	out[first_empty_entry] = buffer;
	out[first_empty_entry + 1] = "\0";
	memcpy(array, &out, sune_SizeofExpArray((const char***)&out));
}