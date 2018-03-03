add_library(evmexec SHARED EthVM.cpp EthVM.h main.cpp)

#set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--export-all-symbols")

target_link_libraries(evmexec ethereum evm ethashseal devcore)

target_include_directories(evmexec PRIVATE ../utils)
