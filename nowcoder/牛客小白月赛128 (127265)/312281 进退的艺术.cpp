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
fun upper_bound_pos(a:IntArray,target:Int):Int
{
	if(a.size==0) return 0
	var l=0
	var r=a.size-1
	var mid:Int
	while(l<r)
	{
		mid=(l+r) shr 1
		if(a[mid]<=target) l=mid+1
		else r=mid
	}
	if(a[l]>target) return l
    return a.size
}
fun go()
{
	var T=readint()
	require(1<=T && T<=2e4)
	var sumn=0
	while(T-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==2)
		var n=tmp_line[0]
		var m=tmp_line[1]
		require(2<=n && n<=2e5)
		require(0<=m && m<=1e9)
		sumn+=n
		require(sumn<=2e5)
		var a=readline_int()
		require(a.size==n)
		for(it in a) require(0<=it && it<=m)
		var b=IntArray(n)
		for(i in 0..n-1) b[i]=a[i]
		b.sort()
		var bit=LongArray(n+1){0}
		for(i in 1..n) bit[i]=bit[i-1]+b[i-1]
		var ans=LongArray(n)
		for(i in 0..n-1)
		{
			var pos=upper_bound_pos(b,max(0,m-a[i]))+1
			ans[i]=1L*(pos-1)*a[i]
			if(pos<=n) ans[i]=ans[i]-(bit[n]-bit[pos-1])
			if(a[i]*2>m) ans[i]=ans[i]+a[i]
			else ans[i]=ans[i]-a[i]
		}
		println(ans.joinToString(" "))
	}
}

