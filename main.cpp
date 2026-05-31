#include<iostream>
using namespace std;

// Models

struct Categoria {
    int codigo;
    string descricao;
};

struct Cliente {
    int codigo;
    string nome;
    string telefone;
};

struct ConsumoIngredientes {
    int codigoProduto;
    int codigoIngrediente;
    float quantidade;
};

struct Garcom {
    int codigo;
    string nome;
};

struct Ingrediente {
    int codigo;
    string descricao;
    float quantEstoque;
    float estoqueMin;
    float estoqueMax;
    float precoUnitario;
};

struct ItemPedido {
    int codigoPedido;
    int codigoProduto;
    int quantidade;
};

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Pedido {
    int codigo;
    int codigoCliente;
    int codigoGarcom;
    Data data;
};

struct Produto {
    int codigo;
    string descricao;
    int codigoCategoria;
    float precoUnitario;
};

// Prototipos

// Menus

void mainMenu(
    Categoria [], int &,
    Produto [], int &,
    Ingrediente [], int &,
    Cliente [], int &,
    Garcom [], int &,
    Pedido [], int &,
    ConsumoIngredientes [], int &,
    ItemPedido [], int &
);

int menuCategoria(Categoria [], int &);

int menuProduto(Produto [], int &, ConsumoIngredientes [], int &, Ingrediente [], int);

int menuIngrediente(Ingrediente [], int &);

int menuCliente(Cliente [], int &);

int menuGarcom(Garcom [], int &);

int menuPedido(Pedido [], int &, Cliente [], int, Garcom [], int, ItemPedido [], int &, Produto [], int,
               ConsumoIngredientes [], int, Ingrediente [], int);

// Funcoes Genericas - Utils

template<typename T>
void verificarCodigo(T [], int, int);

template<typename T>
int buscaBinaria(T [], int, int);

template<typename T>
int buscaBinariaConsumoIngrediente(T [], int, int);

template<typename T>
int buscaBinariaItemPedido(T [], int, int);

// Leituras

void lerCategoria(Categoria [], int &);

void lerProduto(Produto [], int &, ConsumoIngredientes [], int &, Ingrediente [], int);

void lerConsumoIngredientes(ConsumoIngredientes [], int &, int,
                            Ingrediente [], int);

void lerIngrediente(Ingrediente [], int &);

void lerCliente(Cliente [], int &);

void lerGarcom(Garcom [], int &);

void incluirPedido(Pedido [], int &, Cliente [], int, Garcom [], int, ItemPedido [], int &, Produto [], int,
                   ConsumoIngredientes [], int, Ingrediente [], int);

void lerItemPedido(ItemPedido [], int &, Pedido [], int &, Cliente [], int, Garcom [], int);

void lerCodigosDeProdutosParaExclusao(Produto [], int &);

// Percursos

void percursoCategoria(Categoria [], int);

void percursoProduto(Produto [], int);

void percursoIngrediente(Ingrediente [], int);

void percursoCliente(Cliente [], int);

void percursoGarcom(Garcom [], int);

void percursoPedido(Pedido [], int);

// Inclusoes

void incluirNovoCliente(Cliente [], int &, Cliente [], int);

void incluirNovoGarcom(Garcom [], int &, Garcom [], int);

void incluirNovoPedido(Pedido [], int &, Pedido [], int);

int incluirNovoItemPedido(ItemPedido [], int &, int, Produto [], int, ConsumoIngredientes [], int, Ingrediente [],
                          int);

// Exclus?o

void excluirProduto(Produto [], int &, int [], int);

// Consultar

void consultarUmIngrediente(Ingrediente [], int);

void consultarIngredientesComEstoqueBaixo(Ingrediente [], int);

void consultarValorTotalArrecadadoComTodosOsPedidos(Pedido [], int, ItemPedido [],
                                                    int, Produto [], int);

int main() {
    // Mocks

    Categoria categoriaS[1000];
    int contCategoriaS = 0;
    categoriaS[0] = {1, "Bebidas"};
    categoriaS[1] = {2, "Lanches"};
    categoriaS[2] = {3, "Sobremesas"};
    contCategoriaS = 3;

    Produto produtoS[1000];
    int contProdutoS = 0;
    produtoS[0] = {1, "Refrigerante Lata", 1, 6.50};
    produtoS[1] = {2, "Suco Natural", 1, 8.00};
    produtoS[2] = {3, "X-Burguer", 2, 22.90};
    produtoS[3] = {4, "X-Salada", 2, 25.00};
    produtoS[4] = {5, "Pudim de Leite", 3, 10.00};
    contProdutoS = 5;

    Ingrediente ingredienteS[1000];
    int contIngredienteS = 0;
    ingredienteS[0] = {1, "Carne de Hamburguer", 50, 15, 100, 3.50};
    ingredienteS[1] = {2, "Pao de Hamburguer", 22, 20, 150, 1.20};
    ingredienteS[2] = {3, "Queijo Cheddar", 54, 10, 80, 2.00};
    ingredienteS[3] = {4, "Água gaseificada", 1, 10, 80, 2.00};
    ingredienteS[4] = {5, "Fruta", 14, 10, 80, 2.00};
    contIngredienteS = 5;

    ConsumoIngredientes consumoIngredientes[1000];
    int contConsumoIngredientes = 0;
    consumoIngredientes[0] = {1, 4, 1};
    consumoIngredientes[1] = {2, 5, 1};
    consumoIngredientes[2] = {3, 1, 1};
    consumoIngredientes[3] = {4, 2, 2};
    consumoIngredientes[4] = {5, 2, 2};
    contConsumoIngredientes = 5;

    Cliente clienteS[1000];
    int contClienteS = 0;
    clienteS[0] = {1, "Ana Silva", "11999990001"};
    clienteS[1] = {2, "Bruno Lima", "11999990002"};
    clienteS[2] = {3, "Carlos Souza", "11999990003"};
    clienteS[3] = {5, "Diana Rocha", "11999990004"};
    clienteS[4] = {7, "Eduardo Costa", "11999990005"};
    contClienteS = 5;

    Garcom garcomS[1000];
    int contGarcomS = 0;
    garcomS[0] = {1, "Dario"};
    garcomS[1] = {2, "Bruno Lima"};
    garcomS[2] = {3, "Carlos Souza"};
    garcomS[3] = {5, "Diana Rocha"};
    garcomS[4] = {7, "Eduardo Costa"};
    contGarcomS = 5;

    Pedido pedidoS[1000];
    int contPedidoS = 0;
    pedidoS[0] = {1, 2, 2, {15, 5, 2026}};
    pedidoS[1] = {3, 1, 5, {16, 5, 2026}};
    pedidoS[2] = {4, 3, 7, {16, 5, 2026}};
    pedidoS[3] = {5, 2, 3, {17, 5, 2026}};
    pedidoS[4] = {6, 2, 3, {17, 5, 2026}};
    contPedidoS = 5;

    ItemPedido itemPedidoS[1000];
    int contItemPedidoS = 0;
    itemPedidoS[0] = {1, 1, 2};
    itemPedidoS[1] = {3, 2, 1};
    itemPedidoS[2] = {4, 3, 2};
    itemPedidoS[3] = {5, 4, 3};
    itemPedidoS[4] = {6, 5, 2};
    contItemPedidoS = 5;

    mainMenu(
        categoriaS, contCategoriaS,
        produtoS, contProdutoS,
        ingredienteS, contIngredienteS,
        clienteS, contClienteS,
        garcomS, contGarcomS,
        pedidoS, contPedidoS,
        consumoIngredientes, contConsumoIngredientes,
        itemPedidoS, contItemPedidoS
    );
}

