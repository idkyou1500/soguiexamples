/**************************************************************************\
 *
 *  This file is part of a set of example programs for the Coin library.
 *  Copyright (C) 2000-2003 by Systems in Motion. All rights reserved.
 *
 *                   <URL:http://www.coin3d.org>
 *
 *  This sourcecode can be redistributed and/or modified under the
 *  terms of the GNU General Public License version 2 as published by
 *  the Free Software Foundation. See the file COPYING at the root
 *  directory of the distribution for more details.
 *
 *  As a special exception, all sourcecode of the demo examples can be
 *  used for any purpose for licensees of the Coin Professional
 *  Edition License, without the restrictions of the GNU GPL. See our
 *  web pages for information about how to acquire a Professional Edition
 *  License.
 *
 *  Systems in Motion, <URL:http://www.sim.no>, <mailto:support@sim.no>
 *
\**************************************************************************/

#include "TransferFunctionHandler.h"
#include <SoTransferFunction_ctrl.h>

#include <qvalidator.h>
#include <qlineedit.h>
#include <qcombobox.h>

#include <VolumeViz/nodes/SoTransferFunction.h>

#include "Cute/SoQtGradientDialog.h"

// *************************************************************************

TransferFunctionHandler::TransferFunctionHandler(SoTransferFunction * node,
                                                 int remaplow, int remaphigh,
                                                 QWidget * parent)
{
  this->node = node;

  // FIXME: should better place a sensor on it and detect when the
  // node is dying. 20021211 mortene.
  this->node->ref();

  this->ctrl = new SoTransferFunction_ctrl(parent);
  this->ctrl->show();

  this->remap[0] = remaplow;
  this->remap[1] = remaphigh;

  this->initGUI();

  this->gradientdialog = NULL;
}

TransferFunctionHandler::~TransferFunctionHandler()
{
  this->node->unref();
  delete this->gradientdialog;
}

void
TransferFunctionHandler::initGUI(void)
{
  // "reMap" lineedits

  QIntValidator * v = new QIntValidator(0, 255, new QObject);

  this->ctrl->lowEdit->setValidator(v);
  this->ctrl->highEdit->setValidator(v);

  QString s;
  s.sprintf("%d", this->remap[0]);
  this->ctrl->lowEdit->setText(s);
  s.sprintf("%d", this->remap[1]);
  this->ctrl->highEdit->setText(s);

  QObject::connect(this->ctrl->lowEdit, SIGNAL(returnPressed()),
                   this, SLOT(lowEditUpdate()));

  QObject::connect(this->ctrl->highEdit, SIGNAL(returnPressed()),
                   this, SLOT(highEditUpdate()));


  // predefColorMap combobox

  this->ctrl->predefCombo->setCurrentItem(this->node->predefColorMap.getValue());

  QObject::connect(this->ctrl->predefCombo, SIGNAL(activated(int)),
                   this, SLOT(predefColorMapUpdate(int)));


  // "shift" & "offset" lineedits

  v = new QIntValidator(-32767, 32767, new QObject);

  this->ctrl->shiftEdit->setValidator(v);
  this->ctrl->offsetEdit->setValidator(v);

  s.sprintf("%d", this->node->shift.getValue());
  this->ctrl->shiftEdit->setText(s);
  s.sprintf("%d", this->node->offset.getValue());
  this->ctrl->offsetEdit->setText(s);

  QObject::connect(this->ctrl->shiftEdit, SIGNAL(returnPressed()),
                   this, SLOT(shiftEditUpdate()));

  QObject::connect(this->ctrl->offsetEdit, SIGNAL(returnPressed()),
                   this, SLOT(offsetEditUpdate()));

}

void
TransferFunctionHandler::lowEditUpdate(void)
{
  this->remap[0] = this->ctrl->lowEdit->text().toInt();
  assert(this->remap[0] <= this->remap[1] && "must be <= the high value");

  this->node->reMap(this->remap[0], this->remap[1]);
}

void
TransferFunctionHandler::highEditUpdate(void)
{
  this->remap[1] = this->ctrl->highEdit->text().toInt();
  assert(this->remap[1] >= this->remap[0] && "must be >= the low value");

  this->node->reMap(this->remap[0], this->remap[1]);
}

void
TransferFunctionHandler::gradientCallback(const Gradient & g)
{
  const unsigned int NUMCOLS = 256;

  QRgb coltable[NUMCOLS];
  g.getColorArray(coltable, NUMCOLS);

  // FIXME: should work with ALPHA and LUM_ALPHA also. 20031008 mortene.
  this->node->colorMapType = SoTransferFunction::RGBA;

  float colors[NUMCOLS*4];
  for (unsigned int i=0; i < NUMCOLS; i++) {
    QRgb c = coltable[i];
    colors[i*4 + 0] = float(qRed(c)) / 255.0f;
    colors[i*4 + 1] = float(qGreen(c)) / 255.0f;
    colors[i*4 + 2] = float(qBlue(c)) / 255.0f;
    colors[i*4 + 3] = float(qAlpha(c)) / 255.0f;
  }
  this->node->colorMap.setValues(0, NUMCOLS*4, colors);
}

void
TransferFunctionHandler::gradientCallbackP(const Gradient & g, void * userdata)
{
  TransferFunctionHandler * that = (TransferFunctionHandler *)userdata;
  that->gradientCallback(g);
}

void
TransferFunctionHandler::predefColorMapUpdate(int idx)
{
  this->node->predefColorMap = idx;

  if (idx == SoTransferFunction::NONE) {
    if (this->gradientdialog == NULL) {
      this->gradientdialog = new SoQtGradientDialog();
      this->gradientdialog->setChangeCallback(TransferFunctionHandler::gradientCallbackP, this);
    }
    this->gradientdialog->show();
    this->gradientCallback(this->gradientdialog->getGradient());
  }
  else {
    if (this->gradientdialog) { this->gradientdialog->hide(); }
  }
}

void
TransferFunctionHandler::shiftEditUpdate(void)
{
  this->node->shift = this->ctrl->shiftEdit->text().toInt();
}

void
TransferFunctionHandler::offsetEditUpdate(void)
{
  this->node->offset = this->ctrl->offsetEdit->text().toInt();
}
