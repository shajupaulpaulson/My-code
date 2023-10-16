
add_subdirectory("Random")
add_subdirectory("KeyInput")
add_subdirectory("GuessUserInput")

# add the executable
add_executable(Guess_sequence main.cpp Game.cpp)

find_package (Threads)
find_library(LIBRT rt)
if(LIBRT)
   target_link_libraries(Guess_sequence PUBLIC Random KeyInput GuessUserInput ${LIBRT} ${CMAKE_THREAD_LIBS_INIT})
endif()

# add the binary tree to the search path for include files
target_include_directories(Guess_sequence PUBLIC
                          "${CMAKE_CURRENT_SOURCE_DIR}"
                          "${CMAKE_CURRENT_SOURCE_DIR}/Random"
                          "${CMAKE_CURRENT_SOURCE_DIR}/KeyInput"
                          "${CMAKE_CURRENT_SOURCE_DIR}/GuessUserInput")
