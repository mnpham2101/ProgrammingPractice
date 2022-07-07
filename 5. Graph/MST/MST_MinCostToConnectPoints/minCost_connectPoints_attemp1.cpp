#include<iostream>
#include<queue>
#include<functional>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>

using namespace std;

class Solution {
public:
    // Step 1: create sorted weighted edges (descending order) data queue
    priority_queue<int, vector<int>, greater<int>> sorted_edges;
    typedef struct point {
        int x;
        int y;
        bool visited;
    } point;

    // operator overload = for point
    bool operator == (const point& point1, const point& point2) {
        return ( point1.x == point2.x && point1.y == point2.y) ? true:false;
    }

    typedef struct edge_point {
        point point1;
        point point2;
        int manhattan_distance;
    } edge_point;
    // operator overload > for edge_point_map
    bool operator > (const edge_point& edge1, const edge_point& edge2) {
        return (edge1.manhattan_distance > edge2.manhattan_distance ) ? true:false;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int ret = 0;
        int manhattan_distance = 0;

        // Step 2: add edge (distance) to the edges list
        cout<<"-- loop add sorted edges --"<<endl;
        for ( int currentPoints = 0; currentPoints < points.size(); currentPoints++) {                // row = number of points = points.size()

            for ( int nextPoint = currentPoints+1; nextPoint < points.size(); nextPoint++){          // go from 1 points to the immediate next.
                int x1 = points[currentPoints][0];
                int x2 = points[nextPoint][0];
                int y1 = points[currentPoints][1];
                int y2 = points[nextPoint][1];
                point point1;
                point1.x= x1;
                point1.y= y1;
                point point2;
                point2.x= x2;
                point2.y= y2;
                cout<<" (x1,y1)=("<<x1<<","<<y1<<"),(x2,y2)=("<<x2<<","<<y2<<") ";
                manhattan_distance =  abs(x1-x2) + abs(y1-y2)  ;                       //Note: abs has to be used or will go out of range
                edge_point edge_point;
                edge_point.point1 = point1;
                edge_point.point1 = point2;
                edge_point.manhattan_distance = manhattan_distance;
                sorted_edges.push(edge_point);                // push will return descending order,
                cout<<"add edge: "<<manhattan_distance<<endl;
            }
        }
        cout<<"-- end loop add sorted edges --"<<endl;
        // Step 2.1: check the condition that no edge creates a loop
        // Step 2.2: only N-1 edges are needed => sort out the lowest 3 edges
        for ( int currentPoints = 1; currentPoints < points.size(); currentPoints++){   // number of edges count from 1 to N-1
            ret += sorted_edges.top();
            sorted_edges.pop();
            cout<<"ret: "<<ret<<endl;
        }
        // Step 3: calculate total distance and return result
        return ret;
    };
};

int main(){
    Solution sol;
    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    int ret = sol.minCostConnectPoints(points);
    cout<<"Shortest cost connection: "<<ret<<endl;
    return 0;
}