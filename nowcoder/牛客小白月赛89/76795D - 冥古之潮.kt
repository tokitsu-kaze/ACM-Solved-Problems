import java.util.*
import kotlin.math.*

fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readdb()=readLine()!!.toDouble()
fun readstring()=readLine()!!
fun readline_char()=readLine()!!.toCharArray()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun readline_db()=(readLine()!!.split(" ").map{it.toDouble()}).toDoubleArray()
fun readline_string()=(readLine()!!.split(" "))
fun main(args: Array<String>){go()}
inline fun <T:Number> lower_bound_pos(
a:MutableList<T>,L:Int,R:Int,target:T):Int{
	var l=L
	var r=R
	var mid:Int
	while(l<r){
    	mid=(l+r) shr 1
    	if(a[mid].toLong()>=target.toLong()) r=mid
    	else l=mid+1
    }
	return l
}
data class pair(var fi:Int,var se:Int)
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
    if (a.fi==b.fi) a.se.compareTo(b.se)
    else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e6.toInt()+10
const val mod=1e9.toInt()+7
/*------------------------------------------------------------*/
var mp=Array(1){mutableListOf<Int>()}
var dis=IntArray(1)
var cnt=IntArray(1)
fun bfs(s:Int)
{
	val q:Queue<Int> = LinkedList()
	q.offer(s)
	dis[s]=0
	while(!q.isEmpty())
	{
		var t=q.peek()
		q.poll()
		cnt[dis[t]]++
		require(dis[t]>=0 && dis[t]<=5000)
		for(to in mp[t])
		{
			if(dis[to]>dis[t]+1)
			{
				dis[to]=dis[t]+1
				q.offer(to)
			}
		}
	}
}
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==4)
	var n=tmp_line[0]
	var m=tmp_line[1]
	var q=tmp_line[2]
	var x=tmp_line[3]
	require(n>=1 && n<=1e6)
	require(m>=1 && m<=1e6)
	require(q>=1 && q<=5000)
	require(x>=1 && x<=n)
	var ck=mutableListOf<pair>()
	mp=Array(n+1){mutableListOf<Int>()}
	while(m-->0)
	{
		tmp_line=readline_int()
		require(tmp_line.size==2)
		var a=tmp_line[0]
		var b=tmp_line[1]
		require(a>=1 && a<=n)
		require(b>=1 && b<=n)
		require(a!=b)
		if(a<b) ck.add(pair(a,b))
		else ck.add(pair(b,a))
		mp[a].add(b)
		mp[b].add(a)
	}
	ck.sortWith(cmp)
	for(i in 1..ck.size-1) require(!(ck[i].fi==ck[i-1].fi&&ck[i].se==ck[i-1].se))
	dis=IntArray(n+1){INF}
	cnt=IntArray(5001){0}
	bfs(x)
	var dp=IntArray(5001){0}
	dp[0]=1
	for(i in 1..5000)
	{
		var now=IntArray(5001){0}
		now[0]=1
		for(j in 1..5000)
		{
			now[j]=((dp[j]+dp[j-1].toLong()*cnt[i])%mod).toInt()
		}
		dp=now
	}
	var ans=IntArray(q)
	for(i in 0..q-1)
	{
		var k=readint()
		ans[i]=dp[k]
	}
	println(ans.joinToString("\n"))
}

