#include "tetris.h"

const char EMPTY_SQUARE = 32;
const char EMPTY_ROW[] = "          ";
const char FULL_ROW[] = "xxxxxxxxxx";

/* Alla määritetään 2-ulotteinen 20x10-kokoinen staattinen merkkitaulukko,
   jossa täynnä olevat ruudut on merkitty merkillä 'x'. Kukin 10-alkioinen
   alitaulukko alustetaan merkkijonolla (jonka loppumerkki leikkautuu pois). */
char ruudukko[COLUMN_LENGTH][ROW_WIDTH] = {
                         "          ",  /* Rivi 0: ylin rivi.                */
                         "  x   x   ",  /* Rivi 1: toiseksi ylin rivi.       */
                         " xx   xxx ",  /* ...ja niin edelleen...            */
                         "xxx xxxxxx",
                         "xxxxxxxxxx",  /* Rivi 4: täynnä.                   */
                         "xxxxxxxxxx",  /* Rivi 5: täynnä.                   */
                         "xxxxxx xxx",
                         "xxxxxxx xx",
                         "x xxxxxxxx",
                         "xxx xxx xx",
                         "xxxxxx xxx",
                         "x xx xxx x",
                         "xxxxxxxxx ",
                         "xxx xxx xx",
                         "xxxxx xx x",
                         " xxxxxxxxx",
                         "xxx xxx xx",
                         "x xxxx xxx",
                         "xxxxx xxxx",  /* Rivi 18: toiseksi alin rivi.      */
                         "xxxxxxxx x"}; /* Rivi 19: alin rivi.               */

int compare_rows(const char row1[ROW_WIDTH], const char row2[ROW_WIDTH]) {
    int i = 0;
    for (; i < ROW_WIDTH; i++) {
        if (row1[i] != row2[i]) {
          /* not equal */
          return 0;
        }
    }
    /* equal */
    return 1;
}

void paivita(char ruudukko[COLUMN_LENGTH][ROW_WIDTH])
{
  int i, j, k;
  char temp_ruudukko[ROW_WIDTH];

  for (i = 0; i < COLUMN_LENGTH; i++)
  {
    /* if row i is full */
    if (compare_rows(ruudukko[i], FULL_ROW)) {
      /* swap the current row with the row above, repeat until top */
      for (j = i; j > 0; j--) {
        /* Copy row j-1 to temp */
        for (k = 0; k < ROW_WIDTH; k++) {
          temp_ruudukko[k] = ruudukko[j - 1][k];
        }
        /* Copy row j to row j-1 */
        for (k = 0; k < ROW_WIDTH; k++) {
          ruudukko[j - 1][k] = ruudukko[j][k];
        }
        /* Copy temp to row j */
        for (k = 0; k < ROW_WIDTH; k++) {
          ruudukko[j][k] = temp_ruudukko[k];
        }
      }
      /* Clear the top row */
      for (k = 0; k < ROW_WIDTH; k++) {
        ruudukko[0][k] = EMPTY_ROW[k];
      }
    }
  }
}

int main(void)
{
    int i = 0;
    paivita(ruudukko);       /* Poistetaan tyhjät rivit. */
    for(i = 0; i < 20; ++i)  /* Tulostetaan ruudukko.    */
    {
      printf("%.10s\n", ruudukko[i]); /* Tulostetaan 1 rivi eli 10 merkkiä. */
    }
    return 0;
    }