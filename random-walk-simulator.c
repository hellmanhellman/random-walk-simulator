#include <stdlib.h>
#include <math.h>

#include <SDL2/SDL.h>

#define EPOCHS 200 * 1000 * 1000
#define WINDOW_WIDTH 1000

#define WINDOW_MARGIN 20
#define Y_SCALING 100

void playGame(SDL_Renderer *renderer)
{
  int epoch, coin_toss_result;
  int min_score = 0;
  int max_score = 0;
  int score = 0;
  int cur_x = WINDOW_MARGIN;
  int cur_y = (int)WINDOW_WIDTH / 2;
  int prev_x = cur_x, prev_y = cur_y;
  long returns_to_origin = 0;
  long num_times_positive = 0;

  int CONTENT_WIDTH = (WINDOW_WIDTH - 2 * WINDOW_MARGIN);
  int EPOCH_STEP = (int)(2 * EPOCHS / CONTENT_WIDTH);
  int Y_SQUEEZE = (int)fmax(EPOCHS / (CONTENT_WIDTH * Y_SCALING * 30), 1);
  printf("\n\n---------- Running New Game (%i million epochs) ----------\n", (int)(EPOCHS / 1000000));
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
  SDL_RenderClear(renderer);

  for (long epoch = 0; epoch < (long)EPOCHS; ++epoch)
  {
    coin_toss_result = 1 - (random() % 2) * 2; // either -1 or 1

    if (score == 0)
    {
      returns_to_origin++;
      coin_toss_result > 0 ? SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255) : SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    }

    score += coin_toss_result;

    if (score > 0)
      num_times_positive++;

    if (score > max_score)
      max_score = score;

    if (score < min_score)
      min_score = score;

    if (epoch % EPOCH_STEP == 0)
    {

      cur_x += 2;
      cur_y = WINDOW_WIDTH / 2 - round(score / Y_SQUEEZE);

      // if (epoch % (100 * EPOCH_STEP) == 0)
      //   printf("\nEpoch %ld:: Result %i, num_times_positive %ld\n", epoch, coin_toss_result, num_times_positive);

      SDL_RenderDrawLine(renderer, prev_x, prev_y, cur_x, cur_y);
      // SDL_RenderDrawPoint(renderer, cur_x, cur_y);

      prev_x = cur_x;
      prev_y = cur_y;
    }
  }
  printf("\n\tFinal score: %i\n\n\tMaximum score: %i\n\tMinimum score: %i\n\tReturns to origin: %ld\n\tRatio positive: %ld%%\n", score, max_score, min_score, returns_to_origin, (long)(100 * num_times_positive / (EPOCHS)));
  printf("\n----------------------------------------------------------\n");

  printf("\n\n (press space to play again)\n\n");
  SDL_RenderPresent(renderer);
}

int main(void)
{
  SDL_Event event;
  SDL_Renderer *renderer;
  SDL_Window *window;

  SDL_Init(SDL_INIT_VIDEO);
  SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_WIDTH, 0, &window, &renderer);

  playGame(renderer);

  while (1)
  {
    if (SDL_PollEvent(&event))
      switch (event.type)
      {
      case SDL_QUIT:
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_SUCCESS;
        break;

      case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_SPACE)
        {
          playGame(renderer);
        }
        break;

      default:
        break;
      }
  }
}