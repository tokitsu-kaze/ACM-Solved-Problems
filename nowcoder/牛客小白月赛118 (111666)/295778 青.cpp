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
/*using: xxx.sortWith(pair_cmp)*/
val pair_cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e6.toInt()+10
const val mod=1e9.toInt()+7
/*------------------------------------------------------------*/
var a=IntArray(1)
var sum=LongArray(1)
var n=1
var k=0
fun ck(x:Long):Boolean
{
	var dp=Array(n+2){IntArray(2){-INF}}
	var premx=IntArray(n+2){-INF}
	dp[0][0]=0
	dp[0][1]=0
	dp[1][0]=0
	dp[1][1]=1
	premx[0]=0
	premx[1]=1
	var j1=0
	var j2=0
	for(i in 2..n)
	{
		while(j1+1<i-1 && sum[i-1]-sum[j1+1]>=x) j1++;
		while(j2+1<i && sum[i]-sum[j2+1]>=x) j2++;
		if(sum[i-1]-sum[j1]>=x) dp[i][1]=premx[j1]+1
		if(sum[i]-sum[j2]>=x) dp[i][0]=premx[j2]
		premx[i]=max(premx[i-1],dp[i][1])
	}
	return max(dp[n][0],dp[n][1])>=k
}
fun go()
{
	var T=readint()
	require(T>=1 && T<=1e5)
	var sumn=0
	while(T-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==2)
		n=tmp_line[0]
		k=tmp_line[1]
		require(n>=1 && n<=1e5)
		sumn+=n
		require(sumn<=2e5)
		require(k>=0 && k<n)
		require(2*k<=n+1)
		var aa=readline_int()
		require(aa.size==n)
		a=IntArray(n+2)
		sum=LongArray(n+2)
		sum[0]=0
		for(i in 1..n)
		{
			require(aa[i-1]>=1 && aa[i-1]<=1e9)
			a[i]=aa[i-1]
			sum[i]=sum[i-1]+a[i]
		}
		var l=0L
		var r=sum[n]
		while(l<r)
		{
			var mid=(l+r)/2
			if(ck(mid+1)) l=mid+1
			else r=mid
		}
		println("${l}")
	}
}
