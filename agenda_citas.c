#include <stdio.h>
#include <string.h>
#include <windows.h>

void introduccion();
int agendarCita(char *nombre, char *cedula, char *medicos);
void medicos(char *medicos);
void cedula(char *cedula, char *nombre);
void verificar();
void cancelar(char *nombre, char *cedula, char *medicos);

int main(){
    int seleccion;
    SetConsoleOutputCP(65001);
    introduccion();
    do{
        verificar();
        printf("Desea registrar alguna cita extra o cancelar alguna otra\n");
        printf("Marque 1 si desea ingresar nuevamente y 0 para salir\n");
        printf("*************************************************\n");
        scanf("%i", &seleccion);
        getchar();
    }while(seleccion==1);

    return 0;
}
void introduccion(){
    printf("Bienvenido al sistema de agendacion de citas en la clinica NUEVO AMANECER en sucursal Loja\n");
    printf("****************************************************\n");
    printf("Puede agendar su cita de lunes a viernes en un horario de 08h00 a 17h00\n");
    printf("****************************************************\n");
    printf("En caso de ser una emergencia venir directamente al hospital\n");
    printf("****************************************************\n");
    printf("\n");
    printf("Desea agendar una cita o revisar sus citas pendientes \n");
    printf("________________________________________________________________________________\n");
}

void verificar(){
    int seleccion;
    char cd[11];
    char nm[50];
    char med[150];
    do{
        printf("Marque 1 si desea registrar una cita y 2 si desea cancelar una cita\n");
        printf("*************************************************\n");
        scanf("%i", &seleccion);
        getchar();
        if(seleccion==1){
            cedula(cd, nm);
            medicos(med);
            agendarCita(nm, cd, med);
        }else if(seleccion==2){
            cancelar(nm, cd, med);
        }else{
            printf("Servicio no disponible, ingrese nuevamente\n");
        }
    }while(seleccion<=0 || seleccion>2);
}

void cancelar(char *nombre, char *cedula, char *medicos) {
    char ced[11];
    
    do {
        printf("Ingrese su cedula para verificar datos registrados\n"); 
        
        scanf("%s", ced); 
        getchar(); 

        if (strlen(ced) == 10) {
            printf("\n--- Verificando ---\n");
            printf("\n=========================================\n");
        } else {
            printf("\nError: la cedula debe tener exactamente 10 digitos\n");
        }
    } while (strlen(ced) != 10);

    if (strcmp(ced, cedula) == 1) {
        printf("\n=========================================\n");
        printf("         CITA PENDIENTE \n");
        printf("=========================================\n");
        printf("Paciente: %s\n", nombre);  
        printf("Cédula:   %s\n", cedula);  
        printf("Médico:   %s\n", medicos);
        printf("=========================================\n");
    } else {
        printf("No tiene datos previamente registrados o la cédula no coincide\n");
    }
}

void cedula(char *cedula, char *nombre) {

    printf("Ingrese el nombre del paciente: ");
    fgets(nombre, 50, stdin);
    nombre[strcspn(nombre, "\n")] = 0;

    do {
        printf("Ingrese la cedula (10 numeros): ");
        scanf("%s", cedula); 
        getchar(); 

        if (strlen(cedula) == 10) {
            printf("\n--- Datos Registrados ---\n");
            printf("Nombre: %s\n", nombre);
            printf("Cedula: %s\n", cedula);
        } else {
            printf("\nError: la cedula debe tener exactamente 10 digitos\n");
        }
    } while (strlen(cedula) != 10);
}

