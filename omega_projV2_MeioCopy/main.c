#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "lifo.h"

/*
GRUPO: OMEGA
- Igor do Nascimento Alves RA:22.216.004-6
- Thyago Melo dos Santos   RA:22.216.020-2
Versao 2 - MeioCopy - 22/05/2019
*/

char **alocaMatriz2();
void carregaMatriz(char **matriz, char *nomeHD, int blocos, int bytes);
void carrega(char ***matriz, char *nomeHD, int blocos, int bytes);
void reescreveConfig();
void realocaMatrizHD(char ***matrizHD, int *qtHd, int ***matrizTamHd);
void desalocaMatriz2(char **matriz, int c);
int **alocaMatrizInt(int l, int c);
void desalocaMatrizInt2(int **matriz, int blocos);
int binario1Bloco(int pos);
int binario2Bloco(int pos);

char *IntToBinary16bits(int entrada);
int Binary08bitsToInt(char *entrada);
int Binary16bitsToInt(char *entrada);
char *IntToBinary08bits(int entrada);
void imprimir(int num, int size, char *saida);
void info();
void type(char **matriz, int blocos, int bytes, char *nome);
void del(char **matriz, int blocos, int bytes, char *nome, char* EstadoAtual);

void all(){
	printf("Para obter masi informa��es sobre um comando especifico, digite help [nome_comando].\n\n");
	printf("createhd\t\t Serve para criar um novo HD Virtual.\n");
	printf("typehd\t\t\t Exibe conteudo do HD Virtual no formato caracter e hexadecimal.\n");
	printf("selecthd\t\t Serve para selecionar um HD.\n");
	printf("dirhd\t\t\t Serve para exibir a lista dos HDs que j� foram criados pelo sistema.\n");
	printf("formathd\t\t Serve para formatar um HD previamente criado inicializando os blocos com seus valores\n\t\t\t iniciais como no momento de sua criacao.\n");
	printf("cd\t\t\t Serve para selecionar um diretorio (pasta) alterando o prompt de acordo com a pasta seleciona.\n\n");
	printf("cls\t\t\t Serve para limpar a tela da interface de comandos.\n");
	printf("create\t\t\t Permite a cria�ao de um arquivo texto.\n");
	printf("del\t\t\t Exclui um arquivo.\n\n");
	printf("dir\t\t\t Serve para exibir a lista de arquivos de uma determinadda pasta incluindo o tamanho dos\n \t\t\t arquivos em numeros de bytes.\n");
	printf("mkdir\t\t\t Cria um diret�rio (pasta).\n\n");
	printf("type\t\t\t Serve para exibir o conteudo de um arquivo. Da uma pausa quando preencher uma tela.\n\n");
	printf("statushd\t\t Exibe propriedades (espaco) HD VIRTUAL.\n");
	printf("removehd\t\t Remove HD VIRTUAL.\n\n");
	printf("copyfrom\t\t Copia arquivo jpg do HD real para o HD VIRTUAL.\n");
	printf("copyto\t\t\t Copia arquivo jpg do HD VIRTUAL para o HD REAL.\n\n");
	printf("rename\t\t\t Altera o nome de um arquivo.\n");
	printf("rmdir\t\t\t Remove diretorio(pasta) e todo o seu conteudo.\n");
	printf("renamedir\t\t Altera o nome de uma pasta.\n\n");
	printf("copy\t\t\t Copia um arquivo ou arquivos de uma pasta para uma pasta de destino.\n\n");
	printf("move\t\t\t Move um arquivo ou pasta (e todo o seu conteudo) para outra pasta.\n\n");
	printf("help\t\t\t Ajuda ou help sobre os comandos.\n\n");
	printf("tree\t\t\t Exibe graficamente a estrutura de diretorios(pastas).\n");
	
}

