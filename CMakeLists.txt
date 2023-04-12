cmake_minimum_required(VERSION 3.16)
# ---------- FILES ----------
file(MAKE_DIRECTORY lib)
file(GLOB HEADER_LIST inc/*.h)
file(GLOB SRC_LIST src/*.c)

# ---------- SETS ----------
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

# ---------- OPTIONS ----------


project(Ctest DESCRIPTION "Ctest is gtest on C")
include_directories(inc)

add_library(Ctest SHARED ${SRC_LIST})

set_target_properties(Ctest PROPERTIES VERSION ${PROJECT_VERSION})

configure_file(Ctest.pc.in Ctest.pc @ONLY)

install(TARGETS Ctest
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION  ${CMAKE_INSTALL_INCLUDEDIR})

install(FILES ${HEADER_LIST} DESTINATION include ${CMAKE_INSTALL_INCLUDEDIR} )
install(FILES ${CMAKE_BINARY_DIR}/Ctest.pc 
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

install(FILES cmake/CtestConfig.cmake DESTINATION lib/cmake/Ctest)
