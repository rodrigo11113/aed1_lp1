//
// Created by ACER-PC on 02/01/2022.
//

#include "project.h"

/**
 * melhor individo minimiza as distancias;
 * calcular a aptidao para toda a populacao;
 * 2 A, 1 B => A A B (mais provavel sair A);
 * se tiver uma grande aptidao passa para a proxima selecao (helitismo);
 * comecar a estruturar o projeto (criar estruturas .h);
 * evitar funcoes grandes (usar pequenas funcoes dentro de funcoes);
 * nao ha menus;
 * ir vendo algoritmo;
 * criar um funcao para ver aptidao, uma para a distancia;
 *
 * user:
 *  -trip_history (id utilizador, cidades, data inicio/fim);
 *  -data_nascimento;
 *  -data_registo;
 *  -nif;
 *  -morada;
 *
 * cidade:
 *  -lat;
 *  -long;
 *  -POI (points of interest)
 *
 *
 * [A][B][C][D][E] -> conjunto de cidades (individuo) cada cidade é um gene
 * populaçao -> conjunto de individos [ [A][B][C][D][E] [A][C][B][D][E] [B][C][D][E][A] ] -> 1 populacao, 3 individuos, com 5 cidades cada um
 * o individuo visita as cidades em ciclo;
 *
 * Algoritmo Genético:
 * 1º gerar a populacao (sabendo set de cidades a visitar), gerar P individos (populacao), com N cidades (genes);
 * 2º sumatorio das distancias entre as cidades do individuo, quanto menor a distancia melhor a aptidao;
 * 3º selecionar pares de individuos para cruzar, e quais sao selecionados por elitismo para passar diretamento á proxima geracao sem cruzamento (rollete wheel (cruzam segundo a formula) e elitismo ( nao cruzam passar direto))
 * 4º cruzar e mutaçoes (proxima geraçao tera um combinaçao dos genes do pais sem estes serem repetidos) (pegar nos genes dos pais gerar um filho aleatorio e verificar se é diferente de ambos os pais);
 *      pai 1 -> [A][B][C][D][E]; pai 2 -> [A][D][B][C][E];
 *      filho 1 -> [C][D][B][A][F]; filho 2 -> [][][][][];
 * 5º mutaçoes : filho 1 -> [C][D][B][A][F]; apos mutaçao -> [A][D][B][C][F];
 * 6º repete apartir do requesito 2;
 *
 * requesito 1:
 *      [CLIENT]->[ ]->[ ]->[ ]->[ ] (lista ligada de clientes)
 *         ↓
 *      {[TRIP]} -> {[CITY][][][][]} (array dinamico de cidades)
 *      {  []  }        ↓
 *      {  []  }    {[POI]}   (array estatico ou array dinamico para points od interest)
 *      {  []  }    { [] }
 *      {  []  }    { [] }
 * (array dinamico para viagens)
 **/

