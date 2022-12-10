import java.io.BufferedReader
import java.io.InputStreamReader

fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))) {
    val idx = Array(200001) { 0 }
    val sb = StringBuilder()

    var l = 1
    var r = 0

    repeat(readLine().toInt()) {
        val (op, _i) = readLine().split(' ')
        val i = _i.toInt()

        when (op) {
            "L" -> {
                l--
                idx[i] = l
            }
            "R" -> {
                r++
                idx[i] = r
            }
            "?" -> {
                sb.appendln(Math.min(idx[i] - l, r - idx[i]))
            }
        }
    }

    println(sb.toString())
}
