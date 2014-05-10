/**************************************************************
*                                                             *
*   NAME:                     Carmen St. Jean                 *
*   SECTION:                  01                              *
*                                                             *
*   ASSIGNMENT:               5                               *
*   DUE DATE:                 October 25, 2007                *
*                                                             *
*   PURPOSE:                                                  *
*                                                             *
*   INPUT:                                                    *
*                                                             *
*   OUTPUT:                                                   *
*                                                             *
*                                                             *
**************************************************************/
#include <stdio.h>
#include <math.h>

double polynomial(double a, double b, double c, double x);

int main(void) {





    return 0;
}

double polynomial(double a, double b, double c, double x) {
    double f = 0.0;
    f = a * pow(x,2) + b * x + c;
    return f;
}

int input_verify(double a, double b, double c, double left, double right,
double y_critical) {
    int t_f = 0;
    if ( (right > left) || (y_critical < 0) ||
    ( (left > 0) && (right > 0) ) || ( (left < 0) && (right < 0) ) ) {
        /* FALSE */
        t_f = 0;
        }
    else {
        /* TRUE */
        t_f = 1;
        }
    return t_f;
}
