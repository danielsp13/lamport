/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file lmp_logging.cpp
 * @author Daniel Perez Ruiz
 * @brief Gestor de registro de eventos de lamport
 */

#include "lmp_utils/lmp_logging.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [LOGGING] -----

void LMP_Logging::parse_lmp_file(std::string lmp_file){
    // -- Eliminacion de barras
    size_t position = lmp_file.find_last_of('/');

    if (position != std::string::npos) {
        this->LMP_FILE = lmp_file.substr(position + 1);
    } 
    else {
        this->LMP_FILE = lmp_file;
    }
}

bool LMP_Logging::create_dir(std::string dirname){
    // -- Definir permisos de directorio
    mode_t mode_dir = 0733; // rwx-wx-wx

    // -- Intentar crear el directorio
    int result = mkdir(dirname.c_str(),mode_dir);

    // -- Comprobar resultado
    if(result != 0){
        return false;
    }

    // -- Retornar resultado valido
    return true;
}

bool LMP_Logging::check_dir(std::string dirname){
    // -- Obtener estructura para obtener informacion de directorio
    struct stat dir_info;

    // -- Obtener informacion
    int result = stat(dirname.c_str(),&dir_info);

    // -- Verificar
    if(result != 0){
        return false;
    }

    // -- Comprobar ademas si es directorio
    if(!S_ISDIR(dir_info.st_mode)){
        return false;
    }

    // -- Retornar exito
    return true;
}

bool LMP_Logging::create_logging_dir(){
    // -- Comprobar existencia de directorio
    if(!this->check_dir(this->LMP_LOG_DIR)){
        // -- Si no existe, crear
        return this->create_dir(this->LMP_LOG_DIR);
    }

    // -- Retornar true porque existe directorio
    return true;
}

bool LMP_Logging::create_logging_errors_dir(){
    std::string dirname = this->LMP_LOG_DIR + "/" + this->LMP_ERRORS_DIR;
    
    // -- Comprobar existencia de directorio
    if(!this->check_dir(dirname)){
        // -- Si no existe, crear
        return this->create_dir(dirname);
    }

    // -- Retornar true porque existe directorio
    return true;
}

bool LMP_Logging::create_logging_ast_dir(){
    std::string dirname = this->LMP_LOG_DIR + "/" + this->LMP_AST_DIR;
    
    // -- Comprobar existencia de directorio
    if(!this->check_dir(dirname)){
        // -- Si no existe, crear
        return this->create_dir(dirname);
    }

    // -- Retornar true porque existe directorio
    return true;
}

bool LMP_Logging::create_logging_ir_dir(){
    std::string dirname = this->LMP_LOG_DIR + "/" + this->LMP_IR_DIR;
    
    // -- Comprobar existencia de directorio
    if(!this->check_dir(dirname)){
        // -- Si no existe, crear
        return this->create_dir(dirname);
    }

    // -- Retornar true porque existe directorio
    return true;
}

FILE * LMP_Logging::create_logging_file_in_dir(std::string dirname, std::string log_header){
    // -- Definir fichero
    FILE * f = nullptr;
    // -- Definir nombre de fichero destino
    std::string filename = dirname + "/" + log_header + this->LMP_FILE + this->LMP_LOG_FILE_EXT;

    // -- Abrir fichero
    f = fopen(filename.c_str(),"w");

    // -- Retornar puntero a fichero
    return f;
}

bool LMP_Logging::init_log_errors(){
    // -- Definir resultado de operacion
    bool log_result = true;

    // -- Intentar crear directorio de log de ast
    log_result = this->create_logging_errors_dir();

    // -- Crear fichero de logging de errores
    if(log_result){
        std::string dirlog = this->LMP_LOG_DIR + "/" + this->LMP_ERRORS_DIR;
        this->LMP_LOGGING_ERRORS_FILE = this->create_logging_file_in_dir(dirlog,this->LMP_LOG_FILE_ERRORS_HEADER);
    }

    // -- Comprobar creacion de fichero
    if(this->LMP_LOGGING_ERRORS_FILE == nullptr)
        log_result = false;

    // -- Retornar resultado
    return log_result;
}

