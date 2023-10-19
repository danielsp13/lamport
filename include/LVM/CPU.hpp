/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file CPU.hpp
 * @author Daniel Perez Ruiz
 * @brief Simulador de CPU para la maquina virtual de lamport
 */

#ifndef _LAMPORT_LVM_CPU_DPR_
#define _LAMPORT_LVM_CPU_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <vector>
#include <stack>
#include <algorithm>
#include <string>

#include "register_table.hpp"       ///< Tabla de registros
#include "stack_block.hpp"          ///< Bloque

#include "memory.hpp"               ///< Memoria de Maquina Virtual
#include "segment_table.hpp"        ///< Tabla de segmentos de memoria virtual
#include "bounds.hpp"               ///< Registro de limites de arrays
#include "scheduler.hpp"            ///< Planificador de hebras

#include "IR/instruction.hpp"       ///< Instruccion
#include "IR/instruction_table.hpp" ///< Tabla de instrucciones
#include "IR/ir_reg_manager.hpp"    ///< Manejador de registros

// ===============================================================

// ----- DEFINICION DE CLASE CPU -----

class LVM_CPU{
    private:
        // -- Registros de maquina virtual
        LVM_Register_Table& register_table = LVM_Register_Table::get_instance();
        // -- Gestor de registros
        IR_Reg_Manager& reg_manager = IR_Reg_Manager::get_instance();
        // -- Tabla de instrucciones a ejecutar
        IR_Instruction_Table& instructions = IR_Instruction_Table::get_instance();
        // -- Pila (para manejo de subprogramas)
        std::stack<LVM_Stack_Block> stack;
        // -- Planificador de hebras
        LVM_Scheduler& scheduler = LVM_Scheduler::get_instance();
        // -- Hebra actual ejecutando CPU
        LVM_Thread* current_thread = nullptr;
        
        // -- Memoria de la maquina virtual
        LVM_Memory& memory = LVM_Memory::get_instance();
        // -- Tabla de paginas
        LVM_Segment_Table& segments_table = LVM_Segment_Table::get_instance();
        // -- Registro de limites de array
        LVM_Bounds& bounds_arrays = LVM_Bounds::get_instance();

        // -- Contador de programa
        int program_counter = 0;
        // -- Total de instrucciones
        const int total_instructions = instructions.size();

        /**
         * @brief Constructor de la clase
         */
        LVM_CPU() = default;

        /**
         * @brief Obtiene el la direccion fisica a partir de una virtual proporcionada
         * por un operando de instruccion
         * @param op : operando de instruccion
         * @return direccion fisica
         */
        int get_phisical_address_from_operand(const IR_operand & op);

        /**
         * @brief Comprueba si una instruccion es una operacion de inicio o fin de proceso
         * @param instr : instruccion
         * @return TRUE si es una operacion de start / end de proceso
         */
        inline bool instruction_is_start_or_end_process(const IR_instruction & instr);
        
        /**
         * @brief Comprueba si una instruccion es una operacion de fin de programa
         * @param instr : instruccion
         * @return TRUE si es una operacion de fin de programa
         */
        inline bool instruction_is_start_or_end_program(const IR_instruction & instr);

        /**
         * @brief Comprueba si una instruccion es una operacion de carga
         * @param instr : instruccion
         * @return TRUE si es una operacion de carga, FALSE en otro caso
         */
        inline bool instruction_is_load_or_store(const IR_instruction & instr);

        /**
         * @brief Comprueba si una instruccion es una etiqueta
         * @param instr : instruccion
         * @return TRUE si es una etiqueta, FALSE en otro caso
         */
        inline bool instruction_is_label_pointer(const IR_instruction & instr);

        /**
         * @brief Comprueba si una instruccion es una operacion binaria
         * @param instr : instruccion
         * @return TRUE si es una operacion binaria, FALSE en otro caso
         */
        inline bool instruction_is_binary_operation(const IR_instruction & instr);

        /**
         * @brief Comprueba si una instruccion es una operacion unaria
         * @param instr : instruccion
         * @return TRUE si es una operacion unaria, FALSE en otro caso
         */
        inline bool instruction_is_unary_operation(const IR_instruction & instr);

        /**
         * @brief Comprueba si una instruccion es un salto
         * @param instr : instruccion
         * @return TRUE si es una operacion unaria, FALSE en otro caso
         */
        inline bool instruction_is_jump(const IR_instruction & instr);

        /**
         * @brief Comprueba si una instruccion es una operacion de impresion
         * @param instr : instruccion
         * @return TRUE si es una operacion de impresion, FALSE en otro caso
         */
        inline bool instruction_is_print(const IR_instruction & instr);

        /**
         * @brief Comprueba si una instruccion es una operacion de gestion en pila
         * @param instr : instruccion
         * @return TRUE si es una operacion esperada, FALSE en otro caso
         */
        inline bool instruction_is_push_or_pop(const IR_instruction & instr);

