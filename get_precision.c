#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to the current position in the format string
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list) {
    int curr_i = *i;
    int precision = -1;

    if (format[curr_i] != '.')
        return precision;

    curr_i++;
    precision = 0;

    while (format[curr_i] != '\0') {
        if (isdigit(format[curr_i])) {
            precision *= 10;
            precision += format[curr_i] - '0';
            curr_i++;
        } else if (format[curr_i] == '*') {
            curr_i++;
            precision = va_arg(list, int);
            break;
        } else {
            break;
        }
    }

    *i = curr_i;
    return precision;
}
