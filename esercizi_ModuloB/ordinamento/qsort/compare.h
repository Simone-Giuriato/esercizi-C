// Ci sono due diversi modi per gestire void*
// in compare_float si lavora direttamente con variabili float (cast del puntatore e dereferenziazione)
// in compare_float_p si lavora con float* (solo cast da void* a float*)
int compare_float(const void* a, const void* b);
int compare_float_p(const void* a, const void* b);