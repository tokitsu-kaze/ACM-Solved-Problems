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
data class pair(var fi:Int,var se:Int)
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val mod=998244353//1e9.toInt()+7
const val MAX=300000+10
/*------------------------------------------------------------*/
var s=""
var ans=CharArray(1)
var mp=Array(1){mutableListOf<Int>()}
var red=IntArray(1)
var blue=IntArray(1)
var now=0L
fun dfs0(x:Int,fa:Int)
{
	red[x]=0
	blue[x]=0
	if(s[x-1]=='R') red[x]=1
	else blue[x]=1
	for(to in mp[x])
	{
		if(to==fa) continue
		dfs0(to,x)
		red[x]+=red[to]
		blue[x]+=blue[to]
	}
}
fun dfs(x:Int,fa:Int,vv1:Int,vv2:Int)
{
	var v1=vv1
	var v2=vv2
	if(red[x]-blue[x]>=2)
	{
		v1++
		v2--
	}
	else if(red[x]-blue[x]==1) v2--
	else if(red[x]-blue[x]==0)
	{
		v1--
		v2--
	}
	else if(red[x]-blue[x]==-1) v1--
	else if(red[x]-blue[x]<=-2)
	{
		v1--
		v2++
	}
	if(s[x-1]=='R' && v1>0) ans[x-1]='1'
	else if(s[x-1]=='B' && v2>0) ans[x-1]='1'
	else ans[x-1]='0'
	for(to in mp[x])
	{
		if(to==fa) continue
		dfs(to,x,v1,v2)
	}
}
fun go()
{
	var T=readint()
	require(T>=1 && T<=1e4)
	while(T-->0)
	{
		var n=readint()
		require(n>=1 && n<=5e5)
		s=readstring()
		require(s.length==n)
		for(i in 0..n-1) require(s[i]=='B' || s[i]=='R')
		mp=Array(n+1){mutableListOf<Int>()}
		for(i in 1..n-1)
		{
			var tmp_line=readline_int()
			require(tmp_line.size==2)
			var a=tmp_line[0]
			var b=tmp_line[1]
			mp[a].add(b)
			mp[b].add(a)
		}
		red=IntArray(n+1){0}
		blue=IntArray(n+1){0}
		now=0L
		dfs0(1,0)
		ans=CharArray(n){'0'}
		dfs(1,0,0,0)
		println(ans.joinToString(""))
	}
}