// Implementacoes

// Menus

void mainMenu(
    Categoria categoriaS[], int &contCategoriaS,
    Produto produtoS[], int &contProdutoS,
    Ingrediente ingredienteS[], int &contIngredienteS,
    Cliente clienteS[], int &contClienteS,
    Garcom garcomS[], int &contGarcomS,
    Pedido pedidoS[], int &contPedidoS,
    ConsumoIngredientes consumoIngredientes[], int &contConsumoIngredientes,
    ItemPedido itemPedidoS[], int &contItemPedidoS
) {
    int opt = 0;
    while (opt != -1) {
        system("clear");
        cout << "-*-*-*-*-*- Menu Principal -*-*-*-*-*-" << endl;
        cout << "|  -> 0 - Sair                       |" << endl;
        cout << "|  -> 1 - Menu de Categoria          |" << endl;
        cout << "|  -> 2 - Menu de Produto            |" << endl;
        cout << "|  -> 3 - Menu de Ingrediente        |" << endl;
        cout << "|  -> 4 - Menu de Cliente            |" << endl;
        cout << "|  -> 5 - Menu de Garcom             |" << endl;
        cout << "|  -> 6 - Menu de Pedido             |" << endl;
        cout << "-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-" << endl;
        cout << "\n   -> Escolha uma opcao: ";
        cin >> opt;

        switch (opt) {
            case 0:
                opt = -1;
                break;

            case 1:
                opt = menuCategoria(categoriaS, contCategoriaS);
                break;

            case 2:
                opt = menuProduto(produtoS, contProdutoS, consumoIngredientes, contConsumoIngredientes, ingredienteS,
                                  contIngredienteS);
                break;

            case 3:
                opt = menuIngrediente(ingredienteS, contIngredienteS);
                break;

            case 4:
                opt = menuCliente(clienteS, contClienteS);
                break;

            case 5:
                opt = menuGarcom(garcomS, contGarcomS);
                break;

            case 6:
                opt = menuPedido(pedidoS, contPedidoS, clienteS, contClienteS, garcomS, contGarcomS, itemPedidoS,
                                 contItemPedidoS, produtoS, contProdutoS, consumoIngredientes, contConsumoIngredientes,
                                 ingredienteS, contIngredienteS);
                break;

            default:
                cout << "Opcao invalida." << endl;
        }
    }
}

int menuCategoria(Categoria categoriaS[], int &contCategoriaS) {
    int opt = 0;
    while (opt != -1) {
        system("clear");
        cout << "-*-*-*-*-*- Menu Categoria -*-*-*-*-*-" << endl;
        cout << "|  -> 0 - Sair                       |" << endl;
        cout << "|  -> 1 - Voltar                     |" << endl;
        cout << "|  -> 2 - Adicionar registros        |" << endl;
        cout << "|  -> 3 - Consultar registros        |" << endl;
        cout << "-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-" << endl;
        cout << "\n   -> Escolha uma opcao: ";
        cin >> opt;

        switch (opt) {
            case 0:
                return -1;

            case 1:
                return 1;

            case 2:
                lerCategoria(categoriaS, contCategoriaS);
                break;

            case 3:
                percursoCategoria(categoriaS, contCategoriaS);
                break;

            default:
                cout << "Opcao invalida." << endl;
        }
    }
}

int menuProduto(Produto produtoS[], int &contProdutoS, ConsumoIngredientes consumoIngredientes[],
                int &contConsumoIngredientes, Ingrediente ingredienteS[], int contIngredienteS) {
    int opt = 0;
    while (opt != -1) {
        system("clear");
        cout << "-*-*-*-*-*- Menu Produto -*-*-*-*-*-" << endl;
        cout << "|  -> 0 - Sair                     |" << endl;
        cout << "|  -> 1 - Voltar                   |" << endl;
        cout << "|  -> 2 - Adicionar registros      |" << endl;
        cout << "|  -> 3 - Consultar registros      |" << endl;
        cout << "|  -> 4 - Excluir registros        |" << endl;
        cout << "-*-*-*-*-*-*-*-*----*-*-*-*-*-*-*-*-" << endl;
        cout << "\n   -> Escolha uma opcao: ";
        cin >> opt;

        switch (opt) {
            case 0:
                return -1;

            case 1:
                return 2;

            case 2:
                lerProduto(produtoS, contProdutoS, consumoIngredientes, contConsumoIngredientes, ingredienteS,
                           contIngredienteS);
                break;

            case 3:
                percursoProduto(produtoS, contProdutoS);
                break;

            case 4:
                lerCodigosDeProdutosParaExclusao(produtoS, contProdutoS);
                break;

            default:
                cout << "Opcao invalida." << endl;
        }
    }
}

