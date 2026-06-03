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
data class pair(var fi:Int,var se:Int)
/*using: xxx.sortWith(pair_cmp)*/
val pair_cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=2000+10
const val mod=1e9.toInt()+7
/*------------------------------------------------------------*/
class Trie
{
	var LOG=10
	var K=LOG+2
	var rt=0
	var root=IntArray(MAX){0}
	var tot=0
	var ch=Array(MAX*K){IntArray(2){0}}
	var v=IntArray(MAX*K){0}
	fun newnode():Int
	{
		tot++
		ch[tot][0]=0
		ch[tot][1]=0
		v[tot]=0
		return tot
	}
	fun init()
	{
		var n=1 //
		ch[0][0]=0
		ch[0][1]=0
		v[0]=0
		tot=1
		for(i in 0..n) root[i]=0
		rt=1
	}
	fun insert(x:Int,qv:Int)
	{
		if(root[rt]==0) root[rt]=newnode()
		var id=root[rt]
		for(i in LOG downTo 0)
		{
			v[id]+=qv
			if(v[id]>=mod) v[id]-=mod
			var t=((x shr i) and 1).toInt()
			if(ch[id][t]==0) ch[id][t]=newnode()
			id=ch[id][t]
		}
		v[id]+=qv
		if(v[id]>=mod) v[id]-=mod
	}
	fun count_y(x:Int,limt:Int):Int // count y: x xor y <= limt
	{
		if(limt<0) return 0
		if(root[rt]==0) return 0
		var id=root[rt]
		var res=0
		for(i in LOG downTo 0)
		{
			var t=((x shr i) and 1).toInt()
			if((limt shr i) and 1 > 0)
			{
				res+=v[ch[id][t]]
				if(res>=mod) res-=mod
				id=ch[id][t xor 1]
			}
			else id=ch[id][t]
		}
		res+=v[id]
		if(res>=mod) res-=mod
		return res
	}
}
fun go()
{
	var T=readint()
	require(1<=T && T<=100)
	while(T-->0)
	{
		var n=readint()
		require(1<=n && n<=2000)
		var a=IntArray(n+1)
		var l=IntArray(n+1)
		var r=IntArray(n+1)
		for(i in 0..n-1)
		{
			var tmp_line=readline_int()
			require(tmp_line.size==3)
			a[i+1]=tmp_line[0]
			l[i+1]=tmp_line[1]
			r[i+1]=tmp_line[2]
			require(0<=a[i+1] && a[i+1]<(1 shl 10))
			require(0<=l[i+1] && l[i+1]<(1 shl 10))
			require(0<=r[i+1] && r[i+1]<(1 shl 10))
			require(l[i+1]<=r[i+1])
		}
		var tr=Trie()
		var dp=IntArray(1024){0}
		for(i in 0..a[1]) dp[i]=1
		for(i in 1..1023) dp[i]+=dp[i-1]
		for(i in 2..n)
		{
			var ndp=IntArray(1024){0}
			if(i%2==0)
			{
				tr.init()
				for(j in 0..1023)
				{
					var R=min(1023,a[i]+j)
					ndp[j]=dp[R]
					if(j>0)
					{
						ndp[j]-=dp[j-1]
						if(a[i]-j>=0) ndp[j]+=dp[a[i]-j]
						if(ndp[j]<0) ndp[j]+=mod
						else if(ndp[j]>=mod) ndp[j]-=mod
					}
					tr.insert(j,ndp[j])
				}
			}
			else
			{
				for(j in 0..a[i])
				{
					ndp[j]=tr.count_y(j,r[i-1])
					ndp[j]-=tr.count_y(j,l[i-1]-1)
					if(ndp[j]<0) ndp[j]+=mod
				}
			}
			dp=ndp
			for(j in 1..1023)
			{
				dp[j]+=dp[j-1]
				if(dp[j]>=mod) dp[j]-=mod
			}
		}
		println("${dp[1023]}")
	}
}

