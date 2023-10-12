/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file table.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion de funciones para generacion
 * de codigo intermedio  (Tabla de IR Lineal)
 */

#include "IR/table.hpp"

const std::string TABLE_SEPARATOR = "================================================================================";
const unsigned int gap_literals = 16;
const unsigned int gap_variables = 16;
const unsigned int gap_labels = 35;

// ===============================================================

// ----- IMPLEMENTACION DE METODOS DE CLASE TABLA IR (GESTION DE INSTANCIA) -----

IR_Tables& IR_Tables::get_instance(){
    static IR_Tables instance;
    return instance;
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS DE CLASE TABLA IR (INSERCION DE ENTRADAS) -----

int IR_Tables::add_entry_literal(int l_int){
    // -- Comprobar si el literal ha sido insertado con anterioridad
    int possible_index_from_literal = this->get_index_from_literal_value(l_int);
    // -- En caso afirmativo, retornar direccion de literal
    if(possible_index_from_literal != -1)
        return possible_index_from_literal;

    // -- Crear literal
    auto lit = std::make_unique<IR_Table_Entry_Literal>();
    // -- Asignar valor literal
    lit->entry_literal_integer(l_int);

    // -- Crear entrada para literal e insertar
    table_literals.push_back(std::move(lit));

    // -- Retornar direccion de almacenamiento de literal
    return table_literals.size()-1;
}

int IR_Tables::add_entry_literal(float l_real){
    // -- Comprobar si el literal ha sido insertado con anterioridad
    int possible_index_from_literal = this->get_index_from_literal_value(l_real);
    // -- En caso afirmativo, retornar direccion de literal
    if(possible_index_from_literal != -1)
        return possible_index_from_literal;

    // -- Crear literal
    auto lit = std::make_unique<IR_Table_Entry_Literal>();
    // -- Asignar valor literal
    lit->entry_literal_real(l_real);

    // -- Crear entrada para literal e insertar
    table_literals.push_back(std::move(lit));

    // -- Retornar direccion de almacenamiento de literal
    return table_literals.size()-1;
}

int IR_Tables::add_entry_literal(char l_char){
    // -- Comprobar si el literal ha sido insertado con anterioridad
    int possible_index_from_literal = this->get_index_from_literal_value(l_char);
    // -- En caso afirmativo, retornar direccion de literal
    if(possible_index_from_literal != -1)
        return possible_index_from_literal;
    
    // -- Crear literal
    auto lit = std::make_unique<IR_Table_Entry_Literal>();
    // -- Asignar valor literal
    lit->entry_literal_char(l_char);

    // -- Crear entrada para literal e insertar
    table_literals.push_back(std::move(lit));

    // -- Retornar direccion de almacenamiento de literal
    return table_literals.size()-1;
}

int IR_Tables::add_entry_literal(char *l_str){
    // -- Comprobar si el literal ha sido insertado con anterioridad
    int possible_index_from_literal = this->get_index_from_literal_value(l_str);
    // -- En caso afirmativo, retornar direccion de literal
    if(possible_index_from_literal != -1)
        return possible_index_from_literal;

    // -- Crear literal
    auto lit = std::make_unique<IR_Table_Entry_Literal>();
    // -- Asignar valor literal
    lit->entry_literal_string(l_str);

    // -- Crear entrada para literal e insertar
    table_literals.push_back(std::move(lit));

    // -- Retornar direccion de almacenamiento de literal
    return table_literals.size()-1;
}

int IR_Tables::add_entry_literal(std::string l_str){
    // -- Comprobar si el literal ha sido insertado con anterioridad
    int possible_index_from_literal = this->get_index_from_literal_value(l_str);
    // -- En caso afirmativo, retornar direccion de literal
    if(possible_index_from_literal != -1)
        return possible_index_from_literal;

    // -- Crear literal
    auto lit = std::make_unique<IR_Table_Entry_Literal>();
    // -- Asignar valor literal
    lit->entry_literal_string(l_str.c_str());

    // -- Crear entrada para literal e insertar
    table_literals.push_back(std::move(lit));

    // -- Retornar direccion de almacenamiento de literal
    return table_literals.size()-1;
}

int IR_Tables::add_entry_literal(bool l_bool){
    // -- Comprobar si el literal ha sido insertado con anterioridad
    int possible_index_from_literal = this->get_index_from_literal_value(l_bool);
    // -- En caso afirmativo, retornar direccion de literal
    if(possible_index_from_literal != -1)
        return possible_index_from_literal;

    // -- Crear literal
    auto lit = std::make_unique<IR_Table_Entry_Literal>();
    // -- Asignar valor literal
    lit->entry_literal_bool(l_bool);

    // -- Crear entrada para literal e insertar
    table_literals.push_back(std::move(lit));

    // -- Retornar direccion de almacenamiento de literal
    return table_literals.size()-1;
}

int IR_Tables::add_entry_variable(IR_variable_t kind, std::string var_name, IR_variable_type_t type){
    // -- Crear entrada para variable e insertar
    table_variables.push_back(std::make_unique<IR_Table_Entry_Variable>(kind,var_name.c_str(),type));

    // -- Retornar direccion de almacenamiento de literal
    return table_variables.size()-1;
}

int IR_Tables::add_entry_variable(IR_variable_t kind, std::string var_name, IR_variable_type_t arr_type, size_t arr_size){
    // -- Crear entrada para variable e insertar
    table_variables.push_back(std::make_unique<IR_Table_Entry_Variable>(kind,var_name.c_str(),arr_type,arr_size));

    // -- Retornar direccion de almacenamiento de literal
    return table_variables.size()-1;
}

int IR_Tables::add_entry_label(std::string label_id, int addr){
    // -- Crear entrada para etiqueta e insertar
    table_labels.push_back(std::make_unique<IR_Table_Entry_Label>(label_id,addr));

    // -- Retornar direccion de almacenamiento de literal
    return table_labels.size()-1;
}

int IR_Tables::modify_entry_label(std::string label_id, int new_addr){
    int id_label_in_table = get_index_from_label_id(label_id);

    if(id_label_in_table == -1)
        return -1;

    IR_label * lab = get_entry_label(id_label_in_table);
    lab->set_addr(new_addr);

    return id_label_in_table;
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS DE CLASE TABLA IR (OBTENCION DE ENTRADAS) -----

IR_literal * IR_Tables::get_entry_literal(int index){
    // -- Comprobar que esta dentro de rango
    if(0 > index || index >= table_literals.size()){
        return nullptr;
    }

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

int IR_Tables::get_index_from_label_id(std::string id_label){
    // -- Recorrer tabla de etiquetas
    IR_label * label = nullptr;

    for(int i=0; i<table_labels.size(); i++){
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
        if(entry->get_kind_variable() != IR_VAR_GLOBAL)
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

bool IR_Tables::check_if_variable_is_array_using_index(int index){
    return table_variables[index]->get_variable()->is_array();
}

void IR_Tables::print_literals_table(std::ostream& os){
    os << TABLE_SEPARATOR << std::endl;
    os << std::left << "TABLA DE LITERALES IR" << std::endl;
    os << TABLE_SEPARATOR << std::endl;
    os << std::left << std::setw(gap_literals) << "Direccion" << std::setw(gap_literals) << "Tipo" << std::setw(gap_literals) << "Valor" << std::endl;
    os << TABLE_SEPARATOR << std::endl;

    // -- Recorrer tabla de literales y obtener literal
    IR_literal * lit = nullptr;
    for(unsigned i=0; i<table_literals.size(); i++){
        // -- Obtener literal
        lit = table_literals[i].get()->get_literal();

        // -- Imprimir contenido
        os << std::left << std::setw(gap_literals) << i << std::setw(gap_literals) << lit->get_kind_str() << std::setw(gap_literals) << lit->to_string() << std::endl;
    }

}

void IR_Tables::print_variables_table(std::ostream& os){
    os << TABLE_SEPARATOR << std::endl;
    os << std::left << "TABLA DE VARIABLES IR" << std::endl;
    os << TABLE_SEPARATOR << std::endl;
    os << std::left << std::setw(gap_variables) << "Direccion" << std::setw(gap_variables) << "Nombre" << std::setw(gap_variables) << "Scope" << std::setw(gap_variables) << "Tipo" << std::setw(gap_variables) << "Val. Inicial" << std::endl;
    os << TABLE_SEPARATOR << std::endl;

    // -- Recorrer tabla de literales y obtener literal
    IR_variable * var = nullptr;
    for(unsigned i=0; i<table_variables.size(); i++){
        // -- Obtener literal
        var = table_variables[i].get()->get_variable();

        // -- Imprimir contenido
        os << std::left << std::setw(gap_variables) << i << std::setw(gap_variables) << var->get_name() << std::setw(gap_variables) << var->get_kind_str() << std::setw(gap_variables) << var->get_type_str() <<  std::setw(gap_variables) << var->get_initial_value_str() << std::endl;
    }

}

void IR_Tables::print_labels_table(std::ostream& os){
    os << TABLE_SEPARATOR << std::endl;
    os << std::left << "TABLA DE ETIQUETAS IR" << std::endl;
    os << TABLE_SEPARATOR << std::endl;
    os << std::left << std::setw(gap_labels) << "Direccion" << std::setw(gap_labels) << "Etiqueta" << std::setw(gap_labels) << "Apunta a instr." << std::endl;
    os << TABLE_SEPARATOR << std::endl;

    // -- Recorrer tabla de literales y obtener literal
    IR_label * lab = nullptr;
    for(unsigned i=0; i<table_labels.size(); i++){
        // -- Obtener literal
        lab = table_labels[i].get()->get_label();

        // -- Imprimir contenido
        os << std::left << std::setw(gap_labels) << i << std::setw(gap_labels) << lab->get_label() << std::setw(gap_labels) << std::to_string(lab->get_addr()) << std::endl;
    }

}