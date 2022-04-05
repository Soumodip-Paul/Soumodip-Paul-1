/* Gauss Elimination Basic Method */

#include<stdio.h>
#include<math.h>

int flag;

void gauss(int ,float [10][10],float [10],float [10]);
void elimination(int ,float [10][10],float [10]);
void backsubs(int,float [10][10],float [10],float [10]);

void main(void) {

int n,i,j;
float a[10][10],b[10],x[10];
//clrscr();
printf("\nplease enter the size of the system=");
scanf("%d",&n);
printf("\nenter the co-efficients row wise-->\n");
for(i=1;i<=n;i++)
	for(j=1;j<=n;j++) 
		scanf("%f",&a[i][j]);
printf("enter the R.H.S-->\n");
for (i=1;i<=n;i++) 
	scanf("%f",&b[i]);
 gauss(n,a,b,x);
if(flag !=0) 
	{ 
		printf("\n Solution of this System -->\n");
	    for(i=1;i<=n;i++) 
			printf("x%d=%f\n",i,x[i]);
	}
else printf("singular matrix reorder eqn\n");
//getch();
}

void gauss(int n,float a[10][10],float b[10],float x[10])
{
	elimination(n,a,b);
	backsubs(n,a,b,x);
	return;
}

void elimination(int n,float a[10][10],float b[10])
{
	int i,j,k;
	float pivot,factor;
	// elimination begins
	for(k=1;k<=n-1;k++)
	{
		pivot=a[k][k];
		if(pivot< 0.000001) { flag=0; return;}
		flag=1;
		for(i=k+1;i<=n;i++)
		{ 
			factor=a[i][k]/pivot;
			for(j=k+1;j<=n;j++) 
				a[i][j]=a[i][j]-factor*a[k][j];
		b[i]=b[i]-factor*b[k];
		}
	}
	return;
}

void backsubs(int n,float a[10][10],float b[10],float x[10])
{
	int j,k;
	float sum;
	//back substitution
	x[n]=b[n]/a[n][n];
	for(k=n-1;k>=1;k--)
		{	sum=0.0;
			for(j=k+1;j<=n;j++) sum=sum+a[k][j]*x[j];
			x[k]=(b[k]-sum)/a[k][k];
		}
	return;
}

