project (GuessUserInput)

add_library(GuessUserInput "inc/GuessUserInputMessagereceive.h" "src/GuessUserInputMessagereceive.cpp"
            "inc/GuessUserInputAlgorthim.h" "src/GuessUserInputAlgorthim.cpp" )
include_directories("${CMAKE_CURRENT_SOURCE_DIR}")
