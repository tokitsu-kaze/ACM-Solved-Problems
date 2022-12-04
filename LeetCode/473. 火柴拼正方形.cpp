
vector<int> v;
int ok;
void dfs(int x,int a,int b,int c,int d)
{
    if(ok) return;
    if(x==(int)v.size()&&!(a+b+c+d))
    {
        ok=1;
        return;
    }
    if(a>=v[x]) dfs(x+1,a-v[x],b,c,d);
    if(b>=v[x]) dfs(x+1,a,b-v[x],c,d);
    if(c>=v[x]) dfs(x+1,a,b,c-v[x],d);
    if(d>=v[x]) dfs(x+1,a,b,c,d-v[x]);
    if(v[x]>a&&v[x]>b&&v[x]>c&&v[x]>d) return;
}

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        for(auto it:matchsticks) sum+=it;
        if(sum%4!=0) return false;
        sum/=4;
        v=matchsticks;
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        ok=0;
        dfs(0,sum,sum,sum,sum);
        if(!ok) return false;
        return true;
    }
};
