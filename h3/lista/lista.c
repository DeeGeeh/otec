#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

DblSolmu *ds_luo(double data, DblSolmu *seur) {
    DblSolmu *ds = malloc(sizeof(DblSolmu));
    ds->data = data;
    ds->seur = seur;
    return ds;
}

DblLista *dl_luo(void) {
    DblLista *dl = malloc(sizeof(DblLista));
    dl->n = 0;
    dl->paa = NULL;
    return dl;
}

void dl_tuhoa(DblLista *dl) {
    while (dl->n > 0) {
        dl_poistaEdesta(dl);
    }
    free(dl);
}

DblSolmu *dl_lisaaEteen(DblLista *dl, double arvo) {
    dl->paa = ds_luo(arvo, dl->paa);
    dl->n += 1;
    return dl->paa;
}

double dl_poistaEdesta(DblLista *dl) {
    double arvo = 0;
    if (dl->n > 0) {
        DblSolmu *vanhaPaa = dl->paa;
        arvo = dl->paa->data;
        dl->paa = dl->paa->seur;
        free(vanhaPaa);
        dl->n -= 1;
    }
    return arvo;
}

void dl_tulosta(const DblLista *lista) {
    DblSolmu *s;
    printf("Lista:");
    for (s = lista->paa; s != NULL; s = s->seur) {
        printf(" %.1f", s->data);
    }
    printf("\n");
}

double dl_alkio(const DblLista *lista, size_t i) {
    unsigned int count = 0;
    DblSolmu *s;

    if (i < lista->n) {
        for (s = lista->paa; s != NULL; s = s->seur) {
            if (count == i) {
                return s->data;
            }
            count++;
        }
    }

    /* should not reach this...
       unless i is out of bounds */
    return 0.0;
}

DblSolmu *dl_lisaa(DblLista *lista, size_t i, double data) {
    DblSolmu *new_node;
    DblSolmu *curr_node;
    size_t count = 0;

    if (i == 0) {
        return dl_lisaaEteen(lista, data);
    }

    if (i >= lista->n) {
        new_node = ds_luo(data, NULL);
        curr_node = lista->paa;
        while (curr_node->seur != NULL) {
            curr_node = curr_node->seur;
        }
        curr_node->seur = new_node;
        lista->n++;
        return new_node;
    }

    for (curr_node = lista->paa; curr_node != NULL; curr_node = curr_node->seur) {
        if (count == i - 1) {
            new_node = ds_luo(data, curr_node->seur);
            curr_node->seur = new_node;
            lista->n++;
            return new_node;
        }
        count++;
    }

    return NULL;
}

double dl_poista(DblLista *lista, size_t i) {
    DblSolmu *node = lista->paa;
    DblSolmu *temp;
    double data = 0;
    size_t count = 0;

    /* out of bounds i */
    if (i >= lista->n) {
        return 0.0;
    }

    /* first node */
    if (i == 0) {
        return dl_poistaEdesta(lista);
    }

    /* find the node before the one we want to delete */
    for (count = 0; count < i - 1; count++) {
        if (node == NULL) {
            /* this shouldnt happen */
            return 0.0;
        }
        node = node->seur;
    }

    temp = node->seur;
    node->seur = temp->seur;
    data = temp->data;
    free(temp);
    lista->n--;
    return data;
}
