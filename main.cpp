#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include "pilhaLigada.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    //Vari�veis
    Pilha<char> p;
    string exp; //Expressao
    unsigned tam; //Tamanho
    unsigned i;
    bool valido;
    char s; //S�mbolo
    int opc;

    do{
        cout<< "\n\n\t  //                        \\\\" <<endl;
            cout<< "\t //  AN�LISE  DA  EXPRESS�O  \\\\" <<endl;
            cout<< "\t//                            \\\\" <<endl;
        cout<< "\n\t     1  -  Nova Express�o" <<endl;
        cout<< "\t     9  -  Fim\n" <<endl;
        cout<< "\t     Selecione: ";
        cin>> opc;
        cin.ignore();

        switch(opc){
            //Conferir a Express�o
            case 1:
                system("cls");
                cout<< "\n\n\t  //                        \\\\" <<endl;
                    cout<< "\t //  AN�LISE  DA  EXPRESS�O  \\\\" <<endl;
                    cout<< "\t//                            \\\\" <<endl;
                cout<<"\n\t  Express�o: ";
                getline(cin, exp); //Se utilizar s� o cin, a express�o vai ser truncada (n�o consider� o que estiver depois de um espa�o)

                tam = exp.size(); //Comprimento da Express�o
                i = 0;
                valido = true;

                while(i < tam){
                    s = exp.at(i); //Significa "s = expressa[i]" se fosse um vetor, por exemplo

                    if(s == '{' || s == '[' || s == '('){
                        p.empilhar(s);
                    }
                    else{
                        if(s == '}' || s == ']' || s == ')'){
                            if(p.pilhaVazia()){
                                valido = false;
                            }
                            else{
                                if(s == '}' && p.elementoTopo() == '{'){
                                    p.desempilhar();
                                }
                                else{
                                    if(s == ']' && p.elementoTopo() == '['){
                                        p.desempilhar();
                                    }
                                    else{
                                        if(s == ')' && p.elementoTopo() == '('){
                                            p.desempilhar();
                                        }
                                    }
                                }
                            }
                        }
                    }

                    i++;
                }
                //Se todo caracter inserido na Pilha foi desempilhado e valido for true
                if(p.pilhaVazia() && valido){
                    cout<< "\n\n\t \\\\    Express�o Correta!    //";
                }
                else{
                    cout<< "\n\n\t \\\\   Express�o Incorreta!   //";
                }
                while(!p.pilhaVazia()){
                    p.desempilhar();
                }
                break;

            //Sair do Programa
            case 9:
                cout<< "\n\t \\\\  Fim...................  //\n\n\n";
                return 0;
                break;

            //Se for digitado outro N�mero
            default:
                system("cls");
                continue;
                break;
        }
        cout<< "\n\n\n";
        system("pause");
        system("cls");
    }while(opc != 9);
}
