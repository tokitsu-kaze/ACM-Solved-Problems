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
const val mod=998244353L
/*------------------------------------------------------------*/
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==2)
	var n=tmp_line[0]
	var m=tmp_line[1]
	require(n>=1 && n<=1e6)
	require(m>=1 && m<=1e6)
	var s=readstring()
	require(s.length==n)
	var cnt0=IntArray(n+2)
	var cnt1=IntArray(n+2)
	var sum0=LongArray(n+2)
	var sum1=LongArray(n+2)
	var res=LongArray(n+2)
	cnt0[0]=0
	cnt1[0]=0
	sum0[0]=0
	sum1[0]=0
	res[0]=0
	for(i in 1..n)
	{
		require(s[i-1]=='0'||s[i-1]=='1')
		cnt0[i]=cnt0[i-1]
		cnt1[i]=cnt1[i-1]
		sum0[i]=sum0[i-1]
		sum1[i]=sum1[i-1]
		res[i]=res[i-1]
		if(s[i-1]=='0')
		{
			cnt0[i]++
			sum0[i]=(sum0[i]+i)%mod
			res[i]=(res[i]+1L*i*cnt1[i-1]-sum1[i-1])%mod
		}
		else
		{
			cnt1[i]++;
			sum1[i]=(sum1[i]+i)%mod
			res[i]=(res[i]+1L*i*cnt0[i-1]-sum0[i-1])%mod
		}
	}
	var ans_seq=mutableListOf<Long>()
	while(m-->0)
	{
		tmp_line=readline_int()
		require(tmp_line.size==2)
		var l=tmp_line[0]
		var r=tmp_line[1]
		require(l>=1 && l<=n)
		require(r>=l && r<=n)
		var ans=res[r]-res[l-1]
		ans-=(sum1[r]-sum1[l-1])*cnt0[l-1]-(cnt1[r]-cnt1[l-1])*sum0[l-1]
		ans-=(sum0[r]-sum0[l-1])*cnt1[l-1]-(cnt0[r]-cnt0[l-1])*sum1[l-1]
		ans%=mod
		if(ans<0) ans+=mod
		ans_seq.add(ans)
	}
	println(ans_seq.joinToString("\n"))
}

