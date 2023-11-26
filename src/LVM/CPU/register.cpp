/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file register.hpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion de registro para la maquina virtual de lamport
 */

#include "LVM/CPU/register.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [LVM REGISTER] -----



// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [LVM REGISTER] -----

std::string LVM_Register::get_type_of_alloc_str() const{
    std::string allocates_type_str;

    auto it = LVM_Register_type_t_str.find(this->allocates_type);
    if(it != LVM_Register_type_t_str.end())
        allocates_type_str = it->second;

    return allocates_type_str;
}

std::string LVM_Register::get_value_str() const{
    std::string value_allocated_str;
    switch (this->allocates_type)
    {
    case REG_EMPTY:
    {
        value_allocated_str = std::string("NULL");
        break;
    }
    case REG_CONTAINS_INTEGER:
    {
        value_allocated_str = std::to_string(std::get<int>(value_allocated));
        break;
    }
    case REG_CONTAINS_REAL:
    {
        value_allocated_str = std::to_string(std::get<float>(value_allocated));
        break;
    }
    case REG_CONTAINS_CHAR:
    {
        char ch = std::get<char>(value_allocated);
    
        switch(ch) {
            case '\n': 
            {
                value_allocated_str = "'\\n'"; 
                break;
            }
            case '\t':
            {
                value_allocated_str = "'\\t'";
                break;
            }
            case '\r':
            {
                value_allocated_str = "'\\r'";
                break;
            }
            case '\0':
            {
                value_allocated_str = "\'\'";
                break;
            }
            
            default:
            {
                if(std::isprint(ch)) { // Si es un caracter imprimible
                    value_allocated_str = "'" + std::string(1, ch) + "'";
                } else { 
                    // Convertir caracteres no imprimibles a su representación hexadecimal
                    std::ostringstream oss;
                    oss << "'\\x" << std::setfill('0') << std::setw(2) << std::hex << (int)ch << "'";
                    value_allocated_str = oss.str();
                }
                break;
            }
                
        }
        
        break;
    }
    case REG_CONTAINS_STRING:
    {
        value_allocated_str = std::get<std::string>(value_allocated);
        
        if(value_allocated_str == std::string("\n"))
            value_allocated_str = std::string("\"\\n\"");
        else
            value_allocated_str = "\"" + value_allocated_str + "\"";

        break;
    }
    case REG_CONTAINS_BOOL:
    {
        value_allocated_str = std::get<bool>(value_allocated) ? std::string("true") : std::string("false");
        break;
    }
    
    default:
        value_allocated_str = std::string("UNDEFINED");
        break;
    }

    return value_allocated_str;
}

LVM_Register LVM_Register::operator+(const LVM_Register& otro) const{
    switch (allocates_type)
    {
    case REG_CONTAINS_INTEGER:
    {
        return LVM_Register(this->get_value<int>() + otro.get_value<int>());
        break;
    }
    case REG_CONTAINS_REAL:
    {
        return LVM_Register(this->get_value<float>() + otro.get_value<float>());
        break;
    }
    
    default:{
        LVM_Tracker::get_instance().print_trace();
        LVM_Tracker::get_instance().print_cpu_cycle_trace();

        std::string MSG = "OPERACIÓN DE REGISTRO (+) NO SOPORTADA ";
        MSG += ": suma de (" + get_type_of_alloc_str() + ") con (" + otro.get_type_of_alloc_str() + ").";
        throw std::invalid_argument(MSG);
        break;
    }
    }
}

LVM_Register LVM_Register::operator-(const LVM_Register& otro) const{
    switch (allocates_type)
    {
    case REG_CONTAINS_INTEGER:
    {
        return LVM_Register(this->get_value<int>() - otro.get_value<int>());
        break;
    }
    case REG_CONTAINS_REAL:
    {
        return LVM_Register(this->get_value<float>() - otro.get_value<float>());
        break;
    }
    
    default:{
        LVM_Tracker::get_instance().print_trace();
        LVM_Tracker::get_instance().print_cpu_cycle_trace();

        throw std::invalid_argument("OPERACIÓN DE REGISTRO (-) NO SOPORTADA.");
        break;
    }
        
    }
}

LVM_Register LVM_Register::operator*(const LVM_Register& otro) const{
    switch (allocates_type)
    {
    case REG_CONTAINS_INTEGER:
    {
        return LVM_Register(this->get_value<int>() * otro.get_value<int>());
        break;
    }
    case REG_CONTAINS_REAL:
    {
        return LVM_Register(this->get_value<float>() * otro.get_value<float>());
        break;
    }
    
    default:
    {
        LVM_Tracker::get_instance().print_trace();
        LVM_Tracker::get_instance().print_cpu_cycle_trace();

        throw std::invalid_argument("OPERACIÓN DE REGISTRO (*) NO SOPORTADA.");
        break;
    }
        
    }
}

