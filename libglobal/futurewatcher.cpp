/*
 * futurewatcher.cpp
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
#include "futurewatcher.h"

using namespace LibG;

FutureWatcher::FutureWatcher(QObject *parent) :
    QObject(parent),
    mWatcher(new QFutureWatcher<Message>(this))
{
    connect(mWatcher, SIGNAL(finished()), SLOT(finished()));
}

void FutureWatcher::setFuture(const QFuture<LibG::Message> &future)
{
    mWatcher->setFuture(future);
}

void FutureWatcher::finished()
{
    Message msg = mWatcher->result();
    emit messageReceived(&msg);
    this->deleteLater();
}
