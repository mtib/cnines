#include "analyzer.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("to few arguments");
        return 1;
    }

    int *iterations;
    int num_iter = atoi(argv[1]);
    double base = atof(argv[2]);

    iterations = (int*) malloc(sizeof(int) * num_iter);

    int max;
    int min;

    for (int i=0; i<num_iter; i++) {
        int curr = iterate_nines(base+i, base).iterations;
        *(iterations+i) = curr;
        if (max < curr) {
            max = curr;
        } else if ( min > curr ) {
            min = curr;
        }
    }    

    char *graph = (char*) malloc(sizeof(char) * (num_iter+1) * max+1);

    for (int i=0; i<num_iter; i++) {
        for (int j=0; j<=max; j++) {
            *(graph+i+j*(num_iter+1)) = (max-*(iterations+i) == j) ? '*' : ' ';
        }
    }
    for (int j=0; j<max; j++) {
        *(graph+num_iter+j*(num_iter+1)) = '\n';
    }
    *(graph+num_iter+max*(num_iter+1)) = '\0';

    printf("%s\n", graph);

    free(graph);
    free(iterations);
    return 0;
}
