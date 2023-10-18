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

// ===============================================================

// ----- DEFINICION DE ESTADOS DE HILO -----

/**
 * @brief Enumerado que representa los diferentes estados de los
 * hilos del sistema
 */
typedef enum{
    LVM_THREAD_NEW,         ///< Se acaba de crear el hilo
    LVM_THREAD_READY,       ///< El hilo esta listo para ejecucion
    LVM_THREAD_RUNNING,     ///< El hilo esta ejecutando
    LVM_THREAD_BLOCKED,     ///< El hilo esta bloqueado
    LVM_THREAD_TERMINATED,   ///< El hilo ha terminado
    LVM_THREAD_ZOMBIE,      ///< El hilo esta zombie
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

        // -- Flag que indica si ejecuto la instruccion determinada
        bool finished_instruction = false;
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
         * @brief Destrutor de hilo
         */
        ~LVM_Thread() = default;

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
         * @brief Indica que la hebra ha terminado de ejecutar la instruccion 
         * que le corresponde (ha terminado su tiempo en CPU)
         */
        void instruction_finished() { finished_instruction = true; };

        /**
         * @brief Comprueba si la hebra ha terminado de ejecutar la instruccion
         * que le corresponde
         */
        bool has_finished_instruction() const { return this->finished_instruction; } ;

        /**
         * @brief Resetea el flag de controlador de ejecucion de thread
         */
        void reset_instruction_flag() { finished_instruction = false; };
};

#endif //_LAMPORT_LVM_THREAD_DPR_