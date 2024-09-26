#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to find the longest common substring between two strings
string longestCommonSubstring(const string &str1, const string &str2) {
    int n = str1.size();  // Assuming both strings are of the same length
    vector<vector<int>> lookupTable(n + 1, vector<int>(n + 1, 0)); // 2D array for dynamic programming

    int maxLength = 0;   // Track the maximum length of the common substring
    int endIndex = 0;    // To store the index where the longest substring ends in str1

    // Build the lookup table using dynamic programming
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) { // If characters match
                lookupTable[i][j] = lookupTable[i - 1][j - 1] + 1; // Extend the common substring
                if (lookupTable[i][j] > maxLength) {  // Update the maximum length
                    maxLength = lookupTable[i][j];
                    endIndex = i;  // Track the end position of the longest substring in str1
                }
            } else {
                lookupTable[i][j] = 0;  // Reset when characters don't match
            }
        }
    }

    // Display the lookup table for reference (Step 2: for dynamic programming visualization)
    cout << "Lookup Table:\n";
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << lookupTable[i][j] << " ";
        }
        cout << endl;
    }

    // Extract the longest common substring from str1 using maxLength and endIndex (Step 3)
    return str1.substr(endIndex - maxLength, maxLength);
}

int main() {
    // Input strings
    string str1 = "ABAB";
    string str2 = "BABA";

    // Find the longest common substring (Step 1)
    string result = longestCommonSubstring(str1, str2);

    // Display the result (Step 3)
    cout << "The longest common substring is: " << result << endl;
    return 0;
}