// because EASTL is written by very special people and doesn't differentiate between aligned and unaligned free, we have to treat everything as aligned

inline void* allocateAligned(size_t n, size_t align)
{
    return _aligned_malloc(n, align);
}

inline void freeAligned(void* p)
{
    _aligned_free(p);
}

void* operator new(size_t n)
{
    return allocateAligned(n, 0);
}

void* operator new(size_t n, std::align_val_t align)
{
    return allocateAligned(n, (size_t)align);
}

void* operator new[](std::size_t n)
{
    return allocateAligned(n, 0);
}

void* operator new[](std::size_t n, std::align_val_t align)
{
    return allocateAligned(n, (size_t)align);
}

void operator delete(void* p)
{
    freeAligned(p);
}

void operator delete(void* p, std::align_val_t align)
{
    freeAligned(p);
}

void operator delete[](void* p)
{
    freeAligned(p);
}

void operator delete[](void* p, std::align_val_t align)
{
    freeAligned(p);
}