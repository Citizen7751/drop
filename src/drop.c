#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "drop.h"

const char EXIT_KEY = ' ';
const char EMPTY_SPACE = ' ';
const char BORDER = '|';

/* Notice #1
   This is not a very flexible solution for multiple color-types,
   there is no point in using other ones.
   If there is a GUI, the terminal emulator supports RGB.
   Otherwise, without GUI, it only supports 4 bit colors.
 */
static void set_color (const color_t* pcol, const uint8_t is_4bit) {
	(is_4bit) ?
		printf("\033[%u;%um", pcol->_4bit.bg, pcol->_4bit.fg) :
        printf("\033[48;2;%u;%u;%um\033[38;2;%u;%u;%um",
            pcol->rgb.bgr, pcol->rgb.bgg, pcol->rgb.bgb,
            pcol->rgb.fgr, pcol->rgb.fgg, pcol->rgb.fgb);
}

/* Notice #2
   When the command prompt/terminal is resized, the colors just "splash"
   everywhere in a long line, hence the need for actual borders where
   all the ansi graphic settings are set back to default and a character
   is printed with those settings.
*/
static inline void print_border() {
    printf("\033[0m%c\n", BORDER);
}

static void print_colored_line(const size_t length, const color_t* pcol, const uint8_t is_4bit) {

    set_color(pcol, is_4bit);
    for (size_t i = 0; i < length; i++)
        putchar(EMPTY_SPACE);
    print_border();
}

static void print_colored_title(const Verse* v, const color_t* pcol, const uint8_t is_4bit) {

	set_color(pcol, is_4bit);
    const size_t first_half = (PRINTING_LENGTH - strlen(v->title)) / 2;
    for (size_t i = 0; i < first_half; i++)
        putchar(EMPTY_SPACE);
    printf("%s", v->title);	
	for (size_t i = 0; i < PRINTING_LENGTH - first_half - strlen(v->title); i++)
        putchar(EMPTY_SPACE);
    print_border();
}

static void print_colored_text(const Verse* v, const color_t* pcol, const uint8_t is_4bit) {

	size_t column = 0;
    for (size_t i = 0; v->text[i] != '\0';) {
		set_color(pcol, is_4bit);
        for (column = 0; column < PRINTING_LENGTH && v->text[i] != '\0'; i++, column++)
            putchar(v->text[i]);
        print_colored_line(PRINTING_LENGTH - column, pcol, is_4bit);
    }
}

static void print_verse(const uint8_t is_4bit) {
    Verse rand_verse;

    const color_t header_color = {
        {43, 30},
        {151, 139, 37, 70, 50, 10}
    };

	const color_t text_shadow_color = {
		{47, 30},
		{92, 57, 4, 92, 57, 4}
	};
	
    const color_t text_body_color = {
        {47, 30},
        {102, 67, 14, 255, 255, 255}
    };

    do {
		rand_verse = Bible[rand()%BIBLE_LENGTH];

		print_colored_title(&rand_verse, &header_color, is_4bit);
        print_colored_line(PRINTING_LENGTH, &text_shadow_color, is_4bit);
        print_colored_text(&rand_verse, &text_body_color, is_4bit);
        print_colored_line(PRINTING_LENGTH, &text_body_color, is_4bit);
        print_colored_line(PRINTING_LENGTH, &header_color, is_4bit);

    } while(getchar() != EXIT_KEY);
}




int main(int argc, char* argv[]) {
    ANSI_ON;
    srand(time(NULL));

    const uint8_t is_4bit = (argv[1] != NULL && !strcmp(argv[1], "-4")); 
    print_verse(is_4bit);

    while(getchar()!='\n');
    ANSI_OFF;
    return EXIT_SUCCESS;
}
