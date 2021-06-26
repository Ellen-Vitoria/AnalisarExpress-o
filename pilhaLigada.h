#ifndef PILHALIGADA_H_INCLUDED
#define PILHALIGADA_H_INCLUDED

template <typename Tipo>

struct Node{
    Tipo info;
    Node<Tipo> *prox; //Ponteiro para Nó, do tipo Tipo
};

template <typename Tipo> //É preciso declarar template para quando for usado tanto em Struct quanto na Classe

class Pilha{
private:
    Node<Tipo> *topo; //Ponteiro para uma variável do tipo Node

public:
    //Função inicializadora; estado inicial
    Pilha(){
        topo = NULL;
    }

    bool empilhar(Tipo x){
        bool v = true;
        Node<Tipo> *aux = new Node<Tipo>; //1º Passo: Alocar espaço de Memória

        //No caso de não conseguir Alocar
        if(aux == NULL)
        {
            v = false;
        }
        else
        {
            aux->info = x; //2º Passo: Guardar informação; ->: Operador de referência
            aux->prox = topo; //3º Passo: o Prox de Auxiliar receberá conteúdo do Topo, que no momento inicial é NULL
            topo = aux; //4º Passo: o Topo receberá o conteúdo (a informação) de Auxiliar
        }
        return v;
    }

    Tipo desempilhar(){
        Tipo temp = topo->info; //Elemento do Topo para mostrar, depois, que elemento foi desempilhado

        Node<Tipo> *aux = topo; //1º Passo: Aux apontará para onde o Topo está apontando
        topo = topo->prox; //2º Passo: Topo passa a apontar para onde o Prox está apontando, podendo ser um novo Elemento (empilhado anteriormente) ou o NULL
        delete aux; //3º Passo: Liberando espaço, para não ficar perdido na Memória

        return temp;
    }

    Tipo elementoTopo(){
        return topo->info;
    }

    bool pilhaVazia(){
        return topo == NULL;
    }

    //Retornar a referência do Topo
    Node<Tipo> *getTopo(){
        return topo;
    }
};

#endif // PILHALIGADA_H_INCLUDED
