#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocações de texto por regiao
#include <string.h> //biblioteca para strings

int registerUser(){
	char userFile[40]; //variavel que será o nome 'arquivo criado'
	char cpf[40]; //variavel para salvar o cpf
	char name[40];  //variavel para salvar o nome
	char surname[40];  //variavel para salvar o sobrenome
	char role[40];  //variavel para salvar o cargo
	
	printf("\nType a CPF number below:\n"); 
	scanf("%s", cpf); //salvo o input do tipo %s(string) na variavel cpf
	
	strcpy(userFile, cpf); //com o strcpy indico que a variavel userFIle terá o mesmo valor que a cpf
	
	FILE *file; //função nativa FILE - *file indica criação de um novo documento
	file = fopen(userFile, "w"); // o file recém criado recebe o fopen (nome do documento, "write" - no caso de novo;
	fprintf(file, cpf); //dentro do arquivo aberto, printo (file, variavel que quero salvar)
	fclose(file); // fecho o arquivo
	
	file = fopen(userFile, "a"); //file recebe fopen (qual arquivo quero abrir, "a" - para acrescimo)
    fprintf(file, ","); // (file, texto que quero acrescentar)
	fclose(file);  // fecho o arquivo
	
	
	//mesmo caminho, agora acrescentando no arquivo o nome digitado
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
	
	printf("\nUser saved successfully!\n\n");
    
	system("pause");
}

int consultUser(){
	
	setlocale (LC_ALL, "Portuguese"); //para utilizar acentos, preciso trazer novamente a biblioteca
	
    char cpf[40]; //var para salvar o cpf
    char content[200]; //var para salvar o conteudo do file
    char *t; 
    char *number;
    char *name;
    char *surname;
    char *role;
    
    printf("\nType a CPF number:\n");
    scanf("%s", cpf); //salvar o input na variável
    
    FILE *file; //chamo a função de arquivo
    file = fopen(cpf, "r"); //obro o arquivo (nome do file, "r" para read)
    
    if(file == NULL){ //se não houver correspondência (CPF não valido)
    	printf("\nNo user found\n\n"); //imprimo que não foi localizado
	} 
	
	
    while (fgets(content, 200, file) != NULL){//enquanto a função nativa fgets 
	    //(pega o conteudo do file e salva na var, até 200 caract, vindo do arquivo file)
	    // != NULL enquanto houver conteúdo
	    printf("\nUser information:\n\n");
	    t = strtok (content, ",");
	    
	    int i=0;
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
	        case 3:
			  role = t;
	          break;
			};
		t = strtok (NULL, ",");
		i++;
		}
		printf ("CPF:%s\n", number);
		printf ("Name:%s\n", name);
		printf ("Surname:%s\n", surname);
		printf ("Role:%s\n", role);
		printf("\n\n");
		}
	    
        system("pause");
	} 
    
	


int deleteUser(){
	char cpf[40]; //var para salvar o cpf
	char *t;
	char *number;
    char *name;
    char *surname;
    char userOption[1];
    char content[200];
	
    printf("\nType a CPF number to delete:\n");
    scanf("%s", cpf); //salvar o input (string) na variável
    
    FILE *file; //chamo a função de arquivo
    file = fopen(cpf, "r");
    
    if(file == NULL){
         printf("\nUser not found\n\n");
    }
    while (fgets(content, 200, file) != NULL){
	    
	    t = strtok (content, ",");
	    
	    int i=0;
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
        printf("\nAre you sure you want to delete ");
	    printf("%s ", name);
	    printf("%s", surname);
        printf("? (Y / N) \n\n");
        
        scanf("%s", userOption);
        
        userOption[0] = tolower(userOption[0]);
        
        if (strcmp(userOption, "y") == 0) {
           remove(cpf);
           printf("\nUser deleted successfully!\n\n");
        }
        else if (strcmp(userOption, "n") == 0) {
           deleteUser();
        }
        else {
           printf("This option is not available.\n");
           deleteUser();
        }

        }
	     system("pause");    
     }


int main(){ //função principal executada automaticamente
	
	int input=0; //variável para guardar a opção digitada pelo usuário
	
	int x=1;
	//para que o looping não pare: x é 1, e o loop roda enquanto x for 1 (sempre)
	//coloco o FOR aqui para, ao final da execução da função, ela se repetir e reiniciar deste ponto
	//assim que o usuário terminar a operação, voltará à tela inicial do menu 
	
	for(x=1;x=1;) 
	{   
	    system("cls"); //para limpar a tela após o looping

    	setlocale (LC_ALL, "Portuguese"); //para informar a região - assim ele aceitará acentos

  	    printf("### Cartório EBAC ### \n\n"); //título - #para ornamento
	    printf ("Choose an option: \n\n");
	    printf("\t1 - User Register\n"); // \t serve para dar uma espaço prévio
	    printf("\t2 - User Consult\n");
	    printf("\t3 - User Delete\n\n\n");
	    printf("Type your option:\n");
	
	    scanf("%d", &input); //puxar a informação dada pelo usuario
	
	    system("cls"); //comando para limpar a tela
	    
	    switch(input) //pego o input para comparação
		{
	    	case 1: //no caso de o input for 1, dou as instruções com os :
	            registerUser();
		    break; //o break serve para fechar o pacote de instruções
		    case 2:
	    	    consultUser();
		    break;
		    case 3: 
	    	    deleteUser();
		    break;
		    
		    default: //no caso de o input não ser nenhuma das citadas
			    printf("This option is not available.\n\n");
		        system("pause");
		    break;
		    
		};
	};
	
	//printf("Este software é de livre uso.\n");
}


