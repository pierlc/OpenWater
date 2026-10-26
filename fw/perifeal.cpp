#define ISALIB 1
#include <cstdint>

#include "perifeal.hpp"
#include <cstring>

Perifeal::Perifeal(int* faddr, char** fname, int** fpin, char* pname) {
    this->FunctionAddresses = faddr;
    this->FunctionNames = fname;
    this->FunctionPins = fpin;
    this->PerifealName = pname;
}

int Perifeal::GetFunctionAddress(char* FunctionName) {
    int index = GetFunctionIndex(FunctionName);
    if (index == -1) {
        return -1;
    }
    return this->FunctionAddresses[index];
}

// Returns the index of the function with the given name in the FunctionNames array, or -1 if not found.
int Perifeal::GetFunctionIndex(char* FunctionName) {
    for (int i = 0; this->FunctionNames[i] != nullptr; i++) {
        if (strcmp(this->FunctionNames[i], FunctionName) == 0) {
            return i;
        }
    }
    return -1;
}

int* Perifeal::GetFunctionPins(char* FunctionName) {
    int index = GetFunctionIndex(FunctionName);
    if (index == -1) {
        return nullptr;
    }
    return this->FunctionPins[index];
}


// Calls the function apresent in the FunctionAddresses array with the given name and passes the corresponding pins as an argument.

void Perifeal::act(char* cname) {
    int index = GetFunctionIndex(cname);
    if (index == -1) {
        return;
    }
    int address = this->FunctionAddresses[index];
    int* pins = this->FunctionPins[index];

    std::uintptr_t RawAddress = static_cast<std::uintptr_t>(address);
    using FunctionType = void(*)(void*);
    FunctionType Function = reinterpret_cast<FunctionType>(RawAddress);
    Function(pins);
}
