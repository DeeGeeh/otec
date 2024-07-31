/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 *
 * Diar Ghaderi (152098520)
 * diar.ghaderi@tuni.fi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define FACTOR 2
#define AMOUNT_OF_COMMANDS 4
#define LINE_SIZE 80
#define EUR "EUR"



struct ExchangeRate
{
    char currency[4];
    double rate;
};
typedef struct ExchangeRate ExchangeRate;

struct ExhangeRateList
{
    ExchangeRate* rates;
    size_t size;
    size_t capacity;
};
typedef struct ExhangeRateList ExhangeRateList;

void freeData(ExhangeRateList* list)
{
    free(list->rates);
}

int compareRates(const void *a, const void *b)
{
    ExchangeRate* rateA = (ExchangeRate *)a;
    ExchangeRate* rateB = (ExchangeRate *)b;

    return strcmp(rateA->currency, rateB->currency);
}

ExhangeRateList initExchangeRateList(ExhangeRateList *list)
{
    list->size = 0;
    list->capacity = 4;
    list->rates = (ExchangeRate *)malloc(list->capacity * sizeof(ExchangeRate));
}

/* Find and get currency based on its name, return NULL if not found. */
ExchangeRate* getCurrency(ExhangeRateList* list, const char* currency)
{
    size_t i;

    for (i = 0; i < list->size; i++) {
        if (strcmp((const char*)(list->rates[i].currency), currency) == 0) {
            return &list->rates[i];
        }
    }
    return NULL;
}

/* Increase list size and capacity if needed. Handles memory realloc as well.*/
void addNewCurrency(ExhangeRateList* list, const char *currencyStr, double newRate)
{
    if (list->size >= list->capacity) {
        list->capacity *= FACTOR;
        list->rates = (ExchangeRate*) realloc(list->rates, list->capacity * sizeof(ExchangeRate));
    }

    strcpy(list->rates[list->size].currency, currencyStr);
    list->rates[list->size].rate = newRate;
    list->size++;
}

/* Updates rate of currency regardless of it's new or already existing. */
void updateRate(ExhangeRateList *list, const char *currencyStr, double newRate)
{
    ExchangeRate *updatedCurrency = getCurrency(list, currencyStr);
    /* CASE: New currency */
    if (updatedCurrency == NULL) {
        addNewCurrency(list, currencyStr, newRate);
    }
    else {
        updatedCurrency->rate = newRate;
    }
}

void printRates(ExhangeRateList* list)
{
    size_t i;

    qsort(list->rates, list->size, sizeof(ExchangeRate), compareRates);
    for (i = 0; i < list->size; i++) {
        printf("%s %.3f\n", list->rates[i].currency, list->rates[i].rate);
    }
}

void convert(ExhangeRateList* list, const char* currencyStr, const double amount)
{
    ExchangeRate* foundCurrency = getCurrency(list, currencyStr);
    double convertedAmount = -1;

    /* CASE: Currency not found */
    if (foundCurrency == NULL) {
        printf("Valuutan %s kurssia ei ole tiedossa!\n", currencyStr);
        return;
    }

    convertedAmount = amount / foundCurrency->rate;
    printf("%.3lf %s = %.3lf %s\n", amount, foundCurrency->currency, convertedAmount, EUR);
}

int main(int argc, char const *argv[])
{
    char line[LINE_SIZE];
    char cmd[10];
    char currency[4];
    double amount;
    
    ExhangeRateList currencyList;
    initExchangeRateList(&currencyList);

    while (fgets(line, sizeof(line), stdin)) {
        if (sscanf(line, "%9s", cmd) != 1) {continue;}

        if (strcmp(cmd, "kurssi") == 0) {
            if (sscanf(line, "%*s %3s %lf", currency, &amount) == 2) {
                updateRate(&currencyList, currency, amount);
            }
        }
        else if (strcmp(cmd, "muunna") == 0) {
            if (sscanf(line, "%*s %lf %3s", &amount, currency) == 2) {
                convert(&currencyList, currency, amount);
            }
        }
        else if (strcmp(cmd, "kurssit") == 0) {
            printRates(&currencyList);
        }
        else if (strcmp(cmd, "lopeta") == 0) {
            break;
        }
    }
    
    return 0;
}
