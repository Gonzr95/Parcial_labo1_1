/*
 * struct.c
 *
 *  Created on: 8 May 2022
 *      Author: gonzr
 */
#include "relaciones.h"


//--------------------Generador de ID's--------------
static int idAutoIncremental = 1000;
static int user_generateID();
/// @fn int user_generateID()
/// @brief genera un id en base a un contador
///
/// @return retorna el id
static int user_generateID()
{
	return idAutoIncremental++;
}
//--------------------Generador de ID's--------------



/// @fn int user_initUser(User array[], int length)
/// @brief Initiates the array changing the member isEmpty to 1 (TRUE)
///
/// @param array Pointer to array of userengers
/// @param length Length of the array
/// @return -1 length minor to one, -2 NULL pointer
int user_initUser(User* list, int length)
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

/// @fn void user_printOne(User)
/// @brief imprime solo un dato del tipo User
/// el numero que va dsp del % es correlativo con la cantidad de - que tiene el encabezado
/// @param User
void user_printOne(User user)
{
    // 4               26                          25                  10                20	      4          15
	//ID           CORREO                         nombre            PASSWORD        DIRECCION       CP        TIPO
	printf( "|%d|%-30s|%-25s|%-10s|%-20s|%-4d"
			,user.idUsuario,user.correo,user.nombre,user.password,user.direccion,user.codigoPostal);

	switch(user.tipoUser)
	{
		char permisos[20];
		case USER_ADMIN:
			strncpy(permisos,"Administrador",sizeof(permisos));
			printf("|%-15s",permisos);
			break;
		case USER_CONVENCIONAL:
			strncpy(permisos,"Convencional",sizeof(permisos));
			printf("|%-15s",permisos);
			break;
	}
	switch(user.isEmpty)
	{
		char estado[20];
		case OCUPADO:
			strncpy(estado,"ACTIVO",sizeof(estado));
			printf("|%-10s|\n",estado);
			break;
		case USERBAJA:
			strncpy(estado,"BAJA",sizeof(estado));
			printf("|%-10s|\n",estado);
			break;
	}
}

void encabezadoTablaUser(void)
{
	        // 4               26                           25                  10                20	      4          15
			//ID           CORREO                         nombre            PASSWORD        DIRECCION       CP        TIPO
	printf("+----+------------------------------+-------------------------+----------+--------------------+----+---------------+----------+\n");
	printf("| ID |            CORREO            |          NOMBRE         | PASSWORD |      DIRECCION     | CP |      TIPO     |  ESTADO  |\n");
	printf("+----+------------------------------+-------------------------+----------+--------------------+----+---------------+----------+\n");
}
void pieTablaUser(void)
{
	printf("+----+------------------------------+-------------------------+----------+--------------------+----+---------------+----------+\n");
}

