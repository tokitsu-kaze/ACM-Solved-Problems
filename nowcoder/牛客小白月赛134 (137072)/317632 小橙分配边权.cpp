import java.util.*
import kotlin.math.*
import kotlin.random.Random

fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readdb()=readLine()!!.toDouble()
fun readstring()=readLine()!!
fun readline_char()=readLine()!!.toCharArray()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun readline_ull()=(readLine()!!.split(" ").map{it.toULong()}).toULongArray()
fun readline_db()=(readLine()!!.split(" ").map{it.toDouble()}).toDoubleArray()
fun readline_string()=(readLine()!!.split(" "))
fun main(args: Array<String>){go()}
data class pair(var fi:Int,var se:Long)
/*using: xxx.sortWith(pair_cmp)*/
val pair_cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e5.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
class Disjoint_Set_Union()
{
	lateinit var pre:IntArray
	lateinit var sz:IntArray
	fun init(n:Int)
	{
		pre=IntArray(n+1){it}
		sz=IntArray(n+1){1}
	}
	fun find(x:Int):Int
	{
		if(pre[x]!=x) pre[x]=find(pre[x])
		return pre[x]
	}
	fun merge(a:Int,b:Int):Boolean
	{
		var ra=find(a)
		var rb=find(b)
		if(ra!=rb)
		{
			pre[ra]=rb
			sz[rb]+=sz[ra]
			return true
		}
		return false
	}
}
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==2)
	var n=tmp_line[0]
	var m=tmp_line[1]
	require(2<=n && n<=2e5)
	require(n-1<=m && m<=2e5)
	var a=readline_int()
	require(a.size==n)
	for(it in a) require(0<=it && it<=1e9)
	var dsu=Disjoint_Set_Union()
	dsu.init(n)
	var x=IntArray(m+1)
	var y=IntArray(m+1)
	var concnt=0
	var mp=Array(n+1){mutableListOf<Int>()}
	for(i in 1..m)
	{
		tmp_line=readline_int()
		require(tmp_line.size==2)
		x[i]=tmp_line[0]
		y[i]=tmp_line[1]
		require(1<=x[i] && x[i]<=n)
		require(1<=y[i] && y[i]<=n)
		require(x[i]!=y[i])
		if(dsu.merge(x[i],y[i])) concnt++
		mp[x[i]].add(y[i])
		mp[y[i]].add(x[i])
	}
	require(concnt==n-1)
	var s=-1
	for(i in 0..n-1)
	{
		if(a[i]==0) s=i+1
	}
	if(s==-1)
	{
		println("-1")
		return
	}
	var vis=IntArray(n+1){0}
	val q:Queue<Int> = LinkedList()
	q.offer(s)
	vis[s]=1
	var cnt=1
	while(!q.isEmpty())
	{
		var t=q.peek()
		q.poll()
		for(to in mp[t])
		{
			if(vis[to]==1) continue
			if(a[to-1]>=a[t-1])
			{
				q.offer(to)
				vis[to]=1
				cnt++
			}
		}
	}
	if(cnt<n)
	{
		println("-1")
		return
	}
	for(i in 1..m) println("${abs(a[x[i]-1]-a[y[i]-1])}")
}

