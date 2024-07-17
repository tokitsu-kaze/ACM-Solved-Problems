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
const int MAX=2e5+10;
const ll mod=1e9+7;

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        string res;
        int i;
        double d=0.01*(100-discount);
        for(i=0;i<sz(sentence);i++)
        {
            if(sentence[i]=='$'&&(!sz(res)||res.back()==' '))
            {
                res+=sentence[i];
                int j=i+1;
                int ok=1;
                ll now=-1;
                
                while(j<sz(sentence)&&sentence[j]!=' ')
                {
                    if(sentence[j]>='0'&&sentence[j]<='9');
                    else ok=0;
                    j++;
                }
                if(!ok)
                {
                    i++;
                    while(i<sz(sentence)&&sentence[i]!=' ')
                    {
                        res+=sentence[i];
                        i++;
                    }
                    i--;
                    continue;
                }
                
                j=i+1;
                while(j<sz(sentence)&&sentence[j]!=' ')
                {
                    if(sentence[j]>='0'&&sentence[j]<='9')
                    {
                        if(now==-1) now=sentence[j]-'0';
                        else now=now*10+sentence[j]-'0';
                    }
                    j++;
                }
                if(now!=-1)
                {
                    i=j-1;
                    char s[33];
                    sprintf(s,"%.2f",now*d);
                    res+=s;
                }
                else
                {
                    i++;
                    while(i<sz(sentence)&&sentence[i]!=' ')
                    {
                        res+=sentence[i];
                        i++;
                    }
                    i--;
                }
                
            }
            else res+=sentence[i];
        }
        return res;
    }
};
