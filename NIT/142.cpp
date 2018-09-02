#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#include <iomanip>
using namespace std;
int gcd(int x,int y)
{
	if(!y) return x;
    else return x%y==0?y:gcd(y,x%y);
}
int main ()
{
    int a,b,c,d,e,f,s,count,x,y,z;
    while(cin>>a>>b>>c>>d>>e>>f)
    {
        s=abs((a*d+c*f+b*e-a*f-b*c-d*e)/2);
        x=gcd(abs(a-c),abs(b-d));
        y=gcd(abs(a-e),abs(b-f));
        z=gcd(abs(c-e),abs(d-f));
        count=s-(x+y+z)/2+1;
        cout<<count<<endl;
    }
    return 0;
}