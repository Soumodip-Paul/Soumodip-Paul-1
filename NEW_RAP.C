/* Newton Raphson Method Program */

#include <stdio.h>
#include<math.h>
//#define F(x) (x)*(x)+(x)-2
#define F(x) (x)*(x)*(x)-18
#define FD(x) 2*(x)*(x)
#define EPS 0.00005

//float x1,x0,f0,fd0;
int itr;     // count for iterations

float new_rap(float ); // function for Newton Raphson method

void main(void) {
float x0;
//clrscr();
printf(" enter the value of initial guess=");
scanf("%f",&x0);
printf("\nroot=%f",new_rap(x0));
printf("\niteration=%d",itr);
//getch();
}

	float new_rap(float x0)
	{       float x1,f0,fd0;
		itr=0;
		while(1)
		{

			itr++;
			f0=F(x0);
			fd0=FD(x0);
			x1=x0-(f0/fd0);
			printf ("\nitr=%d x0=%f x1=%f",itr,x0,x1);
			if (fabs((x1-x0)/x1) <= EPS) return x1;
			else x0=x1;
		}
	}