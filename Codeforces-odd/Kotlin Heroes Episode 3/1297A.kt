fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun main(args: Array<String>)
{
    var t=readint()
    while(t-->0)
    {
        var a=readint()
        if(a>=0&&a<=999) println("${a}")
        else if(a>=1000&&a<=999499)
        {
            a=(a+500)/1000
            println("${a}K")
        }
        else
        {
            a=(a+500000)/1000000
            println("${a}M")
        }
    }
}