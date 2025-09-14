#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};
NO* atual = NULL;
NO* anterior = NULL;
NO* ultimo = NULL;
NO* primeiro = NULL;

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
	atual = primeiro;
	anterior = NULL;

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

		while (atual != NULL && atual->valor < novo->valor)
		{
			anterior = atual;
			atual = atual->prox;
		
		}	
			//ELEMENTO JA EXISTE??
		if (atual != NULL && atual->valor == novo->valor)
			{
			cout << "JA TEM" << endl;
				free(novo);
			}
		if (anterior == NULL) {
			primeiro = novo;
		}
		else {
			anterior->prox = novo;
		}
		novo->prox = atual;
		}
		
		
	


void excluirElemento()
{
	int numero;
	cout << "O QUE TU QUER TIRAR?\n";
	cin >> numero;
	atual = primeiro;
	while (atual != NULL && atual->valor < numero)
	{
		anterior = atual;
		atual = atual->prox;
	}
	if (numero < atual->valor) {
		cout << "NEM TEM";
		return;
	}
	if (atual->valor == numero) {

		if (atual->valor == primeiro->valor) {
			primeiro = atual->prox;
			free(atual);
			cout << "APAGADO (SOM DE VITORIA DO SENNA)";
			return;

		}
		else
		{
			anterior->prox = atual->prox;
			free(atual);
			cout << "APAGADO (SOM DE VITORIA DO SENNA)";
			return;
		
		}

	
	}	
	
}

void buscarElemento()
{
	int numero;
	cout << "BUSCA O NUMERO VAI:\n";
	cin >> numero;
	while (atual != NULL && atual->valor < numero)
	{
		anterior = atual;
		atual = atual->prox;
	}
	if (atual->valor == numero)
	{
		cout << "OLHA Q LEGAL, O NUMERO TA AI\n";
	}else if(atual->valor > numero)
	{
		cout << "QUE PENA, O NUMERO N EXISTE :(\n";
	}

	
}

NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	anterior = primeiro;
	while (aux != NULL && aux->valor < numero) {
		if (aux->valor == numero) {
			return aux;
			return anterior;
		}
		anterior = aux;
		aux = aux->prox;
	}
	return NULL;
}