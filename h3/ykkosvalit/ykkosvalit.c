/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
 */

#include "ykkosvalit.h"

UintPari ykkosValit(const char *syoteNimi, const char *tulosNimi)
{
    UintPari result = {0, 0};
    char ch;
    
    /* tracks if the last char read was a space */
    bool wasSpace = false;
    /* tracks if the last char read was a newline */
    bool wasNewline = false;
    /* tracks if atleast 1 non-whitespace char has been written to output */
    bool chWritten = false;

    FILE* inputFile = fopen(syoteNimi, "r"); 
    FILE* outputFile = fopen(tulosNimi, "w");

    while ((ch = fgetc(inputFile)) != EOF) {
        result.x++;

        if (ch == '\n') { 
            fputc('\n', outputFile);
            result.y++;
            wasNewline = true;
        }
        else if (ch == ' ') {
            wasSpace = true;
        }
        else {
            if (!wasNewline && wasSpace && chWritten) {
                fputc(' ', outputFile);
                result.y++;
            }
            fputc(ch, outputFile);
            result.y++;
            wasSpace = false;
            wasNewline = false;
            chWritten = true;
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    return result;
}


int main(int argc, char const *argv[])
{
    UintPari result = ykkosValit("input.txt", "output.txt");    
    printf("x: %d\ny: %d\n", result.x, result.y);

    return 0;
}
