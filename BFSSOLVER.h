//
// Created by agavi on 24-06-2024.
//
#include<bits/stdc++.h>
#include "Generalrubikscube.h"

#ifndef BFSSOLVER_H
#define BFSSOLVER_H

template<class T,class H>
class BFSSolver {

private:
    vector<Generalrubikscube::MOVE> moves;
    unordered_map<T, bool, H> visited;
    unordered_map<T, Generalrubikscube::MOVE, H> move_done;
    T bfs() {
        queue<T> q;
        q.push(rubiksCube);
        visited[rubiksCube] = true;

        while (!q.empty()) {
            T node = q.front();
            q.pop();
            if (node.isSolved()) {
                return node;
            }
            for (int i = 0; i < 18; i++) {
                auto curr_move = Generalrubikscube::MOVE(i);
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
    T rubiksCube;

    BFSSolver(T _rubiksCube) {
        rubiksCube = _rubiksCube;
    }

    vector<Generalrubikscube::MOVE> solve() {
        T solved_cube = bfs();
        assert(solved_cube.isSolved());
        T curr_cube = solved_cube;
        while (!(curr_cube == rubiksCube)) {
            Generalrubikscube::MOVE curr_move = move_done[curr_cube];
            moves.push_back(curr_move);
            curr_cube.invert(curr_move);
        }
        rubiksCube = solved_cube;
        reverse(moves.begin(), moves.end());
        return moves;
    }

};






#endif //BFSSOLVER_H
