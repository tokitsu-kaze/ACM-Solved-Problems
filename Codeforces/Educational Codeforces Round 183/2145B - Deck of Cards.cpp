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
const val MAX=1e5.toInt()+10
const val mod=1e9.toInt()+7
/*------------------------------------------------------------*/
fun go()
{
	var T=readint()
	require(1<=T && T<=100)
	while(T-->0)
	{
		var n=readint()
		require(1<=n && n<=2000)
		var a=IntArray(n+1)
		var l=IntArray(n+1)
		var r=IntArray(n+1)
		for(i in 0..n-1)
		{
			var tmp_line=readline_int()
			require(tmp_line.size==3)
			a[i+1]=tmp_line[0]
			l[i+1]=tmp_line[1]
			r[i+1]=tmp_line[2]
			require(0<=a[i+1] && a[i+1]<(1 shl 10))
			require(0<=l[i+1] && l[i+1]<(1 shl 10))
			require(0<=r[i+1] && r[i+1]<(1 shl 10))
			require(l[i+1]<=r[i+1])
		}
		var dp=IntArray(1024){0}
		for(i in 0..a[1]) dp[i]=1
		for(i in 1..1023) dp[i]+=dp[i-1]
		for(i in 2..n)
		{
			var ndp=IntArray(1024){0}
			for(j in 0..1023)
			{
				if(dp[j]==0) continue
				for(k in 0..a[i])
				{
					if(i%2==0)
					{
						ndp[abs(k-j)]+=dp[j]
						if(ndp[abs(k-j)]>=mod) ndp[abs(k-j)]-=mod
					}
					else
					{
						if((j xor k)>=l[i-1] && (j xor k)<=r[i-1])
						{
							ndp[k]+=dp[j]
							if(ndp[k]>=mod) ndp[k]-=mod
						}
					}
				}
			}
			dp=ndp
		}
		var ans=0
		for(i in 0..1023)
		{
			ans+=dp[i]
			if(ans>=mod) ans-=mod
		}
		println("${ans}")
	}
}

