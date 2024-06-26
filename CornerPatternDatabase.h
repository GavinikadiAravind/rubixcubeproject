//
// Created by agavi on 26-05-2024.
//

#ifndef CORNERPATTERNDATABASE_H
#define CORNERPATTERNDATABASE_H
#include "Generalrubikscube.h"
#include "PatternDatabase.h"
#include "PermutationIndexer.h"
using namespace std;




class CornerPatternDatabase:public PatternDatabase{

    typedef Generalrubikscube::FACE F;

    PermutationIndexer<8> permIndexer;

public:
    CornerPatternDatabase();
    CornerPatternDatabase(uint8_t init_val);
    uint32_t getDatabaseIndex(const Generalrubikscube& cube) const;


};



#endif //CORNERPATTERNDATABASE_H
