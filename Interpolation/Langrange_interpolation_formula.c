// Lagrange Method

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

float LagrangeValue(float *,float *,int,float);

int main()
{
	system("cls");
    printf("Welcome to Newtons divided difference method\nEnter the number of sample data points:\n");
    int number = 0;
    scanf("%d", &number);
    if (number <= 0) {
        printf("enter a valid number\n");
        return -1;
    }
    printf("Enter your xi and fi values seprated by space\nlike\n2\t3\n300\t4\n...\nLike this:\nxi\tfi\n");
    float xi[number], fi[number];
    for (int i = 0; i< number; i++) {
        scanf("%f %f", xi + i, fi + i);
    }
      
    printf("Input value of x for which you want to retrive the value: ");
    float xval = 0;
    scanf("%f",&xval);
    LagrangeValue(xi,fi,number,xval);
	getch();
    return 0;
}

float LagrangeValue(float *xi,float *fi, int length, float point){
    float value = 0;
    clock_t t = clock();
    printf("Calculating ...\n");
    for (int i = 0; i < length; i++) {
        float coeff = 1;
        for (int j= 0; j < length; j++) {
            if (i == j) continue;
            coeff = coeff * (point - xi[j])/(xi[i]-xi[j]);
        }
        value = value + coeff * fi[i];
    }
    t = clock() - t;
    double time_taken = ((double)t) /CLOCKS_PER_SEC;
    printf("Done in %f seconds \nValue of f(%.2f) is %.2f",time_taken,point,value);
    return value;
}

