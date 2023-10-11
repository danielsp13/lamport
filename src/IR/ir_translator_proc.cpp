/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_translator_proc.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion del constructor de codigo intermedio Lineal para PROCESOS (IR)
 */

#include "IR/ir_translator_proc.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [IR_Translator_Process] -----

void IR_Translator_Process::translate_process_to_ir_instructions(struct process * proc){
    // 8. Emitir instruccion de inicio de proceso
    instructions.emit_instruction(IR_START_PROCESS);

    // 1. Obtener nombre de proceso
    std::string id_label_block = instructions.get_next_label_id();
    std::string proc_name = std::string(proc->name_process);

    // 2. Registrar proceso como una variable (de scope global)
    int id_process_in_table = tables.add_entry_variable(IR_VAR_GLOBAL,proc_name,IR_VAR_TYPE_PROCESS);

    // 3. Generar etiqueta de entrada de proceso
    int id_label_in_table = tables.add_entry_label(std::string("start_proc_") + proc_name + "(" + id_label_block + ")",instructions.size()+1);

    // 4. Emitir instruccion de punto de entrada de proceso
    IR_operand op_label = instructions.emit_operand_label(id_label_in_table);

    instructions.emit_instruction(IR_LABEL,op_label);

    // 5. Traducir declaraciones de proceso
    if(proc->declarations)
        decl_translator.translate(proc->declarations);

    // 6. Traducir sentencias de proceso
    // TODO .. COMPROBAR SI EL BLOQUE DE SENTENCIAS ES COBEGIN
    if(proc->statements)
        stmt_translator.translate(proc->statements);

    // 7. Generar etiqueta de fin de proceso
    id_label_in_table = tables.add_entry_label(std::string("end_proc_") + proc_name + "(" + id_label_block + ")",instructions.size()+1);

    // 4. Emitir instruccion de punto de entrada de proceso
    op_label = instructions.emit_operand_label(id_label_in_table);

    instructions.emit_instruction(IR_LABEL,op_label);

    // 8. Emitir instruccion de fin de proceso
    instructions.emit_instruction(IR_END_PROCESS);
}

void IR_Translator_Process::translate_list_process_to_ir_instructions(struct process * list_proc){
    struct process *current_proc = list_proc;
    while(current_proc != NULL){
        // -- Traducir declaracion
        this->translate_process_to_ir_instructions(current_proc);
        // -- Ir a siguiente declaracion
        current_proc = current_proc->next;
    }
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [IR_Translator_Process] -----

IR_Translator_Process& IR_Translator_Process::get_instance(){
    static IR_Translator_Process instance;
    return instance;
}

void IR_Translator_Process::translate(struct process * list_proc){
    this->translate_list_process_to_ir_instructions(list_proc);
}