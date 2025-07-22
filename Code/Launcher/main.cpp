import Common;
import Common.SDL;     // for SDL_FRect, SDL_Color
import Common.Demo;
import Common.glm;

import Graphics.Window;
import Graphics.Renderer;

import Input;

int main()
{
    CWindow window("Test", 480, 360);
    CRenderer renderer(window, "software");
    CInput input;

    const float speed = 150.0f;
    glm::vec2 position(150.0f, 150.0f);

    const uint64 countPerSecond = SDL_GetPerformanceFrequency();
    uint64 startTime = SDL_GetPerformanceCounter();
    while (!input.GetKeyState(SDL_SCANCODE_ESCAPE))
    {
        const uint64 currTime = SDL_GetPerformanceCounter();
        const uint64 timePassed = currTime - startTime;
        const float deltaSec = (float)timePassed / (float)countPerSecond;
        startTime = currTime;

        glm::vec2 direction(0.0f, 0.0f);
        if (input.GetKeyState(SDL_SCANCODE_W)) direction.y = -1.0f;
        if (input.GetKeyState(SDL_SCANCODE_S)) direction.y += 1.0f;
        if (input.GetKeyState(SDL_SCANCODE_A)) direction.x = -1.0f;
        if (input.GetKeyState(SDL_SCANCODE_D)) direction.x += 1.0f;
        if (glm::length(direction) > 1.0f) 
            direction = glm::normalize(direction);

        position += direction * speed * deltaSec;

        SDL_Event event;
        while (SDL_PollEvent(&event)) { }

        renderer.Clear();
        const SDL_FRect rect = { .x = position.x, .y = position.y, .w = 50, .h = 50 };
        const SDL_Color color = { .r = 255, .g = 0, .b = 0, .a = 255 };
        renderer.DrawRect(rect, color);
        renderer.Present();

        demo::Sleep(1);
    }

    return 0;
}
