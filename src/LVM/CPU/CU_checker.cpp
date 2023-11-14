/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file CU_checker.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion del de instrucciones de Unidad de Control (CU) de CPU para la maquina virtual de lamport
 */

#include "LVM/CPU/CU_checker.hpp"


// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [CU_Checker] -----

inline void LVM_CPU_CU_Checker::check_label_pointer(IR_instruction_type_t instr_code){
    if(!instr_decoded){
        label_pointer = instr_code == IR_LABEL;

        instr_decoded = label_pointer;
    }
}

inline void LVM_CPU_CU_Checker::check_start_program(IR_instruction_type_t instr_code){
    if(!instr_decoded){
        start_program = instr_code == IR_START_PROGRAM;

        instr_decoded = start_program;
    }
}

inline void LVM_CPU_CU_Checker::check_end_program(IR_instruction_type_t instr_code){
    if(!instr_decoded){
        end_program = instr_code == IR_END_PROGRAM;

        instr_decoded = end_program;
    }
}

inline void LVM_CPU_CU_Checker::check_initalize_var_global(IR_instruction_type_t instr_code){
    if(!instr_decoded){
        start_initialize_global_var = instr_code == IR_INITIALIZE_GLOBAL_VAR;
        
        instr_decoded = start_initialize_global_var;
    }
}

inline void LVM_CPU_CU_Checker::check_end_initialize_var_global(IR_instruction_type_t instr_code){
    if(!instr_decoded){
        end_initialize_global_var = instr_code == IR_END_INITIALIZE_GLOBAL_VAR;
        
        instr_decoded = end_initialize_global_var;
    }
}

inline void LVM_CPU_CU_Checker::check_start_process(IR_instruction_type_t instr_code){
    if(!instr_decoded){
        start_process = instr_code == IR_START_PROCESS;

        instr_decoded = start_process;
    }
}

inline void LVM_CPU_CU_Checker::check_end_process(IR_instruction_type_t instr_code){
    if(!instr_decoded){
        end_process = instr_code == IR_END_PROCESS;

        instr_decoded = end_process;
    }
}

inline void LVM_CPU_CU_Checker::check_load_operation(IR_instruction_type_t instr_code){
    if(!instr_decoded){
        load_operation = instr_code == IR_OP_LOAD;

        instr_decoded = load_operation;
    }
}

inline void LVM_CPU_CU_Checker::check_store_operation(IR_instruction_type_t instr_code){
    if(!instr_decoded){
        store_operation = instr_code == IR_OP_STORE;

        instr_decoded = store_operation;
    }
}

inline void LVM_CPU_CU_Checker::check_ALU_binary_operation(IR_instruction_type_t instr_code){
    if(!instr_decoded){
        ALU_operation_binary = instr_code == IR_OP_ADD_I || instr_code == IR_OP_ADD_F
        || instr_code == IR_OP_SUB_I || instr_code == IR_OP_SUB_F
        || instr_code == IR_OP_MULT_I || instr_code == IR_OP_MULT_F
        || instr_code == IR_OP_DIV_I || instr_code == IR_OP_DIV_F
        || instr_code == IR_OP_MOD_I
        || instr_code == IR_OP_CMP_GTE 
        || instr_code == IR_OP_CMP_GT
        || instr_code == IR_OP_CMP_LTE
        || instr_code == IR_OP_CMP_LT
        || instr_code == IR_OP_CMP_EQ
        || instr_code == IR_OP_CMP_NEQ
        || instr_code == IR_OP_AND
        || instr_code == IR_OP_OR;

        instr_decoded = ALU_operation_binary;
    }
}

inline void LVM_CPU_CU_Checker::check_ALU_unary_operation(IR_instruction_type_t instr_code){
    if(!instr_decoded){
        ALU_operation_unary = instr_code == IR_OP_NEG_I || instr_code == IR_OP_NEG_F
        || instr_code == IR_OP_NOT;

        instr_decoded = ALU_operation_unary;
    }
}

inline void LVM_CPU_CU_Checker::check_jump_operation(IR_instruction_type_t instr_code){
    if(!instr_decoded){
        jmp_operation_unconditional = instr_code == IR_OP_JMP;

        instr_decoded = jmp_operation_unconditional;
    }
    if(!instr_decoded){
        jmp_operation_conditional = instr_code == IR_OP_JMP_TRUE
        || instr_code == IR_OP_JMP_FALSE;

        instr_decoded = jmp_operation_conditional;
    }
}

inline void LVM_CPU_CU_Checker::check_push_operation(IR_instruction_type_t instr_code){
    if(!instr_decoded){
        push_operation = instr_code == IR_OP_PUSH;

        instr_decoded = push_operation;
    }
}

inline void LVM_CPU_CU_Checker::check_pop_operation(IR_instruction_type_t instr_code){
    if(!instr_decoded){
        pop_operation = instr_code == IR_OP_POP;

        instr_decoded = pop_operation;
    }
}

inline void LVM_CPU_CU_Checker::check_call_operation(IR_instruction_type_t instr_code){
    if(!instr_decoded){
        call_operation = instr_code == IR_OP_CALL;

        instr_decoded = call_operation;
    }
}

inline void LVM_CPU_CU_Checker::check_ret_operation(IR_instruction_type_t instr_code){
    if(!instr_decoded){
        ret_operation = instr_code == IR_OP_RET;

        instr_decoded = ret_operation;
    }
}

inline void LVM_CPU_CU_Checker::check_system_call(IR_instruction_type_t instr_code){
    if(!instr_decoded){
        system_call_operation = instr_code == IR_OP_ATOMIC_BEGIN
        || instr_code == IR_OP_ATOMIC_END
        || instr_code == IR_OP_COBEGIN
        || instr_code == IR_OP_COEND
        || instr_code == IR_START_DYNAMIC_PROCESS
        || instr_code == IR_WAIT_PROCESS
        || instr_code == IR_SLEEP_PROCESS
        || instr_code == IR_OP_SEM_WAIT
        || instr_code == IR_OP_SEM_SIGNAL
        || instr_code == IR_OP_PRINT
        || instr_code == IR_END_PRINT;

        instr_decoded = system_call_operation;
    }
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [CU_Checker] -----

LVM_CPU_CU_Checker& LVM_CPU_CU_Checker::get_instance(){
    static LVM_CPU_CU_Checker instance;
    return instance;
}

void LVM_CPU_CU_Checker::check(IR_instruction_type_t instr_code){
    check_label_pointer(instr_code);
    check_start_program(instr_code);
    check_end_program(instr_code);
    check_initalize_var_global(instr_code);
    check_end_initialize_var_global(instr_code);
    check_start_process(instr_code);
    check_end_process(instr_code);
    check_load_operation(instr_code);
    check_store_operation(instr_code);
    check_ALU_binary_operation(instr_code);
    check_ALU_unary_operation(instr_code);
    check_jump_operation(instr_code);
    check_push_operation(instr_code);
    check_pop_operation(instr_code);
    check_call_operation(instr_code);
    check_ret_operation(instr_code);
    check_system_call(instr_code);
}

void LVM_CPU_CU_Checker::reset_flags(){
    instr_decoded = false;

    label_pointer = false;
    start_program = false;
    end_program = false;
    start_initialize_global_var = false;
    end_initialize_global_var = false;
    start_process = false;
    end_process = false;
    load_operation = false;
    store_operation = false;
    ALU_operation_binary = false;
    ALU_operation_unary = false;
    jmp_operation_unconditional = false;
    jmp_operation_conditional = false;
    push_operation = false;
    pop_operation = false;
    call_operation = false;
    ret_operation = false;
    system_call_operation = false;
}