#include "../header/gui_board.hpp"
//#include "../../backend/header/player.hpp"

#include <cstdint>
#include <iostream>
#include <math.h>

GUI_Board::GUI_Board() {
    this->white = new Player(1);
    this->black = new Player(0);

    this->updateBoardState();
}

uint64_t GUI_Board::cartesianToBitmask(int column, int row) const {
    if ((column < 0) | (column > 7) | (row < 0) | (row > 7)) { //return 0 if out of bounds
        return 0;
    }
            
    return pow(2, ((row * 8) + column));
}

void GUI_Board::updateBoardState() {
    this->boardstate = white->getBoardState() | black->getBoardState();
}

uint64_t GUI_Board::getBoardState() const {
    return this->boardstate;
}

void GUI_Board::runGame() {
    /*
    init(SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,500,500);


    while (!gameOver(team) || isRunning) {
        
        handleEvents();
        update();
        render();
        
        updateBoardState();
    }
    */
}

//From Chess Game
void GUI_Board::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    int mX, mY;
    SDL_GetMouseState(&mX, &mY);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        
        case SDL_MOUSEBUTTONDOWN:
            drawDebugBoard();
            if (pieceMoved) {
                mX /= PIECE_W;
                mY = mY/PIECE_H;
                mouseX /= PIECE_W;
                mouseY = mouseY/PIECE_H;

                
                if (makeMove(team, mouseX, 7-mouseY, mX, 7-mY)) {
                    
                    pieceMoving->setX(mX*PIECE_W);
                    pieceMoving->setY((mY)*PIECE_H);
                    switch(team) {
                        case 0:
                            white->testCaptures(black);
                            //if capture update board w/ capture
                            //if (black_pieces[8*(mX) + mY])
                            black_pieces[8*(mX) + mY] = pieceMoving;
                            pieceMoving = nullptr;
                            team = 1;
                            std::cout << "white's move" << std::endl;
                            break;
                        case 1:
                            black->testCaptures(white);
                            white_pieces[8*(mX) + mY] = pieceMoving;

                            pieceMoving = nullptr;
                            team = 0;
                            std::cout << "black's move" << std::endl;
                            break;
                    }
                    drawDebugBoard();
                }
                else {
                    
                    pieceMoving->setX(mouseX*PIECE_W);
                    pieceMoving->setY(mouseY*PIECE_H);
                    if (team == 1) white_pieces[8*(mouseX) + mouseY] = pieceMoving;
                    else black_pieces[8*(mouseX) + mouseY] = pieceMoving;

                    pieceMoving = nullptr;

                }
                pieceMoved = false;
            }
            else {
                SDL_GetMouseState(&mouseX, &mouseY);
                for (int i = 0; i < 64; i++) {
                    if (collision(mouseX,mouseY,white_pieces[i])) {
                        pieceMoved = true;
                        pieceMoving = white_pieces[i];
                        white_pieces[i] = nullptr;
                    }
                    else if (collision(mouseX,mouseY,black_pieces[i])) {
                        pieceMoved = true;
                        pieceMoving = black_pieces[i];
                        black_pieces[i] = nullptr;
                    }
                }
            }
            break;

        case SDL_MOUSEBUTTONUP:
            break;
            
        case SDL_MOUSEMOTION:
            if (pieceMoved) {
                int newMX, newMY;
                SDL_GetMouseState(&newMX, &newMY);
                int currX = pieceMoving->getRect().x + (newMX - mX);
                int currY = pieceMoving->getRect().y + (newMY - mY);
                pieceMoving->setX(newMX-50);
                pieceMoving->setY(newMY-50);
                pieceMoving->update();
            }
            break;
        default:
            break;
    }
}

