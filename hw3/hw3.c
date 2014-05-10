/**************************************************************
*                                                             *
*   NAME:                     Carmen St. Jean                 *
*   SECTION:                  01                              *
*                                                             *
*   ASSIGNMENT:               3                               *
*   DUE DATE:                 October 03, 2007                *
*                                                             *
*   PURPOSE:                                                  *
*      This program classifies soil types; it utilizes        *
*      if-else statements.                                    *
*   INPUT:                                                    *
*      Sample number, sieve analysis, moisture content,       *
*      plastic index, test value 1, and test value 2.         *
*   OUTPUT:                                                   *
*      Soil classification and group index.                   *
*                                                             *
**************************************************************/
#include <stdio.h>
#include <math.h>
#define SILTYLIQLIM 40.0

int
main(void)
{
    /* variable declarations */
    int sample=0, test1=0;
    double seive=0.0, moisture=0.0, plasticindex=0.0, test2=0.0;
    double groupindex=0.0, liqlim=0.0;

    /* introductory header */
    printf("\n\n********************************");
    printf("*****************************\n\n");
    printf("          Welcome to the DIRT Soil Classification Program");
    printf("\n          ===============================\n\n");

    /* inputs */
    printf("Enter sample #         ");
    scanf("%d", &sample);
    printf("\nEnter sieve analysis   ");
    scanf("%lf", &seive);
    printf("\nEnter moisture content ");
    scanf("%lf", &moisture);
    printf("\nEnter plastic index    ");
    scanf("%lf", &plasticindex);
    printf("\nEnter test value 1     ");
    scanf("%d", &test1);
    printf("\nEnter test value 2     ");
    scanf("%lf", &test2);

    /* output header */
    printf("\n\n********************************");
    printf("*****************************");
    printf("\n\n               Soil Classification Analysis");
    printf("\n               ===============================");

    /* output calculations */
    liqlim = moisture * pow((test1/25.0),tan(test2));
    groupindex = (seive-35.0) * (0.2+0.005*(liqlim-40.0)) + 
                 0.01 * (seive-15.0) * (plasticindex-10.0);

    /* input echo */
    printf("\n\n\nInput Data:");
    printf("\n    Sample Number : %8d", sample);
    printf("\n    Sieve Analysis : %7.2f", seive);
    printf("\n    Moisture Content : %4.2f", moisture);
    printf("\n    Plastic Index: %9.2f", plasticindex);
    printf("\n    Test Value 1 : %9d", test1);
    printf("\n    Test Value 2 : %9.2f", test2);

    /* output table */
    printf("\n\nAnalysis:\n\n");
    printf("******************************************************\n\n");
    printf("    Soil Number     Classification        Group Index\n");
    printf("    -----------     --------------        -----------\n\n");

    /* soil number */
    printf("\n     Case #%02d:", sample);

    /* classification */
    if ((seive <= 15.0) && (plasticindex <= 6.00)) {
        printf("       Gravel               "); }
    else if ((seive <= 35.0) && (plasticindex <= 10.0) && 
            (liqlim <= SILTYLIQLIM)) {
        printf("       Silty Sand A         "); }
    else if ((seive <= 35.0) && (plasticindex) <=10.0 && 
            (liqlim > SILTYLIQLIM)) {
        printf("       Silty Sand B         "); }
    else if ( seive > 35.0 ) {
        printf("       Clay                 "); }
    else {
        printf("       Other                "); }

    /* group index */
    if ( groupindex < 0.0 ) {
        groupindex = 0.0; }
    printf("%.6e", groupindex);

    printf("\n------------------------------------------------------");
    printf("\n\nGoodbye\n");

    return 0;

}
