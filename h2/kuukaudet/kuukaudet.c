/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
 */

#include "kuukaudet.h"

#define KARKAUSVUOSI 1
#define EI_KARKAUSVUOSI 0
#define SPACE 32

const char *KK_NIMET[KK_LKM] = {
    "tammikuu",
    "helmikuu",
    "maaliskuu",
    "huhtikuu",
    "toukokuu",
    "kesäkuu",
    "heinäkuu",
    "elokuu",
    "syyskuu",
    "lokakuu",
    "marraskuu",
    "joulukuu"
};

const char KK_PAIVAT[2][KK_LKM] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int karkausvuosi(int vuosiluku) {   
    if ((vuosiluku % 4 == 0 && vuosiluku % 100 != 0) ||
        (vuosiluku % 400 == 0)) return KARKAUSVUOSI;
    
    return EI_KARKAUSVUOSI;
}

char kkPituus(const char *kkNimi, int vuosiluku) {
    int i = 0;
    int not_found = -1;
    char lower_kkNimi[20];

    /* Convert kkNimi to lower case */
   while (kkNimi[i] != '\0') {
        if (kkNimi[i] == SPACE) return not_found;
        lower_kkNimi[i] = tolower(kkNimi[i]);
        i++;
    }
    lower_kkNimi[i] = '\0';

    /* search for month */
    for (i = 0; i < KK_LKM; i++) {
        if (strcmp(lower_kkNimi, KK_NIMET[i]) == 0) {
            /* february case*/
            if (i == 1) {
                if (karkausvuosi(vuosiluku) == KARKAUSVUOSI) {
                    return KK_PAIVAT[1][1];
                } 
                else {
                    return KK_PAIVAT[0][1];
                }
            }
            else {
                return KK_PAIVAT[karkausvuosi(vuosiluku)][i];
            }
        }
    }

    return not_found;
}

int main() {
    printf("Helmikuu 2016: %d päivää\n", kkPituus("Helmikuu", 2016));
    printf("Helmikuu 2100: %d päivää\n", kkPituus("helmikuu", 2100));
    printf("Helmi kuu 2100: %d päivää\n", kkPituus("helmi kuu", 2100));

    return 0;
}