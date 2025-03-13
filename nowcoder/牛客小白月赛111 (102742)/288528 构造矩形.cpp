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
const val MAX=1e5.toInt()+10
const val mod=998244353//1e9.toInt()+7
/*------------------------------------------------------------*/
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==3)
	var n=tmp_line[0]
	var m=tmp_line[1]
	var k=tmp_line[2]
	require(n>=1 && n<=1e5)
	require(m>=1 && m<=1e5)
	require(k>=1 && k<m)
	var aa=readline_int()
	require(aa.size==n)
	m++
	var sum=LongArray(n+2){0}
	var a=LongArray(n+2){0}
	for(i in 1..n)
	{
		a[i]=aa[i-1].toLong()
		sum[i]=sum[i-1]+a[i]
		require(a[i]>=1 && a[i]<=1e5)
		if(i>1) require(a[i]>a[i-1])
	}
	var ans=0L
	var l=1
	for(i in 1..n)
	{
		while(l<i && m-k+a[l]<=a[i]) l++
		if(l!=i && m-k+a[l]>a[i])
		{
//			println("${l} ${i}")
			ans+=1L*(i-l)*(m-a[i]-k)+(sum[i-1]-sum[l-1])
		}
	}
	l=1
	var r=0
	for(i in 1..n)
	{
		while(r+1<i && k+a[r+1]<a[i]) r++
		while(l<i && m+k+a[l]<=a[i]) l++
		if(l<=r && a[r]+k<a[i] && a[i]<a[l]+k+m)
		{
//			println("${i} ${l} ${r}")
			ans+=1L*(r-l+1)*(m-a[i]+k)+(sum[r]-sum[l-1])
		}
	}
	println("${ans}")
}
/*
r

m-(ar-al+k)>0
al<ar<m-k+al

\sum{i=l..r-1} m-(ar-ai+k)
\sum{i=l..r-1} m-ar+ai-k
(r-l)*(m-ar-k) + \sum{i=l..r-1} ai


m-(ar-al-k)>0
m+k+al>ar

ar-al-k>0
ar>al+k

aR+k<ar<aL+k+m

\sum{i=L..R} m-(ar-ai-k)
\sum{i=L..R} m-ar+ai+k
(R-L+1)*(m-ar+k) + \sum{i=L..R} ai
*/
