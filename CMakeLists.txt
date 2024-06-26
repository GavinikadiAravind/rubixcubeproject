cmake_minimum_required(VERSION 3.28)
project(rubixcubeproject)

set(CMAKE_CXX_STANDARD 17)

add_executable(rubixcubeproject main.cpp
        Generalrubikscube.cpp
        Generalrubikscube.h
        Rubikscube3d.cpp
        Rubikscube1d.cpp
        DFSSOLVER.h
        BFSSOLVER.h
        IDDFSSOLVER.h
        IDASTARSOLVER.h
        NibbleArray.cpp
        NibbleArray.h
        PatternDatabase.cpp
        PatternDatabase.h
        math.cpp
        math.h
        PermutationIndexer.h
        CornerDBMaker.cpp
        CornerDBMaker.h
        CornerPatternDatabase.cpp
        CornerPatternDatabase.h
        Rubikscubebitboard.cpp
)
