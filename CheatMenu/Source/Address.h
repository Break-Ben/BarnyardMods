#pragma once
#include "pch.h"

// Represents a memory address accessible by a pointer chain.
class Address {
  public:
    const char *label;
    std::vector<uintptr_t> pointerChain;

    Address(const char *label, std::vector<uintptr_t> pointerChain);
};

// Represents a floating point memory address accessible by a pointer chain.
class FloatAddress : public Address {
  public:
    float currentValue, defaultValue;

    FloatAddress(const char *label, float defaultValue, std::vector<uintptr_t> pointerChain);

    bool write(float value);
    bool revert();
};