int menuIngrediente(Ingrediente ingredienteS[], int &contIngredienteS) {
    int opt = 0;
    while (opt != -1) {
        system("clear");
        cout << "-*-*-*-*-*-*- Menu Ingrediente -*-*-*-*-*-*-" << endl;
        cout << "|  -> 0 - Sair                             |" << endl;
        cout << "|  -> 1 - Voltar                           |" << endl;
        cout << "|  -> 2 - Adicionar registros              |" << endl;
        cout << "|  -> 3 - Consultar registros              |" << endl;
        cout << "|  -> 4 - Consultar um registro            |" << endl;
        cout << "|  -> 5 - Exibir itens com estoque baixo   |" << endl;
        cout << "-*-*-*-*-*-*-*-*-*----*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << "\n   -> Escolha uma opcao: ";
        cin >> opt;

        switch (opt) {
            case 0:
                return -1;

            case 1:
                return 3;

            case 2:
                lerIngrediente(ingredienteS, contIngredienteS);
                break;

            case 3:
                percursoIngrediente(ingredienteS, contIngredienteS);
                break;
            case 4:
                consultarUmIngrediente(ingredienteS, contIngredienteS);
                break;
            case 5:
                consultarIngredientesComEstoqueBaixo(ingredienteS, contIngredienteS);
                break;
            default:
                cout << "Opcao invalida." << endl;
        }
    }
}

int menuCliente(Cliente clienteS[], int &contClienteS) {
    int opt = 0;
    while (opt != -1) {
        system("clear");
        cout << "-*-*-*-*-*- Menu Cliente -*-*-*-*-*-" << endl;
        cout << "|  -> 0 - Sair                     |" << endl;
        cout << "|  -> 1 - Voltar                   |" << endl;
        cout << "|  -> 2 - Adicionar registros      |" << endl;
        cout << "|  -> 3 - Consultar registros      |" << endl;
        cout << "-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-" << endl;
        cout << "\n   -> Escolha uma opcao: ";
        cin >> opt;

        switch (opt) {
            case 0:
                return -1;

            case 1:
                return 4;

            case 2:
                lerCliente(clienteS, contClienteS);
                break;

            case 3:
                percursoCliente(clienteS, contClienteS);
                break;

            default:
                cout << "Opcao invalida." << endl;
        }
    }
}

int menuGarcom(Garcom garcomS[], int &contGarcomS) {
    int opt = 0;
    while (opt != -1) {
        system("clear");
        cout << "-*-*-*-*-*- Menu Garcom -*-*-*-*-*-" << endl;
        cout << "|  -> 0 - Sair                    |" << endl;
        cout << "|  -> 1 - Voltar                  |" << endl;
        cout << "|  -> 2 - Adicionar registros     |" << endl;
        cout << "|  -> 3 - Consultar registros     |" << endl;
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << "\n   -> Escolha uma opcao: ";
        cin >> opt;

        switch (opt) {
            case 0:
                return -1;

            case 1:
                return 5;

            case 2:
                lerGarcom(garcomS, contGarcomS);
                break;

            case 3:
                percursoGarcom(garcomS, contGarcomS);
                break;

            default:
                cout << "Opcao invalida." << endl;
        }
    }
}

int menuPedido(Pedido pedidoS[], int &contPedidoS, Cliente clienteS[], int contClientS, Garcom garcomS[],
               int contGarcomS, ItemPedido itemPedidoS[], int &contItemPedidoS, Produto produtoS[], int contProdutoS,
               ConsumoIngredientes consumoIngredientes[], int contConsumoIngredientes, Ingrediente ingredienteS[],
               int contIngredienteS) {
    int opt = 0;
    while (opt != -1) {
        system("clear");
        cout << "-*-*-*-*-*- Menu Pedido -*-*-*-*-*-" << endl;
        cout << "|  -> 0 - Sair                    |" << endl;
        cout << "|  -> 1 - Voltar                  |" << endl;
        cout << "|  -> 2 - Adicionar registros     |" << endl;
        cout << "|  -> 3 - Consultar registros     |" << endl;
        cout << "|  -> 4 - Consultar total arrec   |" << endl;
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << "\n   -> Escolha uma opcao: ";
        cin >> opt;

        switch (opt) {
            case 0:
                return -1;

            case 1:
                return 6;

            case 2:
                incluirPedido(pedidoS, contPedidoS, clienteS, contClientS, garcomS, contGarcomS, itemPedidoS,
                              contItemPedidoS, produtoS, contProdutoS, consumoIngredientes, contConsumoIngredientes,
                              ingredienteS, contIngredienteS);
                break;

            case 3:
                percursoPedido(pedidoS, contPedidoS);
                break;
            case 4:
                consultarValorTotalArrecadadoComTodosOsPedidos(pedidoS, contPedidoS, itemPedidoS, contItemPedidoS,
                                                               produtoS, contProdutoS);
                break;

            default:
                cout << "Opcao invalida." << endl;
        }
    }
}

// Funcoes Genericas - Utils

template<typename T>
void verificarCodigo(T array[], int size, int index) {
    if constexpr (is_class_v<T>) {
        if (index == 0 && array[size].codigo <= 0) {
            while (array[size].codigo <= 0) {
                cout << "Codigo invalido.\nPor favor, digite outro codigo: ";
                cin >> array[size].codigo;
            }
        } else if (index > 0) {
            while (array[size].codigo <= array[size - 1].codigo) {
                cout << "Codigo invalido.\nPor favor, digite outro codigo: ";
                cin >> array[size].codigo;
            }
        }
    } else {
        if (index == 0 && array[size] <= 0) {
            while (array[size] <= 0) {
                cout << "Codigo invalido.\nPor favor, digite outro codigo: ";
                cin >> array[size];
            }
        } else if (index > 0) {
            while (array[size] <= array[size - 1]) {
                cout << "Codigo invalido.\nPor favor, digite outro codigo: ";
                cin >> array[size];
            }
        }
    }
}