int main_project()
{
    /*
    //CLIENTES pcs={NULL,0};
    char fname[]="C:\\Users\\ACER-PC\\Documents\\LP1_AED1_2021\\cliente.bin";
    char path[]="C:\\Users\\ACER-PC\\Documents\\LP1_AED1_2021\\clientes.txt";

    insert_cliente_ordered(&pcs,"Jose",911111111,"23-08-1999","rua pilinhas",111111111);
    create_dynarray_viagens(pcs.pfirst->viagens,10,pcs.pfirst);
    DATA d1={11,01,2000};
    DATA d2={11,01,3000};

    insert_viagem_dynarray_viagens_data(pcs.pfirst->viagens,1,d1);
    insert_viagem_dynarray_viagens_data(pcs.pfirst->viagens,2,d2);
    create_dynarray_cidades(find_viagem_dynarray_viagens(*pcs.pfirst->viagens,1)->pcidades,10);
    CIDADES * pcidades=find_viagem_dynarray_viagens(*pcs.pfirst->viagens,1)->pcidades;
    CIDADES * pcidades_2=find_viagem_dynarray_viagens(*pcs.pfirst->viagens,2)->pcidades;
    create_dynarray_cidades(pcidades,10);
    insert_cidade_dynarray_cidades_nome(pcidades,1.1,1.1,"ola","Porto");
    insert_cidade_dynarray_cidades_nome(pcidades,2.2,2.2,"ola","Benfica");
    insert_cidade_dynarray_cidades_nome(pcidades,3.3,3.3,"ola","Sporting");
create_dynarray_poi(find_cidade_dynarray_cidades(*pcidades,"Porto")->pois,10);
    insert_poi_dynarray_pois(find_cidade_dynarray_cidades(*pcidades,"Porto")->pois,"estadio do dragao","aaaaaaaa");
    insert_poi_dynarray_pois(find_cidade_dynarray_cidades(*pcidades,"Porto")->pois,"estadio do dragao","aaaaaaaa");
    insert_poi_dynarray_pois(find_cidade_dynarray_cidades(*pcidades,"Porto")->pois,"estadio do dragao","aaaaaaaa");
    create_dynarray_poi(find_cidade_dynarray_cidades(*pcidades,"Benfica")->pois,10);
    insert_poi_dynarray_pois(find_cidade_dynarray_cidades(*pcidades,"Benfica")->pois,"estadio da luz","aaaaaaaa");
    create_dynarray_poi(find_cidade_dynarray_cidades(*pcidades,"Sporting")->pois,10);
    insert_poi_dynarray_pois(find_cidade_dynarray_cidades(*pcidades,"Sporting")->pois,"estadio de alvalade","aaaaaaaa");
    create_dynarray_cidades(pcidades_2,10);
    insert_cidade_dynarray_cidades_nome(pcidades_2,1.1,1.1,"ola","Porto");
    create_dynarray_poi(find_cidade_dynarray_cidades(*pcidades_2,"Porto")->pois,10);
    insert_poi_dynarray_pois(find_cidade_dynarray_cidades(*pcidades_2,"Porto")->pois,"estadio do dragao","aaaaaaaa");
    CIDADE pcidade={"Ola","Antas",10.0,10.0,NULL};
    pcidade.pois=(POIS*)malloc(sizeof(POIS));
    create_dynarray_poi(pcidade.pois,10);
    insert_poi_dynarray_pois(pcidade.pois,"Rabanadas","aaaaa");
    insert_poi_dynarray_pois(pcidade.pois,"Leitao","bbbbb");
    editar_viagem_dynarray_viagens(find_viagem_dynarray_viagens(*pcs.pfirst->viagens,1),"Porto",&pcidade);
    DATA d3={01,01,3000};

    VIAGEM viagem={5,&d3,NULL};
    viagem.pcidades=(CIDADES*)malloc(sizeof(CIDADES));
    create_dynarray_cidades(viagem.pcidades,10);
    insert_cidade_dynarray_cidades_nome(viagem.pcidades,5.5,5.5,"Alta","Porquinho");
    insert_cidade_dynarray_cidades_nome(viagem.pcidades,5.5,5.5,"Baixa","Benfica");
    create_dynarray_poi(find_cidade_dynarray_cidades(*viagem.pcidades,"Porquinho")->pois,10);
    insert_poi_dynarray_pois(find_cidade_dynarray_cidades(*viagem.pcidades,"Porquinho")->pois,"gggg","ffff");
    create_dynarray_poi(find_cidade_dynarray_cidades(*viagem.pcidades,"Benfica")->pois,10);
    insert_poi_dynarray_pois(find_cidade_dynarray_cidades(*viagem.pcidades,"Benfica")->pois,"dddd","eeee");
    editar_viagem_cliente(pcs.pfirst,2,&viagem);
    print_clientes(pcs);
   //consulta_viagem_cliente(*pcs.pfirst);
   //consultar_viagem_cidade(*pcs.pfirst->viagens,"Benfica");
   //save_clientes_txt2(pcs,path);
   //read_clientes_txt2(&pcs,path);
   //print_clientes(pcs);

    CLIENTES pcs={NULL,0};
    insert_cliente_ordered(&pcs,"Jose",911111111,"23-08-1999","rua pilinhas",111111111);
    create_dynarray_viagens(pcs.pfirst->viagens,10,pcs.pfirst);
    DATA d1={11,01,2000};
    DATA d2={11,01,3000};
    DATA d3={01,01,1000};
    insert_viagem_dynarray_viagens_data(pcs.pfirst->viagens,2,d1);

    create_dynarray_cidades(find_viagem_dynarray_viagens(*pcs.pfirst->viagens,2)->pcidades,10);
    insert_cidade_dynarray_cidades_nome(find_viagem_dynarray_viagens(*pcs.pfirst->viagens,2)->pcidades,1.1,1.1,"ola","Porto");
    insert_cidade_dynarray_cidades_nome(find_viagem_dynarray_viagens(*pcs.pfirst->viagens,2)->pcidades,2.2,2.2,"ola","Benfica");
    insert_viagem_dynarray_viagens_data(pcs.pfirst->viagens,3,d2);
    create_dynarray_cidades(find_viagem_dynarray_viagens(*pcs.pfirst->viagens,3)->pcidades,10);
    insert_cidade_dynarray_cidades_nome(find_viagem_dynarray_viagens(*pcs.pfirst->viagens,3)->pcidades,3.3,3.3,"ola","Porto");
    insert_cidade_dynarray_cidades_nome(find_viagem_dynarray_viagens(*pcs.pfirst->viagens,3)->pcidades,4.4,4.4,"ola","Benfica");
    insert_viagem_dynarray_viagens_data(pcs.pfirst->viagens,4,d3);
    create_dynarray_cidades(find_viagem_dynarray_viagens(*pcs.pfirst->viagens,4)->pcidades,10);
    insert_cidade_dynarray_cidades_nome(find_viagem_dynarray_viagens(*pcs.pfirst->viagens,4)->pcidades,5.5,5.5,"ola","Porto");
    insert_cidade_dynarray_cidades_nome(find_viagem_dynarray_viagens(*pcs.pfirst->viagens,4)->pcidades,5.5,5.5,"ola","Benfica");
    print_clientes(pcs);*/
    CLIENTES pcs = {NULL, 0};
    char filename[] = "C:\\Users\\ACER-PC\\Documents\\LP1_AED1_2021\\clientesRelatorio.txt";
    insert_cliente_ordered(&pcs, "Jose Silva", 911111111, "21-03-1999", "Rua 1", 111111111);
    CLIENTE *pct = pcs.pfirst;
    create_dynarray_viagens(pct->viagens, 10, pcs.pfirst);

    /* VIAGEM 1 */
    DATA d1 = {11, 1, 2000};
    insert_viagem_dynarray_viagens_data(pct->viagens, 1, d1);
    VIAGEM *pvg = pct->viagens->pviagens;
    create_dynarray_cidades(pvg->pcidades, 10);
    /** CIDADE 1 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 0.0, 0.0, "info", "Porto");
    CIDADE *pcd = pvg->pcidades->pcidades;
    create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    pcd->pois->poi_size = 1;
    insert_poi_dynarray_pois(pcd->pois, "Estadio do Dragao", "info");
    /*** POI 2 ***/
    pcd->pois->poi_size++;
    insert_poi_dynarray_pois(pcd->pois, "Via Catarina", "info");
    /*** POI 3 ***/
    pcd->pois->poi_size++;
    insert_poi_dynarray_pois(pcd->pois, "Ponte D.Luiz", "info");
    /** CIDADE 2 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 0.0, 0.0, "info", "Benfica");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Benfica");
    create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    pcd->pois->poi_size = 1;
    insert_poi_dynarray_pois(pcd->pois, "Estadio da Luz", "info");
    /*** POI 2 ***/
    pcd->pois->poi_size++;
    insert_poi_dynarray_pois(pcd->pois, "Torre de Belem", "info");
    /*** POI 3 ***/
    pcd->pois->poi_size++;
    insert_poi_dynarray_pois(pcd->pois, "Oceanario de Lisboa", "info");
    /** CIDADE 3 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 0.0, 0.0, "info", "Braga");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Braga");
    create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    pcd->pois->poi_size = 1;
    insert_poi_dynarray_pois(pcd->pois, "Estadio de Alvalade", "info");
    /*** POI 2 ***/
    pcd->pois->poi_size++;
    insert_poi_dynarray_pois(pcd->pois, "Mosteiro dos Jerónimos", "info");
    /*** POI 3 ***/
    pcd->pois->poi_size++;
    insert_poi_dynarray_pois(pcd->pois, "Bairro Alto", "info");

    /* VIAGEM 2 */
    DATA d2 = {21, 3, 1999};
    insert_viagem_dynarray_viagens_data(pct->viagens, 2, d2);
    pvg = find_viagem_dynarray_viagens(*pct->viagens, 2);
    create_dynarray_cidades(pvg->pcidades, 10);
    /** CIDADE 1 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 0.0, 0.0, "info", "Aveiro");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Aveiro");
    // create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    // insert_poi_dynarray_pois(pcd->pois, "Estadio de Aveiro", "info");
    /** CIDADE 2 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 0.0, 0.0, "info", "Braga");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Braga");
    // create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    // insert_poi_dynarray_pois(pcd->pois, "Estadio de Braga", "info");
    /** CIDADE 3 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 0.0, 0.0, "info", "Algarve");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Algarve");
    // create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    // insert_poi_dynarray_pois(pcd->pois, "Estadio de Algarve", "info");

    /* VIAGEM 3 */
    DATA d3 = {21, 1, 1999};
    insert_viagem_dynarray_viagens_data(pct->viagens, 3, d3);
    pvg = find_viagem_dynarray_viagens(*pct->viagens, 3);
    /* NOTA: se o ultimo inserido for tb a data mais recente este nao insere as cidades*/
    create_dynarray_cidades(pvg->pcidades, 10);
    /** CIDADE 1 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 0.0, 0.0, "info", "Aveiro");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Aveiro");
    // create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    // insert_poi_dynarray_pois(pcd->pois, "Estadio do Dragao", "info");
    /** CIDADE 2 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 0.0, 0.0, "info", "Porto");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Porto");
    // create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    // insert_poi_dynarray_pois(pcd->pois, "Estadio do Dragao", "info");
    /** CIDADE 3 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 0.0, 0.0, "info", "Benfica");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Benfica");
    // create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    // insert_poi_dynarray_pois(pcd->pois, "Estadio do Dragao", "info");

    /*---------------------------------CLIENTE 2------------------------------------------*/
    insert_cliente_ordered(&pcs, "Rodrigo Branco", 922222222, "23-08-1999", "Rua 2", 222222222);
    pct = find_cliente(&pcs, 222222222);
    create_dynarray_viagens(pct->viagens, 10, pct);
    DATA d4 = {21, 3, 1999};
    DATA d5 = {21, 10, 2010};
    DATA d6 = {21, 12, 1970};
    insert_viagem_dynarray_viagens_data(pct->viagens, 1, d4);
    insert_viagem_dynarray_viagens_data(pct->viagens, 2, d5);
    insert_viagem_dynarray_viagens_data(pct->viagens, 3, d6);

    /*---------------------------------CLIENTE 3------------------------------------------*/
    insert_cliente_ordered(&pcs, "Ana Costa", 933333333, "08-10-2001", "Rua 3", 333333333);
    pct = find_cliente(&pcs, 333333333);
    create_dynarray_viagens(pct->viagens, 10, pct);
    DATA d7 = {21, 3, 2021};
    DATA d8 = {21, 10, 2015};
    DATA d9 = {21, 12, 2013};
    insert_viagem_dynarray_viagens_data(pct->viagens, 1, d7);
    insert_viagem_dynarray_viagens_data(pct->viagens, 2, d8);
    insert_viagem_dynarray_viagens_data(pct->viagens, 3, d9);

    // print_clientes(pcs);
    save_clientes_relatorio_txt(pcs, filename);

    return 0;
}

