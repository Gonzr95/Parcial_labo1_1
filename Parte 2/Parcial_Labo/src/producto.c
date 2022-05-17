/*
 * struct.c
 *
 *  Created on: 8 May 2022
 *      Author: gonzr
 */
#include "relaciones.h"


//--------------------Generador de ID's--------------
static int idAutoIncremental = 1000;
static int prod_generateID();
/// @fn int prod_generateID()
/// @brief genera un id en base a un contador
///
/// @return retorna el id
static int prod_generateID()
{
	return idAutoIncremental++;
}
//--------------------Generador de ID's--------------



/// @fn int prod_initProducto(Producto array[], int length)
/// @brief Initiates the array changing the member isEmpty to 1 (TRUE)
///
/// @param array Pointer to array of prodengers
/// @param length Length of the array
/// @return -1 length minor to one, -2 NULL pointer
int prod_initProd(Producto* list, int length)
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

/// @fn void prod_printOne(Producto)
/// @brief imprime solo un dato del tipo Producto
/// el numero que va dsp del % es correlativo con la cantidad de - que tiene el encabezado
/// @param Producto
void prod_printOne(Producto prod)
{
    // 1             25                 12         5       9                1
	printf( "|%-4d|%-25s",prod.idProd,prod.nombre);


	switch(prod.categoria)
	{
		char categoria[20];
		case ROPA:
			strncpy(categoria,"ROPA",sizeof(categoria));
			printf("|%-12s",categoria);
			break;
		case TECNOLOGIA:
			strncpy(categoria,"TECNOLOGIA",sizeof(categoria));
			printf("|%-12s",categoria);
			break;
		case COMESTIBLE:
			strncpy(categoria,"COMESTIBLE",sizeof(categoria));
			printf("|%-12s",categoria);
			break;
		case HERRAMIENTAS:
			strncpy(categoria,"HERRAMIENTAS",sizeof(categoria));
			printf("|%-12s",categoria);
			break;
		case LIMPIEZA:
			strncpy(categoria,"LIMPIEZA",sizeof(categoria));
			printf("|%-12s",categoria);
			break;
	}
    // 1             25                 12         5       9                1
	printf("|%5d|%9.2f|%-20s|\n",prod.stock,prod.precio,prod.FK_userVendedor);
}
void encabezadoTablaProd(void)
{
	        // 1             25                 12         5       9               20
	printf("+----+-------------------------+------------+-----+---------+--------------------+\n");
	printf("| ID |          NOMBRE         |  CATEGORIA |STOCK|  PRECIO |       VENDEDOR     |\n");
	printf("+----+-------------------------+------------+-----+---------+--------------------+\n");
}
void pieTablaProd(void)
{
	printf("+----+-------------------------+------------+-----+---------+--------------------+\n");
}

