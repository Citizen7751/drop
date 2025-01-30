#ifndef DROP_H
#define DROP_H

#ifdef _WIN32
    #include <windows.h>

    typedef long long unsigned int size_t;

    void ansi_on();
    void ansi_off();
    #define ANSI_ON ansi_on()
    #define ANSI_OFF ansi_off()

#elif __linux__
    #define ANSI_ON ;
    #define ANSI_OFF ;
#endif

#define PRINTING_LENGTH 60 //can be customised
#define BIBLE_LENGTH 31102

#include <stdint.h>

typedef struct {
	struct ansi { uint8_t bg, fg; } ansi;
    struct rgb { uint8_t bgr, bgg, bgb, fgr, fgg, fgb; } rgb;
} color_t;

typedef struct {
    char title[PRINTING_LENGTH];
    char text[551];
} Verse;

extern const Verse Bible[BIBLE_LENGTH];

#endif //DROP_H