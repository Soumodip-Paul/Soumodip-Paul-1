/* Simpson1/3 for Integration */

#include<stdio.h>
#include<math.h>
float F(float );
void simp(float,float,int);

void main()
{
	int n;
	float a,b;
	clrscr();
	printf("\nEnter the initial value of x=");
	scanf("%f",&a);
	printf("\nEnter the final value of x=");
	scanf("%f",&b);
	printf("\nEnter the number of segments(even no.)=");
	scanf("%d",&n);
	simp(a,b,n);
	getch();
}
void simp(float a, float b, int n)
{
	int i,m;
	float h,sum=0.0,itg,x,f1,f2,f3;
	h=(float)(b-a)/n;
	m=n/2;
	x=a;
	f1=F(x);
	for(i=1;i<=m;i++)
	{       f2=F(x+h);
		f3=F(x+2*h);
		sum=sum+f1+4*f2+f3;
		f1=f3;
		x=x+2*h;
	}
	itg=sum*h/3.0;
	printf("\nIntegration between %f and %f when h=%f is %f",a,b,h,itg);
}

 float F(float x)
 {
	float f;
	f=1.0-exp(-x/2.0);
	return f;
 }

/* a=0.0; b=10.0; n=20; itg=8.0134330 */
