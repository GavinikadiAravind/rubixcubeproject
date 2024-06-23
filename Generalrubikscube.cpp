//
// Created by agavi on 23-06-2024.
//

#include "Generalrubikscube.h"

char Generalrubikscube::getColorLetter(COLOR color) {

    switch (color) {
        case COLOR::BLUE:
            return 'B';
        case COLOR::GREEN:
            return 'G';
        case COLOR::RED:
            return 'R';
        case COLOR::YELLOW:
            return 'Y';
        case COLOR::WHITE:
            return 'W';
        case COLOR::ORANGE:
            return 'O';
    }


}

string Generalrubikscube::getMove(MOVE ind) {
    switch (ind) {
        case MOVE::B:
            return "B";
        case MOVE::B2:
          return "B2";
        case MOVE::BP:
            return "B'";
        case MOVE::L:
            return "L";
        case MOVE::LP:
            return "L'";
        case MOVE::L2:
            return "L2";
        case MOVE::R:
            return "R";
        case MOVE::RP:
            return "R'";
        case MOVE::R2:
            return "R2";
        case MOVE::U:
            return "U";
        case MOVE::UP:
            return "U'";
        case MOVE::U2:
            return "U2";
        case MOVE::D:
            return "D";
        case MOVE::DP:
            return "D'";
        case MOVE::D2:
            return "D2";
        case MOVE::F:
            return "F";
        case MOVE::FP:
            return "F'";
        case MOVE::F2:
            return "F2";






    }


}

Generalrubikscube &Generalrubikscube::move(MOVE ind) {
    switch (ind) {
        case MOVE::B:
            return this->b() ;
        case MOVE::B2:
            return this->b2();
        case MOVE::BP:
            return this->bP();
        case MOVE::D:
            return this->d();
        case MOVE::D2:
            return this->d2();
        case MOVE::DP:
            return this->dP();
        case MOVE::L:
            return this->l();
        case MOVE::LP:
            return this->lP();
        case MOVE::L2:
            return this->l2();
        case MOVE::R:
            return this->r();
        case MOVE::RP:
            return this->rP();
        case MOVE::R2:
            return this->r2();
        case MOVE::U:
            return this->u();
        case MOVE::UP:
            return this->uP();
        case MOVE::U2:
            return this->u2();
        case MOVE::F:
            return this->f();
        case MOVE::FP:
            return this->fP();
        case MOVE::F2:
            return this->f2();


    }
}

Generalrubikscube &Generalrubikscube::invert(MOVE ind) {
    switch(ind) {
        case MOVE::B:
            return this->bP();
        case MOVE::BP:
            return this->b();
        case MOVE::B2:
             return this->b2();
        case MOVE::L:
            return this->lP();
        case MOVE::LP:
            return this->l();
        case MOVE::L2:
            return this->l2();
        case MOVE::R:
            return this->rP();
        case MOVE::RP:
            return this->r();
        case MOVE::R2:
            return this->r2();
        case MOVE::U:
            return this->uP();
        case MOVE::UP:
            return this->u();
        case MOVE::U2:
            return this->u2();
        case MOVE::D:
            return this->dP();
        case MOVE::DP:
            return this->d();
        case MOVE::D2:
            return this->d2();
        case MOVE::F:
            return this->fP();
        case MOVE::FP:
            return this->f();
        case MOVE::F2:
            return this->f2();

    }
}

void Generalrubikscube::print() const {
    cout << "Rubik's Cube:\n\n";

    for (int row = 0; row <= 2; row++) {
        for (unsigned i = 0; i < 7; i++) cout << " ";
        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::UP, row, col)) << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    for (int row = 0; row <= 2; row++) {
        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::LEFT, row, col)) << " ";
        }
        cout << " ";

        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::FRONT, row, col)) << " ";
        }
        cout << " ";

        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::RIGHT, row, col)) << " ";
        }
        cout << " ";


        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::BACK, row, col)) << " ";
        }
        cout << " ";

        cout << "\n";
    }

    cout << "\n";

    for (int row = 0; row <= 2; row++) {
        for (unsigned i = 0; i < 7; i++) cout << " ";
        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::DOWN, row, col)) << " ";
        }
        cout << "\n";
    }

     cout<<'\n';


}

vector<Generalrubikscube::MOVE> Generalrubikscube::randomShuffleCube(unsigned int times) {
  vector<MOVE> sol;
   srand(time(0));
    for(unsigned int i=0;i<times;i++) {
        unsigned int tmove=(rand()%18);
        sol.push_back(static_cast<MOVE> (tmove));
        this->move(static_cast<MOVE> (tmove));


    }
    return sol;


}
string Generalrubikscube::getCornerColorString(uint8_t ind) const {
    string str = "";

    switch (ind) {

        case 0:
            str += getColorLetter(getColor(FACE::UP,2,2));
        str += getColorLetter(getColor(FACE::FRONT, 0, 2));
        str += getColorLetter(getColor(FACE::RIGHT, 0, 0));
        break;

        case 1:
            str += getColorLetter(getColor(FACE::UP, 2, 0));
        str += getColorLetter(getColor(FACE::FRONT, 0, 0));
        str += getColorLetter(getColor(FACE::LEFT, 0, 2));
        break;

        case 2:
            str += getColorLetter(getColor(FACE::UP, 0, 0));
        str += getColorLetter(getColor(FACE::BACK, 0, 2));
        str += getColorLetter(getColor(FACE::LEFT, 0, 0));
        break;

        case 3:
            str += getColorLetter(getColor(FACE::UP, 0, 2));
        str += getColorLetter(getColor(FACE::BACK, 0, 0));
        str += getColorLetter(getColor(FACE::RIGHT, 0, 2));
        break;

        case 4:
            str += getColorLetter(getColor(FACE::DOWN, 0, 2));
        str += getColorLetter(getColor(FACE::FRONT, 2, 2));
        str += getColorLetter(getColor(FACE::RIGHT, 2, 0));
        break;

        case 5:
            str += getColorLetter(getColor(FACE::DOWN, 0, 0));
        str += getColorLetter(getColor(FACE::FRONT, 2, 0));
        str += getColorLetter(getColor(FACE::LEFT, 2, 2));
        break;

        case 6:
            str += getColorLetter(getColor(FACE::DOWN, 2, 2));
        str += getColorLetter(getColor(FACE::BACK, 2, 0));
        str += getColorLetter(getColor(FACE::RIGHT, 2, 2));
        break;

        case 7:
            str += getColorLetter(getColor(FACE::DOWN, 2, 0));//u (or) d
        str += getColorLetter(getColor(FACE::BACK, 2, 2)); // f (or) b
        str += getColorLetter(getColor(FACE::LEFT, 2, 0));//l (or) r
        break;
    }
    return str;
}




