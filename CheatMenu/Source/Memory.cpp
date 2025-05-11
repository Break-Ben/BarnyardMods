#include "pch.h"

#include "Memory.h"

// Checks if the given pointer is valid and accessible.
bool isValidPtr(const void *ptr) {
    MEMORY_BASIC_INFORMATION mbi;
    return VirtualQuery(ptr, &mbi, sizeof(mbi)) &&
           mbi.State == MEM_COMMIT &&
           !(mbi.Protect & (PAGE_NOACCESS | PAGE_GUARD));
}