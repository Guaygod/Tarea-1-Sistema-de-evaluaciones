#include "Menu.h"
#include "BancoPreguntas.h"

using namespace std;

int main() {
    BancoPreguntas banco;
    Menu menu(banco);
    menu.mostrar();
    return 0;
}