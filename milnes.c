#include<stdio.h>

float Y(float X, float Y);

void main(){
    float x[100], y[100], h, X, F, P, C;
    int i, j, k, n, m;

    printf("how many values:");
    scanf("%d", &n);

    printf("enter x and y values:\n");
    i = 0; 
    while(i<n){
        scanf("%f %f", &x[i], &y[i]);
        i++; 
    }

    printf("\n \t X \t\t Y \n");
    for(j=0; j<n; j++){
        F = Y(x[j], y[j]);
        printf("\n X%d = %.2f \t Y%d = %.4f \t y(%d)' = %.4f \n", j, x[j], j, y[j], j, F);
    }

    h = x[1] - x[0];

    // predictior formula
    printf("enter X4 value: ");
    scanf("%f", &x[4]);
    P = y[0] + ((4*h)/3) * ( 2 * Y(x[1], y[1]) - Y(x[2], y[2]) + 2 * Y(x[3], y[3]) - 9 * Y(x[0], y[0]));
    printf("Y(4)p = %.4f \n", P);
    P = Y(x[4], P);
    printf("Y(4)'= %.4f \n", P);
    y[4] = P;
    C = P; 

    //corrector formula
    printf("enter the number of iteration to be performed:");
    scanf("%d", &m);
    for(k=0; k<=m; k++){
        C = y[2] + (h/3) * ( Y(x[2], y[2]) +4 * Y(x[3], y[3]) + Y(x[4], y[4]) );
        printf("Y(4)c = %.4f\n", C);
        C = Y(x[4], C);
        printf("iteration (%d): \nY(4)' = %.4f\n",k+2, C);
        y[4] = C;
        
    }
}

float Y(float X, float Y){
    float z;
    z = ((X*Y) + (Y*Y));
    return z; 
}
