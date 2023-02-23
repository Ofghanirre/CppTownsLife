cmake_minimum_required(VERSION 3.24)
project(Test1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Test1 main.cpp Npc/Npc.cpp Npc/Npc.h Npc/Races/Human/Human.cpp Npc/Races/Human/Human.h Npc/Races/Elf/Elf.cpp Npc/Races/Elf/Elf.h Npc/Races/Undead/Undead.cpp Npc/Races/Undead/Undead.h Npc/Races/Spirit/Spirit.cpp Npc/Races/Spirit/Spirit.h Village/Village.cpp Village/Village.h)
