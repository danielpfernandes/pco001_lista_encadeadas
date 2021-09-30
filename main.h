//
// Created by Daniel Paiva Fernandes on 29/09/2021.
//

#ifndef PCO001_LISTA_ENCADEADA_MAIN_H
#define PCO001_LISTA_ENCADEADA_MAIN_H

#include <iostream>
#include <cstring>
#include <utility>

using namespace std;

int contador = 0;

typedef struct TipoListaEncadeada
{
    string item;
    int contador{};
    TipoListaEncadeada *proximo{};
} TipoListaEncadeada;

void imprimeLista(TipoListaEncadeada *lista)
{
    cout << endl << "Elementos da lista: " << endl;
    TipoListaEncadeada *listaAuxiliar = lista;
    while (listaAuxiliar != nullptr)
    {
        cout << "Endereço: " << listaAuxiliar
             << "  Próximo: " << listaAuxiliar->proximo << " Sequência: " << listaAuxiliar->contador
             << "  Valor:   " << listaAuxiliar->item << endl;
        listaAuxiliar = listaAuxiliar->proximo;
    }
}

TipoListaEncadeada* inicializaLista()
{
    return nullptr;
}

TipoListaEncadeada* insereValor(string item, TipoListaEncadeada* lista)
{
    TipoListaEncadeada *listaAuxiliar;
    listaAuxiliar = new TipoListaEncadeada;
    listaAuxiliar->item = std::move(item);
    if (lista == nullptr)
    {
        contador = 1;
        listaAuxiliar->contador = contador;
        listaAuxiliar->proximo = nullptr;
        lista = listaAuxiliar;
    }
    else
    {
        contador++;
        listaAuxiliar->contador = contador;
        listaAuxiliar->proximo = lista;
        lista = listaAuxiliar;
    }
    return  lista;
}

void retira(TipoListaEncadeada* lista, int indice)
{
    TipoListaEncadeada *proximo = lista;
    TipoListaEncadeada *anterior;
    TipoListaEncadeada *atual = lista;
    int tam=0;

    if( atual == nullptr)
    {
        cout << "Não há alocação. " << endl;
    }

    if( atual->proximo == nullptr && indice==1)
    {
        cout << "Exclui a primeira alocação " << endl;
        delete atual;
        lista = nullptr;
    }

    while (atual != nullptr)
    {
        atual = atual->proximo;
        tam ++;
    }

    atual = lista;

    if (tam >= 2)
    {
        while (tam >indice)
        {
            anterior = atual;
            atual = atual->proximo;
            proximo = atual->proximo;
            tam--;
        }
        atual = anterior;
        atual->proximo = proximo;
    }
}

void retiraPrimeiroItem(TipoListaEncadeada* lista)
{
    retira(lista, 1);
}


void buscarValorNoIndice(TipoListaEncadeada* lista, int indice)
{
    TipoListaEncadeada *listaAuxiliar = lista;
    int tam = 0;
    bool isFound = false;

    if( listaAuxiliar == nullptr)
    {
        cout << "Não há valores nesta lista. " << endl;
    }

    if( listaAuxiliar->proximo == nullptr && indice== 1)
    {
        cout << "O valor no indice " << indice << " é " << listaAuxiliar << endl;
    }

    while (listaAuxiliar != nullptr)
    {
        listaAuxiliar = listaAuxiliar->proximo;
        tam++;

    }

    listaAuxiliar = lista;
    while (listaAuxiliar != nullptr)
    {
        if ( listaAuxiliar->contador == indice)
        {
            isFound=true;
            break;
        }

        listaAuxiliar = listaAuxiliar->proximo;
    }

    if (isFound)
    {
        cout << "O valor no indice " << indice << " é " << listaAuxiliar->item << endl;
    }
}


TipoListaEncadeada* concatenarLista(TipoListaEncadeada* primeiraLista, TipoListaEncadeada* segundaLista)
{
    TipoListaEncadeada *segundaListaAuxiliar = segundaLista;

    TipoListaEncadeada *primeiraListaAuxiliar = primeiraLista;

    while (primeiraListaAuxiliar->proximo != nullptr)
    {
        primeiraListaAuxiliar = primeiraListaAuxiliar->proximo;
    }
    primeiraListaAuxiliar->proximo = segundaListaAuxiliar;

    return primeiraLista;
}

void dividirListas(TipoListaEncadeada* listaOriginal, TipoListaEncadeada** novaLista)
{
    TipoListaEncadeada *aux1, *aux2;
    if(listaOriginal->proximo==nullptr) /*only one element*/
        return;

    aux1= aux2=listaOriginal;

    while(aux2->proximo != nullptr && aux2->proximo->proximo != nullptr)
    {
        aux1 = aux1->proximo;
        aux2 = aux2->proximo->proximo;
    }
    *novaLista = aux1->proximo;
    aux1->proximo = nullptr;
}

TipoListaEncadeada* copiarLista(TipoListaEncadeada* listaOriginal)
{
    struct TipoListaEncadeada* atual = listaOriginal;
    struct TipoListaEncadeada* novaLista = nullptr;
    struct TipoListaEncadeada* ultima = nullptr;

    while (atual != nullptr)
    {
        // special case for the first new node
        if (novaLista == nullptr)
        {
            novaLista = (struct TipoListaEncadeada*)malloc(sizeof(struct TipoListaEncadeada));
            novaLista->item = atual->item;
            novaLista->proximo = nullptr;
            ultima = novaLista;
        }
        else {
            ultima->proximo = (struct TipoListaEncadeada *)malloc(sizeof(struct TipoListaEncadeada));
            ultima = ultima->proximo;
            ultima->item = atual->item;
            ultima->proximo = nullptr;
        }
        atual = atual->proximo;
    }

    return novaLista;
}

struct TipoListaEncadeada * troca(struct TipoListaEncadeada * ptr1, struct TipoListaEncadeada * ptr2)
{
    struct TipoListaEncadeada * tmp = ptr2->proximo;
    ptr2->proximo = ptr1;
    ptr1->proximo = tmp;
    return ptr2;
}

void ordenaLista(TipoListaEncadeada** lista)
{
    struct TipoListaEncadeada** h;
    struct TipoListaEncadeada* aux = *lista;
    int i, j, tam = 0;
    bool trocado;

    while (aux != nullptr)
    {
        aux = aux->proximo;
        tam ++;
    }

    for (i = 0; i <= tam; i++)
    {
        h = lista;
        trocado = false;

        for (j = 0; j < tam - i - 1; j++)
        {

            struct TipoListaEncadeada * p1 = *h;
            struct TipoListaEncadeada * p2 = p1->proximo;

            if (strcmp(p1->item.data(), p2->item.data()) > 0 )
            {
                /* update the link after swapping */
                *h = troca(p1, p2);
                trocado = true;
            }

            h = &(*h)->proximo;
        }

        /* break if the loop ended without any swap */
        if (!trocado)
            break;
    }
}

void buscarOcorrenciaDeValor(TipoListaEncadeada* lista, const string& valorBuscado)
{
    int ocorrencia = 0;

    TipoListaEncadeada* atual = lista; // Initialize atual
    while (atual != nullptr)
    {
        if (atual->item == valorBuscado)
        {
            ocorrencia++;
        }
        atual = atual->proximo;
    }
    cout << to_string(ocorrencia) + " ocorrências do termo pesquisado" << endl;
}

#endif //PCO001_LISTA_ENCADEADA_MAIN_H