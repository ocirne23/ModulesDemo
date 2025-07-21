module Graphics.Window;

CWindow::CWindow(const char* title, int32 width, int32 height)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
    {
        printf("SDL_Init Error: %s\n", SDL_GetError());
    }

    m_pWindow = std::unique_ptr<SDL_Window, SSDLFree>(SDL_CreateWindow(title, width, height, SDL_WINDOW_INPUT_FOCUS));
}

CWindow::~CWindow()
{

}