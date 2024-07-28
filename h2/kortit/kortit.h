/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
 */

#ifndef KORTIT_H
#define KORTIT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Maa {
    HERTTA = 1,
    RUUTU,
    RISTI,
    PATA
};
typedef enum Maa Maa;

enum Arvo {
    ASSA = 1,
    KAKKONEN,
    KOLMONEN,
    NELONEN,
    VIITONEN,
    KUUTONEN,
    SEISKA,
    KASI,
    YSI,
    KYMPPI,
    JATKA,
    ROUVA,
    KUNKKU
};
typedef enum Arvo Arvo;

enum Lkm {
    MAA_LKM = 4,
    MAA_KOKO = 13,
    KORTTI_LKM = MAA_LKM * MAA_KOKO
};

const char *MAIDEN_NIMET[MAA_LKM + 1];
const char *KORTTIEN_NIMET[MAA_KOKO + 1];

struct Kortti {
    Maa maa;
    Arvo arvo;
};
typedef struct Kortti Kortti;

void tulostaKortti(Kortti kortti);
void tulostaKorttiOs(const Kortti *korttiOs);


#endif