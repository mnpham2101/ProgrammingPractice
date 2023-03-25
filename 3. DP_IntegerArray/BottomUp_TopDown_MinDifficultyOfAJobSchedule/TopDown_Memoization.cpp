class Solution {
public:
    vector<vector<int>> cache;  //row: startingIndex of job on currentDay, col: currentDay, starting from 0
    int difficulty ( vector<int>& jobDifficulty, int startingIndex, int currentDay, int maxDay ){
        // cout<<"startingIndex: "<<startingIndex<<" currentDay "<<currentDay<<endl;
        int remainingDay = maxDay - currentDay;
        int maxNumberOfJobInTheDay = jobDifficulty.size() - remainingDay;
        // memoization: 
        if (cache[startingIndex][currentDay] != -1)
            return cache[startingIndex][currentDay];
        // base case: if there is 1 day remaining, finish all jobs
        // difficulty is the max difficulty of the remaining jobs
        if ( remainingDay  == 1 ){
            int result =  *std::max_element( begin(jobDifficulty) + startingIndex, end(jobDifficulty) );
            // cout<<"     result difficulty on last day "<<result<<endl;
            return result; 
        }
        // recursive cases:
        int dailyMaxJobDiff = 0;
        int nextDayJobDiff = 0;
        int result = INT_MAX;
        // DFS process: the for loop runs like a stack (FIFO)
        // it goes deeper in each branch, branch i =0, i = 1, i = ..., i = maxNumberOfJobInTheDay
        for (int i = startingIndex; i <= maxNumberOfJobInTheDay; i++) {
            // cout<<"   job "<<i<<" "<<" difficulty "<<jobDifficulty[i]<<endl;
            dailyMaxJobDiff = max (jobDifficulty[i], dailyMaxJobDiff) ;
            // cout<<"   dailyMaxJobDiff=  "<<dailyMaxJobDiff<<endl;
            nextDayJobDiff = difficulty(jobDifficulty, i+1, currentDay+1, maxDay);      // recursive case: goes deeper, thus i+1 is used as input
            result = min(dailyMaxJobDiff + nextDayJobDiff, result  );
            // cout<<"     min difficulty on this branch "<<result<<endl; 
        }
        return cache[startingIndex][currentDay]=result;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        cache.resize(jobDifficulty.size(), vector<int>(d,-1));
        if (jobDifficulty.size() < d)
            return -1;                   // cannot assign the work during the number of day
        return difficulty(jobDifficulty, 0, 0, d);
    }
};