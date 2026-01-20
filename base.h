#ifndef BASE_H
#define BASE_H
#include "facility.h"


typedef struct{
    char *country; /**< The base location (country). */
    int day; /**< The base date (day). */
    facility_t **facilities; /**< The base facilities. */
    int month; /**< The base date (month). */
    char *name; /**< The base name. */
    int nfacilities; /**< The base number of facilities. */
    int year; /**< The base date (year). */
} base_t;

void base_free(base_t* base);
void base_add_facility(base_t* base, void* facility);
void base_handle_b(base_t* base); 
void base_handle_c(base_t* base);
void base_handle_d(base_t* base);
void base_handle_f(base_t* base);/*récupéré dans facility.c*/
void base_handle_fc(base_t* base, double cost);/*récupéré dans facility.c*/
void base_handle_fcge(base_t* base, double cost);/*récupéré dans facility.c*/
void base_handle_fcgt(base_t* base, double cost);/*récupéré dans facility.c*/
void base_handle_fcle(base_t* base, double cost);/*récupéré dans facility.c*/
void base_handle_fn(base_t* base, char* name);/*récupéré dans facility.c*/
void base_handle_n(base_t* base);
void base_handle_t(base_t* base);

#endif