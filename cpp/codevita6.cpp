#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x,y;
    bool operator<(const Point &o)const{
        return x<o.x || (x == o.x && y < o.y);
    }
    bool operator==(const Point &o) const {
        return x == o.x && y == o.y;
    }
};
int numCycles = 0;
vector<vector<int>> adjList;
int homeIndex;
void dfs(int current, vector<bool> &visited, int pathLength) {
    for (int neighbor : adjList[current]) {
        if (neighbor == homeIndex && pathLength >= 2) {
            numCycles++;
            continue;
        }
        if (!visited[neighbor]) {
            visited[neighbor] = true;
            dfs(neighbor, visited, pathLength + 1);
            visited[neighbor] = false;
        }
    }
}
int main() {
    int N;
    cin >> N;
    map<Point, int> pointToIndex;
    vector<Point> allPoints;
    int pointCount = 0;
    vector<pair<int,int>> edges;
    vector<pair<Point, Point>> paths(N);
    for (int i = 0; i < N; i++) {
        Point p1, p2;
        cin >> p1.x >> p1.y >> p2.x >> p2.y;
        paths[i] = {p1, p2};
        if (!pointToIndex.count(p1)) {
            pointToIndex[p1] = pointCount++;
            allPoints.push_back(p1);
        }
        if (!pointToIndex.count(p2)) {
            pointToIndex[p2] = pointCount++;
            allPoints.push_back(p2);
        }
    }
    Point home;
    cin >> home.x >> home.y;
    if (!pointToIndex.count(home)) {
        cout << 0 << "\n";
        return 0;
    }
    homeIndex = pointToIndex[home];
    adjList.assign(pointCount, {});
    for (auto &p : paths) {
        int u = pointToIndex[p.first];
        int v = pointToIndex[p.second];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    vector<bool> visited(pointCount, false);
    visited[homeIndex] = true;
    dfs(homeIndex, visited, 0);
    cout << numCycles/2<< endl;
    return 0;
}
