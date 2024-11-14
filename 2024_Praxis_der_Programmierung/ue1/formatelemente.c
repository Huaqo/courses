/* formatelemente.c
 *
 * ACHTUNG: Enthaelt Fehler, die Sie bereinigen sollen!
 * 
 */

#include <stdio.h>

int main(){
    int i = 66;
    double x = .000007;
    double y = 123.45;

    /* Printing the integer 'i' in various formats
    %d prints the integer in decimal format
    %o prints the integer in octal format
    %x prints the integer in hexadecimal (lowercase)
    %X prints the integer in hexadecimal (uppercase)*/
    printf("\ni:\n%d \n%o \n%x \n %X", i, i, i, i);

    // Printing the double 'x' in various formats
    // %f prints the double in fixed-point notation
    // %e prints the double in scientific notation (lowercase 'e')
    // %E prints the double in scientific notation (uppercase 'E')
    // %g prints the double in either %f or %e, whichever is shorter, removing trailing zeros
    // %G prints the double in either %f or %E, whichever is shorter, removing trailing zeros
    printf("\nx:\n%f \n%e \n%E \n%g \n%G", x, x, x, x, x);

    // Printing the double 'y' in a couple of formats
    // %g prints the double in either %f or %e, depending on which is shorter, removing trailing zeros
    // %G prints the double in either %f or %E, depending on which is shorter, removing trailing zeros
    printf("\ny:\n%g \n%G\n", y, y);

    // Print sentence
    printf("Ich kenne die Formatelemente zu 100 %%.\n");
    return 0;
}