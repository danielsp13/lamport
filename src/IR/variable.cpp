/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file variable.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion de funciones para generacion
 * de codigo intermedio  (Variables de IR Lineal)
 */

#include "IR/variable.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [IR_VARIABLE_TYPE] -----



// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [IR_VARIABLE_TYPE] -----

std::string IR_variable_type::get_type_str(){
    std::string type_str;

    auto it = IR_variable_type_t_str.find(type);
    if(it != IR_variable_type_t_str.end())
        type_str = it->second;

    if(is_array()){
        it = IR_variable_type_t_str.find(array_subtype);
        if(it != IR_variable_type_t_str.end())
            type_str += " [" + it->second + "]";
    }

    // Retornar tipo
    return type_str;
};

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [IR_VARIABLE_VALUE] -----

bool IR_variable_value::check_array_bounds(int index) const{
    return 0 <= index && index < array_value.size();
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [IR_VARIABLE_VALUE] -----

template <typename T>
void IR_variable_value::set_value(T v){
    value = v;
}

template <typename T>
bool IR_variable_value::set_value_in_array(int index, T v){
    if(!check_array_bounds(index))
        return false;

    array_value[index] = v;
    return true;
}

template <typename T>
T IR_variable_value::get_value() const{
    return std::get<T>(value);
}

template <typename T>
T IR_variable_value::get_array_value(int index) const{
    if(check_array_bounds(index))
        return std::get<T>(array_value[index]);
}

std::string IR_variable_value::get_value_str() const {
    return std::visit([](auto&& arg) -> std::string {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, std::string>) {
            return "\"" + arg + "\"";
        } else if constexpr (std::is_same_v<T, char>) {
            if(arg == '\0')
                return std::string("\'\'");
            return "\'" + std::string(1, arg) + "\'"; // Convertir char a std::string
        } else {
            return std::to_string(arg);
        }
    }, value);
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [IR_VARIABLE] -----

void IR_variable::initialize_variable(){
    switch (get_type())
    {
    case IR_VAR_TYPE_INT:
    {
        value.set_value<int>(0);
        break;
    }
    case IR_VAR_TYPE_REAL:
    {
        value.set_value<float>(0.0f);
        break;
    }
    case IR_VAR_TYPE_CHAR:
    {
        value.set_value<char>('\0');
        break;
    }
    case IR_VAR_TYPE_STR:
    {
        value.set_value<std::string>(std::string(""));
        break;
    }
    case IR_VAR_TYPE_BOOL:
    {
        value.set_value<bool>(false);
        break;
    }
    
    default:
        break;
    }
}

void IR_variable::initialize_array_variable(){
    for(unsigned i=0; i<type.array_size; i++){
        switch (get_array_type())
        {
        case IR_VAR_TYPE_INT:
        {
            value.set_value_in_array<int>(i,0);
            break;
        }
        case IR_VAR_TYPE_REAL:
        {
            value.set_value_in_array<float>(i,0.0f);
            break;
        }
        case IR_VAR_TYPE_CHAR:
        {
            value.set_value_in_array<char>(i,'\0');
            break;
        }
        case IR_VAR_TYPE_STR:
        {
            value.set_value_in_array<std::string>(i,"");
            break;
        }
        case IR_VAR_TYPE_BOOL:
        {
            value.set_value_in_array<bool>(i,false);
            break;
        }
        
        default:
            break;
        }
    }
    
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [IR_VARIABLE] -----

std::string IR_variable::get_kind_str(){
    std::string kind_str;

    auto it = IR_variable_t_str.find(kind);
    if(it != IR_variable_t_str.end())
        kind_str = it->second;

    return kind_str;
};

void IR_variable::set_value(atomic_type& v){
    switch (get_type())
    {
    case IR_VAR_TYPE_INT:
    {
        value.set_value<int>(std::get<int>(v));
        break;
    }
    case IR_VAR_TYPE_REAL:
    {
        value.set_value<float>(std::get<float>(v));
        break;
    }
    case IR_VAR_TYPE_CHAR:
    {
        value.set_value<char>(std::get<char>(v));
        break;
    }
    case IR_VAR_TYPE_STR:
    {
        value.set_value<std::string>(std::get<std::string>(v));
        break;
    }
    case IR_VAR_TYPE_BOOL:
    {
        value.set_value<bool>(std::get<bool>(v));
        break;
    }
    
    default:
        break;
    }
}

bool IR_variable::set_array_value(int index, atomic_type& v){
    bool assign_result = false;

    switch (get_array_type())
    {
    case IR_VAR_TYPE_INT:
    {
        assign_result = value.set_value_in_array<int>(index,std::get<int>(v));
        break;
    }
    case IR_VAR_TYPE_REAL:
    {
        assign_result = value.set_value_in_array<float>(index,std::get<float>(v));
        break;
    }
    case IR_VAR_TYPE_CHAR:
    {
        assign_result = value.set_value_in_array<char>(index,std::get<char>(v));
        break;
    }
    case IR_VAR_TYPE_STR:
    {
        assign_result = value.set_value_in_array<std::string>(index,std::get<std::string>(v));
        break;
    }
    case IR_VAR_TYPE_BOOL:
    {
        assign_result = value.set_value_in_array<bool>(index,std::get<bool>(v));
        break;
    }
    
    default:
        break;
    }

    return assign_result;
}

template <typename T>
T IR_variable::get_value() const{
    return value.get_value<T>();
}

template <typename T>
T IR_variable::get_array_value(int index) const{
    return value.get_array_value<T>(index);
}

std::string IR_variable::get_value_str() const{
    IR_variable_type_t var_type = get_type();
    if(var_type == IR_VAR_TYPE_ARRAY || var_type == IR_VAR_TYPE_PROCESS)
        return "------";
    
    return value.get_value_str();
}