module Input;

import Common.SDL;

CInput::CInput()
{
    int numKeys;
    const uint8* pKeys = SDL_GetKeyboardState(&numKeys);
    m_keyStates = demo::span<const uint8>(pKeys, numKeys);
}

CInput::~CInput()
{

}

bool CInput::GetKeyState(SDL_Scancode key) const
{
    assert(key <= m_keyStates.size());
    return m_keyStates[(int)key] != 0;
}