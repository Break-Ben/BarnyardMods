#include "pch.h"

#include "Address.h"
#include "Memory.h"

Address::Address(const char *label, std::vector<uintptr_t> pointerChain)
    : label(label), pointerChain(std::move(pointerChain)) {}

FloatAddress::FloatAddress(const char *label, float defaultValue, std::vector<uintptr_t> pointerChain)
    : Address(label, std::move(pointerChain)), currentValue(defaultValue), defaultValue(defaultValue) {}

bool FloatAddress::write(float value) {
    currentValue = value;
    return writeMem(value, pointerChain);
}

bool FloatAddress::revert() {
    currentValue = defaultValue;
    return writeMem(defaultValue, pointerChain);
}