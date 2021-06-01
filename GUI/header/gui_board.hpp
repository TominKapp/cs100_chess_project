#ifndef __GUI_BOARD_HPP__
#define __GUI_BOARD_HPP__

#include <cstdint>
#include <SDL2/SDL.h>
#include <iostream>

#include "../../player.hpp"
#include "game_object.hpp"

class GUI_Board {
    private:
        Player* white;
        Player* black;
        
        uint64_t boardstate;
        int team;

        //From Chess Game
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Texture* chessBoard;
        SDL_Rect windowRect;
        GameObject* white_pieces[64] = {nullptr};
        GameObject* black_pieces[64] = {nullptr};
        bool isRunning;
        int mouseX, mouseY;
        bool pieceMoved = false;
        GameObject* pieceMoving = nullptr;
        int PIECE_W, PIECE_H;
    
    protected:
        uint64_t cartesianToBitmask(int column, int row) const;
    
    public:
        GUI_Board();
        //~Board();
<<<<<<< HEAD
        ~GUI_Board();
=======
>>>>>>> bfb73988d621a019083a347f8f6252a81c69df83
        
        void updateBoardState();
        uint64_t getBoardState() const;
        bool makeMove(int team);
        
        void runGame();

        //New Functions
        bool gameOver(int team);
        bool makeMove(int team, int sX, int sY, int eX, int eY);

        //From Chess Game
        void init(int x, int y, int w, int h);

        void handleEvents();
        void update();
        void render();
        void clean();

        bool running() { return isRunning; }



        void drawDebugBoard() const {
            char output;
            
            std::cout << "-------- " << std::endl;
            for (int i = 63; i >= 0; i--) {
                //output = '#';
                
                if (((i / 8) + (i % 8)) % 2 == 1) {
                    output = 176;
                }
                else {
                    output = 178;
                }
                
                switch(white->getPieceAt(pow(2,i))) {
                    case 0:
                        output = 'p';
                        break;
                    case 1:
                        output = 'r';
                        break;
                    case 2:
                        output = 'n';
                        break;
                    case 3:
                        output = 'b';
                        break;
                    case 4:
                        output = 'q';
                        break;
                    case 5:
                        output = 'k';
                        break;
                }
                
                switch(black->getPieceAt(pow(2,i))) {
                    case 0:
                        output = 'P';
                        break;
                    case 1:
                        output = 'R';
                        break;
                    case 2:
                        output = 'N';
                        break;
                    case 3:
                        output = 'B';
                        break;
                    case 4:
                        output = 'Q';
                        break;
                    case 5:
                        output = 'K';
                        break;
                }
                
                std::cout << output;
                
                if (i % 8 == 0) {
                    std::cout << "|" << (i / 8) << std::endl;
                }
            }
            std::cout << "-------- " << std::endl;
            std::cout << "76543210 " << std::endl;
        }
    private:
        bool collision(int, int, GameObject*);


};

#endif