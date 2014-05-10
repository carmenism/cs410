/**************************************************************
*                                                             *
*   NAME:                     Carmen St. Jean                 *
*   SECTION:                  01                              *
*                                                             *
*   ASSIGNMENT:               6                               *
*   DUE DATE:                 November 7, 2007                *
*                                                             *
*   PURPOSE:                                                  *
*     This function evaluates the areas under a graph using   *
*     an approximation of rectangular areas.                  *
*   INPUT:                                                    *
*     An ID number for the data set, a count number for the   *
*     number of pairs in the set, and the data pairs.         *
*   OUTPUT:                                                   *
*     The set ID number, the number of pairs read, a list of  *
*     the pairs, and the numerical integral.                  *
*                                                             *
**************************************************************/
#include <stdio.h>
#include <math.h>
#define MAX_X 50
#define MAX_Y 50

/**************************************************************
*    FUNCTION: get_data                                       *
*    Reads the data into arrays.                              *
*                                                             *
**************************************************************/
void get_data(double [], double [], int);

/**************************************************************
*    FUNCTION: print_data                                     *
*    Prints the contents of the arrays as x,y pairs.          *                                                   *
*                                                             *
**************************************************************/
void print_data(double [], double [], int);

/**************************************************************
*    FUNCTION: calc_area                                      *
*    Calculates the numerical integral using the rectangular  *
*    rule.                                                    *
*                                                             *
**************************************************************/
double calc_area(double [], double [], int);

int main(void)
{

    int data_set=0, count=0, status=0;
    double x_data[MAX_X], y_data[MAX_Y], integral=0.0;

    printf("\n\n*******************************************************");
    printf("******************\n********** Welcome to the Rectangulator");
    printf("  ********************************\n***********************");
    printf("**************************************************\n\n");

    status = scanf("%d%d", &data_set, &count);

    while ( status != EOF ) {

    if ( count > MAX_X )
    {
        printf("ERROR:  Too much data in data set %d ", data_set);
        printf("--- exiting program\n\n");
        status = EOF;
    }

    else if ( count < 2 )
    {
        int i=0;
        double read_in=0;
        printf("Reading data\n\n");
        printf("ERROR:  Not enough data in data set %d ", data_set);
        printf(" --- continuing with next data set\n\n");
        while ( i < 2*count )
        {
            scanf("%lf", &read_in);
            i++;
        }
        status = scanf("%d%d", &data_set, &count);
    }

    else

    {
        printf("Reading data\n\n");
        get_data(x_data, y_data, count);

        printf("****** Data Set  %d  with %d ", data_set, count);
        printf("data points ********************************\n");
        print_data(x_data, y_data, count);

        integral = calc_area(x_data, y_data, count);
        printf("\n\n***************************************************");
        printf("**********************\nThe numerical integral under the");
        printf(" graph between %g and %g is:", x_data[0], x_data[count-1]);
        printf("   %g\n*************************", integral);
        printf("************************************************\n\n\n");

        status = scanf("%d%d", &data_set, &count);

    }

    }
    printf("Good bye!\n");
    return 0;
}

void get_data(double x_data[MAX_X], double y_data[MAX_Y], int count)
{
    int i=0;
    double x_value, y_value;

    while ( i < count )
    {
        scanf(" %lf %lf", &x_value, &y_value);
        x_data[i] = x_value;
        y_data[i] = y_value;
        i++;
    }
    return;
}


void print_data(double x_data[MAX_X], double y_data[MAX_Y], int count)
{
    int i=0;
    double x_value, y_value;
    printf("   x      y\n_____________\n");

    while ( i < count )
    {
        x_value = x_data[i];
        y_value = y_data[i];
        printf("%5.1f %6.1f\n", x_value, y_value);
        i++;
    }
    return;
}

double calc_area(double x_d[MAX_X], double y_d[MAX_Y], int count)
{
    int i=0;
    double left_x=0.0, right_x=0.0;
    double width=0.0, height=0.0, area=0.0, total_area=0.0;

    while ( i < count-1 )
    {
        left_x = x_d[i];
        right_x = x_d[i+1];
        width = right_x - left_x;
        height = y_d[i];
        area = width * height;
        total_area += area;
        i++;
    }
    return total_area;
}
