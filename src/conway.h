#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;

SDL_Window* window = NULL;
SDL_Renderer* renderer;
Mix_Music *bg = NULL;
SDL_Texture *screen_texture;
SDL_Surface* title = NULL;
SDL_Surface* endgame = NULL;
SDL_Surface* screen = NULL;
TTF_Font* gFont = NULL;
SDL_Color bg_color = {0x61, 0x3d, 0x4a, 0xFF};		
SDL_Color filled = {0x9d, 0xa3, 0xb3, 0xFF};
SDL_Color panel_outline = {0x49, 0x7a, 0xbc, 0xFF};
SDL_Event e;
SDL_Surface *surfaceMessage = TTF_RenderText_Solid(gFont, "", {0x10, 0x19, 0x2E, 0xFF});
SDL_Texture *Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 640;
const int PANEL = 100;
const int THICKNESS = 3; 
const int BOARD_SIZE_X = SCREEN_WIDTH/10;
const int BOARD_SIZE_Y = (SCREEN_HEIGHT-PANEL)/10;
int board[BOARD_SIZE_X][BOARD_SIZE_Y] = {0}; 
// n : neighbours (each square has 8 neighbour squares)
int nx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int ny[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int state = 0; 
int previous = 0;
int population_count = 0;
int low = 1000;
int high = 0;
int speed = 150;
bool quit = false;
bool gene = false;
bool paused = false;
bool rText = false;

bool sdl_init();
bool loadMedia();
void print_title();
void print_gameover();
bool load_music();
void mouse_event();
void draw_square(SDL_Color&, int, int, int, int);
void close();
