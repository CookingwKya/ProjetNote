#include "facility.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

facility_t* facility_create() { /*créer une facilité*/
    facility_t* facility = malloc(sizeof(facility_t));
    facility->name = NULL;
    facility->area = 0;
    facility->cost = 0.0;
    return facility;
}

void facility_free(facility_t* facility) { /*free après allocation mémoire*/
    if (facility->name) free(facility->name);
    free(facility);
}

void facility_handle_f(facility_t* facility) { /*affichage de la facilité, et de ses caractéristiques*/
    printf("%s, %d m2, %.2f USD\n", facility->name, facility->area, facility->cost);
}

void facility_handle_facility_cost(facility_t* facility, double cost) {/*affiche toutes les facilités ayant des coûts égaux à cost*/
    if (facility->cost == cost) {
        facility_handle_f(facility);
    }
}

void facility_handle_fcge(facility_t* facility, double cost) { /*affiche les facilités ayant un coût supérieur ou égal à cost*/
    if (facility->cost >= cost) {
        facility_handle_f(facility);
    }
}

void facility_handle_fcgt(facility_t* facility, double cost) {/*affiche les facilités ayant un coût supérieur à cost*/
    if (facility->cost > cost) {
        facility_handle_f(facility);
    }
}

void facility_handle_fcle(facility_t* facility, double cost) {/*affiche les facilités ayant un coût inférieur ou égal à cost*/
    if (facility->cost <= cost) {
        facility_handle_f(facility);
    }
}

void facility_handle_fclt(facility_t* facility, double cost) {/*affiche les facilités ayant un coût inférieur à cost*/
    if (facility->cost < cost) {
        facility_handle_f(facility);
    }
}

void facility_handle_fn(facility_t* facility, char* name) {/*affiche les bases ayant NAME inclut dans leur nom ou pour nom*/
    if (strstr(facility->name, name)) {
        facility_handle_f(facility);
    }
}