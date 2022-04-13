/* Secant Method Program */

#include <stdio.h>
#include<math.h>
#include<conio.h>
//#define F(x) (x)*(x)+(x)-2
#define F(x) (x)*(x)*(x)-18
#define EPS 0.00005

//float x1,x0,f0,fd0;
int itr;     // count for iterations

float secant(float , float ); // function for Secant method

int main(void) 
{
float x0,x1;
system("cls");
printf(" enter the value of initial guess=");
scanf("%f %f",&x0,&x1);
printf("\nroot=%f",secant(x0,x1));
printf("\niteration=%d",itr);
getch();
return 0;
}

	float secant(float x0,float x1)
	{       
		float x2,f0,f1,f2;
		itr=0;
		while(1)
		{       
			itr++;
			f0=F(x0);
			f1=F(x1);
			x2=(f1*x0-f0*x1)/(f1-f0);
			printf ("\nitr=%d x1=%f x2=%f",itr,x1,x2);
			if (fabs((x2-x1)/x2) <= EPS) 
				return x2;
			else 
			{ 
				x0=x1;
				f0=f1;
				x1=x2;
				f1=F(x2); 
			}
		}
	}