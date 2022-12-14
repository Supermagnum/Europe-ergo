// Copyright 2022 Supermagnum (@Supermagnum)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#include "quantum.h"


#define XXX KC_NO

#define LAYOUT_6x9( \
    L00, L01, L02, L03, L04, L05, L06,            /**/            R06, R05, R04, R03, R02, R01, R00, \
    L10, L11, L12, L13, L14, L15, L16, L17,       /**/       R17, R16, R15, R14, R13, R12, R11, R10, \
    L20, L21, L22, L23, L24, L25, L26, L27,       /**/       R27, R26, R25, R24, R23, R22, R21, R20, \
    L30, L31, L32, L33, L34, L35, L36,            /**/            R36, R35, R34, R33, R32, R31, R30, \
    L40, L41, L42, L43, L44, L45, L46, L47,       /**/       R47, R46, R45, R44, R43, R42, R41, R40, \
    L50, L51, L52, L53, L54,                      /**/                      R54, R53, R52, R51, R50, \
                                       L48,       /**/       R48,                                    \
                                  L55, L57, L58,  /**/  R58, R57, R55                                \
    ) \
    { \
        { L00, L01, L02, L03, L04, L05, L06, XXX, XXX }, \
        { L10, L11, L12, L13, L14, L15, L16, L17, XXX }, \
        { L20, L21, L22, L23, L24, L25, L26, L27, XXX }, \
        { L30, L31, L32, L33, L34, L35, L36, XXX, XXX }, \
        { L40, L41, L42, L43, L44, L45, L46, L47, L48 }, \
        { L50, L51, L52, L53, L54, L55, XXX, L57, L58 }, \
\
        { XXX, XXX, R06, R05, R04, R03, R02, R01, R00 }, \
        { XXX, R17, R16, R15, R14, R13, R12, R11, R10 }, \
        { XXX, R27, R26, R25, R24, R23, R22, R21, R20 }, \
        { XXX, XXX, R36, R35, R34, R33, R32, R31, R30 }, \
        { R48, R47, R46, R45, R44, R43, R42, R41, R40 }, \
        { R58, R57, XXX, R55, R54, R53, R52, R51, R50 }, \
}
