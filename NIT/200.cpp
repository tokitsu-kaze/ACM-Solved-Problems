#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int a[1111][1111];
int main()
{
	int t,n,i,j,k,m,flag,now,cnt;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		m=n+2;
		mem(a,0);
		now=10;
		for(i=0,j=n+1,k=0;k<m;i++,j++,k++)
		{
			a[i][j]=now;
			now++;
			if(now>10) now=1;
		}
		i--;
		j--;
		m--;
		while(m)
		{
			for(j=j-2,k=0;k<m;k++,j-=2)
			{
				a[i][j]=now;
				now++;
				if(now>10) now=1;
			}
			j+=2;
			m--;
			if(!m) break;
			for(i=i-1,j=j+1,k=0;k<m;k++,i--,j++)
			{
				a[i][j]=now;
				now++;
				if(now>10) now=1;
			}
			i++;
			j--;
			m--;
			if(!m) break;
			for(i=i+1,j=j+1,k=0;k<m;k++,i++,j++)
			{
				a[i][j]=now;
				now++;
				if(now>10) now=1;
			}
			i--;
			j--;
			m--;
		}
		int temp=n+2;
		for(i=0;i<n+2;i++)
		{
			for(j=0;j<temp;j++)
			{
				if(a[i][j]==10) printf("0");
				else if(a[i][j]) printf("%d",a[i][j]);
				else printf(" ");
			}
			puts("");
			temp++;
		}
		mem(a,0);
		cnt=0;
		for(i=0,j=0;j<n;j++)
		{
			cnt++;
			a[i][j]=now;
			now++;
			if(now>10) now=1;
		}
		j--;
		temp=n-1;
		while(cnt<n*n)
		{
			i++;
			for(k=0;k<temp;k++,i++)
			{
				cnt++;
				a[i][j]=now;
				now++;
				if(now>10) now=1;
			}
			i--;
			j--;
			for(k=0;k<temp;k++,j--)
			{
				cnt++;
				a[i][j]=now;
				now++;
				if(now>10) now=1;
			}
			j++;
			i--;
			temp--;
			for(k=0;k<temp;k++,i--)
			{
				cnt++;
				a[i][j]=now;
				now++;
				if(now>10) now=1;
			}
			i++;
			j++;
			for(k=0;k<temp;k++,j++)
			{
				cnt++;
				a[i][j]=now;
				now++;
				if(now>10) now=1;
			}
			j--;
			temp--;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<2;j++)
			{
				putchar(' ');
			}
			for(j=0;j<n;j++)
			{
				if(a[i][j]==10) a[i][j]=0;
				if(!j) printf("%d",a[i][j]);
				else printf(" %d",a[i][j]);
			}
			puts("");
		}
	}
	return 0;
}