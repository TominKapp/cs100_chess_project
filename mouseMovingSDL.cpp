#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<stdio.h>
#include<string>

bool init();
bool loadMedia();
void close();
SDL_Surface* loadSurface(std::string);

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const int PICTURE_WIDTH = 400;
const int PICTURE_HEIGHT = 400;

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gCurrentSurface = NULL;

int main(int argc, const char args[]) {
    if (!init()) {
        printf("No init :(");
    }
    else {
        if (!loadMedia()) {
            printf("No media :(");
        }
        else {
            bool gameOver = false;
            bool mouseDown = false;
            SDL_Event e;
            int x = 0, y = 0;
            int mX = 0, mY = 0;
            while (!gameOver) {
                //Get currMousePos
                SDL_GetMouseState(&mX, &mY);

                while(SDL_PollEvent(&e) != 0) {
                    if (e.type == SDL_QUIT) {
                        gameOver = true;
                    }
                    
                    if (e.type == SDL_MOUSEBUTTONDOWN) {
                        if (mouseDown) {
                            mouseDown = false;
                            printf("Mouse Up\n");
                        }
                        else {
                            if (mX > x && mX < x+PICTURE_WIDTH) {
                                if (mY > y && mY < y+PICTURE_HEIGHT) {
                                    mouseDown = true;
                                    printf("Mouse Down\n");
                                }
                            }
                        }
                    }
                    if (e.type == SDL_MOUSEMOTION) {
                        if (mouseDown) {
                            printf("x:%i \t\t y:%i\n", mX, mY);
                            int newMX, newMY;
                            SDL_GetMouseState(&newMX, &newMY);
                            x += (newMX - mX);
                            y += (newMY - mY);
                        }
                    }
                    if (e.type = SDL_MOUSEBUTTONUP) {
                    }
                    

                }
                SDL_Rect stretchRect;
                stretchRect.x = x;
                stretchRect.y = y;
                stretchRect.w = PICTURE_WIDTH;
                stretchRect.h = PICTURE_HEIGHT;
                SDL_BlitScaled(gCurrentSurface, NULL, gScreenSurface, &stretchRect);
                
                SDL_UpdateWindowSurface(gWindow);
            }
        }
    }
    close();

    return 0;
}

bool init() {
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Error: %s\n", SDL_GetError());
        success = false;
    }
    else {
        gWindow = SDL_CreateWindow("MouseMovement", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
        if(gWindow == NULL) {
            printf("Error: %s\n", SDL_GetError());
            success = false;
        }
        else {
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags)) & imgFlags) {
                printf("Error: %s\n", IMG_GetError());
                success = false;
            }
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }
    return success;
}
bool loadMedia() {
    bool success = true;
    gCurrentSurface = loadSurface("images/loaded.png");
    if (gCurrentSurface == NULL) {
        printf("Error: %s\n", SDL_GetError());
        success = false;
    }

    return success;
}
void close() {
    SDL_FreeSurface(gCurrentSurface);
    gCurrentSurface = NULL;

    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    SDL_Quit();
}

SDL_Surface* loadSurface(std::string path) {
    SDL_Surface* optimizedSurface = NULL;
    SDL_Surface* loadedSurface = IMG_Load( path.c_str());
    if (loadedSurface == NULL) {
        printf ("Unable to load surface: SDL_Error: %s\n", IMG_GetError());
    }
    else {
        optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, 0);
        if (optimizedSurface == NULL) {
            printf ("Unable to load surface: SDL_Error: %s\n", SDL_GetError());
        }
        SDL_FreeSurface(loadedSurface);
    }

    return optimizedSurface;
}
