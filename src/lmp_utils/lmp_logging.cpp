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

bool LMP_Logging::create_logging_lvm_dir(){
    std::string dirname = this->LMP_LOG_DIR + "/" + this->LMP_LVM_DIR;
    
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
    actual_log_file = dirname + "/" + log_header + this->LMP_FILE + this->LMP_LOG_FILE_EXT;

    // -- Abrir fichero
    f = fopen(actual_log_file.c_str(),"w");

    // -- Retornar puntero a fichero
    return f;
}

std::ofstream LMP_Logging::create_logging_file_stream_in_dir(std::string dirname, std::string log_header){
    // -- Definir nombre de fichero destino
    actual_log_file = dirname + "/" + log_header + this->LMP_FILE + this->LMP_LOG_FILE_EXT;

    // -- Abrir el archivo con std::ofstream
    std::ofstream ofs(actual_log_file,std::ios::out | std::ios::trunc);

    return ofs;
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

    if(get_total_error_syntax() > 0)
        tasker.task_logging_error_syntax(actual_log_file);
    if(get_total_error_semantic() > 0)
        tasker.task_logging_error_semantic(actual_log_file);

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

    tasker.task_logging_ast(actual_log_file);

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
        this->LMP_LOGGING_IR_FILE = this->create_logging_file_stream_in_dir(dirlog,this->LMP_LOG_FILE_IR_HEADER);
    }

    // -- Comprobar creacion de fichero
    if(!this->LMP_LOGGING_IR_FILE.is_open())
        log_result = false;

    tasker.task_logging_ir(actual_log_file);

    // -- Retornar resultado
    return log_result;
}

bool LMP_Logging::init_log_lvm(){
    // -- Definir resultado de operacion
    bool log_result = true;

    // -- Intentar crear fichero de log de ast
    log_result = this->create_logging_lvm_dir();

    // -- Crear fichero de logging de errores
    if(log_result){
        std::string dirlog = this->LMP_LOG_DIR + "/" + this->LMP_LVM_DIR;
        this->LMP_LOGGING_LVM_FILE = this->create_logging_file_stream_in_dir(dirlog,this->LMP_LOG_FILE_LVM_HEADER);
    }

    // -- Comprobar creacion de fichero
    if(!this->LMP_LOGGING_LVM_FILE.is_open())
        log_result = false;

    tasker.task_logging_lvm(actual_log_file);

    // -- Retornar resultado
    return log_result;
}

bool LMP_Logging::init_log_lvm_trace(){
    // -- Definir resultado de operacion
    bool log_result = true;

    // -- Intentar crear fichero de log de ast
    log_result = this->create_logging_lvm_dir();

    // -- Crear fichero de logging de errores
    if(log_result){
        std::string dirlog = this->LMP_LOG_DIR + "/" + this->LMP_LVM_DIR;
        this->LMP_LOGGING_LVM_TRACE_FILE = this->create_logging_file_stream_in_dir(dirlog,this->LMP_LOG_FILE_LVM_TRACE_HEADER);
    }

    // -- Comprobar creacion de fichero
    if(!this->LMP_LOGGING_LVM_TRACE_FILE.is_open())
        log_result = false;

    tasker.task_logging_lvm_trace(actual_log_file);

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
        tasker.task_nop();
        std::cout << "Error. Logging de errores no disponible." << std::endl;
        return false;
    }

    // -- Realizar logging de errores
    if(get_total_error_syntax() > 0){
        report_list_error_syntax(this->LMP_LOGGING_ERRORS_FILE);
        tasker.task_ok();
        return true;
    }

    if(get_total_error_semantic() > 0){
        report_list_error_semantic(this->LMP_LOGGING_ERRORS_FILE);
        tasker.task_ok();
        return true;
    }

    return false;
}

bool LMP_Logging::make_log_ast(){
    // -- Inicializar logging de ast
    if(!this->init_log_ast()){
        tasker.task_nop();
        std::cout << "Error. Logging de AST no disponible." << std::endl;
        return false;
    }

    // -- Realizar logging de AST
    print_AST(AST_program,this->LMP_LOGGING_AST_FILE);
    tasker.task_ok();

    return true;
}

