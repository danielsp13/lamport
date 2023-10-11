/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_translator_assistant.hpp
 * @author Daniel Perez Ruiz
 * @brief Definicion del asistente de traduccion de codigo intermedio Lineal (IR)
 */

#ifndef _LAMPORT_IR_TRANSLATOR_ASSISTANT_DPR_
#define _LAMPORT_IR_TRANSLATOR_ASSISTANT_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <vector>
#include <string>

// ===============================================================

// ----- CLASE ASISTENTE DE TRADUCCION -----

class IR_Translator_Assistant{
    private:
        // Vector de variables locales de subprograma
        std::vector<std::pair<std::string,int>> var_local_subprog;

        /**
         * @brief Constructor de la clase
         */
        IR_Translator_Assistant() = default;

    public:
        /**
         * @brief Inserta una nueva variable local de subprograma en la lista
         * @param var_local_name : nombre de variable local
         * @param reg_addr : direccion de registro
         */
        void insert_var_local_subprog(std::string var_local_name, int reg_addr);

        /**
         * @brief Obtiene el registro donde se encuentra la variable local de subprograma
         * @param var_local_name : variable local de subprograma
         * @return indice de registro
         */
        int get_reg_from_var_local_name_subprog(std::string var_local_name);

        /**
         * @brief Limpia el vector de variables locales de subprograma
         */
        void clear_var_local_subprog() { var_local_subprog.clear(); } ;

        /**
         * @brief Obtiene la instancia de la clase
         * @return instance
         */
        static IR_Translator_Assistant& get_instance();

        /**
         * @brief Destructor de la clase (por defecto)
         */
        ~IR_Translator_Assistant() = default;

        /**
         * @brief Constructor de copia (eliminado)
         */
        IR_Translator_Assistant(const IR_Translator_Assistant&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const IR_Translator_Assistant&) = delete;
};

#endif //_LAMPORT_IR_TRANSLATOR_ASSISTANT_DPR_