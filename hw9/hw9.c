/**************************************************************
*                                                             *
*   NAME:                     Carmen St. Jean                 *
*   SECTION:                  01                              *
*                                                             *
*   ASSIGNMENT:               9                               *
*   DUE DATE:                 December 12, 2007               *
*                                                             *
*   PURPOSE: Finds the number of matches for a given fragment *
*      in a sample of DNA.  Uses structs and strings.         *
*   INPUT: A fragment and the name of a file, from which the  *
*      samples are read.                                      *
*   OUTPUT: The number of "hits" and the locations of each    *
*      hit for the samples.                                   *
*                                                             *
**************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ID 129
#define MAX_SEQ 257
#define MAX_LOC 100
#define MAX_FILE 121
#define MAX_SAMPLES 100

typedef struct
{
    char id[MAX_ID];
    char sequence[MAX_SEQ];
    int count;
    int locations[MAX_LOC];
}dna;

int file_open(char [], dna [], int);
void hits(char [], dna [], int);
void sort_id(dna [], int);
void print_hits(dna [], int);

int main(void)
{
    int count;
    char fragment[MAX_FILE], target_file[MAX_FILE];
    dna samples[MAX_SAMPLES];

    printf("\n\n================================\nDNA fragment Search");
    printf("\n================================\n");
    printf("\nEnter DNA fragment ");
    scanf("%s", fragment);
    printf("\nEnter target file name ");
    scanf("%s", target_file);

    count = file_open(target_file, samples, MAX_SAMPLES);
    printf("\n\n*******  DATABASE HITS  *********\n");
    printf("Results for fragment: %s\n\n", fragment);
    hits(fragment, samples, count);
    sort_id(samples, count);
    print_hits(samples, count);
    printf(" Goodbye\n");

    return 0;
}

/**************************************************************
*    FUNCTION: file_open                                      *
*    Opens file, and reads data into the array, or prints     *
*    appropriate error messages and quits.                    *
**************************************************************/
int file_open(char target_file[], dna samples[], int max_samples)
{
    char temp_id[MAX_ID], temp_sequence[MAX_SEQ];
    int i=0, st;
    FILE * fp;   
    fp = fopen(target_file, "r");
    if ( fp != NULL )
    {
        st = fscanf(fp, "%s %s", temp_id, temp_sequence);
        if ( st == EOF )
        {
            fflush(stdout);
            fprintf(stderr, "\nTarget file is empty\n Goodbye\n");
            exit(0);
        }
        while ( ( st != EOF ) )
        {
            if ( i < max_samples )
            {
                strcpy(samples[i].id, temp_id);
                strcpy(samples[i].sequence, temp_sequence);
                st = fscanf(fp, "%s %s", temp_id, temp_sequence);
            }
            else
            {
                fflush(stdout);
                fprintf(stderr, "\nToo much data in sample file\n Goodbye\n");
                exit(0);
            }
            i++;
        }
    }
    else
    {
        fflush(stdout);
        fprintf(stderr, "\nCould not open the target file %s", target_file);
        fprintf(stderr, " for reading\n Goodbye\n");
        exit(0);
    }
    fclose(fp);
    return i;
}


/**************************************************************
*    FUNCTION: hits                                           *
*    Finds the hits in each sample and records where each is. *
**************************************************************/
void hits(char fragment[], dna samples[], int sample_count)
{
    int i, j, fraglen, hits_exist = 0;
    fraglen = strlen(fragment);
    for (i=0; (i<sample_count) && (strlen(samples[i].sequence)>fraglen); i++)
    {
        samples[i].count = 0;
        for ( j = 0; j < (strlen(samples[i].sequence) - (fraglen-1)) ; j++ )
        {
            if ( strncmp(samples[i].sequence + j, fragment, fraglen) == 0 )
            {
                samples[i].locations[samples[i].count] = j;
                samples[i].count++;
                hits_exist = 1;
            }
        }
    }
    if ( hits_exist == 0 )
        printf("***There are no hits for %s in the database***\n\n",
           fragment);
    return;
}

/**************************************************************
*    FUNCTION: sort_id                                        *
*    Sorts the DNA samples from greatest to least hits.       *
**************************************************************/
void sort_id(dna samples[], int count)
{
    int p, i;
    dna temp;
    for ( p = 0; p < count-1; p++ )
    {
        for ( i = 0; i < count - ( p + 1 ) ; i++ )
        {
            if (samples[i].count < samples[i + 1].count)
            {
                temp = samples[i+1];
                samples[i+1] = samples[i];
                samples[i] = temp;
            }
        }
    }
    return;
}

/**************************************************************
*    FUNCTION: print_hits                                     *
*    Prints the samples with more than one hit and the        *
*    locations of each hit.                                   *
**************************************************************/
void print_hits(dna samples[], int count)
{
    int i, j;
    for ( i = 0; i < count; i++ )
    {
        if ( samples[i].count >= 1 )
        {
            printf("%s\n%s\n\n", samples[i].id, samples[i].sequence);
            printf("   Number of hits: %d\n", samples[i].count);
            for ( j = 0; (j < samples[i].count) && (j < 20); j++ )
                printf("**Hit at location %d\n", samples[i].locations[j]);
            printf("\n********************************\n\n");
        }
    }
    return;
}
