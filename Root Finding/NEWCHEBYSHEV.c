/* Newton Raphson Method Program */

#include <stdio.h>
#include<math.h>
//#define F(x) (x)*(x)+(x)-2
#define F(x) 1/x-7
#define FD(x) -1/(x*x)
#define FD1(x) 2/(x*x*x)
#define EPS 0.000005

//float x1,x0,f0,fd0;
int itr;     // count for iterations

float new_rap(float ); // function for Newton Raphson method

void main(void) 
{
	float x0;
	printf(" enter the value of initial guess=");
	scanf("%f",&x0);
	printf("\nroot=%f",new_rap(x0));
	printf("\niteration=%d",itr);
}

float new_rap(float x0)
{       
	float x1,f0,fd0,fd1;
	itr=0;
	while(1)
	{
		itr++;
		f0=F(x0);
		fd0=FD(x0);
		fd1=FD1(x0);
		x1=x0-(f0/fd0)-(f0*f0*fd1)/(2*fd0*fd0*fd0); 
		printf ("\nitr=%d x0=%f x1=%f",itr,x0,x1);
		if (fabs((x1-x0)/x1) <= EPS) 
			return x1;
		else x0=x1;
	}
}