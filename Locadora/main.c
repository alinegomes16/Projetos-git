#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // Exemplo de uso para converter maiusculas em minusculas e vice versa,(ex.	strupr e strlwr)
#include <locale.h> // Esta biblioteca permite uso de acentos e outros caracteres.
#include <windows.h> //Usando para iniciar a janela maximizada.
#include <string.h> //Biblioteca com recursos para manipula��o de strings.
#include <conio.h>  //Serve para usar fun��es de leitura e escrita (exemplo de uma de suas fun��es: 
                    //getch() que l� um caractere digitado e retorna este caractere).

//---------------------------------------------------------------------------------------------------------------------------------------

//Fun��es

void abnt_br();
void menuPrincipal();
void limpaBuffer();
void telaCheia();
void menuControleLocacao();
void menuCadCarro();
void cadCarro();
void gravaCarro();
void listaCarroDisponivel();
void listaLocacao();
void novaLocacao();
void gravaLocacao();
void menuCadCliente();
void gravaCliente();
void listaCliente();
void removeCliente();
void cadCliente();
void pesquisarCliente();
void pesquisarCarro();
void menuDevolucao();
void cadastrarDevolucao();
void removeCarro();



//---------------------------------------------------------------------------------------------------------------------------------------


//Declara��o das vari�veis---------------------------------------------------------------------------------------------------------------
	    int op; 
	    char valida; 
	    int juridica,empresaParceira,diarias,cortesia,continuar,contador_geral=1,escolha_cliente,escolha_carro;
	    float valorTotal, descontoTotal, valorAluguel, desconto;
	    int escolhaCar,escolha;
	    
		int i,aux;
		int totaldias;
		int anot,mest,diat;

		int hora[2],min[2];
		int dia [2];
		int mes [2];
		int ano [2];		

//Declara��o das estruturas do programa--------------------------------------------------------------------------------------------------	

//----------Struct do aluguel----------
typedef struct aluguel{
   
    char* aplaca;
    char* clienteCpf;
} Alugar;
Alugar alugar[1000];
int a, cont_a=0;

//----------Struct da devolucao----------
typedef struct devolucao{
	

	char* placaCar;


} Cadastro_devolucao;
Cadastro_devolucao  devolucao[1000];
int d;
int escolhaCli,cont_d=0;
float multa;
//----------Struct do carro----------
typedef struct carro{
        char modelo[50];
        char marca[50];
        char cor[50];
        unsigned int ano;
        char placa[7];
        int estado; // 0=disponivel 1=alugado
        float valorDiaria;
    } Cadastro_carro;

    Cadastro_carro carro[1000];
    int c, cont_c=0;

//----------Struct do cliente----------
typedef struct cliente{
    char nomec[50];
    char cpf[15];
    int idade;
    char endereco[99];
} Cadastro_cliente;

Cadastro_cliente cliente[1000];
int C, cont_C=0;



