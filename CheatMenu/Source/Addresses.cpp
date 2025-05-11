#include "pch.h"

#include "Addresses.h"

std::vector<FloatAddress> *movementCheats;

void initAddresses() {
    movementCheats = new std::vector<FloatAddress>{
        FloatAddress("Walk Speed", 1.5f, {0x78A890, 0x54, 0xA84, 0xBC, 0x100}),
        FloatAddress("Run Speed", 4.0f, {0x78A890, 0x54, 0xA84, 0xBC, 0x104}),
        FloatAddress("Sprint Speed", 7.0f, {0x78A890, 0x54, 0xA84, 0xBC, 0x108}),
        FloatAddress("Jump Force", 8.5f, {0x78A890, 0x54, 0xA84, 0xBC, 0x124}),
        FloatAddress("Acceleration", 10.0f, {0x78A890, 0x54, 0xA84, 0xBC, 0x0D8}),
        FloatAddress("Deceleration", 30.0f, {0x78A890, 0x54, 0xA84, 0xBC, 0x0DC})};
}

void deleteAddresses() {
    delete movementCheats;
}