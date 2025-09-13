#include <iostream>
using namespace std;

// defini��o de tipo
struct NO {
    int valor;
    NO* ant;
    NO* prox;

};

NO* primeiro = NULL;
NO* ultimo = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------



int main()
{
    menu();
}

void menu()
{
    int op = 0;
    while (op != 7) {
        system("cls"); // somente no windows
        cout << "Menu Lista Ligada";
        cout << endl << endl;
        cout << "1 - Inicializar Lista \n";
        cout << "2 - Exibir quantidade de elementos \n";
        cout << "3 - Exibir elementos \n";
        cout << "4 - Buscar elemento \n";
        cout << "5 - Inserir elemento \n";
        cout << "6 - Excluir elemento \n";
        cout << "7 - Sair \n\n";

        cout << "Opcao: ";
        cin >> op;

        switch (op)
        {
        case 1: inicializar();
            break;
        case 2: exibirQuantidadeElementos();
            break;
        case 3: exibirElementos();
            break;
        case 4: buscarElemento();
            break;
        case 5: inserirElemento();
            break;
        case 6: excluirElemento();
            break;

        case 7:
            return;
        default:
            break;
        }

        system("pause"); // somente no windows
    }
}

void inicializar()
{

    // se a lista j� possuir elementos
    // libera a memoria ocupada
    NO* aux = primeiro;
    while (aux != NULL) {
        NO* paraExcluir = aux;
        aux = aux->prox;
        free(paraExcluir);
    }

    primeiro = NULL;
    ultimo = NULL;
    cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

    int nElementos = 0;
    NO* aux = primeiro;
    while (aux != NULL) {
        nElementos++;
        aux = aux->prox;
    }
    cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
    if (primeiro == NULL) {
        cout << "Lista vazia \n";
        return;
    }
    else {
        cout << "Elementos: \n";
        NO* aux = primeiro;
        while (aux != NULL) {
            cout << aux->valor << endl;
            aux = aux->prox;
            
        }    
    }
}

void inserirElemento()
{
    // aloca memoria dinamicamente para o novo elemento
    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL)
    {
        return;
    }

    cout << "Digite o elemento: ";
    cin >> novo->valor;
    novo->prox = NULL;
    novo->ant = NULL;


    if (primeiro == NULL)
    {
        ultimo = novo;
        primeiro = novo;
    }
    else if (posicaoElemento(novo->valor) != NULL) {
        cout << "O numero ja existe" << endl;
        return;
    }
    else
    {
        ultimo->prox = novo;
        ultimo = novo;
    
    }
}

void excluirElemento()
{
    int  val;
    cout << "Digite o valor a ser excluido: ";
    cin >> val;
    NO* apaga = posicaoElemento(val);
    if (apaga->valor == NULL) {
        cout << "Primeiramente q isso nem existe \n";
        return;
    }
    if (primeiro->valor == val) {
        primeiro = primeiro->prox;
        free(apaga);
        cout << "Pronto\n";
        return;
    }
    else if (apaga->valor == ultimo->valor) {
        ultimo = ultimo->ant;
        ultimo->prox = NULL;
        free(apaga);
        return;
    }
    else {
        apaga->ant->prox = apaga->prox;
        apaga->prox->ant = apaga->ant;
        free(apaga);
            cout << "mata meio\n";
            return;
    }
}


void buscarElemento()
{
    int b;
    cout << "Digite o numero a ser buscado: ";
    cin >> b;

    NO* elemento = posicaoElemento(b);
    if (elemento != NULL  ) {

    }
    else {
        cout << "nem tem esse numero" << endl;
    }
}



// retorna um ponteiro para o elemento buscado
// ou NULL se o elemento n�o estiver na lista
NO* posicaoElemento(int numero)
{
    NO* aux = primeiro;
    aux->ant = primeiro;
    while (aux != NULL) {
        if (aux->valor == numero) {
            return aux;
        }
        aux->ant = aux;
        aux = aux->prox;
    }
    return NULL;
}