int main(int argc, char *argv[]) {
	
	int menu,i,continuar, contador_geral=1, escolha_cliente, escolha_carro;
	
	inicio:	//R�tulo
		
	do{
		system("cls");
		abnt_br();
		menuPrincipal();
		printf("Selecione uma das op��es do menu:\n");
		scanf(" %d", &op);
		printf("\n");	
		fflush(stdin); //Limpar o buffer do teclado.
	        
		   switch(op)
		   {
		        case 1:
		            system("cls");
		            goto cadCarro;
		            break;
			    case 2:
			    	system("cls");
			    	goto cadCliente;
			    	break;
			    case 3: 
				    system("cls");
			    	goto locacao;
			    	break;
		    	case 4: 
			    	system("cls");
			    	goto devolucao;
			    	break;	
			    case 0: 
			        printf("Deseja encerrar o sistema?  (S - Sim / N - N�o) \n");
		            scanf("%c", &valida);
		            valida = toupper(valida);  //toupper converte o que for digitado para mai�sculo
			    	fflush(stdin); //Limpar o buffer do teclado.
			    	   if (valida == 'S')
				       { 
				        exit(0);
				       }
				        else if (valida == 'N')
				        {
				        system("cls");
				        goto inicio; //Retorna ao menu inicial 
				        }
				        else if(valida != 'S' && valida != 'N')
				        {
				   	    printf("Selecione corretamente uma das op��es! (S - Sim / N - N�o) \n \n \n");
				   	    system ("pause");
				   	    system("cls");
				   	    fflush(stdin); //Limpar o buffer do teclado.			 	  	    
				   	    goto inicio; //Retorna ao menu inicial
				   		}
				   		break;
				   
		    	default:
			    	printf("Selecione uma das op��es contidas no menu acima.\n\n");
			    	system("\n\npause");
			    	system("cls");
			    	goto inicio; //Retorna ao menu inicial
					break;
				}
	
		return 0;
		} //do
    	while(valida != '6');
//---------------------------------------------------------------------------------------------------------------------------------------
locacao:  //Inicio menu controle de loca��o
    menuControleLocacao();
    	printf("\nSelecione uma das op��es do menu:\n");
	    scanf(" %d", &op);
	    printf("\n");
	    fflush(stdin); //Limpar o buffer do teclado.
	    switch(op)
		{
		    case 1: 
		    	system("cls");
		    	while(cont_c==0 || cont_C==0){
			    	printf("\n Cadastre pelo menos um carro e um cliente para continuar! \n");
			    	system("pause");
					goto inicio;
				}
		        novaLocacao();
		        system("pause");
		        system("cls");
		        goto locacao;
		        break;
            case 2: 
		        system("cls");
		        listaLocacao(); 
		        system("cls");
		        goto locacao;
				break;
		    case 0: 
		        system("cls");
		        goto inicio; //Retorna ao menu inicial
		        break;   
		    default:
		    	printf("Selecione uma das op��es contidas no menu acima.\n\n");
		    	system("\n\npause");
		    	system("cls");
		    	goto locacao; //Retorna ao menu de op��es
				break;
        }
//---------------------------------------------------------------------------------------------------------------------------------------        
devolucao:
	menuDevolucao();
	printf("\nSelecione uma das op��es do menu:\n");
	scanf("%d", &op);
	printf("\n");
	fflush(stdin);
	switch(op){
		case 1:
			system("cls");
			if(cont_a==0){
				printf("Deve haver pelo menos um carro alugado\n");
			}else{
			cadastrarDevolucao();
			system("cls");
			}
			goto devolucao;
			break;
		case 0: 
			system("cls");
			goto inicio;
			break;
		default:
			printf("Selecione uma das op��es contidas no menu acima.\n\n");
	    	system("\n\npause");
	    	system("cls");
	    	goto devolucao; //Retorna ao menu de op��es
			break;
	}
//---------------------------------------------------------------------------------------------------------------------------------------        

 cadCliente:  //Inicio menu Controle de clientes
    menuCadCliente();
    	printf("\nSelecione uma das op��es do menu:\n");
	    scanf(" %d", &op);
	    printf("\n");	
	    fflush(stdin); //Limpar o buffer do teclado.
	    switch(op)
		{
		    case 1: 
		    	system("cls");
		        gravaCliente();
				system("cls");		   
		        goto cadCliente;
		        break;
		    case 2: 
		        system("cls");
		        if(cont_C==0){
		        	printf("Nenhum cliente cadastrado \n");
				}else{
					removeCliente();
					goto cadCliente;
				}
		        break;    
            case 3:
            	system("cls");
		        listaCliente();
		        system("cls");
		        goto cadCliente;
		        break;
			case 0: 
		        system("cls");
		        goto inicio; //Retorna ao menu inicial
		        break;	  
		    default:
		    	printf("Selecione uma das op��es contidas no menu acima.\n\n");
		    	system("\n\npause");
		    	goto cadCliente; //Retorna ao menu de op��es
				break;
        } 
//---------------------------------------------------------------------------------------------------------------------------------------        
        
cadCarro:  //Inicio menu Controle de carro
    menuCadCarro();
    	printf("\nSelecione uma das op��es do menu:\n");
	    scanf(" %d", &op);
	    printf("\n");	
	    fflush(stdin); //Limpar o buffer do teclado.
	    switch(op)
		{
		    case 1: 
		    	system("cls");
		        gravaCarro();
				system("cls");		   
		        goto cadCarro;
		        break;
		    case 2: 
		        system("cls");
		        if(cont_c==0 || (carro[c].estado==0)==0){
		        	printf("Nenhum carro cadastrado ou est�o todos alugados \n");
				}else{
					removeCarro();
					goto cadCarro;
				}
		        break;    
            case 3: 
            	system("cls");
		        listaCarroDisponivel();
		        goto cadCarro;
		        break;
		    case 4: 
		    	system("cls");
		        listaLocacao();
		        goto cadCarro;
		        break;
			case 0:
		        system("cls");
		        goto inicio; //Retorna ao menu inicial
		        break;	  
		    default:
		    	printf("Selecione uma das op��es contidas no menu acima .\n\n");
		    	system("\n\npause");
		    	system("cls");
		    	goto cadCarro; //Retorna ao menu de op��es
				break;
        }

}//Fim do main
//---------------------------------------------------------------------------------------------------------------------------------------
                                                       //Declara��o das Fun��es e cria��o dos Menus.
