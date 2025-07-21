export module Graphics.Renderer;

import Common;
import Common.SDL;

export class CWindow;

export class CRenderer
{
public:

    CRenderer(CWindow& rWindow, const char* renderer);
    ~CRenderer();

    void Clear();
    void DrawRect(const SDL_FRect& rect, const SDL_Color& color);
    void Present();

private:

    std::unique_ptr<SDL_Renderer, SSDLFree> m_pRenderer;
};