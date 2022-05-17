/*
 * relaciones.c
 *
 *  Created on: 8 May 2022
 *      Author: gonzr
 */
#include "relaciones.h"



void encabezadoEstadoDeCompras(void)
{

//	             11               25                  7        10            16                    25
	printf("+-----------+-------------------------+-------+----------+----------------+-------------------------+\n");
	printf("|TRACKING ID|        PRODUCTO         |PROD ID| CANTIDAD |     ESTADO     |           ETA           |\n");
	printf("+-----------+-------------------------+-------+----------+----------------+-------------------------+\n");
}
void pieEstadoDeCompras(void)
{
	printf("+-----------+-------------------------+-------+----------+----------------+-------------------------+\n\n");
}

void encabezadoEstadoVentas(void)
{
	printf("+-----------+-------------------------+-------+----------+----------------+\n");
	printf("|TRACKING ID|        PRODUCTO         |PROD ID| CANTIDAD |     ESTADO     |\n");
	printf("+-----------+-------------------------+-------+----------+----------------+\n");
}
void pieEstadoVentas(void)
{
	printf("+-----------+-------------------------+-------+----------+----------------+\n\n");
}

void estadoDeVenta_printOne(Tracking track, char* estado)
{
	printf("|%-11d|%-25s|%-7d|%-10d|%-16s|\n"
	,track.idTracking,track.FK_prodName,track.idProducto,track.qty,estado);
}
/// @fn void track_printOne(Tracking)
/// @brief imprime solo un dato del tipo Tracking
/// el numero que va dsp del % es correlativo con la cantidad de - que tiene el encabezado
/// @param Tracking
void estadoDeCompra_printOne(Tracking* track, long int horaDeConsulta)
{
//	             11               25                  7        10            16                    25
	double llegaEn;
	llegaEn = difftime(horaDeConsulta, track->ETA);//saco la diferencia entre compra y consulta
//	printf("DEBUG la diferencia es: %.2f",llegaEn);

	char ETA[30];
	track->ETA = sumarSegundos(-(long int)llegaEn, horaDeConsulta);//actualizo el horario de llegada

	escribirHoraStringActual(ETA, 30);
	char estado[20];
	if(track->isEmpty == CANCELADO)
	{
		strncpy(estado,"Cancelado",20);
	}
	else
	{
		if(track->ETA>horaDeConsulta)
		{
			strncpy(estado,"En viaje",20);
			track->isEmpty = ENVIAJE;
		}
		else
		{
			strncpy(estado,"Entregado",20);
			track->isEmpty = ENTREGADO;
		}
	}
//	printf("estado de is empty en el print one es : %d",track->isEmpty);
	printf("|%-11d|%-25s|%-7d|%-10d|%16s|%25s|\n"
	,track->idTracking,track->FK_prodName,track->idProducto,track->qty,estado,ETA);
}

/// @fn int track_printByStatus(Tracking*, int, int)
/// @brief imprime los datos del struct por estado de variable isEmpty
///
/// @param list
/// @param length
/// @param status valor que queremos buscar e imrpimer de IsEMpty
/// @return -n ERRORES // 0 SUCCESS
int estadoCompras_printByUserID(int userID, Tracking* list, int length, int status)
{
	int ret = -1; //NULL LIST
	int flagHayCompras = 0;
	if(list != NULL)
	{
		if(length > 0)
		{
			long int horaActual;
			horaActual = time(NULL);
			int i;
			for(i=0; i<length; i++)
			{
				if(list[i].isEmpty != status && list[i].FK_userCompradorID == userID)
				{
					if(flagHayCompras == 0)
					{
						encabezadoEstadoDeCompras();
						flagHayCompras = 1;
					}
					estadoDeCompra_printOne(&list[i], horaActual);
					ret = 0;
				}

			}
			if(flagHayCompras == 1)
			{
				pieEstadoDeCompras();
			}
			else
			{
				printf("Todavia no tenes compras\n");
			}


		}
		else
		{
			ret = -2; //la longitud de la lista es menor a 1
		}
	}
	return ret;
}


