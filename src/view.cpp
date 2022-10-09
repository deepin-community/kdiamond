/*
    SPDX-FileCopyrightText: 2008-2010 Stefan Majewsky <majewsky@gmx.net>

    SPDX-License-Identifier: GPL-2.0-or-later
*/

#include "view.h"

#include <QWheelEvent>
#include <KLocalizedString>

KDiamond::View::View(QWidget *parent)
    : QGraphicsView(parent)
{
    setFrameStyle(QFrame::NoFrame);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //optimize rendering
    setOptimizationFlags(QGraphicsView::DontSavePainterState | QGraphicsView::DontAdjustForAntialiasing);
    //"What's this?" context help
    setWhatsThis(i18n("<h3>Rules of Game</h3><p>Your goal is to assemble lines of at least three similar diamonds. Click on two adjacent diamonds to swap them.</p><p>Earn extra points by building cascades, and extra seconds by assembling big lines or multiple lines at one time.</p>"));
}

void KDiamond::View::setScene(QGraphicsScene *scene)
{
    QGraphicsView::setScene(scene);
    resizeEvent(nullptr);
}

void KDiamond::View::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
    //make widget coordinates equal scene coordinates
    scene()->setSceneRect(rect());
    setTransform(QTransform());
}

void KDiamond::View::wheelEvent(QWheelEvent *event)
{
    //do not allow wheel events
    event->ignore();
}
