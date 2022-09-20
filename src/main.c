#include "header.h"

int main(int argc, char* argv[]) {

    if (argc != 5) {
        write(2, "usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result]\n", 72);
        exit(-1);
    }

    char *operand1 = delete_space(argv[1]);
    char *operation = delete_space(argv[2]);
    char *operand2 = delete_space(argv[3]);
    char *result = delete_space(argv[4]);

    check(argv, operand1, operation, operand2, result);
    equation(argv, operand1, operation, operand2, result);

    free(operand1);
    operand1 = NULL;
    free(operation);
    operation = NULL;
    free(operand2);
    operand2 = NULL;
    free(result);
    result = NULL;
}

