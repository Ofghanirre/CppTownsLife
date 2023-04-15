cmake_minimum_required(VERSION 3.16)
project(Test1)

set(CMAKE_CXX_STANDARD 20)

# Trouver les bibliothèques ncurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(Test1 src/main.cpp src/Npc/Npc.cpp src/Npc/Npc.h src/Npc/Races/Human/Human.cpp src/Npc/Races/Human/Human.h src/Npc/Races/Elf/Elf.cpp src/Npc/Races/Elf/Elf.h src/Npc/Races/Undead/Undead.cpp src/Npc/Races/Undead/Undead.h src/Npc/Races/Spirit/Spirit.cpp src/Npc/Races/Spirit/Spirit.h src/Village/Village.cpp src/Village/Village.h src/NpcRelation/RaceRelation.h src/NpcRelation/NpcRelationComputer.h src/NpcRelation/NpcRelationSystem.cpp src/NpcRelation/NpcRelationSystem.h src/NpcRelation/NpcCouple/NpcCouple.cpp src/NpcRelation/NpcCouple/NpcCouple.h src/Logger/Logger.h src/Logger/Logger.cpp src/GameController.cpp src/GameController.h src/utils/RpgDate.cpp src/utils/RpgDate.h src/utils/Displayer.cpp src/utils/Displayer.h src/Npc/Creator/NpcCreator.cpp src/Npc/Creator/NpcCreator.h src/utils/Utils.h src/utils/Utils.h.cpp src/utils/NpcNameGenerator.cpp src/utils/NpcNameGenerator.h)

# Lier les bibliothèques ncurses à votre exécutable
target_link_libraries(Test1 ${CURSES_LIBRARIES})
