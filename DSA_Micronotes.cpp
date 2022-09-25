GRAPH:
   1) a)  The Bellman–Ford algorithm is an algorithm that computes shortest paths from a single source vertex to all of the other vertices in a weighted digraph whereas Floyd-Warshall computes shortest paths from each node to every other node.
      b)  Note: whenever question says pre-requisite or to complete some task before some task use topological sort
        link: https://www.geeksforgeeks.org/minimum-time-taken-by-each-job-to-be-completed-given-by-a-directed-acyclic-graph/
    2) a) Traveling SalesMan Problem uses below concept
          The Hamiltoninan cycle problem is to find if there exist a tour that visits
          every city exactly once. Here we know that Hamiltonian Tour exists (because
          the graph is complete) and in fact many such tours exist, the problem is to
          find a minimum weight Hamiltonian Cycle.
          problem:
          given cities and dist. between each pair of cities,
          find the shortest possible path that visits each cities and return to origin city
    3) a) Snake and Ladder
                                 /*
                         link: https://leetcode.com/problems/snakes-and-ladders/
                         using BFS

                         logic: everytime steps will be increase in BFS style, like (successor's step = predecessor's step + 1);
                         so all reachable block from predecessor's step will be marked **predecessor's step + 1**;
                     */
                     class Solution {
                     public:
                         int snakesAndLadders(vector<vector<int>>& board) {
                             int N = board.size();

                             // target to reach
                             int target = N * N;

                             // to track visited blocks
                             vector<int> vis(N * N + 1, 0);

                             // pair<int, int> : current pos, steps
                             queue<pair<int, int>> q;

                             // starting with 1 (in board (n-1,0))
                             q.push({ 1, 0 });

                             while (!q.empty()) {
                                 auto curr = q.front();
                                 q.pop();

                                 // target found
                                 if (curr.first == target) return curr.second;

                                 // out of range
                                 if (curr.first > target) continue;

                                 // already visited
                                 if (vis[curr.first]) continue;

                                 // mark visited
                                 vis[curr.first] = 1;

                                 // checking all board with possibility of dice
                                 for (int i = 1;i <= 6;i++) {
                                     // out of board
                                     if (curr.first + i > target) break;

                                     // every dice move
                                     int newNum = curr.first + i;

                                     // r: curr row from bottom side (Boustrophedon style)
                                     int r = (newNum - 1) / N, col;

                                     // row acc. to the board
                                     int row = N - 1 - r;

                                     // if r is even then col will be from left to right
                                     if (r % 2 == 0) col = (newNum - 1) % N;
                                     // if r is odd then col will be from right to left
                                     else col = N - 1 - (newNum - 1) % N;

                                     // push the new BFS based block 
                                     // how BFS? : (see curr.second + 1)
                                     q.push({ board[row][col] == -1 ? newNum : board[row][col], curr.second + 1 });
                                 }
                             }

                             // target is unreachable
                             return -1;
                         }
                     };
