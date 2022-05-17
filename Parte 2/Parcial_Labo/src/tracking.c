/*
 * struct3.c
 *
 *  Created on: 8 May 2022
 *      Author: gonzr
 */
#include "relaciones.h"

/*
 * struct.c
 *
 *  Created on: 8 May 2022
 *      Author: gonzr
 */
#include "relaciones.h"


//--------------------Generador de ID's--------------
static int idAutoIncremental = 1000;
static int track_generateID();
/// @fn int track_generateID()
/// @brief genera un id en base a un contador
///
/// @return retorna el id
static int track_generateID()
{
	return idAutoIncremental++;
}
//--------------------Generador de ID's--------------



/// @fn int track_initTracking(Tracking array[], int length)
/// @brief Initiates the array changing the member isEmpty to 1 (TRUE)
///
/// @param array Pointer to array of trackengers
/// @param length Length of the array
/// @return -1 length minor to one, -2 NULL pointer
int track_initTrack(Tracking* list, int length)
{
	int ret = -1;
	int i;
	if(list != NULL)
	{
		if(length > 0)
		{
			ret = 0;
			for(i=0; i<length; i++)
			{
				list[i].isEmpty = LIBRE;
			}
		}
		else
		{
			ret = -1; //length minor to one
		}
	}
	else
	{
		ret = -2; //NULL pointer
	}
	return ret;
}

/// @fn void track_printOne(Tracking)
/// @brief imprime solo un dato del tipo Tracking
/// el numero que va dsp del % es correlativo con la cantidad de - que tiene el encabezado
/// @param Tracking
void track_printOne(Tracking track)
{
    // 11                   25                  10          11            15
	//TRACKING           PRODUCTO            CANTIDAD   DISTANCIA        ETA
	char hora[30];
	strncpy(hora,ctime(&track.ETA),30); //recibe un long int y retorna en un string la fecha y hora
	dinamitarNuevaLinea(hora, sizeof(hora));
	printf( "|%-11d|%-25s|%10d|%8dkms|%-25s|%25s|\n"
			,track.idTracking,track.FK_prodName,track.qty,track.distancia,track.FK_compradorName,hora);



}
void encabezadoTablaTrack(void)
{
	        // 11                   25                  10          11                25
			//TRACKING           PRODUCTO            CANTIDAD   DISTANCIA             ETA                        26
	printf("+-----------+-------------------------+----------+-----------+-------------------------+-------------------------+\n");
	printf("|TRACKING ID|        PRODUCTO         | CANTIDAD | DISTANCIA |         COMPRADOR       |           ETA           |\n");
	printf("+-----------+-------------------------+----------+-----------+-------------------------+-------------------------+\n");
}
void pieTablaTrack(void)
{
	printf("+-----------+-------------------------+----------+-----------+-------------------------+-------------------------+\n\n");
}

