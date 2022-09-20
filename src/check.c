#include "../inc/header.h"

void print_e(char* error, char* argv) {
    write(2, error, mx_strlen(error));
    write(2, argv, mx_strlen(argv));
    write(2, "\n", 1);
    exit(-1);
}

void check(char* argv[], char* operand1, char* operation, char* operand2, char* result) {

    int lenght_op1 = mx_strlen(operand1);
    int lenght_op2 = mx_strlen(operand2);
    int length_operation = mx_strlen(operation);
    int length_result = mx_strlen(result);


    if (length_operation != 1) print_e("Invalid operation: ", argv[2]);
    if (*operation != '?' && *operation != '+' && *operation != '-' && *operation != '*' && *operation != '/') {
        print_e("Invalid operation: ", argv[2]);
    }

    if (lenght_op1 <= 0) print_e("Invalid operand: ", argv[1]);
    for (int i = 0; i < lenght_op1; i++) {
        if (i == 0 && operand1[i] == '-' 
            && (mx_strcmp((const char*)operand1, "-") != 0)) 
            continue;

        if (operand1[i] != '?' && !mx_isdigit(operand1[i]))
            print_e("Invalid operand: ", argv[1]);
    }

    if (lenght_op2 <= 0) print_e("Invalid operand: ", argv[3]);
    if (mx_strcmp((const char*)operation, "/") == 0 
        && mx_strcmp((const char*)operand2, "0") == 0)
        print_e("Invalid operand: ", argv[3]);
    for (int i = 0; i < lenght_op2; i++) {
        if (i == 0 && operand2[i] == '-' 
            && (mx_strcmp((const char*)operand2, "-") != 0)) 
            continue;

        if (operand2[i] != '?' && !mx_isdigit(operand2[i]))
            print_e("Invalid operand: ", argv[3]);
        }

    if (length_result <= 0) print_e("Invalid result: ", argv[4]);
    for (int i = 0; i < length_result; i++) {
        if (i == 0 && result[i] == '-' 
            && (mx_strcmp((const char*)result, "-") != 0))
            continue;

        if (result[i] != '?' && !mx_isdigit(result[i]))
            print_e("Invalid result: ", argv[4]);
    }
}

