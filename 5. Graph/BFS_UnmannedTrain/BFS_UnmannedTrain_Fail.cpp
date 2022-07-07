#include <queue>
#include <vector>
#include <iostream>
using namespace std;

typedef struct Node{
    int x; 
    int y;
} Node; 

queue<Node> traversingQueue;            // has regionA node=2 and node=0
queue<Node> regionA;                    // has regionA node=2 after running flood fill algorithm on inputArray
int N, M;
int inputArray[50][50];

// apply flood fill (also BFS) algorithm 
// find adjacent node of inputArray[nodeA.x][nodeA.y], if they are 1, change to 2.
void markRegionA(Node nodeA){
    inputArray[nodeA.x][nodeA.y] = 2;                   // mark the first node as regionA
    regionA.push(nodeA);
    while (!regionA.empty()){
        // Step1:      
        Node currentNode;
        currentNode.x = regionA.front().x;    
        currentNode.y = regionA.front().y; 
        // Step2:
		regionA.pop();
        traversingQueue.push(currentNode);
        // Step3:find adjacent node of a nodeA in region A, push to traversingQueue
        int adjX[] = {0,-1,0,1};
        int adjY[] = {-1,0,1,0};
        Node adjNode;
        
        for (int i=0; i<=3; i++){
            adjNode.x = currentNode.x + adjX[i];
            adjNode.y = currentNode.y + adjY[i];
            if (adjNode.x < 0 || adjNode.x >= N) continue; 
            if (adjNode.y < 0 || adjNode.y >= M) continue; 
            // Step4: mark adjNode=1 as 2 to fill region A
            if (inputArray[adjNode.x][adjNode.y] == 1){
                regionA.push(adjNode);
				inputArray[adjNode.x][adjNode.y] = 2;
            }
        }
    }
    // Log
    for (int i=0; i<N; i++){
        for (int j=0; j<M;j++){
            cout<<inputArray[i][j]<<" ";
        }
        cout<<endl;
    }
}


int shortestPath_BFS(){
	int adjX[4] = {0,-1,0,1};
	int adjY[4] = {-1,0,1,0};
	int counter = 0;
	while (!traversingQueue.empty()){
		Node currentNode = traversingQueue.front();
		Node adjNode; 
		traversingQueue.pop();
        int counter=0;
		// process adjNode
		for (int i=0; i<=3; i++){
            adjNode.x = currentNode.x + adjX[i];
            adjNode.y = currentNode.y + adjY[i];
            if (adjNode.x < 0 || adjNode.x >= N) continue; 
            if (adjNode.y < 0 || adjNode.y >= M) continue; 
            if (inputArray[adjNode.x][adjNode.y] == 1){
                // return inputArray[currentNode.x][currentNode.y]-2;
                return counter;
            }
            if (inputArray[adjNode.x][adjNode.y] == 0){
                traversingQueue.push(adjNode);
                // inputArray[adjNode.x][adjNode.y] = inputArray[currentNode.x][currentNode.y]+1;
                counter++;
            }
		}
	}
}

int main(){
    // accept inputArray size and populate its value
    cin>>N>>M;
    
    for (int i=0; i<N;i++){
        for (int j=0; j<M;j++){
            cin>>inputArray[i][j];
        }
    }

    // search for the first node == 1, if found, start solving the problem, return result without continuing the loop
    for (int i=0; i<N;i++){
        for (int j=0; j<M;j++){
            if (inputArray[i][j] == 1){
                Node nodeA = {i,j};
                
                // mark region A push adjacentList if aPoint to traversingQueue
                markRegionA(nodeA);
                int result = shortestPath_BFS();
                cout<<"Result: "<<result<<endl;
                return 0;
            }
        }
    }
    return 0;
}