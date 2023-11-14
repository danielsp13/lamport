/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file CU.hpp
 * @author Daniel Perez Ruiz
 * @brief Simulador de Unidad de Control (CU) de CPU para la maquina virtual de lamport
 */

#ifndef _LAMPORT_LVM_CPU_CU_DPR_
#define _LAMPORT_LVM_CPU_CU_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <memory>
#include <optional>

#include "registers.hpp"    // Registros de CPU
#include "CU_checker.hpp"   // Comprobador de instrucciones de CU
#include "ALU.hpp"          // Unidad Aritmetico Logica de la CPU
#include "EU.hpp"           // Unidad de ejecucion de la CPU

#include "IR/tables/instruction_table.hpp"         // Tabla de instrucciones IR
#include "LVM/memory/memory_manager.hpp"    // Manejador de memoria

#include "LVM/tracker/tracker.hpp"          // Gestor de traza de ejecucion de LVM

// ===============================================================

// ----- DEFINICION DE CLASE CU CPU -----

class LVM_CPU_CU{
    private:
        // -- Registros de CPU
        LVM_CPU_Registers& registers = LVM_CPU_Registers::get_instance();
        // -- Comprobador de instrucciones IR
        LVM_CPU_CU_Checker& instr_checker = LVM_CPU_CU_Checker::get_instance();
        // -- Unidad Aritmetico Logica de la CPU (ALU)
        LVM_CPU_ALU& ALU = LVM_CPU_ALU::get_instance();
        // -- Unidad de ejecucion de la CPU (EU)
        LVM_CPU_EU& EU = LVM_CPU_EU::get_instance();

        // -- Manejador de memoria
        LVM_Memory_Manager& memory_manager = LVM_Memory_Manager::get_instance();
        // -- Manejador de hebras
        LVM_Thread_Manager& thread_manager = LVM_Thread_Manager::get_instance();

        // -- Tabla de instrucciones IR
        IR_Instruction_Table& instructions = IR_Instruction_Table::get_instance();
        // -- Instruccion actual captada
        std::shared_ptr<IR_instruction> fetched_instr;
        // -- Codigo de instruccion captada
        IR_instruction_type_t fetched_instr_code;
        // -- Operando destino de instruccion captada
        std::optional<IR_operand> fetched_instr_operand_dest;
        // -- Operando 1 de instruccion captada
        std::optional<IR_operand> fetched_instr_operand_1;
        // -- Operando 2 de instruccion captada
        std::optional<IR_operand> fetched_instr_operand_2;

        // -- Gestor de traza de ejecucion de LVM
        LVM_Tracker& tracker = LVM_Tracker::get_instance();
        // -- Cabecera de mensajes de traza de ejecucion de LVM
        const std::string TRACKER_HEADER = "[CPU > Unidad de Control]: ";

        // -- Segmento de la hebra actual
        int segment_thread;

        // -- Flag que indica si el programa ha terminado
        bool program_ended = false;

        /**
         * @brief Constructor de la clase (por defecto)
         */
        LVM_CPU_CU() = default;

        /**
         * @brief Obtiene el segmento de memoria especifico del tipo de operando
         * @param type : tipo de operando de instruccion IR
         * @param virtual_dir : direccion virtual
         * @param offset_dir : desplazamiento
         * @return indice de segmento
         */
        int get_segment(IR_operand_t type, int virtual_dir, int offset_dir);

        /**
         * @brief Obtiene el desplazamiento de un acceso a array
         * @param type : tipo de operando de instruccion IR
         * @param offset_reg : indice de registro donde se encuentra el desplazamiento
         * @return desplazamiento de array (0 si el tipo de operando no es acceso a array)
         */
        int get_offset(IR_operand_t type, int offset_reg);

        /**
         * @brief Obtiene el valor del operando especificado
         * @param n_operand : numero de operando (0: destino , 1: operando1, 2: operando2)
         * @param offset : flag que indica si se quiere obtener el offset
         * @return direccion de operando
         */
        int get_value_from_operand(int n_operand, bool offset = false);

        /**
         * @brief Decodifica captada obtieniendo sus atributos y modificando los flags
         */
        void decode();

        /**
         * @brief Ejecuta la instruccion decodificada
         */
        void execute();

        /**
         * @brief Maneja una llamada al sistema
         */
        void manage_system_call();

        /**
         * @brief Actualiza el valor del contador de programa, dependiendo de la instruccion ejecutada
         * @param forced : flag que indica si el incremento debe ser forzado
         */
        void update_pc(bool forced=false);

    public:
        /**
         * @brief Obtiene la instancia de la clase
         * @return instance
         */
        static LVM_CPU_CU& get_instance();

        /**
         * @brief Destructor de la clase
         */ 
        ~LVM_CPU_CU() = default;

        /**
         * @brief Constructor de copia (eliminado)
         */
        LVM_CPU_CU(const LVM_CPU_CU&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const LVM_CPU_CU&) = delete;

        /**
         * @brief Inserta el segmento de direcciones de memoria que dispone
         * la hebra actual que esta ejecutando la CPU
         * @param segment : segmento de hebra
         */
        void set_segment_thread(int segment){segment_thread = segment;};

        /**
         * @brief Obtiene la instruccion
         */
        void fetch();

        /**
         * @brief Comprueba si el programa ha termiando
         * @return estado de flag program_ended
         */
        bool check_program_ended() const {return program_ended || thread_manager.check_all_threads_terminated(); };
};

#endif //_LAMPORT_LVM_CPU_CU_DPR_