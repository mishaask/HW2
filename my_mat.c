#include "my_mat.h"
#include <stdio.h>

void buildMatrix(int Matrix[Msize][Msize]) {
    
    //printf("Enter elements for the matrix:\n");
    for (int i = 0; i < Msize; ++i) {
        for (int j = 0; j < Msize; ++j) {
            scanf("%d", &Matrix[i][j]);
            //printf("Matrix[%d][%d] = %d\n",i ,j,Matrix[i][j]);
        }
    }
}

int isThereAPath(int Matrix[Msize][Msize]){
    if(shortestPath(Matrix) != -1){
        return 1;
    }
    return 0;
}
int shortestPath(int Matrix[Msize][Msize]){

    int start;
    int destination;
    scanf("%d", &start);
    scanf("%d", &destination);

    if(start == destination)
        return -1;
    
    int dist[Msize];  //represents distance of each node from out start
    int visited[Msize] = {0}; //if node was visited its set to 1

    for (int i = 0; i < Msize; i++) {
        dist[i] = INF; //initialise all distances as 2147483647 the max possible int
    }

    dist[start] = 0;

    for (int count = 0; count < Msize - 1; count++) { //for loop that iterated the same amount as we have nodes and each time chooses a node which was not visited and has the smallest distance
        
        int u = -1;
        for (int v = 0; v < Msize; v++) {// go through all nodes and end up with u = the node which wasnt visited and has smallest distance
            if (visited[v] == 0 && (u == -1 || dist[v] < dist[u])) {
                u = v;
            }
        }
        if (u == -1 || u == destination) {
            break; // no vertices to visit or destination reached
        }
        visited[u] = 1;

        // update distances to adjacent vertices
        for (int v = 0; v < Msize; v++) {
            if (visited[v] == 0 && Matrix[u][v] && dist[u] != INF && dist[u] + Matrix[u][v] < dist[v]) {//if not visited && have path && not an unreachable vertex(when start node is isolated) && combined distance smaller then existing distance 
                dist[v] = dist[u] + Matrix[u][v];
            }
        }
    }

    // return the shortest path weight
    if (dist[destination] == INF)  
        return -1;
    else  
        return dist[destination];
}
