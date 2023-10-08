/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file lmp_lvm_launcher.hpp
 * @author Daniel Perez Ruiz
 * @brief Gestor de maquina virtual de interprete lamport
 */

#ifndef _LMP_INTERPRETER_LVM_LAUNCHER_DPR_
#define _LMP_INTERPRETER_LVM_LAUNCHER_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include "LVM/LVM.hpp"              ///< Maquina virtual
#include "lmp_tasker.hpp"           ///< Notificador de eventos

// ===============================================================

// ----- DEFINICION DE CLASE GESTORA DE MAQUINA VIRTUAL -----

class LMP_LVM_Launcher{
    private:
        // -- Notificador de tareas
        LMP_Tasker& tasker = LMP_Tasker::get_instance();
        // -- Maquina virtual
        LVM& lvm = LVM::get_instance();

        /**
         * @brief Constructor por defecto
         */
        LMP_LVM_Launcher() {};
    public:
        /**
         * @brief Obtiene la instancia del manejador
         * @return instancia
         */
        static LMP_LVM_Launcher& get_instance();

        /**
         * @brief Prepara la memoria de la maquina virtual para
         * su ejecucion
         * @param verbose_avaiable : flag de impresion de contenido
         * @return codigo de resultado de operacion
         */
        int preload_lvm(bool verbose_avaiable);

        /**
         * @brief Ejecuta la maquina virtual
         * @return codigo de resultado de operacion
         */
        int start();
};

#endif //_LMP_INTERPRETER_LVM_LAUNCHER_DPR_