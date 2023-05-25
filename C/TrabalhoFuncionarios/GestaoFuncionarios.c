#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

typedef struct
{
    char cpf[12], nome[50], sit;
    float salario;
}Funcionario;

/*
- Inclusão
- Alteração
- Exclusão
- Consulta
- Listagem
- Lixeira
*/

void salvarFuncionario(Funcionario*);
void alterarFuncionario(Funcionario*,int);
void excluirFuncionario(Funcionario*, int);
void listarFuncionarios(Funcionario*);
void listarFuncionariosExcluidos(Funcionario*);


int validarCpf(char*);
int validarNome(char*);

int buscaFuncionario(char*, Funcionario*);

FILE *fp;
int main(){
    Funcionario funcionario;
    char cpf[12];
    char *sus[]={"Ama","Goma"};
    int opc, posicao, opcUtil;
    printf("Bem vindo ao sistema de gerenciamento de funcionarios \n");
    do{
        printf("Escolha o numero da opcao que deseja: \n");
        printf("1. Incluir funcionario \n");
        printf("2. Alterar funcionario \n");
        printf("3. Excluir funcionario \n");
        printf("4. Consultar funcionario \n");
        printf("5. Listar funcionarios \n");
        printf("6. Listar funcionarios deletados \n");
        printf("0. Sair: \n");
        
        fflush(stdin);
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            system("cls");
            printf("Digite o cpf do funcionario: ");
            fflush(stdin);
            gets(cpf);
            buscaFuncionario(cpf,&funcionario);
            while(!validarCpf(cpf) || strcmp(cpf, funcionario.cpf)==0){
                printf("Digite um cpf valido!: ");
                fflush(stdin);
                gets(cpf);
                buscaFuncionario(cpf,&funcionario);
            }
            printf("Digite o nome: ");
            fflush(stdin);
            gets(funcionario.nome);
            while(!validarNome(funcionario.nome)){
                printf("Digite um nome valido!: ");
                fflush(stdin);
                gets(funcionario.nome);
            }
            printf("Digite o salario: ");
            fflush(stdin);
            while(!scanf("%f", &funcionario.salario)){
                printf("Digite um salario valido!: ");
                fflush(stdin);
            }
            funcionario.sit='0';
            strcpy(funcionario.cpf,cpf);
            salvarFuncionario(&funcionario);
            printf("Salvando");
            for(int c=0; c<3; c++){
                printf(".");
                Sleep(400);
            }
            printf("\nFinalizado!");
            printf("\nPressione enter para voltar");
            fflush(stdin);
            getchar();
            break;
        
        case 2:
            system("cls");
            printf("Digite o cpf do funcionario que deseja alterar: ");
            fflush(stdin);
            gets(cpf);
            while(!validarCpf(cpf)){
                printf("Digite um cpf valido!: ");
                fflush(stdin);
                gets(cpf);
            }
            posicao=buscaFuncionario(cpf,&funcionario);
            printf("Buscando");
            for(int c=0; c<3; c++){
                printf(".");
                Sleep(400);
            }
            if(funcionario.sit=='0'){//Encontrado!
                printf("\nEncontrado!\n");
                Sleep(200);
                printf("Cpf: %s\n", funcionario.cpf);
                printf("1. Nome: %s\n", funcionario.nome);
                printf("2. Salario: %f\n", funcionario.salario);
                printf("Digite o numero do campo que quer alterar: ");
                fflush(stdin);
                scanf("%d",&opcUtil);
                switch(opcUtil){
                    case 1:
                        printf("Digite o novo nome: ");
                        fflush(stdin);
                        gets(funcionario.nome);
                        while(!validarNome(funcionario.nome)){
                            printf("Digite um nome valido!: ");
                            fflush(stdin);
                            gets(funcionario.nome);
                        }
                        break;
                    case 2:
                        printf("Digite o novo salario: ");
                        fflush(stdin);
                        while(!scanf("%f", &funcionario.salario)){
                            printf("Digite um salario valido!: ");
                            fflush(stdin);
                        }
                        break;
                }
                alterarFuncionario(&funcionario, posicao);
                printf("Salvando");
                for(int c=0; c<3; c++){
                    printf(".");
                    Sleep(400);
                }
                printf("\nFinalizado!");
            }
            else
                printf("\nNao existe um funcionario ativo com este cpf!");
            printf("\nPressione enter para voltar");
            fflush(stdin);
            getchar();
            break; 

        case 3:
            system("cls");
            printf("Digite o cpf do funcionario que deseja excluir: ");
            fflush(stdin);
            gets(cpf);
            while(!validarCpf(cpf)){
                printf("Digite um cpf valido!: ");
                fflush(stdin);
                gets(cpf);
            }
            posicao=buscaFuncionario(cpf,&funcionario);
            printf("Buscando");
            for(int c=0; c<3; c++){
                printf(".");
                Sleep(400);
            }
            if(funcionario.sit=='0'){//Encontrado!
                printf("\nEncontrado!\n");
                Sleep(200);
                printf("Cpf: %s\n", funcionario.cpf);
                printf("1. Nome: %s\n", funcionario.nome);
                printf("2. Salario: %f\n", funcionario.salario);
                printf("Certeza que deseja exclui-lo?(1 Para sim | 0 Para nao): \n");
                scanf("%d", &opcUtil);
                if(opcUtil==1){
                    excluirFuncionario(&funcionario,posicao);
                    printf("Excluindo");
                    for(int c=0; c<3; c++){
                        printf(".");
                        Sleep(400);
                    }
                    printf("\nFinalizado!");
                }
            }
            else
                printf("\nNao existe um funcionario ativo com este cpf!");
            printf("\nPressione enter para voltar");
            fflush(stdin);
            getchar();
            break;

        case 4:
            system("cls");
            printf("Digite o cpf do funcionario que deseja consultar: ");
            fflush(stdin);
            gets(cpf);
            while(!validarCpf(cpf)){
                printf("Digite um cpf valido!: ");
                fflush(stdin);
                gets(cpf);
            }
            posicao=buscaFuncionario(cpf,&funcionario);
            printf("Buscando");
            for(int c=0; c<3; c++){
                printf(".");
                Sleep(400);
            }
            if(funcionario.sit=='0'){
                printf("\nEncontrado!\n");
                Sleep(200);
                printf("Cpf: %s\n", funcionario.cpf);
                printf("1. Nome: %s\n", funcionario.nome);
                printf("2. Salario: %f\n", funcionario.salario);
            }
            else
                printf("\nNao existe um funcionario ativo com este cpf!");
            printf("\nPressione enter para voltar");
            fflush(stdin);
            getchar();
            break;

        case 5:
            system("cls");
            printf("Lista de funcionarios: \n");
            printf("    CPF    |    NOME    |    SALARIO\n\n");
            listarFuncionarios(&funcionario);
            printf("\nPressione enter para voltar");
            fflush(stdin);
            getchar();
            break;

        case 6:
            system("cls");
            printf("Lista de funcionarios excluidos: \n");
            printf("    CPF    |    NOME    |    SALARIO\n\n");
            listarFuncionariosExcluidos(&funcionario);
            printf("\nPressione enter para voltar");
            fflush(stdin);
            getchar();
            break;
        default:
            break;
        }
    system("cls");
    }while(opc!=0);
}

