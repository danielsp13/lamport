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

#include <iostream>
#include <vector>
#include <string>

// ===============================================================

// ----- CLASE ASISTENTE DE TRADUCCION -----

class IR_Translator_Assistant{
    private:
        // Mapa de variables locales/parametros de subprograma
        std::vector<std::pair<std::string,int>> locals_subprog;

        /**
         * @brief Constructor de la clase
         */
        IR_Translator_Assistant() = default;

        /**
         * @brief Obtiene el indice donde se encuentra la informacion de la variable local
         * @param local_name : variable local del programa
         * @return indice de informacion de variable local
         */
        int get_index_var_local_subprog(std::string local_name);

    public:
        /**
         * @brief Inserta un nuevo parametro de subprograma en la lista
         * @param local_name : variable local del programa
         * @param reg_addr : direccion de registro
         */
        void insert_var_local_subprog(std::string local_name, int reg_addr);

        /**
         * @brief Obtiene el registro donde se encuentra la variable local de subprograma
         * @param local_name : nombre de variable local
         * @return indice de registro
         */
        int get_reg_from_var_local_subprog(std::string local_name);

        /**
         * @brief Obtiene el registro donde se encuentra la variable local de subprograma (arrays)
         * @param local_name : nombre de variable local
         * @param offset : desplazamiento de posicion
         * @return indice de registro
         */
        int get_reg_from_var_local_subprog(std::string local_name, int offset);

        /**
         * @brief Comprueba si el nombre de variable otorgado es una variable local de subprograma
         * @return TRUE si es una variable local/FALSE en otro caso
         */
        bool is_var_local_subprog(std::string var_name);

        /**
         * @brief Limpia el vector de parametros de subprograma
         */
        void clear_locals_subprog() { locals_subprog.clear(); };

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