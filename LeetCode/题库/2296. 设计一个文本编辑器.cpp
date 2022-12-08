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

class TextEditor {
public:
    string a;
    deque<char> b;
    TextEditor() {
        a="";
        b.clear();
    }
    
    void addText(string text) {
        a+=text;
    }
    
    int deleteText(int k) {
        int res=min(sz(a),k);
        for(int i=0;i<res;i++) a.pop_back();
        return res;
    }
    
    string cursorLeft(int k) {
        string res;
        int len=min(sz(a),k);
        while(len--)
        {
            b.push_front(a.back());
            a.pop_back();
        }
        for(int i=max(0,sz(a)-10);i<sz(a);i++) res+=a[i];
        return res;
    }
    
    string cursorRight(int k) {
        string res;
        k=min(k,sz(b));
        while(k--)
        {
            a+=b.front();
            b.pop_front();
        }
        for(int i=max(0,sz(a)-10);i<sz(a);i++) res+=a[i];
        return res;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
