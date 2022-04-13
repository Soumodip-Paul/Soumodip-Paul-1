/* Runga kutta 4th order Method */

#include<stdio.h>
#include<math.h>
#include<conio.h>
float F(float,float);
void rung(float,float,float,float);

void main()
{
	int n;
	float x,y,xp,h;
	system("cls");
	printf("\nEnter the initial value of x=");
	scanf("%f",&x);
	printf("\nEnter the initial value of y=");
	scanf("%f",&y);
	printf("\nEnter the value of x at which y is required=");
	scanf("%f",&xp);
	printf("\nEnter the step size h=");
	scanf("%f",&h);
	rung(x,y,xp,h);
	getch();
}
void rung(float x, float y, float xp, float h)
{
	int i,n;
	float m1,m2,m3,m4;
	n=(int)(xp-x)/h;
	printf("\n******* RUNGA-KUTTA 4th ORDER *******\n");
	printf("  steps\t\tX\t\tY\n");
	for(i=1;i<=n;i++)
	{
		m1=F(x,y);
		m2=F(x+0.5*h,y+0.5*m1*h);
		m3=F(x+0.5*h,y+0.5*m2*h);
		m4=F(x+h,y+m3*h);
		x=x+h;
		y=y+(m1+2.0*m2+2.0*m3+m4)*h/6.0;
		printf("%5d\t%10.6f\t%10.6f\n",i,x,y);
	}
	printf("\nfinal result value of y at x=%f is %f",x,y);
}

 float F(float x,float y)
 {
	float f;
	f=2.0*y/x;
	return f;
 }

/* x=1.0; y=2.0; xp=2.0; h=0.25   ans:=7.9 */
