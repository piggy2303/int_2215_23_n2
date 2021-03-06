// #include <SDL2/SDL.h>
// #include <iostream>

// using namespace std;

// int main()
// {
//     SDL_Window *window = NULL;
//     window = SDL_CreateWindow(
//         "rec", SDL_WINDOWPOS_UNDEFINED,
//         SDL_WINDOWPOS_UNDEFINED,
//         640,
//         480,
//         SDL_WINDOW_SHOWN);

//     // Setup renderer
//     SDL_Renderer *renderer = NULL;
//     renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

//     // Set render color to red ( background will be rendered in this color )
//     SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

//     // Clear winow
//     SDL_RenderClear(renderer);

//     // Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
//     SDL_Rect r;
//     r.x = 50;
//     r.y = 50;
//     r.w = 50;
//     r.h = 50;

//     // Set render color to blue ( rect will be rendered in this color )
//     SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

//     // Render rect
//     SDL_RenderFillRect(renderer, &r);

//     // Render the rect to the screen
//     SDL_RenderPresent(renderer);

//     bool is_running = true;
//     SDL_Event event;
//     while (is_running)
//     {
//         while (SDL_PollEvent(&event))
//         {
//             if (event.type == SDL_QUIT)
//             {
//                 is_running = false;
//             }
//         }
//         SDL_Delay(16);
//     }

//     SDL_DestroyWindow(window);
//     SDL_Quit();
// }

#include <iostream>
// #include <SDL.h>
#include <SDL.h>

using namespace std;

//**************************************************************
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "Keyboard in SDL";

void logSDLError(std::ostream &os,
                 const std::string &msg, bool fatal = false);
void initSDL(SDL_Window *&window, SDL_Renderer *&renderer);
void quitSDL(SDL_Window *window, SDL_Renderer *renderer);
void waitUntilKeyPressed();
//**************************************************************

void refreshScreen(SDL_Window *window, SDL_Renderer *renderer, const SDL_Rect &filled_rect);

int main(int argc, char *argv[])
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    initSDL(window, renderer);

    // Your code here
    SDL_Event e;

    // ?????nh ngh??a to??? ????? ban ?????u v?? k??ch c??? h??nh ch??? nh???t
    SDL_Rect filled_rect;
    filled_rect.x = SCREEN_WIDTH / 2;
    filled_rect.y = SCREEN_HEIGHT / 2;
    filled_rect.w = 16;
    filled_rect.h = 12;
    // B?????c nh???y m???i khi d???ch chuy???n
    int step = 4;
    // Xo?? to??n b??? m??n h??nh v?? v???
    refreshScreen(window, renderer, filled_rect);

    while (true)
    {
        // ?????i 10 mili gi??y
        SDL_Delay(10);

        // N???u kh??ng c?? s??? ki???n g?? th?? ti???p t???c tr??? v??? ?????u v??ng l???p
        if (SDL_WaitEvent(&e) == 0)
            continue;

        // N???u s??? ki???n l?? k???t th??c (nh?? ????ng c???a s???) th?? tho??t kh???i v??ng l???p
        if (e.type == SDL_QUIT)
            break;

        // N???u c?? m???t ph??m ???????c nh???n, th?? x??t ph??m ???? l?? g?? ????? x??? l?? ti???p
        if (e.type == SDL_KEYDOWN)
        {
            // N???u nh???n ph??m ESC th?? tho??t kh???i v??ng l???p
            if (e.key.keysym.sym == SDLK_ESCAPE)
                break;

            // N???u ph??m m??i t??n tr??i, d???ch sang tr??i
            // (c???ng chi???u r???ng, tr??? b?????c, r???i l???y ph???n d?? ????? gi?? tr??? lu??n d????ng, v?? hi???u ???ng quay v??ng)
            if (e.key.keysym.sym == SDLK_LEFT)
                filled_rect.x = (filled_rect.x + SCREEN_WIDTH - step) % SCREEN_WIDTH;
            // T????ng t??? v???i d???ch ph???i, xu???ng v?? l??n
            if (e.key.keysym.sym == SDLK_RIGHT)
                filled_rect.x = (filled_rect.x + step) % SCREEN_WIDTH;
            if (e.key.keysym.sym == SDLK_DOWN)
                filled_rect.y = (filled_rect.y + step) % SCREEN_HEIGHT;
            if (e.key.keysym.sym == SDLK_UP)
                filled_rect.y = (filled_rect.y + SCREEN_HEIGHT - step) % SCREEN_HEIGHT;

            // Xo?? to??n b??? m??n h??nh v?? v??? l???i
            refreshScreen(window, renderer, filled_rect);
        }
    }

    quitSDL(window, renderer);
    return 0;
}

// Xo?? v?? v??? l???i to??n b??? m??n h??nh v???i 1 h??nh ch??? nh???t
void refreshScreen(SDL_Window *window, SDL_Renderer *renderer, const SDL_Rect &filled_rect)
{
    // ?????t m??u v??? th??nh xanh lam (blue), xo?? m??n h??nh v??? m??u xanh lam.
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // blue
    SDL_RenderClear(renderer);

    // ?????t m??u v??? v??? tr???ng v?? v??? h??nh ch??? nh???t
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white
    SDL_RenderFillRect(renderer, &filled_rect);

    // D??ng l???nh hi???n th??? (????a) h??nh ???? v??? ra m??nh h??nh
    // Khi th??ng th?????ng ch???y v???i m??i tr?????ng b??nh th?????ng ??? nh??
    SDL_RenderPresent(renderer);
    // Khi ch???y ??? m??y th???c h??nh WinXP ??? tr?????ng (m??y ???o)
    // SDL_UpdateWindowSurface(window);
}

//*****************************************************
// C??c h??m chung v??? kh???i t???o v?? hu??? SDL
void logSDLError(std::ostream &os,
                 const std::string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal)
    {
        SDL_Quit();
        exit(1);
    }
}

void initSDL(SDL_Window *&window, SDL_Renderer *&renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    // window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
    //    SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (window == nullptr)
        logSDLError(std::cout, "CreateWindow", true);

    // Khi th??ng th?????ng ch???y v???i m??i tr?????ng b??nh th?????ng ??? nh??
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    // Khi ch???y ??? m??y th???c h??nh WinXP ??? tr?????ng (m??y ???o)
    // renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
    if (renderer == nullptr)
        logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void quitSDL(SDL_Window *window, SDL_Renderer *renderer)
{
    // SDL_DestroyRenderer(renderer);
    // SDL_DestroyWindow(window);
    // SDL_Quit();
    bool is_running = true;
    SDL_Event event;
    while (is_running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                is_running = false;
            }
        }
        SDL_Delay(16);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true)
    {
        if (SDL_WaitEvent(&e) != 0 &&
            (e.type == SDL_KEYDOWN || e.type == SDL_QUIT))
            return;
        SDL_Delay(100);
    }
}
//**************************************************************
