//
// Created by agavi on 24-06-2024.
#include<bits/stdc++.h>
#include"Generalrubikscube.h"

#ifndef DFSSOLVER_H
#define DFSSOLVER_H

template<typename T, typename H>
class DFSSOlVER {
private:
    vector<Generalrubikscube::MOVE> moves;
    int max_search_depth;
    bool dfs(int dep) {
        if (rubiksCube.isSolved()) return true;
        if (dep > max_search_depth) return false;
        for (int i = 0; i < 18; i++) {
            rubiksCube.move(Generalrubikscube::MOVE(i));
            moves.push_back(Generalrubikscube::MOVE(i));
            if (dfs(dep + 1)) return true;
            moves.pop_back();
            rubiksCube.invert(RubiksCube::MOVE(i));
        }
        return false;
    }
public:
    T rubiksCube;

    DFSSolver(T _rubiksCube, int _max_search_depth = 8) {
        rubiksCube = _rubiksCube;
        max_search_depth = _max_search_depth;
    }

    vector<Generalrubikscube::MOVE> solve() {
        dfs(1);
        return moves;
    }

};







#endif //DFSSOLVER_H
