#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int ask(int x,int y,int z)
{
	cout<<"? "<<x<<" "<<y<<" "<<z<<" "<<endl;
	int res;
	cin>>res;
	return res;
}
int a[MAX],b[MAX];
int main()
{
	int T,n,i,x,y,res,mx1,mx2,pos1,pos2,tmp;
	cin>>T;
	while(T--)
	{
		cin>>n;
		x=1;
		y=2;
		set<int> s1,s2;
		mx1=pos1=-1;
		for(i=1;i<=n;i++)
		{
			if(i==x || i==y) continue;
			res=ask(x,y,i);
			a[i]=res;
			if(res>mx1)
			{
				mx1=res;
				pos1=i;
			}
			s1.insert(res);
		}
		mx2=mx1;
		pos2=y;
		s2.insert(mx1);
		for(i=1;i<=n;i++)
		{
			if(i==x || i==pos1 || i==y) continue;
			res=ask(x,pos1,i);
			b[i]=res;
			if(res>=mx2)
			{
				mx2=res;
				pos2=i;
			}
			s2.insert(res);
		}
		while(pos2==y||pos2==pos1) pos2++;
		tmp=ask(2,pos1,pos2);
		if(s2.size()==1) cout<<"! "<<x<<" "<<pos1<<endl;
		else if((tmp<a[pos1]&&tmp<=a[pos2])||(tmp<=a[pos1]&&tmp<a[pos2]))
		{
			cout<<"! "<<x<<" "<<y<<endl;
		}
		else if(tmp==a[pos1]) cout<<"! "<<y<<" "<<pos1<<endl;
		else if(tmp==a[pos2]) cout<<"! "<<y<<" "<<pos2<<endl;
		else cout<<"! "<<pos1<<" "<<pos2<<endl;
	}
	return 0;
}