//---------------------------------------------------------------------------------------------------------------------------------------
void menuPrincipal() //Menu Principal
{
	printf("*********************************************************************************************************************\n");
	printf("*********************************************************************************************************************\n \n");
	printf("                      Seja bem vindo ao Sistema de loca��o de ve�culos da Legal Rent a Car.                          \n \n");
	printf("*********************************************************************************************************************\n");
	printf("*********************************************************************************************************************\n\n");
	
    printf("Menu Principal:\n\n");
    printf("(1) -> Controle de Carros. \n");
	printf("(2) -> Controle de Clientes. \n");
	printf("(3) -> Controle de Loca��es. \n");
	printf("(4) -> Fazer Devolu��o. \n");
	printf("(0) -> Sair do Sistema. \n\n");	
}
//Loca��o---------------------------------------------------------------------------------------------------------------------------------
void novaLocacao(){
	if((carro[c].estado==0)==0){
    		printf("Nenhum carro dispon�vel para alugar \n");
    		
		}else{
			do{
				contador_geral=1;
				listaCarroDisponivel();
		
		        printf("\n Numero em que o carro se encontra na lista:\n");  //----------Verificar escolha de carro----------
		        scanf("%d", &escolha_carro);
		        fflush(stdin);
		        c=escolha_carro-1;
		        carro[c].estado=1;
		        alugar[a].aplaca= carro[c].placa;
		       
		        system("cls");
		
		        printf("Placa do carro: %s \n", alugar[a].aplaca);
		        printf("Valor da di�ria para esse ve�culo: %.2f \n\n",carro[c].valorDiaria);
		
				printf("Digite a quantidade de diarias que deseja contratar: \n");
				scanf("%d", &diarias);
				
				valorAluguel = diarias  * carro[c].valorDiaria;
				printf("O cliente � empresa parceira da ONG? 1-Sim 0-N�o \n");
		        scanf("%d", &empresaParceira);
		        if(empresaParceira==1){
	        		printf("Por ser empresa parceira o cliente receber� um desconto de 5 por cento \n\n");
	        		desconto = 5.00;
				}
				system("pause");
                system("cls");			

				
				contador_geral=1;
				listaCliente();
				printf("\nNumero em que o cliente se encontra na lista:\n");  //----------Verificar escolha de cliente----------//Em andamento modificar numero da lista por CPF
                scanf("%d", &escolha_cliente);
                fflush(stdin);
                C=escolha_cliente-1;
                alugar[a].clienteCpf= cliente[C].cpf;
                system("cls");			
                
				printf("Digite o dia da loca��o: \n");					//Em andamento pesquisando fun��o para pegar data/hora automaticamente
				scanf("%d",&dia[0]);
				fflush(stdin);
				printf("Digite o m�s da loca��o: \n");
				scanf("%d",&mes[0]);
				fflush(stdin);
				printf("Digite o ano da loca��o: \n");
				scanf("%d",&ano[0]);
				fflush(stdin);
				printf("Digite a horas da locacao: \n");
				scanf("%d",&hora[0]);
				fflush(stdin);
				printf("Digite os minutos da locacao: \n");
				scanf("%d",&min[0]);
				fflush(stdin);
				printf("Digite o dia previsto da devolu��o: \n");
				scanf("%d",&dia[1]);
				fflush(stdin);
				printf("Digite o m�s previsto da devolu��o: \n");
				scanf("%d",&mes[1]);
				fflush(stdin);
				printf("Digite o ano previsto da devolu��o: \n");
				scanf("%d",&ano[1]);
				fflush(stdin);
				printf("Digite a horas prevista da devolu��o: \n");
				scanf("%d",&hora[1]);
				fflush(stdin);
				printf("Digite os minutos previsto da devolu��o: \n");
				scanf("%d",&min[1]);
				fflush(stdin);
				
		        
		        if(diarias >=5){
					printf("\n\n O cliente tem direito a uma di�ria gr�tis a mais, deseja utilizar esta cortesia? 1-Sim 2-N�o \n\n");
					scanf("%d", &cortesia);
					if(cortesia==1){
						printf("O cliente aderiu a cortesia \n\n");
						diarias = diarias + 1;
						dia[1] = dia[1] +1;
					}
				}
				
				if(cliente[C].idade >=65){
					printf("Pela idade do cliente ser maior que 65 ter� direito a desconto de 10% \n");
					desconto = 10.00;
				}
				descontoTotal = valorAluguel * (desconto/100);
				valorTotal = valorAluguel - descontoTotal;
				printf("Valor do Aluguel: %.2f \n", valorAluguel);
				if(desconto >0){
					printf("Valor sem desconto: %.2f \n", valorAluguel);
					printf("Valor com Desconto: %.2f \n ",descontoTotal);
				}
				
				printf("\nO Cliente efetuou o pagamento de %.2f ? 1-Sim 0-N�o \n ",valorTotal);
				scanf("%d", &op);
				while(op==0){
					printf("O sistema n�o pode concluir a loca��o enquanto n�o houver o pagamento do valor de %.2f \n",valorTotal); 		
					printf("O Cliente efetuou o pagamento de %.2f ? 1-Sim 0-N�o \n ",valorTotal);
					scanf("%d", &op);
				}
				
		        a++;
				system("cls");
				printf("****Ticket de Loca��o*****\n");
				printf("Nome do cliente: %s \n",cliente[C].nomec);
		        printf("CPF do cliente: %s \n",cliente[C].cpf);
		        printf("Endere�o do cliente: %s \n",cliente[C].endereco);
		        printf("Idade do cliente: %d \n",cliente[C].idade);
				printf("Di�rias Contratadas: %d \n",diarias);
				printf("Valor do Aluguel(Pago): %.2f \n",valorTotal);
				printf("Data da Loca��o: %d/%d/%d \n",dia[0],mes[0],ano[0]);
				printf("Hora da Loca��o: %d:%d \n",hora[0],min[0]);
				printf("Data de devolu��o prevista: %d/%d/%d \n",dia[1],mes[1],ano[1]);
				printf("Hora prevista da devolu��o: %d:%d \n",hora[1],min[1]);
				cont_a++;
		        printf("\nAluguel cadastrado com sucesso!\n");
		        printf("\n1 - Continuar cadastrando\n0 - Menu princial\n");
		        scanf("%d", &continuar);
		        fflush(stdin);
    	
		    }while (continuar!=0 && continuar==1 && cont_a<1000 && (carro[c].estado==0)==1);  //----------Valida��o do continuar
		    if (continuar!=0 && continuar!=1){
		        printf("\n*****************OPCAO INVALIDA*****************\n\n\a");
		    }if (cont_a==1000){                                //----------Verifica��o da quantidade de cadastros
		        printf("\n*************Numero maximo de alugueis cadastrados atingido!*************\n\n\a");
		    }if (cont_c==0){
		        printf("\n*************Nenhum carro cadastrado!*************\n\n\a");
		}
	}
}

