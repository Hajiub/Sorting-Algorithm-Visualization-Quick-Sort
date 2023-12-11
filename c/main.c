#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define WIDTH 900
#define HEIGHT 700
#define BAR_W 5
#define NUM 150

int array[NUM] = {0};
SDL_Renderer *renderer;

int randint(int a, int b)
{
    return a + rand() % (b - a + 1);
}
void generateRandomArray(void)
{
    for (int i = 0; i < NUM; i++)
    {
        array[i] = randint(0, HEIGHT);
    }
}

void drawBars()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    for (int i = 0; i < NUM; i++)
    {
        SDL_Rect bar = {i * (BAR_W + 1), HEIGHT - array[i], BAR_W, array[i]};
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderFillRect(renderer, &bar);
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(5); 
}


void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void bubbleSort() {
    for (int i = 0; i < NUM - 1; i++) {
        for (int j = 0; j < NUM - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
            drawBars();
        }
        drawBars();
    }
}

int partition(int *array, int low, int high)
{
    int piv, i, j;
    piv = array[high];
    j = low - 1;
    for (i = low; i < high; i++)
    {
        drawBars();
        if (piv >= array[i])
        {
            j++;
            // swap
            swap(&array[i], &array[j]);
        }
    }
    drawBars();
    j++;
    swap(&array[j], &array[high]);
    return j;
}

void quicksort(int *array, int low, int high)
{
    if (low < high)
    {
        int piv = partition(array, low, high);

        quicksort(array, low, piv - 1);
        drawBars();
        quicksort(array, piv + 1, high);
    }
}
int main()
{
    srand(time(NULL));
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window;
    

    SDL_CreateWindowAndRenderer(900, 700, 0, &window, &renderer);
    SDL_Event event;
    int quit = 0;

    generateRandomArray();
    while (!quit)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                quit = 1;
                exit(EXIT_SUCCESS);
            }
            else if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_b:
                    bubbleSort();
                    break;
                
                case SDLK_q:
                    quicksort(array, 0, NUM - 1);
                    break;

                case SDLK_SPACE:
                    generateRandomArray();
                    break;
                case SDLK_ESCAPE:
                    quit = 1;
                    exit(EXIT_SUCCESS);
                    break;
                default:
                    break;
                }
                
            }
        }

        drawBars();
    }
    
}                   