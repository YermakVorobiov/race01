#include "header.h"

void print(int i, int j, int k, char* op) {
    mx_printint(i);
    mx_printstr(op);
    mx_printint(j);
    mx_printstr(" = ");
    mx_printint(k);
    mx_printchar('\n');
}

void equation(char *argv[], char *operand1, char *operation, char *operand2, char *result) {

    int lenght_op1 = mx_strlen(delete_space(argv[1]));
    int lenght_op2 = mx_strlen(delete_space(argv[3]));
    int length_result = mx_strlen(delete_space(argv[4]));

    if (*operation == '?') {
        equation(argv, operand1, "+", operand2, result);
        equation(argv, operand1, "-", operand2, result);
        equation(argv, operand1, "*", operand2, result);
        equation(argv, operand1, "/", operand2, result);
        return;
    }

    bool isIBelowZero = false;
    if (operand1[0] == '-') {
        isIBelowZero = true;
        operand1++;
        lenght_op1--;
    }
    bool isJBelowZero = false;
    if (operand2[0] == '-') {
        isJBelowZero = true;
        operand2++;
        lenght_op2--;
    }
    bool isKBelowZero = false;
    if (result[0] == '-') {
        isKBelowZero = true;
        result++;
        length_result--;
    }

    long long first_number = mx_atoi(operand1);
    long long second_number = mx_atoi(operand2);
    long long third_number = mx_atoi(result);

    for (long long i = 0; i < mx_pow(10, lenght_op1); i++) {
        if (first_number > 0) i = first_number;

        char *i_str = mx_itoa(i);
        int i_str_length = mx_strlen(i_str);
        bool isCorrectI = true;

        for (int i_i = 0; i_i < lenght_op1 - i_str_length; i_i++)
            if (mx_isdigit(operand1[i_i]) && operand1[i_i] != '0') {
                isCorrectI = false;
                break;
            }

        for (int i_i = lenght_op1 - i_str_length, i_str_i = 0; i_i < lenght_op1; i_i++, i_str_i++) {
            if (operand1[i_i] != '?' 
                && operand1[i_i] != i_str[i_str_i]) {
                isCorrectI = false;
                break;
            }
        }
        free(i_str);
        i_str = NULL;

        if (!isCorrectI) continue;

        for (long long j = 0; j < mx_pow(10, lenght_op2); j++) {
            if (second_number > 0) j = second_number;

            char *j_str = mx_itoa(j);
            int j_str_length = mx_strlen(j_str);
            bool isCorrectJ = true;

            for (int j_i = 0; j_i < lenght_op2 - j_str_length; j_i++)
                if (mx_isdigit(operand2[j_i]) && operand2[j_i] != '0') {
                    isCorrectJ = false;
                    break;
                }

            for (int j_i = lenght_op2 - j_str_length, j_str_i = 0; j_i < lenght_op2; j_i++, j_str_i++) {
                if (operand2[j_i] != '?' && operand2[j_i] != j_str[j_str_i]) {
                    isCorrectJ = false;
                    break;
                }
            }

            free(j_str);
            j_str = NULL;

            if (!isCorrectJ) continue;

            for (long long k = 0; k < mx_pow(10, length_result); k++) {
                if (third_number > 0)  k = third_number;

                char *k_str = mx_itoa(k);
                int k_str_length = mx_strlen(k_str);
                bool isCorrectK = true;

                for (int k_i = 0; k_i < length_result - k_str_length; k_i++) {
                    if (mx_isdigit(result[k_i]) && result[k_i] != '0') {
                        isCorrectK = false;
                        break;
                    }
                }

                for (int k_i = length_result - k_str_length; k_i < length_result; k_i++) {
                    int k_str_i = 0;
                    if (result[k_i] != '?' && result[k_i] != k_str[k_str_i]) {
                        isCorrectK = false;
                        break;
                    }
                    k_str_i++;
                }

                free(k_str);
                k_str = NULL;

                if (!isCorrectK) continue;
                if (isIBelowZero) i *= -1;
                if (isJBelowZero) j *= -1;
                if (isKBelowZero) k *= -1;

                if (*operation == '+' && (i + j == k)) 
                    print(i, j, k, " + ");

                if (*operation == '-' && (i - j == k))
                    print(i, j, k, " - ");

                if (*operation == '*' && (i * j == k)) 
                    print(i, j, k, " * ");

                if (*operation == '/' && j != 0 && i / j == k) 
                    print(i, j, k, " / ");

                if (isIBelowZero) i *= -1;
                if (isJBelowZero) j *= -1;
                if (isKBelowZero) k *= -1;
                if (third_number > 0) break;
            }
            if (second_number > 0) break;
        }
        if (first_number > 0) break;
    }

    if (isIBelowZero) operand1--;
    if (isJBelowZero) operand2--;
    if (isKBelowZero) result--;

}

