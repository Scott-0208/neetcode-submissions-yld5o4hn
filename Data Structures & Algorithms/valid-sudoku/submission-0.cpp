class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 1. Setup 27 clipboards
        bool rowCheck[9][10] = {false};
        bool colCheck[9][10] = {false};
        bool boxCheck[9][10] = {false};
        // 2. Iterate through every cell in the 9x9 board (indices 0 - 8)
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char currentChar = board[r][c];
                // 3. If the cell is empty, skip to the next cell
                if (currentChar == '.') {
                    continue;
                    // 'continue' skips the rest of the code in the loop and move to next
                }
                // 4. Convert the charartcer to an integer use it as an index
                int num = currentChar - '0';
                // 5. Calculate sub-box index
                int boxIndex = (r / 3) * 3 + (c / 3);
                // 6. Check our clipboards
                // Have we seen this 'num' in this row, col, box?
                if (rowCheck[r][num] || colCheck[c][num] || boxCheck[boxIndex][num]) {
                    return false;
                }
                // 7. If we made it here, it means hasn't seen
                rowCheck[r][num] = true;
                colCheck[c][num] = true;
                boxCheck[boxIndex][num] = true;
            }
        }
        // 8. If check every cell and never return flase, the board is valid
        return true;
    }
};
