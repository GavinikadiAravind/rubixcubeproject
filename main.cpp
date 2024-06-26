#include <bits/stdc++.h>
#include "Rubikscube3d.cpp"
#include "Rubikscube1d.cpp"
//#include "Rubikscubebitboard.cpp"
#include "DFSSolver.h"
#include "BFSSolver.h"
#include "IDDFSSolver.h"
#include "IDAstarSolver.h"
//#include "CornerPatternDatabase.h"
#include "CornerDBMaker.h"
using namespace std;
int main() {
    RubiksCube3dArray object3DArray;
    RubiksCube1dArray object1dArray;
   // RubiksCubeBitboard objectBitboard;
    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
    else cout << "NOT SOLVED\n\n";

    if (object1dArray.isSolved()) cout << "SOLVED\n\n";
    else cout << "NOT SOLVED\n\n";

    // if (objectBitboard.isSolved()) cout << "SOLVED\n\n";
    // else cout << "NOT SOLVED\n\n";

    //objectBitboard.u();
    // object3DArray.u();
    // object1dArray.u();
  //  objectBitboard.print();
    // object3DArray.print();
    // object1dArray.print();

    //   objectBitboard.uP();
        // object3DArray.uP();
        // object1dArray.uP();
    //   objectBitboard.print();
    // object3DArray.print();
    // object1dArray.print();

   // //DFSSolver
   //  RubiksCube3dArray cube;
   //  cube.print();
   //
   //  vector<Generalrubikscube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
   //  for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
   //  cout << "\n";
   //  cube.print();
   //
   //  DFSSolver<RubiksCube3dArray, Hash3d> dfsSolver(cube, 8);
   //  vector<Generalrubikscube::MOVE> solve_moves = dfsSolver.solve();
   //
   //  for (auto move: solve_moves) cout << cube.getMove(move) << " ";
   //  cout << "\n";
   //  dfsSolver.rubiksCube.print();

    //BFSSolver

    // RubiksCube3dArray cube;
    // cube.print();
    //
    // vector<Generalrubikscube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
    // for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // cube.print();
    //
    // BFSSolver<RubiksCube3dArray, Hash3d> bfsSolver(cube);
    // vector<Generalrubikscube::MOVE> solve_moves = bfsSolver.solve();
    //
    // for (auto move: solve_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // bfsSolver.rubiksCube.print();

     //IDDFSSolver

    // RubiksCube3dArray cube;
    // cube.print();
    //
    // vector<Generalrubikscube::MOVE> shuffle_moves = cube.randomShuffleCube(7);
    // for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // cube.print();
    //
    // IDDFSSolver<RubiksCube3dArray, Hash3d> iddfsSolver(cube,7);
    // vector<Generalrubikscube::MOVE> solve_moves = iddfsSolver.solve();
    //
    // for (auto move: solve_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // iddfsSolver.rubiksCube.print();
    // IDA* SOLVER ---------------------------------------------------------------------------------------------------
  string file="C:\\Users\\agavi\\CLionProjects\\rubixcubeproject\\cornerDepth5V1.txt";
    RubiksCube3dArray cube;
    cube.print();

    vector<Generalrubikscube::MOVE> shuffle_moves = cube.randomShuffleCube(5);
    for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    cube.print();

    IDAstarSolver<RubiksCube3dArray, Hash3d> idAstarSolver(cube,file);
    vector<Generalrubikscube::MOVE> solve_moves = idAstarSolver.solve();
    for (auto move: solve_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    idAstarSolver.rubiksCube.print();




    return 0;

}
