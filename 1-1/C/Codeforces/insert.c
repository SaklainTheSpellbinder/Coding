#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

// The player struct
struct player {
  int x;
  int y;
  int speed;
};

// The enemy struct
struct enemy {
  int x;
  int y;
  int speed;
};

// The main function
int main() {
  // Initialize the player and enemies
  struct player player = {100, 100, 20};
  struct enemy enemies[10];
  for (int i = 0; i < 10; i++) {
    enemies[i].x = i * 100;
    enemies[i].y = 200;
    enemies[i].speed = 10;
  }

  // Create the screen
  SDL_Window *window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == NULL) {
    printf("Could not create window: %s\n", SDL_GetError());
    return 1;
  }

  // Create the renderer
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer == NULL) {
    printf("Could not create renderer: %s\n", SDL_GetError());
    return 1;
  }

  // Set the background color
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

  // Start the main loop
  while (1) {
    // Clear the screen
    SDL_RenderClear(renderer);

    // Update the player
    if (SDL_GetKeyState(NULL) & SDLK_RIGHT) {
      player.x += player.speed;
    } else if (SDL_GetKeyState(NULL) & SDLK_LEFT) {
      player.x -= player.speed;
    }

    // Update the enemies
    for (int i = 0; i < 10; i++) {
      enemies[i].x += enemies[i].speed;
    }

    // Check for collisions
    for (int i = 0; i < 10; i++) {
      if (player.x == enemies[i].x && player.y == enemies[i].y) {
        break;
      }
    }

    // Draw the background
    SDL_RenderFillRect(renderer, NULL);

    // Draw the player
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &player);

    // Draw the enemies
    for (int i = 0; i < 10; i++) {
      SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
      SDL_RenderDrawRect(renderer, &enemies[i]);
    }

    // Update the display
    SDL_RenderPresent(renderer);

    // Check for events
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        break;
      }
    }
  }

  // Destroy the renderer
  SDL_DestroyRenderer(renderer);

  // Destroy the window
  SDL_DestroyWindow(window);

  // Quit SDL
  SDL_Quit();

  return 0;
}