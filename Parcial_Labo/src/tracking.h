/*
 * struct3.h
 *
 *  Created on: 8 May 2022
 *      Author: gonzr
 */

#ifndef TRACKING_H_
#define TRACKING_H_

#define TRACKING_LEN 2000



typedef struct
{
	int idTracking;
	int idProducto;
	char FK_prodName[PROD_NOMBRE_LEN];
	int FK_userIndex;
	int FK_userCompradorID;
	int FK_userVendedorID;
	char FK_compradorName[NOMBRE_LEN];
	int qty;
	int distancia;
	long int horaDeCompra;
	long int ETA;
	int isEmpty;
}Tracking;

int track_initTrack(Tracking* list, int length);
void track_printOne(Tracking track);
void encabezadoTablaTrack(void);
void pieTablaTrack(void);
int track_cargaForzada(Tracking* list, int length);
int track_getEmptyIndex(Tracking* list, int length);
int track_findIndexById(Tracking* list, int length);
int track_altaTracking(Tracking* tList, int length, int uIndexAux, User* uList, int qty, Producto* pList, int pIndexAux);
Tracking track_cargarTrack (void);
int track_printByStatus(Tracking* list, int length, int status);
int track_bajaTrack(Tracking* list, int length);
int track_modifyTrack(Tracking* list, int length);
void track_trackModifier(Tracking* aux);
int track_copyArray(Tracking* list, Tracking* listCopy, int length);
float track_calcAverageFLOAT(float* pResultado, Tracking* list, int length);
int track_calcTotalFLOAT(float* pResultado, Tracking* list, int length);
int track_calcSuperiorAlPromedio(Tracking* list, int length, float promedio);
int track_calcDistancia(int cp);
long int calcETA(Tracking trackAux);
int track_findIndexByProdId(Tracking* tList, int prodID);
void encabezadoTrackingGlobal(void);
void pieTrackingGlobal(void);
void printOneTrack(Tracking track);
int track_printTrackingAdmin(Tracking* tList);

#endif /* TRACKING_H_ */
