#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int minimax(int depth, int nodeIndex, bool maximizingPlayer, int values[], int alpha, int beta)
{
    // Terminating condition. i.e leaf node is reached
    if (depth == 3)
        return values[nodeIndex];
 
    if (maximizingPlayer) {
        int best = INT_MIN;
        // alpha <= beta
        // Recur for left and right children
        for (int i = 0; i < 2; i++) 
        {
            int val = minimax(depth + 1, nodeIndex * 2 + i, false, values, alpha, beta);
            best = (best > val) ? best : val;
            alpha = (alpha > best) ? alpha : best;
            // Alpha Beta Pruning
            if (beta <= alpha)
                break;
        }
        return best;
    }
    else 
    {
        int best = INT_MAX;

        // Recur for left and right children
        for (int i = 0; i < 2; i++) {
            int val = minimax(depth + 1, nodeIndex * 2 + i,true, values, alpha, beta);
            best = (best < val) ? best : val;
            beta = (beta < best) ? beta : best;
 
            // Alpha Beta Pruning
            if (beta <= alpha)
                break;
        }
        return best;
    }
}

void main()
{
    int values[] = { 3, 5, 2, 9, 12, 5, 23, 23 };
    int result = minimax(0, 0, true, values, INT_MIN, INT_MAX);
    printf("The optimal value is : %d\n", result);    
}

