export module Common.eastl;

export import <EASTL/vector.h>;
export import <EASTL/array.h>;
export import <EASTL/list.h>;
export import <EASTL/bitset.h>;

export import <EASTL/map.h>;
export import <EASTL/set.h>;
export import <EASTL/unordered_map.h>;
export import <EASTL/unordered_set.h>;

export import <EASTL/span.h>;
export import <EASTL/string_view.h>;
export import <EASTL/string.h>;

export import <EASTL/variant.h>;
export import <EASTL/tuple.h>;

// Required functions for static EASTL
void* __cdecl operator new[](size_t size, const char* name, int flags, unsigned debugFlags, const char* file, int line)
{
	return operator new(size, std::align_val_t(0));
}

void* operator new[](size_t size, size_t alignment, size_t alignmentOffset, const char* pName, int flags, unsigned debugFlags, const char* file, int line)
{
	return operator new(size, std::align_val_t(alignment));
}