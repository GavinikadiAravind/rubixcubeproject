//
// Created by agavi on 23-06-2024.
//

#ifndef GENERALRUBIKSCUBE_H
#define GENERALRUBIKSCUBE_H

#include<bits/stdc++.h>
using namespace std;


class Generalrubikscube{
public:
    enum class FACE {
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };

    enum class COLOR {
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };

    enum class MOVE {
        L, LP, L2,
        R, RP, R2,
        U, UP, U2,
        D, DP, D2,
        F, FP, F2,
        B, BP, B2
    };
   // virtual ~GeneralRubiksCube() = default;
    virtual COLOR getColor(FACE face, unsigned row, unsigned col) const= 0;
    static char getColorLetter(COLOR color);
    virtual bool isSolved() const = 0;
    static string getMove(MOVE ind);
    void print() const;
    vector<MOVE> randomShuffleCube(unsigned int times);
    Generalrubikscube &move(MOVE ind);
    Generalrubikscube &invert(MOVE ind);
    virtual Generalrubikscube& f()=0;
    virtual Generalrubikscube& fP()=0;
    virtual Generalrubikscube& f2()=0;
    virtual Generalrubikscube& u()=0;
    virtual Generalrubikscube& uP()=0;
    virtual Generalrubikscube& u2()=0;
    virtual Generalrubikscube& l()=0;
    virtual Generalrubikscube& lP()=0;
    virtual Generalrubikscube& l2()=0;
    virtual Generalrubikscube& r()=0;
    virtual Generalrubikscube& rP()=0;
    virtual Generalrubikscube& r2()=0;
    virtual Generalrubikscube& d()=0;
    virtual Generalrubikscube& dP()=0;
    virtual Generalrubikscube& d2()=0;
    virtual Generalrubikscube& b()=0;
    virtual Generalrubikscube& bP()=0;
    virtual Generalrubikscube& b2()=0;
    string getCornerColorString(uint8_t ind) const;
    uint8_t getCornerIndex(uint8_t ind) const;
    uint8_t getCornerOrientation(uint8_t ind) const;
};



#endif //GENERALRUBIKSCUBE_H
