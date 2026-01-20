#include "base.h"
#include "facility.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libxml/parser.h>

base_t* base_create() {
    base_t* base = malloc(sizeof(base_t));
    base->country = NULL;
    base->name = NULL;
    base->facilities = NULL;
    base->nfacilities = 0;
    base->day = 0;
    base->month = 0;
    base->year = 0;
    return base;
}

void base_free(base_t* base) {
    if (base->country) free(base->country);
    if (base->name) free(base->name);
    for (int i = 0; i < base->nfacilities; i++) {
        facility_free(base->facilities[i]);
    }
    if (base->facilities) free(base->facilities);
    free(base);
}

void base_add_facility(base_t* base, void* facility) {
    base->facilities = realloc(base->facilities, sizeof(void*) * (base->nfacilities + 1));
    base->facilities[base->nfacilities] = facility;
    base->nfacilities++;
}

void base_handle_b(base_t* base) {/*affiche la base, son nom, son année de construction, le mois, le jour, et le pays*/
    printf("%s (%04d-%02d-%02d, %s)\n", base->name, base->year, base->month, base->day, base->country);
}

void base_handle_c(base_t* base) {/*affiche le pays de la base*/
    printf("%s\n", base->country);
}

void base_handle_d(base_t* base) {/*affiche l'année le mois et jour */
    printf("%04d-%02d-%02d\n", base->year, base->month, base->day);
}

void base_handle_f(base_t* base) {
    for (int i = 0; i < base->nfacilities; i++) {
        facility_handle_f(base->facilities[i]);
    }
}

/*void base_handle_fc(base_t* base, double cost) {
    for (int i = 0; i < base->nfacilities; i++) {
        facility_handle_fc(base->facilities[i], cost);
    }
}*/

void base_handle_fcge(base_t* base, double cost) {
    for (int i = 0; i < base->nfacilities; i++) {
        facility_handle_fcge(base->facilities[i], cost);
    }
}

void base_handle_fcgt(base_t* base, double cost) {
    for (int i = 0; i < base->nfacilities; i++) {
        facility_handle_fcgt(base->facilities[i], cost);
    }
}

void base_handle_fcle(base_t* base, double cost) {
    for (int i = 0; i < base->nfacilities; i++) {
        facility_handle_fcle(base->facilities[i], cost);
    }
}

void base_handle_fclt(base_t* base, double cost) {
    for (int i = 0; i < base->nfacilities; i++) {
        facility_handle_fclt(base->facilities[i], cost);
    }
}

void base_handle_fn(base_t* base, char* name) {
    for (int i = 0; i < base->nfacilities; i++) {
        facility_handle_fn(base->facilities[i], name);
    }
}

void base_handle_n(base_t* base) {
    printf("%s\n", base->name);
}

void base_handle_t(base_t* base) {
    double total = 0.0;
    for (int i = 0; i < base->nfacilities; i++) {
        total += ((facility_t*)base->facilities[i])->cost;
    }
    printf("%.2f USD\n", total);
}