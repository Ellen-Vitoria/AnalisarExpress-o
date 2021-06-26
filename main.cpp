#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include "pilhaLigada.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    //Variáveis
    Pilha<char> p;
    string exp; //Expressao
    unsigned tam; //Tamanho
    unsigned i;
    bool valido;
    char s; //Símbolo
    int opc;

    do{
        cout<< "\n\n\t  //                        \\\\" <<endl;
            cout<< "\t //  ANÁLISE  DA  EXPRESSÃO  \\\\" <<endl;
            cout<< "\t//                            \\\\" <<endl;
        cout<< "\n\t     1  -  Nova Expressão" <<endl;
        cout<< "\t     9  -  Fim\n" <<endl;
        cout<< "\t     Selecione: ";
        cin>> opc;
        cin.ignore();

        switch(opc){
            //Conferir a Expressão
            case 1:
                system("cls");
                cout<< "\n\n\t  //                        \\\\" <<endl;
                    cout<< "\t //  ANÁLISE  DA  EXPRESSÃO  \\\\" <<endl;
                    cout<< "\t//                            \\\\" <<endl;
                cout<<"\n\t  Expressão: ";
                getline(cin, exp); //Se utilizar só o cin, a expressão vai ser truncada (não considerá o que estiver depois de um espaço)

                tam = exp.size(); //Comprimento da Expressão
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
                    cout<< "\n\n\t \\\\    Expressão Correta!    //";
                }
                else{
                    cout<< "\n\n\t \\\\   Expressão Incorreta!   //";
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

            //Se for digitado outro Número
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
