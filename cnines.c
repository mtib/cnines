#include "nines.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("nines <number base 10> <base>\n");
        return 1;
    }
    double num = atof(argv[1]);
    double base = atof(argv[2]);
    printf("num:  %.0f\nbase: %.0f\n", num, base);
    nine_result_t t = iterate_nines(num, base);
    printf("reached %.0f=base-1 after %d iterations\n", t.result, t.iterations);
    return 0;
}
