/*
 ============================================================================
 Name        : ABM_Generico.c
 Author      : Gonzalo Rodriguez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "relaciones.h"
#define INGRESAR 1
#define SALIR 0
#define COMPRAR 1
#define VENDER 2
#define	ESTADO_COMPRAS 3
#define ESTADO_VENTAS 4

int main(void)
{
	setbuf(stdout,NULL);
	printf( "--------A modo de introduccion al programa se explicara lo siguiente--------\n"
			"Por cada 10KM de distancia, se genera agregan 10 segundos al tiempo estimado de llegada del producto\n"
			"Se han hardcodeado 1 user Admin y 5 compradores/vendedores\n"
			"A continuacion se listaran los usuarios recien mencionados con sus credenciales correspondientes\n"
			"El listado tmb estara disponible en el submenu 1)del admin.\n"
			"El estado cancelado de un tracking se genera apartir de poner en -1 el campo isEmpty\n"
			"El FK para traer el tracking correspondiente al usuario logeado sera el indice en el que se encuentra el user\n"
			"\tPara la proxima se me ocurre generar un dato UserAUX y una vez pasado el logeo guardar los datos en el main\n"
			"\tpara que cuando sean necesarios extraer esos datos se tengan todos al alcance de la mano\n"
			"La baja de un producto desde el user ADMIN no impacta en las entregas EN CAMINO o ENTREGADO\n"
			"");
	int submenu2;
	int menuPrincipal;
	int menuUser;
	int userLogginRespuesta;
	char correo[CORREO_LEN];
	int userIndex;
	User userLogeado;
	int userIDBaja;

	//---------------------------INICIALIZACION DE ARRAYS---------------------------
	User userList[USER_LEN];
	user_initUser(userList, USER_LEN);
	user_cargaForzada(userList, USER_LEN);
	user_printByStatus(userList, USER_LEN, OCUPADO);

	Producto prodList[PROD_LEN];
	prod_initProd(prodList, PROD_LEN);
	prod_cargaForzada(prodList, PROD_LEN);

	Tracking trackingList[TRACKING_LEN];
	track_initTrack(trackingList, TRACKING_LEN);
	//---------------------------MENU PRINCIPAL---------------------------


	do
	{
		utn_getNumero(&menuPrincipal,
		"----Menu principal----\n"
		"1)Ingresar\n"
		"2)Registrarse\n"
		"0)Salir\n", "ERROR\n", 0, 2, 2);
		switch(menuPrincipal)
		{
			case INGRESAR:
				userLogginRespuesta = user_Loggin(userList, USER_LEN, correo, &userIndex, &userLogeado);
				switch (userLogginRespuesta)
				{
				case USER_ADMIN:
					do
					{
						utn_getNumero(&menuUser,"----Menu ADMIN----\n"
						"1)Listado de todos los usuarios\n"
						"2)Listado de prods en stock ordenados por cat y nombre\n"
						"3)Baja de un producto\n"
						"4)Baja de un user\n"
						"5)Ver tracking global\n"
						"6)Filtrar por nombre de prod\n"
						"0)Salir", "ERROR, revise las opciones\n", 0, 6, 1);
						switch(menuUser)
						{
							case 1:
								//***********Imprimir users**********
								user_printByStatus(userList, USER_LEN, OCUPADO);
								break;
							case 2:
								//***********Imprimir prods by vat, stock and name**********
								prod_printByCatStockYAlfabeticoAdmin(prodList, PROD_LEN);
								break;
							case 3:
								//***********Baja prod by ID**********
								prod_bajaProd(prodList, PROD_LEN);
								break;
							case 4:
								//***********Baja USER by ID**********

								if(user_bajaUser(userList, USER_LEN, &userIDBaja) == 0)
								{
									//***********Baja de sus PRODS by ID**********
									prod_bajaProdsPorUserBaja(userIDBaja, prodList);
								}
								break;
							case 5:
								//Ver tracking global
								track_printTrackingAdmin(trackingList);
								break;
							case 6:
								prod_printProdByName(prodList);
								break;
							case SALIR:
								break;
						}
					}while(menuUser != 0);
					break;
				case USER_CONVENCIONAL:
					do
					{
						utn_getNumero(&menuUser,"----Menu usuario convencional----\n"
						"1)Comprar\n"
						"2)Vender\n"
						"3)Estado de compras\n"
						"4)Estado de ventas\n"
						"0)Salir\n", "ERROR, revise las opciones\n", 0, 4, 1);
						switch(menuUser)
						{
							case COMPRAR:
								printf("Se mostraran los prods ordenados por CAT y solo si hay stock\n");
								prod_printByCat(prodList, PROD_LEN, 2);
								prod_comprar(prodList, PROD_LEN, userList, userIndex, trackingList);
								break;
							case VENDER:

								do
								{
									utn_getNumero(&submenu2, "1)Alta de prod\n2)Reponer Stock\n0)Salir\n", "ERROR, revise las opciones\n", 0, 2, 1);
									switch (submenu2)
									{
									case 1:
										prod_altaProd(prodList, PROD_LEN, userLogeado);
										break;
									case 2:
										prod_reponerStock(userLogeado, prodList);
										break;
									}
								}while(submenu2 != 0);
								break;
							case ESTADO_COMPRAS:
								estadoDeCompras(userLogeado.idUsuario, trackingList, prodList);
								break;
							case ESTADO_VENTAS:
								estadoDeVentas(userLogeado, prodList, trackingList);
								break;
						}
					}while(menuUser!=0);
					break;
				default:
					printf("Usted no es nada\n");
					break;
				}
			break;
		}
	}
	while(menuPrincipal != 0);
	return EXIT_SUCCESS;
}