/// @fn int prod_findIndexById(Producto*, int)
/// @brief pide el ID de un strut1 y retorna en que posicion del array se encuentra
///
/// @param list array de struc1
/// @param length longitud del mismo
/// @return el indice en el que se encuentra ese ID o errores
int prod_findIndexByIdV2(Producto* list, int length, int id)
{
	int ret = -1; // lista NULL
	if(list != NULL)
	{
		if(length > 0)
		{

			int i;
			for(i=0; i<length; i++)
			{
				if(id == list[i].idProd)
				{
					if(list[i].isEmpty == OCUPADO)
					{
						ret = i; // retorno el indice en el que se encuentra ese ID
						break;
					}
					else
					{
						ret = -5; //HUBO COINCIDENCIA PERO el pasajero no estaba ocupado
					}
				}
				else
				{
					ret = -4; //no hubo coincidencia entre el id ingresado y los que habia disponibles
				}
			}
		}
		else
		{
			ret = -2; // length menor a
		}
	}
	return ret;
}

int prod_comprar(Producto* list, int length, User* uList, int uIndex, Tracking* tList)
{
	int ret = -1;//null list
	if(list != NULL)
	{
		if(length >0)
		{
			int idProd;
			if(utn_getNumero(&idProd, "Ingrese el ID del producto que desea comprar\n", "ERROR\n", 1000, 3000, 2) == 0)
			{
				int pIndexAux;
				pIndexAux = prod_findIndexByIdV2(list, length,idProd);
				if(pIndexAux>=0)
				{
					int stock;
					stock = prod_checkStock(list, pIndexAux);
					if(stock > 0)
					{
						int qty;
						if(utn_getNumero(&qty, "Cuantas unidades desea comprar?\n", "ERROR\n", 1, stock, 2) == 0)
						{
							//aca estaria bueno poner un if(hay lugar vacio en la lista de trackings y si no hay no se realiza la compra
							if(validateExit_YN("****************ATENCION****************\n"
									           "*******Estas a un paso de comprar*******\n"
									           "*Presione Y/N para confirmar o cancelar*\n", "ERROR\n", 2) == 1)
							{
								prod_updateStock(list, pIndexAux, qty);
								ret = 0;
								track_altaTracking(tList, length, uIndex, uList, qty, list, pIndexAux);
								//generar tracking


							}
							else
							{
								ret = -7; // no quiere el producto
							}
						}
						else
						{
							ret = -6; //error de utn get num
						}
					}
					else
					{
						printf("Id Invalido, vuelvo al menu\n");
						ret = -5;//no hay stock
					}

				}
				else
				{
					printf("No");
					ret =  -4; //error al encontrar el indice
				}
			}
			else
			{
				ret = -3;//error de utn get num
			}
		}
		else
		{
			ret = -2; // ERROR de length
		}
	}
	return ret;
}

int prod_checkStock(Producto* list, int indice)
{
	int ret = -1;//null list
	if(list != NULL)
	{

		if(list[indice].stock > 0)
		{
			ret = list[indice].stock;
		}
	}
	return ret;
}

int prod_updateStock(Producto* list, int indice, int qty)
{
	int ret = -1; //null list
	// lo hago negativo por si en algunn momento
	qty = qty * (-1);

	if(list != NULL)
	{
		list[indice].stock = list[indice].stock + qty;
		printf("El nuevo stock es: %d\n\n",list[indice].stock);
		ret = 0; //SUCCESS
	}
	return ret;
}

int prod_updatearStock(Producto* list, int indice, int qty)
{
	int ret = -1; //null list
	// lo hago negativo por si en algunn momento

	if(list != NULL)
	{
		list[indice].stock = list[indice].stock + qty;
		printf("El nuevo stock es: %d\n\n",list[indice].stock);
		ret = 0; //SUCCESS
	}
	return ret;
}


int estadoDeCompras(int userID, Tracking* tList, Producto* pList)
{
	int ret = -1;
	int opcion;
	do
	{
		utn_getNumero(&opcion, "1)Ver estado de compras\n"
				"2)Dar de baja una compra\n"
				"3)Salir\n", "ERROR\n", 1, 3, 2);
		switch(opcion)
		{
		case 1:
			estadoCompras_printByUserID(userID, tList, TRACKING_LEN, LIBRE);
			break;
		case 2:
			if(track_bajaTrackingByUser(tList, TRACKING_LEN, pList, userID) == 0)
			{
				printf("Ha dado de baja la compra y el producto ha vuelto a estar en stock\n");
			}
			else
			{
//				printf("Algo ha ocurrido\n");
			}
			break;
		}
	}while(opcion != 3);


	return ret;
}



