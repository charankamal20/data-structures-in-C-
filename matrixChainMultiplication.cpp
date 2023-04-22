#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

// Function to multiply two matrices
int matrix_multiply(vector<vector<int>> &matrices) {
  int n = matrices.size();
  // Initialize a 2D array to store the minimum number of multiplications needed
  // for each subproblem
  vector<vector<int>> dp(n, vector<int>(n, 0));
  // Fill the diagonal elements with 0, as each matrix multiplied with itself
  // doesn't require any multiplication
  for (int i = 0; i < n; i++) {
    dp[i][i] = 0;
  }
  // Iterate over the upper diagonal elements of the matrix
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
      int k = j + i;
      // Initialize the minimum number of multiplications required for this
      // subproblem to a large number
      dp[j][k] = INT16_MAX;
      // Iterate over all possible split points in the subproblem and update the
      // minimum number of multiplications required
      for (int x = j; x < k; x++) {
        dp[j][k] =
            min(dp[j][k], dp[j][x] + dp[x + 1][k] +
                              matrices[j][0] * matrices[x][1] * matrices[k][1]);
      }
    }
  }
  // Return the minimum number of multiplications required for the entire matrix
  // multiplication problem
  return dp[0][n - 1];
}

int main() {
  vector<vector<int>> matrices = {{2, 3}, {3, 6}, {6, 4}, {4, 5}};
  int product = matrix_multiply(matrices);
  cout << "\nThis is the min number of multiplications required: " << product
       << "\n";
  return 0;
}