void GUI_Board::init(int x, int y, int w, int h) {
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Initializing..." << std::endl;
        window = SDL_CreateWindow("Chess Game", x,y,w,h,0);
        if (window) std::cout << "Window in..." << std::endl;
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            std::cout << "Renderer in..." << std::endl;
            SDL_SetRenderDrawColor(renderer, 255,255,255,255);

        }
        isRunning = true;
        team = 0;
        
        chessBoard = TextureManager::load_Texture("GUI/img/chessboard2.png", renderer);
        windowRect.x = 0;
        windowRect.y = 0;
        windowRect.w = w;
        windowRect.h = h;
        
        int pos = 0;
        PIECE_W = w/8;
        PIECE_H = h/8;

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                int currPiece = white->getPieceAt(cartesianToBitmask(j,7-i));
                if (currPiece != -1) {
                    std::cout << i << "," << j << ": " << currPiece << std::endl;
                    const char* currPieceImg = "GUI/img/pawn2.png";
                    switch (currPiece) {
                        case 0: 
                            currPieceImg = "GUI/img/white_pawn.png";
                            break;
                        case 1: 
                            currPieceImg = "GUI/img/white_rook.png";
                            break;
                        case 2:
                            currPieceImg = "GUI/img/white_knight.png";
                            break;
                        case 3:
                            currPieceImg = "GUI/img/white_bishop.png";
                            break;
                        case 4:
                            currPieceImg = "GUI/img/white_queen.png";
                            break;
                        case 5:
                            currPieceImg = "GUI/img/white_king.png";
                            break;
                        default:
                            break;
                    }
                    GameObject* o = new GameObject(currPieceImg, renderer, 100, 100);
                    if (o) {
                        o->setX(PIECE_W*j);
                        o->setY(PIECE_H*i);
                        o->update();
                        white_pieces[8*(i) + j] = o;
                        std::cout << "Created object with params: " << std::endl;
                        std::cout << "w(" <<  o->getRect().w << "), h(" << o->getRect().h << "), x(" << o->getRect().x << "), y(" << o->getRect().y << ")" << std::endl;
                    }
                    else white_pieces[8*(i) + j] = nullptr;
                }
                else white_pieces[8*(i) + j] = nullptr;

                currPiece = black->getPieceAt(cartesianToBitmask(j,7-i));
                if (currPiece != -1) {
                    std::cout << i << "," << j << ": " << currPiece << std::endl;
                    const char* currPieceImg = "GUI/img/pawn2.png";
                    switch (currPiece) {
                        case 0: 
                            currPieceImg = "GUI/img/black_pawn.png";
                            break;
                        case 1: 
                            currPieceImg = "GUI/img/black_rook.png";
                            break;
                        case 2:
                            currPieceImg = "GUI/img/black_knight.png";
                            break;
                        case 3:
                            currPieceImg = "GUI/img/black_bishop.png";
                            break;
                        case 4:
                            currPieceImg = "GUI/img/black_queen.png";
                            break;
                        case 5:
                            currPieceImg = "GUI/img/black_king.png";
                            break;
                        default:
                            break;
                    }
                    GameObject* o = new GameObject(currPieceImg, renderer, PIECE_W, PIECE_H);
                    if (o) {
                        o->setX(PIECE_W*j);
                        o->setY(PIECE_H*i);
                        o->update();
                        black_pieces[8*(i) + j] = o;
                        std::cout << "Created object with params: " << std::endl;
                        std::cout << "w(" <<  o->getRect().w << "), h(" << o->getRect().h << "), x(" << o->getRect().x << "), y(" << o->getRect().y << ")" << std::endl << std::endl;
                        
                    }
                    else black_pieces[8*(i) + j] = nullptr;
                }
                else black_pieces[8*(i) + j] = nullptr;
            }
        }
        
    }
    else {
        std::cout << "Bad things happened" << std::endl;
        isRunning = false;
    }
}
void GUI_Board::update() {
    for(GameObject* o : white_pieces) {
        if (o) o->update();
    }
    for(GameObject* o : black_pieces) {
        if (o) o->update();
    }
    if (pieceMoving) pieceMoving->update();
}
void GUI_Board::render() {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, chessBoard, NULL, &windowRect);

    for(GameObject* o : white_pieces) {
        if (o) o->render();
    }
    for(GameObject* o : black_pieces) {
        if (o) o->render();
    }
    if (pieceMoving) pieceMoving->render();

    SDL_RenderPresent(renderer);
}
void GUI_Board::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
//Helpers
bool GUI_Board::collision(int x, int y, GameObject* o) {
    if (!o) return false;
    SDL_Rect temp = o->getRect();
    if (x > temp.x && x < temp.x + temp.w) {
        if (y > temp.y && y < temp.y + temp.h) {
            return true;
        }
    }
    return false;
}

//Additional Functions
bool GUI_Board::gameOver(int teamTmp) {
    //Checks if checkmate

    //Checks if no more moves
    if (white->getAllValidMoves(boardstate) == 0 && team == 0) return true;
    if (black->getAllValidMoves(boardstate) == 0 && team == 1) return true;
    return false;
}
bool GUI_Board::makeMove(int teamTmp, int sX, int sY, int eX, int eY) {
    uint64_t scoord;
    uint64_t ecoord;

    scoord = cartesianToBitmask(sX,sY);
    ecoord = cartesianToBitmask(eX,eY);
    
    if (team == 0) {
        return black->makeMove(scoord, ecoord, this->boardstate);
    }
    else {
        return white->makeMove(scoord, ecoord, this->boardstate);
    }
}

