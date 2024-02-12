#include <stdio.h>
#include "my_mat.h"

int main() {
    char userInput;
    int Matrix[Msize][Msize];

//printf("Welcome to my_graph\n");
//printf("Please enter a letter grom A-D\n");
scanf("%c", &userInput);


while(userInput!= 'D' && userInput!= EOF){
    if(userInput== 'A'){//if user inputs 'A' then start building a matrix
        buildMatrix(Matrix);
       // printf("Matrix is built\n");

    }
    else if(userInput== 'B'){// if user input B use shortestPath to find isThereAPath
        int pathExists = isThereAPath(Matrix);
        if(pathExists == 1) printf("True\n");
        else printf("False\n");
    }

    else if(userInput== 'C'){//if input is C use Dijkstra's algorithmto find the weight of the shortest path
        printf("%d\n",shortestPath(Matrix));
    }

    scanf("%c", &userInput);

}
return 0;
}