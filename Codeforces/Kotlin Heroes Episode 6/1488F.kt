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
val cmp: Comparator<pair> = Comparator{ a,b->
    if (a.fi==b.fi) a.se.compareTo(b.se)
    else a.fi.compareTo(b.fi)
}
val INF=0x3f3f3f3f
/*------------------------------------------------------------*/
data class node(var l:Int,var r:Int,var id:Int)
fun go()
{
    var n=readint()
    var a=readline_int()
    var q=readint()
    var res=mutableListOf<node>()
    for(i in 0..q-1)
    {
        var tmp_line=readline_int()
        var l=tmp_line[0]-1
        var r=tmp_line[1]-1
        res.add(node(l,r,i))
    }
    res.sortBy({it.r})
    var st=Array<Int>(n+2){0}
    var top=0
    var bit=Array<Long>(n+2){0}
    var ans=Array<Long>(q){0}
    var idx=0
    for(i in 0..n-1)
    {
        while(top>0 && a[st[top]]<a[i]) top-=1
        var now=(i-st[top]).toLong()*a[i].toLong()
        top+=1
        st[top]=i
        bit[top]=bit[top-1]+now
        while(idx<res.size)
        {
            if(res[idx].r>i) break
            if(res[idx].r==i)
            {
                var l=1
                var r=top
                while(l<r)
                {
                    var mid=(l+r)/2
                    if(st[mid]>=res[idx].l) r=mid
                    else l=mid+1
                }
                ans[res[idx].id]=bit[top]-bit[l]+(st[l]-res[idx].l+1).toLong()*a[st[l]].toLong()
            }
            idx+=1
        }
    }
    println(ans.joinToString(" "))
}

