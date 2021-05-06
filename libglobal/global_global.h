/*
 * global_global.h
 * Copyright 2021 - ~, Shu Khi No <hernandessukino94@gmail.com>
 *
 * This file is part of Imperion.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef GLOBAL_GLOBAL_H
#define GLOBAL_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef GLOBAL_LIBRARY_STATIC
    #define GLOBALSHARED_EXPORT
#else
    #if defined(GLOBAL_LIBRARY)
        #define GLOBALSHARED_EXPORT Q_DECL_EXPORT
    #else
        #if defined(SINGLEBIN)
            #define GLOBALSHARED_EXPORT
        #else
            #define GLOBALSHARED_EXPORT Q_DECL_IMPORT
        #endif
    #endif
#endif

#endif // GLOBAL_GLOBAL_H
