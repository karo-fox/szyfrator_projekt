cmake_minimum_required(VERSION 3.10)
project(Szyfrator VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(
    "${PROJECT_SOURCE_DIR}/szyfrator_c++"
    "${PROJECT_SOURCE_DIR}/szyfrator_c++/Ciphers"
    "${PROJECT_SOURCE_DIR}/szyfrator_c++/Ciphers/CeasarCipher"
    "${PROJECT_SOURCE_DIR}/szyfrator_c++/Ciphers/FourSquareCipher"
    "${PROJECT_SOURCE_DIR}/szyfrator_c++/Ciphers/RailFenceCipher"
    "${PROJECT_SOURCE_DIR}/szyfrator_c++/Ciphers/VigenereCipher"
    "${PROJECT_SOURCE_DIR}/szyfrator_c++/Exceptions"
    "${PROJECT_SOURCE_DIR}/szyfrator_c++/UI"
    "${PROJECT_SOURCE_DIR}/szyfrator_c++/UI/Lang"
    "${PROJECT_SOURCE_DIR}/szyfrator_c++/UI/Screens"
    "${PROJECT_SOURCE_DIR}/szyfrator_c++/UI/Screens/MainScreen"
    "${PROJECT_SOURCE_DIR}/szyfrator_c++/UI/Screens/SettingsScreen"
)
find_package(fmt REQUIRED)

file(GLOB_RECURSE SOURCES
    "${PROJECT_SOURCE_DIR}/szyfrator_c++/*.cpp"
    "${PROJECT_SOURCE_DIR}/szyfrator_c++/Ciphers/*.cpp"
    "${PROJECT_SOURCE_DIR}/szyfrator_c++/Ciphers/CeasarCipher/*.cpp"
    "${PROJECT_SOURCE_DIR}/szyfrator_c++/Ciphers/FourSquareCipher/*.cpp"
    "${PROJECT_SOURCE_DIR}/szyfrator_c++/Ciphers/RailFenceCipher/*.cpp"
    "${PROJECT_SOURCE_DIR}/szyfrator_c++/Ciphers/VigenereCipher/*.cpp"
    "${PROJECT_SOURCE_DIR}/szyfrator_c++/Exceptions/*.cpp"
    "${PROJECT_SOURCE_DIR}/szyfrator_c++/UI/*.cpp"
    "${PROJECT_SOURCE_DIR}/szyfrator_c++/UI/Lang/*.cpp"
    "${PROJECT_SOURCE_DIR}/szyfrator_c++/UI/Screens/*.cpp"
    "${PROJECT_SOURCE_DIR}/szyfrator_c++/UI/Screens/MainScreen/*.cpp"
    "${PROJECT_SOURCE_DIR}/szyfrator_c++/UI/Screens/SettingsScreen/*.cpp"
)
add_executable(Szyfrator "${SOURCES}")
target_link_libraries(Szyfrator fmt::fmt)