#include <stdio.h>
int fat_rec(int n)
{
    if (n <= 1)
        return 1;
    if (n > 1)
        return n * fat_rec(n-1);
}
int fat(int n)
{
    int fat = 1;
    for ( int i = 1; i <= n ; i++)
    {
        fat = fat * i;
    }
    return fat;
}
int main ()
{
    int n = 5;
    int res = fat(n);
    printf("%d\n",res);
    return 0;
}