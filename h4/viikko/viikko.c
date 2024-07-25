/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
 */

#include "viikko.h"
#include <time.h>

#define BUFFER_SIZE 80
#define WEEKDAYS 7

void viikko(int pv, int kk, int vuosi)
{
    char date[BUFFER_SIZE];
    struct tm time_info = {0};
    int i;

    time_info.tm_mday = pv;
    time_info.tm_mon = kk - 1;
    time_info.tm_year = vuosi - 1900;
    mktime(&time_info);
    time_info.tm_mday -= (time_info.tm_wday + 6) % 7;
    mktime(&time_info);

    for (i = 0; i < WEEKDAYS; i++) {
        strftime(date, BUFFER_SIZE, "%A %d. %B %Y", &time_info);
        printf("%s\n", date);
        time_info.tm_mday++;
        mktime(&time_info);
    }
}
