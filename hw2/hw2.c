/**************************************************************
*                                                             *
*   NAME:                     Carmen St. Jean                 *
*   SECTION:                  01                              *
*                                                             *
*   ASSIGNMENT:               2                               *
*   DUE DATE:                 September 24, 2007              *
*                                                             *
*   PURPOSE:                                                  *
*      Calculates volume.                                     *
*   INPUT:                                                    *
*      The dimensions of a shape.                             *
*   OUTPUT:                                                   *
*      That shape's volume.                                   *
*                                                             *
**************************************************************/

#include <stdio.h>
#include <math.h>
#define PI 3.14159
#define CMTOINCH 0.3937

int main(void)
{
    /* variable declarations */
    double side1=0.0, side2=0.0, side3=0.0;     /*box*/
    double radius=0.0, cheight=0.0;             /*cylinder*/
    double rsmall=0.0, rlarge=0.0, fheight=0.0; /*fustrum*/
    double length=0.0;                          /*icosohedron*/

    double vbox=0.0, vboxinch=0.0;              /*volumes*/
    double vcyl=0.0, vcylinch=0.0;
    double vfus=0.0, vfusinch=0.0;
    double vico=0.0, vicoinch=0.0;

    printf("\n\n           Solid Volume Computational Program");
    printf("\n           ==================================\n\n");

    /* box input */
    printf("BOX------------------------------------------------------\n");
    printf(" Please enter the lengths of the sides of the box.\n");
    scanf("%lf%lf%lf",&side1,&side2,&side3);

    /* box process */
    vbox = side1*side2*side3;
    vboxinch = vbox * pow(CMTOINCH,3);

    /* box output */
    printf(" A box with sides of %.4f cm, %.4f cm, and %.4f cm",
           side1, side2, side3);
    printf("\n will have a volume of:\n\n    %.6f cm-cubed or",
           vbox);
    printf(" %.5e in-cubed.\n\n",
           vboxinch);

    /* cylinder input */
    printf("CYLINDER-------------------------------------------------\n");
    printf(" Please enter the radius of the base and the height.\n");
    scanf("%lf%lf",&radius,&cheight);  

    /* cylinder process */
    vcyl = PI*pow(radius,2.0)*cheight;
    vcylinch = vcyl * pow(CMTOINCH,3);

    /* cylinder output */
    printf(" A cylinder with a radius of %.4f cm and a height of\n",
           radius);
    printf(" %.4f cm will have a volume of:\n\n    %.6f cm-cubed or",
           cheight, vcyl);
    printf(" %.5e in-cubed.\n\n", vcylinch);

    /* fustrum input */
    printf("FUSTRUM--------------------------------------------------\n");
    printf(" Please enter the");
    printf(" small radius, large radius, and height of the fustrum.\n");
    scanf("%lf%lf%lf",&rsmall,&rlarge,&fheight);

    /* fustrum process */
    vfus = PI*(fheight/3.0)*(pow(rsmall,2.0)+rsmall*rlarge+pow(rlarge,2.0));
    vfusinch = vfus * pow(CMTOINCH,3);

    /* fustrum output */
    printf(" A fustrum with a small radius of %.4f cm, a large radius\n",
           rsmall);
    printf(" of %.4f cm, and height of %.4f cm",
           rlarge, fheight);
    printf(" will have a volume of:\n\n    %.6f cm-cubed or",
           vfus);
    printf(" %.5e in-cubed.\n\n",
           vfusinch);

    /* icosohedron input */
    printf("ICOSOHEDRON----------------------------------------------\n");
    printf(" Please enter the length of the edge of the icosohedron.\n");
    scanf("%lf",&length);

    /* icosohedron process */
    vico = (5.0/12.0)*(3.0+sqrt(5.0))*pow(length,3.0);
    vicoinch = vico * pow(CMTOINCH,3);

    /* icosohedron output */
    printf(" An icosohedron with a length of %.4f cm",
           length);
    printf(" will have a volume of:\n\n    %.6f cm-cubed",
           vico);
    printf(" or %.5e in-cubed.\n\n",
           vicoinch);

    printf("Goodbye.\n");

    return 0;

}

