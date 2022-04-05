/* Bisection Method Program */

#include <stdio.h>
#include<math.h>
//#define F(x) (x)*(x)+(x)-2
#define F(x) (x)*(x)*(x)-8
#define EPS 0.000001

float x1,x2,x0,f0,f1,f2;
int itr;     // count for iterations

void read_check(); //function for reading inputs and checking for validity
float bisec(float x1, float x2 ); // function for bisection method

int main()
{

read_check();
if (f1 == 0 || f2 == 0 ){
	printf("\nroot=%f", f1 == 0 ? x1 : x2 );
	return 0;
}
printf("\nroot=%f",bisec(x1,x2));
printf("\niteration=%d",itr);

return 0;
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
			printf("\nsorry wrong input\nenter your data-->");			
			continue;
		}
		else 
			break;
	}
}

float bisec(float x1,float x2)
{       
	itr=0;
	while(1)
	{
		itr++;
		x0=(x1+x2)/2.0;
		f0=F(x0);
		if (f0 == 0) 
			return x0;
		if (f1*f0 < 0)  
			x2=x0;
		else 
		{
			x1=x0;f1=f0;
		}

		if(fabs((x2-x1)/x2) < EPS) 
			return (x1+x2)/2;
	}
}

//x1=2, x2=3, root=2.6207