/**
 * insere ordenadamente um cliente na lista ligada de clientes
 * @param pcs - apontador para a lista ligada (CLIENTES).
 * @param identificacao - identificacao do cliente
 * @param contacto - contacto de cliente
 * @param dataNascimento - data de nascimento cliente
 * @param moradaFiscal - morada fiscal do cliente
 * @param NIF - NIF do cliente
 */
void save_clientes_relatorio_txt(CLIENTES cs, char filename[])
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("ERRO %s\n", filename);
        return;
    }
    fprintf(fp, "Clientes: %d\n\n", cs.nclientes);
    CLIENTE *pr = cs.pfirst;
    for (int i = 0; i < cs.nclientes; i++)
    {
        fprintf(fp, "\n|------------------------------------CLIENTE[%d]------------------------------------|\n", i + 1);
        fprintf(fp, "NIF -> %d\nIDENTIFICACAO -> %s\nCONTACTO -> %d\nDATA NASCIMENTO -> %s\nMORADA FISCAL -> %s\n", pr->NIF, pr->identificaco, pr->contacto, pr->dataNascimento, pr->moradaFiscal);
        fprintf(fp, "\nHistorico de Viagens:\n");
        VIAGEM *vg = pr->viagens->pviagens;
        for (int j = 0; j < pr->viagens->nviagens; j++)
        {
            fprintf(fp, "viagem[%d]-> ", j + 1);
            fprintf(fp, "%d/%d/%d\n", vg->date->dia, vg->date->mes, vg->date->ano);
            CIDADE *cd = vg->pcidades->pcidades;
            for (int k = 0; k < vg->pcidades->ncidades; k++)
            {
                fprintf(fp, "\t->cidade[%d] || ", k + 1);
                fprintf(fp, "%s, %s, %0.02f, %0.02f\n", cd->nome, cd->informacao, cd->x, cd->y);
                POI *poi = cd->pois->ppois;
                for (int l = 0; l < cd->pois->poi_size; l++)
                {
                    fprintf(fp, "\t\t||poi[%d] -> ", l + 1);
                    fprintf(fp, "%s, %s\n", poi->nome, poi->infomacao);
                    poi++;
                }
                cd++;
            }
            vg++;
        }
        pr = pr->pnext;
    }
    fclose(fp);
}
void insert_cliente_ordered(CLIENTES *pcs, char *identificaco, int contacto, char* dataNascimento, char *moradaFiscal, int NIF) {
    CLIENTE *temp = (CLIENTE *) malloc(sizeof(CLIENTE));
    CLIENTE *temp2;
    temp->viagens=(VIAGENS*)malloc(sizeof(VIAGENS));
    temp->viagens->pviagens=NULL;
    temp->viagens->nviagens=0;
    temp->viagens->size_viagem=0;
    temp->contacto = contacto;
    temp->dataNascimento = (char *) malloc(sizeof(char) * strlen(dataNascimento) + 1);
    strcpy(temp->dataNascimento, dataNascimento);
    temp->NIF = NIF;
    temp->identificaco = (char *) malloc(sizeof(char) * strlen(identificaco) + 1);
    strcpy(temp->identificaco, identificaco);
    temp->moradaFiscal = (char *) malloc(sizeof(char) * strlen(moradaFiscal) + 1);
    strcpy(temp->moradaFiscal, moradaFiscal);
    pcs->nclientes++;
    temp->pnext = NULL;

    if (pcs->pfirst == NULL) {
        pcs->pfirst = temp;
        return;
    } else {

        if (pcs->pfirst->NIF > NIF) {
            temp2 = pcs->pfirst;
            pcs->pfirst = temp;
            pcs->pfirst->pnext = temp2;
            return;
        }
        CLIENTE *current = pcs->pfirst;
        while (current->pnext != NULL && current->NIF < NIF) {
            temp2 = current;
            current = current->pnext;
        }
        if (current->NIF > NIF) {

            temp2->pnext = temp;
            temp->pnext = current;

            return;
        }
        if (current->pnext == NULL) {
            current->pnext = temp;
            current->pnext->pnext = NULL;
            return;
        }

    }
}
void print_clientes(CLIENTES cs)
{
    CLIENTE *pc = cs.pfirst;
    for (int i = 0; i < cs.nclientes; i++)
    {
        if (pc->identificaco != NULL)
        {
            printf("CLIENTE[%d] || NIF -> %d; IDENTIFICACAO -> %s; CONTACTO -> %d, DATA NASCIMENTO -> %s, MORADA FISCAL -> %s\n", i+1, pc->NIF, pc->identificaco, pc->contacto, pc->dataNascimento, pc->moradaFiscal);
            print_dynarray_viagens(*pc->viagens);
            pc = pc->pnext;
        }
        else
            return;
    }
}
void remove_cliente(CLIENTES *pcs, int NIF) {
    CLIENTE *pcl = find_cliente(pcs, NIF);
  CLIENTE *temp;
    if (pcl != NULL) {
        if(pcl==pcs->pfirst){
            printf("CLIENTE -> %s;|| NIF -> %d; Foi removido com sucesso\n", pcl->identificaco ,pcl->NIF);
            pcs->pfirst=pcl->pnext;
            pcs->nclientes--;
            return;
        }
        if(pcl->pnext->pnext==NULL){
            printf("CLIENTE -> %s;|| NIF -> %d; Foi removido com sucesso\n", pcl->pnext->identificaco ,pcl->pnext->NIF);
            pcl->pnext=NULL;
            pcs->nclientes--;
            return;
        }
        printf("CLIENTE -> %s;|| NIF -> %d; Foi removido com sucesso\n", pcl->pnext->identificaco ,pcl->pnext->NIF);
        pcl->pnext=pcl->pnext->pnext;
      pcs->nclientes--;

        return;
    }
    printf("Nao existe esse cliente com o %d\n",NIF);


}
CLIENTE * find_cliente(CLIENTES *clientes, int NIF)
{
    CLIENTE *current = clientes->pfirst;
    CLIENTE* temp;
    if(current->NIF==NIF)
        return current;
    current=current->pnext;
    while (current != NULL) {
      if(current->NIF==NIF)
          return temp;
        temp=current;
      current=current->pnext;


    }
    return NULL;
}
void save_clientes_bin(CLIENTES cs, char fname[])
{
    FILE *fp = NULL;
    fp = fopen(fname, "wb");

    if (fp == NULL)
    {
        printf("ERRO A ABRIR FICHEIRO %s PARA LEITURA!\n", fname);
        return;
    }

    fwrite(&cs.nclientes, sizeof(int), 1, fp);
    CLIENTE *pc = cs.pfirst;
    for (int i = 0; i < cs.nclientes; i++)
    {

         int size = strlen(pc->identificaco) + 1;
        int size2 = strlen(pc->moradaFiscal) + 1;
        int size3= strlen(pc->dataNascimento)+1;
        fwrite(&size, sizeof(int), 1, fp);
        fwrite(pc->identificaco, sizeof(char), size, fp);
        fwrite(&pc->contacto, sizeof(int), 1, fp);
        fwrite(&size3, sizeof(int), 1, fp);
        fwrite(pc->dataNascimento, sizeof(char), size3, fp);
        fwrite(&size2, sizeof(int), 1, fp);
        fwrite(pc->moradaFiscal, sizeof(char), size2, fp);
        fwrite(&pc->NIF, sizeof(int),1,fp);
        pc = pc->pnext;
    }

    fclose(fp);
}
void read_clientes_bin(CLIENTES *pcs, char fname[])
{
    FILE *fp=NULL;
    if((fp=fopen(fname,"rb"))==NULL){
        printf("erro");
        return;
    }
    int nclientes=0;
    fread(&nclientes, sizeof(int),1,fp);
    int size=0;
    for (int i = 0; i <nclientes ; i++) {
        char identificacao[MAX100]="";
        char dataNascimento[MAX100]="";
        char moradaFiscal[MAX100]="";
        int  NIF=0;
        int contacto=0;
        fread(&size, sizeof(int),1,fp);
        fread(&identificacao, sizeof(char),size,fp);
        fread(&contacto, sizeof(int),1,fp);
        fread(&size, sizeof(int),1,fp);
        fread(&identificacao, sizeof(char),size,fp);
        fread(&size, sizeof(int),1,fp);
        fread(&dataNascimento, sizeof(char),size,fp);
        fread(&size, sizeof(int),1,fp);
        fread(&moradaFiscal, sizeof(char),size,fp);
        fread(&NIF, sizeof(int),size,fp);
        insert_cliente_ordered(pcs,identificacao,contacto,dataNascimento,moradaFiscal,NIF);
    }
    fclose(fp);
}
void create_dynarray_viagens(VIAGENS *pcs, int intsize, CLIENTE *pct)
{
    pcs->pviagens = (VIAGEM *)calloc(intsize, sizeof(VIAGEM));
    pcs->size_viagem = intsize;
    pcs->nviagens = 0;
    pct->viagens = pcs;
}
void insert_viagem_dynarray_viagens_data(VIAGENS *pcs, int id_viagem, DATA data)
{
    int newSize = pcs->size_viagem + 10;
    int oldSize = pcs->size_viagem;

    VIAGEM *vg = NULL,*temp=NULL,temp2={0,NULL,NULL},temp3={0,NULL,NULL}, v0={0,NULL,NULL};
   DATA *pd=(DATA*)malloc(sizeof(DATA));
    if (pcs->size_viagem == pcs->nviagens)
    {
        pcs->pviagens = (VIAGEM *)realloc(pcs->pviagens, newSize * sizeof(VIAGEM));
        pcs->size_viagem = newSize;
        vg = pcs->pviagens;

        for (int i = oldSize ; i < newSize; i++)
        {
            *(vg+i) = v0;

        }
    }

   *pd=data;
    temp=pcs->pviagens;
    while(diferencna_data(temp->date,&data)!=0){
        temp++;
    }
    temp2=*temp;

    vg=temp;
    vg->date = pd;
    vg->id_viagem=id_viagem;
    vg->pcidades = (CIDADES*)malloc(sizeof(CIDADES));
    vg->pcidades->pcidades=NULL;
    vg->pcidades->size_cidades=0;
    vg->pcidades->ncidades=0;
    pcs->nviagens++;
    temp++;
    while(temp!=pcs->pviagens+pcs->size_viagem){
        temp3=*temp;
        *temp=temp2;
        temp++;
        temp2=temp3;
        if(temp->id_viagem==0){
            *temp=temp2;
            break;

        }

    }



}
int diferencna_data(DATA *d1,DATA *d2){
    if(d1==NULL){
        return 0;
    }
    if (d1->ano > d2->ano)
        return 0;

    else if (d1->ano < d2->ano)
        return 1;

    if (d1->ano == d2->ano)
    {
        if (d1->mes>d2->mes)
            return 0;
        else if (d1->mes<d2->mes)
            return 1;
        else if (d1->dia>d2->dia)
            return 0;
        else if(d1->dia<d2->dia)
            return 1;

        return 1;
    }
    return 1;
}
void print_dynarray_viagens(VIAGENS cs)
{
    VIAGEM *pvg = cs.pviagens;
     if(pvg==NULL)
         return;
    for (int i = 0; i < cs.nviagens; i++)
    {
        printf("viagem-[%d] ",i+1);
        printf("%d/%d/%d id_viagem-%d\n", pvg->date->dia,pvg->date->mes,pvg->date->ano,pvg->id_viagem);
        print_dynarray_cidades(*pvg->pcidades);
        pvg++;
    }
}
VIAGEM remove_viagem_dynarray_viagens(VIAGENS *pcs, int id_viagem)
{
    VIAGEM vg = { 0, 0, NULL};
    VIAGEM *pvg = find_viagem_dynarray_viagens(*pcs, id_viagem);

    if (pvg != NULL)
    {
        vg = *pvg;
        while (pvg < (pcs->pviagens + pcs->size_viagem - 1))
        {
            *pvg = *(pvg + 1);
            pvg++;
        }
        if (pvg == pcs->pviagens + pcs->size_viagem - 1)
        {
            pvg->id_viagem = 0;
            pvg->date =NULL;

        }
        pcs->nviagens--;
    }

    return vg;
}
void editar_viagem_dynarray_viagens(VIAGEM *pcs, char *antigo,CIDADE *nova){
    CIDADE * pc=find_cidade_dynarray_cidades(*pcs->pcidades,antigo);
    if(pc==NULL){
        printf("Nao existe cidade com o nome %s\n",antigo);
        return;
    }
    remove_cidade_dynarray_cidades(pcs->pcidades,antigo);
    insert_cidade_dynarray_cidades_nome(pcs->pcidades,nova->x,nova->y,nova->informacao,nova->nome);
    pc=find_cidade_dynarray_cidades(*pcs->pcidades,nova->nome);
    create_dynarray_poi(pc->pois,10);
    pc->pois=nova->pois;
}
VIAGEM *find_viagem_dynarray_viagens(VIAGENS cs, int id_viagem)//falar stor
{
    VIAGEM *pst = cs.pviagens;
    if (pst == NULL)
    {
        return NULL;
    }
    for (int i = 0; (i < cs.nviagens); i++)
    {
        if(pst->id_viagem==id_viagem)
            return pst;
        pst++;
    }
    return NULL;
}
void create_dynarray_cidades(CIDADES *pcs, int intsize){

    pcs->pcidades = (CIDADE *)calloc(intsize, sizeof(CIDADE));
    pcs->size_cidades = intsize;
    pcs->ncidades = 0;
}
void insert_cidade_dynarray_cidades_nome(CIDADES *pcs, float x,float y,char *informacao, char *nome){
    int newSize = pcs->size_cidades + 10;
    int oldSize = pcs->size_cidades;

    CIDADE *vg = NULL,*temp=NULL,temp2={NULL,NULL,0.0,0.0,NULL},temp3={NULL,NULL,0.0,0.0,NULL}, v0={NULL,NULL,0.0,0.0,NULL};
    if (pcs->size_cidades == pcs->ncidades)
    {
        pcs->pcidades = (CIDADE *)realloc(pcs->pcidades, newSize * sizeof(CIDADE));
        pcs->size_cidades = newSize;
        vg = pcs->pcidades;

        for (int i = oldSize ; i < newSize; i++)
        {
            *(vg+i) = v0;

        }
    }


    temp=pcs->pcidades;

    while(comparar_nome(temp->nome,nome)!=0){
        temp++;
    }
    temp2=*temp;

    vg=temp;
    vg->nome=(char*)malloc(sizeof(char)*strlen(nome)+1);
    strcpy(vg->nome,nome);
    vg->informacao=(char*)malloc(sizeof(char)*strlen(informacao)+1);
    strcpy(vg->informacao,informacao);
    vg->y=y;
    vg->x=x;
    vg->pois=(POIS*)malloc(sizeof(POIS));
    vg->pois->poi_size=0;
    vg->pois->ppois=NULL;
    vg->pois->current_poi=0;
    pcs->ncidades++;
    temp++;
    while(temp!=pcs->pcidades+pcs->size_cidades){
        temp3=*temp;
        *temp=temp2;
        temp++;
        temp2=temp3;
        if(temp->nome==NULL){
            *temp=temp2;
            break;

        }

    }
}
int comparar_nome(char* a,char* b){
    if(a==NULL)
        return 0;
    if(strcmp(a,b)>0)
        return 0;
    return 1;
}
void print_dynarray_cidades(CIDADES cs){
    CIDADE *pc=cs.pcidades;
    if(pc==NULL)
        return;
    for (int i = 0; i <cs.ncidades ; i++) {
        printf("cidade[%d] nome-%s informacao-%s x-%0.1f y-%0.1f\n",i+1,pc->nome,pc->informacao,pc->x,pc->y);
        print_dynarray_pois(*pc->pois);
        pc++;
    }
}
CIDADE *find_cidade_dynarray_cidades(CIDADES cs, char *nome){
      CIDADE *pcd =cs.pcidades;
      if(pcd ==NULL)
          return NULL;
    for (int i = 0; i <cs.ncidades ; ++i) {
        if(strcmp(pcd->nome,nome)==0)
            return pcd;
        else if(strcmp(pcd->nome,nome)>0)
            return NULL;
        pcd++;
    }
    return NULL;
}
CIDADE remove_cidade_dynarray_cidades(CIDADES *pcs, char *nome){
CIDADE  vg={NULL,NULL,0.0,0.0,NULL};
CIDADE *pc=find_cidade_dynarray_cidades(*pcs,nome);
if(pc==NULL){
    printf("Nao existe cidade com o nome %s\n",nome);
    return vg;
}
vg=*pc;
    while (pc < (pcs->pcidades + pcs->size_cidades - 1))
    {
        *pc = *(pc + 1);
        pc++;
    }
    if (pc == pcs->pcidades + pcs->size_cidades - 1)
    {
        pc->nome=NULL;
        pc->y=0.0;
        pc->x=0.0;
        pc->pois=NULL;

    }
    pcs->ncidades--;
    return vg;
}
void create_dynarray_poi(POIS *ppois, int intsize)
{

    ppois->ppois = (POI *)calloc(intsize, sizeof(POI));
    ppois->poi_size = intsize;
    ppois->current_poi = 0;
}
void insert_poi_dynarray_pois(POIS *pcs, char *nome, char *info)
{
    int newSize = pcs->poi_size + 10;
    int oldSize = pcs->poi_size;

    POI *poi = NULL, p0 = {NULL, NULL};

    if (pcs->poi_size == pcs->current_poi)
    {
        pcs->ppois = (POI *)realloc(pcs->ppois, newSize * sizeof(POI));
        pcs->poi_size = newSize;
        poi = pcs->ppois;

        for (int i = oldSize; i < newSize; i++)
        {
            *(poi + i) = p0;
        }
    }
    poi = pcs->ppois + pcs->current_poi;

    poi->nome = (char *)malloc(sizeof(char) * strlen(nome) + 1);
    strcpy(poi->nome, nome);
    poi->infomacao = (char *)malloc(sizeof(char) * strlen(info) + 1);
    strcpy(poi->infomacao, info);

    pcs->current_poi++;
}
void print_dynarray_pois(POIS pois)
{

    POI *poi = pois.ppois;
if(poi==NULL)
    return;

    for (int i = 0; i < pois.current_poi; i++)
    {
        printf("poi[%d] nome-%s | informacao-%s\n",i+1 ,poi->nome, poi->infomacao);
        poi++;
    }
}
POI remove_poi_dynarray_pois(POIS *pcs, char *nome)
{
    POI  vg={NULL,NULL};
    POI *pc=find_poi_dynarray_pois(*pcs,nome);
    if(pc==NULL){
        printf("Nao existe poi com o nome %s\n",nome);
        return vg;
    }
    vg=*pc;
    while (pc < (pcs->ppois + pcs->poi_size - 1))
    {
        *pc = *(pc + 1);
        pc++;
    }
    if (pc == pcs->ppois + pcs->poi_size - 1)
    {
        pc->nome=NULL;
        pc->infomacao=NULL;

    }
    pcs->current_poi--;
    return vg;
}
POI *find_poi_dynarray_pois(POIS cs, char *nome)
{
    POI *ppoi = cs.ppois;
    if(ppoi ==NULL)
        return NULL;
    for (int i = 0; i <cs.current_poi ; ++i) {
        if(strcmp(ppoi->nome,nome)==0)
            return ppoi;
        ppoi++;
    }
    return NULL;
}

