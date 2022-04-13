/* Euler Method */

#include<stdio.h>
#include<math.h>
#include<conio.h>
float F(float,float);
void elu(float,float,float,float);

int main()
{
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
	elu(x,y,xp,h);
	getch();
	return 0;
}
void elu(float x, float y, float xp, float h)
{
	int i,n;
	float dy;
	n=(int)(xp-x)/h;
	printf("\n******* EULER METHOD *******\n");
	printf("steps\t\tX\t\tY\n");
	for(i=1;i<=n;i++)
	{
		dy=h*F(x,y);
		x=x+h;
		y=y+dy;
		printf("%5d\t%10.6f\t%10.6f\n",i,x,y);
	}
	printf("\nfinal result value of y(x=%f) =\t%f \nn = %d",x,y,n);
}

 float F(float x,float y)
 {
	float f;
	f=(x-y)/3;//f=2.0*y/x;
	return f;
 }

/* x=1.0; y=2.0; xp=2.0; h=0.25   ans:=7.2 */
