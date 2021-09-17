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
fun go()
{
    var t=readint()
    while(t-->0)
    {
        var tmp_line=readline_int()
        var n=tmp_line[0]
        var m=tmp_line[1]
        var k=tmp_line[2]
        var ok=1
        var nown=0
        var kk=k
        if(n%2!=0)
        {
            if(k>0 && m%2!=0) ok=0
            if(m/2>k) ok=0
            k-=m/2
            nown++
        }
        var mp=Array(n){Array<Char>(m){'a'}}
        if(k%2!=0) ok=0
        if((n-nown)*(m/2)<k) ok=0
        if(ok>0)
        {
            println("YES")
            var i=0
            if(n%2!=0) i=1
            while(i<n)
            {
                var f=(i/2)%2
                for(j in 0..m-1)
                {
                    mp[i][j]='a'+f
                    mp[i+1][j]='a'+f
                    f=f xor 1
                }
                i+=2
            }
            if(n%2!=0)
            {
                i=0
                var j=0
                var f=0
                while(j<m && kk>0)
                {
                    mp[i][j]='c'+f
                    mp[i][j+1]='c'+f
                    f=f xor 1
                    j+=2
                    kk--
                }
            }
            if(n%2!=0) i=1
            else i=0
            while(i<n && kk>0)
            {
                var f=0
                var j=0
                while(j+1<m && kk>0)
                {
                    mp[i][j]='e'+f
                    mp[i][j+1]='e'+f
                    f=f xor 1
                    mp[i+1][j]='e'+f
                    mp[i+1][j+1]='e'+f
                    j+=2
                    kk-=2
                }
                i+=2
            }
            for(i in 0..n-1) println(mp[i].joinToString(""))
        }
        else println("NO")
    }
}

