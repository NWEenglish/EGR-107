/***********************************************************************

Author: Nicholas English
Course: EGR-107-006
Assignment: Assignment 1
Date of Completion: 1/17/2018
Program Name: EGR107_Sec006_English_Assignment1
Inputs: User will input the polynomial values, x-initial, x-final,
    and delta-x values.
Outputs: User will receive a table that lists all the values of x,
    f(x), f'(x), and area respectively.
Description: This program takes input from the user to fill in the
    missing parameters for a second-degree polynomial. This program
    will then use this to calculate the rate of change and the area
    under the curve. The program gets more user input to find
    x-initial, x-final, and delta x. With this, the program will
    then display a table to the user starting at x-initial,and going
    up by delta x amount until it reaches (but does not pass) the
    x-final. Each line on the table will hold values representing x,
    f(x), f'(x), and Area.

***********************************************************************/

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Functions */
/** Introduces the program to the user */
void introFunction();

/** Calculates f(x), f'(x), and A */
void calcFunction( double aValue, double bValue, double cValue,
                   double x, double x_i, double *pArea, double *pF_x,
                   double *pF_prime_x );

int main() {

    /* Variables */
    double aValue, bValue, cValue;      // Second-degree poly. values
    double x_i, x_f, delta_x;           // Used for x-values in table
    double x;                           // Used for for-loops and calc.
    double pArea, pF_x, pF_prime_x;     // Used for call-by-reference

    /* Calls the "introFunction" function */
    introFunction();

    /* Asks the user for variables for calculating */
    printf( " Enter the values for the second-degree polynomial: " );
    scanf( " %lf %lf %lf", &aValue, &bValue, &cValue );

    printf( "\n Enter the values for x-initial, x-final, and "
                "delta x: " );
    scanf( " %lf %lf %lf", &x_i, &x_f, &delta_x );

    /* Creation of the table */

        /* Header of the table */
        // Equation with filled in values
        printf( "\n\n f(x) = %.3lfx^2 + %.3lfx + %.3lf ", aValue,
               bValue, cValue );

        // Labels for table
        printf( "\n    x\t  f(x)\t  f'(x)\t    A" );

        // Line separator
        printf( "\n -------------------------------- \n" );

        /* Body of the table */
        // Loops until x has reached x-final
        for( x = x_i; x <= x_f; x = x + delta_x ) {

            // Calls the "calcFunction" */
            calcFunction( aValue, bValue, cValue, x, x_i, &pArea,
                         &pF_x, &pF_prime_x );

            // Prints the row to the table
            printf("\n %6.3lf\t %6.3lf\t %6.3lf\t %6.3lf",
                   x, pF_x, pF_prime_x, pArea);

        }

    /* End of code reached */
    printf("\n\n\n");
    return 0;

}

/** Writes to the user a welcome/intro to the program */
void introFunction() {

    // Intro to the user written in the console
    printf( "\n Welcome to EGR107_Sec006_English_Assignment1!"
            "\n This program takes input from the user to fill in "
                "the missing parameters"
            "\n for a second-degree polynomial. This program will "
                "then use this to calculate"
            "\n the rate of change and the area under the curve. "
                "The program gets more user"
            "\n input to find x-initial, x-final, and delta x. "
                "With this, the program will"
            "\n then display a table to the user starting at "
                "x-initial,and going up by"
            "\n delta x amount until it reaches (but does not "
                "pass) the x-final. Each line"
            "\n on the table will hold values representing x, "
                "f(x), f'(x), and Area.\n\n" );

}

/** Takes in values for the second-degree polynomial, x, and x_i. It
    then returns the values via pointers. This process is called
    "call-by-reference" */
void calcFunction ( double aValue, double bValue, double cValue,
                   double x, double x_i, double *pArea, double *pF_x,
                   double *pF_prime_x ) {

    /* Calculates for f(x) */
    *pF_x = ( ( aValue * pow( x, 2 ) ) + ( bValue * x ) + cValue );

    /* Calculates for f'(x) */
    *pF_prime_x = ( ( 2 * aValue * x ) + bValue );

    /* Calculates for Area */
    *pArea = ( ( ( aValue / 3) * pow( x, 3 ) ) + ( ( bValue / 2 )
            * pow( x, 2 ) ) + ( cValue * x ) ) -
            ( ( ( aValue / 3) * pow( x_i, 3 ) ) + ( ( bValue / 2 )
            * pow( x_i, 2 ) ) + ( cValue * x_i ) );

}
