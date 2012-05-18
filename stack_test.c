#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
	Stack strs;
	Stack ints;
	char* str = NULL;
	int val = 0;
	int i;

	stackInit(&strs);
	stackInit(&ints);

	// Test strings
	printf("Test strings:\n");

	str = "this";
	printf("Pushing \"%s\"\n", str);
	stackPush(&strs, str);
	printf("Top of stack: \"%s\"\n", (char*)stackTop(&strs));
	str = "is";
	printf("Pushing \"%s\"\n", str);
	stackPush(&strs, str);
	printf("Top of stack: \"%s\"\n", (char*)stackTop(&strs));
	str = "a";
	printf("Pushing \"%s\"\n", str);
	stackPush(&strs, str);
	printf("Top of stack: \"%s\"\n", (char*)stackTop(&strs));
	str = "stack";
	printf("Pushing \"%s\"\n", str);
	stackPush(&strs, str);
	printf("Top of stack: \"%s\"\n", (char*)stackTop(&strs));

	printf("Stack before stackPop():\n");
	for(i = stackSize(&strs) - 1; i >= 0; i--)
	{
		printf("\"%s\"\n", (char*)(strs.content[i]));
	}

	str = stackPop(&strs);
	printf("stackPop() returned \"%s\"\n", str);
	printf("Remainder of stack:\n");
	while(stackSize(&strs))
	{
		str = (char*)stackPop(&strs);
		printf("\"%s\"\n", str);
	}

	stackFree(&strs);

	// Test ints
	printf("\n\nTest ints:\n");

	for(i = 1; i <= 4; i++)
	{
		int *add = (int*)malloc(sizeof(int));
		*add = i;
		printf("Pushing %d\n", *add);
		stackPush(&ints, add);
		printf("Top of stack: %d\n", *(int*)stackTop(&ints));
	}

	printf("Stack before stackPop():\n");
	for(i = stackSize(&ints) - 1; i >= 0; i--)
	{
		printf("%d\n", *((int*)(ints.content[i])));
	}

	val = *(int*)stackPop(&ints);
	printf("stackPop() returned %d\n", val);
	printf("Remainder of stack:\n");
	while(stackSize(&ints))
	{
		int *rem = (int*)stackPop(&ints);
		val = (rem != NULL ? *rem : -1);
		printf("%d\n", val);
		free(rem);
	}

	stackFree(&ints);
}
