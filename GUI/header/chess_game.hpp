#ifndef __CHESS_GAME_HPP__
#define __CHESS_GAME_HPP__

#include <SDL2/SDL.h>
#include <vector>

#include "game_object.hpp"
#include "texture_manager.hpp"
#include "mouse_manager.hpp"
//#include "../../backend/header/piece.hpp"
//#include "../../backend/header/player.hpp"


class ChessGame {
    private:
        bool isRunning;
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Texture* chessBoard;
        SDL_Rect windowRect;
        GameObject* pieces[64];

    public:
        ChessGame();
        ~ChessGame();

        void init(int x, int y, int w, int h);

        void handleEvents();
        void update();
        void render();
        void clean();

        bool running() { return isRunning; }

    private:
        bool collision(int, int, GameObject*);
};

#endif