import java.util.*
import kotlin.math.*

fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readdb()=readLine()!!.toDouble()
fun readstring()=readLine()!!
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun readline_db()=(readLine()!!.split(" ").map{it.toDouble()}).toDoubleArray()
fun main(args: Array<String>){go()}
/*
---------------c++->kotlin-------------------
swap(a,b)                    a=b.also{b=a}
for(i=0;i<n;i++)             for(i in 0 until n) / for(i in 0..n-1)
for(i=n-1;i>=0;i--)          for(i in n-1 downTo 0)
for(auto it:s)               for(it in s)
printf                       println("${ans}")
println(res)                 println(res.joinToString(" "))
ll a[n]                      var a=Array<Long>(n){}
int a[n+2][m+2]              var a=Array(n+2){Array<Int>(m+2){0}}
a&b                          a and b
a|b                          a or b
a^b                          a xor b
int gao(int a,int b)         fun gao(a:Int,b:Int):Int
---------sort---------
res.sortBy({it.fi})
res.sortWith({it.fi},{it.se})
--------vector--------
vector<int> res;             var res=mutableListOf<Int>()
res.push_back                res.add
vector<int> mp[n];           var mp=Array(n){mutableListOf<Int>()}
---------set----------
set<int> s;                  var s=TreeSet<Int>()
s.insert                     s.add
s.erase                      s.remove
s.count                      s.contains
s.begin                      s.first
s.rbegin                     s.last
set<pair<int,int>> s;        var s=TreeSet<Pair<Int,Int>>(compareBy({it.first},{it.second}))
-----unordered_map-----
unordered_map<int,int>       var mp:MutableMap<Int,Int> = mutableMapOf()
mp[x]++                      mp[x]=(mp[x]?:0)+1
sum+=mp[x]                   sum+=mp[x]?:0
-----priority_queue-----
struct node{int a;}          data class node(var a:Int)
priority_queue<node> q;      var q=PriorityQueue<node>(compareBy({it.a}))
q.top                        q.peek
q.pop                        q.poll
q.push                       q.add
---------deque----------
deque<int> dq;               var dq=ArrayDeque<Int>()
dq.push_front()              dq.offerFirst()
dq.front()                   dq.peekFirst()
dq.pop_front()               dq.pollFirst()
{dq.front(),dq.pop_front()}  dq.pollFirst()

dq.push_back()               dq.offerLast()
dq.back()                    dq.peekLast()
dq.pop_back()                dq.pollLast()
{dq.back(),dq.pop_back()}    dq.pollLast()
---------------------------------------------
 */
data class pair(var fi:Int,var se:Int)
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
    if (a.fi==b.fi) a.se.compareTo(b.se)
    else a.fi.compareTo(b.fi)
}
val INF=0x3f3f3f3f
val LLINF=0x3f3f3f3f3f3f3f3fL
/*------------------------------------------------------------*/

fun go()
{
    var t=readint()
    while(t-->0)
    {
        var n=readint()
        var tmp_s=readstring()
        var s=CharArray(n){'('}
        var a=readstring()
        var ans=0
        for(i in 0..n-1) s[i]=tmp_s[i]
        for(i in 0..n-4)
        {
            if(a[i]=='0') continue
            var now=INF
            var tmp=0
            if(s[i]!='(') tmp++
            if(s[i+1]!=')') tmp++
            if(s[i+2]!='(') tmp++
            if(s[i+3]!=')') tmp++
            now=tmp
            tmp=0
            if(s[i]!='(') tmp++
            if(s[i+1]!='(') tmp++
            if(s[i+2]!=')') tmp++
            if(s[i+3]!=')') tmp++
            if(tmp<now && !(i+2<n-3&&a[i+2]=='1'))
            {
                s[i]='('
                s[i+1]='('
                s[i+2]=')'
                s[i+3]=')'
                now=tmp
            }
            else
            {
                s[i]='('
                s[i+1]=')'
                s[i+2]='('
                s[i+3]=')'
            }
            ans+=now
        }
        for(i in 0..n-4)
        {
            if(a[i]=='0') continue
            var now=INF
            var tmp=0
            if(s[i]!='(') tmp++
            if(s[i+1]!=')') tmp++
            if(s[i+2]!='(') tmp++
            if(s[i+3]!=')') tmp++
            now=tmp
            tmp=0
            if(s[i]!='(') tmp++
            if(s[i+1]!='(') tmp++
            if(s[i+2]!=')') tmp++
            if(s[i+3]!=')') tmp++
            now=min(now,tmp)
            if(now!=0)
            {
                ans=-1
                break
            }
        }
        println("${ans}")
    }

}

