export module Input;

import Common;
import Common.Demo;
import Common.SDL;

export class CInput
{
public:

    CInput();
    ~CInput();

    bool GetKeyState(SDL_Scancode key) const;

private:

    demo::span<const uint8> m_keyStates;
};