        /**
         * @brief Comprueba si una instruccion es una operacion llamada/retorno de subprograma
         * @param instr : intruccion
         * @return TRUE si es una operacion esperada, FALSE en otro caso
         */
        inline bool instruction_is_call_or_ret_subprogram(const IR_instruction & instr);

        /**
         * @brief Comprueba si una instruccion es atomica
         * @param instr : instruccion
         * @return TRUE si es una operacion esperada, FALSE en otro caso
         */
        inline bool instruction_is_atomic(const IR_instruction & instr);

        /**
         * @brief Comprueba si una instruccion es fork o join
         * @param instr : instruccion
         * @return TRUE si es una operacion esperada, FALSE en otro caso
         */
        inline bool instruction_is_fork_or_join(const IR_instruction & instr);

        /**
         * @brief Comprueba si una instruccion es un acceso a bloque cobegin-coend
         * @param instr : instruccion
         * @return TRUE si es una operacion esperada, FALSE en otro caso
         */
        inline bool instruction_is_cobegin(const IR_instruction & instr);

        /**
         * @brief Comprueba si una instruccion marca el inicio/fin de hebra cobegin
         * @param instr : instruccion
         * @return TRUE si es una operacion esperada, FALSE en otro caso
         */
        inline bool instruction_is_thread_cobegin(const IR_instruction & instr);

        /**
         * @brief Comprueba si una instruccion no es una instruccion (inicio de seccion de subprogramas)
         * @param instr : instruccion
         */
        inline bool instruction_is_not_instruction(const IR_instruction & instr);
        
        /**
         * @brief Obtiene el conjunto de registros a los que refiere una instruccion
         * @param instr : instruccion
         * @return vector con los registros de la tabla de registros a los que hace referencia
         */
        std::vector<LVM_Register> get_registers_from_operands(const IR_instruction & instr);

        /**
         * @brief Ejecuta la instruccion especificada
         * @param instr_to_exec : instruccion
         */
        void execute_instruction(const IR_instruction & instr_to_exec);

        /**
         * @brief Ejecuta una instruccion de inicio/fin de proceso
         * @param instr : instruccion
         */
        void execute_instruction_start_or_end_process(const IR_instruction & instr);

        /**
         * @brief Ejecuta una instruccion de inicio de proceso
         * @param instr : instruccion IR_START_PROCESS
         */
        void execute_instruction_start_process(const IR_instruction & instr);

        /**
         * @brief Ejecuta una instruccion de fin de proceso
         * @param instr : instruccion IR_END_PROCESS
         */
        void execute_instruction_end_process(const IR_instruction & instr);
        
        /**
         * @brief Ejecuta una instruccion de inicio/fin de programa
         * @param instr : instruccion
         */
        void execute_instruction_start_or_end_program(const IR_instruction & instr);

        /**
         * @brief Ejecuta una instruccion de inicio de programa
         * @param instr : instruccion
         */
        void execute_instruction_start_program(const IR_instruction & instr);

        /**
         * @brief Ejecuta una instruccion de fin de programa
         * @param instr : instruccion IR_END_PROGRAM
         */
        void execute_instruction_end_program(const IR_instruction & instr);

        /**
         * @brief Ejecuta una instruccion de almacenamiento a memoria o a registro
         * @param instr : instruccion IR_OP_LOAD o IR_OP_STORE
         */
        void execute_instruction_load_or_store(const IR_instruction & instr);

        /**
         * @brief Ejecuta la instruccion de almacenamiento en registro
         * @param instr : instruccion IR_OP_LOAD
         */
        void execute_instruction_load(const IR_instruction & instr);

        /**
         * @brief Ejecuta la instruccion de almacenamiento en memoria
         * @param instr : instruccion IR_OP_STORE
         */
        void execute_instruction_store(const IR_instruction & instr);

        /**
         * @brief Ejecuta la instruccion de operacion binaria
         * @param instr : instruccion
         * Tipos de instrucciones binarias
         * --- IR_OP_ADD (suma)
         * --- IR_OP_SUB (resta)
         * --- IR_OP_MULT (multiplicacion)
         * --- IR_OP_DIV (division)
         * --- IR_OP_MOD (resto)
         * 
         * --- IR_OP_CMP_LTE (menor o igual)
         * --- IR_OP_CMP_LT (menor)
         * --- IR_OP_CMP_GTE (mayor o igual)
         * --- IR_OP_CMP_GT (mayor)
         * --- IR_OP_CMP_EQ (igual)
         * --- IR_OP_CMP_NEQ (no igual)
         * 
         * --- IR_OP_AND (conjuncion logica)
         * --- IR_OP_OR (disyuncion logica)
         */
        void execute_instruction_binary_operation(const IR_instruction & instr);

