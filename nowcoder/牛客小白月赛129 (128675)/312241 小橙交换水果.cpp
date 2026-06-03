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
fun readline_db()=(readLine()!!.split(" ").map{it.toDouble()}).toDoubleArray()
fun readline_string()=(readLine()!!.split(" "))
fun main(args: Array<String>){go()}
data class pair(var first:Int,var second:Int)
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e7.toInt()+10
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
const val LOG=20
var mp=Array(1){mutableListOf<Int>()}
var fa=Array(1){IntArray(1)}
var dep=IntArray(1)
var cnt=IntArray(1)
fun dfs(x:Int,pre:Int)
{
	fa[0][x]=pre
	dep[x]=dep[pre]+1
	cnt[x]=cnt[pre]
	if(mp[x].size>=3) cnt[x]++
	for(i in 1..LOG-1) fa[i][x]=fa[i-1][fa[i-1][x]]
	for(to in mp[x])
	{
		if(to==pre) continue
		dfs(to,x)
	}
}
fun lca(xx:Int,yy:Int):Int
{
	var x=xx
	var y=yy
	if(dep[x]<dep[y]) x=y.also{y=x}
	var d=dep[x]-dep[y]
	for(i in 0..LOG-1)
	{
		if(((d shr i) and 1)==1) x=fa[i][x]
	}
	if(x==y) return x
	for(i in LOG-1 downTo 0)
	{
		if(fa[i][x]!=fa[i][y])
		{
			x=fa[i][x]
			y=fa[i][y]
		}
	}
	return fa[0][x]
}
var dis=IntArray(1)
fun bfs(n:Int)
{
	dis=IntArray(n+1){INF}
	val q:Queue<Int> = LinkedList()
	for(i in 1..n)
	{
		if(mp[i].size>=3)
		{
			q.offer(i)
			dis[i]=0
		}
	}
	while(!q.isEmpty())
	{
		var x=q.peek()
		q.poll()
		for(to in mp[x])
		{
			if(dis[to]>dis[x]+1)
			{
				dis[to]=dis[x]+1
				q.offer(to)
			}
		}
	}
}
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==2)
	var n=tmp_line[0]
	var q=tmp_line[1]
	require(2<=n && n<=2e5)
	require(1<=q && q<=2e5)
	mp=Array(n+1){mutableListOf<Int>()}
	var dsu=Disjoint_Set_Union()
	dsu.init(n)
	for(i in 1..n-1)
	{
		tmp_line=readline_int()
		require(tmp_line.size==2)
		var a=tmp_line[0]
		var b=tmp_line[1]
		require(a!=b)
		require(1<=a && a<=n)
		require(1<=b && b<=n)
		dsu.merge(a,b)
		mp[a].add(b)
		mp[b].add(a)
	}
	var rtcnt=0
	for(i in 1..n)
	{
		if(dsu.find(i)==i) rtcnt++
	}
	require(rtcnt==1)
	fa=Array(LOG){IntArray(n+1){0}}
	dep=IntArray(n+1){0}
	cnt=IntArray(n+1){0}
	dfs(1,0)
	bfs(n)
	var res=mutableListOf<Int>()
	while(q-->0)
	{
		tmp_line=readline_int()
		require(tmp_line.size==2)
		var a=tmp_line[0]
		var b=tmp_line[1]
		require(a!=b)
		require(1<=a && a<=n)
		require(1<=b && b<=n)
		var c=lca(a,b)
		var cnt3=cnt[a]+cnt[b]-cnt[c]*2
		if(mp[a].size>=3) cnt3--
		if(mp[b].size>=3) cnt3--
		if(mp[c].size>=3) cnt3++
		var len=dep[a]+dep[b]-dep[c]*2
		if(dis[a]==INF) res.add(-1)
		else if(cnt3>0) res.add(len*2+2)
		else res.add(len*2+(min(dis[a],dis[b])+1)*4)
	}
	println(res.joinToString("\n"))
}
