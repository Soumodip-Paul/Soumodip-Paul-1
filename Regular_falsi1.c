   #include<stdio.h>
   #include<conio.h>
   #include<math.h>
   // #define ESP 0.01
   //x0=0 x1=2
   #define F(x) x*x*x*x - x - 10
   void main()
   {
    int i=0;
    float x0,x1,x2,f1,f2,f0,x4;
    //clrscr();
    do
    {
        printf("\nEnter the value of x0: ");
        scanf("%f",&x0);
    }
    while(F(x0) > 0);
    do
    {
        printf("\nEnter the value of x1: ");
        scanf("%f",&x1);
    }
    while(F(x1) < 0);
    printf("\n_______________________________________________________\n");
    printf("\n x0 x1 x2 f0 f1 f2");
    printf("\n_______________________________________________________\n");
    do
    {
        f0=F(x0);
        f1=F(x1);
        x2=x0-((f0*(x1-x0))/(f1-f0));
        f2=F(x2);
        printf("\n%f %f %f %f %f %f",x0,x1,x2,f0,f1,f2);
        if(f0*f2<0)
        {
            x1=x2;
        }
        else
        {
            x0 = x2;
        }
        i++;
    }
    while(i<10);
    x4=x0-((f0*(x1-x0))/(f1-f0));
    printf("\n______________________________________________________\n");
    printf("\n\nApp.root = %f",x4);
    
    getch();
  } 
     

