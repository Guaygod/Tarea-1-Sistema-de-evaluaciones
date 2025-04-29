#ifndef PREGUNTA_H
#define PREGUNTA_H

#include <string>

using namespace std;

class Pregunta {
private:
    string enunciado;
    string nivel;
    int tiempo;
    bool usadaAntes;

    bool esTiempoValido(int tiempo) const;

public:
    Pregunta();
    Pregunta(const string& enunciado, const string& nivel, int tiempo);

    string getEnunciado() const;
    string getNivel() const;
    int getTiempo() const;
    bool isUsadaAntes() const;

    bool setEnunciado(const string& enunciado);
    bool setNivel(const string& nivel);
    bool setTiempo(int tiempo);
    bool marcarUsada();

    string toString(int indice) const;
};

#endif
