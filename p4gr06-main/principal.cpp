#include "./include/IUsuario.h"
#include "./include/ICurso.h"
#include "./include/Fabrica.h"
#include "./include/ControladorUsuario.h"
#include "./include/DTUsuario.h"
#include <iostream>
#include <string>
#include <set>
#include <vector>

enum enum_cmd_t {
	cmd_fin,
	cmd_altaUsuario,
	cmd_consulta_de_usuario,
	cmd_altaIdioma,
	cmd_consultar_idiomas,
	cmd_altaCurso,
	cmd_agregarleccion,
	cmd_agregarejercicio,
	cmd_consultar_estadisticas,
	cmd_suscribirse_a_notificaciones,
	cmd_consulta_de_notificaciones,
	cmd_eliminar_suscripciones,
	no_reconocido
};
const int cant_com = no_reconocido;

struct enum_nombre_cmd {
  const enum_cmd_t enum_cmd;
  const char *nombre_cmd;
};

const enum_nombre_cmd cmds[] = {{cmd_fin, "Fin"}, {cmd_altaUsuario, "Alta de usuario"}, {cmd_consulta_de_usuario, "Consulta de usuario"}, {cmd_altaIdioma, "Alta de idioma"}, {cmd_consultar_idiomas, "Consultar idiomas"}, {cmd_altaCurso, "Alta de curso"}, {cmd_agregarleccion, "Agregar leccion"},{cmd_agregarejercicio, "Agregar ejercicio"}, {cmd_consultar_estadisticas, "Consultar estadiscicas"},{cmd_suscribirse_a_notificaciones, "Suscribirse a notificaciones"}, {cmd_consulta_de_notificaciones,"Consulta de notificaciones"}, {cmd_eliminar_suscripciones, "Eliminar suscripciones"}};

void solicitar_cmd() {
	int cont = 1;
	while(cont<=cant_com) {
		std::cout << cont << ". " << cmds[cont-1].nombre_cmd << std::endl;
		cont++;
	}
	std::cout << "Ingrese el numero de comando que quiera ejecutar: ";

}

enum_cmd_t identificarComando() {
	int i;
	std::cin >> i;
	std::cout << std::endl;
	if(i-1 < cant_com)
		return cmds[i-1].enum_cmd;
	else
		return no_reconocido;
}

