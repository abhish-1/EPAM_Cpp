#include <iostream>
#include <csignal>
#ifdef __linux__
#include <execinfo.h>
#endif
void crashHandler(int sig) {
    std::cerr << "Caught signal " << sig << "! (segmentation fault)" << std::endl;
#ifdef __linux__
    void *array[50];
    int size = backtrace(array, 50);
    std::cerr << "Stack trace:" << std::endl;
    backtrace_symbols_fd(array, size, STDERR_FILENO);
#endif
    std::_Exit(1); // Exit immediately
}
int main() {
    signal(SIGSEGV, crashHandler);

    int* ptr = nullptr;
    *ptr = 10; // Deliberately trigger SIGSEGV

    return 0;
}
