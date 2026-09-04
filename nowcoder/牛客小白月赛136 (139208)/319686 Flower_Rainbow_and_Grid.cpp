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
var n=0L
var m=0L
var k=0L
data class node(var cnt:Long,var sum:Long)
fun cal(x:Long):node
{
	var cnt=0L
	var sum=0L
	var j=0
	for(i in 1..n)
	{
		while(j<m && 1L*i*i-1L*(j+1)*(j+1)>=x) j++
		cnt+=j
		sum+=1L*j*i*i-1L*j*(j+1)*(2*j+1)/6
	}
	return node(cnt,sum)
}
fun ck(x:Long):Boolean
{
	var res=cal(x)
	return res.cnt>=k;
}
fun go()
{
	var T=readint()
	require(1<=T && T<=5e4)
	var sumn=0L
	var summ=0L
	while(T-->0)
	{
		var tmp_line=readline_ll()
		require(tmp_line.size==3)
		n=tmp_line[0]
		m=tmp_line[1]
		k=tmp_line[2]
		require(1<=n && n<=5e4)
		require(1<=m && m<=5e4)
		require(1<=k && k<=n*m)
		sumn+=n
		summ+=m
		require(sumn<=5e4)
		require(summ<=5e4)
		var l=1-m*m
		var r=n*n-1
		while(l<r)
		{
			var mid=(l+r) shr 1
			if(ck(mid+1)) l=mid+1
			else r=mid
		}
		var res=cal(l)
		println("${res.sum-(res.cnt-k)*l}")
	}
}

