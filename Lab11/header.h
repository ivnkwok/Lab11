#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee {
	char name[100];
	char title;
	double hours_worked;
	double payrate;
	double payment;
} Employee;

Employee readEmployee(FILE* infile);
double calcPayment(Employee emp);
void output(Employee payroll[200], FILE* outfile);