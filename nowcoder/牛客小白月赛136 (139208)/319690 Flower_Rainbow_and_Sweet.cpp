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
const val LOG=20
var mp=Array(1){mutableListOf<Int>()}
var fa=Array(LOG+1){IntArray(1)}
var dep=IntArray(1)
fun dfs0(x:Int,pre:Int)
{
	fa[0][x]=pre
	dep[x]=dep[pre]+1
	for(i in 1..LOG-1) fa[i][x]=fa[i-1][fa[i-1][x]]
	for(to in mp[x])
	{
		if(to==pre) continue
		dfs0(to,x)
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
var res=Array(1){mutableListOf<Int>()}
var w=0
data class node(var v:Int)
var q=Array(1){PriorityQueue<node>(compareBy({it.v}))}
var sum=IntArray(1)
var ans=0L
fun add(x:Int,v:Int)
{
	q[x].add(node(-v))
	sum[x]+=v
	while(sum[x]>w)
	{
		sum[x]-=-q[x].peek().v
		q[x].poll()
	}
}
fun dfs(x:Int,fa:Int)
{
	for(to in mp[x])
	{
		if(to==fa) continue
		dfs(to,x)
		if(q[to].size>q[x].size)
		{
			q[to]=q[x].also{q[x]=q[to]}
			sum[to]=sum[x].also{sum[x]=sum[to]}
		}
		while(q[to].size>0)
		{
			add(x,-q[to].peek().v)
			q[to].poll()
		}
	}
	for(it in res[x]) add(x,it)
	ans=max(ans,1L*dep[x]*q[x].size)
}
fun go()
{
	var T=readint()
	require(1<=T && T<=1e4)
	var sumn=0
	while(T-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==2)
		var n=tmp_line[0]
		w=tmp_line[1]
		require(1<=n && n<=1e5)
		require(1<=w && w<=1e5)
		sumn+=n
		require(sumn<=1e5)
		var c=readline_int()
		require(c.size==n)
		for(it in c) require(1<=it && it<=n)
		mp=Array(n+1){mutableListOf<Int>()}
		for(i in 1..n-1)
		{
			tmp_line=readline_int()
			require(tmp_line.size==2)
			var a=tmp_line[0]
			var b=tmp_line[1]
			require(1<=a && a<=n)
			require(1<=b && b<=n)
			require(a!=b)
			mp[a].add(b)
			mp[b].add(a)
		}
		fa=Array(LOG+1){IntArray(n+1){0}}
		dep=IntArray(n+1){0}
		dfs0(1,0)
		var z=IntArray(n+1){0}
		var cnt=IntArray(n+1){0}
		for(i in 1..n)
		{
			if(z[c[i-1]]==0) z[c[i-1]]=i
			else z[c[i-1]]=lca(z[c[i-1]],i)
			cnt[c[i-1]]++
		}
		res=Array(n+1){mutableListOf<Int>()}
		for(i in 1..n)
		{
			if(z[i]!=0) res[z[i]].add(cnt[i])
		}
		ans=0L
		q=Array(n+1){PriorityQueue<node>(compareBy({it.v}))}
		sum=IntArray(n+1){0}
		dfs(1,0)
		println("${ans}")
	}
}
/*
按题意模拟，先把集货点求出来，然后树上启发式合并即可。
*/

