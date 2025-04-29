#include "Menu.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

Menu::Menu(BancoPreguntas& banco) : banco(banco) {}

bool Menu::leerEntradaEntera(int& valor) const {
    if (!(cin >> valor)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return true;
}

string Menu::leerEntradaTexto() const {
    string texto;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, texto);
    return texto;
}

void Menu::mostrar() {
    int opcion;
    do {
        cout << "\n--- Menú del Sistema de Evaluación ---\n";
        cout << "1. Agregar pregunta\n";
        cout << "2. Listar preguntas\n";
        cout << "3. Actualizar pregunta\n";
        cout << "4. Eliminar pregunta\n";
        cout << "5. Generar evaluación\n";
        cout << "6. Marcar como usada\n";
        cout << "0. Salir\n";
        cout << "Opción: ";

        if (!leerEntradaEntera(opcion)) {
            cout << "Entrada inválida.\n";
            continue;
        }

        switch (opcion) {
        case 1: {
            cout << "Ingrese enunciado: ";
            string enunciado = leerEntradaTexto();
            cout << "Ingrese nivel de la taxonomía: ";
            string nivel = leerEntradaTexto();
            cout << "Ingrese tiempo estimado (minutos): ";
            int tiempo;
            if (!leerEntradaEntera(tiempo)) {
                cout << "Tiempo inválido.\n";
                break;
            }
            if (banco.agregarPregunta(enunciado, nivel, tiempo)) {
                cout << "Pregunta agregada.\n";
            } else {
                cout << "Error al agregar pregunta.\n";
            }
            break;
        }
        case 2: {
            cout << banco.listarPreguntas();
            break;
        }
        case 3: {
            cout << banco.listarPreguntas();
            cout << "Ingrese número de pregunta a actualizar: ";
            int idx;
            if (!leerEntradaEntera(idx)) {
                cout << "Índice inválido.\n";
                break;
            }
            cout << "Nuevo enunciado: ";
            string enunciado = leerEntradaTexto();
            cout << "Nuevo nivel: ";
            string nivel = leerEntradaTexto();
            cout << "Nuevo tiempo (minutos): ";
            int tiempo;
            if (!leerEntradaEntera(tiempo)) {
                cout << "Tiempo inválido.\n";
                break;
            }
            if (banco.actualizarPregunta(idx, enunciado, nivel, tiempo)) {
                cout << "Pregunta actualizada.\n";
            } else {
                cout << "Error al actualizar pregunta.\n";
            }
            break;
        }
        case 4: {
            cout << banco.listarPreguntas();
            cout << "Ingrese número de pregunta a eliminar: ";
            int idx;
            if (!leerEntradaEntera(idx)) {
                cout << "Índice inválido.\n";
                break;
            }
            if (banco.eliminarPregunta(idx)) {
                cout << "Pregunta eliminada.\n";
            } else {
                cout << "Error al eliminar pregunta.\n";
            }
            break;
        }
        case 5: {
            cout << "Ingrese nivel para la evaluación: ";
            string nivel = leerEntradaTexto();
            cout << "Ingrese cantidad de preguntas: ";
            int cantidad;
            if (!leerEntradaEntera(cantidad)) {
                cout << "Cantidad inválida.\n";
                break;
            }
            cout << banco.generarEvaluacion(nivel, cantidad);
            break;
        }
        case 6: {
            cout << banco.listarPreguntas();
            cout << "Ingrese número de pregunta usada antes: ";
            int idx;
            if (!leerEntradaEntera(idx)) {
                cout << "Índice inválido.\n";
                break;
            }
            if (banco.marcarPreguntaUsada(idx)) {
                cout << "Pregunta marcada como usada.\n";
            } else {
                cout << "Error al marcar pregunta.\n";
            }
            break;
        }
        case 0:
            cout << "Saliendo del programa.\n";
            break;
        default:
            cout << "Opción inválida.\n";
        }
    } while (opcion != 0);
}