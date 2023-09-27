/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file table.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion de funciones para generacion
 * de codigo intermedio  (Tabla de IR Lineal)
 */

#include "IR/table.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS DE CLASE TABLA IR (GESTION DE INSTANCIA) -----

IR_Tables& IR_Tables::get_instance(){
    static IR_Tables instance;
    return instance;
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS DE CLASE TABLA IR (INSERCION DE ENTRADAS) -----

void IR_Tables::add_entry_literal(int l_int){
    // -- Crear literal
    auto lit = std::make_unique<IR_Table_Entry_Literal>();
    // -- Asignar valor literal
    lit->entry_literal_integer(l_int);

    // -- Crear entrada para literal e insertar
    table_literals.push_back(std::move(lit));
}

void IR_Tables::add_entry_literal(float l_real){
    // -- Crear literal
    auto lit = std::make_unique<IR_Table_Entry_Literal>();
    // -- Asignar valor literal
    lit->entry_literal_real(l_real);

    // -- Crear entrada para literal e insertar
    table_literals.push_back(std::move(lit));
}

void IR_Tables::add_entry_literal(char l_char){
    // -- Crear literal
    auto lit = std::make_unique<IR_Table_Entry_Literal>();
    // -- Asignar valor literal
    lit->entry_literal_char(l_char);

    // -- Crear entrada para literal e insertar
    table_literals.push_back(std::move(lit));
}

void IR_Tables::add_entry_literal(char *l_str){
    // -- Crear literal
    auto lit = std::make_unique<IR_Table_Entry_Literal>();
    // -- Asignar valor literal
    lit->entry_literal_string(l_str);

    // -- Crear entrada para literal e insertar
    table_literals.push_back(std::move(lit));
}

void IR_Tables::add_entry_literal(std::string l_str){
    // -- Crear literal
    auto lit = std::make_unique<IR_Table_Entry_Literal>();
    // -- Asignar valor literal
    lit->entry_literal_string(l_str.c_str());

    // -- Crear entrada para literal e insertar
    table_literals.push_back(std::move(lit));
}

void IR_Tables::add_entry_literal(bool l_bool){
    // -- Crear literal
    auto lit = std::make_unique<IR_Table_Entry_Literal>();
    // -- Asignar valor literal
    lit->entry_literal_bool(l_bool);

    // -- Crear entrada para literal e insertar
    table_literals.push_back(std::move(lit));
}

void IR_Tables::add_entry_variable(IR_variable_t kind, std::string var_name, IR_variable_type_t type){
    // -- Crear entrada para variable e insertar
    table_variables.push_back(std::make_unique<IR_Table_Entry_Variable>(kind,var_name.c_str(),type));
}

void IR_Tables::add_entry_variable(IR_variable_t kind, std::string var_name, IR_variable_type_t arr_type, size_t arr_size){
    // -- Crear entrada para variable e insertar
    table_variables.push_back(std::make_unique<IR_Table_Entry_Variable>(kind,var_name.c_str(),arr_type,arr_size));
}

void IR_Tables::add_entry_label(int label_id){
    // -- Crear entrada para etiqueta e insertar
    table_labels.push_back(std::make_unique<IR_Table_Entry_Label>(label_id));
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS DE CLASE TABLA IR (OBTENCION DE ENTRADAS) -----

IR_literal * IR_Tables::get_entry_literal(int index){
    // -- Comprobar que esta dentro de rango
    if(0 > index || index >= table_literals.size())
        return nullptr;

    // -- Retornar entrada de tabla
    return table_literals[index].get()->get_literal();
}

IR_variable * IR_Tables::get_entry_variable(int index){
    // -- Comprobar que esta dentro de rango
    if(0 > index || index >= table_variables.size())
        return nullptr;

    // -- Retornar entrada de tabla
    return table_variables[index].get()->get_variable();
}

IR_label * IR_Tables::get_entry_label(int index){
    // -- Comprobar que esta dentro de rango
    if(0 > index || index >= table_labels.size())
        return nullptr;

    // -- Retornar entrada de tabla
    return table_labels[index].get()->get_label();
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS DE CLASE TABLA IR (OBTENCION DE INDICES) -----

int IR_Tables::get_index_from_literal_value(int l_int){
    // -- Recorrer tabla de literales
    IR_Table_Entry_Literal * entry = nullptr;
    IR_literal * lit = nullptr;
    for(int i=0; i<table_literals.size(); i++){
        // -- Recuperar entrada
        entry = table_literals[i].get();

        // -- Comprobar si es una entrada de tipo entero
        if(entry->get_kind_literal() != IR_literal_t::IR_LIT_INTEGER)
            continue;

        // -- Recuperar literal
        lit = entry->get_literal();

        // -- Comprobar si el valor coincide
        if(lit->get_literal<int>() == l_int)
            return i;
    }

    // -- Retornar fallo
    return -1;
}

int IR_Tables::get_index_from_literal_value(float l_real){
    // -- Recorrer tabla de literales
    IR_Table_Entry_Literal * entry = nullptr;
    IR_literal * lit = nullptr;
    for(int i=0; i<table_literals.size(); i++){
        // -- Recuperar entrada
        entry = table_literals[i].get();

        // -- Comprobar si es una entrada de tipo entero
        if(entry->get_kind_literal() != IR_literal_t::IR_LIT_REAL)
            continue;

        // -- Recuperar literal
        lit = entry->get_literal();

        // -- Comprobar si el valor coincide
        if(lit->get_literal<float>() == l_real)
            return i;
    }

    // -- Retornar fallo
    return -1;
}

int IR_Tables::get_index_from_literal_value(char l_char){
    // -- Recorrer tabla de literales
    IR_Table_Entry_Literal * entry = nullptr;
    IR_literal * lit = nullptr;
    for(int i=0; i<table_literals.size(); i++){
        // -- Recuperar entrada
        entry = table_literals[i].get();

        // -- Comprobar si es una entrada de tipo entero
        if(entry->get_kind_literal() != IR_literal_t::IR_LIT_CHAR)
            continue;

        // -- Recuperar literal
        lit = entry->get_literal();

        // -- Comprobar si el valor coincide
        if(lit->get_literal<char>() == l_char)
            return i;
    }

    // -- Retornar fallo
    return -1;
}

int IR_Tables::get_index_from_literal_value(std::string l_str){
    // -- Recorrer tabla de literales
    IR_Table_Entry_Literal * entry = nullptr;
    IR_literal * lit = nullptr;
    for(int i=0; i<table_literals.size(); i++){
        // -- Recuperar entrada
        entry = table_literals[i].get();

        // -- Comprobar si es una entrada de tipo entero
        if(entry->get_kind_literal() != IR_literal_t::IR_LIT_STRING)
            continue;

        // -- Recuperar literal
        lit = entry->get_literal();

        // -- Comprobar si el valor coincide
        if(lit->get_literal<std::string>() == l_str)
            return i;
    }

    // -- Retornar fallo
    return -1;
}

int IR_Tables::get_index_from_literal_value(bool l_bool){
    // -- Recorrer tabla de literales
    IR_Table_Entry_Literal * entry = nullptr;
    IR_literal * lit = nullptr;
    for(int i=0; i<table_literals.size(); i++){
        // -- Recuperar entrada
        entry = table_literals[i].get();

        // -- Comprobar si es una entrada de tipo entero
        if(entry->get_kind_literal() != IR_literal_t::IR_LIT_BOOLEAN)
            continue;

        // -- Recuperar literal
        lit = entry->get_literal();

        // -- Comprobar si el valor coincide
        if(lit->get_literal<bool>() == l_bool)
            return i;
    }

    // -- Retornar fallo
    return -1;
}

int IR_Tables::get_index_from_label_id(int id_label){
    // -- Recorrer tabla de etiquetas
    IR_label * label = nullptr;

    for(int i=0; i<table_literals.size(); i++){
        // -- Recuperar entrada
        label = table_labels[i].get()->get_label();

        // -- Comprobar si el valor coincide
        if(label->get_id() == id_label)
            return i;
    }

    // -- Retornar fallo
    return -1;
}

int IR_Tables::get_index_from_local_variable(std::string var_name){
    // -- Recorrer tabla de literales
    IR_Table_Entry_Variable * entry = nullptr;
    IR_variable * var = nullptr;
    for(int i=0; i<table_variables.size(); i++){
        // -- Recuperar entrada
        entry = table_variables[i].get();

        // -- Comprobar si es una entrada de tipo entero
        if(entry->get_kind_variable() != IR_variable_t::IR_VAR_LOCAL)
            continue;

        // -- Recuperar literal
        var = entry->get_variable();

        // -- Comprobar si el valor coincide
        if(var->get_name() == std::string(var_name))
            return i;
    }

    // -- Retornar fallo
    return -1;
}


int IR_Tables::get_index_from_global_variable(std::string var_name){
    // -- Recorrer tabla de literales
    IR_Table_Entry_Variable * entry = nullptr;
    IR_variable * var = nullptr;
    for(int i=0; i<table_variables.size(); i++){
        // -- Recuperar entrada
        entry = table_variables[i].get();

        // -- Comprobar si es una entrada de tipo entero
        if(entry->get_kind_variable() != IR_variable_t::IR_VAR_GLOBAL)
            continue;

        // -- Recuperar literal
        var = entry->get_variable();

        // -- Comprobar si el valor coincide
        if(var->get_name() == std::string(var_name))
            return i;
    }

    // -- Retornar fallo
    return -1;
}