int main() {
	Fabrica fabrica;
	bool salir = false;
	while(!salir) {
		solicitar_cmd();
		enum_cmd_t enum_com = identificarComando();
		//std::cout << "Has elegido el comando: " << cmds[enum_com].nombre_cmd << std::endl;
		switch(enum_com) {
			//FIN
			case cmd_fin: {
				salir = true;
				std::cout << "Fin." << std::endl;
				break;
			}


			//ALTA DE USUARIO
			case cmd_altaUsuario: {
				IUsuario * iu = fabrica.getIUsuario();

				int tipoU;
				std::cout << "Ingrese 1 si quiere registrar un Estudiante o 2 si quiere registrar un Profesor: ";
				std::cin >> tipoU;
				std::cout << std::endl;
				while(tipoU != 1 && tipoU != 2) {
					std::cout << "El numero no es valido." << std::endl;
					std::cout << "Ingrese 1 si quiere registrar un Estudiante o 2 si quiere registrar un Profesor: ";
					std::cin >> tipoU;
					std::cout << std::endl;				
				}

				std::cout << "Ingrese nombre de usuario: ";
				std::string nickname;
				std::cin >> nickname;
				std::cout << std::endl;

				std::cout << "Ingrese contrasenia (minimo 6 caracteres): ";
				std::string contrasenia;
				std::cin >> contrasenia;
				std::cout << std::endl;
				while(contrasenia.size() < 6) {
					std::cout << "La contrasenia es muy corta, ingrese una nueva: ";
					std::cin >> contrasenia;
					std::cout << std::endl;
				}

				std::cout << "Ingrese su nombre: ";
				std::string nombre;
				std::cin >> nombre;
				std::cout << std::endl;

				std::string descripcion;
				std::cout << "Ingrese una descripcion: " << std::endl;
				std::cin.ignore(); 
				std::getline(std::cin, descripcion);
				//std::cout << "La descripcion es: " << descripcion << std::endl;
				

				if(tipoU == 1) { //Estudiante
					std::cout << "Ingrese su pais de residencia: ";
					std::string pais;
					std::cin >> pais;
					std::cout << std::endl;

					std::cout << "Ingrese su dia de nacimiento: ";
					int dia;
					std::cin >> dia;
					std::cout << std::endl;

					std::cout << "Ingrese su mes de nacimiento: ";
					int mes;
					std::cin >> mes;
					std::cout << std::endl;

					std::cout << "Ingrese su anio de nacimiento: ";
					int anio;
					std::cin >> anio;
					std::cout << std::endl;

					DTFecha fecha_nacimiento = DTFecha(dia,mes,anio);
					iu->ingresarDatosUsuario(nickname, contrasenia, nombre, descripcion);
					iu->ingresarPaisResidencia(pais);
					iu->ingresarFechaNacimiento(fecha_nacimiento);
					bool altaEst = iu->confirmarAltaEstudiante();
					if(altaEst)
						std::cout << "El usuario ha sido creado con exito." << std::endl;
					else while(!altaEst){
						std::cout << "El nickname no esta disponible, ingrese uno nuevo: ";
						std::cin >> nickname;
						std::cout << std::endl;
						iu->setNickname(nickname);
						altaEst = iu->confirmarAltaEstudiante();
					}
					std::cout << std::endl;
					break;
				}
				else { //Profesor
					std::cout << "Ingrese su instituto de trabajo: " << std::endl;
					std::string instituto;
					std::cin.ignore();
					std::getline(std::cin, instituto);
					std::cout << std::endl;

					std::set<std::string> set_idiomas = iu->obtenerIdiomasDisponibles();
					//std::cout << (set_idiomas.empty()) << std::endl;
					if(!set_idiomas.empty()) {
						std::cout << "LOS IDIOMAS DISPONIBLES SON:" << std::endl;
						int i = 1;
						for (std::set<std::string>::iterator it = set_idiomas.begin(); it != set_idiomas.end(); ++it){
	        				std::cout << i << ". " << (*it) << std::endl;
	        				i++;
	    				}
	    				bool agregar = true;
	    				int contador = 1;
	    				std::string idiomaEsp;
	    				while(agregar || contador < i-1) {
	    					std::cout << "Ingrese el nombre del idioma que desee agregar a sus especializaciones: ";
	    					std::cin >> idiomaEsp;
	    					iu->agregarEspecializacion(idiomaEsp);
	    					std::cout << std::endl;
	    					std::cout << "SI DESEA SEGUIR AGREGANDO ESPECIALIZACIONES INGRESE 1, 0 SI NO: ";
	    					
	    					std::cin >> agregar;
	    					contador++;
	    				}
    				}
    				iu->ingresarDatosUsuario(nickname, contrasenia, nombre, descripcion);
					iu->ingresarInstituto(instituto);
					bool altaProf = iu->confirmarAltaProfesor();
					if(altaProf){
						std::cout << "El usuario ha sido creado con exito." << std::endl;
					}
					else {
						while(!altaProf){
							std::cout << "El nickname no esta disponible, ingrese uno nuevo: ";
							std::cin >> nickname;
							std::cout << std::endl;
							iu->setNickname(nickname);
							altaProf = iu->confirmarAltaProfesor();
						}
					}
					std::cout << std::endl;
					
					break;
				}
			}



			//CONSULTA DE USUARIO
			case cmd_consulta_de_usuario: {
				IUsuario * iu = fabrica.getIUsuario();
				std::string nick;
				std::set<std::string> nicksUsuarios = iu->obtenerNicks();
				std::cout << "LOS NICKNAMES DISPONIBLES HASTA EL MOMENTO SON:" << std::endl;
				for (std::set<std::string>::iterator it = nicksUsuarios.begin(); it != nicksUsuarios.end(); ++it){
	        				std::cout << (*it) << std::endl;
	    		}
	    	std::cout << std::endl;
	    	std::cout << "INGRESE EL NICKNAME QUE DESEA CONSULTAR: " << std::endl;
	    	std::cin >> nick;
	    	std::cout << std::endl;
	    	bool nickValido = !iu->NicknameDisponible(nick);
				bool quit = false;
				if(!nickValido) {
					while(!nickValido && !quit){
						std::cout << "El nickname no es valido, ingrese uno nuevo, si desea salir ingrese 0: ";
						std::cin >> nick;
						std::cout << std::endl;
						if(nick != "0")
							nickValido = !iu->NicknameDisponible(nick);
						else 
							quit = true;
					}
				}
				if(!quit) {
					bool esEst = iu->esEstudiante(nick);
					if(esEst) {
						DTEstudiante de = iu->obtenerInfoEstudiante(nick);
						std::cout << de << std::endl;
					}
					else {
						DTProfesor dp = iu->obtenerInfoProfesor(nick);
						std::cout << dp << std::endl;
					}
				}
				break;
			}

			

			//ALTA DE IDIOMA
			case cmd_altaIdioma: {
				ICurso * ic = fabrica.getICurso();
				std::string nomIdioma;
				std::cout << "Ingrese el nombre del idioma que desea registrar: ";
				std::cin >> nomIdioma;
				std::cout << std::endl;
				bool verificar = ic->altaIdioma(nomIdioma);
				if(verificar) {
					std::cout << "El idioma de nombre: " << nomIdioma << " ha sido creado." << std::endl;
				} else {
					std::cout << "El idioma de nombre: " << nomIdioma << " ya existe." << std::endl;
				}
				std::cout << std::endl;
				break;
			}


			//CONSULTAR IDIOMAS
			case cmd_consultar_idiomas: {
				ICurso * ic = fabrica.getICurso();
				std::set<std::string> idiomas= ic->consultarIdiomas();
				std::cout << "LOS IDIOMAS DISPONIBLES SON: " << std::endl;
				for(std::set<std::string>::iterator it = idiomas.begin(); it != idiomas.end(); ++it) {
					std::cout << (*it) << std::endl;
				}
				std::cout << std::endl;
				break;
			}


			//ALTA DE CURSO
			case cmd_altaCurso: {
				ICurso * ic = fabrica.getICurso();
				IUsuario * iu = fabrica.getIUsuario();
				std::set<std::string> profes = ic->obtenerNicksProfes();
				std::cout << "LOS NICKNAMES DE LOS PROFESORES SON:" << std::endl;
				for(std::set<std::string>::iterator it = profes.begin(); it != profes.end(); ++it) {
					std::cout << (*it) << std::endl;
				}
				std::string nickProf;
				std::cout << "INGRESE EL NICKNAME DEL PROFESOR QUE DESEA ELEGIR: ";
				std::cin >> nickProf;
				std::cout << std::endl;
				bool nickValido = !iu->NicknameDisponible(nickProf);
				bool quit = false;
				if(!nickValido) {
					while(!nickValido && !quit){
						std::cout << "El nickname no es valido, ingrese uno nuevo, si desea salir ingrese 0: ";
						std::cin >> nickProf;
						std::cout << std::endl;
						if(nickProf != "0")
							nickValido = !iu->NicknameDisponible(nickProf);
						else 
							quit = true;
					}
				}
				if(!quit) {
					ic->seleccionarProfesor(nickProf);
					std::string nomCurso;
					std::cout << "INGRESE EL NOMBRE DEL CURSO QUE DESEA CREAR: ";
					std::cin >> nomCurso;
					std::cout << std::endl;

					std::string descCurso;
					std::cout << "INGRESE LA DESCRIPCION DEL CURSO QUE DESEA CREAR: ";
					std::cin >> descCurso;
					std::cout << std::endl;

					int dif;
					std::cout << "Ingrese 0 si la dificultad es 'Principiante', 1 si es 'Intermedio' o 2 si es 'Avanzado': ";
					std::cin >> dif;
					std::cout << std::endl;
					while(dif!=0 && dif!=1 && dif!=2 && dif!=-1) {
						std::cout << "El numero ingresado no es un numero valido. Ingrese otro, o si desea salir ingrese -1: ";
						std::cin >> dif;
						std::cout << std::endl;
					}
					if(dif!=-1) {
						enumDificultad dificultad = noms[dif].enum_dif;
						ic->ingresarDatosCurso(nomCurso, descCurso, dificultad);
						std::cout << "A continuacion se listaran las especializaciones del profesor:" << std::endl;
						std::set<std::string> idiomas = ic->obtenerIdiomasProfe();
						for(std::set<std::string>::iterator it = idiomas.begin(); it != idiomas.end(); ++it) {
							std::cout << (*it) << std::endl;
						}
						std::string idioma;
						std::cout << "Ingrese el nombre del idioma que enseñara el curso: ";
						std::cin >> idioma;
						std::cout << std::endl;
						ic->seleccionarIdioma(idioma);

						std::cout <<"Ingrese 1 si el curso necesitara la aprobacion de cursos previos y 0 si no: ";
						bool prev;
						std::cin >> prev;
						std::cout << std::endl;
						if(prev) {
							std::set<std::string> cursosH = ic->obtenerCursosHabilitados();
							std::string nomPrevia;
	    					std::cout << "Ingrese los nombres de los cursos que desea agregar como previa (ingrese 'fin' para terminar):" << std::endl;
						    while (std::cin >> nomPrevia && nomPrevia != "fin") {
						        ic->agregarPrevia(nomPrevia);
	  					  	}
	  					}

  					  bool agregarLec;
  					  std::cout <<"Ingrese 1 si desea agregar una leccion y 0 si no: ";
  					  std::cin >> agregarLec;
							std::cout << std::endl;
							if(agregarLec) 
								std::cout << "Por favor, ingrese las lecciones en el orden que desee que las realice el estudiante." << std::endl;
							while(agregarLec) {
								std::string nomTema;
								std::cout << "Ingrese el nombre del tema que tratara la leccion: ";
								std::cin >> nomTema;
								std::cout << std::endl;

								std::string objetivo;
								std::cout << "Ingrese el objetivo de la leccion: ";
								std::cin >> objetivo;
								std::cout << std::endl;
								ic->agregarLeccion(nomTema, objetivo);
								bool agregarEj;
								std::cout <<"Ingrese 1 si desea agregar un ejercicio a la leccion y 0 si no: ";
								std::cin >> agregarEj;
								std::cout << std::endl;
								while(agregarEj) {
									std::string tipoEj;
									std::cout << "Ingrese el tipo de ejercicio que desea agregar (Completar o Traducir): " << std::endl;
									std::cin >> tipoEj;
									std::cout << std::endl;
									
									std::string descEj;
									std::cout << "Ingrese la descripcion del ejercicio: " << std::endl;
									std::cin >> descEj;
									std::cout << std::endl;

									if(tipoEj == "Completar") {
										std::string fraseCompletar;
										std::cout << "Ingrese la frase a completar (los espacios se representan con 3 guiones ---):" << std::endl;
										std::cin.ignore();
										std::getline(std::cin, fraseCompletar);

										std::string solucion;
										std::cout << "Ingrese la solucion (conjunto de palabras separadas por coma que conforman la solucion):" << std::endl;
										std::cin.ignore();
										std::getline(std::cin, solucion);

										ic->agregarEjercicioCompletar(fraseCompletar, solucion);

									} else {
										std::string fraseTraducir;
										std::cout << "Ingrese la frase a traducir:" << std::endl;
										std::cin.ignore();
										std::getline(std::cin, fraseTraducir);

										std::string solucion;
										std::cout << "Ingrese la traduccion:" << std::endl;
										std::cin.ignore();
										std::getline(std::cin, solucion);

										ic->agregarEjercicioTraducir(fraseTraducir, solucion);
									}
									std::cout << "Si desea agregar otro ejercicio ingrese 1 y 0 si no: ";
									std::cin >> agregarEj;
									std::cout << std::endl;
								}
								std::cout << "Si desea agregar otra leccion ingrese 1 y 0 si no: ";
								std::cin >> agregarLec;
								std::cout << std::endl;
							}
							ic->confirmarAltaCurso();
						}
					} 
				

				break;
			}
	//AGREGAR LECCION
	case cmd_agregarleccion: {
		ICurso * icc = fabrica.getICurso();
		std::string nomTema;
		std::cout << "Ingrese el nombre del tema que tratara la leccion: ";
		std::cin >> nomTema;
		std::cout << std::endl;

		std::string objetivo;
		std::cout << "Ingrese el objetivo de la leccion: ";
		std::cin >> objetivo;
		std::cout << std::endl;
		icc->agregarLeccion(nomTema, objetivo);

		bool agregar;
		std::cout << "Si desea agregar un ejercicio a la leccion ingrese 1 y 0 si no: ";
		std::cin >> agregar;
		std::cout << std::endl;

		int tipoEj;
		while(agregar) {
		    std::cout << "Ingrese 1 si quiere un ejercicio de completar o 2 si quiere uno de traduccion: ";
		    std::cin >> tipoEj;
		    std::cout << std::endl;
		    if(tipoEj == 1) {
		        std::string frase;
		        std::string solucion;
		        std::cout << "Ingrese la frase para completar escribiendo --- en los espacios a completar: " << std::endl;
		        std::cin.ignore();
		        std::getline(std::cin, frase);
		        std::cout << std::endl;
		        std::cout << "Ingrese la solucion: " << std::endl;
		        std::cin.ignore();
		        std::getline(std::cin, solucion);
		        icc->agregarEjercicioCompletar(frase, solucion);
		        std::cout << "Si desea seguir agregando ejercicios ingrese 1 y 0 si no: ";
		        std::cin >> agregar;
		    } else {
		        std::string frase;
		        std::string solucion;
		        std::cout << "Ingrese la frase para traducir: " << std::endl;
		        std::cin.ignore();
		        std::getline(std::cin, frase);
		        std::cout << std::endl;
		        std::cout << "Ingrese la solucion: " << std::endl;
		        std::cin.ignore();
		        std::getline(std::cin, solucion);
		        icc->agregarEjercicioCompletar(frase, solucion);
		        std::cout << "Si desea seguir agregando ejercicios ingrese 1 y 0 si no: ";
		        std::cin >> agregar;
		    }
		}
		break;
	}
	//AGREGAR EJERCICIO
	case cmd_agregarejercicio: {
		ICurso * ic2 = fabrica.getICurso();
		int tipoEj;
	    std::cout << "Ingrese 1 si quiere agregar un ejercicio de completar o 2 si quiere uno de traduccion: ";
	    std::cin >> tipoEj;
	    std::cout << std::endl;
	    if(tipoEj == 1) {
	        std::string frase;
	        std::string solucion;
	        std::cout << "Ingrese la frase para completar escribiendo --- en los espacios a completar: " << std::endl;
	        std::cin.ignore();
	        std::getline(std::cin, frase);
	        std::cout << std::endl;
	        std::cout << "Ingrese la solucion: " << std::endl;
	        std::cin.ignore();
	        std::getline(std::cin, solucion);
	        ic2->agregarEjercicioCompletar(frase, solucion);
	    } else {
	        std::string frase;
	        std::string solucion;
	        std::cout << "Ingrese la frase para traducir: " << std::endl;
	        std::cin.ignore();
	        std::getline(std::cin, frase);
	        std::cout << std::endl;
	        std::cout << "Ingrese la solucion: " << std::endl;
	        std::cin.ignore();
	        std::getline(std::cin, solucion);
	        ic2->agregarEjercicioTraducir(frase, solucion);
	    }
		break;
	}


			//CONSULTAR ESTADISTICAS
			case cmd_consultar_estadisticas: {
				ICurso * ic = fabrica.getICurso();
				std::cout << "Ingrese 1 si quiere consultar un estudiante, 2 si quiere consultar un profesor o 3 si quiere consultar un curso: ";
				int tipoCons;
				std::cin >> tipoCons;
				std::cout << std::endl;
				if(tipoCons == 1) {
					std::cout << "A CONTINUACION SE LISTARAN LOS NICKNAMES DE LOS ESTUDIANTES:" << std::endl;
					std::set<std::string> estudiantes = ic->obtenerEstudiantes();
					for (std::set<std::string>::iterator it = estudiantes.begin(); it != estudiantes.end(); ++it){
	        				std::cout << (*it) << std::endl;
	    			}
	    			std::cout << "INGRESE EL NICKNAME DEL ESTUDIANTE QUE DESEA CONSULTAR: ";
	    			std::string nickname;
	    			std::cin >> nickname;
	    			std::cout << std::endl;
	    			ic->seleccionarEstudiante(nickname);
	    			std::vector<DTAvanceEstudiante> avance = ic->obtenerAvanceEstudiante();
	    			for (std::vector<DTAvanceEstudiante>::iterator it = avance.begin(); it != avance.end(); ++it){
	        				std::cout << "CURSO: " << (*it).getNombreCurso() << std::endl;
	        				std::cout << "DESCRIPCION: " << (*it).getDescripcionCurso() << std::endl;
	        				std::cout << "DIFICULTAD: " << (*it).getDificultadCurso() << std::endl;
	    					std::cout << "AVANCE: " << (*it).getAvanceEstudiante() << std::endl;
	    			}
				} else if(tipoCons == 2) {
					std::cout << "A CONTINUACION SE LISTARAN LOS NICKNAMES DE LOS PROFESORES:" << std::endl;
					std::set<std::string> profesores = ic->obtenerNicksProfes();
					for (std::set<std::string>::iterator it = profesores.begin(); it != profesores.end(); ++it){
	        				std::cout << (*it) << std::endl;
	    			}
	    			std::cout << "INGRESE EL NICKNAME DEL PROFESOR QUE DESEA CONSULTAR: ";
	    			std::string nickname;
	    			std::cin >> nickname;
	    			std::cout << std::endl;
	    			ic->seleccionarProfesor(nickname);
	    			std::vector<DTAvanceCurso> avance = ic->obtenerAvanceProfesor();
	    			for (std::vector<DTAvanceCurso>::iterator it = avance.begin(); it != avance.end(); ++it){
	        				std::cout << "CURSO: " << (*it).getNombreCurso() << std::endl;
	        				std::cout << "DESCRIPCION: " << (*it).getDescripcionCurso() << std::endl;
	        				std::cout << "DIFICULTAD: " << (*it).getDificultadCurso() << std::endl;
	    					std::cout << "AVANCE: " << (*it).getAvanceCurso() << std::endl;
	    			}
				} else {
					std::cout << "A CONTINUACION SE LISTARAN LOS NOMBRES DE LOS CURSOS:" << std::endl;
					std::set<std::string> cursos = ic->obtenerCursos();
					for (std::set<std::string>::iterator it = cursos.begin(); it != cursos.end(); ++it){
	        				std::cout << (*it) << std::endl;
	    			}
	    			std::cout << "INGRESE EL NOMBRE DEL CURSO QUE DESEA CONSULTAR: ";
	    			std::string nomCurso;
	    			std::cin >> nomCurso;
	    			std::cout << std::endl;
	    			ic->seleccionarCurso(nomCurso);
	    			DTAvanceCurso avance = ic->obtenerAvanceCurso();
    				std::cout << "CURSO: " << avance.getNombreCurso() << std::endl;
    				std::cout << "DESCRIPCION: " << avance.getDescripcionCurso() << std::endl;
    				std::cout << "DIFICULTAD: " << avance.getDificultadCurso() << std::endl;
					std::cout << "AVANCE: " << avance.getAvanceCurso() << std::endl;
				}
				std::cout << std::endl;
				break;
			}




			//SUSCRIBIRSE A NOTIFICACIONES
			case cmd_suscribirse_a_notificaciones: {
				IUsuario * iu = fabrica.getIUsuario();

				std::string nick;
				std::cout << "Ingrese su nickname: ";
				std::cin >> nick;
				std::cout << std::endl;

				bool nickValido = !iu->NicknameDisponible(nick);
				bool quit = false;
				if(!nickValido) {
					while(!nickValido && !quit){
						std::cout << "El nickname no es valido, ingrese uno nuevo, si desea salir ingrese 0: ";
						std::cin >> nick;
						std::cout << std::endl;
						if(nick != "0")
							nickValido = !iu->NicknameDisponible(nick);
						else 
							quit = true;
					}
				}
				if(!quit) {
					std::set<std::string> set_idiomas = iu->listarIdiomas(nick);
					int i = 1;
					for (std::set<std::string>::iterator it = set_idiomas.begin(); it != set_idiomas.end(); ++it){
        				std::cout << i << ". " << (*it) << std::endl;
        				i++;
    				}
    				bool agregar = true;
    				int contador = 1;
    				std::string idiomaSus;
    				while(agregar || contador < i-1) {
    					std::cout << "Ingrese el nombre del idioma al que desea suscribirse: ";
    					std::cin >> idiomaSus;
    					iu->altaSuscripcion(idiomaSus);
    					std::cout << std::endl;
    					std::cout << "SI DESEA SEGUIR AGREGANDO SUSCRIPCIONES INGRESE 1, 0 SI NO: ";
    					std::cin >> agregar;
    					contador++;
    				} 
				}

				break;
			}


			//CONSULTA DE NOTIFICACIONES
			case cmd_consulta_de_notificaciones: {
				IUsuario * iu = fabrica.getIUsuario();

				std::string nick;
				std::cout << "Ingrese su nickname: ";
				std::cin >> nick;
				std::cout << std::endl;

				bool nickValido = !iu->NicknameDisponible(nick);
				bool quit = false;
				if(!nickValido) {
					while(!nickValido && !quit){
						std::cout << "El nickname no es valido, ingrese uno nuevo, si desea salir ingrese 0: ";
						std::cin >> nick;
						std::cout << std::endl;
						if(nick != "0")
							nickValido = !iu->NicknameDisponible(nick);
						else 
							quit = true;
					}
				}
				if(!quit) { 
					std::vector<DTNotificacion> notificaciones = iu->notificacionesRecibidas(nick);
					/*DTNotificacion dn = DTNotificacion("Español", "Historia");
					notificaciones.push_back(dn);*/
					for (auto it = notificaciones.begin(); it != notificaciones.end(); it++) {
					    std::cout << "IDIOMA: " << (*it).getnomIdioma() << ". CURSO: " << (*it).getnomCurso() << "." << std::endl;
					}
				}
				std::cout << std::endl;
				break;
			}
			case cmd_eliminar_suscripciones: {
				IUsuario * iu = fabrica.getIUsuario();

				std::string nick;
				std::cout << "Ingrese su nickname: ";
				std::cin >> nick;
				std::cout << std::endl;

				bool nickValido = !iu->NicknameDisponible(nick);
				bool quit = false;
				if(!nickValido) {
					while(!nickValido && !quit){
						std::cout << "El nickname no es valido, ingrese uno nuevo, si desea salir ingrese 0: ";
						std::cin >> nick;
						std::cout << std::endl;
						if(nick != "0")
							nickValido = !iu->NicknameDisponible(nick);
						else 
							quit = true;
					}
				}
				if(!quit) {
					std::set<std::string> suscripciones = iu->listaSuscripciones(nick);
					int i = 1;
					for (auto it = suscripciones.begin(); it != suscripciones.end(); it++) {
					    std::cout << (*it) << std::endl;
					    i++;
					}
					bool eliminar = true;
    				int contador = 1;
    				std::string susElim;
    				while(eliminar || contador < i-1) {
    					std::cout << "Ingrese el nombre del idioma al que desea desuscribirse: ";
    					std::cin >> susElim;
    					iu->eliminarSuscripcion(susElim);
    					std::cout << std::endl;
    					std::cout << "SI DESEA SEGUIR ELIMINANDO SUSCRIPCIONES INGRESE 1, 0 SI NO: ";
    					std::cin >> eliminar;
    					contador++;
    				} 
				}
				break;	
			}
			case no_reconocido: {
				std::cout << "Comando no reconocido." << std::endl;
				std::cout << std::endl;
				break;
			}
		}
	}
	

	return 0;
}