LVM_Register LVM_Register::operator/(const LVM_Register& otro) const{

    switch (allocates_type)
    {
    case REG_CONTAINS_INTEGER:
    {
        if(otro.get_value<int>() == 0){
            std::string operation = this->get_value_str() + " / " + otro.get_value_str();
            throw std::runtime_error("DIVISION POR CERO NO PERMITIDA. Se encontró: " + operation + ".");
        }

        return LVM_Register(this->get_value<int>() / otro.get_value<int>());
        break;
    }
    case REG_CONTAINS_REAL:
    {
        return LVM_Register(this->get_value<float>() / otro.get_value<float>());
        break;
    }
    
    default:
    {
        LVM_Tracker::get_instance().print_trace();
        LVM_Tracker::get_instance().print_cpu_cycle_trace();

        throw std::invalid_argument("OPERACIÓN DE REGISTRO (/) NO SOPORTADA.");
        break;
    }
    }
}

LVM_Register LVM_Register::operator%(const LVM_Register & otro) const{
    switch (allocates_type)
    {
    case REG_CONTAINS_INTEGER:
    {
        return LVM_Register(this->get_value<int>() % otro.get_value<int>());
        break;
    }
    
    default:
    {
        LVM_Tracker::get_instance().print_trace();
        LVM_Tracker::get_instance().print_cpu_cycle_trace();
        
        throw std::invalid_argument("OPERACIÓN DE REGISTRO (%) NO SOPORTADA.");
        break;
    }
        
    }
}

LVM_Register LVM_Register::operator-() const{
    switch (allocates_type)
    {
    case REG_CONTAINS_INTEGER:
    {
        return LVM_Register(-this->get_value<int>());
        break;
    }
    case REG_CONTAINS_REAL:
    {
        return LVM_Register(-this->get_value<float>());
        break;
    }
    
    default:
    {
        LVM_Tracker::get_instance().print_trace();
        LVM_Tracker::get_instance().print_cpu_cycle_trace();

        throw std::invalid_argument("OPERACIÓN DE REGISTRO (- unary) NO SOPORTADA.");
        break;
    }
        
    }
}

LVM_Register LVM_Register::operator<(const LVM_Register & otro) const{
    switch (allocates_type)
    {
    case REG_CONTAINS_INTEGER:
    {
        return LVM_Register(this->get_value<int>() < otro.get_value<int>());
        break;
    }
    case REG_CONTAINS_REAL:
    {
        return LVM_Register(this->get_value<float>() < otro.get_value<float>());
        break;
    }
    
    default:
        throw std::invalid_argument("OPERACIÓN DE REGISTRO (<) NO SOPORTADA.");
        break;
    }
}

LVM_Register LVM_Register::operator<=(const LVM_Register & otro) const{
    switch (allocates_type)
    {
    case REG_CONTAINS_INTEGER:
    {
        return LVM_Register(this->get_value<int>() <= otro.get_value<int>());
        break;
    }
    case REG_CONTAINS_REAL:
    {
        return LVM_Register(this->get_value<float>() <= otro.get_value<float>());
        break;
    }
    
    default:
    {
        LVM_Tracker::get_instance().print_trace();
        LVM_Tracker::get_instance().print_cpu_cycle_trace();

        throw std::invalid_argument("OPERACIÓN DE REGISTRO (<=) NO SOPORTADA.");
        break;
    }
        
    }
}

LVM_Register LVM_Register::operator>(const LVM_Register & otro) const{
    switch (allocates_type)
    {
    case REG_CONTAINS_INTEGER:
    {
        return LVM_Register(this->get_value<int>() > otro.get_value<int>());
        break;
    }
    case REG_CONTAINS_REAL:
    {
        return LVM_Register(this->get_value<float>() > otro.get_value<float>());
        break;
    }
    
    default: 
    {
        LVM_Tracker::get_instance().print_trace();
        LVM_Tracker::get_instance().print_cpu_cycle_trace();
        
        throw std::invalid_argument("OPERACIÓN DE REGISTRO (>) NO SOPORTADA.");
        break;
    }
        
    }
}