void editar_informacao_cidade(CIDADES *pcs,char *nome,char *informacao){
    CIDADE *pc=find_cidade_dynarray_cidades(*pcs,nome);
    if(pc==NULL)
        return;

    pc->informacao=(char*)malloc(sizeof(char)*strlen(informacao)+1);
    strcpy(pc->informacao,informacao);
}
void editar_viagem_cliente(CLIENTE *pcliente,int id_viagem,VIAGEM * nova){
    VIAGEM *pviagem=find_viagem_dynarray_viagens(*pcliente->viagens,id_viagem);
    if (pviagem==NULL)
        return;
    remove_viagem_dynarray_viagens(pcliente->viagens,id_viagem);
    insert_viagem_dynarray_viagens_data(pcliente->viagens,nova->id_viagem,*nova->date);
    find_viagem_dynarray_viagens(*pcliente->viagens,nova->id_viagem)->pcidades=nova->pcidades;

}
void consulta_viagem_cliente(CLIENTE pc){
    printf("%s\n",pc.identificaco);
    print_dynarray_viagens(*pc.viagens);
}
void consultar_viagem_cidade(VIAGENS vg,char *nome){
    CIDADE * pcidade=NULL;
    VIAGEM *pviagem=vg.pviagens;
    for (int i = 0; i <vg.nviagens ; i++) {
      pcidade=find_cidade_dynarray_cidades(*pviagem->pcidades,nome);
        if(pcidade!=NULL){
            printf("viagem com id-%d\n",pviagem->id_viagem);
            printf("cidade-%s x-%0.1f y-%0.1f descricao- %s \n",pcidade->nome,pcidade->x,pcidade->y,pcidade->informacao);
            print_dynarray_pois(*pcidade->pois);
    }
        pviagem++;
                    }

}
void save_clientes_txt2(CLIENTES cs, char filename[])
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("ERRO %s\n", filename);
        return;
    }
    CLIENTE *pr = cs.pfirst;
    fprintf(fp,"%d\n",cs.nclientes);
    for (int i = 0; i < cs.nclientes; i++)
    {
        fprintf(fp, "%d,%s,%d,%s,%s,\n", pr->NIF, pr->identificaco, pr->contacto, pr->dataNascimento, pr->moradaFiscal);
        VIAGEM *pviagem=pr->viagens->pviagens;
        fprintf(fp,"%d\n",pr->viagens->nviagens);
        for (int j = 0; j < pr->viagens->nviagens; j++)
        {
            fprintf(fp, "%d,%d,%d,%d\n", pviagem->id_viagem,pviagem->date->dia, pviagem->date->mes, pviagem->date->ano);
            CIDADE *pcidade=pviagem->pcidades->pcidades;
            fprintf(fp,"%d\n",pviagem->pcidades->ncidades);
            for (int k = 0; k <pviagem->pcidades->ncidades ; k++) {
                fprintf(fp,"%s,%s,%0.1f,%0.1f\n",pcidade->nome,pcidade->informacao,pcidade->x,pcidade->y);
                POI *poi=pcidade->pois->ppois;
                fprintf(fp,"%d\n",pcidade->pois->current_poi);
                for (int l = 0; l <pcidade->pois->current_poi ; l++) {
                    fprintf(fp,"%s,%s,\n",poi->nome,poi->infomacao);
                    poi++;
                }
            pcidade++;
            }
            pviagem++;
        }
        pr++;
    }
    fclose(fp);
}
void read_clientes_txt2(CLIENTES *cs,char filename[]){

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("ERRO %s\n", filename);
        return;
    }
    int size=0;
    int size2=0;
    int size3=0;
    int size4=0;
 fscanf(fp,"%d",&size);
    char identificaco[100]="";
    int  contacto;
    char dataNascimento[100]="";
    char moradaFiscal[100]="";
    int NIF;
    int id_viagem;
    DATA  date;
    char informacao[100];
    char nome[100];
    float x,y;
    for (int i = 0; i <size ; i++) {
           fscanf(fp,"%d%*[,]%[^,]%*[,]%d%*[,]%[^,]%*[,]%[^,]%*[,]",&NIF,identificaco,&contacto,dataNascimento,moradaFiscal);
           insert_cliente_ordered(cs,identificaco,contacto,dataNascimento,moradaFiscal,NIF);
           CLIENTE *pcliente=cs->pfirst;
           fscanf(fp,"%d",&size2);


        for (int j = 1; j < cs->nclientes ; j++) {
            pcliente=pcliente->pnext;
        }
           create_dynarray_viagens(pcliente->viagens,size2,pcliente);
        VIAGEM *pviagem=pcliente->viagens->pviagens;
        for (int k = 0; k < pcliente->viagens->size_viagem; k++) {
           fscanf(fp,"%d%*[,]%d%*[,]%d%*[,]%d",&id_viagem,&date.dia,&date.mes,&date.ano);
           insert_viagem_dynarray_viagens_data(pcliente->viagens,id_viagem,date);
           fscanf(fp,"%d",&size3);
           create_dynarray_cidades(pviagem->pcidades,size3);
           CIDADE * pcidade=pviagem->pcidades->pcidades;
            for (int j = 0; j <pviagem->pcidades->size_cidades ; j++) {
                fscanf(fp,"%*[\n]%[^,]%*[,]%[^,]%*[,]%f%*[,]%f",nome,informacao,&x,&y);
                insert_cidade_dynarray_cidades_nome(pviagem->pcidades,x,y,informacao,nome);
                fscanf(fp,"%d",&size4);
                create_dynarray_poi(pcidade->pois,size4);
                POI * ppoi=pcidade->pois->ppois;
                for (int l = 0; l <pcidade->pois->poi_size ; l++) {
                 fscanf(fp,"%*[\n]%[^,]%*[,]%[^,]%*[,]",nome,informacao);
                 insert_poi_dynarray_pois(pcidade->pois,nome,informacao);
                 ppoi++;
                }
                pcidade++;
            }
        pviagem++;
        }
    }
}

