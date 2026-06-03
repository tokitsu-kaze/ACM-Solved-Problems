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
const val mod=1e9.toInt()+7
/*------------------------------------------------------------*/
fun qpow(aa:Long,bb:Int,p:Int):Long
{
	var res=1L
	var a=aa
	var b=bb
	while(b>0)
	{
		if((b and 1)==1) res=res*a%p
		a=a*a%p
		b=b shr 1
	}
	return res
}
fun inv(x:Long):Long
{
	return qpow(x,mod-2,mod)
}
var fac=LongArray(1)
var invfac=LongArray(1)
fun init_comb(n:Int)
{
	fac=LongArray(n+1)
	invfac=LongArray(n+1)
	fac[0]=1
	for(i in 1..n) fac[i]=fac[i-1]*i%mod
	invfac[n]=inv(fac[n])
	for(i in n-1 downTo 0) invfac[i]=invfac[i+1]*(i+1)%mod
}
fun C(n:Int,m:Int):Long
{
	if(m>n||m<0||n<0) return 0L
	return fac[n]*invfac[m]%mod*invfac[n-m]%mod
}
fun go()
{
	var T=readint()
	require(1<=T && T<=2e4)
	var sumn=0
	init_comb(200000)
	var res=mutableListOf<Long>()
	while(T-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==2)
		var n=tmp_line[0]
		var m=tmp_line[1]
		require(1<=n && n<=2e5)
		require(1<=m && m<=1e9)
		sumn+=n
		require(sumn<=2e5)
		var a=readline_int()
		require(a.size==n)
		var cnt=IntArray(n+1){0}
		for(it in a)
		{
			require(1<=it && it<=n)
			cnt[it]++
		}
		var tot=0
		var ans=1L
		for(i in 1..n)
		{
			if(cnt[i]==0) continue
			if(cnt[i]%i!=0)
			{
				ans=0L
				break
			}
			var j=cnt[i]
			while(j>0)
			{
				ans=ans*C(j,i)%mod
				j-=i
				tot++
			}
			ans=ans*invfac[cnt[i]/i]%mod
		}
		for(i in 1..tot)
		{
			ans=ans*m%mod
			m=max(m-1,0)
		}
		res.add(ans)
	}
	println(res.joinToString("\n"))
}