//---------------------------------------------------------------------------------------------------------------------------------------
void cadastrarDevolucao(){
	if((carro[c].estado==1)==0){
    		printf("Nenhum carro alugado para devolver \n");
	}else{
		do{
			listaLocacao();
			
			printf("Digite o numero em que a loca��o se encontra na lista:\n");			//Em andamento pesquisar por placa
			scanf("%d", &escolhaCar);
			fflush(stdin);
	        d=escolhaCar-1;
	        carro[c].estado=0;															//muda o estado para disponivel
	        devolucao[d].placaCar = carro[c].placa;
	        system("cls");
	    
	        printf("Placa do carro: %s \n", devolucao[d].placaCar);
					
	        //Manipula��o de horas
			int mintotal(int hora, int minuto) {
				int r = (hora*60) + minuto;
				return r;
			}
			int r1,r2, total,horas; //variaveis declaradas
			
			r1 = mintotal(hora[1],min[1]);
			
			printf("Digite o dia da devolu��o: \n");
			scanf("%d",&dia[2]);
			fflush(stdin);
			printf("Digite o m�s da devolu��o: \n");
			scanf("%d",&mes[2]);
			fflush(stdin);
			printf("Digite o ano da devolu��o: \n");
			scanf("%d",&ano[2]);
			fflush(stdin);
			printf("Digite a horas da devolu��o: \n");
			scanf("%d",&hora[2]);
			fflush(stdin);
			printf("Digite o minutos da devolu��o: \n");
			scanf("%d",&min[2]);
			fflush(stdin);
			
			r2 = mintotal(hora[2],min[2]);
			total = r2-r1;
			horas = total/60;
			if (total < 0){
				total +=1440; //calculo
				printf ("%d Horas de diferenca!\n\n", horas);} //impress�o do resultado
			else printf ("%d Horas de diferenca!\n\n", horas); //impress�o do resultado
			
			if(horas>0){
				multa=diarias*(horas/24); 
				printf("Por haver atraso na devolu��o o cliente receber� uma multa de: %.2f \n",multa);
			}
			
			printf("O Cliente efetuou o pagamento de %.2f ? 1-Sim 0-N�o \n ",multa);
			scanf("%d", &op);
			while(op==0){
				printf("O sistema n�o pode concluir a devolu��o enquanto n�o houver o pagamento da multa por atraso de %.2f \n",multa);		//nao aparece o valor da multa, em andamento
				printf("O Cliente efetuou o pagamento de %.2f ? 1-Sim 0-N�o \n ",multa);
				scanf("%d", &op);
			}
        	d++;
			cont_a--;
			carro[c].estado=0;
			
			system("pause");
			printf("Devolu��o feita com sucesso! \n\n");
			printf("\n1 - Continuar devolvendo carros \n 0 - Menu princial\n");
	        scanf("%d", &continuar);
	        fflush(stdin);

		}while (continuar!=0 && continuar==1 && cont_a>0);  //----------Valida��o do continuar
	    if (continuar!=0 && continuar!=1){
	        printf("\n*****************OPCAO INVALIDA*****************\n\n\a");
	    }
	}
}