void medicos(char *medicos){
    int seleccion, med;
    printf("Los medicos disponibles son: \n");
    printf("______________________________________\n");
    printf("*****LABORATORIO CLINICO*****\n");
    printf("Lcda. Maria Dolores Soto Cueva \n");
    printf("*****MEDICINA GENERAL*****\n");
    printf("Doc. Liliana Emperatriz Jimbo Gonzales \nDoc. Jhon Alexander Aguirre Suarez\n");
    printf("*****ODONTOLOGIA*****\n");
    printf("Doc. Emily Jassiel Salas paz \n");
    printf("*****PSICOLOGIA CLINICA*****\n");
    printf("Doc. Maria de Angeles Picoita Patiño \n");
    printf("______________________________________\n");
    do{
        printf("Ingrese el numero 1 para acceder a Laboratorio Clinico\n");
        printf("______________________________________\n");
        printf("Ingrese el numero 2 para acceder a Medicina Gneral\n");
        printf("______________________________________\n");
        printf("Ingrese el numero 3 para acceder a Odontologia\n");
        printf("______________________________________\n");
        printf("Ingrese el numero 4 para acceder a Psicologia Clinica\n");
        printf("______________________________________\n");
        scanf("%i", &seleccion);
        getchar();
        switch (seleccion){
            case 1 : strcpy(medicos, "Lcda. Maria Dolores Soto Cueva");
            printf("Ha ingresado a laboratorio Clinico, su medico encargado sera la %s\n", medicos);
            break;
            case 2 :printf("Ha ingresado a Medicina General, Seleccione su medico por favor\n");
            do{
                printf("Ingrese 1 si gusta iniciar con la Doc. Liliana Emperatriz Jimbo Gonzales \ny 2 si solicita al Doc. Jhon Alexander Aguirre Suarez\n");
                scanf("%i", &med);
                getchar();
                if(med==1){
                    strcpy(medicos, "Doc. Liliana Emperatriz Jimbo Gonzales");
                    printf("Usted ha solicitado una cita con la %s\n", medicos);
                }else if(med==2){
                    strcpy(medicos, "Doc. Jhon Alexander Aguirre Suarez");
                    printf("Usted ha solicitado una cita con el %s\n", medicos);
                }else{
                    printf("Medico no disponible, ingrese uno nuevamente\n");
                }
            }while(med<0 || med>2);
            break;
            case 3 : strcpy(medicos, "Doc. Emily Jassiel Salas Paz");
            printf("Ha ingresado a Odontologia, su medico encargado sera la %s\n", medicos);
            break;
            case 4 :strcpy(medicos, "Doc. Pilar Valentina Naranjo Quizhpe");
            printf("Ha ingresado a Psicologia Clinica, su medico encargado sera la %s\n", medicos);
            break;
            default:printf("Sistema no permitido, sleccione un servicio disponible\n");
        }
    }while(seleccion<0 && seleccion>5);
    printf("Enfermeras encargadas de turno:\n");
    printf("*************************************************\n");
    printf("Lcda. Rosa Elida Hidalgo Alberca \nLcda. Laura Beatriz Benavidez Gonzales\n");
}

int agendarCita(char *nombre, char *cedula, char *medicos) {
    int dia, mes, anio;
    int hora, minuto;
    char cd[11];
    char nm[50];
    char *med;
    printf("\n--- AGENDAR CITA MEDICA ---\n");

     do {
        printf("Ingrese la fecha (DD MM AAAA): ");
        scanf("%i", &dia);
        scanf("%i", &mes);
        scanf("%i", &anio);
        if (dia>31 || dia<1) {
            printf("Fecha no valida. Intente nuevamente.\n");
        }else if(mes<1 || mes>12){
            printf("Fecha no valida. Intente nuevamente.\n");
        }else if(anio!=2026){
            printf("Fecha no valida. Intente nuevamente.\n");
        }
    } while (dia>31 || dia<0 || mes<1 || mes>12 || anio!=2026);

    do {
        printf("Ingrese la hora (HH MM): ");
        scanf("%i", &hora);
        scanf("%i", &minuto);
        if (hora<8 || hora>17) {
            printf("- Horario: 08:00 a 17:00\n"); 
        }else if(minuto!=00 && minuto!=30){
            printf("- Solo minutos 00 o 30\n");
        }
    } while (hora<8 || hora>17 || minuto!=00 && minuto!=30);
    
    printf("\n=========================================\n");
    printf("        CITA AGENDADA CORRECTAMENTE\n");
    printf("=========================================\n");
    printf("Paciente: %s\n", nombre);
    printf("Cédula:   %s\n", cedula);
    printf("Médico:   %s\n", medicos);
    printf("Fecha:    %02d/%02d/%04d\n", dia, mes, anio);
    printf("Hora:     %02d:%02d\n", hora, minuto);
    printf("=========================================\n");
}

