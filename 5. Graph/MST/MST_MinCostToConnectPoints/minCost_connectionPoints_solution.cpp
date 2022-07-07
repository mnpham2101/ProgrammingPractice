#include<iostream>
#include<queue>
#include<functional>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>

using namespace std;

class edge_point {
public:
    int point1;
    int point2;
    int manhattan_distance;
    edge_point(int point1, int point2, int manhattan_distance)
        : point1(point1), point2(point2), manhattan_distance(manhattan_distance) {}
};

// Overload the < operator.
bool operator<(const edge_point& edge1, const edge_point& edge2) {
    return edge1.manhattan_distance > edge2.manhattan_distance;
}

class UnionFind {
public:
    UnionFind(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

private:
    vector<int> root;
    vector<int> rank;
};

class Solution {
public:
    // Kruskal's algorithm
    int minCostConnectPoints(vector<vector<int>>& points) {
        if (points.size() == 0) {
            return 0;
        }
        int numberOfPoints = points.size();
        priority_queue<edge_point> edgeList;
        UnionFind unionFind(numberOfPoints);
        cout<<"-- loop adding sorted edges --"<<endl;
        for (int i = 0; i < numberOfPoints; i++) {
            vector<int>& currentPoint = points[i];
            for (int j = i + 1; j < numberOfPoints; j++) {
                vector<int>& nextPoint = points[j];
                int x1 = currentPoint[0];
                int x2 = nextPoint[0];
                int y1 = currentPoint[1];
                int y2 = nextPoint[1];
                cout<<" (x1,y1)=("<<x1<<","<<y1<<"),(x2,y2)=("<<x2<<","<<y2<<") ";
                int manhattan_distance = abs(x1 - x2) + abs(y1- y2);
                edge_point edge(i, j, manhattan_distance);
                edgeList.push(edge);
                cout<<"add edge: "<<manhattan_distance<<endl;
            }
        }
        cout<<"-- end loop adding sorted edges --"<<endl;

        cout<<"-- start loop adding distance --"<<endl;
        int result = 0;
        int numberOfEdge = numberOfPoints - 1;
        // while (!edgeList.empty() && numberOfEdge > 0) {
        for ( int numberOfEdge = 1; numberOfEdge < points.size(); numberOfEdge++){   // number of edges count from 1 to N-1
            edge_point tmpEdge = edgeList.top();                // shallow/default constructor copy
            if (unionFind.connected(tmpEdge.point1, tmpEdge.point2)){
                cout<<"adding edge "<<tmpEdge.manhattan_distance<<" will cause looping"<<endl;
                edgeList.pop();
                numberOfEdge--;         //doesn't add up the edge count
            }
            else {
                edgeList.pop();
                unionFind.unionSet(tmpEdge.point1, tmpEdge.point2);
                cout<<"add distance "<<tmpEdge.manhattan_distance<<" ";
                result += tmpEdge.manhattan_distance;

            }
        }
        cout<< "-- end loop adding distance -- result: "<<result<<endl;
        return result;
    }
};

int main() {
    vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    Solution solution;
    solution.minCostConnectPoints(points);
    return 0;
}