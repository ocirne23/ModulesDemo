export module Common;

export import :BaseTypes; // re-export everything in partitions
export import :STDIncludes;

import Common.Windows;

namespace demo
{
    export void Sleep(uint32 ms)
    {
        ::Sleep(ms); // Windows.h Sleep
    }

    export template<typename T>
    void Sleep2(T ms)
    {
        ::Sleep(static_cast<uint32>(ms));
    }
}


export namespace demo
{
    void Sleep3(uint32 ms) 
    { 
        ::Sleep(ms); 
    }
}