/// @fn int track_cargaForzada(Tracking*, int)
/// @brief hardcodea datos con el fin de adelantar el testing de nuestro programa
///
/// @param list puntero a larray de track
/// @param length longitud de dicho array
/// @return -1 NULL list  // -2 longitud muy pequeña  //
int track_cargaForzada(Tracking* list, int length)
{
	int ret = -1; //LIST NULL
	Tracking trackAux[8];
	if(list != NULL)
	{
		if(length >0)
		{
			trackAux[0].idTracking = track_generateID();
			trackAux[0].idProducto = 1000;
			trackAux[0].qty = 1;
			trackAux[0].FK_userCompradorID=1005;
			trackAux[0].horaDeCompra=time(NULL);
			trackAux[0].distancia=20;
			trackAux[0].ETA=sumarSegundos(trackAux[0].distancia,trackAux[0].horaDeCompra);
			strncpy(trackAux[0].FK_prodName,"Zapas NIKE",PROD_NOMBRE_LEN);
			strncpy(trackAux[0].FK_compradorName,"Juan",NOMBRE_LEN);
			trackAux[0].isEmpty = OCUPADO;

			trackAux[1].idTracking = track_generateID();
			trackAux[1].idProducto = 1001;
			trackAux[1].qty = 1;
			trackAux[1].FK_userCompradorID=1005;
			trackAux[1].horaDeCompra=time(NULL);
			trackAux[1].distancia=20;
			trackAux[1].ETA=sumarSegundos(trackAux[1].distancia,trackAux[1].horaDeCompra);
			strncpy(trackAux[1].FK_prodName,"Zapas Adidas",PROD_NOMBRE_LEN);
			strncpy(trackAux[1].FK_compradorName,"Juan",NOMBRE_LEN);
			trackAux[1].isEmpty = OCUPADO;

			trackAux[2].idTracking = track_generateID();
			trackAux[2].idProducto = 1006;
			trackAux[2].qty = 1;
			trackAux[2].FK_userCompradorID=1003;
			trackAux[2].horaDeCompra=time(NULL);
			trackAux[2].distancia=80;
			trackAux[2].ETA=sumarSegundos(trackAux[2].distancia,trackAux[2].horaDeCompra);
			strncpy(trackAux[2].FK_prodName,"Destornillador Philips",PROD_NOMBRE_LEN);
			strncpy(trackAux[2].FK_compradorName,"Ivan",NOMBRE_LEN);
			trackAux[2].isEmpty = OCUPADO;

			trackAux[3].idTracking = track_generateID();
			trackAux[3].idProducto = 1003;
			trackAux[3].qty = 1;
			trackAux[3].FK_userCompradorID=1005;
			trackAux[3].horaDeCompra=time(NULL);
			trackAux[3].distancia=80;
			trackAux[3].ETA=sumarSegundos(trackAux[3].distancia,trackAux[3].horaDeCompra);
			strncpy(trackAux[3].FK_prodName,"Celular Samsung a20",PROD_NOMBRE_LEN);
			strncpy(trackAux[3].FK_compradorName,"Ivan",NOMBRE_LEN);
			trackAux[3].isEmpty = OCUPADO;

			trackAux[4].idTracking = track_generateID();
			trackAux[4].idProducto = 1009;
			trackAux[4].qty = 2;
			trackAux[4].FK_userCompradorID=1001;
			trackAux[4].horaDeCompra=time(NULL);
			trackAux[4].distancia=30;
			trackAux[4].ETA=sumarSegundos(trackAux[4].distancia,trackAux[4].horaDeCompra);
			strncpy(trackAux[4].FK_prodName,"Detergente",PROD_NOMBRE_LEN);
			strncpy(trackAux[4].FK_compradorName,"Gonzalo",NOMBRE_LEN);
			trackAux[4].isEmpty = OCUPADO;

			trackAux[5].idTracking = track_generateID();
			trackAux[5].idProducto = 1005;
			trackAux[5].qty = 1;
			trackAux[5].FK_userCompradorID=1001;
			trackAux[5].horaDeCompra=time(NULL);
			trackAux[5].distancia=30;
			trackAux[5].ETA=sumarSegundos(trackAux[5].distancia,trackAux[5].horaDeCompra);
			strncpy(trackAux[5].FK_prodName,"Papas de tubo Lays",PROD_NOMBRE_LEN);
			strncpy(trackAux[5].FK_compradorName,"Gonzalo",NOMBRE_LEN);
			trackAux[5].isEmpty = OCUPADO;

			trackAux[6].idTracking = track_generateID();
			trackAux[6].idProducto = 1000;
			trackAux[6].qty = 1;
			trackAux[6].FK_userCompradorID=1002;
			trackAux[6].horaDeCompra=time(NULL);
			trackAux[6].distancia=30;
			trackAux[6].ETA=sumarSegundos(trackAux[6].distancia,trackAux[6].horaDeCompra);
			strncpy(trackAux[6].FK_prodName,"Zapas NIKE",PROD_NOMBRE_LEN);
			strncpy(trackAux[6].FK_compradorName,"Agostina",NOMBRE_LEN);
			trackAux[6].isEmpty = OCUPADO;

			trackAux[7].idTracking = track_generateID();
			trackAux[7].idProducto = 1007;
			trackAux[7].qty = 2;
			trackAux[7].FK_userCompradorID=1002;
			trackAux[7].horaDeCompra=time(NULL);
			trackAux[7].distancia=30;
			trackAux[7].ETA=sumarSegundos(trackAux[7].distancia,trackAux[7].horaDeCompra);
			strncpy(trackAux[7].FK_prodName,"Colgate 3x accion",PROD_NOMBRE_LEN);
			strncpy(trackAux[7].FK_compradorName,"Agostina",NOMBRE_LEN);
			trackAux[7].isEmpty = OCUPADO;

			//hardcodear 4 mas de estos cosos

			int i;
			for(i=0; i<7; i++)
			{
				list[track_getEmptyIndex(list, TRACKING_LEN)] = trackAux[i];
			}
			ret = 0; //SUCCESS
		}
		else
		{
			ret = -2; // LENGTH MENOR A 0
		}
	}
	return ret;
}

