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
        isMouseEmpty = true;

        
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
                //Remove a piece
                if ((i*8 + j) > 23 && (i*8 + j) < 40)
                    pieces[i*8 + j] = nullptr;
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
        case SDL_MOUSEBUTTONDOWN:
            int mX, mY;
            if (this->isMouseEmpty == true){
                this->isMouseEmpty = false;
            }
            else{
                this->isMouseEmpty = true;
            }
            SDL_GetMouseState(&mX, &mY);
            for (int i = 0; i < 64; i++) {
                if (collision(mX,mY,pieces[i])) {
                    std::cout << "Row: " << (8 - (i/8)) << ", Col: " << (i%8 +1) << std::endl; 
                        pieces[i]->setX(mX - 50); //-50 offset for a 100x100 piece 
                        pieces[i]->setY(mY - 50); //-50 offset for a 100x100 piece
                        this->currentPiece = i;
                }
            }
            break;
        case SDL_MOUSEMOTION:
            if (this->isMouseEmpty == false)
            {
                int motionX, motionY;
                SDL_GetMouseState(&motionX, &motionY);
                pieces[this->currentPiece]->setX(motionX - 50);
                pieces[this->currentPiece]->setY(motionY - 50);
            }
            break;
        default:
            break;
    
    }
}

void ChessGame::update() {
    for(GameObject* o : pieces)
    {
        if (o)
        o->update();
    }
}

void ChessGame::render() {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, chessBoard, NULL, &windowRect);
    for(GameObject* o : pieces) {
        if (o)
        o->render();
    }
    SDL_RenderPresent(renderer);
}

void ChessGame::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}


//Helpers
bool ChessGame::collision(int x, int y, GameObject* o) {
    if (!o) 
        return false;
    SDL_Rect temp = o->getRect();
    if (x > temp.x && x < temp.x + temp.w) {
        if (y > temp.y && y < temp.y + temp.h) {
            return true;
        }
    }
    return false;
}