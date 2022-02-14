#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE_BUF_LENGTH 5
#define INT_BUF_LENGTH 100
#define STRING_OUT_BUF_LENGTH 100

int getBase() {
	char baseBuf[BASE_BUF_LENGTH];
	fgets(baseBuf, BASE_BUF_LENGTH, stdin);
	int base = atoi(baseBuf);
	if(base <= 0) {
		printf("Invalid base\n");
		exit(1);
	}
	return atoi(baseBuf);
}

int getInBase() {
	printf("Input Base: ");
	return getBase();
}

int getOutBase() {
	printf("Output Base: ");
	return getBase();
}

char *getInputNumString() {
	char *intBuf = malloc(INT_BUF_LENGTH);
	printf("Number: ");
	fgets(intBuf, INT_BUF_LENGTH, stdin);
	// Check if input is valid
	if(intBuf[0] == '0') {
		return intBuf;
	}
	if(atoi(intBuf) == 0) {
		printf("Invalid number input\n");
		exit(1);
	}
	return intBuf;
}

int getInputValue(int base, char *intBuf) {
	int num = 0;
	int multiplier = 1;
	int length = strlen(intBuf) - 1; // account for newline
	for(int i = length - 1; i >= 0; --i) {
		num += (intBuf[i] - '0') * multiplier;
		multiplier *= base;
	}
	return num;
}

void printIntInNewBase(int base, int n) {
	if(n == 0) {
		printf("0\n");
		return;
	}
	int bufIndex = 0;
	char output_buf[STRING_OUT_BUF_LENGTH];
	while(n > 0) {
		output_buf[bufIndex] = '0' + (n % base);
		n /= base;
		bufIndex += 1;
	}
	output_buf[bufIndex] = '\0';

	int length = strlen(output_buf);
	for(int i = length - 1; i >= 0; i--) {
		printf("%c", output_buf[i]);
	}
	printf("\n", output_buf);
}

int main() {
	int inBase = getInBase();

	char* inputNumString = getInputNumString();
	int inputValue = getInputValue(inBase, inputNumString);
	
	int outBase = getOutBase();

	printIntInNewBase(outBase, inputValue);
}
