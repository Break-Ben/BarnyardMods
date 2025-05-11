#pragma once
#include "pch.h"

bool isValidPtr(const void *ptr);

// Returns a pointer to a memory address using a chain of offsets. Returns nullptr if the chain is invalid.
template <typename T>
T *getMem(const std::vector<uintptr_t> &pointerChain) {
    uintptr_t pointer = pointerChain[0];
    for (int i = 1; i < pointerChain.size(); i++) {
        uintptr_t *address = reinterpret_cast<uintptr_t *>(pointer);
        if (!isValidPtr((void *)address)) {
            return nullptr;
        }
        pointer = *address + pointerChain[i];
    }
    return reinterpret_cast<T *>(pointer);
}

// Tries to write a value to a memory address. Returns false if the address is invalid.
template <typename T>
bool writeMem(T value, const std::vector<uintptr_t> &pointerChain) {
    T *pointer = getMem<T>(pointerChain);
    if (pointer != nullptr) {
        *pointer = value;
        return true;
    }
    return false;
}