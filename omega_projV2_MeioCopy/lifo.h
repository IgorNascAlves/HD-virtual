typedef struct {
    int tam;
    int topo;
    int *vet;
}tp_pilha;

int pilha_vazia(tp_pilha *pilha){
    if(pilha->topo==-1){
        return 1;
    }
    else
        return 0;
}
void push(tp_pilha *pilha, int numero){
    //int numero;
    pilha->tam++;

    pilha->vet = (int*) realloc(pilha->vet,pilha->tam*sizeof(int));

    //printf("insira numero:");
    //scanf("%i",&numero);

    pilha->topo++;
    pilha->vet[pilha->topo]=numero;
}
int pop(tp_pilha *pilha){
    if(!pilha_vazia(pilha)){
        //pilha->vet[pilha->topo]=NULL;
        pilha->topo--;
        return pilha->vet[pilha->topo+1];
    }
    else
        printf("pilha vazia!\n");
    return -1;
}

void listar(tp_pilha *pilha){
    int i;
    int n = pilha->tam;

    if(!pilha_vazia(pilha)){
        for(i=n-1;i>=0;i--){
        	if(i%10 == 0 && i!=0)
        		printf("\n");
            //if(pilha->vet[i]!=0){
            	printf("%i ",pilha->vet[i]);
       		//}
   		}
   		printf("\n");
    }
    else
         printf("pilha vazia!\n");
}
