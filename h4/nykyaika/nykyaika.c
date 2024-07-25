/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
 */

#include <ctype.h>
#include <locale.h>
#include <time.h>
#include <stdio.h>

#define BUFFER_SIZE 50

char *WEEKDAYS[7] = {"Sunnuntai", "Maanantai", "Tiistai",
                     "Keskiviikko", "Torstai", "Perjantai",
                     "Lauantai"};

int main(int argc, char const *argv[])
{
    char buffer[BUFFER_SIZE];
    time_t a = time(NULL);
    struct tm *b = gmtime(&a);
    
    setlocale(LC_TIME, "fi_FI");
    time(&a);
    b = localtime(&a);
    strftime(buffer, BUFFER_SIZE, "%A %d.%m.%Y klo %H:%M", b);
    buffer[0] = toupper(buffer[0]);
    printf("%s\n", buffer);
    return 0;
}