//---------------------------------------------------------------------------------------------------------------------------------------
void menuControleDevolucao() //Menu controle de devolucao
{
	printf("*********************************************************************************************************************\n");
	printf("*********************************************************************************************************************\n \n");
	printf("                      Seja bem vindo ao Sistema de loca��o de ve�culos da Legal Rent a Car.                          \n \n");
	printf("*********************************************************************************************************************\n");
	printf("*********************************************************************************************************************\n\n");
    printf("*****Controle de Devolu��o*****\n\n");
	printf("(1) -> Devolver Carro. \n");
	printf("(2) -> Listar Devolu��es . \n");
	printf("(0) -> Voltar ao menu Anterior. \n");
}

//---------------------------------------------------------------------------------------------------------------------------------------
void menuDevolucao()
{
	printf("*********************************************************************************************************************\n");
	printf("*********************************************************************************************************************\n \n");
	printf("                      Seja bem vindo ao Sistema de loca��o de ve�culos da Legal Rent a Car.                          \n \n");
	printf("*********************************************************************************************************************\n");
	printf("*********************************************************************************************************************\n\n");
	printf("*****Controle de Devolu��o***** \n\n");
	printf("(1) -> Cadastrar devolu��o \n");
	printf("(0) -> Menu Principal \n");
}
//---------------------------------------------------------------------------------------------------------------------------------------

