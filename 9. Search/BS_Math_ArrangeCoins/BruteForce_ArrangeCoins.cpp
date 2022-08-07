class Solution {
public:
    int arrangeCoins(int n) {
        int row = 0, coinsPerRow=0;
        while ( n>0 ){
            row++; 
            n -= (++coinsPerRow);           // BUG: error if n -= (coinsPerRow++)
            if (n<=coinsPerRow)             // not enough coins for next row
                return row;     
        }
        return row;
    }
};