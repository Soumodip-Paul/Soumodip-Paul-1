/* Regula Falsi Method Program */

#include <stdio.h>
#include<math.h>
//#define F(x) (x)*(x)+(x)-2
#define F(x) (x)*(x)*(x)-18
#define EPS 0.3005

float x1,x2,x0,f0,f1,f2;
int itr;     // count for iterations

void read_check(); //function for reading inputs and checking for validity
float regulaFalsi(float x1, float x2 ); // function for regula falsi method

void main(void)
{

read_check();
printf("\nroot=%f",regulaFalsi(x1,x2));
printf("\niteration=%d",itr);

}

/* function for input */
void read_check()
{

	while(1)
	{
		printf("\n enter x1=");
		scanf("%f",&x1);
		printf(" enter x2=");
		scanf("%f",&x2);
		f1=F(x1);
		f2=F(x2);
		if(f1*f2 > 0)
		{ 
			printf("\nsorry wrong input\nrenter your data-->");			
			continue;
		}
		else 
			break;
	}
}

float regulaFalsi(float x1,float x2)
{       
	itr=0;
	while(1)
	{
		itr++;
		f1=F(x1), f2=F(x2); 
		x0=((x1*f2)-(x2*f1))/(f2-f1); 
		f0=F(x0);    
		if (f0 == 0) 
			return x0;
		if (f1*f0 < 0)  
		{	x2=x0; f2=f0;}
		else 
		{
			x1=x0;f1=f0;
		}
 //       printf("Diff=%f   x0=%f   f0=%f  f1=%f  f2=%f\n",x2-x1, x0,f0,f1,f2); getch();
		if(fabs(x2-x1) < EPS) 
			return x0;
	}
}

//x1=2, x2=3, root=2.6207