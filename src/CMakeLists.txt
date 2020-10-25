add_library(TerminalDisplaySources
        Dummy.h
        Dummy.cpp)
add_subdirectory(Frame)
target_link_libraries(TerminalDisplaySources Frame)