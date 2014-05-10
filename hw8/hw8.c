/**************************************************************
*                                                             *
*   NAME:                     Carmen St. Jean                 *
*   SECTION:                  01                              *
*                                                             *
*   ASSIGNMENT:               8                               *
*   DUE DATE:                 December 5, 2007                *
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
#include <stdlib.h>
#define MAX_FILENAME 120
#define MAX_SKINAME 20
#define MAX_AREAS 50
#define MAX_DAYS 7

int file_open(char [], int, char [][MAX_SKINAME], int, int, 
    double [][MAX_DAYS], int, int);

int main(void)
{
    char input, filename[MAX_FILENAME];
    char skinames[MAX_AREAS][MAX_SKINAME];
    double snowfall[MAX_AREAS][MAX_DAYS];

    printf("Welcome to the Acme Ski Database\n");
    printf("__________________________________\n\n\n\n");

    printf("Please enter your Command:\n");
    printf("F - open file\nP - print all\nG - greatest snow\n");
    printf("A - average\nS - one area\nD - one day\nQ - quit\n");
    fscanf(stdin, "%c", &input);

    /* OPEN FILE */
    if ( input == 'f' || input == 'F' )
    }
        fscanf(stdin, "%s", &filename[0]);
    }

    /* PRINT ALL */
    if ( input == 'p' || input == 'P' )
    {
        ;
    } 

    /* GREATEST SNOW */
    if ( input == 'g' || input == 'G' )

    /* AVERAGE */
    if ( input == 'a' || input == 'A' )

    /* ONE AREA */
    if ( input == 's' || input == 'S' )

    /* ONE DAY */
    if ( input == 'd' || input == 'D' )

    /* QUIT */
    if ( input == 'q' || input == 'Q' )     

    return 0;
}

int file_open(char filename[], char skinames[][MAX_SKINAME],
    int ski_areas, int ski_length, double snowfall[][MAX_DAYS], 
    int snow_areas, int snow_days)
{
    FILE * fp;
    fp = fopen(filename, "r");
    if ( fp != NULL )
    {
        fscanf(fp, "%s", temp);
        temp;
    }
    else
    {
        fprint(stderr, "Couldn't open file %s\n", filename);
        exit(0);
    }
    
    return;
}
