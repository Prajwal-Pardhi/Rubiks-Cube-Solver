#include<bits/stdc++.h>
#include "../Model/RubiksCube.h"

#ifndef RUBIKS_CUBE_SOLVER_BFS_Solver_H
#define RUBIKS_CUBE_SOLVER_BFS_Solver_H

// For template:
// Typename C: RubiksCube (3d Representation)
// Typename H: Corresponding Hash function

template<typename C, typename H>

class BFS_Solver {
private:
    vector<RubiksCube::MOVE> moves;
    unordered_map<C, bool, H> visited;
    
//  move_done[] -> Back-Pointer map as to how we reached that state
    unordered_map<C, RubiksCube::MOVE, H> move_done;

//    bfs() -> performs breadth-first-search and returns a solved Rubik's Cube
    C bfs() {
        queue<C> q;
        q.push(rubiksCube);
        visited[rubiksCube] = true;

        while (!q.empty()) {
            C node = q.front();
            q.pop();
            if (node.isSolved()) {
                return node;
            }
            for (int i = 0; i < 18; i++) {
                auto curr_move = RubiksCube::MOVE(i);
                node.move(curr_move);
                if (!visited[node]) {
                    visited[node] = true;
                    move_done[node] = curr_move;
                    q.push(node);
                }
                node.invert(curr_move);
            }
        }
        return rubiksCube;
    }

public:
    C rubiksCube;
    
    //constructor
    BFS_Solver(C _rubiksCube) {
        rubiksCube = _rubiksCube;
    }

//    Performs BFS and returns the vector of moves done to solve the cube
    vector<RubiksCube::MOVE> solve() {
        C solved_cube = bfs();
        assert(solved_cube.isSolved());
        C curr_cube = solved_cube;
        while (!(curr_cube == rubiksCube)) {
            RubiksCube::MOVE curr_move = move_done[curr_cube];
            moves.push_back(curr_move);
            curr_cube.invert(curr_move);
        }
        rubiksCube = solved_cube;
        reverse(moves.begin(), moves.end());
        return moves;
    }
};

#endif //RUBIKS_CUBE_SOLVER_BFS_Solver_H
