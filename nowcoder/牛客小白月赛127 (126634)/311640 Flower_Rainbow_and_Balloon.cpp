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
var sumr=IntArray(1)
var sumw=IntArray(1)
var sumy=IntArray(1)
fun ck(len:Int,n:Int,m:Int,k:Int):Boolean
{
	for(i in len..n)
	{
		var x=sumr[i]-sumr[i-len]
		var y=sumy[i]-sumy[i-len]
		if(x<y) x=y.also{y=x}
		x+=min(sumw[i]-sumw[i-len],m)
		if(2*x+y>=k) return true
	}
	return false
}
fun go()
{
	var T=readint()
	require(1<=T && T<=1e5)
	var sumn=0
	var sumtot=0L
	while(T-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==3)
		var n=tmp_line[0]
		var m=tmp_line[1]
		var k=tmp_line[2]
		require(1<=n && n<=2e5)
		require(0<=m && m<=n)
		require(0<=k && k<=1e9)
		sumn+=n
		require(sumn<=1e6)
		var s=readstring()
		require(s.length==n)
		sumr=IntArray(n+2)
		sumw=IntArray(n+2)
		sumy=IntArray(n+2)
		sumr[0]=0
		sumw[0]=0
		sumy[0]=0
		for(i in 1..n)
		{
			sumr[i]=sumr[i-1]
			sumw[i]=sumw[i-1]
			sumy[i]=sumy[i-1]
			if(s[i-1]=='r') sumr[i]++
			else if(s[i-1]=='w') sumw[i]++
			else if(s[i-1]=='y') sumy[i]++
			else require(false)
		}
		var l=1
		var r=n
		while(l<r)
		{
			var mid=(l+r) shr 1
			if(ck(mid,n,m,k)) r=mid;
			else l=mid+1;
		}
		if(ck(l,n,m,k))
		{
			sumtot+=1L*n*l
			println("${l}")
		}
		else
		{
			sumtot+=1L*n*n
			println("-1")
		}
	}
}