LVM_Register LVM_Register::operator>=(const LVM_Register & otro) const{
    switch (allocates_type)
    {
    case REG_CONTAINS_INTEGER:
    {
        return LVM_Register(this->get_value<int>() >= otro.get_value<int>());
        break;
    }
    case REG_CONTAINS_REAL:
    {
        return LVM_Register(this->get_value<float>() >= otro.get_value<float>());
        break;
    }
    
    default:
    {
        LVM_Tracker::get_instance().print_trace();
        LVM_Tracker::get_instance().print_cpu_cycle_trace();

        throw std::invalid_argument("OPERACIÓN DE REGISTRO (>=) NO SOPORTADA.");
        break;
    }
        
    } 
}

LVM_Register LVM_Register::operator==(const LVM_Register & otro) const{
    switch (allocates_type)
    {
    case REG_CONTAINS_INTEGER:
    {
        return LVM_Register(this->get_value<int>() == otro.get_value<int>());
        break;
    }
    case REG_CONTAINS_REAL:
    {
        return LVM_Register(this->get_value<float>() == otro.get_value<float>());
        break;
    }
    case REG_CONTAINS_CHAR:
    {
        return LVM_Register(this->get_value<char>() == otro.get_value<char>());
        break;
    }
    case REG_CONTAINS_STRING:
    {
        return LVM_Register(this->get_value<std::string>() == otro.get_value<std::string>());
        break;
    }
    case REG_CONTAINS_BOOL:
    {
        return LVM_Register(this->get_value<bool>() == otro.get_value<bool>());
        break;
    }
    
    default:
    {
        LVM_Tracker::get_instance().print_trace();
        LVM_Tracker::get_instance().print_cpu_cycle_trace();

        throw std::invalid_argument("OPERACIÓN DE REGISTRO (==) NO SOPORTADA.");
        break;
    }
        
    }
}

LVM_Register LVM_Register::operator!=(const LVM_Register & otro) const{
    switch (allocates_type)
    {
    case REG_CONTAINS_INTEGER:
    {
        return LVM_Register(this->get_value<int>() != otro.get_value<int>());
        break;
    }
    case REG_CONTAINS_REAL:
    {
        return LVM_Register(this->get_value<float>() != otro.get_value<float>());
        break;
    }
    case REG_CONTAINS_CHAR:
    {
        return LVM_Register(this->get_value<char>() != otro.get_value<char>());
        break;
    }
    case REG_CONTAINS_STRING:
    {
        return LVM_Register(this->get_value<std::string>() != otro.get_value<std::string>());
        break;
    }
    case REG_CONTAINS_BOOL:
    {
        return LVM_Register(this->get_value<bool>() != otro.get_value<bool>());
        break;
    }
    
    default:
    {
        LVM_Tracker::get_instance().print_trace();
        LVM_Tracker::get_instance().print_cpu_cycle_trace();

        throw std::invalid_argument("OPERACIÓN DE REGISTRO (!=) NO SOPORTADA.");
        break;
    }
        
    }
}

LVM_Register LVM_Register::operator&&(const LVM_Register & otro) const{
    switch (allocates_type)
    {
    case REG_CONTAINS_BOOL:
    {
        return LVM_Register(this->get_value<bool>() && otro.get_value<bool>());
        break;
    }
    
    default:
    {
        LVM_Tracker::get_instance().print_trace();
        LVM_Tracker::get_instance().print_cpu_cycle_trace();

        throw std::invalid_argument("OPERACIÓN DE REGISTRO (&& and) NO SOPORTADA.");
        break;
    }
        
    }
}

LVM_Register LVM_Register::operator||(const LVM_Register & otro) const{
    switch (allocates_type)
    {
    case REG_CONTAINS_BOOL:
    {
        return LVM_Register(this->get_value<bool>() || otro.get_value<bool>());
        break;
    }
    
    default:
    {
        LVM_Tracker::get_instance().print_trace();
        LVM_Tracker::get_instance().print_cpu_cycle_trace();

        throw std::invalid_argument("OPERACIÓN DE REGISTRO (|| or) NO SOPORTADA.");
        break;
    }
        
    }
}

LVM_Register LVM_Register::operator!() const{
    switch (allocates_type)
    {
    case REG_CONTAINS_BOOL:
    {
        return LVM_Register(!this->get_value<bool>());
        break;
    }
    
    default:
    {
        LVM_Tracker::get_instance().print_trace();
        LVM_Tracker::get_instance().print_cpu_cycle_trace();

        throw std::invalid_argument("OPERACIÓN DE REGISTRO (! not) NO SOPORTADA.");
        break;
    }
        
    }
}