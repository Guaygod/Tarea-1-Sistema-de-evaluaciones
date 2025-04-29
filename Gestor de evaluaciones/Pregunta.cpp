#include "Pregunta.h"
#include <string>

using namespace std;

bool Pregunta::esTiempoValido(int tiempo) const {
    return tiempo > 0;
}

Pregunta::Pregunta() : tiempo(0), usadaAntes(false) {}

Pregunta::Pregunta(const string& enunciado, const string& nivel, int tiempo)
    : enunciado(enunciado), nivel(nivel), tiempo(tiempo), usadaAntes(false) {}

string Pregunta::getEnunciado() const { return enunciado; }
string Pregunta::getNivel() const { return nivel; }
int Pregunta::getTiempo() const { return tiempo; }
bool Pregunta::isUsadaAntes() const { return usadaAntes; }

bool Pregunta::setEnunciado(const string& enunciado) {
    if (enunciado.empty()) return false;
    this->enunciado = enunciado;
    return true;
}

bool Pregunta::setNivel(const string& nivel) {
    if (nivel.empty()) return false;
    this->nivel = nivel;
    return true;
}

bool Pregunta::setTiempo(int tiempo) {
    if (!esTiempoValido(tiempo)) return false;
    this->tiempo = tiempo;
    return true;
}

bool Pregunta::marcarUsada() {
    if (usadaAntes) return false;
    usadaAntes = true;
    return true;
}

string Pregunta::toString(int indice) const {
    string result = "[" + to_string(indice) + "] Enunciado: " + enunciado + "\n";
    result += "   Nivel: " + nivel + "\n";
    result += "   Tiempo: " + to_string(tiempo) + " min\n";
    result += "   Usada antes: " + string(usadaAntes ? "Sí" : "No") + "\n";
    result += "------------------------\n";
    return result;
}