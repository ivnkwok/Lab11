#include "header.h"

Employee readEmployee(FILE* infile) {
	Employee emp = { 0 };
	char temp[100];
	fgets(emp.name, 100, infile);
	fscanf(infile, " %c", &emp.title);
	fscanf(infile, "%lf", &emp.hours_worked);
	fscanf(infile, "%lf", &emp.payrate);
	fgets(temp, 100, infile);
	emp.payment = calcPayment(emp);
	
	return emp;
}

double calcPayment(Employee emp) {
	double hours = emp.hours_worked;
	double payrate = emp.payrate;
	double payment = 0;

	if (hours >= 80) {
		payment += 80 * payrate;
		hours -= 80;
		if (emp.title == 'B') {
			payment += hours * (1.5 * payrate);
			}
		else {
			payment += hours * (1.8 * payrate);
		}
	}
	else {
		payment += hours * payrate;
	}

	return payment;
}

void output(Employee payroll[200], FILE* outfile) {
	double payment = payroll[0].payment;
	double total = 0;
	double avg = 0;
	double min = payment;
	double max = payment;
	
	int i = 0;

	while (payroll[i].title == 'B' || payroll[i].title == 'M') {
		payment = payroll[i].payment;
		total += payment;
		if (min > payment) {
			min = payment;
		}
		if (max < payment) {
			max = payment;
		}
		i++;
	}
	avg = total / i;

	fprintf(outfile, "Total: $%.2lf\n", total);
	fprintf(outfile, "Average: $%.2lf\n", avg);
	fprintf(outfile, "Max: $%.2lf\n", max);
	fprintf(outfile, "Min: $%.2lf\n", min);
}