#include "signaalit.h"

void hoidaSIGFPE(int s)
{
    signal(SIGFPE, hoidaSIGFPE);
    longjmp(paluuTila, SIGFPE);
}

void hoidaSIGSEGV(int s)
{
    signal(SIGSEGV, hoidaSIGSEGV);
    longjmp(paluuTila, SIGSEGV);
}
