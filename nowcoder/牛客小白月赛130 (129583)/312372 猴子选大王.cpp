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
const val MAX=1e7.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==2)
	var n=tmp_line[0]
	var m=tmp_line[1]
	require(2<=n && n<=1e5)
	require(2<=m && m<=1e5)
	var cnt=IntArray(m+1){0}
	var a=IntArray(n+1){0}
	var b=IntArray(n+1){0}
	for(i in 1..n)
	{
		tmp_line=readline_int()
		require(tmp_line.size==2)
		a[i]=tmp_line[0]
		b[i]=tmp_line[1]
		require(1<=a[i] && a[i]<=m)
		require(1<=b[i] && b[i]<=m)
		require(a[i]!=b[i])
		cnt[a[i]]++
		cnt[b[i]]++
	}
	var ccnt=IntArray(n+1){0}
	var mx=0
	var cmx=0
	for(i in 1..m)
	{
		ccnt[cnt[i]]++
		if(cnt[i]>mx)
		{
			cmx=mx
			mx=cnt[i]
		}
		else cmx=max(cmx,cnt[i])
	}
	if(ccnt[mx]>1) cmx=mx
	var mp:MutableMap<Long,Int> = mutableMapOf()
	var ha=LongArray(n+1){0}
	var ans=INF
	for(i in 1..n)
	{
		if(a[i]>b[i]) a[i]=b[i].also{b[i]=a[i]}
		ha[i]=a[i]*1000000000L+b[i]
		var f=0
		if(cnt[a[i]]==mx && cnt[b[i]]==cmx) f=1
		if(cnt[b[i]]==mx && cnt[a[i]]==cmx) f=1
		if(f==1) mp[ha[i]]=(mp[ha[i]]?:0)+1
	}
	var tot=0L
	if(mx==cmx) tot=1L*ccnt[mx]*(ccnt[cmx]-1)/2
	else tot=1L*ccnt[mx]*ccnt[cmx]
	if(tot>mp.size) ans=0
	else
	{
		for(i in 1..n) ans=min(ans,mp[ha[i]]?:INF)
	}
	println("${mx+cmx-ans}")
}