/// @fn int track_bajatrack(Tracking*, int)
/// @brief reescribe el campo isEmpty como LIBRE para dar de baja al struct
///
/// @param list array a analizar
/// @param length longitud del mismo
/// @return -n ERRORES / 0 SUCCESS
int track_bajaTrackingByUser(Tracking* list, int length, Producto* pList, int userID)
{
	int ret = -1;
	int idProd;

	if(list != NULL)
	{
		if(length > 0)
		{
			if(estadoCompras_printByUserID(userID, list, TRACKING_LEN, LIBRE) == 0)
			{
				utn_getNumero(&idProd, "Ingrese el ID del producto que desea cancelar su compra\n", "ERROR\n", 1000, 2000, 2);
				if(idProd >= 1000 && idProd <=3000)
				{
					int indexBaja;
					indexBaja = track_findIndexByProdId(list, idProd);
					if(indexBaja >= 0)
					{
						if(list[indexBaja].isEmpty == CANCELADO)
						{
							printf("No puede dar de baja una compra ya cancelada\n");
						}
						else
						{
							if(validateExit_YN("Estas seguro de dar de baja?? Y/N\n", "ERROR, revise opciones\n", 2) == 1)
							{
								if(list[indexBaja].isEmpty == ENTREGADO)
								{
									printf("No puede cancelar una compra ya recibida\n");
									//no puede cancelar una compra entregada
								}
								else
								{
									list[indexBaja].isEmpty = CANCELADO;
									int pIndex;
									pIndex = prod_findIndexByIdV2(pList, PROD_LEN, idProd);
									if(pIndex >= 0)
									{
										ret = 0;
										prod_updateStock(pList, pIndex, -list[indexBaja].qty);
									}
									else
									{
		//								printf("Error al encontrar el index del producto para volverlo al stock\n");
									}

								}
							}
						}

					}
					else
					{
						printf("ID invalido\n");
					}

				}
				else
				{
					ret = -3; // error al encontrar el index del ID
				}
			}
			else
			{
//				printf("Usted todavia no tiene compras\n");
			}

		}
		else
		{
			ret = -2; //LENGTH INCORRECTA
		}
	}
	return ret;
}


int estadoDeVentas(User userLogeado, Producto* pList, Tracking* tList)
{
	int ret = -1;
	int opcion;
	do
	{
		utn_getNumero(&opcion, "1)Estado de ventas\n2)Mis productos\n3)Salir\n", "ERROR\n", 1, 3, 2);
		switch(opcion)
		{
			case 1:
				if(findVentas(userLogeado.idUsuario, tList) == 0)
				{
					pieEstadoVentas();
				}
				else
				{
					printf("No tiene ventas todavia\n");
				}
				break;
			case 2:
				if(printMyStock(pList, userLogeado) == -1)
				{
					printf("No tiene productos a la venta o con stock\n");
				}
				break;
		}
	}while(opcion!=3);

	return ret;
}


int findVentas(int idVendedor, Tracking* tList)
{
	long int horaActual = time(NULL);
	int ret = -1;
	int i;
	int flagHayVentas=0;
	for(i=0; i<TRACKING_LEN; i++)
	{
		if(tList[i].FK_userVendedorID  == idVendedor)
		{
			if(flagHayVentas == 0)
			{
				encabezadoEstadoVentas();
				flagHayVentas = 1;
			}
			char estado[30];
			if(tList[i].isEmpty == CANCELADO)
			{
				strncpy(estado,"CANCELADO",30);
				estadoDeVenta_printOne(tList[i], estado);

			}
			else
			{
				if(tList[i].ETA>=horaActual)
				{
					strncpy(estado,"EN VIAJE",30);
					estadoDeVenta_printOne(tList[i], estado);
					//imprimir el estado en viaje
				}
				else
				{
					strncpy(estado,"ENTREGADO",30);
					estadoDeVenta_printOne(tList[i], estado);
				}
			}

			ret = 0;
		}
	}
	return ret;
}