void menuControleLocacao() //Menu controle de loca��o
{
	printf("*********************************************************************************************************************\n");
	printf("*********************************************************************************************************************\n \n");
	printf("                      Seja bem vindo ao Sistema de loca��o de ve�culos da Legal Rent a Car.                          \n \n");
	printf("*********************************************************************************************************************\n");
	printf("*********************************************************************************************************************\n\n");
    printf("*****Controle de Aloca��o*****\n\n");
	printf("(1) -> Cadastrar novo Aluguel. \n");
	printf("(2) -> Listar Loca��es . \n");
	printf("(0) -> Voltar ao menu Anterior. \n");
}

//---------------------------------------------------------------------------------------------------------------------------------------
void menuCadCarro() //Menu Controle de carro
{
	printf("*********************************************************************************************************************\n");
	printf("*********************************************************************************************************************\n \n");
	printf("                      Seja bem vindo ao Sistema de loca��o de ve�culos da Legal Rent a Car.                          \n \n");
	printf("*********************************************************************************************************************\n");
	printf("*********************************************************************************************************************\n\n");
    printf("*****Controle de Carros*****\n\n");
	printf("(1) -> Incluir Novo carro. \n");
	printf("(2) -> Remover Carro. \n");
	printf("(3) -> Listar Carros Dispon�veis. \n");
	printf("(4) -> Listar Carros Alugados. \n");
	printf("(0) -> Voltar ao Menu Anterior. \n");
}
//---------------------------------------------------------------------------------------------------------------------------------------
void menuCadCliente() //Menu Controle de clientes
{
	printf("*********************************************************************************************************************\n");
	printf("*********************************************************************************************************************\n \n");
	printf("                      Seja bem vindo ao Sistema de loca��o de ve�culos da Legal Rent a Car.                          \n \n");
	printf("*********************************************************************************************************************\n");
	printf("*********************************************************************************************************************\n\n");
    printf("*****Controle de Clientes*****\n\n");
	printf("(1) -> Incluir Novo Registro. \n");
	printf("(2) -> Remover Registro. \n");
	printf("(3) -> Listar Clientes\n");
	printf("(0) -> Voltar ao Menu Anterior. \n");
}

