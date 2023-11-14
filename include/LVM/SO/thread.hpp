/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file thread.hpp
 * @author Daniel Perez Ruiz
 * @brief Simulador de hilo para la maquina virtual de lamport
 */

#ifndef _LAMPORT_LVM_THREAD_DPR_
#define _LAMPORT_LVM_THREAD_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <vector>
#include <stack>
#include <string>

#include "LVM/CPU/registers.hpp"    ///< Registros LVM
#include "LVM/utils/block.hpp"      ///< Bloque de datos
#include "LVM/SO/thread_stack.hpp"  ///< Pila de hebra

// ===============================================================

// ----- DEFINICION DE ESTADOS DE HILO -----

/**
 * @brief Enumerado que representa los diferentes estados de los
 * hilos del sistema
 */
typedef enum{
    LVM_THREAD_NEW,             ///< Se acaba de crear el hilo
    LVM_THREAD_READY,           ///< El hilo esta listo para ejecucion
    LVM_THREAD_RUNNING,         ///< El hilo esta ejecutando
    LVM_THREAD_BLOCKED,         ///< El hilo esta bloqueado
    LVM_THREAD_UNBLOCKED,       ///< El hilo acaba de ser desbloqueado
    LVM_THREAD_TERMINATED,      ///< El hilo ha terminado
    LVM_THREAD_ZOMBIE,          ///< El hilo esta zombie
} LVM_Thread_states_t;

// ===============================================================

// ----- DEFINICION DE CLASE HILO -----

class LVM_Thread{
    private:
        // -- Identificacion de hilo
        int id;
        // -- Contador de programa
        int program_counter;
        // -- Segmento de direcciones asociado a thread
        int segment_address;
        // -- Estado del hilo
        LVM_Thread_states_t state;
        // -- Prioridad de ejecucion del hilo
        int priority;
        
        // -- Contexto de registros de CPU de la hebra
        std::vector<LVM_Register> regs_context;
        // -- Pila de la hebra
        LVM_Thread_Stack stack;

        // -- Contador de instrucciones ejecutadas por la hebra
        int instruction_counter = 0;
        // -- Quantum asociado a la hebra
        int quantum = 0;

        // -- Contador de hebras hijas
        int child_counter = 0;
        // -- Contador de hebras hijas terminadas
        int child_end_counter = 0;

        // -- Flag que comprueba si el thread ha entrado en una seccion critica
        bool in_atomic = false;

        // -- Flag que comprueba si es thread iniciadora de programa
        bool master = false;

        // --------------- Hebras hijas

        // -- Flag que indica que el thread es un hijo
        bool child = false;

        // -- Puntero a hebra padre
        LVM_Thread * parent = nullptr;
    public:
        // -- Constante de prioridad de hebra maestra
        static const unsigned int MASTER_PRIORITY = 100000;
        // -- Constante de prioridad de hebra maestra
        static const unsigned int DEFAULT_PRIORITY = 1;

        /**
         * @brief Crea e inicializa un nuevo hilo
         * @param id : identificador de hilo
         * @param pc : contador de programa
         * @param segment_addr : direccion de segmento virtual
         */
        LVM_Thread(int id, int pc, int segment_addr)
            : id(id), program_counter(pc), segment_address(segment_addr), state(LVM_THREAD_NEW), priority(DEFAULT_PRIORITY), regs_context(LVM_CPU_Registers::N_REGISTERS) {};

        /**
         * @brief Crea e inicializa un nuevo hilo hijo
         * @param id : identificador de hilo
         * @param pc : contador de programa
         * @param segment_addr : direccion de segmento virtual
         * @param parent : puntero a hebra padre
         */
        LVM_Thread(int id, int pc, int segment_addr, LVM_Thread * parent)
            : id(id), program_counter(pc), segment_address(segment_addr), state(LVM_THREAD_NEW), priority(DEFAULT_PRIORITY), parent(parent), regs_context(LVM_CPU_Registers::N_REGISTERS) {
                if(parent != nullptr)
                    child = true;
            };

        /**
         * @brief Crea e inicializa un nuevo hilo hijo
         * @param id : identificador de hilo
         * @param pc : contador de programa
         * @param segment_addr : direccion de segmento virtual
         * @param priority : prioridad de hebra
         * @param parent : puntero a hebra padre
         */
        LVM_Thread(int id, int pc, int segment_addr, int priority, LVM_Thread * parent)
            : id(id), program_counter(pc), segment_address(segment_addr), state(LVM_THREAD_NEW), priority(priority), parent(parent), regs_context(LVM_CPU_Registers::N_REGISTERS) {
                if(parent != nullptr)
                    child = true;

                if(priority == MASTER_PRIORITY)
                    mark_master();
            };

        /**
         * @brief Destrutor de hilo
         */
        ~LVM_Thread() = default;

        /**
         * @brief Obtiene el identificador de la hebra
         * @return id de hebra
         */
        int get_id() const {return id; };

        /**
         * @brief Obtiene el identificador de la hebra padre
         * @return id de hebra padre
         */
        int get_parent_id() const {return parent->get_id(); };

        /**
         * @brief Obtiene la hebra padre
         * @return hebra padre
         */
        LVM_Thread * get_parent() {return parent; };

        /**
         * @brief Devuelve el numero de hijos de la hebra
         */
        int get_childs() {return child_counter; };

