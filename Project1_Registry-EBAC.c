#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca��es de texto por regiao
#include <string.h> //biblioteca para strings

int registerUser(){ //fun��o respons�vel por criar os usu�rios no sistema;
	char userFile[40]; //variavel que ser� o nome 'arquivo criado'
	char cpf[40]; //variavel para salvar o cpf
	char name[40];  //variavel para salvar o nome
	char surname[40];  //variavel para salvar o sobrenome
	char role[40];  //variavel para salvar o cargo
	char userOption[1];// vari�vel para salvar a op��o do usu�rio
	
	printf("\nType a CPF number below:\n"); //imprimo na tela a mensagem 
	scanf("%s", cpf); //salvo o input do tipo %s(string) na variavel cpf
	
	strcpy(userFile, cpf); //com o strcpy indico que a variavel userFIle ter� o mesmo valor que a cpf
	
	FILE *file; //fun��o nativa FILE - *file indica cria��o de um novo documento
	file = fopen(userFile, "w"); // o file rec�m criado recebe o fopen (nome do documento, "write" - no caso de novo;
	fprintf(file, cpf); //dentro do arquivo aberto, printo (file, variavel que quero salvar)
	fclose(file); // fecho o arquivo
	
	file = fopen(userFile, "a"); //file recebe fopen (qual arquivo quero abrir, "a" - para acrescimo)
    fprintf(file, ","); // (file, texto que quero acrescentar)
	fclose(file);  // fecho o arquivo
	
	
	//mesmo caminho, agora acrescentando no arquivo o nome do usuario digitado
	printf("\nType a name below:\n");
	scanf("%s", name);
	file = fopen(userFile, "a");
    fprintf(file, name);
	fclose(file);  
	
	file = fopen(userFile, "a");
    fprintf(file, ",");
	fclose(file); 

    //mesmo caminho, agora acrescentando no arquivo o sobrenome digitado
    printf("\nType a surname below:\n");
	scanf("%s", surname);
	file = fopen(userFile, "a");
    fprintf(file, surname);
	fclose(file);
	
	file = fopen(userFile, "a");
    fprintf(file, ",");
	fclose(file); 
	
	//mesmo caminho, agora acrescentando no arquivo o cargo digitado
	printf("\nType a role below:\n");
	scanf("%s", role);
	file = fopen(userFile, "a");
    fprintf(file, role);
	fclose(file);
	
	printf("\nUser saved successfully!\n\n"); //mensagem para indicar ao usu�rio que foi salvo
    
int registerAnother() {
	printf("\nDo you want to register another user? (Y / N) \n\n"); //imprimo a mensagem na tela
	scanf("%s", userOption); //capturo a op��o do usuario
	
	userOption[0] = tolower(userOption[0]); //transformo a op��o do usuario sempre em minuscula, para padronizar
        
        if (strcmp(userOption, "y") == 0) {//compara a op��o do usuario com o termo "y". Se o resultado for zero (igual)
           registerUser(); //volto para o in�cio da fun��o
        }
        else if (strcmp(userOption, "n") == 0) {//compara a op��o do usuario com o termo "n". Se o resultado for zero (igual)
           main(); //volta para o menu principal
        }
        else {//se nenhuma das op��es anteriores..
           printf("This option is not available.\n");//imprimo a mensagem na tela
           registerAnother();
        }
        system("pause");}
    registerAnother();
 
    system("pause");
}

int consultUser(){//fun��o respons�vel por consultar usu�rios no sistema;
	
	setlocale (LC_ALL, "Portuguese"); //para utilizar acentos, preciso trazer novamente a biblioteca
	
    char cpf[40]; //var para salvar o cpf
    char content[200]; //var para salvar o conteudo do file
    char *t;  //var para fazer o looping nas informa��es obtidas no arquivo
    char *number; //var para salvar o numero do cpf, a partir do looping
    char *name; //var para salvar o nome, a partir do looping
    char *surname; //var para salvar o sobrenome, a partir do looping
    char *role; //var para salvar a fun��o, a partir do looping
    
    printf("\nType a CPF number:\n"); //imprimo na tela a mensagem 
    scanf("%s", cpf); //salvar o input na vari�vel
    
    FILE *file; //chamo a fun��o de arquivo
    file = fopen(cpf, "r"); //abro o arquivo (nome do file, "r" para read)
    
    if(file == NULL){ //se n�o houver correspond�ncia (CPF n�o valido)
    	printf("\nNo user found\n\n"); //imprimo que n�o foi localizado
	} 
	
	
    while (fgets(content, 200, file) != NULL){//enquanto a fun��o nativa fgets 
	    //(pega o conteudo do file e salva na var, at� 200 caract, vindo do arquivo file)
	    // != NULL enquanto houver conte�do
	    printf("\nUser information:\n\n"); //imprimo na tela a mensagem 
	    t = strtok (content, ","); //defino que a var T vai receber o primeiro 'token' antes do par�metro dado (virgula)
	    
	    int i=0; //var para o looping
	    while (t !=NULL) { //enquanto houver conte�do no t;
	    switch (i){ //fa�o o switch case
	    	case 0: //primeiro token (antes da virgula) - salvo na var number
			  number = t;
	          break;
	        case 1: //segundo token (antes da virgula) - salvo na var name
			  name = t;
	          break;
	        case 2: //terceiro token (antes da virgula) - salvo na var surname
			  surname = t;
	          break;
	        case 3: //quarto token - salvo na var role
			  role = t;
	          break;
			};
		t = strtok (NULL, ","); // para zerar o t ap�s o looping
		i++; //incremetador para rodar o looping
		}
		fclose(file);
		
		printf ("CPF:%s\n", number); //imprimo na tela a mensagem + var
		printf ("Name:%s\n", name); //imprimo na tela a mensagem + var
		printf ("Surname:%s\n", surname); //imprimo na tela a mensagem + var
		printf ("Role:%s\n", role); //imprimo na tela a mensagem + var
		printf("\n\n");
		}
	    
        system("pause");
	} 
    
	


