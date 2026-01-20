#ifndef FACILITY_H
#define FACILITY_H

typedef struct {
    int area;
    double cost;
    char* name;
} facility_t;

facility_t* facility_create();
void facility_free(facility_t* facility);
void facility_handle_f(facility_t* facility);
void facility_handle_fc(facility_t* facility, double cost);
void facility_handle_fcge(facility_t* facility, double cost);
void facility_handle_fcgt(facility_t* facility, double cost);
void facility_handle_fcle(facility_t* facility, double cost);
void facility_handle_fclt(facility_t* facility, double cost);
void facility_handle_fn(facility_t* facility, char* name);

#endif