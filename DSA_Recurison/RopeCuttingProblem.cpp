#include <iostream>
using namespace std;

int max(int a, int b, int c)
{
    if (a > b)
    {
        if (a > c)
            return a;
        else
            return c;
    }

    else{
        if (b > c)
            return b;

        else
            return c;

    }
}
    
int maxpiece(int l, int a, int b, int c)
{
    int r;
    if (l == 0) 
        return 0;

    if (l<0)
        return -1;
        
    r = max(maxpiece(l-a, a, b, c), maxpiece(l-b, a, b, c), maxpiece(l-c, a, b, c));
    
    if (r == -1)
        return -1;
    
    return r + 1;

}
    

int main(){
    
    int n = 23 , a = 11 , b = 9 , c = 12;

    cout<<maxpiece(n,a,b,c); 

}