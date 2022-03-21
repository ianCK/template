#pragma once

template <typename T, T (*oper)(T, T)> void SOS(int tot, T* arr);

#include "SOS.ipp"