template<typename T>
int buscaBinaria(T array[], int cod, int f) {
    if (f < 0) return -1;

    int i = 0;
    int m = (i + f) / 2;

    for (; f >= i && cod != array[m].codigo; m = (i + f) / 2) {
        if (cod > array[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == array[m].codigo) {
        return m;
    }
    return -1;
}

template<typename T>
int buscaBinariaConsumoIngrediente(T array[], int cod, int f) {
    if (f < 0) return -1;

    int i = 0;
    int m = (i + f) / 2;

    for (; f >= i && cod != array[m].codigoProduto; m = (i + f) / 2) {
        if (cod > array[m].codigoProduto)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == array[m].codigoProduto) {
        return m;
    }
    return -1;
}

template<typename T>
int buscaBinariaItemPedido(T array[], int cod, int f) {
    if (f < 0) return -1;

    int i = 0;
    int m = (i + f) / 2;

    for (; f >= i && cod != array[m].codigoPedido; m = (i + f) / 2) {
        if (cod > array[m].codigoPedido)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == array[m].codigoPedido) {
        return m;
    }
    return -1;
}

// 1. Leituras (Categoria, Produtos e Ingredientes)

void lerCategoria(Categoria categoriaS[], int &contCategoriaS) {
    char continuar = 'S';
    for (int i = 0; i < 1000 && toupper(continuar) == 'S'; i++) {
        system("clear");
        cout << "\n====== Cadastro de Categorias ======" << endl;
        cout << "\nDigite o codigo da categoria: ";
        cin >> categoriaS[contCategoriaS].codigo;

        verificarCodigo(categoriaS, contCategoriaS, i);

        cin.ignore();
        cout << "\nDigite a descricao da categoria: ";
        getline(cin, categoriaS[contCategoriaS].descricao);

        contCategoriaS++;

        cout << "\nDeseja continuar?";
        cout << "\n(S/N):";
        cin >> continuar;
    }
}

void lerProduto(Produto produtoS[], int &contProdutoS, ConsumoIngredientes consumoIngredientes[],
                int &contConsumoIngredientes, Ingrediente ingredienteS[], int contIngredienteS) {
    char continuar = 'S';
    for (int i = 0; i < 1000 && toupper(continuar) == 'S'; i++) {
        system("clear");
        cout << "\n====== Cadastro de Produtos ======" << endl;
        cout << "\nDigite o codigo do produto: ";
        cin >> produtoS[contProdutoS].codigo;

        verificarCodigo(produtoS, contProdutoS, i);

        cin.ignore();
        cout << "\nDigite o descricao do produto: ";
        getline(cin, produtoS[contProdutoS].descricao);

        cout << "\nDigite o codigo da categoria do produto: ";
        cin >> produtoS[contProdutoS].codigoCategoria;
        cout << "\nDigite o preco unitario do produto: ";
        cin >> produtoS[contProdutoS].precoUnitario;

        lerConsumoIngredientes(consumoIngredientes, contConsumoIngredientes, produtoS[contProdutoS].codigo,
                               ingredienteS, contIngredienteS);

        contProdutoS++;

        cout << "\nDeseja continuar?";
        cout << "\n(S/N):";
        cin >> continuar;
    }
}

void lerIngrediente(Ingrediente ingredienteS[], int &contIngredienteS) {
    char continuar = 'S';
    for (int i = 0; i < 1000 && toupper(continuar) == 'S'; i++) {
        system("clear");
        cout << "\n====== Cadastro de Ingredientes ======" << endl;
        cout << "\nDigite o codigo do ingrediente: ";
        cin >> ingredienteS[contIngredienteS].codigo;

        verificarCodigo(ingredienteS, contIngredienteS, i);

        cin.ignore();
        cout << "\nDigite o descricao do ingrediente: ";
        getline(cin, ingredienteS[contIngredienteS].descricao);

        cout << "\nDigite o preco unitario do ingrediente: ";
        cin >> ingredienteS[contIngredienteS].precoUnitario;
        cout << "\nDigite a quantidade de ingredientes no estoque: ";
        cin >> ingredienteS[contIngredienteS].quantEstoque;
        cout << "\nDigite o estoque minimo de ingredientes no estoque: ";
        cin >> ingredienteS[contIngredienteS].estoqueMin;
        cout << "\nDigite o estoque maximo de ingredientes no estoque: ";
        cin >> ingredienteS[contIngredienteS].estoqueMax;

        contIngredienteS++;

        cout << "\nDeseja continuar?";
        cout << "\n(S/N):";
        cin >> continuar;
    }
}

// 2.1 - O programa devera garantir que o codigo do cliente a ser inserido nao existe na tabela de Clientes.

void lerCliente(Cliente clienteS[], int &contClienteS) {
    Cliente clienteT[1000];
    int contClienteT = 0;
    char continuar = 'S';
    for (int i = 0; i < 1000 && toupper(continuar) == 'S'; i++) {
        system("clear");
        cout << "\n====== Cadastro de Clientes ======" << endl;
        cout << "\nDigite o codigo do cliente: ";
        cin >> clienteT[contClienteT].codigo;

        verificarCodigo(clienteT, contClienteT, i);

        while (buscaBinaria(clienteS, clienteT[contClienteT].codigo, contClienteS - 1) != -1) {
            cout << "Codigo ja registrado.\nPor favor digite outro codigo: ";
            cin >> clienteT[contClienteT].codigo;
            verificarCodigo(clienteT, contClienteT, i);
        }

        cin.ignore();
        cout << "\nDigite o nome do cliente: ";
        getline(cin, clienteT[contClienteT].nome);

        cout << "\nDigite telefone do cliente: ";
        cin >> clienteT[contClienteT].telefone;

        contClienteT++;

        cout << "\nDeseja continuar?";
        cout << "\n(S/N):";
        cin >> continuar;
    }

    incluirNovoCliente(clienteS, contClienteS, clienteT, contClienteT);
}

// 3.1) O programa devera garantir que o codigo do garcom a ser inserido nao existe na tabela de Garcoms.

void lerGarcom(Garcom garcomS[], int &contGarcomS) {
    Garcom garcomT[1000];
    int contGarcomT = 0;
    char continuar = 'S';
    for (int i = 0; i < 1000 && toupper(continuar) == 'S'; i++) {
        system("clear");
        cout << "\n====== Cadastro de Garcoms ======" << endl;
        cout << "\nDigite o codigo do garcom: ";
        cin >> garcomT[contGarcomT].codigo;

        verificarCodigo(garcomT, contGarcomT, i);

        while (buscaBinaria(garcomS, garcomT[contGarcomT].codigo, contGarcomS - 1) != -1) {
            cout << "Codigo ja registrado.\nPor favor digite outro codigo: ";
            cin >> garcomT[contGarcomT].codigo;
            verificarCodigo(garcomT, contGarcomT, i);
        }

        cin.ignore();
        cout << "\nDigite o nome do garcom: ";
        getline(cin, garcomT[contGarcomT].nome);

        contGarcomT++;

        cout << "\nDeseja continuar?";
        cout << "\n(S/N):";
        cin >> continuar;
    }

    incluirNovoGarcom(garcomS, contGarcomS, garcomT, contGarcomT);
}

void lerConsumoIngredientes(ConsumoIngredientes consumoIngredientes[], int &contConsumoIngredientes, int codProduto,
                            Ingrediente ingredienteS[], int contIngredienteS) {
    consumoIngredientes[contConsumoIngredientes].codigoProduto = codProduto;
    cout << "\nDigite o codigo do ingrediente necessario para este produto: ";
    cin >> consumoIngredientes[contConsumoIngredientes].codigoIngrediente;

    while (buscaBinaria(ingredienteS, consumoIngredientes[contConsumoIngredientes].codigoIngrediente,
                        contIngredienteS - 1) == -1) {
        cout << "Codigo nao encontrado.\nPor favor digite outro codigo: ";
        cin >> consumoIngredientes[contConsumoIngredientes].codigoIngrediente;
    }

    cout << "\nDigite a quantidade necessaria de ingrediente para este produto: ";
    cin >> consumoIngredientes[contConsumoIngredientes].quantidade;

    while (consumoIngredientes[contConsumoIngredientes].quantidade <= 0) {
        cout << "\nQuantidade necessária inválida, digite novamente: ";
        cin >> consumoIngredientes[contConsumoIngredientes].quantidade;
    }

    contConsumoIngredientes++;
}

// 5. Escreva uma função para permitir o registro de um novo Pedido.

void incluirPedido(Pedido pedidoS[], int &contPedidoS, Cliente clienteS[], int contClienteS, Garcom garcomS[],
                   int contGarcomS, ItemPedido itemPedidoS[], int &contItemPedidoS, Produto produtoS[],
                   int contProdutoS, ConsumoIngredientes consumoIngredientes[], int contConsumoIngredientes,
                   Ingrediente ingredienteS[], int contIngredienteS) {
    Pedido pedidoA[1000];
    system("clear");
    cout << "\n====== Cadastro de Pedidos ======" << endl;
    cout << "\nDigite o codigo do pedido: ";
    cin >> pedidoS[contPedidoS].codigo;

    verificarCodigo(pedidoS, contPedidoS, 0);

    while (buscaBinaria(pedidoS, pedidoS[contPedidoS].codigo, contPedidoS - 1) != -1) {
        cout << "Codigo ja registrado.\nPor favor digite outro codigo: ";
        cin >> pedidoS[contPedidoS].codigo;
        verificarCodigo(pedidoS, contPedidoS, 0);
    }

    cout << "\nDigite o codigo do cliente do pedido: ";
    cin >> pedidoS[contPedidoS].codigoCliente;

    int indexClienteEncontrado = buscaBinaria(clienteS, pedidoS[contPedidoS].codigoCliente, contClienteS - 1);

    while (indexClienteEncontrado == -1) {
        cout << "Codigo nao encontrado.\nPor favor digite outro codigo: ";
        cin >> pedidoS[contPedidoS].codigoCliente;
        indexClienteEncontrado = buscaBinaria(clienteS, pedidoS[contPedidoS].codigoCliente, contClienteS - 1);
    }

    cout << "\nCliente encontrado: " << clienteS[indexClienteEncontrado].nome << endl;

    cout << "\nDigite o codigo do garcom do pedido: ";
    cin >> pedidoS[contPedidoS].codigoGarcom;

    int indexGarcomEncontrado = buscaBinaria(garcomS, pedidoS[contPedidoS].codigoGarcom, contGarcomS - 1);

    while (indexGarcomEncontrado == -1) {
        cout << "Codigo nao encontrado.\nPor favor digite outro codigo: ";
        cin >> pedidoS[contPedidoS].codigoGarcom;
        indexGarcomEncontrado = buscaBinaria(garcomS, pedidoS[contPedidoS].codigoGarcom, contGarcomS - 1);
    }

    cout << "\nGarcom encontrado: " << garcomS[indexGarcomEncontrado].nome << endl;

    cout << "\nDigite o dia do pedido: ";
    cin >> pedidoS[contPedidoS].data.dia;

    cout << "\nDigite o mes do pedido: ";
    cin >> pedidoS[contPedidoS].data.mes;

    cout << "\nDigite o ano do pedido: ";
    cin >> pedidoS[contPedidoS].data.ano;

    contPedidoS++;

    int j = 0, k = 0;
    bool naoInseriuNovoRegistro = true;
    for (; naoInseriuNovoRegistro; j++) {
        if (pedidoS[k].codigo < pedidoS[contPedidoS - 1].codigo) {
            pedidoA[j] = pedidoS[k];
            k++;
        } else {
            pedidoA[j] = pedidoS[contPedidoS - 1];
            naoInseriuNovoRegistro = false;
        }
    }

    while (j < contPedidoS) {
        pedidoA[j] = pedidoS[k];
        k++;
        j++;
    }

    int codigoDeResposta = incluirNovoItemPedido(itemPedidoS, contItemPedidoS, pedidoS[contPedidoS - 1].codigo,
                                                 produtoS, contProdutoS,
                                                 consumoIngredientes, contConsumoIngredientes, ingredienteS,
                                                 contIngredienteS) != 0;

    while (codigoDeResposta != 0) {
        codigoDeResposta = incluirNovoItemPedido(itemPedidoS, contItemPedidoS, pedidoS[contPedidoS - 1].codigo,
                                                 produtoS, contProdutoS,
                                                 consumoIngredientes, contConsumoIngredientes, ingredienteS,
                                                 contIngredienteS) != 0;
    };

    system("read -p 'Pressione Enter para continuar...' var");

    for (int l = 0; l < contPedidoS; l++) {
        pedidoS[l] = pedidoA[l];
    }
}

// 6. Escreva uma função para permitir a inclusão de produtos em um pedido.

int incluirNovoItemPedido(ItemPedido itemPedidoS[], int &contItemPedidoS, int codigoPedido,
                          Produto produtoS[], int contProdutoS, ConsumoIngredientes consumoIngredientes[],
                          int contConsumoIngredientes, Ingrediente ingredienteS[], int contIngredienteS) {
    system("clear");

    ItemPedido itemPedidoA[1000];

    itemPedidoS[contItemPedidoS].codigoPedido = codigoPedido;
    cout << "\n====== Selecionar Produto do Pedido ======" << endl;
    cout << "\nDigite o codigo do produto desejado: ";
    cin >> itemPedidoS[contItemPedidoS].codigoProduto;

    int indexProdutoEncontrado = buscaBinaria(produtoS, itemPedidoS[contItemPedidoS].codigoProduto, contProdutoS - 1);

    while (indexProdutoEncontrado == -1) {
        cout << "Produto nao encontrado.\nPor favor digite outro codigo: ";
        cin >> itemPedidoS[contItemPedidoS].codigoProduto;
        indexProdutoEncontrado = buscaBinaria(produtoS, itemPedidoS[contItemPedidoS].codigoProduto, contProdutoS - 1);
    }

    cout << "Produto: " << produtoS[indexProdutoEncontrado].descricao << endl;
    cout << "Preco Unitario: " << produtoS[indexProdutoEncontrado].precoUnitario << endl;

    cout << "Digite a quantidade deste produto: " << endl;
    cin >> itemPedidoS[contItemPedidoS].quantidade;

    int indexConsumoIngrediente = buscaBinariaConsumoIngrediente(consumoIngredientes,
                                                                 produtoS[indexProdutoEncontrado].codigo,
                                                                 contConsumoIngredientes - 1);

    int indexIngrediente = buscaBinaria(ingredienteS, consumoIngredientes[indexConsumoIngrediente].codigoIngrediente,
                                        contIngredienteS - 1);

    cout << "\nIngrediente Necessario: " << ingredienteS[indexIngrediente].descricao << endl;

    if (ingredienteS[indexIngrediente].quantEstoque - (
            consumoIngredientes[indexConsumoIngrediente].quantidade * itemPedidoS[contItemPedidoS].quantidade) >= 0) {
        cout << "Item adicionado com sucesso";
        ingredienteS[indexIngrediente].quantEstoque -= (
            consumoIngredientes[indexConsumoIngrediente].quantidade * itemPedidoS[contItemPedidoS].quantidade);
        contItemPedidoS++;

        int j = 0, k = 0;
        bool naoInseriuNovoRegistro = true;
        for (; naoInseriuNovoRegistro; j++) {
            if (itemPedidoS[k].codigoPedido < itemPedidoS[contItemPedidoS - 1].codigoPedido) {
                itemPedidoA[j] = itemPedidoS[k];
                k++;
            } else {
                itemPedidoA[j] = itemPedidoS[contItemPedidoS - 1];
                naoInseriuNovoRegistro = false;
            }
        }

        while (j < contItemPedidoS) {
            itemPedidoA[j] = itemPedidoS[k];
            k++;
            j++;
        }

        system("read -p 'Pressione Enter para continuar...' var");

        for (int l = 0; l < contItemPedidoS; l++) {
            itemPedidoS[l] = itemPedidoA[l];
        }

        return 0;
    }

    cout << "\nIngredientes insulficientes: " << ingredienteS[indexIngrediente].quantEstoque - (
        consumoIngredientes[indexConsumoIngrediente].quantidade * itemPedidoS[contItemPedidoS].quantidade) << endl;
    cout << "Insira outro produto: " << endl;
    system("read -p 'Pressione Enter para continuar...' var");
    return -1;
}


// 2. Escreva uma funcao para permitir a inclusao de novos registros na tabela de Clientes.

void incluirNovoCliente(Cliente clienteS[], int &contClienteS, Cliente clienteT[], int contClienteT) {
    Cliente clienteA[1000];

    int i = 0, j = 0, k = 0; // i (contador de S) j (contador de T) k (contador de A)
    for (; i < contClienteS && j < contClienteT; k++) {
        if (clienteS[i].codigo < clienteT[j].codigo) {
            clienteA[k].codigo = clienteS[i].codigo;
            clienteA[k].nome = clienteS[i].nome;
            clienteA[k].telefone = clienteS[i].telefone;
            i++;
        } else {
            clienteA[k].codigo = clienteT[j].codigo;
            clienteA[k].nome = clienteT[j].nome;
            clienteA[k].telefone = clienteT[j].telefone;
            j++;
        }
    }
    while (i < contClienteS) {
        clienteA[k].codigo = clienteS[i].codigo;
        clienteA[k].nome = clienteS[i].nome;
        clienteA[k].telefone = clienteS[i].telefone;
        i++;
        k++;
    }
    while (j < contClienteT) {
        clienteA[k].codigo = clienteT[j].codigo;
        clienteA[k].nome = clienteT[j].nome;
        clienteA[k].telefone = clienteT[j].telefone;
        j++;
        k++;
    }
    contClienteS = k;

    for (int l = 0; l < k; l++) {
        clienteS[l].codigo = clienteA[l].codigo;
        clienteS[l].nome = clienteA[l].nome;
        clienteS[l].telefone = clienteA[l].telefone;
    }
}

// 3. Escreva uma funcao para permitir a inclusao de novos registros na tabela de Garcoms.

void incluirNovoGarcom(Garcom garcomS[], int &contGarcomS, Garcom garcomT[], int contGarcomT) {
    Garcom garcomA[1000];
    int i = 0, j = 0, k = 0; // i (contador de S) j (contador de T) k (contador de A)
    for (; i < contGarcomS && j < contGarcomT; k++) {
        if (garcomS[i].codigo < garcomT[j].codigo) {
            garcomA[k].codigo = garcomS[i].codigo;
            garcomA[k].nome = garcomS[i].nome;
            i++;
        } else {
            garcomA[k].codigo = garcomT[j].codigo;
            garcomA[k].nome = garcomT[j].nome;
            j++;
        }
    }
    while (i < contGarcomS) {
        garcomA[k].codigo = garcomS[i].codigo;
        garcomA[k].nome = garcomS[i].nome;
        i++;
        k++;
    }
    while (j < contGarcomT) {
        garcomA[k].codigo = garcomT[j].codigo;
        garcomA[k].nome = garcomT[j].nome;
        j++;
        k++;
    }
    contGarcomS = k;

    for (int l = 0; l < k; l++) {
        garcomS[l].codigo = garcomA[l].codigo;
        garcomS[l].nome = garcomA[l].nome;
    }
}

// 4. Escreva uma funcao para permitir a exclusao de registros da tabela de Produtos.

void excluirProduto(Produto produtoS[], int &qtdProdutoS, int codigosT[], int qtdCodigosT) {
    Produto produtoA[1000];
    int i = 0, j = 0, k = 0; // i (contador de S) j (contador de T) k (contador de A)
    for (; j < qtdCodigosT; i++) {
        if (produtoS[i].codigo != codigosT[j]) {
            produtoA[k].codigo = produtoS[i].codigo;
            produtoA[k].descricao = produtoS[i].descricao;
            produtoA[k].codigoCategoria = produtoS[i].codigoCategoria;
            produtoA[k].precoUnitario = produtoS[i].precoUnitario;
            k++;
        } else {
            j++;
        }
    }
    while (i < qtdProdutoS) {
        produtoA[k].codigo = produtoS[i].codigo;
        produtoA[k].descricao = produtoS[i].descricao;
        produtoA[k].codigoCategoria = produtoS[i].codigoCategoria;
        produtoA[k].precoUnitario = produtoS[i].precoUnitario;
        i++;
        k++;
    }
    qtdProdutoS = k;

    for (int l = 0; l < k; l++) {
        produtoS[l].codigo = produtoA[l].codigo;
        produtoS[l].descricao = produtoA[l].descricao;
        produtoS[l].codigoCategoria = produtoA[l].codigoCategoria;
        produtoS[l].precoUnitario = produtoA[l].precoUnitario;
    }
}


void lerCodigosDeProdutosParaExclusao(Produto produtoS[], int &contProdutoS) {
    int codigoT[1000], contCodigoT = 0;
    char continuar = 'S';
    for (int i = 0; i < 1000 && toupper(continuar) == 'S'; i++) {
        system("clear");
        cout << "\n====== Codigos de Produtos Para Exclusao ======" << endl;
        cout << "\nDigite o codigo do produto a ser excluido: ";
        cin >> codigoT[contCodigoT];

        verificarCodigo(codigoT, contCodigoT, i);

        while (buscaBinaria(produtoS, codigoT[contCodigoT], contProdutoS - 1) == -1) {
            cout << "Codigo nao encontrado.\nPor favor digite outro codigo: ";
            cin >> codigoT[contCodigoT];
            verificarCodigo(codigoT, contCodigoT, i);
        }

        contCodigoT++;

        if (contCodigoT == contProdutoS) {
            cout << "Todos os produtos foram excluidos" << endl;
            i = 1000;
        } else {
            cout << "\nDeseja continuar?";
            cout << "\n(S/N):";
            cin >> continuar;
        }
    }

    excluirProduto(produtoS, contProdutoS, codigoT, contCodigoT);
}

// Percursos

void percursoCategoria(Categoria categorias[], int qtde) {
    system("clear");
    cout << "[" << endl;
    for (int i = 0; i < qtde; i++) {
        cout << "  {" << endl;
        cout << "    \"codigo\": " << categorias[i].codigo << "," << endl;
        cout << "    \"descricao\": \"" << categorias[i].descricao << "\"" << endl;
        cout << "  }";

        if (i < qtde - 1) {
            cout << "," << endl;
        }
    }
    cout << "\n]" << endl;
    system("read -p 'Pressione Enter para continuar...' var");
}

void percursoProduto(Produto produtos[], int qtde) {
    system("clear");
    cout << "[" << endl;
    for (int i = 0; i < qtde; i++) {
        cout << "  {" << endl;
        cout << "    \"codigo\": " << produtos[i].codigo << "," << endl;
        cout << "    \"descricao\": \"" << produtos[i].descricao << "\"," << endl;
        cout << "    \"codigoCategoria\": " << produtos[i].codigoCategoria << "," << endl;
        cout << "    \"precoUnitario\": " << produtos[i].precoUnitario << endl;
        cout << "  }";

        if (i < qtde - 1) {
            cout << "," << endl;
        }
    }
    cout << "\n]" << endl;
    system("read -p 'Pressione Enter para continuar...' var");
}

void percursoIngrediente(Ingrediente ingredientes[], int qtde) {
    system("clear");
    cout << "[" << endl;
    for (int i = 0; i < qtde; i++) {
        cout << "  {" << endl;
        cout << "    \"codigo\": " << ingredientes[i].codigo << "," << endl;
        cout << "    \"descricao\": \"" << ingredientes[i].descricao << "\"," << endl;
        cout << "    \"quantEstoque\": " << ingredientes[i].quantEstoque << "," << endl;
        cout << "    \"estoqueMin\": " << ingredientes[i].estoqueMin << "," << endl;
        cout << "    \"estoqueMax\": " << ingredientes[i].estoqueMax << "," << endl;
        cout << "    \"precoUnitario\": " << ingredientes[i].precoUnitario << "," << endl;
        cout << "    \"valorTotal\": " << ingredientes[i].quantEstoque * ingredientes[i].precoUnitario << endl;
        cout << "  }";

        if (i < qtde - 1) {
            cout << "," << endl;
        }
    }
    cout << "\n]" << endl;
    system("read -p 'Pressione Enter para continuar...' var");
}

void printIngrediente(Ingrediente ingrediente) {
    system("clear");
    cout << "{" << endl;
    cout << "  \"codigo\": " << ingrediente.codigo << "," << endl;
    cout << "  \"descricao\": \"" << ingrediente.descricao << "\"," << endl;
    cout << "  \"quantEstoque\": " << ingrediente.quantEstoque << "," << endl;
    cout << "  \"estoqueMin\": " << ingrediente.estoqueMin << "," << endl;
    cout << "  \"estoqueMax\": " << ingrediente.estoqueMax << "," << endl;
    cout << "  \"precoUnitario\": " << ingrediente.precoUnitario << "," << endl;
    cout << "  \"valorTotal\": " << ingrediente.quantEstoque * ingrediente.precoUnitario << endl;
    cout << "}";
    system("read -p 'Pressione Enter para continuar...' var");
}

void percursoCliente(Cliente clientes[], int qtde) {
    system("clear");
    cout << "[" << endl;
    for (int i = 0; i < qtde; i++) {
        cout << "  {" << endl;
        cout << "    \"codigo\": " << clientes[i].codigo << "," << endl;
        cout << "    \"nome\": \"" << clientes[i].nome << "\"," << endl;
        cout << "    \"telefone\": \"" << clientes[i].telefone << "\"" << endl;
        cout << "  }";

        if (i < qtde - 1) {
            cout << "," << endl;
        }
    }
    cout << "\n]" << endl;
    system("read -p 'Pressione Enter para continuar...' var");
}

void percursoGarcom(Garcom garcons[], int qtde) {
    system("clear");
    cout << "[" << endl;
    for (int i = 0; i < qtde; i++) {
        cout << "  {" << endl;
        cout << "    \"codigo\": " << garcons[i].codigo << "," << endl;
        cout << "    \"nome\": \"" << garcons[i].nome << "\"" << endl;
        cout << "  }";

        if (i < qtde - 1) {
            cout << "," << endl;
        }
    }
    cout << "\n]" << endl;
    system("read -p 'Pressione Enter para continuar...' var");
}

void percursoPedido(Pedido pedidos[], int qtde) {
    system("clear");
    cout << "[" << endl;
    for (int i = 0; i < qtde; i++) {
        cout << "  {" << endl;
        cout << "    \"codigo\": " << pedidos[i].codigo << "," << endl;
        cout << "    \"codigoCliente\": " << pedidos[i].codigoCliente << "," << endl;
        cout << "    \"codigoGarcom\": " << pedidos[i].codigoGarcom << "," << endl;
        cout << "    \"data\": \"" << pedidos[i].data.dia << "/" << pedidos[i].data.mes << "/" << pedidos[i].data.ano <<
                "\"" << endl;
        cout << "  }";


        if (i < qtde - 1) {
            cout << "," << endl;
        }
    }
    cout << "\n]" << endl;
    system("read -p 'Pressione Enter para continuar...' var");
}

// 7. Escreva uma fun??o para permitir ao usu?rio consultar os dados de determinado ingrediente.

void consultarUmIngrediente(Ingrediente ingrediente[], int qtdIngredienteCadastrado) {
    system("clear");

    int cod = 0;
    cout << "Digite o codigo do ingrediente: ";
    cin >> cod;

    while (cod <= 0) {
        cout << "O codigo digitado nao e valido!" << endl;
        cout << "Digite outro codigo para consultar: ";
        cin >> cod;
    }


    int index = buscaBinaria(ingrediente, cod, qtdIngredienteCadastrado - 1);

    if (index < 0) {
        cout << "O codigo digitado nao foi encontrado!" << endl;
        system("read -p 'Pressione Enter para continuar...' var");
        return;
    }
    system("clear");
    cout << "\n{" << endl;
    cout << "  \"codigo\": " << ingrediente[index].codigo << "," << endl;
    cout << "  \"descricao\": \"" << ingrediente[index].descricao << "\"," << endl;
    cout << "  \"quantEstoque\": " << ingrediente[index].quantEstoque << "," << endl;
    cout << "  \"estoqueMin\": " << ingrediente[index].estoqueMin << "," << endl;
    cout << "  \"estoqueMax\": " << ingrediente[index].estoqueMax << "," << endl;
    cout << "  \"precoUnitario\": " << ingrediente[index].precoUnitario << "," << endl;
    cout << "  \"valorTotal\": " << ingrediente[index].quantEstoque * ingrediente[index].precoUnitario << endl;
    cout << "}" << endl;
    cout << endl;
    system("read -p 'Pressione Enter para continuar...' var");
}

// 8. Escreva uma fun??o para exibir todos os ingredientes que estejam com a quantidade em estoque abaixo do estoque m?nimo.

void consultarIngredientesComEstoqueBaixo(Ingrediente ingrediente[], int qtdIngredienteCadastrado) {
    system("clear");
    int cont = 0;
    float totalReposicao = 0;
    for (int i = 0; i < qtdIngredienteCadastrado; i++) {
        if (ingrediente[i].quantEstoque < ingrediente[i].estoqueMin) {
            cout << "{" << endl;
            cout << "  \"codigo\": " << ingrediente[i].codigo << "," << endl;
            cout << "  \"descricao\": \"" << ingrediente[i].descricao << "\"," << endl;
            cout << "  \"quantEstoque\": " << ingrediente[i].quantEstoque << "," << endl;
            cout << "  \"estoqueMax\": " << ingrediente[i].estoqueMax << "," << endl;
            cout << "  \"estoqueMin\": " << ingrediente[i].estoqueMin << "," << endl;
            cout << "  \"quantidadeASerComprada\": " << ingrediente[i].estoqueMax - ingrediente[i].quantEstoque << ","
                    << endl;
            cout << "  \"valorDaCompraDosIngredientes\": " << (ingrediente[i].estoqueMax - ingrediente[i].quantEstoque)
                    * ingrediente[i].precoUnitario << "," << endl;
            cout << "}" << endl;
            cont++;
            totalReposicao += (ingrediente[i].estoqueMax - ingrediente[i].quantEstoque)
                    * ingrediente[i].precoUnitario;
        }
    }
    if (cont == 0) {
        cout << "Nao ha itens com estoque abaixo do minimo!" << endl;
    } else {
        cout << "\nTotal de gastos para reposicao: " << totalReposicao << endl;
    }
    cout << endl;
    system("read -p 'Pressione Enter para continuar...' var");
}

// 9. Escreva uma função para exibir o valor total arrecadado com todos os pedidos.

void consultarValorTotalArrecadadoComTodosOsPedidos(Pedido pedidoS[], int contPedidoS, ItemPedido itemPedidoS[],
                                                    int contItemPedidoS, Produto produtoS[], int contProdutoS) {
    system("clear");
    float valorTotalArrecadado = 0;

    for (int i = 0; i < contPedidoS; i++) {
        int indexItemPedido = buscaBinariaItemPedido(itemPedidoS, pedidoS[i].codigo, contItemPedidoS);
        int indexProduto = buscaBinaria(produtoS, itemPedidoS[indexItemPedido].codigoProduto, contProdutoS);
        valorTotalArrecadado += itemPedidoS[indexItemPedido].quantidade * produtoS[indexProduto].precoUnitario;
    }

    cout << "Valor total arrecadado: " << valorTotalArrecadado << endl;
}
