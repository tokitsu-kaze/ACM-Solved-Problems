fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun main(args: Array<String>)
{
    var t=readint()
    while(t-->0)
    {
        var n=readint()
        var a=Array(n+1){0}
        var b=Array(n+1){0}
        var res=Array(6*n+1){0}
        var tot=0
        for(i in 0 until n)
        {
            var tmp=readline_int()
            a[i]=tmp[0]
            b[i]=tmp[1]
            res[tot]=a[i]-1
            tot++
            res[tot]=a[i]
            tot++
            res[tot]=a[i]+1
            tot++
            res[tot]=b[i]-1
            tot++
            res[tot]=b[i]
            tot++
            res[tot]=b[i]+1
            tot++
        }
        if(n==1)
        {
            println("${a[0]}")
            continue
        }
        var ans=-1
        for(i in 0 until tot)
        {
            var ok=0
            for(j in 0 until n)
            {
                if(res[i]<=b[j]&&res[i]>=a[j]) ok++
            }
            if(ok==1)
            {
                ans=res[i]
                break
            }
        }
        println("${ans}")
    }
}