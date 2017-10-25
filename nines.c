#include "nines.h"

int first_digit(double num, double base) {
    double n = log(num)/log(base);
    return (int) floor(pow(base, n - floor(n)));
}

int iterate_digit(double *num, double base) {
    int fd = first_digit(*num, base);
    *num = *num - fd * pow(base, floor(log(*num)/log(base)));
    return fd;
}

int quer_sum(double num, double base) {
    double *nump = &num;
    int qs = 0;
#ifdef DEBUG
    int count = 0;
    printf("num(0): %.0f\n", num);
#endif
    while (num > 0) {
        qs += iterate_digit(nump, base);
#ifdef DEBUG
        printf("num(%d): %.0f (qs: %d)\n", ++count, num, qs);
#endif
    }
    return qs;
}

nine_result_t iterate_nines(double num, double base) {
    nine_result_t result;
    result.iterations = 0;
    int quer;
    while (num > base-1) {
        quer = quer_sum(num, base);
        num = num - quer;
        result.iterations++;
#ifdef DEBUG
        printf("quer: %d\n", quer);
        printf("iter(%d)=num-quer: %.0f-%d=%.0f\n", result.iterations, num+quer, quer, num);
#endif
    }
    result.result = num;
    return result;
}

