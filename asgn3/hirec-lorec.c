#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double hirec(int n);
double lorec(int n);

typedef struct {
   double hi;
   double lo;
} two_val;

///////////////////
// int fib(int n)
// {
//     if (n <= 1)
//         return n;
//     return fib(n - 1) + fib(n - 2);
// }
int fib(int n)
{
    int a = 0, b = 1, c, i;
    if( n == 0)
        return a;
    for(i = 2; i <= n; i++)
    {
       c = a + b;
       a = b;
       b = c;
    }
    return b;
}
// //////////////////

double hirec ( int n )
{
//complete the code
    double one=1;
    if (n == 0) 
        return one;
    return 2 * hirec(n-1) + lorec(n-1);
}

double lorec ( int n )
{
//complete the code
    double zero=0;
    if (n == 0) 
        return zero;
    return hirec(n-1) + lorec(n-1);
}

two_val hilorec ( int n )
{
    two_val N;
    if (n == 0){
        two_val base;
        base.hi=1;
        base.lo=0;
        return base;
    }
    N = hilorec(n-1);
    two_val ans;
    ans.hi=2 * N.hi + N.lo;
    ans.lo=N.hi + N.lo;
    return ans;
}

two_val hiloformula ( int n )
{
   two_val N;

   N.hi = ((5+sqrt(5))/10) * pow((3-sqrt(5))/2,n+1) + ((5-sqrt(5))/10) * pow((3+sqrt(5))/2,n+1);
   N.lo = ((-5-3*sqrt(5))/10) * pow((3-sqrt(5))/2,n+1) + ((-5+3*sqrt(5))/10) * pow((3+sqrt(5))/2,n+1);
   return N;
}

int main ( int argc, char *argv[] )
{
   two_val N1, N2, N3;
   int n;

   clock_t start, end;
   double cpu_time_used;

   scanf("%d", &n);
   printf("n = %d\n", n);

	printf("\n+++ Method 0\n");
    start = clock();
    N1.hi = hirec(n); N1.lo = lorec(n);
    end = clock();
    printf("    hi(%d) = %.10le, lo(%d) = %.10le\n", n, N1.hi, n, N1.lo);
    cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;
    printf("Method 0 took %f seconds to execute \n", cpu_time_used);
    
   printf("\n+++ Method 1\n");
   start = clock();
   N2 = hilorec(n);
   end = clock();
   printf("    hi(%d) = %.10le, lo(%d) = %.10le\n", n, N2.hi, n, N2.lo);
   cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;
   printf("Method 1 took %f seconds to execute \n", cpu_time_used);

   printf("\n+++ Method 2\n");
   start = clock();
   N3 = hiloformula(n);
   end = clock();
   printf("    hi(%d) = %.10le, lo(%d) = %.10le\n", n, N3.hi, n, N3.lo);
   cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;
   printf("Method 2 took %f seconds to execute \n", cpu_time_used);

   exit(0);
}