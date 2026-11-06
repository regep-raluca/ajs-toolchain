cmake_minimum_required(VERSION 3.14)

cmake_policy(SET CMP0091 NEW)

project(expr_prj)

include(ExternalProject)
ExternalProject_Add(antlr4
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../libs/antlr4-cpp-runtime
    BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../libs/antlr4-cpp-runtime/build
    INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../libs/antlr4-cpp-runtime/install
    CMAKE_ARGS "-DCMAKE_POLICY_VERSION_MINIMUM=3.5 -DANTLR4_CMAKE_DIR=${CMAKE_CURRENT_SOURCE_DIR}/../libs/antlr4-cpp-runtime/install2 -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/../libs/antlr4-cpp-runtime/install"
    )

add_custom_command(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/generated/ExprBaseVisitor.cpp ${CMAKE_CURRENT_SOURCE_DIR}/generated/ExprLexer.cpp ${CMAKE_CURRENT_SOURCE_DIR}/generated/ExprParser.cpp ${CMAKE_CURRENT_SOURCE_DIR}/generated/ExprVisitor.cpp 
    COMMAND java -jar ${CMAKE_CURRENT_SOURCE_DIR}/../bin/antlr-4.13.2-complete.jar -Dlanguage=Cpp -visitor -no-listener -o ${CMAKE_CURRENT_SOURCE_DIR}/generated ${CMAKE_CURRENT_SOURCE_DIR}/Expr.g4
    DEPENDS Expr.g4
    COMMENT "Generating parser and lexer with ANTLR4"
	)
	
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../libs/antlr4-cpp-runtime/install/include/antlr4-runtime)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../libs/antlr4-cpp-runtime/install/lib)

add_executable(expr main.cpp 
    generated/ExprBaseVisitor.cpp 
    generated/ExprLexer.cpp
    generated/ExprParser.cpp 
    generated/ExprVisitor.cpp
    )


#set_property(TARGET expr PROPERTY
#    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

if(MSVC)
    target_compile_options(expr PUBLIC "/MT")    
endif()

set_target_properties(expr PROPERTIES
            CXX_STANDARD 17
            )

add_definitions(-DANTLR4CPP_STATIC)

if(MSVC)
    target_link_libraries(expr antlr4-runtime-static)
else()
    target_link_libraries(expr antlr4-runtime)
endif()

add_dependencies(expr antlr4)

if(MSVC)
    add_custom_command(TARGET expr POST_BUILD        # Adds a post-build event to MyTest
        COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different  # which executes "cmake - E copy_if_different..."
            "${CMAKE_CURRENT_SOURCE_DIR}/../libs/antlr4-cpp-runtime/install/bin"      # <--this is in-file
            $<TARGET_FILE_DIR:expr>)                 # <--this is out-file path
endif()
