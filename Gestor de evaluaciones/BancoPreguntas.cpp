#include "BancoPreguntas.h"
#include <vector>
#include <string>

using namespace std;

BancoPreguntas::BancoPreguntas() {}

bool BancoPreguntas::agregarPregunta(const string& enunciado, const string& nivel, int tiempo) {
    Pregunta nueva(enunciado, nivel, tiempo);
    if (nueva.getEnunciado().empty() || nueva.getNivel().empty() || nueva.getTiempo() <= 0) {
        return false;
    }
    preguntas.emplace_back(enunciado, nivel, tiempo);
    return true;
}

string BancoPreguntas::listarPreguntas() const {
    if (preguntas.empty()) {
        return "No hay preguntas registradas.\n";
    }
    string result;
    for (size_t i = 0; i < preguntas.size(); ++i) {
        result += preguntas[i].toString(i + 1);
    }
    return result;
}

bool BancoPreguntas::actualizarPregunta(int indice, const string& enunciado, const string& nivel, int tiempo) {
    if (indice < 1 || indice > static_cast<int>(preguntas.size())) {
        return false;
    }
    Pregunta& p = preguntas[indice - 1];
    return p.setEnunciado(enunciado) && p.setNivel(nivel) && p.setTiempo(tiempo);
}

bool BancoPreguntas::eliminarPregunta(int indice) {
    if (indice < 1 || indice > static_cast<int>(preguntas.size())) {
        return false;
    }
    preguntas.erase(preguntas.begin() + (indice - 1));
    return true;
}

bool BancoPreguntas::marcarPreguntaUsada(int indice) {
    if (indice < 1 || indice > static_cast<int>(preguntas.size())) {
        return false;
    }
    return preguntas[indice - 1].marcarUsada();
}

string BancoPreguntas::generarEvaluacion(const string& nivelBuscado, int cantidad) const {
    if (cantidad <= 0) {
        return "Cantidad inválida.\n";
    }
    string result = "\n--- Evaluación generada ---\n";
    int contador = 0;
    int tiempoTotal = 0;

    for (size_t i = 0; i < preguntas.size() && contador < cantidad; ++i) {
        if (preguntas[i].getNivel() == nivelBuscado && !preguntas[i].isUsadaAntes()) {
            result += "[" + to_string(contador + 1) + "] " + preguntas[i].getEnunciado() + "\n";
            result += "   Tiempo: " + to_string(preguntas[i].getTiempo()) + " min\n";
            result += "--------------------------\n";
            tiempoTotal += preguntas[i].getTiempo();
            contador++;
        }
    }

    if (contador == 0) {
        result += "No se encontraron preguntas con ese nivel.\n";
    } else {
        result += "Tiempo total estimado: " + to_string(tiempoTotal) + " minutos\n";
    }
    return result;
}

size_t BancoPreguntas::getCantidadPreguntas() const {
    return preguntas.size();
}