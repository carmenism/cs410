/**************************************************************
*                                                             *
*   NAME:                     Carmen St. Jean                 *
*   SECTION:                  01                              *
*                                                             *
*   ASSIGNMENT:               7                               *
*   DUE DATE:                 November 14, 2007               *
*                                                             *
*   PURPOSE:                                                  *
*     Simulates the transfer of heat across a metal plate.    *
*   INPUT:                                                    *
*     The critical value, the heater temperature, and the     *
*     plate temperature.                                      *
*   OUTPUT:                                                   *
*     A sequence of plate displays and the average temperature*
*     for the final plate displayed.                          *
*                                                             *
**************************************************************/
#include <stdio.h>
#include <math.h>
#define ROW 9
#define COL 8

void echo(double, double, double);
void plate_initializer(double[][COL], int, int, double);
void plate_print(double [][COL], int, int);
void temp_updater(double [][COL], double [][COL], int, int, double);
void plate_copier(double [][COL], double [][COL], int, int);
int plate_compare(double [][COL], double [][COL], int, int, double);
void plate_average(double [][COL], int, int);

int main(void)
{
    double critical=0.0, heater_temp=0.0, plate_initial=0.0;
    double plate_a[ROW][COL], plate_b[ROW][COL];
    int count = 1, compare_value = 0;

    printf("\nWelcome to the Heat Plate Simulation\n\n");
    printf("Enter:  Heater Temp, Plate Temp and Number of cycles\n");
    scanf("%lf%lf%lf", &critical, &heater_temp, &plate_initial);

    echo(critical, heater_temp, plate_initial);
    plate_initializer(plate_a, ROW, COL, plate_initial);
    printf("\n    #### INITIAL PLATE  ####\n");
    plate_print(plate_a, ROW, COL);
 
    while ( compare_value != 1 )
    {
        temp_updater(plate_a, plate_b, ROW, COL, heater_temp);
        printf("\n    #### PLATE %d ####\n", count);
        plate_print(plate_b, ROW, COL);
        compare_value = plate_compare(plate_a, plate_b, ROW, COL, critical);
        plate_copier(plate_a, plate_b, ROW, COL);
        count++;
    }

    plate_average(plate_b, ROW, COL);
    printf("\nGoodbye!\n");

    return 0;
}

/**************************************************************
*    FUNCTION: echo                                           *
*    Echos the data from the input.                           *
**************************************************************/
void echo(double critical,double heater_temp, double plate_initial)
{
    printf("\n   HEATER   TEMPERATURE:       %.2f", heater_temp);
    printf("\n   INITIAL PLATE TEMPERATURE:  %.2f", plate_initial);
    printf("\n   STABALIZATION CRITERION:    %.2f\n", critical);

    return;
}

/**************************************************************
*    FUNCTION: plate_initializer                              *
*    Sets all values of the plate to the initial value.       *
**************************************************************/
void plate_initializer(double plate[][COL], int rows, int cols, 
    double plate_initial)
{
    int r, c;
    for ( r = 0; r < rows; r++ )
    {
        for ( c = 0; c < cols; c++ )
            plate[r][c] = plate_initial;
    }
    return;
}

/**************************************************************
*    FUNCTION: plate_print                                    *
*    Prints a given plate out in an organized format.         *
**************************************************************/
void plate_print(double plate[][COL], int rows, int cols)
{
    int r, c;
    for ( r = 0; r < rows; r++ )
    {
        for ( c = 0; c < cols; c++ )
            printf(" %6.2f", plate[r][c]);
        printf("\n");
    }
    return;
}

