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
/*------------------------------------------------------------*/
fun go()
{
    var t=readint()
    while(t-->0)
    {
        var n=readint()
        var a=readline_int()
        var res=Array<Int>(n){-1}
        var ok=1
        for(i in 1..n-1)
        {
            if(a[i]!=a[0]) ok=0;
        }
        if(ok==1)
        {
            println("1")
            for(i in 0..n-1) res[i]=1
            println(res.joinToString(" "))
            continue
        }
        if(n%2==0)
        {
            println("2")
            for(i in 0..n-1) res[i]=i%2+1
            println(res.joinToString(" "))
        }
        else
        {
            ok=0
            for(i in 0..n-1)
            {
                if(a[i]==a[(i+1)%n])
                {
                    res[i]=1
                    res[(i+1)%n]=1
                    ok=1
                    var pos=(i+2)%n
                    while(res[pos]==-1)
                    {
                        res[pos]=ok+1
                        ok=ok xor 1
                        pos++
                        if(pos==n) pos=0
                    }
                    println("2")
                    println(res.joinToString(" "))
                    ok=1
                    break
                }
            }
            if(ok==0)
            {
                println("3")
                for(i in 0..n-2) res[i]=i%2+1
                res[n-1]=3
                println(res.joinToString(" "))
            }
        }
    }
}
