/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
 */

#include "kortit.h"

const char *MAIDEN_NIMET[MAA_LKM + 1] = {"", "Hertta", "Ruutu", "Risti", "Pata"};
const char *KORTTIEN_NIMET[MAA_KOKO + 1] = {"", "ässä", "kakkonen", "kolmonen",
                                            "nelonen", "viitonen", "kuutonen",
                                            "seiska", "kasi", "ysi", "kymppi",
                                            "jätkä", "rouva", "kunkku"};

void tulostaKortti(Kortti kortti)
{
    const char *korttiMaaStr = MAIDEN_NIMET[kortti.maa];
    const char *korttiArvoStr = KORTTIEN_NIMET[kortti.arvo];
    char kortinNimi[60];

    strcpy(kortinNimi, korttiMaaStr);
    strcat(kortinNimi, korttiArvoStr);
    printf("%s", kortinNimi);
}


void tulostaKorttiOs(const Kortti *korttiOs) 
{
    const char *korttiMaaStr = MAIDEN_NIMET[korttiOs->maa];
    const char *korttiArvoStr = KORTTIEN_NIMET[korttiOs->arvo];
    char kortinNimi[60];

    strcpy(kortinNimi, korttiMaaStr);
    strcat(kortinNimi, korttiArvoStr);
    printf("%s", kortinNimi);
}