        /**
         * @brief Ejecuta la instruccion de operacion unaria
         * @param instr : instruccion
         * Tipos de instrucciones unarias
         * --- IR_OP_NEG (negacion aritmetica)
         * --- IR_OP_NOT (negacion logica)
         */
        void execute_instruction_unary_operation(const IR_instruction & instr);

        /**
         * @brief Ejecuta instruccion de salto
         * @param instr : instruccion
         * Tipos de instrucciones de salto
         * --- IR_OP_JMP (salto incondicional)
         * --- IR_OP_JMP_FALSE (salto condicional si falso)
         * --- IR_OP_JMP_TRUE (salto condicional si verdadero)
         */
        void execute_instruction_jump(const IR_instruction & instr);
    
        /**
         * @brief Ejecuta la instruccion de impresion de contenido
         * @param instr : instruccion IR_OP_PRINT
         */
        void execute_instruction_print(const IR_instruction & instr);

        /**
         * @brief Ejecuta una instruccion de llamada o de retorno de subprograma
         * @param instr : instruccion
         */
        void execute_instruction_call_or_ret(const IR_instruction & instr);

        /**
         * @brief Ejecuta una instruccion de llamada a subprograma
         * @param instr : instruccion IR_OP_CALL
         */
        void execute_instruction_call(const IR_instruction & instr);

        /**
         * @brief Ejecuta una instruccion de llamada a subprograma
         * @param instr : instruccion IR_OP_RET
         */
        void execute_instruction_ret(const IR_instruction & instr);

        /**
         * @brief Ejecuta una instruccion de pushing o poping a pila
         * @param instr : instruccion
         */
        void execute_instruction_push_or_pop(const IR_instruction & instr);

        /**
         * @brief Ejecuta una instruccion de pushing a pila
         * @param instr : instruccion IR_OP_PUSH
         */
        void execute_instruction_push(const IR_instruction & instr, bool from_local = false);
        
        /**
         * @brief Ejecuta una instruccion de pushing a pila
         * @param instr : instruccion IR_OP_PUSH
         */
        void execute_instruction_push_local(const IR_instruction & instr);

        /**
         * @brief Ejecuta una instruccion de poping a pila
         * @param instr : instruccion IR_OP_POP
         */
        void execute_instruction_pop(const IR_instruction & instr, bool from_local = false);

        /**
         * @brief Ejecuta una instruccion de poping a pila
         * @param instr : instruccion IR_OP_POP_LOCAL
         */
        void execute_instruction_pop_local(const IR_instruction & instr);

        /**
         * @brief Ejecuta el inicio/fin de seccion atomica
         * @param instr : instruccion IR_OP_ATOMIC_BEGIN / IR_OP_ATOMIC_END
         */
        void execute_instruction_atomic(const IR_instruction & instr);

        /**
         * @brief Ejecuta una instruccion fork o join
         * @param instr : instruccion
         */
        void execute_instruction_fork_or_join(const IR_instruction & instr);

        /**
         * @brief Ejecuta una instruccion fork
         * @param instr : instruccion
         */
        void execute_instruction_fork(const IR_instruction & instr);

        /**
         * @brief Ejecuta una instruccion join
         * @param instr : instruccion
         */
        void execute_instruction_join(const IR_instruction & instr);

        /**
         * @brief Ejecuta una instruccion cobegin/coend
         * @param instr : instruccion
         */
        void execute_instruction_cobegin_or_coend(const IR_instruction & instr);

        /**
         * @brief Ejecuta una instruccion cobegin
         * @param instr : instruccion
         */
        void execute_instruction_cobegin(const IR_instruction & instr);

        /**
         * @brief Ejecuta una instruccion cobegin
         * @param instr : instruccion
         */
        void execute_instruction_coend(const IR_instruction & instr);

        /**
         * @brief Ejecuta una instruccion de gestion de thread cobegin
         * @param instr : instruccion
         */
        void execute_instruction_thread_cobegin(const IR_instruction & instr);

    public:
        /**
         * @brief Obtiene la instancia
         * @return instancia
         */
        static LVM_CPU& get_instance();

        /**
         * @brief Destructor de la clase
         */
        ~LVM_CPU() = default;

        /**
         * @brief Constructor de copia (eliminado)
         */
        LVM_CPU(const LVM_CPU&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const LVM_CPU&) = delete;

        /**
         * @brief Devuelve el valor del contador de programa
         * @return contador de programa
         */
        int get_program_counter() const { return this->program_counter; };

        /**
         * @brief Devuelve el total de instrucciones a ejecutar
         * @return total de instrucciones
         */
        int get_total_instructions() const { return this->total_instructions; };

        /**
         * @brief Preinicia el programa, llegando a una seccion de proceso
         */
        void pre_start();

        /**
         * @brief Ejecuta la siguiente instruccion a la que apunta el contador de programa
         */
        void execute_next_instruction();

        
};

#endif //_LAMPORT_LVM_CPU_DPR_
