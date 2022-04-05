/* Gauss Elimination Pivoting method  */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 10

void gaussp(int ,float [10][10],float [10],float [10]);

void main(void) {

int n,i,j,ch;
float a[N][N],b[N],x[N];
clrscr();
n=N;
printf("\nThe size of the system=%d",n);
/*
printf("\nenter the co-efficients row wise-->\n");
for(i=1;i<=n;i++)
	for(j=1;j<=n;j++) scanf("%f",&a[i][j]);
printf("enter the R.H.S-->\n");
for (i=1;i<=n;i++) scanf("%f",&b[i]);
  gaussp(n,a,b,x);*/

for(i=1;i<=N;i++)
	b[i]=rand()%N;

for(i=1;i<=N; i++)
{	for(j=1;j<=N;j++)
		a[i][j]=rand()%N;
 }

printf("\co-efficients -->\n");
for(i=1;i<=n;i++)
      {	for(j=1;j<=n;j++) printf("%f",a[i][j]);}
printf("R.H.S-->\n");
for (i=1;i<=n;i++) printf("%f",b[i]);

gaussp(n,a,b,x);

printf("\n Solution of this System--->\n");
for(i=1;i<=n;i++) printf("x%d=%f\n",i,x[i]);
getch();
}

void gaussp(int n,float a[N][N],float b[N],float x[N])
{
	int i,j,k,p,m;
	float factor,sum,l,temp;

	// find pivot p

//add openmp directives

	for(k=1;k<=n-1;k++)
	{  	p=k;
		l=fabs(a[k][k]);
		for(i=k+1;i<=n;i++)
			{
			if(fabs(a[i][k]>l))
				{ l=fabs(a[i][k]);
				  p=i;
				}
			}
		//exchange rows p & k
		if(p!=k)
		{
		    for(j=k;j<=n;j++)
		    { 	temp=a[p][j];a[p][j]=a[k][j];a[k][j]=temp;}
		    temp=b[p];b[p]=b[k];b[k]=temp;
		}


	       //elimination
	       for(i=k+1;i<=n;i++)
		{ factor=a[i][k]/a[k][k];
		for(j=k+1;j<=n;j++) a[i][j]=a[i][j]-factor*a[k][j];
		b[i]=b[i]-factor*b[k];
		}

	}
	//back substitution

//add openmp directives and dump profiler data

	 x[n]=b[n]/a[n][n];
	for(k=n-1;k>=1;k--)
	{	sum=0.0;
		for(j=k+1;j<=n;j++) sum=sum+a[k][j]*x[j];
		x[k]=(b[k]-sum)/a[k][k];
	}
	return;
   }

