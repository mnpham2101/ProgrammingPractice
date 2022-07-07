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

    typedef struct point {
        int x;
        int y;
        // == operator overload
        bool operator == (const point& point1) {
            return ( this->x == point1.x && this->y == point1.y) ? true:false;
        }
        // assignment operator overload
        point& operator = (const point& point1) {   // assigment change value==> should return reference
            x = point1.x;
            y = point1.y;
            return *this;  // must de-reference the pointer
        }
    } point;

    typedef struct edge_point {
        point point1;
        point point2;
        int manhattan_distance;
        // operator overload = for edge_point
        edge_point& operator = (const edge_point& edge1) {
            point1 = edge1.point1;
            point2 = edge1.point2;
            manhattan_distance = edge1.manhattan_distance;
            return *this;
        }
        bool operator > (const edge_point& edge1) {
            return (manhattan_distance > edge1.manhattan_distance );
        }
    } edge_point;
    bool operator () (const edge_point& edge1, const edge_point& edge2) {
            return (edge1.manhattan_distance > edge2.manhattan_distance );
        }
    // operator overload > for edge_point to use with std::greater()
    struct compareGreater{
        bool operator () (const edge_point& edge1, const edge_point& edge2) {
            return (edge1.manhattan_distance > edge2.manhattan_distance );
        }
    };

    vector<point> visisted;
    bool looping(edge_point edge_point){
        if ( find(visisted.begin(),visisted.end(),edge_point.point1) != visisted.end()
             &&
             find(visisted.begin(),visisted.end(),edge_point.point2) != visisted.end()
             ){
                 return true;
             }
        else return false;
    };

    // Step 1: create sorted weighted edges (descending order) data queue
    priority_queue<edge_point, vector<edge_point>, greater<>> sorted_edges;

    int minCostConnectPoints(vector<vector<int>>& points) {
        int ret = 0;
        int manhattan_distance = 0;

        // Step 2: add edge (distance) to the edges list
        cout<<"-- loop add sorted edges --"<<endl;
        for ( int currentPoints = 0; currentPoints < points.size(); currentPoints++) {                // row = number of points = points.size()s
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
                edge_point.point2 = point2;
                edge_point.manhattan_distance = manhattan_distance;
                sorted_edges.push(edge_point);                // push will return descending order,
                cout<<"add edge: "<<manhattan_distance<<endl;
            }
        }
        cout<<"-- end loop add sorted edges --"<<endl;

        cout<<"-- output sorted edges to check--"<<endl;
        // output sorted edges to check - comment out when not need
        while(!sorted_edges.empty()){
            sorted_edges.top();
            cout<<sorted_edges.top().manhattan_distance<<" "<<endl;
            sorted_edges.pop();
        }

        // Step 2.1: only N-1 edges are needed => sort out the lowest 3 edges
        // for ( int numberOfEdge = 1; numberOfEdge < points.size(); numberOfEdge++){   // number of edges count from 1 to N-1
        //     // Step 2.2: check the condition that no edge creates a loop
        //     edge_point tmpPoint = sorted_edges.top();
        //     if (looping(tmpPoint)){
        //         cout<<"--visited points--"<<endl;
        //         cout<<"("<<tmpPoint.point1.x<<","<<tmpPoint.point1.y<<") "<<"is already visited"<<endl;
        //         cout<<"("<<tmpPoint.point2.x<<","<<tmpPoint.point2.y<<") "<<"is already visited"<<endl;
        //         sorted_edges.pop();
        //         numberOfEdge--;         //doesn't add up the edge count
        //     }
        //     else{
        //         cout<<"--add distance--"<<endl;
        //         ret += tmpPoint.manhattan_distance;
        //         visisted.push_back(tmpPoint.point1);
        //         visisted.push_back(tmpPoint.point2);
        //         cout<<"visit ("<<tmpPoint.point1.x<<","<<tmpPoint.point1.y<<")&("<<tmpPoint.point2.x<<","<<tmpPoint.point2.y<<")";
        //         sorted_edges.pop();
        //         cout<<"ret: "<<ret<<endl;
        //     }
        // }
        // Step 3: calculate total distance and return result
        return ret;
    };
};

int main(){
    Solution sol;
    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    vector<vector<int>> points2 = {{0,0},{1,1},{1,0},{-1,1}};
    vector<vector<int>> points3 = {{2,-3},{-17,-8},{13,8},{-17,-15}};
    int ret = sol.minCostConnectPoints(points);
    cout<<"Shortest cost connection: "<<ret<<endl;
    return 0;
}