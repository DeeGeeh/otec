#ifndef lista_h
#define lista_h

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct DblSolmu {
    double data;
    struct DblSolmu *seur;
};
typedef struct DblSolmu DblSolmu;


struct DblLista {
    size_t n;
    DblSolmu *paa;
};
typedef struct DblLista DblLista;

DblSolmu *ds_luo(double data, DblSolmu *seur);

DblLista *dl_luo(void);

void dl_tuhoa(DblLista *dl);

DblSolmu *dl_lisaaEteen(DblLista *dl, double arvo);

double dl_poistaEdesta(DblLista *dl);

void dl_tulosta(const DblLista *lista);

double dl_alkio(const DblLista *lista, size_t i);

DblSolmu *dl_lisaa(DblLista *lista, size_t i, double arvo);

double dl_poista(DblLista *lista, size_t i);

#endif