void help(char *comando){

	if(!strcmp(comando,"all")){
		all();
	}else{
		if(!strcmp(comando, "createhd")){
		    printf("Cria um novo HD Virtual.\n\n");
		    printf("createhd [nome][numm blocos][tam bloco]\n\n");
		    printf("\t[nome] = nome do HD\n");
		    printf("\t[num bloco] = numero de blocos do HD\n");
		    printf("\t[tam blocos] = tamanho de cada bloco\n ");
		}else{
			if(!strcmp(comando, "typehd")){
				printf("Exibe conteudo do HD Virtual no formato caracter e hexadecimal\n\n");
				printf("typehd[nome do hd]\n\n");
				printf("\t[nome do hd] = nome do HD\n");
			}else{
				if(!strcmp(comando, "selecthd")){
                    printf("Serve para selecionar um HD\n\n");
					printf("selecthd[nome do hd]\n\n");
					printf("\t[nome do hd] = nome do HD\n");
				}else{
                    if(!strcmp(comando, "dirhd")){
	                    printf("Serve para exibir a lista dos HDs que ja foram criados pelo sistema\n\n");
						printf("dirhd\n\n");
					}else{
                        if(!strcmp(comando, "formathd")){
							printf("Serve para formatar um HD VIRTUAL\n");
							printf("formathd[nome do hd]\n\n");
							printf("[nome do hd] = nome do HD");
						}else{
							if(!strcmp(comando, "cd")){
								printf("Serve para selecionar um diret�rio\n");
								printf("cd[nome da pasta]\n\n");
								printf("[nome da pasta] = nome da pasta\n");
							}else{
								if(!strcmp(comando, "cls")){
									printf("Serve para limpar a tela da interface de comandos\n");
									printf("cls\n\n");
								}else{
									if(!strcmp(comando, "create")){
										printf("Permite a criacao de um arquivo texto\n");
										printf("[nome do arquivo] = nome do arquivo texto\n\n");
									}else{
										if(!strcmp(comando, "del")){
											printf("Exclui um arquivo\n");
											printf("del[nome do arquivo]\n\n");
											printf("[nome do arquivo]\n");
										}else{
											if(!strcmp(comando, "dir")){
												printf("Serve para exibir a lista de arquivos de uma determinada pasta\nincluindo o tamanho dos arquivos em numeros de bytes\n");
												printf("dir[noem da pasta]\n\n");
												printf("[nome da pasta]\n");
											}else{
												if(!strcmp(comando, "mkdir")){
													printf("Cria um diretorio\n");
													printf("mkdir[nome da pasta]\n\n");
													printf("[nome da pasta] = nome da pasta\n");
												}else{
													if(!strcmp(comando, "type")){
														printf("type[nome do arquivo]\n\n");
														printf("[nome do arquivo] = nome do arquivo\n");
													}else{
														if(!strcmp(comando, "statushd")){
															printf("Exite propriedades (espaco) do HD Virtual\n");
															printf("statushd[nome]\n\n");
															printf("[nome] = nome do hd");
														}else{
															if(!strcmp(comando, "removehd")){
																printf("Remove HD Virtual\n");
																printf("removehd[nome]\n\n");
																printf("[nome] = nome do HD\n");
															}else{
																if(!strcmp(comando, "copyfrom")){
																	printf("Copia arquivo jpg HD REAL para o HD VIRTUAL\n");
																	printf("copyfrom[nome][novo nome]\n\n");
																	printf("[nome] = nome do arquivo no HD REAL\n");
																	printf("[novo nome] = nome do arquivo\n");
																}else{
																	if(!strcmp(comando, "copyto")){
																		printf("Copia arquivo jpg do HD VIRTUAL para o HD REAL\n");
																		printf("copyto[nome][novo nome]\n\n");
																		printf("[nome] = nome do arquivo do HD VIRTUAL\n");
																		printf("[novo nome] = nome do arquivo no HD REAL\n");
																		
																	}else{
																		if(!strcmp(comando, "renamedir")){
																			printf("Altera o nome de uma pasta\n");
																			printf("renamedir[nome][novo nome]\n\n");
																			printf("[nome] = nome de uma pasta\n");
																			printf("[novo nome] = novo nome da pasta\n");
																			
																		}else{
																			if(!strcmp(comando, "copy")){
																				printf("Copia um arquivo ou arquivos de uma pasta para uma pasta de destino\n");
																				printf("copy[nome][local destino]\n\n");
																				printf("[nome] = nome de uma pasta\n");
																				printf("[local destino] = nome da pasta destino\n");
																				
																			}else{
																				if(!strcmp(comando, "help")){
																					printf("Ajuda ou Help sobre os comandos\n");
																					printf("help[comando]\n\n");
																					printf("[comando] = nome de um comando\n");
																					
																				}else{
																					if(!strcmp(comando, "move")){
																						printf("Move um arquivo ou pasta (e todo o seu conteudo) para outra pasta\n");
																						printf("move[nome][nomedapasta]\n\n");
																						printf("[nome] = nome de um arquivo ou pasta\n");
																						printf("[nome da pasta] = nome da pasta destino\n");
																						
																					}else{
																						if(!strcmp(comando, "rename")){
																							printf("Altera o nome de um arquivo\n");
																							printf("rename[nome][novonome]\n\n");
																							printf("[nome] = nome de um arquivo\n");
																							printf("[novo nome] = novo nome do arquivo\n");
																						
																						}else{
																							if(!strcmp(comando, "rmdir")){
																								printf("Remove diretorio(pasta)e todo o seu conteudo\n");
																								printf("rmdir[nome]\n\n");
																								printf("[nome] = nome de uma pasta\n");
																							}else{
																								if(!strcmp(comando, "tree")){
																									printf("Exibe graficamente a estrutura de diretorios(pastas)\n");
																									printf("tree\n");
																								}else{
																									printf("Este comando [ %s ] nao exite, tente help para saber sobre os comandos existentes\n\n", comando);
																								}
																							}	
																						}	
																					}	
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}		
									}	
								}
							}
						}
					}
				}
			}
		}
	}

}

int *agoraSim(int a)
{
	int *retorno;
	retorno = (int *)malloc(sizeof(int) * 2);
	char *bits16 = IntToBinary16bits(a);
	char temp[9] = {bits16[0], bits16[1], bits16[2], bits16[3], bits16[4], bits16[5], bits16[6], bits16[7], '\0'};
	char temp2[9] = {bits16[8], bits16[9], bits16[10], bits16[11], bits16[12], bits16[13], bits16[14], bits16[15], '\0'};
	retorno[0] = Binary08bitsToInt(temp);
	retorno[1] = Binary08bitsToInt(temp2);
	//printf("\n%d %d\n",retorno[0],retorno[1]);
	//printf("%c %c\n",retorno[0],retorno[1]);
	return retorno;
}

int agoraNao(int *a)
{
	int temp0 = a[0];
	int temp1 = a[1];
	char *bits80 = IntToBinary08bits(temp0);
	char *bits81 = IntToBinary08bits(temp1);
	char teste[17] =
		{bits80[0], bits80[1], bits80[2], bits80[3], bits80[4], bits80[5], bits80[6], bits80[7],
		 bits81[0], bits81[1], bits81[2], bits81[3], bits81[4], bits81[5], bits81[6], bits81[7], '\0'};
	return Binary16bitsToInt(teste);
}

void info()
{
	printf("coloque -1 para sair");
	printf("\nmaior num de 16bits eh: 65535");
	printf("\nmaior num de 08bits eh: 255\n\n");
}

void imprimir(int num, int size, char *saida)
{
	printf("%d: ", num);
	int i;
	for (i = 0; i < size; i++)
	{
		if (!(i % 4) && i != 0)
		{
			printf(" ");
		}
		printf("%c", *(saida + i));
	}
	printf("\n");
}

char *IntToBinary08bits(int entrada)
{
	int bits = 8;
	int guardaRest[32];
	int i = bits - 1;
	int j = i, aux = 0;
	char *temp = (char *)malloc(9);
	if (entrada == 1)
	{
		temp[i] = 1 + '0';
	}
	else if (entrada != 0)
		while (entrada != 1 && i > 0)
		{
			guardaRest[i] = (entrada % 2);
			temp[i] = guardaRest[i] + '0';
			entrada /= 2;
			i--;
			j--;
			if (entrada == 1)
			{
				temp[i] = 1 + '0';
				guardaRest[i] = 1;
			}
		}
	else
	{
		for (i = 0; i <= j; i++)
			temp[i] = 0 + '0';
	}
	for (i = 0; i < j; i++)
		temp[i] = 0 + '0';
	temp[8] = '\0';
	return temp;
}

int Binary16bitsToInt(char *entrada)
{
	int dec = 0;
	int i = 0, j = 0;
	int res;
	int bits = 16;
	long long int temp = 0;
	for (i = 0; i < bits; i++)
	{
		temp = temp * 10 + (entrada[i] - 48);
	}

	while (temp != 0)
	{

		res = (temp % 10);
		temp = temp / 10;
		dec = dec + res * pow(2, j);
		++j;
	}

	return dec;
}

char *IntToBinary16bits(int entrada)
{
	int bits = 16, guardaRest[32], i = bits - 1, j = i;
	char *temp = malloc(17);
	if (entrada == 1)
	{
		temp[i] = 1 + '0';
	}
	else if (entrada != 0)
		while (entrada != 1)
		{
			guardaRest[i] = (entrada % 2);
			temp[i] = guardaRest[i] + '0';
			entrada /= 2;
			i--;
			j--;
			if (entrada == 1)
			{
				temp[i] = 1 + '0';
				guardaRest[i] = 1;
			}
		}
	else
	{
		for (i = 0; i <= j; i++)
			temp[i] = 0 + '0';
	}
	for (i = 0; i < j; i++)
		temp[i] = 0 + '0';

	temp[16] = '\0';
	return temp;
}

int Binary08bitsToInt(char *entrada)
{

	int dec = 0;
	int i = 0, j = 0;
	;
	int res;
	int bits = 8;
	int temp = 0;
	for (i = 0; i < bits; i++)
	{
		temp = temp * 10 + (entrada[i] - '0');
	}

	while (temp != 0)
	{
		res = (temp % 10);
		temp = temp / 10;
		dec = dec + res * pow(2, j);
		++j;
	}
	return dec;
}

void selectHD(int qtHD, char **matrizHD, int **matrizTamHd, char *nome, char ***matriz, char *EstadoAtual, int *Blocos, int *Bytes)
{
	//printf("\nBlocos: %d Bytes: %d\n",matrizTamHd[qtHD-1][0],matrizTamHd[qtHD-1][1]);
	int i;
	for (i = 0; i < qtHD; i++)
	{
		if (!strcoll(matrizHD[i], nome))
		{
			*Blocos = matrizTamHd[i][0];
			*Bytes = matrizTamHd[i][1];
			carrega(matriz, nome, *Blocos, *Bytes);
			//i=qtHD;
			strcpy(EstadoAtual, nome);
			strcat(EstadoAtual,":\\root");
			strcat(nome,":\\root");
		}
	}
	if (strcmp(EstadoAtual, nome))
		printf("HD invalido\n");
}

void formatHD(int qtHD, char **matrizHD, int **matrizTamHd, char *nome, char ***matriz, char *EstadoAtual, int *Blocos, int *Bytes)
{
	int i;
	for (i = 0; i < qtHD; i++)
	{
		if (!strcoll(matrizHD[i], nome))
		{
			*Blocos = matrizTamHd[i][0];
			*Bytes = matrizTamHd[i][1];
			carrega(matriz, nome, *Blocos, *Bytes);
			carregaMatriz(*matriz, nome, *Blocos, *Bytes);
			strcpy(EstadoAtual, "Omega");
		}
	}
	if (strcmp(EstadoAtual, "Omega"))
		printf("HD invalido\n");
}

int createHD(int *qtHD, char ***matrizHD, char *nome, char **matriz, int blocos, int bytes, int ***matrizTamHD)
{
	int i;
	for (i = 0; i < *qtHD; i++)
		if (!strcmp((*matrizHD[i]), nome))
		{
			printf("HD ja existe\n");
			return 0;
		}

	carregaMatriz(matriz, nome, blocos, bytes);
	realocaMatrizHD(matrizHD, qtHD, matrizTamHD);
	strcpy((*matrizHD)[(*qtHD) - 1], nome);
	(*matrizTamHD)[(*qtHD) - 1][0] = blocos;
	(*matrizTamHD)[(*qtHD) - 1][1] = bytes;
	reescreveConfig(*qtHD, matrizHD, matrizTamHD);

	return 1;
}

int removeHD(int *qtHD, char ***matrizHD, char *nome, char **matriz, int blocos, int bytes, int ***matrizTamHD)
{
	int i;
	for (i = 0; i < *qtHD; i++)
		if (!strcmp(((*matrizHD)[i]), nome))
		{
			if((*qtHD) == 1){				
				char comando[200];
				strcat(comando,"del ");
				strcat(comando,((*matrizHD)[i]));
				system(comando);	
				*qtHD = (*qtHD) - 1;
			}
			else{
				int indCpy = (*qtHD) - 1;
				if(indCpy == i)
					indCpy--;
				char comando[200];
				strcat(comando,"del ");
				strcat(comando,((*matrizHD)[i]));
				system(comando);			
				strcpy( (*matrizHD)[i], (*matrizHD)[indCpy]);	
				(*matrizTamHD)[i][0] = (*matrizTamHD)[indCpy][0];
				(*matrizTamHD)[i][1] = (*matrizTamHD)[indCpy][1];	
				*qtHD = *qtHD - 1;
				//realocaMatrizHD(matrizHD, qtHD, matrizTamHD);

				char **matriz = alocaMatriz2(*qtHD, 200);
				int **matriz2 = alocaMatrizInt(*qtHD, 2);
				int i;
				for (i = 0; i < (*qtHD); i++)
				{
					strcpy(matriz[i], *((*matrizHD) + i));
					matriz2[i][0] = (*matrizTamHD)[i][0];
					matriz2[i][1] = (*matrizTamHD)[i][1];
				}
				//desalocaMatriz2(*matrizHD,*qtHd - 1);
				//desalocaMatrizInt2(*matrizTamHd,*qtHd - 1);
				*matrizHD = NULL;
				*matrizTamHD = NULL;
				*matrizHD = matriz;
				*matrizTamHD = matriz2;
			}
			reescreveConfig(*qtHD, matrizHD, matrizTamHD);
			printf("HD removido\n");
			return 0;
		}
	printf("HD nao existe\n");
	return 1;
}

void dirHD(int qtHD, char **matriz, int **matrizTamHd)
{
	int i;
	for (i = 0; i < qtHD; i++)
		printf("%d Nome: %s Blocos:%d Bytes:%d \n", i, matriz[i], matrizTamHd[i][0], matrizTamHd[i][1]);
}

void config(int *qtHd, int ***matrizTamHD, char ***matriz)
{
	FILE *pont_arqR;
	pont_arqR = fopen("config", "rb");
	if (pont_arqR == NULL)
	{
		FILE *pont_arq;
		pont_arq = fopen("config", "wb");
		*qtHd = 0;
		fprintf(pont_arq, "%d\n", *qtHd);
		fclose(pont_arq);
		fclose(pont_arqR);
	}
	pont_arqR = fopen("config", "rb");
	fscanf(pont_arqR, "%d", qtHd);
	*matriz = alocaMatriz2(*qtHd, 200);
	*matrizTamHD = alocaMatrizInt(*qtHd, 2);

	int i, A = 0, B = 0;
	for (i = 0; i < *qtHd; i++)
	{
		fscanf(pont_arqR, "%s", ((*matriz)[i]));
		fscanf(pont_arqR, "%d", &(*matrizTamHD)[i][0]);
		fscanf(pont_arqR, "%d", &(*matrizTamHD)[i][1]);
	}
	fclose(pont_arqR);
}

void reescreveConfig(int qtHd, char ***matriz, int ***matrizTamHD)
{
	FILE *pont_arq;
	pont_arq = fopen("config", "wb");
	fprintf(pont_arq, "%d\n", qtHd);
	int i;
	for (i = 0; i < qtHd; i++)
	{
		fprintf(pont_arq, "%s ", (*matriz)[i]);
		fprintf(pont_arq, "%d ", (*matrizTamHD)[i][0]);
		fprintf(pont_arq, "%d \n", (*matrizTamHD)[i][1]);
	}
	fclose(pont_arq);
}

void realocaMatrizHD(char ***matrizHD, int *qtHd, int ***matrizTamHd)
{
	*qtHd = *qtHd + 1;
	char **matriz = alocaMatriz2(*qtHd, 200);
	int **matriz2 = alocaMatrizInt(*qtHd, 2);
	int i;
	for (i = 0; i < (*qtHd) - 1; i++)
	{
		strcpy(matriz[i], *((*matrizHD) + i));
		matriz2[i][0] = (*matrizTamHd)[i][0];
		matriz2[i][1] = (*matrizTamHd)[i][1];
	}
	//desalocaMatriz2(*matrizHD,*qtHd - 1);
	//desalocaMatrizInt2(*matrizTamHd,*qtHd - 1);
	*matrizHD = NULL;
	*matrizTamHd = NULL;
	*matrizHD = matriz;
	*matrizTamHd = matriz2;
}

void carregaMatriz(char **matriz, char *nomeHD, int blocos, int bytes)
{
	matriz = alocaMatriz2(blocos, bytes);
	int i, j;
	for (i = 0; i < blocos; i++)
	{
		matriz[i][0] = '0';
		for (j = 1; j < bytes - 1; j++)
		{
			matriz[i][j] = ' ';
		}
		matriz[i][j] = '\n';
	}
	FILE *pont_arq;
	pont_arq = fopen(nomeHD, "wb");

	for (i = 0; i < blocos; i++)
		for (j = 0; j < bytes; j++)
			fprintf(pont_arq, "%c", matriz[i][j]);

	fclose(pont_arq);
}

void carrega(char ***matriz, char *nomeHD, int blocos, int bytes)
{
	FILE *pont_arq;
	pont_arq = fopen(nomeHD, "rb");

	*matriz = alocaMatriz2(blocos, bytes);

	if (pont_arq == NULL)
		carregaMatriz(*matriz, nomeHD, blocos, bytes);
	else
	{
		int i, j;
		char a;

		for (i = 0; i < blocos; i++)
		{
			for (j = 0; j < bytes; j++)
			{
				fscanf(pont_arq, "%c", &a);
				(*matriz)[i][j] = a;
			}
		}
	}
	fclose(pont_arq);
}

void filtraPasta(char *nomeHD, char* EstadoAtual){
	int i=0,j=0,k=0;
	while(EstadoAtual[i++] != ':');
	while(j<i-1)
		nomeHD[k++] = EstadoAtual[j++];
	nomeHD[k] = '\0';
}

void preencher(char **matriz, char *EstadoAtual, int blocos, int bytes)
{
	char nomeHD[200];
	filtraPasta(nomeHD,EstadoAtual);
	//printf("nomeHD: %s\nEstado Atual: %s\n",nomeHD,EstadoAtual);
	//system("pause");
	FILE *pont_arq;
	pont_arq = fopen(nomeHD, "rb+");

	int i, j;
	for (i = 0; i < blocos; i++)
		for (j = 0; j < bytes; j++)
			fprintf(pont_arq, "%c", matriz[i][j]);

	fclose(pont_arq);
}

void input(char **matriz)
{
	int posX, posY;
	char entrada;

	printf("bloco: ");
	scanf("%i", &posX);

	printf("byte: ");
	scanf("%i", &posY);

	fflush(stdin);
	printf("Entrada: ");
	scanf("%c", &entrada);

	matriz[posX][posY] = entrada;
}

void copiaBinario(char entrada[200], char *retorno)
{
	int i;
	for (i = 0; i < 8; i++)
		retorno[i] = entrada[2 + i];
}

int binario(char *binario)
{

	int decimal = 0;
	int i = 0, j = 8;

	while (j--)
	{
		decimal += pow(2, i++) * (binario[j] - 48);
	}

	return decimal;
}

void input2(char **matriz)
{
	int posX, posY;

	printf("bloco: ");
	scanf("%i", &posX);

	printf("byte: ");
	scanf("%i", &posY);

	fflush(stdin);
	printf("Entrada: ");
	char entrada[200];
	scanf("%s", entrada);

	//posX--;
	//posY--;

	//if(posY == 0)
	//posY++;

	int i = 0;
	if (entrada[0] == 'b')
	{
		char *retorno = NULL;
		copiaBinario(entrada, retorno);
		char a = binario(retorno);
		matriz[posX][posY] = a;
	}
	else
	{
		i = 0;
		while (entrada[i] != '\0')
		{
			matriz[posX][posY++] = entrada[i++];
		}
	}
}

char **alocaMatriz()
{
	char **matriz = malloc(sizeof(char *) * 1024);
	int i;
	for (i = 0; i < 1024; i++)
	{
		*(matriz + i) = malloc(32);
	}
	return matriz;
}

char **alocaMatriz2(int l, int c)
{
	char **matriz = malloc(sizeof(char *) * l);
	int i;
	for (i = 0; i < l; i++)
	{
		*(matriz + i) = malloc(sizeof(char) * c);
	}
	return matriz;
}

int **alocaMatrizInt(int l, int c)
{
	int **matriz = malloc(sizeof(int *) * l);
	int i;
	for (i = 0; i < l; i++)
	{
		*(matriz + i) = malloc(sizeof(int) * c);
	}

	int j;
	for (i = 0; i < l; i++)
		for (j = 0; j < c; j++)
			matriz[i][j] = 0;

	return matriz;
}

void desalocaMatriz(char **matriz)
{
	int i;
	for (i = 0; i < 1024; i++)
		free(matriz[i]);
	free(matriz);
}

void desalocaMatriz2(char **matriz, int blocos)
{
	int i;
	for (i = 0; i < blocos; i++)
		free(matriz[i]);
	if (!matriz)
		free(matriz);
}

void desalocaMatrizInt2(int **matriz, int blocos)
{
	int i;
	for (i = 0; i < blocos; i++)
		free(matriz[i]);
	free(matriz);
}

void typehd(char **matriz, int blocos, int bytes)
{

	printf("BLOCO| BYTES\n");

	int i, j, z = 0, flag = 0;
	//int v[blocos];
	int * v = (int*) malloc(sizeof(int)*blocos);

	for (i = 0; i < blocos; i++)
	{
		//for(j=1;j<bytes-1;j++)
		if (matriz[i][0] != '0' && flag != 1)
		{
			v[z++] = i;
			flag = 1;
		}
		flag = 0;
	}

	for (i = 0; i < z; i++)
	{
		printf("%04i |", v[i]);
		int k = bytes - 1;
		//	while(matriz[v[i]][k--] == ' ');
		k = matriz[v[i]][3] + matriz[v[i]][4] + 0;
		for (j = 0; j < k; j++)
			/*if(matriz[v[i]][j] == '_')
				printf("   ");
			else*/
			if (matriz[v[i]][j] == '\n')
				printf(" \\n ");
			else
				printf(" %c ", matriz[v[i]][j]);
		printf("\n     |");
		for (j = 0; j < k; j++)
			/*if(matriz[v[i]][j] == '_')
				printf("   ");
			else*/
			printf("%2x ", matriz[v[i]][j]);
		printf("\n");
	}
}

void leBlocosDisp(char **matriz, int blocos, int bytes, tp_pilha *pilha)
{
	int i;
	for (i = blocos - 1; i >= 0; i--)
		if (matriz[i][0] == '0')
			push(pilha, i);
}

void copyfrom(char **matriz, int blocos, int bytes, tp_pilha *pilha, const char *nome, char *nome2, char *EstadoAtual)
{
	int tam=0,i=0;FILE* stream;
	//VERIFICA TAMANHO DA IMAGEM
	stream = fopen(nome,"rb");
	while(getc(stream)>-1)tam++;
	fclose(stream);
	
	//char imagem[tam];
	char* imagem;
	imagem = (char*) malloc(sizeof(char)*tam);

	//SALVA TODOS OS CHAR DA IMAGEM EM UM VETOR
	stream = fopen(nome,"rb");
	for(i=0;i<tam;i++)
		fscanf(stream,"%c",imagem+i);
	fclose(stream);	

	int posXNome = pop(pilha);
	int posX = pop(pilha);
	int posY = 5;
	matriz[posX][0] = '2';

	int *saida;
	saida = agoraSim(posX);
	matriz[posXNome][5] = saida[0];
	matriz[posXNome][6] = saida[1];

	matriz[posXNome][0] = '3';
	int posYNome = 7;
	matriz[posXNome][1] = 0;
	matriz[posXNome][2] = 0;
	i=0;
	while (nome[i] != '\0' && posYNome < bytes - 2)
	{
		matriz[posXNome][posYNome++] = nome2[i++];
	}
	saida = agoraSim(posYNome);
	matriz[posXNome][3] = saida[0];
	matriz[posXNome][4] = saida[1];

	for(i=0;i<tam;i++){
		if(posY == bytes){
			saida = agoraSim(posY);
			matriz[posX][3] = saida[0];
			matriz[posX][4] = saida[1];

			int temp = posX;
			posX = pop(pilha);

			saida = agoraSim(posX);
			matriz[temp][1] = saida[0];
			matriz[temp][2] = saida[1];

			posY = 5;
			matriz[posX][0] = '2';
		}
		matriz[posX][posY++] = imagem[i];
	}

	saida = agoraSim(posY);
	matriz[posX][3] = saida[0];
	matriz[posX][4] = saida[1];	

	matriz[posX][1] = 0;
	matriz[posX][2] = 0;
	type(matriz,blocos,bytes,nome2);
}

void copyto(char **matriz, int blocos, int bytes, tp_pilha *pilha, char *nome, char *nome2, char *EstadoAtual)
{
	FILE* stream;
	stream = fopen(nome2,"wb");	
	int i, j, k;
	for (i = 0; i < blocos; i++)
	{
		//printf("%d\n",matriz[i][0]-'0');
		if (matriz[i][0] - '0' == 3)
		{
			//printf("\nACHOU\n");
			char temp[200];
			j = 7;
			k = 0;
			int tempAgoraNao[2] = {matriz[i][3],matriz[i][4]};
			//while (j < matriz[i][3] + matriz[i][4])
			while (j < agoraNao(tempAgoraNao))
			{
				temp[k++] = matriz[i][j++];
			}
			temp[k] = '\0';
			tempAgoraNao[0] = matriz[i][5];
			tempAgoraNao[1] = matriz[i][6];
			if (!strcmp(temp, nome)){
				int posX =  agoraNao(tempAgoraNao);
				int posXatual = posX;
				int i, sair = 0;
				int tempAgoraNao[2];
				while (!(sair))
				{		
					tempAgoraNao[0] = matriz[posXatual][3];
					tempAgoraNao[1] = matriz[posXatual][4];
					//for (i = 5; i < matriz[posXatual][3] + matriz[posXatual][4]; i++)
					for (i = 5; i < agoraNao(tempAgoraNao); i++)
					{						
						fprintf(stream,"%c",matriz[posXatual][i]);
					}
					tempAgoraNao[0] = matriz[posXatual][1];
					tempAgoraNao[1] = matriz[posXatual][2];
					//if (matriz[posXatual][1] + matriz[posXatual][2] == 0)
					if (agoraNao(tempAgoraNao) == 0)
						sair = 1;
					tempAgoraNao[0] = matriz[posXatual][1];
					tempAgoraNao[1] = matriz[posXatual][2];
					//posXatual = matriz[posXatual][1] + matriz[posXatual][2];
					posXatual = agoraNao(tempAgoraNao);
				}
			}
				//imprimirArq(matriz, agoraNao(tempAgoraNao));
				//imprimirArq(matriz, matriz[i][5] + matriz[i][6]);
		}
	}
	fclose(stream);
}

void lerPastaAtual(char * pasta,char * EstadoAtual){
	int i=0,j=0,k=0;
	while(EstadoAtual[i] != '\0')i++;
	j=i;
	while(EstadoAtual[j] != '\\' )j--;
	while(j<i)
		pasta[k++] = EstadoAtual[++j];
	pasta[k] = '\0';
}

void lerPastaAnterior(char * EstadoAtual){
	int i=0,j=0,k=0;
	while(EstadoAtual[i] != '\0')i++;
	j=i;
	while(EstadoAtual[j] != '\\' )j--;
	EstadoAtual[j] = '\0';
}

void mkdir(char **matriz, int blocos, int bytes, tp_pilha *pilha, char *nome, char *EstadoAtual)
{
	int exit = 0;
	int i = 0;

	int posXNome = pop(pilha);
	int posX = pop(pilha);
	int posY = 5;
	matriz[posX][0] = '1';

	int *saida;
	saida = agoraSim(posX);
	matriz[posXNome][5] = saida[0];
	matriz[posXNome][6] = saida[1];

	matriz[posXNome][0] = '3';
	int posYNome = 7;
	matriz[posXNome][1] = 0;
	matriz[posXNome][2] = 0;
	while (nome[i] != '\0' && posYNome < bytes - 2)
	{
		matriz[posXNome][posYNome++] = nome[i++];
	}

	saida = agoraSim(posYNome);
	matriz[posXNome][3] = saida[0];
	matriz[posXNome][4] = saida[1];

	saida = agoraSim(posY);
	matriz[posX][3] = saida[0];
	matriz[posX][4] = saida[1];	

	matriz[posX][1] = 0;
	matriz[posX][2] = 0;
	printf("\n");
	
	int j, k;
	char pasta[200];
	lerPastaAtual(pasta,EstadoAtual);
	for (i = 0; i < blocos; i++)
	{
		if (matriz[i][0] - '0' == 3)
		{
			char temp[200];
			j = 7;
			k = 0;
			int tempAgoraNao[2] = {matriz[i][3],matriz[i][4]};
			while (j < agoraNao(tempAgoraNao))
			{
				temp[k++] = matriz[i][j++];
			}
			temp[k] = '\0';
			if (!strcmp(temp, pasta)){
				int tempAgoraNao[2] = {matriz[i][5],matriz[i][6]};
				int ponteiroCont = agoraNao(tempAgoraNao);
				tempAgoraNao[0] = matriz[ponteiroCont][3];
				tempAgoraNao[1] = matriz[ponteiroCont][4];
				int s_byteConteudo = agoraNao(tempAgoraNao);
				int* p_conteudo = agoraSim(posXNome);
				matriz[ponteiroCont][s_byteConteudo] =  p_conteudo[0];
				matriz[ponteiroCont][++s_byteConteudo] =  p_conteudo[1];
				int* s_byteConteudo_novo = agoraSim(++s_byteConteudo);
				matriz[ponteiroCont][3] = s_byteConteudo_novo[0];
				matriz[ponteiroCont][4] = s_byteConteudo_novo[1];
			}
		}
	}

}

void cd(char **matriz, int blocos, int bytes, tp_pilha *pilha, char *nome, char *EstadoAtual)
{
	char pasta[200];
	if(!strcmp("..",nome)){
		lerPastaAnterior(EstadoAtual);
	}
	else{
		strcat(EstadoAtual,"\\");
		strcat(EstadoAtual,nome);
	}
}

void imprimirDir(char **matriz,int posX){
	int i,j;
	int tempAgoraNao[2] = {matriz[posX][3],matriz[posX][4]};
	int posYMax = agoraNao(tempAgoraNao);
	for(i=5;i<posYMax;i=i+2){
		tempAgoraNao[0] = matriz[posX][i];
		tempAgoraNao[1] = matriz[posX][i+1];
		int arq = agoraNao(tempAgoraNao);
		tempAgoraNao[0] = matriz[arq][3];
		tempAgoraNao[1] = matriz[arq][4];
		int sizeNomeArq = agoraNao(tempAgoraNao);
		for(j=7;j<sizeNomeArq;j++){
			printf("%c",matriz[arq][j]);
		}			
		printf("\n");
	}
}

void dir(char **matriz, int blocos, int bytes, tp_pilha *pilha, char *EstadoAtual)
{
	char pasta[200];
	lerPastaAtual(pasta,EstadoAtual);
	int i;
	for(i=0;i<blocos;i++){
		if(matriz[i][0] - '0' == 3){			
			char temp[200];
			int j = 7, k = 0;
			int tempAgoraNao[2] = {matriz[i][3],matriz[i][4]};
			while (j < agoraNao(tempAgoraNao))
			{
				temp[k++] = matriz[i][j++];
			}
			temp[k] = '\0';
			if(!strcmp(pasta,temp)){
				tempAgoraNao[0] = matriz[i][5];
				tempAgoraNao[1] = matriz[i][6];
				imprimirDir(matriz,agoraNao(tempAgoraNao));
			}
		}
	}
}

void create(char **matriz, int blocos, int bytes, tp_pilha *pilha, char *nome, char *EstadoAtual)
{
	int exit = 0;
	char entrada;
	int i = 0;

	int posXNome = pop(pilha);
	int posX = pop(pilha);
	int posY = 5;
	matriz[posX][0] = '2';

	int *saida;
	saida = agoraSim(posX);
	matriz[posXNome][5] = saida[0];
	matriz[posXNome][6] = saida[1];

	matriz[posXNome][0] = '3';
	int posYNome = 7;
	matriz[posXNome][1] = 0;
	matriz[posXNome][2] = 0;
	while (nome[i] != '\0' && posYNome < bytes - 2)
	{
		matriz[posXNome][posYNome++] = nome[i++];
	}

	saida = agoraSim(posYNome);
	matriz[posXNome][3] = saida[0];
	matriz[posXNome][4] = saida[1];

	while (!exit)
	{
		if (posY == bytes)
		{
			saida = agoraSim(posY);
			matriz[posX][3] = saida[0];
			matriz[posX][4] = saida[1];

			int temp = posX;
			posX = pop(pilha);

			saida = agoraSim(posX);
			matriz[temp][1] = saida[0];
			matriz[temp][2] = saida[1];

			posY = 5;
			matriz[posX][0] = '2';
		}
		entrada = getch();
		if (entrada == 26)
			exit = 1;
		else if (entrada == 13)
		{
			printf("\n");
			matriz[posX][posY++] = '\n';
		}
		else
			matriz[posX][posY++] = entrada;
		if (entrada != 26 && entrada != 13)
			printf("%c", entrada);
	}
	saida = agoraSim(posY);
	matriz[posX][3] = saida[0];
	matriz[posX][4] = saida[1];	

	matriz[posX][1] = 0;
	matriz[posX][2] = 0;
	printf("\n");


	
	int j, k;
	char pasta[200];
	lerPastaAtual(pasta,EstadoAtual);
	//printf("pasta: %s\nEstado atual: %s\n",pasta,EstadoAtual);
	//system("pause");
	//strcpy(pasta,"root");
	for (i = 0; i < blocos; i++)
	{
		if (matriz[i][0] - '0' == 3)
		{
			char temp[200];
			j = 7;
			k = 0;
			int tempAgoraNao[2] = {matriz[i][3],matriz[i][4]};
			while (j < agoraNao(tempAgoraNao))
			{
				temp[k++] = matriz[i][j++];
			}
			temp[k] = '\0';
			//tempAgoraNao[0] = matriz[i][5];
			//tempAgoraNao[1] = matriz[i][6];
			if (!strcmp(temp, pasta)){
				//printf("Salvando em pasta\n");
				int tempAgoraNao[2] = {matriz[i][5],matriz[i][6]};
				int ponteiroCont = agoraNao(tempAgoraNao);
				//printf("%d\n",ponteiroCont);
				tempAgoraNao[0] = matriz[ponteiroCont][3];
				tempAgoraNao[1] = matriz[ponteiroCont][4];
				int s_byteConteudo = agoraNao(tempAgoraNao);
				//printf("%d\n",s_byteConteudo);
				int* p_conteudo = agoraSim(posXNome);
				matriz[ponteiroCont][s_byteConteudo] =  p_conteudo[0];
				matriz[ponteiroCont][++s_byteConteudo] =  p_conteudo[1];
				//printf("%d\n",s_byteConteudo);
				int* s_byteConteudo_novo = agoraSim(++s_byteConteudo);
				matriz[ponteiroCont][3] = s_byteConteudo_novo[0];
				matriz[ponteiroCont][4] = s_byteConteudo_novo[1];
				//printf("Salvo em pasta\n");
			}
		}
	}

}

void rename2(char **matriz, int blocos, int bytes, tp_pilha *pilha, char *nome, char *EstadoAtual,char* nomeNovo)
{
	int i,j;
	for(i=0;i<blocos;i++){
		if(matriz[i][0] - 48 == 3){
			int tempAgoraNao[2] = {matriz[i][3],matriz[i][4]};
			char temp[200];
			int k=0;
			for(j=7;j<agoraNao(tempAgoraNao);j++){
				temp[k++] = matriz[i][j];
			}
			temp[k] = '\0';
			if(!strcmp(nome, temp)){
				int l=7;
				k = 0;
				while(nomeNovo[k] != '\0'){
					matriz[i][l++] = nomeNovo[k++];
				}
				int* tempAgoraSim = agoraSim(l);
				matriz[i][3] = tempAgoraSim[0];
				matriz[i][4] = tempAgoraSim[1];
			}
		}
	}
}

void move(char **matriz, int blocos, int bytes, tp_pilha *pilha, char *nome, char *EstadoAtual,char* pasta)
{
	int i,j,posY;
	//encontrar nome
	for(i=0;i<blocos;i++){
		if(matriz[i][0] - 48 == 3){
			int tempAgoraNao[2] = {matriz[i][3],matriz[i][4]};
			char temp[200];
			int k=0;
			for(j=7;j<agoraNao(tempAgoraNao);j++){
				temp[k++] = matriz[i][j];
			}
			temp[k] = '\0';
			if(!strcmp(nome, temp)){
				posY = i;
			}
		}
	}
	//apagar da pasta antiga
	for(i=0;i<blocos;i++){
		if(matriz[i][0] - 48 == 1){
			int tempAgoraNao[2] = {matriz[i][3],matriz[i][4]};
			int valor = agoraNao(tempAgoraNao);
			for(j=5;j<valor;j=j+2){
				tempAgoraNao[0] = matriz[i][j];
				tempAgoraNao[1] = matriz[i][j+1];
				int tempY = agoraNao(tempAgoraNao);
				if(tempY == posY){
					tempAgoraNao[0] = matriz[i][3];
					tempAgoraNao[1] = matriz[i][4];
					int posYCont = agoraNao(tempAgoraNao);
					//pensar em como reorganizar
					for(j;j<posYCont-3;j=j+2){
						matriz[i][j] = matriz[i][j+2];
						matriz[i][j+1] = matriz[i][j+3];
					}
					//Apagar i do conteudo da pasta atual
					posYCont = posYCont - 2;
					int *temp = agoraSim(posYCont);
					matriz[i][3] = temp[0];
					matriz[i][4] = temp[1];
				}
			}
		}
	}
	//incluir na nova pasta
	for(i=0;i<blocos;i++){
		if(matriz[i][0] - 48 == 3){
			int tempAgoraNao[2] = {matriz[i][3],matriz[i][4]};
			char temp[200];
			int k=0;
			for(j=7;j<agoraNao(tempAgoraNao);j++){
				temp[k++] = matriz[i][j];
			}
			temp[k] = '\0';
			if(!strcmp(pasta, temp)){
				tempAgoraNao[0] = matriz[i][5];
				tempAgoraNao[1] = matriz[i][6];
				int posXConteudoPastaNova = agoraNao(tempAgoraNao);
				tempAgoraNao[0] = matriz[posXConteudoPastaNova][3];
				tempAgoraNao[1] = matriz[posXConteudoPastaNova][4];
				int posYConteudoPastaNova = agoraNao(tempAgoraNao);
				int* posXConteudo = agoraSim(posY);
				matriz[posXConteudoPastaNova][posYConteudoPastaNova] = posXConteudo[0];
				matriz[posXConteudoPastaNova][posYConteudoPastaNova+1] = posXConteudo[1];
				int* tempAgoraSim = agoraSim(posYConteudoPastaNova+2);
				matriz[posXConteudoPastaNova][3] = tempAgoraSim[0];
				matriz[posXConteudoPastaNova][4] = tempAgoraSim[1];
			}
		}
	}
}

int copiaArquivo(char **matriz,int blocos,int bytes,tp_pilha *pilha,char* nome,char *EstadoAtual,int pasta,int posY){
	int posXNome = pop(pilha);
	int posXConteudo = pop(pilha);
	int i;

	for(i=0;i<bytes;i++)
		matriz[posXNome][i] = matriz[posY][i];

	int *tempAgoraSim = agoraSim(posXConteudo);
	matriz[posXNome][5] = tempAgoraSim[0];
	matriz[posXNome][6] = tempAgoraSim[1];

	int temp[2] = {matriz[posY][5],matriz[posY][6]};
	int tempAgoraNao = agoraNao(temp);

	for(i=0;i<bytes;i++)
		matriz[posXConteudo][i] = matriz[tempAgoraNao][i];

	return posXNome;
}

void copy(char **matriz, int blocos, int bytes, tp_pilha *pilha, char *nome, char *EstadoAtual,char* pasta)
{
	int i,j,posX;
	//encontrar nome
	for(i=0;i<blocos;i++){
		if(matriz[i][0] - 48 == 3){
			int tempAgoraNao[2] = {matriz[i][3],matriz[i][4]};
			char temp[200];
			int k=0;
			for(j=7;j<agoraNao(tempAgoraNao);j++){
				temp[k++] = matriz[i][j];
			}
			temp[k] = '\0';
			if(!strcmp(nome, temp)){
				posX = i;
			}
		}
	}
	//incluir na nova pasta
	for(i=0;i<blocos;i++){
		if(matriz[i][0] - 48 == 3){
			int tempAgoraNao[2] = {matriz[i][3],matriz[i][4]};
			char temp[200];
			int k=0;
			for(j=7;j<agoraNao(tempAgoraNao);j++){
				temp[k++] = matriz[i][j];
			}
			temp[k] = '\0';
			if(!strcmp(pasta, temp)){
				//se arquivo cria arquivo
				int temp[2] = {matriz[posX][5],matriz[posX][6]};
				int tempAgoraNaoCont = agoraNao(temp);
				printf("%c\n",matriz[tempAgoraNaoCont][0]);
				if(matriz[tempAgoraNaoCont][0] - 48 == 2){
					int posY = copiaArquivo(matriz,blocos,bytes,pilha,nome,EstadoAtual,i,posX);
					tempAgoraNao[0] = matriz[i][5];
					tempAgoraNao[1] = matriz[i][6];
					int posXConteudoPastaNova = agoraNao(tempAgoraNao);
					tempAgoraNao[0] = matriz[posXConteudoPastaNova][3];
					tempAgoraNao[1] = matriz[posXConteudoPastaNova][4];
					int posYConteudoPastaNova = agoraNao(tempAgoraNao);
					int* posXConteudo = agoraSim(posY);
					matriz[posXConteudoPastaNova][posYConteudoPastaNova] = posXConteudo[0];
					matriz[posXConteudoPastaNova][posYConteudoPastaNova+1] = posXConteudo[1];
					int* tempAgoraSim = agoraSim(posYConteudoPastaNova+2);
					matriz[posXConteudoPastaNova][3] = tempAgoraSim[0];
					matriz[posXConteudoPastaNova][4] = tempAgoraSim[1];
				}
				//se pasta cria pasta e olha dentro
			}
		}
	}
}

int binario1Bloco(int pos)
{
	char b[8];
	int i, posB = 8;
	int rest, quo = pos;
	for (i = 0; i < 16; i++)
	{
		if (quo > 1)
		{
			rest = quo % 2;
			quo = quo / 2;
		}
		else
		{
			rest = quo;
			if (8 <= i && i < 16)
				b[--posB] = rest;
			while (i++ < 16)
				b[--posB] = 0;
		}
		if (8 <= i && i < 16)
			b[--posB] = rest;
	}
	return binario(b);
}

int binario2Bloco(int pos)
{
	char b[8];
	int i, posB = 8;
	int rest, quo = pos;
	for (i = 0; i < 8; i++)
	{
		if (quo > 1)
		{
			rest = quo % 2;
			quo = quo / 2;
		}
		else
		{
			rest = quo;
			b[--posB] = rest;
			while (i++ < 8)
				b[--posB] = 0;
		}
		if (i < 8)
			b[--posB] = rest;
	}
	return binario(b);
}

void imprimirArq(char **matriz, int posX)
{
	int posXatual = posX;
	int i, sair = 0;
	int tempAgoraNao[2];
	while (!(sair))
	{		
		tempAgoraNao[0] = matriz[posXatual][3];
		tempAgoraNao[1] = matriz[posXatual][4];
		//for (i = 5; i < matriz[posXatual][3] + matriz[posXatual][4]; i++)
		for (i = 5; i < agoraNao(tempAgoraNao); i++)
		{
			printf("%c", matriz[posXatual][i]);
		}
		tempAgoraNao[0] = matriz[posXatual][1];
		tempAgoraNao[1] = matriz[posXatual][2];
		//if (matriz[posXatual][1] + matriz[posXatual][2] == 0)
		if (agoraNao(tempAgoraNao) == 0)
			sair = 1;
		tempAgoraNao[0] = matriz[posXatual][1];
		tempAgoraNao[1] = matriz[posXatual][2];
		//posXatual = matriz[posXatual][1] + matriz[posXatual][2];
		posXatual = agoraNao(tempAgoraNao);
	}
}

void DelProx(char **matriz, int posX)
{
	int posXatual = posX;
	int i, sair = 0;
	int tempAgoraNao[2];
	while (!(sair))
	{
		matriz[posXatual][0] = '0';
		tempAgoraNao[0] = matriz[posXatual][1];
		tempAgoraNao[1] = matriz[posXatual][2];
		//if (matriz[posXatual][1] + matriz[posXatual][2] == 0)
		if (agoraNao(tempAgoraNao) == 0)
			sair = 1;
		tempAgoraNao[0] = matriz[posXatual][1];
		tempAgoraNao[1] = matriz[posXatual][2];	
		//posXatual = matriz[posXatual][1] + matriz[posXatual][2];
		posXatual = agoraNao(tempAgoraNao);
	}
}

void type(char **matriz, int blocos, int bytes, char *nome)
{
	int i, j, k;
	for (i = 0; i < blocos; i++)
	{
		//printf("%d\n",matriz[i][0]-'0');
		if (matriz[i][0] - '0' == 3)
		{
			//printf("\nACHOU\n");
			char temp[200];
			j = 7;
			k = 0;
			int tempAgoraNao[2] = {matriz[i][3],matriz[i][4]};
			//while (j < matriz[i][3] + matriz[i][4])
			while (j < agoraNao(tempAgoraNao))
			{
				temp[k++] = matriz[i][j++];
			}
			temp[k] = '\0';
			tempAgoraNao[0] = matriz[i][5];
			tempAgoraNao[1] = matriz[i][6];
			if (!strcmp(temp, nome))
				imprimirArq(matriz, agoraNao(tempAgoraNao));
				//imprimirArq(matriz, matriz[i][5] + matriz[i][6]);
		}
	}
	printf("\n");
}

void del(char **matriz, int blocos, int bytes, char *nome, char* EstadoAtual)
{
	int i, j, k;
	int tempAgoraNao[2];
	for (i = 0; i < blocos; i++)
	{
		//printf("%d\n",matriz[i][0]-'0');
		if (matriz[i][0] - '0' == 3)
		{
			//printf("\nACHOU\n");
			char temp[200];
			j = 7;
			k = 0;
			
			tempAgoraNao[0] = matriz[i][3];
			tempAgoraNao[1] = matriz[i][4];
			//while (j < matriz[i][3] + matriz[i][4])
			while (j < agoraNao(tempAgoraNao))
			{
				temp[k++] = matriz[i][j++];
			}
			temp[k] = '\0';
			if (!strcmp(temp, nome))
			{
				tempAgoraNao[0] = matriz[i][5];
				tempAgoraNao[1] = matriz[i][6];
				DelProx(matriz, agoraNao(tempAgoraNao));
				matriz[i][0] = '0';
				
				//Inicio apagar arq da pasta
				char pasta[200];
				lerPastaAtual(pasta,EstadoAtual);	
				int posXNome;
				int z;
				for (z = 0; z < blocos; z++)
					{
						if (matriz[z][0] - '0' == 3)
						{
							char temp[200];
							j = 7;
							k = 0;
							int tempAgoraNao[2] = {matriz[z][3],matriz[z][4]};
							while (j < agoraNao(tempAgoraNao))
							{
								temp[k++] = matriz[z][j++];
							}
							temp[k] = '\0';
							//tempAgoraNao[0] = matriz[i][5];
							//tempAgoraNao[1] = matriz[i][6];
							if (!strcmp(temp, pasta)){
								posXNome = z;
							}
						}
					}
				
				tempAgoraNao[0] = matriz[posXNome][5];
				tempAgoraNao[1] = matriz[posXNome][6];	
				int posXCont = agoraNao(tempAgoraNao);	
				tempAgoraNao[0] = matriz[posXCont][3];
				tempAgoraNao[1] = matriz[posXCont][4];
				int posYCont = agoraNao(tempAgoraNao);
				//Procurar por i no conteudo da pasta atual
				int posY;
				for(posY=5;posY<posYCont-1;posY=posY+2){
					tempAgoraNao[0] = matriz[posXCont][posY];
					tempAgoraNao[1] = matriz[posXCont][posY+1];
					if(i == agoraNao(tempAgoraNao)){
						//pensar em como reorganizar
						for(posY;posY<posYCont-3;posY=posY+2){
							matriz[posXCont][posY] = matriz[posXCont][posY+2];
							matriz[posXCont][posY+1] = matriz[posXCont][posY+3];
						}
						//Apagar i do conteudo da pasta atual
						posYCont = posYCont - 2;
						int *temp = agoraSim(posYCont);
						matriz[posXCont][3] = temp[0];
						matriz[posXCont][4] = temp[1];
					}
				}
			}
		}
	}
	printf("\n");
}

void rmdir(char **matriz, int blocos, int bytes, char *nome, char* EstadoAtual)
{
	//encontrar pasta
	int PosXNome;
	int i;
	for(i=0;i<blocos;i++){
		if(matriz[i][0] - 48 == 3){
			char temp[200];
			int j = 7;
			int k = 0;
			int tempAgoraNao[2];
			tempAgoraNao[0] = matriz[i][3];
			tempAgoraNao[1] = matriz[i][4];
			while (j < agoraNao(tempAgoraNao))
			{
				temp[k++] = matriz[i][j++];
			}
			temp[k] = '\0';
			if (!strcmp(temp, nome)){
				PosXNome = i;
			}
		}
	}
	
	//anda conteudo
	int tempAgoraNao[2] = {matriz[PosXNome][5], matriz[PosXNome][6]};
	int PosXConteudo = agoraNao(tempAgoraNao);
	tempAgoraNao[0] = matriz[PosXConteudo][3];
	tempAgoraNao[1] = matriz[PosXConteudo][4];
	int PosYConteudo = agoraNao(tempAgoraNao);
	for(i=5;i<PosYConteudo;i=i+2){
		tempAgoraNao[0] = matriz[PosXConteudo][i];
		tempAgoraNao[1] = matriz[PosXConteudo][i+1];
		int ponteiroNomeConteudo = agoraNao(tempAgoraNao);
		tempAgoraNao[0] = matriz[ponteiroNomeConteudo][5];
		tempAgoraNao[1] = matriz[ponteiroNomeConteudo][6];
		int ponteiroConteudo = agoraNao(tempAgoraNao);
		int primeiroByte = matriz[ponteiroConteudo][0] - 48;
		char nomeInterno[200];
		tempAgoraNao[0] = matriz[ponteiroNomeConteudo][3];
		tempAgoraNao[1] = matriz[ponteiroNomeConteudo][4];
		int tamNome = agoraNao(tempAgoraNao);
		int j=0;
		int k=0;
		for(j=7;j<tamNome;j++){
			nomeInterno[k++] = matriz[ponteiroNomeConteudo][j];
		}
		nomeInterno[k] = '\0';
		if(primeiroByte == 1){			
			//se pasta chama rmdir
			rmdir(matriz,blocos,bytes,nomeInterno,EstadoAtual);
		}
		else
		{
			//se arq del arq
			del(matriz,blocos,bytes,nomeInterno,EstadoAtual);
		}		
	}
	//fim apaga propria pasta

	for(i=0;i<blocos;i++){
		if(matriz[i][0]-48 == 1){
			tempAgoraNao[0] = matriz[i][3];
			tempAgoraNao[1] = matriz[i][4];
			int qtBytes = agoraNao(tempAgoraNao);
			int j;
			for(j=5;j<qtBytes;j=j+2){
				tempAgoraNao[0] = matriz[i][j];
				tempAgoraNao[1] = matriz[i][j+1];
				int pontConteudo = agoraNao(tempAgoraNao);
				if(pontConteudo == PosXNome){
					int z;
					for(j;j<qtBytes-3;j=j+2){
						matriz[i][j] = matriz[i][j+2];
						matriz[i][j+1] = matriz[i][j+3];
					}
					int *novoTamBytes = agoraSim(qtBytes-2);
					matriz[i][3] =  novoTamBytes[0];
					matriz[i][4] =  novoTamBytes[1]; 
				}
			}
		}
	}

	matriz[PosXNome][0] = '0';
	matriz[PosXConteudo][0] = '0';
}

void createRoot(char **matriz, int blocos, int bytes, tp_pilha *pilha, char *EstadoAtual)
{
	int exit = 0;
	char entrada;
	int i = 0;
	char * nome = {"root"};

	int posXNome = pop(pilha);
	int posX = pop(pilha);
	int posY = 5;
	matriz[posX][0] = '1';

	int *saida;
	saida = agoraSim(posX);
	matriz[posXNome][5] = saida[0];
	matriz[posXNome][6] = saida[1];

	matriz[posXNome][0] = '3';
	int posYNome = 7;
	matriz[posXNome][1] = 0;
	matriz[posXNome][2] = 0;
	while (nome[i] != '\0' && posYNome < bytes - 2)
	{
		matriz[posXNome][posYNome++] = nome[i++];
	}

	saida = agoraSim(posYNome);
	matriz[posXNome][3] = saida[0];
	matriz[posXNome][4] = saida[1];

	saida = agoraSim(posY);
	matriz[posX][3] = saida[0];
	matriz[posX][4] = saida[1];	

	matriz[posX][1] = 0;
	matriz[posX][2] = 0;
	printf("\n");
}

void comandos()
{
	char **matriz;
	int **matrizTamHd;
	char **matrizHd;
	tp_pilha pilha;
	char entrada[200];
	entrada[0] = '\0';
	int qtHD = 0;
	system("cls");
	char EstadoAtual[200] = "Omega";
	int blocos = 0, bytes = 0;
	while (strcmp(entrada, "exit"))
	{
		printf("%s>", EstadoAtual);
		char nome[200];
		int flag = 0;
		config(&qtHD, &matrizTamHd, &matrizHd);
		fflush(stdin);
		scanf("%s", entrada);
		if (!strcmp(entrada, "typeHD"))
		{
			if (!strcmp(EstadoAtual, "Omega"))
			{
				scanf("%s", nome);
				selectHD(qtHD, matrizHd, matrizTamHd, nome, &matriz, EstadoAtual, &blocos, &bytes);
				if (strcmp(EstadoAtual, "Omega")){
					typehd(matriz, blocos, bytes);
					strcpy(EstadoAtual, "Omega");
					strcpy(entrada, "Omega");
				}
			}
			else
			{
				typehd(matriz, blocos, bytes);
			}
			flag = 1;
		}
		if (!strcmp(entrada, "createHD"))
		{
			scanf("%s", nome);
			scanf("%d", &blocos);
			scanf("%d", &bytes);
			printf("Hd name: %s Blocos: %d Bytes: %d\n", nome, blocos, bytes);
			createHD(&qtHD, &matrizHd, nome, matriz, blocos, bytes, &matrizTamHd);

			selectHD(qtHD, matrizHd, matrizTamHd, nome, &matriz, EstadoAtual, &blocos, &bytes);
			pilha.tam = 0;
			pilha.topo = -1;
			pilha.vet = 0;
			leBlocosDisp(matriz, blocos, bytes, &pilha);

			createRoot(matriz, blocos, bytes, &pilha, EstadoAtual);
			preencher(matriz, EstadoAtual, blocos, bytes);

			flag = 1;
		}
		if (!strcmp(entrada, "removeHD"))
		{
			scanf("%s", nome);
			if (!strcmp(EstadoAtual, "Omega")){				
				removeHD(&qtHD, &matrizHd, nome, matriz, blocos, bytes, &matrizTamHd);
			}
			else
			{
				printf("Saia antes do HD\n");
			}
			
			flag = 1;
		}
		if (!strcmp(entrada, "blocosDisp"))
		{
			if (!strcmp(EstadoAtual, "Omega"))
				printf("nenhum HD selecionado\n");
			else
			{
				//Teste
				listar(&pilha);
				//FimTeste
			}
			flag = 1;
		}
		if (!strcmp(entrada, "cls"))
		{
			system("cls");
			flag = 1;
		}
		if (!strcmp(entrada, "dirHD"))
		{
			dirHD(qtHD, matrizHd, matrizTamHd);
			flag = 1;
		}
		if (!strcmp(entrada, "entradaHD"))
		{
			if (!strcmp(EstadoAtual, "Omega"))
				printf("nenhum HD selecionado\n");
			else
			{
				//carrega(matriz,EstadoAtual,blocos,bytes);
				input2(matriz);
				preencher(matriz, EstadoAtual, blocos, bytes);
			}
			flag = 1;
		}
		if (!strcmp(entrada, "selectHD"))
		{
			scanf("%s", nome);
			selectHD(qtHD, matrizHd, matrizTamHd, nome, &matriz, EstadoAtual, &blocos, &bytes);
			if (strcmp(EstadoAtual, "Omega"))
			{
				pilha.tam = 0;
				pilha.topo = -1;
				pilha.vet = 0;
				leBlocosDisp(matriz, blocos, bytes, &pilha);
			}
			flag = 1;
		}
		if (!strcmp(entrada, "create"))
		{
			if (!strcmp(EstadoAtual, "Omega"))
				printf("nenhum HD selecionado\n");
			else
			{
				//carrega(matriz,EstadoAtual,blocos,bytes);
				char nome2[200];
				scanf("%s", nome2);
				//gets(nome2);
				create(matriz, blocos, bytes, &pilha, nome2, EstadoAtual);
				preencher(matriz, EstadoAtual, blocos, bytes);
			}
			flag = 1;
		}
		if (!strcmp(entrada, "rename"))
		{
			if (!strcmp(EstadoAtual, "Omega"))
				printf("nenhum HD selecionado\n");
			else
			{
				//carrega(matriz,EstadoAtual,blocos,bytes);
				char NomeAntigo[200];
				scanf("%s", NomeAntigo);
				char NovoNome[200];
				scanf("%s", NovoNome);
				rename2(matriz, blocos, bytes, &pilha, NomeAntigo, EstadoAtual,NovoNome);
				preencher(matriz, EstadoAtual, blocos, bytes);
			}
			flag = 1;
		}
		if (!strcmp(entrada, "renamedir"))
		{
			if (!strcmp(EstadoAtual, "Omega"))
				printf("nenhum HD selecionado\n");
			else
			{
				//carrega(matriz,EstadoAtual,blocos,bytes);
				char NomeAntigo[200];
				scanf("%s", NomeAntigo);
				char NovoNome[200];
				scanf("%s", NovoNome);
				rename2(matriz, blocos, bytes, &pilha, NomeAntigo, EstadoAtual,NovoNome);
				preencher(matriz, EstadoAtual, blocos, bytes);
			}
			flag = 1;
		}
		if (!strcmp(entrada, "move"))
		{
			if (!strcmp(EstadoAtual, "Omega"))
				printf("nenhum HD selecionado\n");
			else
			{
				//carrega(matriz,EstadoAtual,blocos,bytes);
				char nome[200];
				scanf("%s", nome);
				char pasta[200];
				scanf("%s", pasta);
				move(matriz, blocos, bytes, &pilha, nome, EstadoAtual,pasta);
				preencher(matriz, EstadoAtual, blocos, bytes);
			}
			flag = 1;
		}
		if (!strcmp(entrada, "copy"))
		{
			if (!strcmp(EstadoAtual, "Omega"))
				printf("nenhum HD selecionado\n");
			else
			{
				//carrega(matriz,EstadoAtual,blocos,bytes);
				char nome[200];
				scanf("%s", nome);
				char pasta[200];
				scanf("%s", pasta);
				copy(matriz, blocos, bytes, &pilha, nome, EstadoAtual,pasta);
				preencher(matriz, EstadoAtual, blocos, bytes);
			}
			flag = 1;
		}
		if (!strcmp(entrada, "type"))
		{
			if (!strcmp(EstadoAtual, "Omega"))
				printf("nenhum HD selecionado\n");
			else
			{
				//carrega(matriz,EstadoAtual,blocos,bytes);
				char nome2[200];
				scanf("%s", nome2);
				//gets(nome2);
				type(matriz, blocos, bytes, nome2);
			}
			flag = 1;
		}
		if (!strcmp(entrada, "del"))
		{
			if (!strcmp(EstadoAtual, "Omega"))
				printf("nenhum HD selecionado\n");
			else
			{
				//carrega(matriz,EstadoAtual,blocos,bytes);
				char nome2[200];
				scanf("%s", nome2);
				//gets(nome2);
				del(matriz, blocos, bytes, nome2,EstadoAtual);				
				preencher(matriz, EstadoAtual, blocos, bytes);
				pilha.tam = 0;
				pilha.topo = -1;
				pilha.vet = 0;
				leBlocosDisp(matriz, blocos, bytes, &pilha);
			}
			flag = 1;
		}
		if (!strcmp(entrada, "rmdir"))
		{
			if (!strcmp(EstadoAtual, "Omega"))
				printf("nenhum HD selecionado\n");
			else
			{
				//carrega(matriz,EstadoAtual,blocos,bytes);
				char nome2[200];
				scanf("%s", nome2);
				//gets(nome2);
				rmdir(matriz, blocos, bytes, nome2,EstadoAtual);				
				preencher(matriz, EstadoAtual, blocos, bytes);
				pilha.tam = 0;
				pilha.topo = -1;
				pilha.vet = 0;
				leBlocosDisp(matriz, blocos, bytes, &pilha);
			}
			flag = 1;
		}
		if (!strcmp(entrada, "copyfrom"))
		{
			if (!strcmp(EstadoAtual, "Omega"))
				printf("nenhum HD selecionado\n");
			else
			{
				//carrega(matriz,EstadoAtual,blocos,bytes);
				char NomeImagem[200];
				scanf("%s", NomeImagem);
				char NovoNome[200];
				scanf("%s", NovoNome);
				copyfrom(matriz, blocos, bytes, &pilha, NomeImagem, NovoNome, EstadoAtual);
				preencher(matriz, EstadoAtual, blocos, bytes);
			}
			flag = 1;
		}
		if (!strcmp(entrada, "copyto"))
		{
			if (!strcmp(EstadoAtual, "Omega"))
				printf("nenhum HD selecionado\n");
			else
			{
				//carrega(matriz,EstadoAtual,blocos,bytes);
				char NomeImagem[200];
				scanf("%s", NomeImagem);
				char NovoNome[200];
				scanf("%s", NovoNome);
				copyto(matriz, blocos, bytes, &pilha, NomeImagem, NovoNome, EstadoAtual);
				preencher(matriz, EstadoAtual, blocos, bytes);
			}
			flag = 1;
		}
		if (!strcmp(entrada, "formatHD"))
		{
			scanf("%s", nome);
			formatHD(qtHD, matrizHd, matrizTamHd, nome, &matriz, EstadoAtual, &blocos, &bytes);
			selectHD(qtHD, matrizHd, matrizTamHd, nome, &matriz, EstadoAtual, &blocos, &bytes);
			pilha.tam = 0;
			pilha.topo = -1;
			pilha.vet = 0;
			leBlocosDisp(matriz, blocos, bytes, &pilha);

			createRoot(matriz, blocos, bytes, &pilha, EstadoAtual);
			preencher(matriz, EstadoAtual, blocos, bytes);

			//strcpy(EstadoAtual, "Omega");
			strcpy(entrada, "Omega");

			flag = 1;
		}
		if (!strcmp(entrada, "cd"))
		{
			if (!strcmp(EstadoAtual, "Omega"))
				printf("nenhum HD selecionado\n");
			else
			{
				//carrega(matriz,EstadoAtual,blocos,bytes);
				char nome2[200];
				scanf("%s", nome2);
				//gets(nome2);
				cd(matriz, blocos, bytes, &pilha, nome2, EstadoAtual);
			}
			flag = 1;
		}		
		if (!strcmp(entrada, "dir"))
		{
			if (!strcmp(EstadoAtual, "Omega"))
				printf("nenhum HD selecionado\n");
			else
			{
				dir(matriz, blocos, bytes, &pilha, EstadoAtual);
			}
			flag = 1;
		}
		if (!strcmp(entrada, "mkdir"))
		{
			if (!strcmp(EstadoAtual, "Omega"))
				printf("nenhum HD selecionado\n");
			else
			{
				//carrega(matriz,EstadoAtual,blocos,bytes);
				char nome2[200];
				scanf("%s", nome2);
				//gets(nome2);
				//create(matriz, blocos, bytes, &pilha, nome2, EstadoAtual);
				mkdir(matriz, blocos, bytes, &pilha, nome2, EstadoAtual);
				preencher(matriz, EstadoAtual, blocos, bytes);
			}
			flag = 1;
		}		
		if (!strcmp(entrada, "help"))
		{
			char comando[200];
			scanf("%s",comando);
			if(!strcmp(comando,"-a"))
				strcpy(comando,"all");
			help(comando);
			flag = 1;
		}
		if (!strcmp(entrada, "statusHD"))
		{
			
			flag = 1;
		}
		if (!strcmp(entrada, "exit"))
		{
			if (strcmp(EstadoAtual, "Omega"))
			{
				strcpy(EstadoAtual, "Omega");
				strcpy(entrada, "Omega");
			}
			flag = 1;
		}
		if (!flag)
		{
			printf("comando nao conhecido\n");
		}
		//desalocaMatriz2(matrizHd,qtHD);
		//desalocaMatrizInt2(matrizTamHd,qtHD);
	}
}

int main(int argc, char *argv[])
{
	comandos();
	printf("\nSaiu OK\n");
	system("pause");
	return 0;
}
