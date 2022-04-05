/* Trapezoidal for Integration */

#include<stdio.h>
#include<math.h>
float F(float );
void trape(float,float,float);
void main()
{

	float a,b,h;
	clrscr();
	printf("\nEnter the initial value of x=");
	scanf("%f",&a);
	printf("\nEnter the final value of x=");
	scanf("%f",&b);
	printf("\nEnter the segment width=");
	scanf("%f",&h);
	trape(a,b,h);
	getch();
}

void trape(float a,float b,float h)
{
	int i,n;
	float sum,itg;
	n=(b-a)/h;
	sum=(F(a)+F(b))/2.0;
	for(i=1;i<=n-1;i++) sum=sum+F(a+i*h);
	itg=sum*h;
	printf("\nIntegration between %f and %f when h=%f is %f",a,b,h,itg);
	getch();
}

float F(float x)
{
	float f;
	f=1.0-exp(-x/2.0);
	return f;
 }

/* a=0.0; b=0.0; h=0.5; itg=8.0031400 */
