#include "Solution.h"

Solution::Solution(){
    newGame();
}

Solution::~Solution(){

}

void Solution::newGame(){
    generateRandomMatrix();
    generateGraph();
}

void Solution::generateRandomMatrix(){
    srand(time(NULL));

    for(int i=0; i<10; ++i){
        for(int j=0; j<10; ++j){
            gameMatrix[i][j] = rand()%30+1;
        }
    }
}

void Solution::generateGraph(){

    for (int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            adjList* l = newAdjList(i, j);
            setAdjs(gameMatrix, l);
            graph.push_back(l);
        }
    }
}

int Solution::getSolution(){
    return Dijkstra::run(graph, 0, 99);
}

