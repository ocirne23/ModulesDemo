module Graphics.Renderer;

import Graphics.Window;

CRenderer::CRenderer(CWindow& rWindow, const char* renderer)
{
    m_pRenderer = std::unique_ptr<SDL_Renderer, SSDLFree>(SDL_CreateRenderer(rWindow.GetSDLWindow(), renderer, 0));
}

CRenderer::~CRenderer()
{

}

void CRenderer::Clear()
{
    SDL_SetRenderDrawColor(m_pRenderer.get(), 0, 0, 0, 255);
    SDL_RenderClear(m_pRenderer.get());
}

void CRenderer::DrawRect(const SDL_FRect& rect, const SDL_Color& color)
{
    SDL_SetRenderDrawColor(m_pRenderer.get(), color.r, color.b, color.g, color.a);
    SDL_RenderFillRect(m_pRenderer.get(), &rect);
}

void CRenderer::Present()
{
    SDL_RenderPresent(m_pRenderer.get());
}