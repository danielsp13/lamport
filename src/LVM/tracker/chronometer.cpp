/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file chronometer.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion de cronometro de eventos en la ejecucion de LVM
 */

#include "LVM/tracker/chronometer.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [CHRONOMETER] -----

void LVM_Tracker_Chronometer::parse_timestamp() {
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(actual_time - start_time);

    // Calcula las horas, minutos y segundos
    auto hours = std::chrono::duration_cast<std::chrono::hours>(duration);
    duration -= hours;
    auto minutes = std::chrono::duration_cast<std::chrono::minutes>(duration);
    duration -= minutes;
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration);
    duration -= seconds;
    auto nanoseconds = duration; // El resto son nanosegundos

    stream << '['
           << std::setfill('0') << std::setw(2) << hours.count() << ':'
           << std::setfill('0') << std::setw(2) << minutes.count() << ':'
           << std::setfill('0') << std::setw(2) << seconds.count() << '.'
           << std::setfill('0') << std::setw(9) << nanoseconds.count() // 9 dígitos para nanosegundos
           << ']';
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [CHRONOMETER] -----

LVM_Tracker_Chronometer& LVM_Tracker_Chronometer::get_instance(){
    static LVM_Tracker_Chronometer instance;
    return instance;
}

void LVM_Tracker_Chronometer::start(){
    if(!running){
        running = true;
        start_time = std::chrono::high_resolution_clock::now();
    }
}

std::string LVM_Tracker_Chronometer::timestamp(){
    if(running){
        actual_time = std::chrono::high_resolution_clock::now();

        parse_timestamp();

        std::string timestamp_str = stream.str();
        stream.clear(); stream.str("");

        return timestamp_str;
    }

    return "[]";
}

void LVM_Tracker_Chronometer::stop(){
    if(running){
        running = false;
    }
}