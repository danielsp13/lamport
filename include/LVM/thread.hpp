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

#include "stack_block.hpp"  ///< Bloques de pila
#include "register.hpp"     ///< Registro LVM

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
        
        // -- Contexto de registros de CPU de la hebra
        std::vector<LVM_Register> regs_context;
        // -- Pila de la hebra
        std::stack<LVM_Stack_Block> stack;

        // -- Contador de instrucciones ejecutadas por la hebra
        int instruction_counter = 0;
        // -- Quantum asociado a la hebra
        int quantum = 0;

        // -- Vector de hebras hijas
        std::vector<LVM_Thread *> childs;

        // -- Flag que comprueba si el thread ha entrado en una seccion critica
        bool in_atomic = false;

        // --------------- Hebras hijas

        // -- Flag que indica que el thread es un hijo
        bool child = false;

        // -- Puntero a hebra padre
        LVM_Thread * parent = nullptr;
    public:
        /**
         * @brief Crea e inicializa un nuevo hilo
         * @param id : identificador de hilo
         * @param pc : contador de programa
         * @param segment_addr : direccion de segmento virtual
         */
        LVM_Thread(int id, int pc, int segment_addr)
            : id(id), program_counter(pc), segment_address(segment_addr), state(LVM_THREAD_NEW) {};

        /**
         * @brief Crea e inicializa un nuevo hilo hijo
         * @param id : identificador de hilo
         * @param pc : contador de programa
         * @param segment_addr : direccion de segmento virtual
         * @param parent : puntero a hebra padre
         */
        LVM_Thread(int id, int pc, int segment_addr, LVM_Thread * parent)
            : id(id), program_counter(pc), segment_address(segment_addr), state(LVM_THREAD_NEW), child(true), parent(parent) {};

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
         * @brief Inserta una pila en la hebra
         * @param st : hebra
         */
        void set_stack(std::stack<LVM_Stack_Block> st){ stack = st;};

        /**
         * @brief Obtiene la pila de la hebra
         * @return pila
         */
        std::stack<LVM_Stack_Block> get_stack() { return stack; };

        /**
         * @brief Inserta un vector de registros en la hebra
         * @param v : vector
         */
        void set_registers(std::vector<LVM_Register> v){ regs_context = v; };

        /**
         * @brief Obtiene el vector de registros guardado en la hebra
         * @return vector de registros
         */
        std::vector<LVM_Register> get_registers(){ return regs_context; };

        /**
         * @brief Incluye una nueva hija en el vector de hebras hijas
         * @param child_thread : hebra hija
         */
        void set_child(LVM_Thread * child_thread){
            childs.push_back(child_thread);
        };

        /**
         * @brief Elimina un hijo
         * @param child_thread : hebra hija a eliminar
         */
        void remove_child(LVM_Thread * child_thread){
            std::vector<LVM_Thread*> aux_threads;
            for(int i=0; i<childs.size(); i++){
                if(childs[i]->get_id() != child_thread->get_id()){
                    aux_threads.push_back(childs[i]);
                }
            }

            childs = aux_threads;
        };

        /**
         * @brief Comprueba si todas las hebras hijas de la hebra han finalizado
         * @return TRUE si todas han terminado, FALSE en otro caso
         */
        bool childs_has_finished(){
            return childs.size() == 0;
        };
};

#endif //_LAMPORT_LVM_THREAD_DPR_