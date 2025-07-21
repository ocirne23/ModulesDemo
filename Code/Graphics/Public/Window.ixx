export module Graphics.Window;

import Common;
import Common.SDL;

export class CWindow
{
public:

    CWindow(const char* title, int32 width, int32 height);
    ~CWindow();

    SDL_Window* GetSDLWindow() const { return m_pWindow.get(); }

private:

    std::unique_ptr<SDL_Window, SSDLFree> m_pWindow;
};