/**************************************************************
*    FUNCTION: temp_updater                                   *
*    Calculates the new temperature for each element of plate.*
**************************************************************/
void temp_updater(double plate_a[][COL], double plate_b[][COL],
    int rows, int cols, double heater_temp)
{
    int r=0, c=0;

    /* FIRST ROW */
    plate_b[r][c] = ( plate_a[r][c] + plate_a[r+1][c] + plate_a[r][c+1] )
        / 3.0;
    c++;
    while ( c < cols-1 )
    {
        plate_b[r][c] = ( plate_a[r][c] + plate_a[r][c-1] + plate_a[r][c+1]
            + plate_a[r+1][c] ) / 4.0;
        c++;
    }
    plate_b[r][c] = ( plate_a[r][c] + plate_a[r][c-1] + plate_a[r+1][c] )
        / 3.0;
    r++;

    /* SECOND ROW */
    c = 0;
    plate_b[r][c] = ( plate_a[r][c] + plate_a[r-1][c] + plate_a[r+1][c] +
        plate_a[r][c+1] + heater_temp ) / 5.0;
    c++;
    while ( c < cols-1 )
    {
        plate_b[r][c] = ( plate_a[r][c] + plate_a[r][c-1] + plate_a[r][c+1]
            + plate_a[r+1][c] + plate_a[r-1][c] ) / 5.0;
        c++;
    }
    plate_b[r][c] = ( plate_a[r][c] + plate_a[r][c-1] + plate_a[r+1][c] +
        plate_a[r-1][c] ) / 4.0;
    r++;

    /* THIRD, FOURTH, FIFTH, SIXTH, SEVENTH ROWS */
    while ( r < rows-1 )
    {
        c = 0;
        plate_b[r][c] = ( plate_a[r][c] + plate_a[r+1][c] + 
            plate_a[r][c+1] + plate_a[r-1][c] ) / 4.0;
        c++;
        while ( c < cols-1 )
        {
            plate_b[r][c] = ( plate_a[r][c] + plate_a[r][c-1] +
                plate_a[r][c+1] + plate_a[r+1][c] + plate_a[r-1][c] ) / 5.0;
            c++;
        }
        plate_b[r][c] = ( plate_a[r][c] + plate_a[r][c-1] +
            plate_a[r+1][c] + plate_a[r-1][c] ) / 4.0;
        r++;
    }

    /* EIGHTH ROW */
    c = 0;
    plate_b[r][c] = ( plate_a[r][c] + plate_a[r-1][c] + plate_a[r][c+1] )
        / 3.0;
    c++;
    while ( c < cols-1 )
    {
        plate_b[r][c] = ( plate_a[r][c] + plate_a[r][c-1] + plate_a[r][c+1]
            + plate_a[r-1][c] ) / 4.0;
        c++;
    }
    plate_b[r][c] = ( plate_a[r][c] + plate_a[r][c-1] + plate_a[r-1][c] )
        / 3.0;    

    return;
}


/**************************************************************
*    FUNCTION: plate_copier                                   *
*    Copies the elements of one plate to another.             *
**************************************************************/
void plate_copier(double plate_a[][COL], double plate_b[][COL],
    int rows, int cols)
{
    int r, c;
    for ( r = 0; r < rows; r++ )
    {
        for ( c = 0; c < cols; c++ )
            plate_a[r][c] = plate_b[r][c];
    }
    return;
}

/**************************************************************
*    FUNCTION: plate_compare                                  *
*    Compares two plates by finding the differences of each   *
*    element, then finds the maximum difference value, and    *
*    compares this to 'critical' (returns 1 if less than it). *
**************************************************************/
int plate_compare(double plate_a[][COL], double plate_b[][COL],
    int rows, int cols, double critical)
{
    int r, c, return_val = 0;
    double plate_difference[ROW][COL];
    double max;
    for ( r = 0; r < rows; r++ )
    {
        for ( c = 0; c < cols; c++ )
        {
            plate_difference[r][c] = fabs(plate_b[r][c] - plate_a[r][c]);
        }
    }
    max = plate_difference[0][0];
    for ( r = 0; r < rows; r++ )
    {
        for ( c = 0; c < cols; c++ )
        {
            if ( plate_difference[r][c] > max )
                max = plate_difference[r][c];
        }
    }
    if ( max < critical )
    {
        return_val = 1;
    }
    return return_val;
}

/**************************************************************
*    FUNCTION: plate_average                                  *
*    Finds the average of all elements of plate.              *
**************************************************************/
void plate_average(double plate[][COL], int rows, int cols)
{
    double sum=0.0, average;
    int r, c;
    for ( r = 0; r < rows; r++ )
    {
        for ( c = 0; c < cols; c++ )
            sum += plate[r][c];
    }
    average = sum / 72.0;
    printf("\n\n     SIMULATION COMPLETE\n     AVERAGE PLATE ");
    printf("TEMPERATURE %.2f\n", average);
    return;
}
