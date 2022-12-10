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
---------------------------------------------
 */
data class pair(var fi:Int,var se:Int)
val cmp: Comparator<pair> = Comparator{ a,b->
    if (a.fi==b.fi) a.se.compareTo(b.se)
    else a.fi.compareTo(b.fi)
}
fun go()
{
    var t=readint()
    while(t-->0)
    {
        var tmp=readline_int()
        var n=tmp[0]
        var k=tmp[1]
        var mp=Array(n+1){mutableListOf<Int>()}
        var d=Array(n+1){0}
        for(i in 0 until n-1)
        {
            tmp=readline_int()
            var a=tmp[0]
            var b=tmp[1]
            mp[a].add(b)
            mp[b].add(a)
            d[a]++
            d[b]++
        }
        if(k==1)
        {
            println("Yes")
            println("1")
            println("1")
            continue
        }
        var q=mutableListOf<Int>()
        var head=0
        var flag=Array(n+1){0}
        for(i in 1..n)
        {
            if(d[i]==1) q.add(i)
            flag[i]=1
        }
        var ok=0
        while(q.size-head>0)
        {
            if(q.size-head==k)
            {
                ok=1
                break
            }
            var x=q[head]
            head++
            flag[x]=0
            for(to in mp[x])
            {
                d[to]--
                if(d[to]==1) q.add(to)
            }
        }
        if(ok==0)
        {
            println("No")
            continue
        }
        var res=mutableListOf<Int>()
        for(i in 1..n)
        {
            if(flag[i]==1) res.add(i)
        }
        println("Yes")
        println("${res.size}")
        println(res.joinToString(" "))
    }
}