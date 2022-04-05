/* JACOBIIterative method for linear system solution */

#include<stdio.h>
#include<math.h>
#define EPS 0.000001

float a[10][10],b[10],x[10];
int n;
void jacobi_f(int ,float [10][10],float [10],float [10]);

void main(void) {

int i,j;
clrscr();
printf("\nplease enter the size of the system=");
scanf("%d",&n);
printf("\nenter the co-efficients row wise-->\n");
for(i=1;i<=n;i++)
	for(j=1;j<=n;j++) scanf("%f",&a[i][j]);
printf("enter the R.H.S-->\n");
for (i=1;i<=n;i++) scanf("%f",&b[i]);
  jacobi_f(n,a,b,x);
getch();
}

void jacobi_f(int n,float a[10][10],float b[10],float x[10])
{
	int i,j,flag,count=0,it=50;
	float sum,x0[10];
	// initial value
	for(i=1;i<=n;i++)  x0[i]=b[i]/a[i][i];

	do {
		count++; //number of iterations
		flag=0;

		for(i=1;i<=n;i++)
		{ 	sum=b[i];
			for(j=1;j<=n;j++)
			{       if(i!=j) sum=sum-(a[i][j]*x0[j]);
			}
			x[i]=sum/a[i][i];
			printf("\n%d X[%d]=%f",count,i,x[i]);
		}
			// testing for accuracy
			for(i=1;i<=n;i++)
			{if(fabs((x[i]-x0[i])/x[i]) > EPS) flag=1;}

			if(flag==1)
				{
			if(count==it) { printf(" no convergence in %d iteration",count);
					return;
					}
			else {
		       for(i=1;i<=n;i++) x0[i]=x[i];}
			}
	    }while(flag);
	    printf(" \n\nSolution -->\n");
 for(i=1;i<=n;i++) printf("\nX[%d]=%f",i,x[i]);
 }
 /*
    a===> 1 1 -1
	  -1 3 0
	  1 0 -2

    b===> [0,2,-3]
    x===>[1,1,2]
    17 iterations

 */



