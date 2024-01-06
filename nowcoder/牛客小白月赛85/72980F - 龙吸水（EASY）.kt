import java.util.*
import kotlin.math.*

fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readdb()=readLine()!!.toDouble()
fun readstring()=readLine()!!
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun readline_db()=(readLine()!!.split(" ").map{it.toDouble()}).toDoubleArray()
fun main(args: Array<String>){go()}
inline fun <T:Number> lower_bound_pos(
a:MutableList<T>,L:Int,R:Int,target:T):Int{
	var l=L
	var r=R
	var mid:Int
	while(l<r){
		mid=(l+r) shr 1
		if(a[mid].toLong()>=target.toLong()) r=mid
		else l=mid+1
	}
	return l
}
data class pair(var fi:Int,var se:Int)
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
    if (a.fi==b.fi) a.se.compareTo(b.se)
    else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=2e5.toInt()+10
/*------------------------------------------------------------*/
fun go()
{
    var tmp_line=readline_int()
    var n=tmp_line[0]
    var l=tmp_line[1]
    var r=tmp_line[2]
    require(n>=1 && n<=5000)
    require(l>=1 && l<=1e9)
    require(r>=l && r<=1e9)
    var a=readline_int()
    require(a.size==n)
    for(it in a) require(it>=0 && it<=5000)
    var res=Array<Int>(n+1){0}
    for(i in 2..n) res[i]=a[i-1]-a[i-2]
    res[1]=0
    var ans=0
    var dp=Array(n+2){IntArray(5002)}
    for(j in 0..5000){dp[0][j]=0}
    for(i in 1..n){
        for(j in 0..5000){dp[i][j]=0}
        for(j in 0..5000){
            var tmp=max(0,j+res[i])
            if(tmp>5000) break
            dp[i][tmp]=max(dp[i-1][j],dp[i][tmp])
        }
        var mx=0
        for(j in 5000 downTo 0)
        {
            mx=max(mx,dp[i][j])
            if(j<=a[i-1]) {
                dp[i][j]=mx
                if(j>=l&&j<=r) dp[i][j]++
            }
            ans=max(ans,dp[i][j])
        }
    }
    println("${ans}")
}
