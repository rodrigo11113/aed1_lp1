//
// Created by ACER-PC on 02/01/2022.
//

#ifndef LP1_AED1_2021_PROJECT_H
#define LP1_AED1_2021_PROJECT_H
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX100 100

/**
 * @brief Lista ligada de clientes 1.A
 * NOTA: falta as funções inserir à cauda e à cabeça
 */
 typedef struct data
 {
     int dia;
     int mes;
     int ano;
 }DATA;

typedef struct poi
{
    char *nome;
    char *infomacao;

} POI;
typedef struct pois
{
    POI *ppois;
    int poi_size;
    int current_poi;
} POIS;
typedef struct cidade
{
    char *informacao;
    char *nome;
    float x,y;
    POIS *pois;
} CIDADE;


typedef struct cidades
{
    CIDADE *pcidades;
    int ncidades;
    int size_cidades;
} CIDADES;

typedef struct viagem
{
    int id_viagem;
    DATA * date;
    CIDADES * pcidades;
} VIAGEM;
typedef struct viagens
{

    VIAGEM *pviagens;
    int size_viagem;
    int nviagens;
} VIAGENS;
typedef struct cliente
{
    VIAGENS  *viagens;//apontador pa viagem
    char *identificaco;
    int  contacto;
    char* dataNascimento;
    char *moradaFiscal;
    int NIF;
    struct cliente *pnext;//sequalahr fazer uma dupla
} CLIENTE;

typedef struct clientes
{
    CLIENTE *pfirst;
    int nclientes;
} CLIENTES;
int main_project();
void insert_cliente_ordered(CLIENTES *pcs, char *identificaco, int contacto, char* dataNascimento, char *moradaFiscal, int NIF); // FEITO
void remove_cliente(CLIENTES *pcs,int NIF);                                                                                        // FEITO
CLIENTE * find_cliente(CLIENTES *clientes, int NIF);                                                           // FEITO
void save_clientes_bin(CLIENTES cs, char fname[]);                                                                            // FEITO
void read_clientes_bin(CLIENTES *pcs, char fname[]);                                                                          // FEITO
void editar_viagem_cliente(CLIENTE *pcliente,int id_viagem,VIAGEM * nova);
void print_clientes(CLIENTES cs);                                                                                             // FEITO

/**
 * @brief Array dinãmico de viagens 1.B
 * NOTA: falta a função redimensionar o array dinâmico e editar viagens / info viagem
 */

void create_dynarray_viagens(VIAGENS *pcs, int intsize, CLIENTE *pct);                              // FEITO
void insert_viagem_dynarray_viagens_data(VIAGENS *pcs, int id_viagem, DATA data);// FEITO
VIAGEM remove_viagem_dynarray_viagens(VIAGENS *pcs, int id_viagem);                      // FEITO
VIAGEM remove_viageminfo_dynarray_viagens(VIAGENS *pcs, int id_viagem, char informacao); // FEITO
VIAGEM *find_viagem_dynarray_viagens(VIAGENS cs, int id_viagem);                         // FEITO
void print_dynarray_viagens(VIAGENS cs);                                                 // FEITO
void free_dynarray_viagens(VIAGENS *pcs);                                                // FEITO
void editar_viagem_dynarray_viagens(VIAGEM *pcs, char *antigo,CIDADE *nova);

int diferencna_data(DATA *data1,DATA *data2);
/**
 * @brief Array dinâmico de todas as cidades 1.C
 * NOTA: falta a função redimensionar o array dinâmico e editar cidades / info cidade
 */

void create_dynarray_cidades(CIDADES *pcs, int intsize);                                 // FEITO
void insert_cidade_dynarray_cidades_nome(CIDADES *pcs, float x,float y,char* informacao, char *nome);       // FEITO
CIDADE remove_cidade_dynarray_cidades(CIDADES *pcs, char *nome);                      // FEITO
CIDADE remove_cidadeinfo_dynarray_cidades(CIDADES *pcs, int id_cidade, char informacao); // FEITO
CIDADE *find_cidade_dynarray_cidades(CIDADES cs, char *nome);                         // FEITO
void print_dynarray_cidades(CIDADES cs);// FEITO
void editar_informacao_cidade(CIDADES *pcs,char *nome,char *informacao);
void free_dynarray_cidades(CIDADES *pcs);
int comparar_nome(char* a,char* b);
/**
 *
 * @return
 */
void insert_poi_dynarray_pois(POIS *pcs, char *nome, char *info);
void create_dynarray_poi(POIS *ppois, int intsize);
POI remove_poi_dynarray_pois(POIS *pcs, char *nome);
void print_dynarray_pois(POIS pois);
POI *find_poi_dynarray_pois(POIS cs, char *nome);

void consulta_viagem_cliente(CLIENTE pc);
void consultar_viagem_cidade(VIAGENS vg,char *nome);//falta fazer para os pontos de interesse
void save_clientes_txt2(CLIENTES cs, char filename[]);
void read_clientes_txt2(CLIENTES *cs,char filename[]);
void save_clientes_relatorio_txt(CLIENTES cs, char filename[]);
#endif //LP1_AED1_2021_PROJECT_H
