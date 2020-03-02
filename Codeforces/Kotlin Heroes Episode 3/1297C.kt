fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
data class pair(var fi:Int,var se:Int)
fun main(args: Array<String>)
{
    var t=readint()
    while(t-->0)
    {
        var n=readint()
        var a=readline_int()
        var res:MutableList<pair> =mutableListOf()
        for(i in 0 until n)  res.add(pair(a[i],i))
        res.sortBy({it.fi})
        var ans=Array(n){0}
        var mn=10000000
        var sum=0
        var pos=0
        var mx=-10000000
        var posmx=0
        for(i in n-1 downTo 0)
        {
            if(res[i].fi>0)
            {
                ans[res[i].se]=1
                sum+=res[i].fi
                mn= minOf(mn,res[i].fi)
                if(res[i].fi==mn) pos=res[i].se
            }
            else if(res[i].fi<0)
            {
                mx= maxOf(res[i].fi,mx)
                if(res[i].fi==mx) posmx=res[i].se
            }
        }
        if(mx!=-10000000)
        {
            if(sum-mn<sum+mx)
            {
                ans[posmx]=1
                sum+=mx
            }
            else
            {
                ans[pos]=0
                sum-=mn
            }
        }
        else
        {
            ans[pos]=0
            sum-=mn
        }
        println("${sum}")
        for(i in 0 until n) print("${ans[i]}")
        println()
    }
}