int deleteUser(){ //fun��o para deletar o usu�rio
	char cpf[40]; //var para salvar o cpf
	char *t; //var para fazer o looping nas informa��es obtidas no arquivo
	char *number; //var para salvar o numero do cpf, a partir do looping
    char *name; //var para salvar o nome, a partir do looping
    char *surname; //var para salvar o sobrenome, a partir do looping
    char userOption[1]; //var para salvar a op��o do usuario (com limite de 1 caractere)
    char content[200];  //var para salvar o conteudo do file
	
    printf("\nType a CPF number to delete:\n");
    scanf("%s", cpf); //salvar o input (string) na vari�vel

    
    FILE *file; //chamo a fun��o de arquivo
    file = fopen(cpf, "r");
    
    if(file == NULL){ //se o arquivo n�o for encontrado
        printf("\nUser not found\n\n");//imprimo na tela a mensagem
        return 0;
        system("pause"); 
    }
    
        while (fgets(content, 200, file) != NULL){ // fun��o para garavar no content o conte�do do file lido
	    
	      t = strtok (content, ","); //defino que a var T vai receber o primeiro 'token' antes do par�metro dado (virgula)
	    
	      int i=0; // looping para salvar os dados nas vari�veis
	      while (t !=NULL) {
	      switch (i){
	    	case 0:
			  number = t;
	          break;
	        case 1:
			  name = t;
	          break;
	        case 2:
			  surname = t;
	          break;
			};
	   	  t = strtok (NULL, ",");
		  i++;
		  }
        fclose(file);
		
        printf("\nAre you sure you want to delete "); //imprimo a mensagem na tela
	    printf("%s ", name); 
	    printf("%s", surname);
        printf("? (Y / N) \n\n");
        
        scanf("%s", userOption); // gravo a resposta do usuario
        
        userOption[0] = tolower(userOption[0]); //transformo a op��o do usuario sempre em minuscula, para padronizar
        
        if (strcmp(userOption, "y") == 0) {//compara a op��o do usuario com o termo "y". Se o resultado for zero (igual)
           remove(cpf); //deleto o arquivo
           printf("\nUser deleted successfully!\n\n"); //imprimo a mensagem na tela  
           system("pause"); 
        }
        else if (strcmp(userOption, "n") == 0) {//compara a op��o do usuario com o termo "n". Se o resultado for zero (igual)
           deleteUser();//retomo a fun��o desde o in�cio 
           return 0;
        }
        else {//se nenhuma das op��es anteriores..
           printf("This option is not available.\n");//imprimo a mensagem na tela
           deleteUser();//retomo a fun��o desde o in�cio 
           return 0;
        }

        }   

     }


int main(){ //fun��o principal executada automaticamente
	
	int input=0; //vari�vel para guardar a op��o digitada pelo usu�rio
	
	int x=1;
	//para que o looping n�o pare: x � 1, e o loop roda enquanto x for 1 (sempre)
	//coloco o FOR aqui para, ao final da execu��o da fun��o, ela se repetir e reiniciar deste ponto
	//assim que o usu�rio terminar a opera��o, voltar� � tela inicial do menu 
	
	for(x=1;x=1;) 
	{   
	    system("cls"); //para limpar a tela ap�s o looping

    	setlocale (LC_ALL, "Portuguese"); //para informar a regi�o - assim ele aceitar� acentos

  	    printf("### Cart�rio EBAC ### \n\n"); //t�tulo - #para ornamento
	    printf ("Choose an option: \n\n");
	    printf("\t1 - User Register\n"); // \t serve para dar uma espa�o pr�vio
	    printf("\t2 - User Consult\n");
	    printf("\t3 - User Delete\n\n\n");
	    printf("Type your option:\n");
	
	    scanf("%d", &input); //puxar a informa��o dada pelo usuario
	
	    system("cls"); //comando para limpar a tela
	    
	    switch(input) //pego o input para compara��o
		{
	    	case 1: //no caso de o input for 1, dou as instru��es com os :
	            registerUser();
		    break; //o break serve para fechar o pacote de instru��es
		    case 2:
	    	    consultUser();
		    break;
		    case 3: 
	    	    deleteUser();
		    break;
		    
		    default: //no caso de o input n�o ser nenhuma das citadas
			    printf("This option is not available.\n\n");
		        system("pause");
		    break;
		    
		};
	};
	
	//printf("Este software � de livre uso.\n");
}


