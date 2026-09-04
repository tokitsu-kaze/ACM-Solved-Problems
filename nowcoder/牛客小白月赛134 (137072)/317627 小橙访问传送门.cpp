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
fun lower_bound_pos(a:LongArray,target:Long):Int
{
	if(a.size==0) return 0
	var l=0
	var r=a.size-1
	var mid:Int
	while(l<r)
	{
		mid=(l+r) shr 1
		if(a[mid]>=target) r=mid
		else l=mid+1
	}
    if(a[l]>=target) return l
    return a.size
}
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==2)
	var n=tmp_line[0]
	var m=tmp_line[1]
	require(1<=n && n<=1e5)
	require(1<=m && m<=1e5)
	var x=readline_ll()
	var y=readline_ll()
	require(x.size==n)
	require(y.size==m)
	for(it in x) require(-1e9<=it && it<=1e9)
	for(it in y) require(-1e9<=it && it<=1e9)
	x.sort()
	y.sort()
	var a=LLINF
	var b=LLINF
	var c=LLINF
	for(it in x) a=min(a,abs(it))
	for(it in y) b=min(b,abs(it))
	for(it in x)
	{
		var pos=lower_bound_pos(y,it)
		if(pos<m) c=min(c,y[pos]-it)
		if(pos>0) c=min(c,it-y[pos-1])
	}
	var ans=a+b+c
	ans=min(ans,2*(a+c))
	ans=min(ans,2*(b+c))
	println("${ans}")
}
/*
0 ºì À¶ 0£ºa+b+c
0 ºì À¶ ºì 0£º2a+2c
0 À¶ ºì À¶ 0£º2b+2c
*/
