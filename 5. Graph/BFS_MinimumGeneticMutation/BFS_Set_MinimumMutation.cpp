#include<queue>
#include<vector>
#include<unordered_set>
#include<string>
using namespace std;

class Solution {
private:
    vector<char> gene = {'A','C','G','T'};
    //Step 2: Made a vector of string for storing all possible mutation from gene string
    vector<string> findMutate(string& geneSequence,int pos){
        vector<string> mutateList(4,geneSequence);              // there will be 4 mutates
        for(int j=0;j<4;j++){
            mutateList[j][pos] = gene[j];
        }
        return mutateList;
    }
public:
    int minMutation(string start, string end, vector<string>& bank) {
        // Step1: create set for for query
        unordered_set<string> validGene;
        for(int i=0;i<bank.size();i++){ // Inserting all ellement of banks in set
            validGene.insert(bank[i]);
        }
        
        //special case
        if(!validGene.count(end)) return -1;        // If end is not present in bank
        if(start==end) return 0;                    // if there is no mutation
        
        // Step 3: start BFS
        int result=0;
        queue<string> bfsQueue;
        bfsQueue.push(start);
             
        while (!bfsQueue.empty()){
            int n = bfsQueue.size(); 
            result++;                               // for each valid mutate, increment counting
            // Step 3.1: for every item already in bfsQueue, mutate them 
            for (int i = 0; i< n; i++){             
                string curr = bfsQueue.front();     // create a mutate from 
                cout<<"curr "<<curr<<endl;
                bfsQueue.pop();
                // Step 3.2: mutation happens to a single char along the original sequence
                for (int i=0; i<curr.size(); i++){    
                    vector<string> mutateList(4);
                    mutateList = findMutate(curr, i);
                    for (string mutate : mutateList){
                        cout<<"     "<<mutate<<endl;
                        if (validGene.find(mutate) !=validGene.end()){
                            
                            // Step 3.4: break when end is found
                            if (mutate == end)          
                                return result;
                            bfsQueue.push(mutate);
                            // Step 3.3: mark the mutate as visited by removing it from bank
                            validGene.erase(mutate);
                        }
                    }
                }
            }
        }
        // bfsQueue is empty is all mutation is found, but the end sequence is not found. 
        return -1;
    }
};