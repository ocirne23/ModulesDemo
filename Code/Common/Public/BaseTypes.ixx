export module Common:BaseTypes; // Module partition, cannot be imported except by the parent (Common)

export typedef signed char        int8;
export typedef short              int16;
export typedef int                int32;
export typedef long long          int64;
export typedef unsigned char      uint8;
export typedef unsigned short     uint16;
export typedef unsigned int       uint32;
export typedef unsigned long long uint64;

export constexpr int8   INT8_MAX   = 0x7fi8;
export constexpr int16  INT16_MAX  = 0x7fffi16;
export constexpr int32  INT32_MAX  = 0x7fff'ffffi32;
export constexpr int64  INT64_MAX  = 0x7fff'ffff'ffff'ffffi64;
export constexpr int8   INT8_MIN   = -INT8_MAX - 1;
export constexpr int16  INT16_MIN  = -INT16_MAX - 1;
export constexpr int32  INT32_MIN  = -INT32_MAX - 1;
export constexpr int64  INT64_MIN  = -INT64_MAX - 1;
export constexpr uint8  UINT8_MAX  = 0xffui8;
export constexpr uint16 UINT16_MAX = 0xffffui16;
export constexpr uint32 UINT32_MAX = 0xffffffffui32;
export constexpr uint64 UINT64_MAX = 0xffffffffffffffffui64;