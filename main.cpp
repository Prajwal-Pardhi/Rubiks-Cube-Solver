#include <bits/stdc++.h>
#include "Model/RubiksCube3dArray.cpp"
#include "DFS_Solver.h"
#include "BFS_Solver.h"

using namespace std;

int main() {
    RubiksCube3dArray object3DArray;
    object3DArray.print();

    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
    else cout << "NOT SOLVED\n\n";
    
//    Testing each move ____________________________________________________________________________
//    object3DArray.u();
//    object3DArray.print();
//
//    object3DArray.l();
//    object3DArray.print();
//
//    object3DArray.f();
//    object3DArray.print();
//
//    object3DArray.r();
//    object3DArray.print();
//
//    object3DArray.b();
//    object3DArray.print();
//
//    object3DArray.d();
//    object3DArray.print();
//
//    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";
//

    
// DFS Solver Testing __________________________________________________________________________________________
/*    RubiksCube3dArray cube;
    cube.print();
    
    vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
    for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    cube.print();

    DFS_Solver<RubiksCube3dArray, Hash3d> dfsSolver(cube, 8);
    vector<RubiksCube::MOVE> solve_moves = dfsSolver.solve();

    for (auto move: solve_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    dfsSolver.rubiksCube.print();
*/

//BFS Solver -----------------------------------------------------------------------------------------------------
    RubiksCube3dArray cube;
    cube.print();

    vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
    for(auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    cube.print();

    BFS_Solver<RubiksCube3dArray, Hash3d> bfsSolver(cube);
    vector<RubiksCube::MOVE> solve_moves = bfsSolver.solve();

    for(auto move: solve_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    bfsSolver.rubiksCube.print();

    return 0;
}
