#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int method0 ( int *A, int n )
{
//your method should return 1 on success, and 0 on failure
//write code for method 0 to solve this probelm
    for(int a=1; a<=n-2;a++){
        for(int b=a+1; b<=n-1;b++){
            for (int c = b+1; c<=n; c++){
                int i,j,k;
                for(int ind =0 ;ind<n;ind++){
                    if(A[ind]==c)
                        i=ind;
                    if(A[ind]==a)
                        j=ind;
                    if(A[ind]==b)
                        k=ind;
                }
                if(i<j&&i<k&&j<k){
                    return 0;
                }
            }
            
        }
    }
    return 1;
}

int method1 ( int *A, int n )
{
//your method should return 1 on success, and 0 on failure
//write code for method 1 to solve this probelm
for (int i = 0; i < n-2; i++){
    for(int j=i+1; j <n-1; j++){
        for (int k = j+1; k < n; k++){
            int c=A[i];
            int a=A[j];
            int b=A[k];
            if(a<b && a<c && b<c)
                return 0;
        }
    }
}
return 1;
}

int method2 ( int *A, int n )
{
//your method should return 1 on success, and 0 on failure
//write code for method 2 to solve this probelm
    for (int i = 1; i < n; i++){
        int last=A[i];
        for(int j=i+1; j<n;j++){
          if(A[i]>A[j]){
            if(A[j]>last)
                return 0;
            last=A[j];
          }  
        }
    }
    return 1;
    
}

int method3 ( int *A, int n )
{

//your method should return 1 on success, and 0 on failure
//write an O(n) method to solve this probelm
//hint: you may look into the stack concept
    int max = A[0];
    for(int i = 1; i<n ; i++){
        if(A[i]<A[i-1]){
            continue;
        }else{
            if(A[i]>max){
                max = A[i];
                continue;
            }else{
                return 0;
            }
        }
    }
    return 1;
}

int main ( int argc, char *argv[] )
{
   int i, n, *A, *B;
    clock_t start, end;
    double cpu_time_used;
   //scan the input
   scanf("%d", &n);
   A = (int*) malloc (sizeof(int)*n);
   for (i=0; i<n; ++i) scanf(" %d", &A[i]);

    printf("\n");
    start = clock();
    printf("Method 0: %s\n", method0(A,n) ? "Valid" : "Invalid");
    end = clock();
    cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;
    printf("Method 0 took %f seconds to execute \n", cpu_time_used);
    
    start = clock();
    printf("Method 1: %s\n", method1(A,n) ? "Valid" : "Invalid");
    end = clock();
    cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;
    printf("Method 1 took %f seconds to execute \n", cpu_time_used);
    
    start = clock();
    printf("    Method 2: %s\n", method2(A,n) ? "Valid" : "Invalid");
    end = clock();
    cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;
    printf("Method 2 took %f seconds to execute \n", cpu_time_used);

    start = clock();
    printf("    Method 3: %s\n", method3(A,n) ? "Valid" : "Invalid");
    end = clock();
    cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;
    printf("Method 3 took %f seconds to execute \n", cpu_time_used);

    // printf("    Method 1: %s\n", method1(A,n) ? "Valid" : "Invalid");
    // printf("    Method 2: %s\n", method2(A,n) ? "Valid" : "Invalid");
    // printf("    Method 3: %s\n", method3(A,n) ? "Valid" : "Invalid");

   exit(0);
}