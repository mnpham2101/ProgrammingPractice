class Solution {
    fun fib(n: Int): Int {
        if (n<=1)
            return n
        val result = ArrayList<Int>(Collections.nCopies(n+1, 0))
        result[0]=0
        result[1]=1
        for (i in 2..n){
            println(i)
            result[i] = result[i-1]+result[i-2]      
        }
            
        return result[n];
    }
}