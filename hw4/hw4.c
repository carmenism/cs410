/**************************************************************
*                                                             *
*   NAME:                     Carmen St. Jean                 *
*   SECTION:                  01                              *
*                                                             *
*   ASSIGNMENT:               4                               *
*   DUE DATE:                 October 17, 2007                *
*                                                             *
*   PURPOSE:                                                  *
*      This program approximates cos and exp.                 *
*   INPUT:                                                    *
*      A character followed by two floating point numbers.    *
*   OUTPUT:                                                   *
*      Index for the term, value of the term, current         *
*      approximate value, and the error.                      *
*                                                             *
**************************************************************/
#include <stdio.h>
#include <math.h>

double fact(int n) {
    double f = 1.0;
    int i;
    for ( i = n; i > 0; i-- )
            f = f * i;
    return f;
}

int main(void) {

    char input_type;
    double x=0.0, error_lim=0.0;
    double actual_e=0.0, approx_e_term=0.0, approx_e_sum=0.0, error_e=1.0;
    double actual_c=0.0, approx_c_term=0.0, approx_c_sum=0.0, error_c=1.0; 
    int n=0;

    printf("\n***************************************************");
    printf("\n*    Acme Partial Sum  Approximator!    *");
    printf("\n***************************************************");

    printf("\n\nEnter e for exponential, ");
    printf("c for cosine or any other letter to quit\n");
    scanf(" %c", &input_type);
   
    while ( ( input_type == 'c' ) || ( input_type == 'e' ) ) {

    approx_e_sum = 0.0;
    approx_c_sum = 0.0;
   
    printf("\nEnter a number and limit\n");
    scanf(" %lf %lf", &x, &error_lim);

    if ( input_type == 'c' ) {

        actual_c = cos(x);

        printf("\n***************************************************");
        printf("\n*    Approximating cos(%g)", x);
        printf(" with limit   %g", error_lim);
        printf("\n*    The true value of cos(%g)", x);
        printf(" is   %g", actual_c);
        printf("\n***************************************************\n\n");
        printf("\nn      Term           Approx Sum           ERROR\n");
        n = 0; 

        approx_c_term = error_lim + 1;

        while ( fabs(approx_c_term) > error_lim ) {

            actual_c = cos(x);
            approx_c_term = pow((-1),n)*(pow(x,(2*n)))/fact(2*n);
            approx_c_sum += approx_c_term;
            error_c = fabs(actual_c-approx_c_sum);

            printf("%02d ", n);
            printf("  %12.8f   ", approx_c_term);
            printf("%12.8f    ", approx_c_sum);
            printf("%12g\n", error_c);

            n++;
        }
    }

    else if ( input_type == 'e' ) {

        actual_e = exp(x);

        printf("\n***************************************************");
        printf("\n*    Approximating exp(%g)", x);
        printf(" with limit   %g", error_lim);
        printf("\n*    The true value of exp(%g)", x);
        printf(" is   %g", actual_e);
        printf("\n***************************************************\n\n");
        printf("\nn      Term           Approx Sum           ERROR\n");
        n = 0;

        approx_e_term = error_lim + 1;

        while ( fabs(approx_e_term) > error_lim ) {

            actual_e = exp(x);
            approx_e_term = pow(x,n)/(fact(n));
            approx_e_sum += approx_e_term;
            error_e = fabs(actual_e-approx_e_sum);

            printf("%02d", n);
            printf("%15.8f   ", approx_e_term);
            printf("%12.8f    ", approx_e_sum);
            printf("%12g\n", error_e);

            n++;
        }

    }

    printf("\nDone!\n\n");  
    printf("Enter e for exponential, ");
    printf("c for cosine or any other letter to quit\n");
    scanf(" %c", &input_type);
 
    }

    printf("\n Goodbye!\n\n");

    return 0;
}
