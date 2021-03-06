/**************************************************************************
** This file is part of LiteIDE
**
** Copyright (c) 2011-2017 LiteIDE. All rights reserved.
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License as published by the Free Software Foundation; either
** version 2.1 of the License, or (at your option) any later version.
**
** This library is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
** Lesser General Public License for more details.
**
** In addition, as a special exception,  that plugins developed for LiteIDE,
** are allowed to remain closed sourced and can be distributed under any license .
** These rights are included in the file LGPL_EXCEPTION.txt in this package.
**
**************************************************************************/
// Module: libucd.h
// Creator: visualfc <visualfc@gmail.com>

#ifndef LIBUCD_H
#define LIBUCD_H

#include "libucd/include/libucd.h"
#include <QByteArray>

class LibUcd
{
public:
    LibUcd()
    {
        ucd_init(&t);
    }
    ~LibUcd()
    {
        ucd_clear(&t);
    }
    QByteArray parse(const QByteArray &data)
    {
        int r = ucd_parse(&t,data.constData(),data.size());
        ucd_end(&t);
        char name[128] = {0};
        if (r == UCD_RESULT_OK) {
            ucd_results(&t,name,127);
        }
        ucd_reset(&t);
        return name;
    }
protected:
    ucd_t t;
};


#endif // LIBUCD_H
