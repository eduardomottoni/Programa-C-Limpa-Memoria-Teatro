#include <stdio.h>
#include <windows.h>
#include <time.h> 
#include <string.h>
#include <stdlib.h>


int main(){
	int e,f,i,j,k,l,m,n,terca,cancela,peca,poltlivre,*polt,peca1[61],peca2[61],peca3[61],peca4[61],peca5[61],confirmarcompra,fechardia;
	char pagantes[310],pausa[60];
	for(;;){  /////For loop continuo, para que o programa não seja encerrado automaticamente ao fim da execução
	memset(&peca1, 0, sizeof(peca1)); //Limpando toda memória das varíaveis referentes as poltronas de cada peça para que todas as poltronas fiquem disponiveis
	memset(&peca2, 0, sizeof(peca2));
	memset(&peca3, 0, sizeof(peca3));
	memset(&peca4, 0, sizeof(peca4));
	memset(&peca5, 0, sizeof(peca5));
	memset(&polt, 0, sizeof(polt));
	for (i=1;i<310;i++){ // o sistema permite simplesmente 310 operações por dia, referente a 4 peças lotadas(300) + 10, porém, a contagem começa no 1, para que fique claro ao usuário e não exista uma venda "0"
		printf("1.Vender ingresso\n2.Fechar caixa\n3.Verificar condicoes promocionais\n4.Fechar programa\n");
		scanf("%d",&f);
		system("cls");
		switch(f){
			
			case 1:
				printf("Selecione a peca\n");
				printf("1.Lago dos cisnes 16h\n2.O fantasma da opera 17h\n3.Lago dos cisnes 18h\n4.O fantasma da opera 19h\n5.O vento da cidade 20h\n\n");
				scanf("%d",&peca);
				if (peca==1){polt=&peca1[0];
				}else if (peca==2){polt=&peca2[0];
				}else if (peca==3){polt=&peca3[0];
				}else if (peca==4){polt=&peca4[0];
				}else if (peca==5){polt=&peca5[0];
				}else {printf("Peca invalida\n");
				Sleep(1000);
				system("cls");
				i--;				
				break;
				i--; // É importante coloca i-- pois a venda não foi realizada, e não queremos adicionar um espaço vazio no numero do registro
				}
				//printf("%d",i); << Este comando foi introduzido para testar se a int "i" trazia o valor recebido na lina 11 para dentro do switch case 1
				printf("\n1.Inteira\n2.Meia entrada\n3.Crianca carente isenta\n");
				scanf("%d",&j);
				if(j==1){
				}else if(j==2){
				printf("Atencao, verifique se as condicoes para meia entrada foram atendidas\n1.Prosseguir\n2.Cancelar compra\n");
				scanf("%d",&cancela);
				if(cancela==1){
				}else{
					i--;
					printf("Retornando ao menu\n");
					system("pause");
					system("cls");
					break;
					}
				
				}else if(j==3){
				printf("Hoje e terca feira e a crianca estuda em escola publica?\n1.Sim\n2.Nao\n");
				scanf("%d",&terca);
				if (terca==1){
				printf("Prosseguindo com a compra");
				Sleep(1000);
				}else{
					printf("\nHoje nao e terca feira ou outra condicao nao foi atendida, infelizmente a promocao nao e valida.\n");
					system("pause");
					i--;
					system("cls");
					break;
				}
				
				}else{printf("Opcao invalida");
				Sleep(2000);
				system("cls");
				i--;
				break;
				}
					system("cls");
					printf("\n(D=Disponivel X=Ocupada)\n");
				for(k=1;k<=60;k++){ //$$verificar caso em que as poltronas estão ocupadas
					if(polt[k]==0){
					printf("%d.D ",k);
					}else {printf("%d.X ",k);	
					}
				}
				for(e=0;e<=60;e++){ // Esse loop é interessante, e funciona da seguinte maneira: Verifica se o loop esta em 60, caso esteja, significa que todas as poltronas estavam ocupadas, pois quando uma poltrona a próxima poltrona da sequencia está ocupada ele retorna e testa se está na ultima interação do loop, caso esteja significa que todos os valores de "polt" estão ocupados
					if(e==60){
					printf("\nSinto muito, sem cadeiras para essa peca\n");
					poltlivre=0;
					Sleep(2000);
					break;}
					else if (polt[e]==1){}
					else if(polt[e]==0){
					printf("\nSelecione sua poltrona:\n");
					scanf("%d",&l); //l refere-se ao numero de poltrona escolhido pelo cliente
					poltlivre=1;
					break;}
				}
				if(l<=60&&l>0&&poltlivre==1){
				if(poltlivre==1){
				system("cls");
				printf("carregando dados da compra...");
				Sleep(1000);			
				if (polt[l]==0){printf("Os dados da compra sao:\npoltrona = %d",l);
				switch(peca){
						case 1:
							printf("\nPeca \"O lago dos cisnes\" - horario 16h\n");
							break;
						case 2:
							printf("\nPeca \"O fantasma da opera\" - horario 17h\n");
							break;
						case 3:
							printf("\nPeca \"O lago dos cisnes\" - horario 18h\n");
							break;
						case 4:
							printf("\nPeca \"O fantasma da opera\" - horario 19h\n");
							break;
						case 5:
							printf("\nPeca \"O vento da cidade\" - horario 20h\n");
								break;
							default:
							printf("\nA peça selecionada é invalida, sinto muito");
							Sleep(1000);
							system("cls");
							break;}
						struct tm *data_hora_atual;  
							time_t segundos;
							time(&segundos);   
							data_hora_atual = localtime(&segundos);  
							printf("Hora da compra ..: %d:",data_hora_atual->tm_hour); 
							printf("%d:",data_hora_atual->tm_min);
							printf("%d\n",data_hora_atual->tm_sec);
							printf("Data ..: %d/", data_hora_atual->tm_mday);
							printf("%d/",data_hora_atual->tm_mon+1); 
							printf("%d\n",data_hora_atual->tm_year+1900);
							polt[l]=1;
							//Sleep(7000); O sleep seria o tempo que o ingresso ficaria na tela, porém, com o comando CMD "pause", o usuario decide quando prosseguir
					printf("\nConfirmar compra:\n1.Sim\n2.Nao\n");
					scanf("%d",&confirmarcompra);
					if(confirmarcompra==1){
						if(j==1){strcat(pagantes,"I\n");
						}else if(j==2){
							strcat(pagantes,"M\n"); //Nesse conjunto de "ifs" é registrada a compra, sómente apos confirmar que deseja concluir a compra
						}else if(j==3){
							strcat(pagantes,"CC\n");
						}
					
					
						}else{
						
						polt[l]=0;						
						i--;
						printf("Retornando ao menu\n");
						system("pause");
						system("cls");
						break;
					}
					
					} else{
					printf("carregando dados da compra...");
					Sleep(2000);
					printf("Sinto muito, poltrona ocupada\n");
					Sleep(2500);
					i--;
					system("cls");
				
				}		
				system("cls");		
				break;}else {printf("Selecione outra peca\n");
				Sleep(2000);
				system("cls");
				}
				break;}
				else{
				
				printf("Poltrona invalida, selecione um valor de 1 a 60\n");
				Sleep(2000);
				i--;
				system("cls");
				break;
				}
			case 2:
				printf("I= inteira;M= meia;CC= crianca carente\n");
				printf("%s",pagantes);
					system("pause");
					printf("Deseja encerrar o dia?\n1.Sim\n2.Nao\n");
					scanf("%d",&fechardia);
					if(fechardia==1){
					system("cls");
					i=310; //coloco i > loop anterior, assim o loop se encerra e é reiniciado com i=0, como se fosse um novo dia de vendas
					break;}	else{
					system("cls");
					break;}
			case 3:
				system("cls");
				printf("MEIA ENTRADA=estudantes, criancas de 2 a 12 anos, idosos a partir de 60 anos e professores da rede publica de ensino\n\nISENCAO = criancas carentes da rede publica SOMENTE TERCA FEIRA\n\n");
				system("pause");
				i--;
				system("cls");
				break;		
					
			
			case 4:
				printf("Encerrando o programa, obrigado.");
				Sleep(2000);
				return 0;
				
			
			
			default:
				printf("Operacao invalida\n");
				Sleep(2000);
				system("cls");
				i--;
				break;
		}
								
	}
	
	
	
}}

