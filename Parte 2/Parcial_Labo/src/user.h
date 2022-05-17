/*
 * struct.h
 *
 *  Created on: 8 May 2022
 *      Author: gonzr
 */

#ifndef USER_H_
#define USER_H_
#define USER_LEN 200
#define CORREO_LEN 30
#define PASS_LEN 10
#define DIRECCION_LEN 50
#define USER_ADMIN 1
#define USER_CONVENCIONAL 2
#define NOMBRE_LEN 25
#define LIBRE 1
#define OCUPADO 0
#define USERBAJA -1



typedef struct
{
	int idUsuario;
	char correo[CORREO_LEN];
	char nombre[NOMBRE_LEN];
	int tipoUser;
	char password[PASS_LEN];
	char direccion[DIRECCION_LEN];
	int codigoPostal;
	int isEmpty;
}User;

int user_initUser(User* list, int length);
void user_printOne(User user);
void encabezadoTablaUser(void);
void pieTablaUser(void);
int user_cargaForzada(User* list, int length);
int user_getEmptyIndex(User* list, int length);
int user_findIndexById(User* list, int length);
int user_printByStatus(User* list, int length, int status);
int user_bajaUser(User* list, int length, int* bajaUser);
int user_Loggin(User* list, int length, char* correoaux, int* uIndex, User* userLogg);
int user_checkCorreo(char* mail, User* list, int length, int* indexUser, char* correoaux);
int user_checkPass(User* list, int length, int indexAux);
int user_copyArray(User* list, User* listCopy, int length);



#endif /* USER_H_ */
