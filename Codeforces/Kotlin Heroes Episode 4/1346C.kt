import java.util.*
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
min,max                      minOf,maxOf
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
/*------------------------------------------------------------*/
fun go()
{
    var t=readint()
    while(t-->0)
    {
        var tmp=readline_int()
        var n=tmp[0]
        var k=tmp[1]
        var x=tmp[2]
        var y=tmp[3]
        var a=readline_int().sorted()
        var ans=1L*x*n
        var now=0L
        var sum=0L
        for(i in 0..n-1) sum+=a[i];
        if((sum+n-1)/n<=k) ans=minOf(ans,y*1L)
        for(i in n-1 downTo 0)
        {
            if(a[i]<=k)  ans=minOf(ans,now)
            sum-=a[i]
            now+=x
            if((sum+n-1)/n<=k) ans=minOf(ans,now+y)
        }
        println("${ans}")
    }
}