/// @fn int track_getEmptyIndex(Tracking*, int, int)
/// @brief	busca un lugar vacio en el array
///
/// @param array
/// @param length
/// @return -1 NO HAY LUGAR; -2 EL ARRAY ES NULO; -3 LENGTH MENOR A 1
int track_getEmptyIndex(Tracking* list, int length)
{
	int ret = -1; //NO HAY LUGAR
	if(list != NULL)
	{
		if(length>0)
		{
			int i;
			for(i=0; i<length; i++)
			{
				if(list[i].isEmpty == LIBRE)
				{
					ret = i;
					break;
				}
			}
		}
		else
		{
			ret = -3; // ERROR, lenght menor a 1
		}
	}
	else
	{
		ret = -2; // ERROR, array es nulo
	}
	return ret;
}


/// @fn int track_findIndexById(Tracking*, int)
/// @brief pide el ID de un strut1 y retorna en que posicion del array se encuentra
///
/// @param list array de struc1
/// @param length longitud del mismo
/// @return el indice en el que se encuentra ese ID o errores
int track_findIndexById(Tracking* list, int length)
{
	int ret = -1; // lista NULL
	int idAux;
	if(list != NULL)
	{
		if(length > 0)
		{
			if(utn_getNumero(&idAux, "Ingrese el ID de 4 digitos de la track que busca\n", "ERROR, reintente\n", 0, 9999, 2) == 0)
			{
				int i;
				for(i=0; i<length; i++)
				{
					if(idAux == list[i].idTracking)
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
				ret = -3; //error al obtener num
			}
		}
		else
		{
			ret = -2; // length menor a
		}
	}
	return ret;
}

int track_findIndexByProdId(Tracking* tList, int prodID)
{
	int ret = -1;
	int i;
	for(i=0; i<TRACKING_LEN; i++)
	{
		if(tList[i].idProducto == prodID)
		{
			ret = i;
		}
	}
	return ret;
}

/// @fn int track_altaTracking(Tracking*, int)
/// @brief copia en un indice vacio el track auxiliar, NECESITA de
/// track_cargarTracking y track_getEmptyIndex
///
/// @param array
/// @param arrayLen
/// @return retorna -1 (errores) 0 OK
///                                 length innecesaria ya que estan en los define
int track_altaTracking(Tracking* tList, int length, int uIndexAux, User* uList, int qty, Producto* pList, int pIndexAux)
{
	int ret = -1; //NULL LIST

	int emptyIndex;
	if(tList != NULL)
	{
		if(length > 0)
		{
			emptyIndex = track_getEmptyIndex(tList, length);
			if(emptyIndex >= 0)
			{
				int codigoPostalAux;
				tList[emptyIndex].idTracking = track_generateID();
				tList[emptyIndex].idProducto = pList[pIndexAux].idProd;
				strncpy(tList[emptyIndex].FK_prodName,pList[pIndexAux].nombre,PROD_NOMBRE_LEN);
				strncpy(tList[emptyIndex].FK_compradorName,uList[uIndexAux].nombre,NOMBRE_LEN);
				tList[emptyIndex].FK_userCompradorID = uList[uIndexAux].idUsuario;
				tList[emptyIndex].FK_userVendedorID = pList[pIndexAux].FK_userVendedorIDD;
				tList[emptyIndex].qty = qty;
				codigoPostalAux=uList[uIndexAux].codigoPostal;
				tList[emptyIndex].horaDeCompra=time(NULL);
				tList[emptyIndex].distancia = track_calcDistancia(codigoPostalAux);
//				tList[emptyIndex].ETA = sumarSegundos(tList[emptyIndex].distancia, tList[emptyIndex].horaDeCompra);
				tList[emptyIndex].ETA = calcETA(tList[emptyIndex]);
				tList[emptyIndex].isEmpty = OCUPADO;
				char horaAux[30];
				/*
				strncpy(horaAux,ctime(&tList[emptyIndex].horaDeCompra),sizeof(horaAux));
				dinamitarNuevaLinea(horaAux, sizeof(horaAux));
				*/
				escribirHoraStringActual(horaAux, 30);

				printf( "_____Siendo la fecha_____\n"
						"%s\n"
						"Se ha generado un tracking\n\n",horaAux);
				encabezadoTablaTrack();
				track_printOne(tList[emptyIndex]);
				pieTablaTrack();
			}
		}
		else
		{
			ret = -2; //length incorrecta
		}
	}
	return ret;
}

/// @fn Tracking track_cargarTracking(void)
/// @brief carga los datos en un auxiliar y pregunta si desea cargar los datos
///
/// @return retorna un trackenger de tipo auxiliar con id y isempty ya OCUPADO si salio todo OK
/*
Tracking track_cargarTrack (void)
{
	Tracking trackAux;

	if( 1 )
		// corroborar si estos son todos los campos
	{
		printf("Estos son los datos cargados:\n");
		track_printOne(trackAux);

		if(validateExit_YN("Confirma? Y/N\n", "ERROR, revise las opciones\n", 2) == 1 )
		{
			//corroborar si es necesario ponerle ID
			trackAux.idTracking = track_generateID();
			trackAux.isEmpty = OCUPADO;
		}
	}
	else
	{
		printf("Hubo muchos errores, vuelvo al menu, saludos\n\n");
	}
	return trackAux;
}
*/
/// @fn int track_printByStatus(Tracking*, int, int)
/// @brief imprime los datos del struct por estado de variable isEmpty
///
/// @param list
/// @param length
/// @param status valor que queremos buscar e imrpimer de IsEMpty
/// @return -n ERRORES // 0 SUCCESS
int track_printByStatus(Tracking* list, int length, int status)
{
	int ret = -1; //NULL LIST
	if(list != NULL)
	{
		if(length > 0)
		{
			encabezadoTablaTrack();
			int i;
			for(i=0; i<length; i++)
			{
				if(list[i].isEmpty == status)
				{
					track_printOne(list[i]);
					ret = 0;
				}
			}
			pieTablaTrack();
		}
		else
		{
			ret = -2; //la longitud de la lista es menor a 1
		}
	}
	return ret;
}




/// @fn int track_modifyTracking(Tracking*, int)
/// @brief reescribe los datos de track
///
/// @param list array donde se encuentra dicho track
/// @param length longitud del array
/// @return -n ERRORES // 0 SUCCESS
int track_modifyTracking(Tracking* list, int length)
{
	int ret = -1; //NULL LIST
	int indexModificacion;
	Tracking trackAux;
	if(list != NULL)
	{
		if(length > 0)
		{
			if(track_printByStatus(list, length, OCUPADO) == 0)
			{
				indexModificacion = track_findIndexById(list, length);
				if(indexModificacion >= 0)
				{
					trackAux = list[indexModificacion];
					track_trackModifier(&trackAux);
					if(validateExit_YN("Desea guardar los cambios? Y/N\n", "ERROR, revise las opciones\n", 2) == 1)
					{
						ret = 0;//se guardo el cambio
						list[indexModificacion] = trackAux;
						printf("Los cambios han sido guardados\n");
					}
					else
					{
						//no guardo nada y salgo
					}
				}
				else
				{
					ret = -3; // error al obtener el indice
				}
			}
		}
		else
		{
			ret = -2; //error de length
		}
	}


	return ret;
}

/// @fn void track_trackModifier(Tracking*)
/// @brief pide los datos necesarios para modificar la struct
///
/// @param aux dato tipo struct donde se almacenaran temporalmente los cambios
void track_trackModifier(Tracking* aux)
{
	int memberToModify;
	do
	{
		if(utn_getNumero(&memberToModify, "Que campo desea modificar?\n"
		"1)nombre\n"
		"2)campoINT\n"
		"3)campoINT2\n"
		"4)campoFLOAT\n"
		"5)\n"
		"6)Ver modificaciones\n"
		"7)Salir y guardar\n"
		,"ERROR, revise las opciones\n", 1, 8, 2) == 0)
		{

		}
	}while(memberToModify != 7);
}

/// @fn int track_copyArray(Tracking*, Tracking*, int)
/// @brief toma un array de struct y copia los indices que esten ocupados
///  en un auxiliar que ha recibido por puntero
///
/// @param list puntero al array original
/// @param listCopy puntero al array de copia
/// @param length longitud de los array
/// @return -n ERRORES // 0 SUCCESS
int track_copyArray(Tracking* list, Tracking* listCopy, int length)
{
	int ret = -1; //NULL LIST
	int i;
	if(list != NULL)
	{
		if(length > 0)
		{
			ret = 0; //SUCCES
			for(i=0; i<length; i++)
			{
				if(list[i].isEmpty == OCUPADO)
				{
					listCopy[i] = list[i];
				}
			}
		}
		else
		{
			ret = -2;//longitud menor a 0
		}
	}
	return ret;
}

/// @fn int track_calAverageFLOAT(float*, Tracking*, int)
/// @brief acumula el campoFLOAT de un struct y calcula un promedio
///
/// @param pResultado puntero a direccion de memoria donde se guardara el promedio calculado
/// @param list lista a analizar
/// @param length longitud de la misma
/// @return -n ERRORES // 0 SUCCESS
float track_calcAverageFLOAT(float* pResultado, Tracking* list, int length)
{
	int ret = -1;// puntero NULL de pResultado
	int contador = 0;
	int acumulador = 0;
	int i;

	if(pResultado != NULL)
	{
		if(list != NULL)
		{
			if(length > 0)
			{
				for(i=0; i<length; i++)
				{
					if(list[i].isEmpty == 0)
					{

						contador++;
					}
				}
				if(utn_calcularPromedio(pResultado, acumulador, contador) == 0)
				{
					ret = 0;
				}
				else
				{
					ret = -4; //ERROR de la funcion utn get num
				}
			}
			else
			{
				ret = -3; //length incorrecta
			}
		}
		else
		{
			ret = -2; // lista NUL
		}
	}
	return ret;
}


/// @fn int track_calcTotalFLOAT(float*, Tracking*, int)
/// @brief acumula el campoFLOAT de un Tracking y suma sus valores
///
/// @param pResultado puntero a direccion de memoria se almacenara el resultado
/// @param list array de struct
/// @param length longitud del array
/// @return -n ERRORES // 0 SUCCESS
int track_calcTotalFLOAT(float* pResultado, Tracking* list, int length)
{
	int ret = -1;// puntero NULL de pResultado
	int acumulador = 0;
	int i;
	if(pResultado != NULL)
	{
		if(list != NULL)
		{
			if(length > 0)
			{
				for(i=0; i<length; i++)
				{
					if(list[i].isEmpty == 0)
					{

					}
				}
				*pResultado = acumulador;
				ret = 0;

			}
			else
			{
				ret = -3; //length incorrecta
			}
		}
		else
		{
			ret = -2; // lista NUL
		}
	}
	return ret;
}
/// @fn int track_calcSuperiorAlPromedio(Tracking*, int, float, float)
/// @brief calcula cuantos camposFLOAT superan el promedio de campoFloat
///
/// @param list lista a analizar
/// @param length longitud de la lista
/// @param promedio promedio de campoFLOAT
/// @return -n ERROR // <0 SUCCES
int track_calcSuperiorAlPromedio(Tracking* list, int length, float promedio)
{
	int ret = -1; //error NULL ARRAY
	int contador = 0;
	int i;
	if(list != NULL)
	{
		if(length>0)
		{
			for(i=0; i<length; i++)
			{

			}
			ret = contador; //SUCCES
		}
		else
		{
			ret = -2; //ERROR DE LENGTH
		}
	}
	return ret;
}

int track_calcDistancia(int cp)
{
	int ret = -1;
	if(cp>=1 && cp<=1000)
	{
		ret=20;
	}
	else
	{
		if(cp>=1001 && cp<=3000)
		{
			ret = 30;
		}
		else
		{
			if(cp>=3001 && cp<=5000)
			{
				ret = 50;
			}
			else
			{
				if(cp>=5001 && cp<=8000)
				{
					ret = 80;
				}
				else
				{
					if(cp>=8001 && cp<=9999)
					{
						ret = 150;
					}

				}
			}
		}
	}
	return ret;
}

long int calcETA(Tracking trackAux)
{
	long int ret;
	ret = sumarSegundos(trackAux.distancia, trackAux.horaDeCompra);
	return ret;
}

int track_printTrackingAdmin(Tracking* tList)
{
	int flagHayTrack = 0;
	int i;
	for(i=0; i<TRACKING_LEN; i++)
	{
		if(tList[i].isEmpty != LIBRE)
		{
			if(flagHayTrack == 0)
			{
				encabezadoTrackingGlobal();
				flagHayTrack=1;
			}
			printOneTrack(tList[i]);
		}
	}
	if(flagHayTrack == 1)
	{
		pieTrackingGlobal();
	}
	else
	{
		printf("Todavia no hay ventas\n");
	}
	return flagHayTrack;
}

void encabezadoTrackingGlobal(void)
{

printf("+-----------+-------------------------+-----------+--------------+-------------+-------------+\n");
printf("|TRACKING ID|        PRODUCTO         | DISTANCIA | ID COMPRADOR | ID VENDEDOR |    ESTADO   |\n");
printf("+-----------+-------------------------+-----------+--------------+-------------+-------------+\n");
}
void pieTrackingGlobal(void)
{
printf("+-----------+-------------------------+-----------+--------------+-------------+-------------+\n");
}

void printOneTrack(Tracking track)
{
	double llegaEn;
	long int horaDeConsulta = time(NULL);
	llegaEn = difftime(horaDeConsulta, track.ETA);//saco la diferencia entre compra y consulta
//	printf("DEBUG la diferencia es: %.2f",llegaEn);

	char ETA[30];
	track.ETA = sumarSegundos(-(long int)llegaEn, horaDeConsulta);//actualizo el horario de llegada

	escribirHoraStringActual(ETA, 30);
	char estado[20];
	if(track.isEmpty == CANCELADO)
	{
		strncpy(estado,"Cancelado",20);
	}
	else
	{
		if(track.ETA>horaDeConsulta)
		{
			strncpy(estado,"En viaje",20);
			track.isEmpty = ENVIAJE;
		}
		else
		{
			strncpy(estado,"Entregado",20);
			track.isEmpty = ENTREGADO;
		}
	}

	printf("|%-11d|%-25s|%-11d|%-14d|%-13d|%-13s|\n"
	,track.idTracking,track.FK_prodName,track.distancia,track.FK_userCompradorID,track.FK_userVendedorID,estado);
}




