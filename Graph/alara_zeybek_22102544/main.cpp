#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int inf = 99999999;
int minPath(int dist[], int V, bool visited[]){
    int min = inf;
    int index = 0;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            index = v;
            min = dist[v];
        }
    }
    return index;
}
int main(int argc, char *argv[]) {
    freopen(argv[1], "r", stdin);

    int routerNum, garbage;
    scanf("%d",&routerNum);
    // initializing the graph
    int infinity = routerNum + 1;
    int** r = new int*[routerNum];
    int* visitedvertex = new int[routerNum];
    for(int i = 0; i<routerNum;i++){
        r[i] = new int[routerNum];
        for(int j = 0; j<routerNum; j++){
            r[i][j] = infinity;
            if (i==j){
                r[i][j] = 0;
            }
        }
    }

    string line;
    getline(cin, line);
    for (int i = 0; i < routerNum; ++i) {
        getline(cin, line);
        stringstream ss(line);
        // cout<<"router num: "<<routerNum<< " string: "<<line<<endl;
        int id, degree, num;
        ss >> id;
        ss >> degree;
        while (ss >> num) {
            //cout << "num for "<<i<<" :" << num<<endl;
            r[i][num] = 1; //there exist a road with 1 weight
        }
    }

    int from = stoi(argv[2]);
    int to = stoi(argv[3]);
    int* result = new int[routerNum];
    int r_index = 0;
    int* previous = new int[routerNum];

    int* dist = new int[routerNum]; // The output array.

    bool* visited = new bool[routerNum];

    // Initialize all distances as INFINITE and stpSet[] as 0
    for (int i = 0; i < routerNum; i++) {
        dist[i] = inf;
        visited[i] = false;
        previous[i] = -1;
    }

    dist[from] = 0;

    // Shortest path
    for (int a = 0; a < routerNum - 1; a++) {
        int u = minPath(dist,routerNum, visited);
        // Mark the picked vertex
        visited[u] = true;

        for (int v = 0; v < routerNum; v++) {
            if (r[u][v] && dist[u] != inf && !visited[v] && dist[u] + r[u][v] < dist[v]) {
                dist[v] = dist[u] + r[u][v];
                previous[v] = u; // Update previous node
            }
        }
    }

    cout << "Path consists of " << dist[to]+1 << " routers:" << endl;

    int current = to;
    while (current != from) {
        //cout << current << endl;
        result[r_index++]=current;
        current = previous[current];
    }
    result[r_index] = from;
    while(r_index >= 0){
        cout << result[r_index--] << endl;
    }

    // Diameter -> Do the same but start at the begining
    from = 0;
    for (int i = 0; i < routerNum; i++) {
        dist[i] = inf;
        visited[i] = false;
    }
    dist[from] = 0;
    for (int a = 0; a < routerNum - 1; a++) {
        int u = minPath(dist,routerNum, visited);
        visited[u] = true;
        for (int v = 0; v < routerNum; v++) {
            if (!visited[v] && r[u][v]
                && dist[u] != inf
                && dist[u] + r[u][v] < dist[v]) {
                dist[v] = dist[u] + r[u][v];
            }
        }
    }
    int max = 0;
    for (int i= 0; i< routerNum; i++){
        if (dist[i] > max){
            max = dist[i];
        }
    }
    cout << "Diameter of the graph is  " << max << endl;

    // Free dynamically allocated memory
    for (int i = 0; i < routerNum; i++) {
        delete[] r[i];
    }
    delete[] r;
    delete[] visitedvertex;
    delete[] result;
    delete[] previous;
    delete[] dist;
    delete[] visited;

    return 0;
}
