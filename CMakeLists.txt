cmake_minimum_required(VERSION 3.16)
project(Test1)

add_custom_target(install_${PROJECT_NAME}
        $(MAKE) install
        DEPENDS ${PROJECT_NAME}
        COMMENT "Installing ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Werror)

# Trouver les bibliothèques ncurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(Test1
        src/main.cpp
        # NPC:
        src/Npc/Npc.cpp src/Npc/Npc.h
        src/Npc/Races/ERace.cpp src/Npc/Races/ERace.h
        src/Npc/EGender.cpp src/Npc/EGender.h
        src/Npc/ELifeState.cpp src/Npc/ELifeState.h
        src/Npc/Creator/NpcCreator.cpp src/Npc/Creator/NpcCreator.h
        # NPC SUBTYPE:
            src/Npc/Races/Human/Human.cpp src/Npc/Races/Human/Human.h
            src/Npc/Races/Elf/Elf.cpp src/Npc/Races/Elf/Elf.h
            src/Npc/Races/Undead/Undead.cpp src/Npc/Races/Undead/Undead.h
            src/Npc/Races/Spirit/Spirit.cpp src/Npc/Races/Spirit/Spirit.h

        # VILLAGE:
        src/Village/Village.cpp src/Village/Village.h

        # NPC RELATION :
        src/NpcRelation/RaceRelation.h
        src/NpcRelation/NpcRelationComputer.h
        src/NpcRelation/NpcRelationSystem.cpp src/NpcRelation/NpcRelationSystem.h
        src/NpcRelation/NpcCouple/NpcCouple.cpp src/NpcRelation/NpcCouple/NpcCouple.h

        # UTILS
        src/utils/Utils.h src/utils/Utils.h.cpp
        src/utils/RpgDate.cpp src/utils/RpgDate.h
        src/utils/Displayer.cpp src/utils/Displayer.h
        src/utils/NpcNameGenerator.cpp src/utils/NpcNameGenerator.h

        # OTHERS
        src/Logger/Logger.h src/Logger/Logger.cpp

        # GAME CONTROLLER
        src/GameController.cpp src/GameController.h
        src/PlayerActions/EPlayerActions.cpp src/PlayerActions/EPlayerActions.h
        src/PlayerActions/PlayerAction.cpp src/PlayerActions/PlayerAction.h
)

# Lier les bibliothèques ncurses à votre exécutable
target_link_libraries(Test1 ${CURSES_LIBRARIES})
