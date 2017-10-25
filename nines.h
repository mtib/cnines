#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct nine_result {
    double result;
    int iterations;
} nine_result_t;

int first_digit(double num, double base);
int iterate_digit(double *num, double base);
int quer_sum(double num, double base);
nine_result_t iterate_nines(double num, double base);