void salvarFuncionario(Funcionario *novoFuncionario){

    fp=fopen("cadfun.dad","ab");

    fwrite(novoFuncionario,sizeof(Funcionario),1,fp);

    fclose(fp);
}

int buscaFuncionario(char *cpf, Funcionario* funcionario){
    int posicao=0;

    fp=fopen("cadfun.dad","rb");

    fread(funcionario,sizeof(Funcionario),1,fp);
    //printf("Sus");
    while(strcmp(cpf, funcionario->cpf)!=0){
        posicao++;
        //printf("Sugoma");
        fread(funcionario,sizeof(Funcionario),1,fp);
    
        if(feof(fp)&&strcmp(cpf, funcionario->cpf)!=0){
            funcionario->sit='2';
            break;
        }

    }

    fclose(fp);
    return posicao;
}

void alterarFuncionario(Funcionario *funcionario, int posicao){

    fp=fopen("cadfun.dad","r+b");
    
    fseek(fp, posicao*sizeof(Funcionario), SEEK_SET);
    fwrite(funcionario,sizeof(Funcionario),1,fp);

    fclose(fp);
}

void excluirFuncionario(Funcionario *funcionario, int posicao){

    fp=fopen("cadfun.dad","r+b");

    funcionario->sit='1';

    fseek(fp, posicao*sizeof(Funcionario), SEEK_SET);
    fwrite(funcionario,sizeof(Funcionario),1,fp);

    fclose(fp);
}

void listarFuncionarios(Funcionario *funcionario){
    fp=fopen("cadfun.dad","rb");

    fread(funcionario,sizeof(Funcionario),1,fp);
    while(!feof(fp)){
        if(funcionario->sit=='0'){
            printf("%s | %s | %f\n", funcionario->cpf, funcionario->nome, funcionario->salario);
        }
        fread(funcionario,sizeof(Funcionario),1,fp);
    }

    fclose(fp);
}

void listarFuncionariosExcluidos(Funcionario *funcionario){
    fp=fopen("cadfun.dad","rb");

    fread(funcionario,sizeof(Funcionario),1,fp);
    while(!feof(fp)){
        if(funcionario->sit=='1'){
            printf("%s | %s | %f\n", funcionario->cpf, funcionario->nome, funcionario->salario);
        }
        fread(funcionario,sizeof(Funcionario),1,fp);
    }

    fclose(fp);
}

int validarCpf(char *cpf){
    unsigned char c;
    if (strlen(cpf)!=11)
        return 0;
        
    while ( ( c = *cpf ) && (isdigit( c )) ) ++cpf;

    return *cpf == '\0'; 
}

int validarNome(char *nome){
    unsigned char c;

    while ( ( c = *nome ) && ( isalpha( c ) || isblank( c ) ) ) ++nome;

    return *nome == '\0'; 
}

//-> Arrow operator
//Para o feof() é final do arquivo apos ele encontrar o EOF(EOF=-1), ou seja, pra ele, é final de arquivo apos EOF 