//---------------------------------------------------------------------------------------------------------------------------------------
void gravaCarro() //Fun��o para gravar registro de carro
{		
	do{			
			
			printf("Digite a marca do carro:\n");
	        gets (carro[c].marca);
	        fflush(stdin);
	        printf("Digite o modelo do carro:\n");
	        gets (carro[c].modelo);
	        fflush(stdin);
	        printf("Digite a cor do carro:\n");
	        gets (carro[c].cor);
	        fflush(stdin);
	        printf("Digite o ano do carro:\n");
	        scanf("%d", &carro[c].ano);
	        fflush(stdin);
	        printf("Digite a placa do carro:\n");
	        gets (carro[c].placa);
	        fflush(stdin);
	        printf("Digite o valor da di�ria para este ve�culo:\n");
	        scanf("%f", &carro[c].valorDiaria);
	        fflush(stdin);
	        
	        c++;
	        cont_c ++;
	        carro[c].estado=0; //----------Coloca o carro como disponivel para alugar----------
	
	        printf("\nCarro cadastrado com sucesso!\n");
	        printf("\n1 - Continuar cadastrando\n0 - Menu princial\n");
	        scanf("%d", &continuar);
	        fflush(stdin);
	        if (cont_c==1000){                                //----------Verifica��o da quantidade de cadastros
        		printf("\n*************Numero maximo de carros cadastrados atingido!*************\n\n\a");
   			}
	    	if (continuar!=0 && continuar!=1){
   				printf("\n*****************OPCAO INVALIDA*****************\n\n\a");
			}
	}while (continuar!=0 && continuar==1 && cont_c<1000);  //----------Valida��o do continuar
	
	
}
//---------------------------------------------------------------------------------------------------------------------------------------
void listaLocacao(){
	for(a=0;a<cont_a;a++){
		if(carro[c].estado==1){
	    printf("***********Loca��es************\n");
	    printf("Numero - %d\n", contador_geral);
	    printf("Modelo:%s \n", carro[c].modelo);
	    printf("Marca:%s \n", carro[c].marca);
	    printf("Placa:%s \n", carro[c].placa);
	    printf("Ano:%d \n", carro[c].ano);
	    printf("Cor:%s \n", carro[c].cor);
	    printf("Pre�o da diaria:%.2f \n", carro[c].valorDiaria);
	    printf("Dados do cliente que esta alugando: ");
	    printf("Nome do cliente: %s \n", cliente[C].nomec);
		printf("CPF do cliente: %s \n",cliente[C].cpf);
        printf("Endere�o do cliente: %s \n",cliente[C].endereco);
        printf("Idade do cliente: %d \n",cliente[C].idade);
		printf("Di�rias Contratadas: %d \n",diarias);
		printf("Valor do Aluguel(Pago): %.2f \n",valorTotal);
		printf("Data da Loca��o: %d/%d/%d \n",dia[0],mes[0],ano[0]);
		printf("Hora da Loca��o: %d:%d \n",hora[0],min[0]);
		printf("Data de devolu��o prevista: %d/%d/%d \n",dia[1],mes[1],ano[1]);
		printf("Hora prevista da devolu��o: %d:%d \n",hora[1],min[1]);
	    printf("***********************\n");
	    contador_geral ++;
    	}
    	if((carro[c].estado==1)==0){
    		printf("Nenhum carro alugado \n");
    		system("pause");
		}
    	contador_geral=1;
    	printf("\n\n***************Fim do relat�rio.***************\n\n");
		system("pause");
	}
	if((carro[c].estado==1)==0){
    		printf("Nenhum carro alugado \n");
    		system("pause");
		}
}
//---------------------------------------------------------------------------------------------------------------------------------------