bool LMP_Logging::init_log_ast(){
    // -- Definir resultado de operacion
    bool log_result = true;

    // -- Intentar crear directorio de log de ast
    log_result = this->create_logging_ast_dir();

    // -- Crear fichero de logging de errores
    if(log_result){
        std::string dirlog = this->LMP_LOG_DIR + "/" + this->LMP_AST_DIR;
        this->LMP_LOGGING_AST_FILE = this->create_logging_file_in_dir(dirlog,this->LMP_LOG_FILE_AST_HEADER);
    }

    // -- Comprobar creacion de fichero
    if(this->LMP_LOGGING_AST_FILE == nullptr)
        log_result = false;


    // -- Retornar resultado
    return log_result;
}

bool LMP_Logging::init_log_ir(){
    // -- Definir resultado de operacion
    bool log_result = true;

    // -- Intentar crear fichero de log de ast
    log_result = this->create_logging_ir_dir();

    // -- Crear fichero de logging de errores
    if(log_result){
        std::string dirlog = this->LMP_LOG_DIR + "/" + this->LMP_IR_DIR;
        this->LMP_LOGGING_IR_FILE = this->create_logging_file_in_dir(dirlog,this->LMP_LOG_FILE_IR_HEADER);
    }

    // -- Comprobar creacion de fichero
    if(this->LMP_LOGGING_IR_FILE == nullptr)
        log_result = false;

    // -- Retornar resultado
    return log_result;
}

bool LMP_Logging::make_log_errors(){
    // -- Comprobar que hay errores
    bool exists_errors = get_total_error_syntax() > 0 || get_total_error_semantic() > 0;

    if(!exists_errors)
        return false;

    // -- Inicializar logging de errores
    if(!this->init_log_errors()){
        std::cout << "Error. Logging de errores no disponible." << std::endl;
        return false;
    }

    // -- Realizar logging de errores
    if(get_total_error_syntax() > 0){
        report_list_error_syntax(this->LMP_LOGGING_ERRORS_FILE);
        return true;
    }

    if(get_total_error_semantic() > 0){
        report_list_error_semantic(this->LMP_LOGGING_ERRORS_FILE);
        return true;
    }

    return false;
}

bool LMP_Logging::make_log_ast(){
    // -- Inicializar logging de ast
    if(!this->init_log_ast()){
        std::cout << "Error. Logging de AST no disponible." << std::endl;
        return false;
    }

    // -- Realizar logging de AST
    print_AST(AST_program,this->LMP_LOGGING_AST_FILE);

    return true;
}

bool LMP_Logging::make_log_ir(){
    // -- Inicializar logging de ast
    if(!this->init_log_ir()){
        std::cout << "Error. Logging de IR no disponible." << std::endl;
        return false;
    }

    return false;
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [LOGGING] -----

LMP_Logging::~LMP_Logging(){
    // -- Intentar cerrar fichero de log de errores
    if(this->LMP_LOGGING_ERRORS_FILE != nullptr){
        fclose(this->LMP_LOGGING_ERRORS_FILE);
        this->LMP_LOGGING_ERRORS_FILE = nullptr;
    }

    // -- Intentar cerrar fichero de log de AST
    if(this->LMP_LOGGING_AST_FILE != nullptr){
        fclose(this->LMP_LOGGING_AST_FILE);
        this->LMP_LOGGING_AST_FILE = nullptr;
    }

    // -- Intentar cerrar fichero de log de IR
    if(this->LMP_LOGGING_IR_FILE != nullptr){
        fclose(this->LMP_LOGGING_IR_FILE);
        this->LMP_LOGGING_IR_FILE = nullptr;
    }
}

void LMP_Logging::log(std::string lmp_file){
    // -- Inicializar nombre de fichero
    this->parse_lmp_file(lmp_file);

    // -- Crear directorio de logging principal
    if(!this->create_logging_dir()){
        std::cout << "Error. No se puede realizar logging de interpretacion sobre fichero: " << this->LMP_FILE << "." << std::endl;
        return;
    }

    // -- Intentar realizar logging de errores
    if(!this->make_log_errors()){
        // -- Realizar logging de AST
        this->make_log_ast();

        // -- Realizar logging de IR
        //this->make_log_ir();
    }
}