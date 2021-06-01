#include "GUI/header/gui_board.hpp"

//ChessGame* game = nullptr;
GUI_Board* game;

int main(int argc, const char* args[]) {
    /*
    //game = new ChessGame();
    //game->init(SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,800);

    while(game->running()) {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();
    */
    game = new GUI_Board();
    game->init(SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,800);

    
    while (!game->gameOver(1) && game->running()) {
        
        game->handleEvents();
        game->update();
        game->render();
        
        game->updateBoardState();
    }
    game->drawDebugBoard();
    

    game->clean();

    return 0;
}