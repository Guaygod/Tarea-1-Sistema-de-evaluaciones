#ifndef MENU_H
#define MENU_H

#include "BancoPreguntas.h"
#include <string>

using namespace std;

class Menu {
private:
    BancoPreguntas& banco;
    bool leerEntradaEntera(int& valor) const;
    string leerEntradaTexto() const;

public:
    Menu(BancoPreguntas& banco);
    void mostrar();
};

#endif