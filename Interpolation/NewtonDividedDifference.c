#include<stdio.h>

float *getCoefficients(float *xi, float *fi, int length)
{
    float ftemp[length];
    for (int i = 0; i < length ; i++){
        if (i == 0) {
            ftemp[i] = fi[i];
            continue;
        }
        for (int j = i; j < length; j++){
            float delx = (xi[j] - xi[j-i]);
            float delf = (fi[j] - fi[j-1]);
            ftemp[j] = delf / delx;
        }
        for (int i = 1; i < length; i++){
            fi[i] = ftemp[i];
        }
    }
    return fi;
}

float dividedDifference(float *xirev, float *birev, int length, float point)
{
    if (length == 1) return birev[0];
    return dividedDifference(xirev,birev,length-1,point) * (point - xirev[length - 1]) + birev[ length - 1 ];
}

void printArray(float *arr, int length)
{
    for (int i = 0 ; i < length; i++){
        printf("%.2f\t",arr[i]);
    }
    printf("\n");
}

void rvereseArray(float arr[], int start, int end)
{
   float temp;
   if (start >= end)
     return;
   temp = arr[start];  
   arr[start] = arr[end];
   arr[end] = temp;
   rvereseArray(arr, start+1, end-1);  
}    

float getValue(float *xi,float *fi, int length, float xval)
{
    float *coeffs = getCoefficients(xi,fi,length);
    rvereseArray(xi,0,length-1);
    rvereseArray(coeffs,0,length-1);
    printf("Calculating ...\n");
    float fval = dividedDifference(xi,coeffs,length,xval);
    printf("Done \nValue of f(%.2f) is %.2f",xval,fval);
    return fval;
} 

int main(int argc, char const *argv[])
{
    printf("Welcome to Newtons divided difference method\nEnter the number of sample data points:\n");
    int number = 0;
    scanf("%d", &number);
    printf("Enter your xi and fi values seprated by space\nlike\n2\t3\n300\t4\n...\nLike this:\nxi\tfi\n");
    float xi[number], fi[number];
    for (int i = 0; i< number; i++) {
        scanf("%f %f", xi + i, fi + i);
    }
      
    printf("Input value of x for which you want to retrive the value: ");
    float xval = 0;
    scanf("%f",&xval);
    getValue(xi,fi,number,xval);
    return 0;
}