bool LMP_Logging::make_log_ir(){
    // -- Inicializar logging de ast
    if(!this->init_log_ir()){
        tasker.task_nop();
        std::cout << "Error. Logging de IR no disponible." << std::endl;
        return false;
    }

    // -- Realizar logging de IR
    IR_Printer::get_instance().print_tables(this->LMP_LOGGING_IR_FILE);
    IR_Printer::get_instance().print_ir_instructions(this->LMP_LOGGING_IR_FILE);
    tasker.task_ok();

    return false;
}

bool LMP_Logging::make_log_lvm(){
    // -- Inicializar logging de lvm
    if(!this->init_log_lvm()){
        tasker.task_nop();
        std::cout << "Error. Logging de LVM no disponible." << std::endl;
        return false;
    }

    // -- Realizar logging de lvm
    LVM::get_instance().print_segment_table(this->LMP_LOGGING_LVM_FILE);
    LVM::get_instance().print_memory(this->LMP_LOGGING_LVM_FILE);
    tasker.task_ok();

    return false;
}

bool LMP_Logging::make_log_lvm_trace(){
    // -- Inicializar logging de lvm
    if(!this->init_log_lvm_trace()){
        tasker.task_nop();
        std::cout << "Error. Logging de traza de ejecucion de LVM no disponible." << std::endl;
        return false;
    }

    // -- Realizar logging de lvm
    LVM::get_instance().print_lvm_trace(this->LMP_LOGGING_LVM_TRACE_FILE);
    tasker.task_ok();

    return false;
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [LOGGING] -----

LMP_Logging& LMP_Logging::get_instance(){
    static LMP_Logging instance;
    return instance;
}

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
    if(this->LMP_LOGGING_IR_FILE.is_open()){
        this->LMP_LOGGING_IR_FILE.close();
    }

    // -- Intentar cerrar fichero de log de LVM
    if(this->LMP_LOGGING_LVM_FILE.is_open()){
        this->LMP_LOGGING_LVM_FILE.close();
    }

    // -- Intentar cerrar fichero de log de LVM (traza)
    if(this->LMP_LOGGING_LVM_TRACE_FILE.is_open()){
        this->LMP_LOGGING_LVM_TRACE_FILE.close();
    }
}

void LMP_Logging::log_analysis(std::string lmp_file){
    // -- Inicializar nombre de fichero
    this->parse_lmp_file(lmp_file);

    // -- Crear directorio de logging principal
    if(!this->create_logging_dir()){
        std::cout << "Error. No se puede realizar logging de analisis sobre fichero: " << this->LMP_FILE << "." << std::endl;
        return;
    }

    // -- Intentar realizar logging de errores
    if(!this->make_log_errors()){
        // -- Realizar logging de AST
        this->make_log_ast();
    }
}

void LMP_Logging::log_ir(){
    // -- Crear directorio de logging principal
    if(!this->create_logging_dir()){
        std::cout << "Error. No se puede realizar logging de codigo intermedio sobre fichero: " << this->LMP_FILE << "." << std::endl;
        return;
    }

    // -- Intentar realizar logging de errores
    if(!this->make_log_errors()){
        // -- Realizar logging de IR
        this->make_log_ir();
    }
}

void LMP_Logging::log_lvm(){
    // -- Crear directorio de logging principal
    if(!this->create_logging_dir()){
        std::cout << "Error. No se puede realizar logging de maquina virtual sobre fichero: " << this->LMP_FILE << "." << std::endl;
        return;
    }

    // -- Intentar realizar logging de errores
    if(!this->make_log_errors()){
        // -- Realizar logging de LVM
        this->make_log_lvm();
    }   
}

void LMP_Logging::log_lvm_trace(){
    // -- Crear directorio de logging principal
    if(!this->create_logging_dir()){
        std::cout << "Error. No se puede realizar logging de maquina virtual sobre fichero: " << this->LMP_FILE << "." << std::endl;
        return;
    }

    // -- Intentar realizar logging de errores
    if(!this->make_log_errors()){
        // -- Realizar logging de LVM
        this->make_log_lvm_trace();
    } 
}