/* File: h-config.h */

#ifndef INCLUDED_H_CONFIG_H
#define INCLUDED_H_CONFIG_H

// these were all missing and throwing errors -N
#ifndef PATH_MAX
#define PATH_MAX 256
#endif

#ifndef SDL_DEFAULT_REPEAT_DELAY
#define SDL_DEFAULT_REPEAT_DELAY 500
#endif

#ifndef SDL_DEFAULT_REPEAT_INTERVAL
#define SDL_DEFAULT_REPEAT_INTERVAL 30
#endif

#define 	SDL_HWSURFACE   0x00000001
#define 	SDL_SRCALPHA   0x00010000

#undef PATH_SEP
#define PATH_SEP "/"

#define FILE_TYPE(X) ((void)0)

#define HAS_STRICMP

#define HAS_MEMSET

#endif
