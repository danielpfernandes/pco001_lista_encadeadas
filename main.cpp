//
// Created by Daniel Paiva Fernandes on 23/09/2021.
//
#include "main.h"

int main()
{
    TipoListaEncadeada *primeiraLista;
    TipoListaEncadeada *segundaLista;

    cout << "01. Criação da estrutura de dados vazia" << endl;
    primeiraLista = inicializaLista();
    segundaLista = inicializaLista();
    imprimeLista(primeiraLista);
    imprimeLista(segundaLista);
    cout << "Enter para continuar..."; cin.get();

    cout << endl << "02. Inserir um novo item imediatamente após o i-ésimo item" << endl;
    primeiraLista = insereValor("banana", primeiraLista);
    primeiraLista = insereValor("laranja", primeiraLista);
    primeiraLista = insereValor("manga", primeiraLista);
    primeiraLista = insereValor("morango", primeiraLista);
    primeiraLista = insereValor("uva", primeiraLista);
    segundaLista = insereValor("batata", segundaLista);
    segundaLista = insereValor("cebola", segundaLista);
    segundaLista = insereValor("vagem", segundaLista);
    segundaLista = insereValor("cenoura", segundaLista);
    segundaLista = insereValor("beterraba", segundaLista);
    segundaLista = insereValor("tomate", segundaLista);
    imprimeLista(primeiraLista);
    imprimeLista(segundaLista);
    cout << "Enter para continuar..."; cin.get();

    cout << endl <<  "03. Retirar o primeiro item" << endl;
    retiraPrimeiroItem(primeiraLista);
    retiraPrimeiroItem(segundaLista);
    imprimeLista(primeiraLista);
    imprimeLista(segundaLista);
    cout << "Enter para continuar..."; cin.get();

    cout << endl << "04. Retirar o i-ésimo item" << endl;
    retira(primeiraLista, 2);
    retira(segundaLista, 3);
    imprimeLista(primeiraLista);
    imprimeLista(segundaLista);
    cout << "Enter para continuar..."; cin.get();

    cout << endl <<  "05. Localizar um item na Lista" << endl;
    buscarValorNoIndice(primeiraLista, 2);
    buscarValorNoIndice(primeiraLista, 4);
    buscarValorNoIndice(segundaLista, 6);
    buscarValorNoIndice(segundaLista, 5);
    cout << "Enter para continuar..."; cin.get();

    cout << endl << "06. Combinar duas ou mais estruturas em uma" << endl;
    TipoListaEncadeada* novaLista;
    novaLista = concatenarLista(segundaLista, primeiraLista);
    imprimeLista(novaLista);
    cout << "Enter para continuar..."; cin.get();

    cout << endl << "07. Partir uma estrutura em duas ou mais" << endl;
    auto novaListaDireita = new TipoListaEncadeada;
    dividirListas(novaLista, &novaListaDireita);
    imprimeLista(novaLista);
    imprimeLista(novaListaDireita);
    cout << "Enter para continuar..."; cin.get();

    cout << endl << "08. Fazer uma cópia" << endl;
    TipoListaEncadeada* listaCopiada = copiarLista(novaLista);
    imprimeLista(listaCopiada);
    cout << "Enter para continuar..."; cin.get();

    cout << endl << "09. Ordenar os itens da estrutura" << endl;
    ordenaLista(&novaLista);
    imprimeLista(novaLista);
    cout << "Enter para continuar..."; cin.get();

    cout << endl << "10. Buscar a ocorrência de um valor particular" << endl;
    novaLista = insereValor("cebola", novaLista);
    imprimeLista(novaLista);
    buscarOcorrenciaDeValor(novaLista, "cebola");
    cout << "Enter para continuar..."; cin.get();
}
