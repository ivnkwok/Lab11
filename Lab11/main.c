#include "header.h"

int main(void) {
	FILE* infile = fopen("payroll.txt", "r");
	FILE* outfile = fopen("paid.txt", "w");
	Employee payroll[200];

	int i = 0;
	while (!feof(infile)) {
		payroll[i] = readEmployee(infile);
		i++;
	}

	output(payroll, outfile);

	fclose(infile);
	fclose(outfile);
	return 0;
}