#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII > VPII;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e4+10;
const ll mod=1e9+7;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
		int n,m,i,j,r;
		n=sz(matrix);
		m=sz(matrix[0]);
		vector<VI > bit(n,VI(m,0));
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				bit[i][j]+=matrix[i][j]-'0';
				if(i+1<n && matrix[i+1][j]-'0') bit[i+1][j]+=bit[i][j];
			}
		}
		VI st,l;
		int ans=0;
		for(i=0;i<n;i++)
		{
			l=VI(m,0);
			st.clear();
			for(j=0;j<m;j++)
			{
				while(sz(st)&&bit[i][st.back()]>=bit[i][j]) st.pop_back();
				if(sz(st)) l[j]=st.back()+1;
				else l[j]=0;
				st.pb(j);
			}
			st.clear();
			for(j=m-1;~j;j--)
			{
				while(sz(st)&&bit[i][st.back()]>=bit[i][j]) st.pop_back();
				if(sz(st)) r=st.back()-1;
				else r=m-1;
				st.pb(j);
				printf("%d %d %d %d %d\n",i,j,l[j],r,bit[i][j]);
				ans=max(ans,(r-l[j]+1)*bit[i][j]);
			}
		}
		return ans;
    }
};
