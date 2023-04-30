class Solution {
    var counter = ArrayList<Int>()

    fun climbStairs(startingStep: Int, endingStep: Int ) : Int {
        if (counter[startingStep]>0)
            return counter[startingStep]
        if (startingStep == endingStep){
            counter[startingStep]=1
            return counter[startingStep]
        }
        else if (startingStep < endingStep){
            counter[startingStep] = climbStairs (startingStep+1, endingStep) + climbStairs(startingStep+2, endingStep)
            return counter[startingStep]
        }        
        else
            counter[startingStep]=0
            return counter[startingStep]
    }
    fun climbStairs(n: Int): Int {
        for (i in 0..n+1){
            counter.add(0)
        }        
        return climbStairs(1, n) + climbStairs(2,n)
    }
}