        /**
         * @brief Devuelve el numero de hijos terminados de la hebra
         */
        int get_childs_finished() {return child_end_counter; };

        /**
         * @brief Obtiene el estado de la hebra
         * @return estado de la hebra
         */
        LVM_Thread_states_t get_state() const {return state;} ;

        /**
         * @brief Asigna un contador de programa al hilo
         * @param pc : contador de programa
         */
        void set_pc(int pc) { program_counter = pc; };

        /**
         * @brief Obtiene el contador de programa del hilo
         * @return contador de programa
         */
        const int get_pc() const { return program_counter; };

        /**
         * @brief Asigna una prioridad de ejecucion a la hebra
         * @param prior : prioridad
         */
        void set_priority(int prior){ priority = prior; };

        /**
         * @brief Obtiene la prioridad de la hebra
         * @return priority
         */
        const int get_priority() const {return priority; };
        
        /**
         * @brief Obtiene el segmento asociado al hilo
         * @return segmento
         */
        const int get_segment() const {return segment_address; };

        /**
         * @brief Especifica un quantum para la hebra
         * @param q : quantum
         */
        void set_quantum(int q) { quantum = q; };

        /**
         * @brief Obtiene el quantum dedicado al hilo
         * @return quantum
         */
        const int get_quantum() const {return quantum; };

        /**
         * @brief Marca que ha ejecutado una instruccion incrementando su contador
         */
        void instruction_executed(){ instruction_counter++; };

        /**
         * @brief Obtiene el total de instrucciones ejecutadas por la hebra
         * @return numero de instrucciones
         */
        const int get_total_instructions_executed() const {return instruction_counter; };

        /**
         * @brief Reseta los contadores de instruccion de la hebra
         */
        void reset_counters(){ quantum = 0; instruction_counter = 0; };

        /**
         * @brief Indica que el thread entra de seccion atomica
         */
        void mark_atomic() {in_atomic = true; };

        /**
         * @brief Indica que el thread sale de seccion atomica
         */
        void unmark_atomic() {in_atomic = false;};

        /**
         * @brief Marca que la hebra es master
         */
        void mark_master() {master = true; };
        
        /**
         * @brief Comprueba si la hebra es iniciadora del programa
         */
        bool is_master() {return master; };

        /**
         * @brief Indica que la hebra ha entrado en una seccion critica
         * @return TRUE si esta en seccion critica, FALSE en otro caso
         */
        bool in_atomic_section() const {return in_atomic; };

        /**
         * @brief Asigna un nuevo estado al hilo
         * @param st : nuevo estado
         */
        void set_state(LVM_Thread_states_t st){ state = st; };

        /**
         * @brief Indica si el hilo es nuevo
         * @return TRUE si verifica el estado, FALSE si no lo es
         */
        bool is_new() {return state == LVM_THREAD_NEW;};

        /**
         * @brief Indica si el hilo esta listo para ejecucion
         * @return TRUE si verifica el estado, FALSE si no lo es
         */
        bool is_ready() {return state == LVM_THREAD_READY; };

        /**
         * @brief Indica si el hilo esta ejecutandose
         * @return TRUE si verifica el estado, FALSE si no lo es
         */
        bool is_running() {return state == LVM_THREAD_RUNNING; };

        /**
         * @brief Indica si el hilo esta bloqueada
         * @return TRUE si verifica el estado, FALSE si no lo es
         */
        bool is_blocked() {return state == LVM_THREAD_BLOCKED; };

        /**
         * @brief Indica si el hilo esta desbloqueado
         * @return TRUE si se verifica el estado, FALSE si no lo es
         */
        bool is_unblocked() {return state == LVM_THREAD_UNBLOCKED; };

        /**
         * @brief Indica si el hilo ha terminado
         * @return TRUE si verifica el estado, FALSE si no lo es
         */
        bool is_terminated() {return state == LVM_THREAD_TERMINATED; };

        /**
         * @brief Indica si el hilo es zombie
         * @return TRUE si verifica el estado, FALSE si no lo es
         */
        bool is_zombie() {return state == LVM_THREAD_ZOMBIE; };

        /**
         * @brief Indica si es una hebra hija
         * @return TRUE si lo es, FALSE en otro caso
         */
        bool is_child() const {return child; };

        /**
         * @brief Obtiene la pila de la hebra
         * @return pila
         */
        LVM_Thread_Stack& get_stack() { return stack; };

        /**
         * @brief Obtiene el vector de registros guardado en la hebra
         * @return vector de registros
         */
        std::vector<LVM_Register> get_registers(){ return regs_context; };

        /**
         * @brief Coloca los registros en el contexto de hebra
         * @param reg : registro
         */
        void set_registers(std::vector<LVM_Register> reg) { regs_context = reg;};

        /**
         * @brief Incluye una nueva hija en el vector de hebras hijas
         */
        void set_child_counter(int childs){
            child_counter = childs;
        };

        /**
         * @brief Elimina un hijo
         */
        void remove_child(){
            child_end_counter++;
        };

        /**
         * @brief Comprueba si todas las hebras hijas de la hebra han finalizado
         * @return TRUE si todas han terminado, FALSE en otro caso
         */
        bool childs_have_finished(){
            return child_counter == child_end_counter;
        };
};

#endif //_LAMPORT_LVM_THREAD_DPR_