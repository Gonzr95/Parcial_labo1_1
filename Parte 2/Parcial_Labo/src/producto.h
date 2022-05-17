/*
 * struct.h
 *
 *  Created on: 8 May 2022
 *      Author: gonzr
 */

#ifndef PRODUCTO_H_
//#include "utn.h"
#define PRODUCTO_H_

#define PROD_LEN 1000
#define PROD_NOMBRE_LEN 25
#define OCUPADO 0
#define LIBRE 1
#define CANCELADO -1
#define ENTREGADO 2
#define ENVIAJE 3
#define CATEGORIA_MIN 1
#define CATEGORIA_MAX 5
#define PRECIO_MIN 1
#define PRECIO_MAX 10000
#define STOCK_MIN 0
#define STOCK_MAX 99999
#define ROPA 1
#define TECNOLOGIA 2
#define COMESTIBLE 3
#define HERRAMIENTAS 4
#define LIMPIEZA 5
#define CAT_MIN 1
#define CAT_MAX 5


typedef struct
{
	char nombre[PROD_NOMBRE_LEN];
	int categoria;
	int stock;
	int FK_userVendedorIDD;
	char FK_userMail[CORREO_LEN];
	char FK_userVendedor[NOMBRE_LEN];
	float precio;
	int idProd;
	int isEmpty;
}Producto;

int prod_initProd(Producto* list, int length);
void prod_printOne(Producto prod);
void encabezadoTablaProd(void);
void pieTablaProd(void);
int prod_cargaForzada(Producto* list, int length);
int prod_getEmptyIndex(Producto* list, int length);
int prod_findIndexById(Producto* list, int length);
int prod_altaProd(Producto* list, int length, User userLogeado);
Producto prod_cargarProd(User userLogeado);
int prod_printByStatus(Producto* list, int length, int status);
int prod_printByStatusAndStock(Producto* list, int length, int status);
int prod_bajaProd(Producto* list, int length);
int prod_modifyProd(Producto* list, int length);
void prod_prodModifier(Producto* aux);
int prod_copyArray(Producto* list, Producto* listCopy, int length);
float prod_calcAverageFLOAT(float* pResultado, Producto* list, int length);
int prod_calcTotalFLOAT(float* pResultado, Producto* list, int length);
int prod_calcSuperiorAlPromedio(Producto* list, int length, float promedio);
void encabezadoMyStock();
void pieMyStock();
void prod_printMyStockOneProduct(Producto prod);
int printMyStock(Producto* pList, User userLogeado);
int prod_printByCatStockYAlfabeticoAdmin(Producto* list, int length);
int prod_ascendingBubbleSortingAdmin(Producto* list, int length);
int prod_ascendingBubbleSortingAlfabetico(Producto* pList);
int prod_bajaProdsPorUserBaja(int userBajaID, Producto* pList);
int sortByStock(Producto* pListAux);
int prod_findProdByName(char* prodName, Producto* pList);
int prod_printProdByName(Producto* pList);


int prod_printByCat(Producto* list, int length, int order);
int prod_ascendingBubbleSorting(Producto* list, int length);
int prod_reponerStock(User userLogeado, Producto* pList);



#endif /* PRODUCTO_H_ */