void listaCarroDisponivel()
{
    for(c=0 ; c<cont_c ; c++){
	    if(carro[c].estado==0){
	    printf("***********Carros Dispon�veis************\n");
	    printf("Numero - %d\n", contador_geral);
	    printf("Modelo:%s \n", carro[c].modelo);
	    printf("Marca:%s \n", carro[c].marca);
	    printf("Placa:%s \n", carro[c].placa);
	    printf("Ano:%d \n", carro[c].ano);
	    printf("Cor:%s \n", carro[c].cor);
	    printf("Pre�o da diaria:%2.2f \n", carro[c].valorDiaria);
	    printf("***********************\n");
	    contador_geral ++;
	    
    	}
    	if((carro[c].estado==0)==0){
    		printf("Nenhum carro dispon�vel \n");
    		system("pause");
		}
    	contador_geral=1;

	}
	printf("\n\n***************Fim do relat�rio.***************\n\n");
	system("pause");	 
}
//---------------------------------------------------------------------------------------------------------------------------------------
void removeCliente(){
	do{
		listaCliente();
		printf("Remover Cliente \n\n");
		printf("Digite o numero em que o cliente se encontra na lista:\n");
		scanf("%d", &escolha);
		fflush(stdin);
        C=escolha-1;
        printf("Deseja realmente remover este cliente 1-Sim 0-N�o \n");
        scanf("%d",&op);
        if(op==0){
        	printf("Remo��o cancelada \n");
        	system("pause");
		}else{
	        C--;
	        cont_C--;
	        printf("Cliente removido com sucesso \n");
			printf("\n1 - Continuar removendo\n0 - Menu princial\n");
	        scanf("%d", &continuar);
	        fflush(stdin);
	    
	    	if (continuar!=0 && continuar!=1){
				printf("\n*****************OPCAO INVALIDA*****************\n\n\a");
			}
		}
	}while (continuar!=0 && continuar==1 && cont_C>0);
}
//---------------------------------------------------------------------------------------------------------------------------------------
void removeCarro(){
	do{
		listaCarroDisponivel();
		printf("Remover Carro \n\n");
		printf("Digite o numero em que o carro se encontra na lista:\n");
		scanf("%d", &escolha);
		fflush(stdin);
        c=escolha-1;
        if(carro[c].estado==1){
        	printf("Carro alugado no momento, devolva-o primeiro para continuar \n");
		}else{
	        printf("Deseja realmente remover este carro 1-Sim 0-N�o \n");
	        scanf("%d",&op);
	        if(op==0){
	        	printf("Remo��o cancelada \n");
	        	system("pause");
			}else{
		        c--;
		        cont_c--;
		        printf("Carro removido com sucesso \n");
				printf("\n1 - Continuar removendo\n0 - Menu princial\n");
		        scanf("%d", &continuar);
		        fflush(stdin);
		    
		    	if (continuar!=0 && continuar!=1){
					printf("\n*****************OPCAO INVALIDA*****************\n\n\a");
				}
			}
		}
	}while (continuar!=0 && continuar==1 && cont_c>0);
}
//---------------------------------------------------------------------------------------------------------------------------------------
void gravaCliente() //Fun��o para gravar registro de Clientes
{
	do{                	
	        printf("Digite o nome completo:\n");
	        gets(cliente[C].nomec);
	        fflush(stdin);
	
	        printf("Digite o CPF do cliente:\n");
	        gets(cliente[C].cpf);
	        fflush(stdin);
	        
	        printf("Digite a idade do cliente:\n");
	        scanf("%d", &cliente[C].idade);
	        fflush(stdin);
	
	        printf("Digite seu endere�o: ");
	        gets(cliente[C].endereco);
	        fflush(stdin);
	
	        cont_C ++;
	        C++;
	
	        printf("\nCliente cadastrado com sucesso!\n");
	        printf("\n1 - Continuar cadastrando\n0 - Menu anterior\n");
	        scanf("%d", &continuar);
	        fflush(stdin);
	        	
			if (cont_C==1000){                                //----------Verifica��o da quantidade de cadastros
        		printf("\n*************Numero maximo de clientes cadastrados atingido!*************\n\n\a");
   			}
   			if (continuar!=0 && continuar!=1){
   				printf("\n*****************OPCAO INVALIDA*****************\n\n\a");
			}
    }while (continuar!=0 && continuar==1 && cont_c<1000);  //----------Valida��o do continuar
}
    
//---------------------------------------------------------------------------------------------------------------------------------------
void listaCliente()
{
	for(C=0 ; C<cont_C ; C++){
			printf("N�mero do cliente na lista: %d \n", contador_geral);
			printf("Nome: %s\n", cliente[C].nomec);	
	        printf("CPF: %s\n", cliente[C].cpf);
	        printf("Endere�o: %s\n", cliente[C].endereco);
	        printf("Idade:%d \n",cliente[C].idade);
	        contador_geral ++;
    }
    printf("**************************\n");
    contador_geral=1;
	printf("\n\n***************Fim do relat�rio.***************\n\n");
	system("pause");	 
}
//---------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------------
void abnt_br() //Esta fun��o ajusta a sa�da do texto para aceitar caracteres especiais ou acentos do idioma portugu�s BR.
{
    setlocale(LC_ALL, "Portuguese_Brazil"); 
}
//---------------------------------------------------------------------------------------------------------------------------------------
void telaCheia()//Esta fun��o vai "enviar" um alt+enter e inicar em tela cheia.
{
    keybd_event ( VK_MENU, 0x36, 0, 0 ); 
    keybd_event ( VK_RETURN, 0x1C, 0, 0 ); 
    keybd_event ( VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0 ); 
    keybd_event ( VK_MENU, 0x38, KEYEVENTF_KEYUP, 0 );	
}
//---------------------------------------------------------------------------------------------------------------------------------------
void limpaBuffer() // fun��o personalizada para limpeza de buffer do teclado
{
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}

//---------------------------------------------------------------------------------------------------------------------------------------

//Feito por Aline Gomes de Brito
