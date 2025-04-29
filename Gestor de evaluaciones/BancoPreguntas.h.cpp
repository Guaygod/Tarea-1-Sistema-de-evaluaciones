#ifndef BANCO_PREGUNTAS_H
#define BANCO_PREGUNTAS_H

#include <vector>
#include <string>
#include "Pregunta.h"

using namespace std;

class BancoPreguntas {
private:
    vector<Pregunta> preguntas;

public:
    BancoPreguntas();

    bool agregarPregunta(const string& enunciado, const string& nivel, int tiempo);
    string listarPreguntas() const;
    bool actualizarPregunta(int indice, const string& enunciado, const string& nivel, int tiempo);
    bool eliminarPregunta(int indice);
    bool marcarPreguntaUsada(int indice);
    string generarEvaluacion(const string& nivelBuscado, int cantidad) const;

    size_t getCantidadPreguntas() const;
};

#endif