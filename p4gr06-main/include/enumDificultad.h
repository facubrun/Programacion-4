#ifndef ENUMDIFICULTAD
#define ENUMDIFICULTAD

enum enumDificultad {Principiante, Intermedio, Avanzado};

struct nombreDificultad {
  const enumDificultad enum_dif;
  const char *nombre_enum;
};

const nombreDificultad noms[] = {
    {Principiante, "Principiante"},
    {Intermedio, "Intermedio"},
    {Avanzado, "Avanzado"}
}; 

#endif