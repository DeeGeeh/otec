/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
 */

#include "asteet.h"

const float KELVIN_CONVERSION = 273.15;

/* celsius to fahrenheit */
float c_to_f(float c)
{
    return (c * 1.8) + 32;
}

/* fahrenheit to celsius */
float f_to_c(float f)
{
    return (f - 32) / 1.8;
}

/* celsius to kelvin */
float c_to_k(float c) 
{
    return c + KELVIN_CONVERSION;
} 

/* kelvin to celsius */
float k_to_c(float k) 
{
    return k - KELVIN_CONVERSION;
}

float muunna(Lampotila a, Asteikko b)
{
    float celsius = 0.0;

    /* case: sama asteikko */
    if (a.asteikko == b) return a.lampotila;

    /* kaikki celsiukseks, koska celsius kääntyy kaikkiin muihinki */
    if (a.asteikko == Celsius) {
        celsius = a.lampotila;
    } 
    else if (a.asteikko == Fahrenheit)
    {
        celsius = f_to_c(a.lampotila);
    }
    else if (a.asteikko == Kelvin)
    {
        celsius = k_to_c(a.lampotila);
    }

    /* muunnetaan celsius haluttuun asteikkoon b */
    if (b == Celsius) {
        return celsius;
    }
    else if (b == Fahrenheit)
    {
        return c_to_f(celsius);
    }
    else if (b == Kelvin)
    {
        return c_to_k(celsius);
    }

    return 0.0f;
}

float erotus(Lampotila a, Lampotila b, Asteikko c)
{
    float a_muunnettu = muunna(a, c);
    float b_muunnettu = muunna(b, c);
    return a_muunnettu - b_muunnettu;
}
