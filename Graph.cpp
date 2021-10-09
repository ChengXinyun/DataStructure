#include <iostream>
using namespace std;

//广度优先算法
/*
bool visited[MAX_NUM];
Queue Q;
void BFS_Traverse(Graph G){
    for(int i = 0; i < G.vnum(); i++){
        visited[i] = false;
    }
    InitQueue(Q);
    for(int i = 0; i < G.vnum(); i++){
        if(!visited[i]){
            BFS(G, i);
        }
    }
}
void BFS(Graph G, int v){
    visit(v);
    visited[v] = true;
    EnQueue(Q, v);
    while(!Q.empty()){
        DeQueue(Q, v);
        for(w = FirstNeighbor(G, v); w >= 0; w = nextNeighbor(G, v)){
            if(!visited[w]){
                visit(w);
                visited[w] = true;
                EnQueue(Q, w);
            }
        }
    }
}
*/

// 深度优先搜索
/*
bool visited[MAX_NUM];
void DFS_Traverse(Graph G){
    for(int i = 0; i < G.vnum(); i++){
        visited[i] = false;
    }
    for(int i = 0; i < G.vnum(); i++){
        if(!visited[i]){
            DFS(G, i);
        }
    }
}
void DFS(Graph G, int v){
    visit(v);
    visited[v] = true;
    for(w = FirstNeighbor(); w >= 0; w = nextNeighbor()){
        if(!visited[w]){
            DFS(G, w);
        }
    }
}
*/