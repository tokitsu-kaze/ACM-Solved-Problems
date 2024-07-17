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
data class pair(var fi:Long,var se:Long)
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
    if (a.fi==b.fi) a.se.compareTo(b.se)
    else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e5.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
fun lower_bound_pos(a:MutableList<Long>,target:Long):Int
{
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
fun upper_bound_pos(a:MutableList<Long>,target:Long):Int
{
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
fun qpow(aa:Long,bb:Int):Long
{
	var res=1L
	var a=aa
	var b=bb
	while(b>0)
	{
		if((b and 1)==1) res=res*a%mod
		a=a*a%mod
		b=b shr 1
	}
	return res
}
var pw=Array(12){LongArray(12){0}}
fun init()
{
	for(i in 1..10)
	{
		pw[i][0]=1L
		for(j in 1..11) pw[i][j]=pw[i][j-1]*i
	}
}
fun go()
{
	init()
	var tmp_line=readline_ll()
	require(tmp_line.size==2)
	var n=tmp_line[0]
	var k=tmp_line[1]
	require(n>=1 && n<=1e10)
	require(k>=0 && k<=1e10)
	require(n%mod!=0L)
	var len=n.toString().length
	var rlen=(len+1)/2
	var llen=len-rlen
	var ln=n/pw[10][rlen]
	var rn=n%pw[10][rlen]
	var res=Array(12){mutableListOf<Long>()}
	var reslimt=Array(12){mutableListOf<Long>()}
	var ans=0L
	for(i in 0..pw[10][rlen]-1)
	{
		var tmp=i.toString()
		for(j in tmp.length..tmp.length)
		{
			var now=0L
			for(it in tmp) now+=pw[it-'0'][j]
			if(i>0 && abs(i-now)<=k) ans++
		}
		for(j in rlen..len)
		{
			var now=0L
			for(it in tmp) now+=pw[it-'0'][j]
			res[j].add(i-now)
		}
		if(i==rn)
		{
			for(j in 1..11) reslimt[j]=res[j].toMutableList()
		}
	}
//	println("${ans}")
	for(i in 1..11)
	{
		res[i].sort()
		reslimt[i].sort()
	}
	for(i in 1..ln-1)
	{
		var tmp=i.toString()
		for(j in tmp.length..tmp.length)
		{
			var now=0L
			for(it in tmp) now+=pw[it-'0'][j+rlen]
			now=i*pw[10][rlen]-now
			var cnt=upper_bound_pos(res[j+rlen],k-now)-
				    lower_bound_pos(res[j+rlen],-k-now)
			ans+=cnt
//			println("${i} ${now} ${cnt}")
		}
	}
	for(i in ln..ln)
	{
		var tmp=i.toString()
		for(j in tmp.length..tmp.length)
		{
			var now=0L
			for(it in tmp) now+=pw[it-'0'][j+rlen]
			now=i*pw[10][rlen]-now
			var cnt=upper_bound_pos(reslimt[j+rlen],k-now)-
				    lower_bound_pos(reslimt[j+rlen],-k-now)
			ans+=cnt
//			println("${i} ${now} ${cnt}")
		}
	}
//	println("${ans}")
	println("${ans%mod*qpow(n%mod,mod-2)%mod}")
}

