//
// Created by senyaaa on 4/12/2024.
//
#pragma once

#include <random>
#include <iostream>
#include "NeighborGenerator.hpp"

#ifndef BI_ZUM_2024_POGODARS_SWAPSUBGRIDNEIGHBOR_HPP
#define BI_ZUM_2024_POGODARS_SWAPSUBGRIDNEIGHBOR_HPP


class RandPosFill : public NeighborGenerator{
    void generatorNeighbor(SudokuBoard & state) const override;
};

#endif //BI_ZUM_2024_POGODARS_SWAPSUBGRIDNEIGHBOR_HPP
