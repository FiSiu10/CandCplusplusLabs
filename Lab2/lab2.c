
/* 
 * Calculate the terminal velocity of a falling object as well as it's
 * velocity at time step intervals
 * 
 * File:   lab2.c
 * Author: fionasiu
 *
 * Created on January 16, 2018, 2:34 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 
 */
int main(void) {

    double drag, area, mass, size, time, i, vi, g, height, density, terminalVelocity, fg, fd, fnet, vf, a;
    g = 9.80667;
    density = 1.2754;

    //Prompt drop height, drag coefficient, cross-sectional area, time-step size
    printf("Enter the height in metres: ");
    scanf("%lf", &height);

    printf("Enter the mass in kg: ");
    scanf("%lf", &mass);

    printf("Enter the drag coefficient: ");
    scanf("%lf", &drag);

    printf("Enter the cross-sectional area: ");
    scanf("%lf", &area);

    printf("Enter the time step size: ");
    scanf("%lf", &size);

    printf("      Time      Height        Velocity");
    printf("\n%10.2lf  %10.1lf  %10.1lf", time, height, vi);

    //initial velocity is calculated
    vi = g*time;

    //calculate force of gravity
    fg = mass*g;

    //iterate to a 1000000
    for (i = 0; i < 1000000; i++) {
        time += size;
        vi = vf;

        //calculate drag force
        fd = (-0.5) * drag * density * area * (vf * vf);


        //calculate final velocity 
        fnet = fd + fg;
        a = fnet / mass;
        vf = vi + a;

        height -= vf;

        if (height < 0) {
            break;
        }
        printf("\n%10.2lf  %10.1lf  %10.1lf", time, height, vf);
    }

    //calculate terminal velocity
    terminalVelocity = sqrt((2 * mass * g) / (drag * density * area));
    printf("\nTheoretical terminal velocity is %4.1lf m/s", terminalVelocity);
    return (EXIT_SUCCESS);
}

