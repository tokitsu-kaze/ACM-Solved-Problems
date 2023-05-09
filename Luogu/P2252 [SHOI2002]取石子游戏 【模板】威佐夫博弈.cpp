#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    if(int(abs(n-m)*(sqrt(5.0)+1))/2==min(n,m)) printf("0\n");
    else printf("1\n");
    return 0;
}