/// @fn int user_cargaForzada(User*, int)
/// @brief hardcodea datos con el fin de adelantar el testing de nuestro programa
///
/// @param list puntero a larray de user
/// @param length longitud de dicho array
/// @return -1 NULL list  // -2 longitud muy pequeña  //
int user_cargaForzada(User* list, int length)
{
	int ret = -1; //LIST NULL

	User userAux[6];

	if(list != NULL)
	{

		if(length >0)
		{
			//ADMIN
			userAux[0].idUsuario = user_generateID();
			strncpy(userAux[0].correo,"jefe@hotmail.com",CORREO_LEN);
			strncpy(userAux[0].nombre,"Jefe",NOMBRE_LEN);
			strncpy(userAux[0].password,"Admin1234",PASS_LEN);
			strncpy(userAux[0].direccion,"Alcorta 295",DIRECCION_LEN);
			userAux[0].tipoUser = USER_ADMIN;
			userAux[0].codigoPostal = 1;
			userAux[0].isEmpty = OCUPADO;

			//Convencionales
			userAux[1].idUsuario = user_generateID();
			strncpy(userAux[1].correo,"gonz.r@hotmail.com",CORREO_LEN);
			strncpy(userAux[1].nombre,"Gonzalo",NOMBRE_LEN);
			strncpy(userAux[1].password,"paso1234",PASS_LEN);
			strncpy(userAux[1].direccion,"Jacinto Rosso 462",DIRECCION_LEN);
			userAux[1].tipoUser = USER_CONVENCIONAL;
			userAux[1].codigoPostal = 1954;
			userAux[1].isEmpty = OCUPADO;

			userAux[2].idUsuario = user_generateID();
			strncpy(userAux[2].correo,"agostina.ang@hotmail.com",CORREO_LEN);
			strncpy(userAux[2].nombre,"Agostina",NOMBRE_LEN);
			strncpy(userAux[2].password,"pass1234",PASS_LEN);
			strncpy(userAux[2].direccion,"Plaza Bynon 79",DIRECCION_LEN);
			userAux[2].tipoUser = USER_CONVENCIONAL;
			userAux[2].codigoPostal = 1378;
			userAux[2].isEmpty = OCUPADO;

			userAux[3].idUsuario = user_generateID();
			strncpy(userAux[3].correo,"ivan.sosa@hotmail.com",CORREO_LEN);
			strncpy(userAux[3].nombre,"Ivan",NOMBRE_LEN);
			strncpy(userAux[3].password,"pass1234",PASS_LEN);
			strncpy(userAux[3].direccion,"Cangallo 499",DIRECCION_LEN);
			userAux[3].tipoUser = USER_CONVENCIONAL;
			userAux[3].codigoPostal = 6666;
			userAux[3].isEmpty = OCUPADO;


			userAux[4].idUsuario = user_generateID();
			strncpy(userAux[4].correo,"micaela.bogado@hotmail.com",CORREO_LEN);
			strncpy(userAux[4].nombre,"Micaela",NOMBRE_LEN);
			strncpy(userAux[4].password,"pass1234",PASS_LEN);
			strncpy(userAux[4].direccion,"King 919",DIRECCION_LEN);
			userAux[4].tipoUser = USER_CONVENCIONAL;
			userAux[4].codigoPostal = 2;
			userAux[4].isEmpty = OCUPADO;

			userAux[5].idUsuario = user_generateID();
			strncpy(userAux[5].correo,"juan.ezeisa@gmail.com",CORREO_LEN);
			strncpy(userAux[5].nombre,"Juan",NOMBRE_LEN);
			strncpy(userAux[5].password,"pass1234",PASS_LEN);
			strncpy(userAux[5].direccion,"Condarco 395",DIRECCION_LEN);
			userAux[5].tipoUser = USER_CONVENCIONAL;
			userAux[5].codigoPostal = 800;
			userAux[5].isEmpty = OCUPADO;


			int emptyIndex;
			int i;
			for(i=0; i<6; i++)
			{
				emptyIndex = user_getEmptyIndex(list, USER_LEN);
				list[emptyIndex] = userAux[i];
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

/// @fn int user_getEmptyIndex(User*, int, int)
/// @brief	busca un lugar vacio en el array
///
/// @param array
/// @param length
/// @return -1 NO HAY LUGAR; -2 EL ARRAY ES NULO; -3 LENGTH MENOR A 1
int user_getEmptyIndex(User* list, int length)
{
	int ret = -1;
	if(list !=NULL)
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
			ret = -2;
		}
	}
	return ret;
}


/// @fn int user_findIndexById(User*, int)
/// @brief pide el ID de un strut1 y retorna en que posicion del array se encuentra
///
/// @param list array de struc1
/// @param length longitud del mismo
/// @return el indice en el que se encuentra ese ID o errores
int user_findIndexById(User* list, int length)
{
	int ret = -1; // lista NULL
	int idAux;
	if(list != NULL)
	{
		if(length > 0)
		{
			if(utn_getNumero(&idAux, "Ingrese el ID de 4 digitos de la user que busca\n", "ERROR, reintente\n", 0, 9999, 2) == 0)
			{
				int i;
				for(i=0; i<length; i++)
				{
					if(idAux == list[i].idUsuario)
					{
						if(list[i].isEmpty == OCUPADO)
						{
							ret = i; // retorno el indice en el que se encuentra ese ID
							break;
						}
						else
						{
							if(list[i].isEmpty == USERBAJA)
							{
								printf("El user ya esta dado de baja\n");
							}
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

/// @fn int user_printByStatus(User*, int, int)
/// @brief imprime los datos del struct por estado de variable isEmpty
///
/// @param list
/// @param length
/// @param status valor que queremos buscar e imrpimer de IsEMpty
/// @return -n ERRORES // 0 SUCCESS
int user_printByStatus(User* list, int length, int status)
{
	int ret = -1; //NULL LIST
	if(list != NULL)
	{
		if(length > 0)
		{
			encabezadoTablaUser();
			int i;
			for(i=0; i<length; i++)
			{
				if(list[i].isEmpty == status || list[i].isEmpty == USERBAJA)
				{
					user_printOne(list[i]);
					ret = 0;
				}
			}
			pieTablaUser();
		}
		else
		{
			ret = -2; //la longitud de la lista es menor a 1
		}
	}
	return ret;
}

/// @fn int user_bajauser(User*, int)
/// @brief reescribe el campo isEmpty como LIBRE para dar de baja al struct
///
/// @param list array a analizar
/// @param length longitud del mismo
/// @return -n ERRORES / 0 SUCCESS
int user_bajaUser(User* list, int length, int* idUser)
{
	int ret = -1;
	int indexBaja;
	if(list != NULL)
	{
		if(length > 0)
		{
			printf("Vas a dar de baja un User, esto dara de baja todos sus productos en stock\n");
			indexBaja = user_findIndexById(list, length);
			if(indexBaja >= 0)
			{
				if(validateExit_YN("Estas seguro de dar de baja?? Y/N\n", "ERROR, revise opciones\n", 2) == 1)
				{
					list[indexBaja].isEmpty = USERBAJA;
					*idUser = list[indexBaja].idUsuario;
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





/// @fn int user_copyArray(User*, User*, int)
/// @brief toma un array de struct y copia los indices que esten ocupados
///  en un auxiliar que ha recibido por puntero
///
/// @param list puntero al array original
/// @param listCopy puntero al array de copia
/// @param length longitud de los array
/// @return -n ERRORES // 0 SUCCESS
int user_copyArray(User* list, User* listCopy, int length)
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

/// @fn int userLoggin(void)
/// @brief
///
/// @return 1 ADMIN 2 USERConvencional 0 ERROR
int user_Loggin(User* list, int length, char* correoaux, int* uIndex, User* userLogg)
{
	int ret = -1;//
	char correo[CORREO_LEN];
	int userIndex;
	if(utn_getMail(correo, CORREO_LEN, "Ingrese su correo, sin el dominio (hasta 15chars)\n", "ERROR\n", 2) == 0)
	{
		if(user_checkCorreo(correo, list, length, &userIndex, correoaux) == 0)
		{
//			printf("Hubo coincidencia de user en la base de datos\n");
			int respuestaCheckPass;
			respuestaCheckPass = user_checkPass(list, length,userIndex);
			* uIndex = userIndex;
			* userLogg = list[userIndex];
			switch(respuestaCheckPass)
			{
				case USER_ADMIN:
					printf("Bienvenido %s\n",list[userIndex].nombre);
					ret = USER_ADMIN;
					break;
				case USER_CONVENCIONAL:
					printf("Bienvenido %s\n",list[userIndex].nombre);
					ret = USER_CONVENCIONAL;
					break;
				case -5:
					printf("Usuario Dado de baja, retirese\n");
					break;
				default:
					ret = -3; //error de user check pass
					break;
			}
		}
		else
		{
			ret = -2;//error de mail
		}
	}
	return ret;
}
/// @fn int user_checkCorreo(char)
/// @brief
///
/// @param mail
/// @return -1 NULL, -2 null list, -3 length incorrecta
///  -4 no esta en la base de datos 0 SUCCES
int user_checkCorreo(char* mail, User* list, int length, int* indexUser, char* correoaux)
{
	int ret = -1;//mail null
	if(mail != NULL)
	{
		if(list != NULL)
		{
			if(length > 0)
			{
				int auxCMP;
				int i;
				for(i=0; i<length; i++)
				{
					auxCMP = strcmp(mail,list[i].correo);
					if(auxCMP == 0)
					{
						ret = 0;
						*indexUser = i;
						strncpy(correoaux,mail,CORREO_LEN);
//						printf("Hay coincidencia entre mail y database\n");
						break;//hay coincidencia
					}

				}
			}
			else
			{
				ret = -3;
			}
		}
		else
		{
			ret = -2;
		}
	}
	return ret;
}

int user_checkPass(User* list, int length, int indexAux)
{
	int ret = -1; //NULL list;
	if(list != NULL)
	{
		if(length>0)
		{
			char passwordAux[PASS_LEN];
			int reintentos = 2;
			do
			{
				if(utn_getPassword(passwordAux, PASS_LEN, "Ingrese su password (10 Caracteres alfaNum)\n", "ERROR\n", 2) == 0)
				{
	//				printf("bien voy a corroborar la pass\n");
					int auxCMP;
					auxCMP = strcmp(passwordAux,list[indexAux].password);
					if(auxCMP == 0)
					{
						if(list[indexAux].isEmpty == USERBAJA)
						{
							return -5;
						}
						else
						{
							ret = list[indexAux].tipoUser;
							break;
		//					printf("Hay coincidencia entre pass y database\n");
						}
					}
					else
					{
						printf("Contraseña incorrecta\n");
						reintentos--;
						ret = -4; //no hubo coincidencia entre la pass y la database
					}
				}
				else
				{
					ret = -3;//error de la utn _get pass
				}
			}while(reintentos >= 0);

		}
		else
		{
			ret = -2;// error de longitud
		}
	}
	return ret;
}







