/*
 * relaciones.h
 *
 *  Created on: 8 May 2022
 *      Author: gonzr
 */

#ifndef RELACIONES_H_
#define RELACIONES_H_
#include "utn.h"
#include "user.h"
#include "producto.h"
#include "tracking.h"

int prod_comprar(Producto* list, int length, User* uList, int uIndex, Tracking* tList);
int prod_findIndexByIdV2(Producto* list, int length, int id);
int prod_checkStock(Producto* list, int indice);
int prod_updateStock(Producto* list, int indice, int qty);
int estadoCompras_printByUserID(int userID, Tracking* list, int length, int status);
void estadoDeCompra_printOne(Tracking* track, long int horaDeConsulta);
void pieEstadoDeCompras(void);
void encabezadoEstadoDeCompras(void);
int estadoDeCompras(int userID, Tracking* tList, Producto* pList);
int track_bajaTrackingByUser(Tracking* list, int length, Producto* pList, int userID);
int estadoDeVentas(User userLogeado, Producto* pList, Tracking* tList);
int findVentas(int idVendedor, Tracking* tList);
void encabezadoEstadoVentas(void);
void pieEstadoVentas(void);
void estadoDeVenta_printOne(Tracking track, char* estado);
int prod_updatearStock(Producto* list, int indice, int qty);

#endif /* RELACIONES_H_ */
