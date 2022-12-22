#pragma once
#ifndef SUNEKIT_SCRIPT_LANG

typedef enum {
	SUNE_VOID,
	SUNE_INT,
	SUNE_FLOAT,
	SUNE_DOUBLE,
	SUNE_CHAR,
	SUNE_STRING
} sune_Type;

typedef struct {
	int id;
	const char* name;
	sune_Type type;
	void* value;
} sune_Variable;

typedef struct {

} sune_State;

int sune_SizeofExpArray(const char*** arr);

void sune_StringToExpArray(char*** array, const char* str);

#define SUNEKIT_SCRIPT_LANG
#endif // SUNEKIT_SCRIPT_LANG