cmake_minimum_required(VERSION 3.16)

project(Projeto_Parte2_Oficial LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Projeto_Parte2_Oficial main.cpp
    sculptor.h sculptor.cpp
    figurageometrica.h
    putvoxel.h putvoxel.cpp
    voxel.h
    cutvoxel.h cutvoxel.cpp
    putbox.h putbox.cpp
    cutbox.h cutbox.cpp
    putsphere.h putsphere.cpp
    cutsphere.h cutsphere.cpp
    putelipsoide.h putelipsoide.cpp
    cutelipsoide.h cutelipsoide.cpp
    leituraarquivo.h leituraarquivo.cpp
    arquivo/arquivo.txt

)

include(GNUInstallDirs)
install(TARGETS Projeto_Parte2_Oficial
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
