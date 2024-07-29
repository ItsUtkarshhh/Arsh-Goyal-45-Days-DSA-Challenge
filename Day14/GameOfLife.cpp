// Leetcode question number 289 :
int rows = board.size();
        int cols = board[0].size();
        vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, 
                                             {0, 1}, {1, -1}, {1, 0}, {1, 1}};
      
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                int liveNeighbors = 0;

                for (auto dir : directions) {
                    int r = row + dir.first;
                    int c = col + dir.second;
                    if (r >= 0 && r < rows && c >= 0 && c < cols && abs(board[r][c]) == 1) {
                        liveNeighbors++;
                    }
                }

                if (board[row][col] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                    board[row][col] = -1;
                }
                if (board[row][col] == 0 && liveNeighbors == 3) {
                    board[row][col] = 2;
                }
            }
        }
        
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (board[row][col] == -1) {
                    board[row][col] = 0;
                } else if (board[row][col] == 2) {
                    board[row][col] = 1;
                }
            }
        }
