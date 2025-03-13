#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int ask(int x,int y,int z)
{
	int res;
	cout<<"? "<<x<<" "<<y<<" "<<z<<endl;
	cin>>res;
	return res;
}
int main()
{
	srand(time(0));
	int T,n,i,res;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		vector<int> id;
		for(i=1;i<=n;i++) id.push_back(i);
		random_shuffle(id.begin(),id.end());
		while(1)
		{
			res=ask(id[0],id[1],id[2]);
			if(res==0)
			{
				cout<<"! "<<id[0]<<" "<<id[1]<<" "<<id[2]<<endl;
				break;
			}
			id[rand()%3]=res;
		}
	}
	return 0;
}
