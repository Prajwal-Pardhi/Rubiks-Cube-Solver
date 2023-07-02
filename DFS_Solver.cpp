#include<bits/stdc++.h>
#include "../Model/RubiksCube.h"

#ifndef RUBIKS_CUBE_SOLVER_DFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_DFSSOLVER_H

// Typename C: RubiksCube 3d Representation
// Typename H: Corresponding Hash function
template<typename C, typename H>

class DFS_Solver {

private:

    vector<RubiksCube::MOVE> moves_done;
    int max_search_depth; //max search depth

//    DFS code to find the solution (helper function)
    bool dfs(int dep) {
        //Base case: return true is we get solved cube
        if (rubiksCube.isSolved()) return true;
        
        //If max depth is reached
        if (dep > max_search_depth) return false;
        
        //performng 18 different operations
        for (int i = 0; i < 18; i++) {
            rubiksCube.move(RubiksCube::MOVE(i));
            moves_done.push_back(RubiksCube::MOVE(i));
            if (dfs(dep + 1)) return true;
            moves_done.pop_back();
            rubiksCube.invert(RubiksCube::MOVE(i));
        }
        return false;
    }

public:
    C rubiksCube;
    
    //constructor
    DFS_Solver(C _rubiksCube, int _max_search_depth = 8) {
        rubiksCube = _rubiksCube;
        max_search_depth = _max_search_depth;
    }

    vector<RubiksCube::MOVE> solve() {
        dfs(1);
        return moves_done;
    }

};


#endif //RUBIKS_CUBE_SOLVER_DFS_SOLVER_H
