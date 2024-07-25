#ifndef signaalit_h
#define signaalit_h

#include <setjmp.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

extern jmp_buf paluuTila;

/* floating point exeption */
void hoidaSIGFPE(int s);

/* segmentation violation */
void hoidaSIGSEGV(int s);


#endif