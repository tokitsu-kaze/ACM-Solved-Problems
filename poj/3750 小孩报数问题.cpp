#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#include <list> 
#include <iomanip>
#define mem(a,b) memset(a,b,sizeof(a))
#define pi acos(-1.0) 
using namespace std;
typedef long long ll;
struct children
{
	char name[21];
}kid[101];
int main()
{
	int i,n,w,s;
	list<int> m;
    list<int>::iterator l,del;
    while(cin>>n)
    {
		m.clear();
		for(i=1;i<=n;i++)
		{
			cin>>kid[i].name;
			m.push_back(i);
		}
		scanf("%d,%d",&w,&s);
		l=m.begin();
		for(i=0;i<w-1;i++)
		{
			++l;
		}
		while(m.size()>1)
		{
			for(i=0;i<s-1;i++)
			{
				if(++l==m.end()) l=m.begin();
			}
			del=l;
			if(++l==m.end()) l=m.begin();
			cout<<kid[*del].name<<endl;
			m.erase(del);
		}
		cout<<kid[*l].name<<endl;
	}
    return 0;
}