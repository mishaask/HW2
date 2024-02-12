#include <stdio.h>

#define items 5
#define maxWeight 20
#define namelength 21//20+1 for /n

int knapSack(int weights[], int values[], int selected_bool[]);

int main(){
    char names[items][namelength];
    int weights[items]= {0};
    int values[items]= {0};
    int selected_bool[items] = {0};

    for (int i = 0; i < items; i++) {
        printf("Enter name %d: ", i + 1); //enter names
        scanf("%20s", names[i]); // Limited to 20 chars

        printf("Enter value of %d: ", i + 1); //enter names
        scanf("%d", &values[i]);

        printf("Enter weight of %d: ", i + 1); //enter names
        scanf("%d", &weights[i]); 
    }
    int maxValue = knapSack(weights, values, selected_bool);
    

    printf("\nMaximum profit: %d", maxValue);
    printf("\nSelected items:");
    int first = 1;
    for (int i = 0; i < items; i++) {
        if (selected_bool[i] == 1) {
            // if (!first) {
            //     printf(", ");
            // }
            printf(" %s", names[i]);
            first = 0;
        }
    }
    printf("\n");
    

    return 0;
}

int knapSack (int weights[], int values[] , int selected_bool[]){
    
    int mat[items + 1][maxWeight + 1];//with max 20 char names runtime O(cn) should be good

    // initialize the matrix
    for (int i = 0; i <= items; i++) {
        for (int w = 0; w <= maxWeight; w++) {

            if (i == 0 || w == 0) //no items or no weight is 0
                mat[i][w] = 0;

            else if (weights[i - 1] <= w) { // if item fits the weight limit we either include it or not

                int incl = values[i - 1] + mat[i - 1][w - weights[i - 1]];// if we include we add the items value to the other best option with the remaining weight with i-1 items
                int N_incl = mat[i - 1][w];//if we dont include we just take the best opeion with i-1 items and the same weight
                
                if (incl > N_incl)//we choode the biggest amount to be in matrix[i][w]
                    {mat[i][w] = incl;}
                else
                    {mat[i][w] = N_incl;}

            }else{   //if item goes over weight limit we set it as the next best option mat[items-1][same weight]
                mat[i][w] = mat[i - 1][w];
            }
        }
    }

    //we traverse the matrix and find the selected items
    int w = maxWeight;
    for (int i = items; i > 0 && w > 0; i--) {
        if (mat[i][w] != mat[i - 1][w]) {
            selected_bool[i - 1] = 1;
            w -= weights[i - 1];
        }
    }

    // return max value
    return mat[items][maxWeight];
} 