/* Trapezoidal for Integration */

#include<stdio.h>
#include<math.h>
#include<conio.h>
float F(float );
void trape(float,float,float);
int main()
{

	float a,b,h;
	system("cls");
	printf("\nEnter the initial value of x=");
	scanf("%f",&a);
	printf("\nEnter the final value of x=");
	scanf("%f",&b);
	printf("\nEnter the segment width=");
	scanf("%f",&h);
	trape(a,b,h);
	getch();
	return 0;
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
	f= powf(4/M_PI, 0.5) * exp(-(x * x));
	return f;
 }

/* a=0.0; b=0.0; h=0.5; itg=8.0031400 */
