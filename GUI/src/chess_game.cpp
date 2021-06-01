#include "../header/chess_game.hpp"
#include <iostream>

ChessGame::ChessGame() {
    //init(SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,w,h);
}
ChessGame::~ChessGame() {
    /*
    delete window;
    delete renderer;
    for (int i = 0; i < 64; i++) {
        delete pieces[i];
    }
    */
}

void ChessGame::init(int x, int y, int w, int h) {
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

        
        chessBoard = TextureManager::load_Texture("GUI/img/chessboard2.png", renderer);
        windowRect.x = 0;
        windowRect.y = 0;
        windowRect.w = w;
        windowRect.h = h;
        
        int pos = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                GameObject* o = new GameObject("GUI/img/pawn2.png", renderer, 100, 100);
                o->setX(100*j);
                o->setY(100*i);
                
                pieces[i*8 + j] = o;
            }
        }
        
    }
    else {
        std::cout << "Bad things happened" << std::endl;
        isRunning = false;
    }
}

void ChessGame::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
    MouseManager::checkEvent(event)
        case SDL_MOUSEBUTTONDOWN:
            int mX, mY;
            SDL_GetMouseState(&mX, &mY);
            for (int i = 0; i < 64; i++) {
                if (collision(mX,mY,pieces[i])) {
                    
                }
            }
            break;
        default:
            break;
    
    }
}

void ChessGame::update() {
    for(GameObject* o : pieces) o->update();
}

void ChessGame::render() {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, chessBoard, NULL, &windowRect);
    for(GameObject* o : pieces) o->render();
    SDL_RenderPresent(renderer);
}

void ChessGame::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}


//Helpers
bool ChessGame::collision(int x, int y, GameObject* o) {
    SDL_Rect temp = o->getRect();
    if (x > temp.x && x < temp.x + temp.w) {
        if (y > temp.y && y < temp.y + temp.h) {
            return true;
        }
    }
    return false;
}