/// @fn void prod_printOne(Producto)
/// @brief imprime solo un dato del tipo Producto
/// el numero que va dsp del % es correlativo con la cantidad de - que tiene el encabezado
/// @param Producto
void prod_printMyStockOneProduct(Producto prod)
{
	printf( "|%-4d|%-25s",prod.idProd,prod.nombre);

	switch(prod.categoria)
		{
			char categoria[20];
			case ROPA:
				strncpy(categoria,"ROPA",sizeof(categoria));
				printf("|%-12s",categoria);
				break;
			case TECNOLOGIA:
				strncpy(categoria,"TECNOLOGIA",sizeof(categoria));
				printf("|%-12s",categoria);
				break;
			case COMESTIBLE:
				strncpy(categoria,"COMESTIBLE",sizeof(categoria));
				printf("|%-12s",categoria);
				break;
			case HERRAMIENTAS:
				strncpy(categoria,"HERRAMIENTAS",sizeof(categoria));
				printf("|%-12s",categoria);
				break;
			case LIMPIEZA:
				strncpy(categoria,"LIMPIEZA",sizeof(categoria));
				printf("|%-12s",categoria);
				break;
		}
	    // 1             25                 12         5       9                1
		printf("|%5d|%9.2f|\n",prod.stock,prod.precio);
}
/// @fn int prod_cargaForzada(Producto*, int)
/// @brief hardcodea datos con el fin de adelantar el testing de nuestro programa
///
/// @param list puntero a larray de prod
/// @param length longitud de dicho array
/// @return -1 NULL list  // -2 longitud muy pequeña  //
int prod_cargaForzada(Producto* list, int length)
{
	int ret = -1; //LIST NULL
	Producto prodAux[15];
	if(list != NULL)
	{
		if(length >0)
		{
			strncpy(prodAux[0].nombre,"Zapas NIKE",PROD_NOMBRE_LEN);
			prodAux[0].categoria = 1;
			prodAux[0].stock = 10;
			prodAux[0].precio = 3000;
			prodAux[0].idProd = prod_generateID();
			prodAux[0].FK_userVendedorIDD = 1001;
			strncpy(prodAux[0].FK_userVendedor,"Gonzalo",NOMBRE_LEN);
			prodAux[0].isEmpty = OCUPADO;

			strncpy(prodAux[1].nombre,"Zapas NIKE",PROD_NOMBRE_LEN);
			prodAux[1].categoria = 1;
			prodAux[1].stock = 11;
			prodAux[1].precio = 3050;
			prodAux[1].idProd = prod_generateID();
			prodAux[1].FK_userVendedorIDD = 1002;
			strncpy(prodAux[1].FK_userVendedor,"Agostina",NOMBRE_LEN);
			prodAux[1].isEmpty = OCUPADO;

			strncpy(prodAux[2].nombre,"Zapas NIKE",PROD_NOMBRE_LEN);
			prodAux[2].categoria = 1;
			prodAux[2].stock = 5;
			prodAux[2].precio = 4000;
			prodAux[2].idProd = prod_generateID();
			prodAux[2].FK_userVendedorIDD = 1003;
			strncpy(prodAux[2].FK_userVendedor,"Ivan",NOMBRE_LEN);
			prodAux[2].isEmpty = OCUPADO;

			strncpy(prodAux[3].nombre,"Zapas Adidas",PROD_NOMBRE_LEN);
			prodAux[3].categoria = 1;
			prodAux[3].stock = 1;
			prodAux[3].precio = 4000;
			prodAux[3].idProd = prod_generateID();
			prodAux[3].FK_userVendedorIDD = 1001;
			strncpy(prodAux[3].FK_userVendedor,"Gonzalo",NOMBRE_LEN);
			prodAux[3].isEmpty = OCUPADO;

			strncpy(prodAux[4].nombre,"Zapas Puma",PROD_NOMBRE_LEN);
			prodAux[4].categoria = 1;
			prodAux[4].stock = 0;
			prodAux[4].precio = 3000;
			prodAux[4].idProd = prod_generateID();
			prodAux[4].FK_userVendedorIDD = 1001;
			strncpy(prodAux[4].FK_userVendedor,"Gonzalo",NOMBRE_LEN);
			prodAux[4].isEmpty = OCUPADO;

			strncpy(prodAux[5].nombre,"Celular Samsung a20",PROD_NOMBRE_LEN);
			prodAux[5].categoria = 2;
			prodAux[5].stock = 1;
			prodAux[5].precio = 50000;
			prodAux[5].idProd = prod_generateID();
			prodAux[5].FK_userVendedorIDD = 1002;
			strncpy(prodAux[5].FK_userVendedor,"Agostina",NOMBRE_LEN);
			prodAux[5].isEmpty = OCUPADO;

			strncpy(prodAux[6].nombre,"Celular iPhone 13",PROD_NOMBRE_LEN);
			prodAux[6].categoria = 2;
			prodAux[6].stock = 10;
			prodAux[6].precio = 70000;
			prodAux[6].idProd = prod_generateID();
			prodAux[6].FK_userVendedorIDD = 1002;
			strncpy(prodAux[6].FK_userVendedor,"Agostina",NOMBRE_LEN);
			prodAux[6].isEmpty = OCUPADO;

			strncpy(prodAux[7].nombre,"Papas de tubo Lays",PROD_NOMBRE_LEN);
			prodAux[7].categoria = 3;
			prodAux[7].stock = 20;
			prodAux[7].precio = 70;
			prodAux[7].idProd = prod_generateID();
			strncpy(prodAux[7].FK_userVendedor,"Ivan",NOMBRE_LEN);
			prodAux[7].FK_userVendedorIDD = 1003;
			prodAux[7].isEmpty = OCUPADO;

			strncpy(prodAux[8].nombre,"Destornillador Philips",PROD_NOMBRE_LEN);
			prodAux[8].categoria = 4;
			prodAux[8].stock = 1;
			prodAux[8].precio = 200;
			prodAux[8].idProd = prod_generateID();
			prodAux[8].FK_userVendedorIDD = 1004;
			strncpy(prodAux[8].FK_userVendedor,"Micaela",NOMBRE_LEN);
			prodAux[8].isEmpty = OCUPADO;

			strncpy(prodAux[9].nombre,"Colgate 3x accion",PROD_NOMBRE_LEN);
			prodAux[9].categoria = 5;
			prodAux[9].stock = 10;
			prodAux[9].precio = 200;
			prodAux[9].idProd = prod_generateID();
			prodAux[9].FK_userVendedorIDD = 1005;
			strncpy(prodAux[9].FK_userVendedor,"Juan",NOMBRE_LEN);
			prodAux[9].isEmpty = OCUPADO;

			strncpy(prodAux[10].nombre,"Jabon blanco",PROD_NOMBRE_LEN);
			prodAux[10].categoria = 5;
			prodAux[10].stock = 0;
			prodAux[10].precio = 90;
			prodAux[10].idProd = prod_generateID();
			prodAux[10].FK_userVendedorIDD = 1005;
			strncpy(prodAux[10].FK_userVendedor,"Juan",NOMBRE_LEN);
			prodAux[10].isEmpty = OCUPADO;

			strncpy(prodAux[11].nombre,"Detergente",PROD_NOMBRE_LEN);
			prodAux[11].categoria = 5;
			prodAux[11].stock = 30;
			prodAux[11].precio = 300;
			prodAux[11].idProd = prod_generateID();
			prodAux[11].FK_userVendedorIDD = 1005;
			strncpy(prodAux[11].FK_userVendedor,"Juan",NOMBRE_LEN);
			prodAux[11].isEmpty = OCUPADO;

			strncpy(prodAux[12].nombre,"Medias NIKE",PROD_NOMBRE_LEN);
			prodAux[12].categoria = 1;
			prodAux[12].stock = 15;
			prodAux[12].precio = 300;
			prodAux[12].idProd = prod_generateID();
			prodAux[12].FK_userVendedorIDD = 1001;
			strncpy(prodAux[12].FK_userVendedor,"Gonzalo",NOMBRE_LEN);
			prodAux[12].isEmpty = OCUPADO;

			strncpy(prodAux[13].nombre,"Celular Xiomi Redmi 12",PROD_NOMBRE_LEN);
			prodAux[13].categoria = 2;
			prodAux[13].stock = 3;
			prodAux[13].precio = 60000;
			prodAux[13].idProd = prod_generateID();
			prodAux[13].FK_userVendedorIDD = 1002;
			strncpy(prodAux[13].FK_userVendedor,"Agostina",NOMBRE_LEN);
			prodAux[13].isEmpty = OCUPADO;

			strncpy(prodAux[14].nombre,"Pantalon Adidas",PROD_NOMBRE_LEN);
			prodAux[14].categoria = 1;
			prodAux[14].stock = 20;
			prodAux[14].precio = 3000;
			prodAux[14].idProd = prod_generateID();
			prodAux[14].FK_userVendedorIDD = 1001;
			strncpy(prodAux[14].FK_userVendedor,"Gonzalo",NOMBRE_LEN);
			prodAux[14].isEmpty = OCUPADO;

			int i;
			int emptyIndex;
			for(i=0; i<15; i++)
			{
				emptyIndex = prod_getEmptyIndex(list, PROD_LEN);
				list[emptyIndex] = prodAux[i];
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

/// @fn int prod_getEmptyIndex(Producto*, int, int)
/// @brief	busca un lugar vacio en el array
///
/// @param array
/// @param length
/// @return -1 NO HAY LUGAR; -2 EL ARRAY ES NULO; -3 LENGTH MENOR A 1
int prod_getEmptyIndex(Producto* list, int length)
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


/// @fn int prod_findIndexById(Producto*, int)
/// @brief pide el ID de un strut1 y retorna en que posicion del array se encuentra
///
/// @param list array de struc1
/// @param length longitud del mismo
/// @return el indice en el que se encuentra ese ID o errores
int prod_findIndexById(Producto* list, int length)
{
	int ret = -1; // lista NULL
	int idAux;
	if(list != NULL)
	{
		if(length > 0)
		{
			if(utn_getNumero(&idAux, "Ingrese el ID de 4 digitos de la prod que busca\n", "ERROR, reintente\n", 0, 9999, 2) == 0)
			{
				int i;
				for(i=0; i<length; i++)
				{
					if(idAux == list[i].idProd)
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


/// @fn int prod_altaProducto(Producto*, int)
/// @brief copia en un indice vacio el prod auxiliar, NECESITA de
/// prod_cargarProducto y prod_getEmptyIndex
///
/// @param array
/// @param arrayLen
/// @return retorna -1 (errores) 0 OK
int prod_altaProd(Producto* list, int length, User userLogeado)
{
	int ret = -1; //NULL LIST
	Producto prodAux;
	int emptyIndex;
	if(list != NULL)
	{
		if(length > 0)
		{
			emptyIndex = prod_getEmptyIndex(list, length);
			if(emptyIndex >= 0)
			{
				prodAux = prod_cargarProd(userLogeado);
				list[emptyIndex] = prodAux;
				ret = 0;
			}
		}
		else
		{
			ret = -2; //length incorrecta
		}
	}

	return ret;
}

/// @fn Producto prod_cargarProducto(void)
/// @brief carga los datos en un auxiliar y pregunta si desea cargar los datos
///
/// @return retorna un prodenger de tipo auxiliar con id y isempty ya OCUPADO si salio todo OK
Producto prod_cargarProd(User userLogeado)
{
	Producto prodAux;

	if( utn_getDescripcion(prodAux.nombre, PROD_NOMBRE_LEN, "Ingrese el nombre del producto (Hasta 25 caracteres)\n", "ERROR\n", 2) == 0 &&
		utn_getNumero(&prodAux.categoria, "Ingrese el categoria (1-5)\n"
		"1)Ropa\n"
		"2)Tecnologia\n"
		"3)Comestible\n"
		"4)Herramientas\n"
		"5)Limpieza\n", "ERROR\n", CATEGORIA_MIN, CATEGORIA_MAX, 2) == 0 &&
		utn_getFloat(&prodAux.precio, "Ingrese el precio del producto\n", "ERROR\n", PRECIO_MIN, PRECIO_MAX, 2) == 0 &&
		utn_getNumero(&prodAux.stock, "Ingrese el stock del producto\n", "ERROR\n", STOCK_MIN, STOCK_MAX, 2) == 0)
	{
		strncpy(prodAux.FK_userVendedor,userLogeado.nombre,NOMBRE_LEN);
		strncpy(prodAux.FK_userMail,userLogeado.correo,CORREO_LEN);
		prodAux.idProd = prod_generateID();

		printf("Estos son los datos cargados:\n");
		encabezadoTablaProd();
		prod_printOne(prodAux);
		pieTablaProd();

		if(validateExit_YN("Confirma? Y/N\n", "ERROR, revise las opciones\n", 2) == 1 )
		{
			prodAux.isEmpty = OCUPADO;
		}
		else
		{

			idAutoIncremental--;
		}
	}
	else
	{
		printf("Hubo muchos errores, vuelvo al menu, saludos\n\n");
		prodAux.isEmpty=LIBRE;
	}
	return prodAux;
}

/// @fn int prod_printByStatus(Producto*, int, int)
/// @brief imprime los datos del struct por estado de variable isEmpty
///
/// @param list
/// @param length
/// @param status valor que queremos buscar e imrpimer de IsEMpty
/// @return -n ERRORES // 0 SUCCESS
int prod_printByStatus(Producto* list, int length, int status)
{
	int ret = -1; //NULL LIST
	if(list != NULL)
	{
		if(length > 0)
		{
			encabezadoTablaProd();
			int i;
			for(i=0; i<length; i++)
			{
				if(list[i].isEmpty == status)
				{
					prod_printOne(list[i]);
					ret = 0;
				}
			}
			pieTablaProd();
		}
		else
		{
			ret = -2; //la longitud de la lista es menor a 1
		}
	}
	return ret;
}

/// @fn int prod_printByStatus(Producto*, int, int)
/// @brief imprime los datos del struct por estado de variable isEmpty
///
/// @param list
/// @param length
/// @param status valor que queremos buscar e imrpimer de IsEMpty
/// @return -n ERRORES // 0 SUCCESS
int prod_printByStatusAndStock(Producto* list, int length, int status)
{
	int ret = -1; //NULL LIST
	if(list != NULL)
	{
		if(length > 0)
		{
			encabezadoTablaProd();
			int i;
			for(i=0; i<length; i++)
			{
				if(list[i].isEmpty == status)
				{
					if(list[i].stock > 0)
					{
						prod_printOne(list[i]);
						ret = 0;
					}
				}
			}
			pieTablaProd();
		}
		else
		{
			ret = -2; //la longitud de la lista es menor a 1
		}
	}
	return ret;
}

/// @fn int prod_bajaprod(Producto*, int)
/// @brief reescribe el campo isEmpty como LIBRE para dar de baja al struct
///
/// @param list array a analizar
/// @param length longitud del mismo
/// @return -n ERRORES / 0 SUCCESS
int prod_bajaProd(Producto* list, int length)
{
	int ret = -1;
	int indexBaja;
	if(list != NULL)
	{
		if(length > 0)
		{
			indexBaja = prod_findIndexById(list, length);
			if(indexBaja >= 0)
			{
				if(validateExit_YN("Estas seguro de dar de baja?? Y/N\n", "ERROR, revise opciones\n", 2) == 1)
				{
					list[indexBaja].isEmpty = LIBRE;
					ret = 0; //success
				}
			}
			else
			{
				ret = -3; // error al encontrar el index del ID
			}
		}
		else
		{
			ret = -2; //LENGTH INCORRECTA
		}
	}
	return ret;
}


/// @fn int prod_modifyProducto(Producto*, int)
/// @brief reescribe los datos de prod
///
/// @param list array donde se encuentra dicho prod
/// @param length longitud del array
/// @return -n ERRORES // 0 SUCCESS
int prod_modifyProd(Producto* list, int length)
{
	int ret = -1; //NULL LIST
	int indexModificacion;
	Producto prodAux;
	if(list != NULL)
	{
		if(length > 0)
		{
			if(prod_printByStatus(list, length, OCUPADO) == 0)
			{
				indexModificacion = prod_findIndexById(list, length);
				if(indexModificacion >= 0)
				{
					prodAux = list[indexModificacion];
					prod_prodModifier(&prodAux);
					if(validateExit_YN("Desea guardar los cambios? Y/N\n", "ERROR, revise las opciones\n", 2) == 1)
					{
						ret = 0;//se guardo el cambio
						list[indexModificacion] = prodAux;
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

/// @fn void prod_prodModifier(Producto*)
/// @brief pide los datos necesarios para modificar la struct
///
/// @param aux dato tipo struct donde se almacenaran temporalmente los cambios
void prod_prodModifier(Producto* aux)
{
	int memberToModify;
	do
	{
		if(utn_getNumero(&memberToModify, "Que campo desea modificar?\n"
		"1)nombre\n"
		"2)categoria\n"
		"3)categoria2\n"
		"4)precio\n"
		"5)\n"
		"6)Ver modificaciones\n"
		"7)Salir y guardar\n"
		,"ERROR, revise las opciones\n", 1, 8, 2) == 0)
		{
			switch(memberToModify)
			{
			case 1:
				break;
			case 6:
				prod_printOne(*aux);
				break;
			}
		}
	}while(memberToModify != 7);
}

/// @fn int prod_copyArray(Producto*, Producto*, int)
/// @brief toma un array de struct y copia los indices que esten ocupados
///  en un auxiliar que ha recibido por puntero
///
/// @param list puntero al array original
/// @param listCopy puntero al array de copia
/// @param length longitud de los array
/// @return -n ERRORES // 0 SUCCESS
int prod_copyArray(Producto* list, Producto* listCopy, int length)
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

int prod_printByCat(Producto* list, int length, int order)
{
	int ret = -1; //NULL LIST
	if(list != NULL)
	{
		if(length > 0)
		{
			prod_ascendingBubbleSorting(list, length);
		}
		else
		{
			ret = -2; // LENGTH MENOR A 0
		}
	}
	return ret;
}


int prod_printByCatStockYAlfabeticoAdmin(Producto* list, int length)
{
	int ret = -1; //NULL LIST
	if(list != NULL)
	{
		if(length > 0)
		{
			prod_ascendingBubbleSortingAdmin(list, length);
		}
		else
		{
			ret = -2; // LENGTH MENOR A 0
		}
	}
	return ret;
}

int prod_ascendingBubbleSortingAdmin(Producto* list, int length)
{
	int ret = -1; //NULL LIST
	int flagSwap;
	Producto aux;
	Producto arrayCopy[length];

	if(list != NULL)
	{
		if(length > 0)
		{
			if(prod_initProd(arrayCopy, length) == 0)
			{
				if(prod_copyArray(list, arrayCopy, length) == 0)
				{
					do
					{
						flagSwap = 0;
						int i;
						//limite -1 para que no compare contra la nada
						for(i=0; i<length-1; i++)
						{
							//de todas formas es redundante porque solo copie lo que estaba ocupado
							//pregunto si esta vacio itero una vez mas asi no comparo de mas
							if(arrayCopy[i].isEmpty == LIBRE || arrayCopy[i+1].isEmpty == LIBRE)
							{
								continue;
							}
							/*
							auxiliarDeComparacion = strncmp(arrayCopy[i].surname,arrayCopy[i+1].surname,SURNAME_LEN);
							orden alfanumerico ascendente
							si hay 2 pasajeros iguales ordena por tipo de pasajeros
							 */
							if(arrayCopy[i].categoria>arrayCopy[i+1].categoria)
							{
								flagSwap = 1;
								aux = arrayCopy[i];
								arrayCopy[i] = arrayCopy[i+1];
								arrayCopy[i+1] = aux;
							}
						}
					}
					while(flagSwap);
					//llamar a funcion para ordenar alfabeticamente ahora y ahi imprimir la copia de ese array

					if(prod_ascendingBubbleSortingAlfabetico(arrayCopy) == 0)
					{
						ret = 0;//SUCCESS
					}
					else
					{
						ret = -5; //Fallo la impresion
					}
				}
				else
				{
					ret = -4; // fallo la copia del array
				}
			}
			else
			{
				ret = -3; //fallo la inicializacion
			}
		}
		else
		{
			ret = -2; //length minor to 0
		}
	}
	return ret;
}

int prod_ascendingBubbleSortingAlfabetico(Producto* pList)
{
	int ret = -1; //NULL LIST
	int flagSwap;
	int auxiliarDeComparacion;
	Producto aux;
	Producto arrayCopy[PROD_LEN];

	if(pList != NULL)
	{
		if(prod_initProd(arrayCopy, PROD_LEN) == 0)
		{
			if(prod_copyArray(pList, arrayCopy, PROD_LEN) == 0)
			{
				do
				{
					flagSwap = 0;
					int i;
					//limite -1 para que no compare contra la nada
					for(i=0; i<PROD_LEN-1; i++)
					{
						//de todas formas es redundante porque solo copie lo que estaba ocupado
						//pregunto si esta vacio itero una vez mas asi no comparo de mas
						if(arrayCopy[i].isEmpty == 1 || arrayCopy[i+1].isEmpty == 1)
						{
							continue;
						}
						if(arrayCopy[i].categoria == arrayCopy[i+1].categoria)
						{
							auxiliarDeComparacion = strncmp(arrayCopy[i].nombre,arrayCopy[i+1].nombre,PROD_NOMBRE_LEN);
							//orden alfanumerico ascendente
							//si hay 2 pasajeros iguales ordena por tipo de pasajeros
							if( auxiliarDeComparacion > 0 ||
							(	auxiliarDeComparacion == 0 &&
								arrayCopy[i].nombre > arrayCopy[i+1].nombre))
							{
								flagSwap = 1;
								aux = arrayCopy[i];
								arrayCopy[i] = arrayCopy[i+1];
								arrayCopy[i+1] = aux;
							}
						}
					}
				}
				while(flagSwap);
				prod_printByStatusAndStock(arrayCopy, PROD_LEN, OCUPADO);
			}
			else
			{
				ret = -4; // fallo la copia del array
			}
		}
		else
		{
			ret = -2; //length minor to 0
		}
	}
	return ret;
}

int prod_ascendingBubbleSorting(Producto* list, int length)
{
	int ret = -1; //NULL LIST
	int flagSwap;
	Producto aux;
	Producto arrayCopy[length];

	if(list != NULL)
	{
		if(length > 0)
		{
			if(prod_initProd(arrayCopy, length) == 0)
			{
				if(prod_copyArray(list, arrayCopy, length) == 0)
				{
					do
					{
						flagSwap = 0;
						int i;
						//limite -1 para que no compare contra la nada
						for(i=0; i<length-1; i++)
						{
							//de todas formas es redundante porque solo copie lo que estaba ocupado
							//pregunto si esta vacio itero una vez mas asi no comparo de mas
							if(arrayCopy[i].isEmpty == LIBRE || arrayCopy[i+1].isEmpty == LIBRE)
							{
								continue;
							}
							/*
							auxiliarDeComparacion = strncmp(arrayCopy[i].surname,arrayCopy[i+1].surname,SURNAME_LEN);
							orden alfanumerico ascendente
							si hay 2 pasajeros iguales ordena por tipo de pasajeros
							 */
							if(arrayCopy[i].categoria>arrayCopy[i+1].categoria)
							{
								flagSwap = 1;
								aux = arrayCopy[i];
								arrayCopy[i] = arrayCopy[i+1];
								arrayCopy[i+1] = aux;
							}
						}
					}
					while(flagSwap);
					if(prod_printByStatusAndStock(arrayCopy, length, OCUPADO) == 0)
					{
						ret = 0;//SUCCESS
					}
					else
					{
						ret = -5; //Fallo la impresion
					}
				}
				else
				{
					ret = -4; // fallo la copia del array
				}
			}
			else
			{
				ret = -3; //fallo la inicializacion
			}
		}
		else
		{
			ret = -2; //length minor to 0
		}
	}
	return ret;
}

/// @fn int prod_calAverageFLOAT(float*, Producto*, int)
/// @brief acumula el precio de un struct y calcula un promedio
///
/// @param pResultado puntero a direccion de memoria donde se guardara el promedio calculado
/// @param list lista a analizar
/// @param length longitud de la misma
/// @return -n ERRORES // 0 SUCCESS
float prod_calcAverageFLOAT(float* pResultado, Producto* list, int length)
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
						acumulador = acumulador + list[i].precio;
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


/// @fn int prod_calcTotalFLOAT(float*, Producto*, int)
/// @brief acumula el precio de un Producto y suma sus valores
///
/// @param pResultado puntero a direccion de memoria se almacenara el resultado
/// @param list array de struct
/// @param length longitud del array
/// @return -n ERRORES // 0 SUCCESS
int prod_calcTotalFLOAT(float* pResultado, Producto* list, int length)
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
						acumulador = acumulador + list[i].precio;

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
/// @fn int prod_calcSuperiorAlPromedio(Producto*, int, float, float)
/// @brief calcula cuantos camposFLOAT superan el promedio de campoFloat
///
/// @param list lista a analizar
/// @param length longitud de la lista
/// @param promedio promedio de precio
/// @return -n ERROR // <0 SUCCES
int prod_calcSuperiorAlPromedio(Producto* list, int length, float promedio)
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
				if(list[i].isEmpty == 0 && (list[i].precio > promedio))
				{
					contador++;
				}
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

int printMyStock(Producto* pList, User userLogeado)
{
	int ret = -1;
	int i;
	int flagHayStock=0;
	for(i=0; i<PROD_LEN; i++)
	{
		if( pList[i].FK_userVendedorIDD == userLogeado.idUsuario &&
			pList[i].isEmpty == OCUPADO &&
			pList[i].stock >= 0 )
		{
			ret = 0;//hay algo por lo menos
			if(flagHayStock == 0)
			{
				encabezadoMyStock();
				flagHayStock = 1;
			}
			prod_printMyStockOneProduct(pList[i]);
		}
	}
	if(flagHayStock == 1)
	{
		pieMyStock();
	}
	return ret;
}

void encabezadoMyStock()
{
	printf("+----+-------------------------+------------+-----+---------+\n");
	printf("| ID |          NOMBRE         |  CATEGORIA |STOCK|  PRECIO |\n");
	printf("+----+-------------------------+------------+-----+---------+\n");
}
void pieMyStock()
{
	printf("+----+-------------------------+------------+-----+---------+\n");
}

//va a devolver la cantidad de productos dados de baja
int prod_bajaProdsPorUserBaja(int userBajaID, Producto* pList)
{
	int i;
	int contador = 0;
	for(i=0; i<PROD_LEN; i++)
	{
		if(pList[i].FK_userVendedorIDD == userBajaID)
		{
			pList[i].isEmpty=CANCELADO;
			contador++;
		}
	}
	if(contador>0)
	{
		printf("Se han dado de baja %d productos del usuario dado de baja\n",contador);
	}
	else
	{
		printf("El user no tenia productos a la venta\n");
	}
	return contador;
}



int prod_reponerStock(User userLogeado, Producto* pList)
{
	int ret = -1;
	printMyStock(pList, userLogeado);
	int idProd;
	int qty;
	int pIndexAux;
	if(utn_getNumero(&idProd, "Introduzca el ID del prod que desea reponer\n", "Error, invalido\n", 1000, 3000, 2) == 0)
	{
		pIndexAux = prod_findIndexByIdV2(pList, PROD_LEN, idProd);
		if(pIndexAux >= 0)
		{
			if(utn_getNumero(&qty, "Cuantas unidades desea reponer?\n", "ERROR\n", 1, STOCK_MAX, 2) == 0)
			{
				prod_updatearStock(pList, pIndexAux, qty);
				ret = 0;
			}
			else
			{
				printf("Demasiados errores, vuelvo al menu\n");
			}
		}

	}
	return ret;
}


int prod_printProdByName(Producto* pList)
{
	int ret;
	char nombreProd[PROD_NOMBRE_LEN];
	if(utn_getDescripcion(nombreProd, PROD_NOMBRE_LEN, "Ingrese el nombre del producto a buscar\n"
	, "ERROR\n", 20) == 0)
	{
		if(prod_findProdByName(nombreProd, pList) == 0)
		{

		}
		else
		{
			printf("No hay productos con ese nombre, el buscador distingue entre minus y mayus, saludos\n");
		}
	}
	else
	{
		ret = -1;
	}
	return ret;
}

int prod_findProdByName(char* prodName, Producto* pList)
{
	int ret = -1; // no hubo ninguna coincidencia
	int auxCMP;
	Producto pListAux[PROD_LEN];
	prod_initProd(pListAux, PROD_LEN);
	int i;
	for(i=0; i<PROD_LEN; i++)
	{
		auxCMP = strcmp(prodName,pList[i].nombre);
		if(auxCMP == 0)
		{
			ret = 0;//hubo al menos una coincidencia
//			printf("Encontre 1 coincidencia");
			//copio en un array aux el nombre que coincida
			pListAux[prod_getEmptyIndex(pListAux, PROD_LEN)] = pList[i];
//			printf("%s",pListAux[1].nombre);
		}
	}
	if(ret == 0)//si hubo al menos una coincidencia ordeno por stock
	{
		sortByStock(pListAux);
		ret = 0;
	}
	return ret;
}

int sortByStock(Producto* pListAux)
{
	int ret = -1; //NULL LIST
	int flagSwap;
	Producto aux;
	do
	{
		flagSwap = 0;
		int i;
		//limite -1 para que no compare contra la nada
		for(i=0; i<PROD_LEN-1; i++)
		{
			if(pListAux[i].isEmpty == 0)
			{
//				printf("%s\n",pListAux[i].nombre);
			}
			/*
			de todas formas es redundante porque solo copie lo que estaba ocupado
			pregunto si esta vacio itero una vez mas asi no comparo de mas
			*/
			if(pListAux[i].isEmpty == LIBRE || pListAux[i+1].isEmpty == LIBRE)
			{
				continue;
			}

			if(pListAux[i].stock>pListAux[i+1].stock)
			{
				flagSwap = 1;
				aux = pListAux[i];
				pListAux[i] = pListAux[i+1];
				pListAux[i+1] = aux;
			}

		}
	}
	while(flagSwap);

	encabezadoTablaProd();
	int i;
	for(i=0; i<PROD_LEN; i++)
	{
		if(pListAux[i].isEmpty == 0)
		{
			prod_printOne(pListAux[i]);
		}
	}
	pieTablaProd();
	return ret;
}





















