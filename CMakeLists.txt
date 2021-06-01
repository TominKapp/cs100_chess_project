CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
    tests/unit_test.cpp
    
    board.cpp
    moveBishop.cpp
    moveBlackPawn.cpp
    moveFactory.cpp
    moveKing.cpp
    moveKnight.cpp
    moveQueen.cpp
    moveRook.cpp
    moveWhitePawn.cpp
    piece.cpp
    player.cpp
)

ADD_EXECUTABLE(main
    GUI/src/game_object.cpp
    GUI/src/gui_board.cpp
    GUI/src/texture_manager.cpp

    board.cpp
    main.cpp
    moveBishop.cpp
    moveBlackPawn.cpp
    moveFactory.cpp
    moveKing.cpp
    moveKnight.cpp
    moveQueen.cpp
    moveRook.cpp
    moveWhitePawn.cpp
    piece.cpp
    player.cpp
)

ADD_COMPILE_OPTIONS(-std=c++0x -lSDL2 -lSDL2_image )
TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
