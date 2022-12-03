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
fun lower_bound(a:Array<Int>, L:Int, R:Int, key:Int):Int {
    var mid=0
    var l=L
    var r=R-1
    while(l<r) {
        mid=(l+r)/2
        if(a[mid]<key) l=mid+1
        else r=mid
    }
    return l
}
data class pair(var fi:Int,var se:Int,var id:Int)
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
    if (a.fi==b.fi) a.se.compareTo(b.se)
    else a.fi.compareTo(b.fi)
}
val INF=0x3f3f3f3f
val LLINF=0x3f3f3f3f3f3f3f3fL
val MAX=200000+10
/*------------------------------------------------------------*/
fun go()
{
    var n=readint()
    var a=readline_int()
    var ans=Array<Int>(n){0}
    var mx=-1
    var mn=INF
    for(i in 0..n-1) {
        if(a[i]>mx && a[i]>=mn) {
            mx=a[i]
            continue
        }
        if(a[i]<=mx && a[i]<mn) {
            mn=a[i]
            ans[i]=1
            continue
        }
        if(a[i]<=mx && a[i]>=mn) {
            println("NO")
            return
        }
        if(a[i]>mx && a[i]<mn) {
            if(i==n-1) mx=a[i]
            else if(a[i]>a[i+1]) {
                mn=a[i]
                ans[i]=1
            }
            else mx=a[i]
        }
    }
    println("YES")
    println(ans.joinToString(" "))
}




