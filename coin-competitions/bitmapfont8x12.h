/**************************************************************************\
 *
 *  This file is part of a set of example programs for the Coin library.
 *  Copyright (C) 2000-2002 by Systems in Motion. All rights reserved.
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

/* First submitted in a competition entry by Marius Bugge Monsen.
   Cleaned up a bit and submitted as common data by Marius Kintel. */

/* Font size is 8x12 */

static unsigned char SOGUIEXAMPLES_FONT[256][12] = {
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,126,195,129,165,129,189,153,195,126,0,0},
  {0,126,255,255,219,255,195,231,255,126,0,0},
  {0,0,68,238,254,254,254,124,56,16,0,0},
  {0,16,56,124,254,254,124,56,16,0,0,0},
  {0,24,60,60,255,231,231,24,24,126,0,0},
  {0,24,60,126,255,255,126,24,24,126,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,62,14,58,114,248,204,204,204,120,0,0},
  {0,60,102,102,102,60,24,126,24,24,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,127,99,127,99,99,99,103,231,230,192,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,128,192,224,248,254,248,224,192,128,0,0},
  {0,2,6,14,62,254,62,14,6,2,0,0},
  {0,24,60,126,24,24,24,126,60,24,0,0},
  {0,102,102,102,102,102,0,0,102,102,0,0},
  {0,127,219,219,219,123,27,27,27,27,0,0},
  {0,126,99,48,60,102,102,60,12,198,126,0},
  {0,0,0,0,0,0,0,254,254,254,0,0},
  {0,24,60,126,24,24,24,126,60,24,126,0},
  {0,24,60,126,24,24,24,24,24,24,0,0},
  {0,24,24,24,24,24,24,126,60,24,0,0},
  {0,0,0,24,12,254,12,24,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,192,192,192,254,0,0,0,0},
  {0,0,0,36,102,255,102,36,0,0,0,0},
  {0,0,16,16,56,56,124,124,254,254,0,0},
  {0,0,254,254,124,124,56,56,16,16,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,48,120,120,120,48,48,0,48,48,0,0},
  {0,102,102,102,36,0,0,0,0,0,0,0},
  {0,108,108,254,108,108,108,254,108,108,0,0},
  {48,48,124,192,192,120,12,12,248,48,48,0},
  {0,0,0,196,204,24,48,96,204,140,0,0},
  {0,112,216,216,112,250,222,204,220,118,0,0},
  {0,48,48,48,96,0,0,0,0,0,0,0},
  {0,12,24,48,96,96,96,48,24,12,0,0},
  {0,96,48,24,12,12,12,24,48,96,0,0},
  {0,0,0,102,60,255,60,102,0,0,0,0},
  {0,0,0,24,24,126,24,24,0,0,0,0},
  {0,0,0,0,0,0,0,0,56,56,96,0},
  {0,0,0,0,0,254,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,56,56,0,0},
  {0,0,2,6,12,24,48,96,192,128,0,0},
  {0,124,198,206,222,214,246,230,198,124,0,0},
  {0,16,48,240,48,48,48,48,48,252,0,0},
  {0,120,204,204,12,24,48,96,204,252,0,0},
  {0,120,204,12,12,56,12,12,204,120,0,0},
  {0,12,28,60,108,204,254,12,12,30,0,0},
  {0,252,192,192,192,248,12,12,204,120,0,0},
  {0,56,96,192,192,248,204,204,204,120,0,0},
  {0,254,198,198,6,12,24,48,48,48,0,0},
  {0,120,204,204,236,120,220,204,204,120,0,0},
  {0,120,204,204,204,124,24,24,48,112,0,0},
  {0,0,0,56,56,0,0,56,56,0,0,0},
  {0,0,0,56,56,0,0,56,56,24,48,0},
  {0,12,24,48,96,192,96,48,24,12,0,0},
  {0,0,0,0,126,0,126,0,0,0,0,0},
  {0,96,48,24,12,6,12,24,48,96,0,0},
  {0,120,204,12,24,48,48,0,48,48,0,0},
  {0,124,198,198,222,222,222,192,192,124,0,0},
  {0,48,120,204,204,204,252,204,204,204,0,0},
  {0,252,102,102,102,124,102,102,102,252,0,0},
  {0,60,102,198,192,192,192,198,102,60,0,0},
  {0,248,108,102,102,102,102,102,108,248,0,0},
  {0,254,98,96,100,124,100,96,98,254,0,0},
  {0,254,102,98,100,124,100,96,96,240,0,0},
  {0,60,102,198,192,192,206,198,102,62,0,0},
  {0,204,204,204,204,252,204,204,204,204,0,0},
  {0,120,48,48,48,48,48,48,48,120,0,0},
  {0,30,12,12,12,12,204,204,204,120,0,0},
  {0,230,102,108,108,120,108,108,102,230,0,0},
  {0,240,96,96,96,96,98,102,102,254,0,0},
  {0,198,238,254,254,214,198,198,198,198,0,0},
  {0,198,198,230,246,254,222,206,198,198,0,0},
  {0,56,108,198,198,198,198,198,108,56,0,0},
  {0,252,102,102,102,124,96,96,96,240,0,0},
  {0,56,108,198,198,198,206,222,124,12,30,0},
  {0,252,102,102,102,124,108,102,102,230,0,0},
  {0,120,204,204,192,112,24,204,204,120,0,0},
  {0,252,180,48,48,48,48,48,48,120,0,0},
  {0,204,204,204,204,204,204,204,204,120,0,0},
  {0,204,204,204,204,204,204,204,120,48,0,0},
  {0,198,198,198,198,214,214,108,108,108,0,0},
  {0,204,204,204,120,48,120,204,204,204,0,0},
  {0,204,204,204,204,120,48,48,48,120,0,0},
  {0,254,206,152,24,48,96,98,198,254,0,0},
  {0,60,48,48,48,48,48,48,48,60,0,0},
  {0,0,128,192,96,48,24,12,6,2,0,0},
  {0,60,12,12,12,12,12,12,12,60,0,0},
  {16,56,108,198,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,255,0},
  {48,48,24,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,120,12,124,204,204,118,0,0},
  {0,224,96,96,124,102,102,102,102,220,0,0},
  {0,0,0,0,120,204,192,192,204,120,0,0},
  {0,28,12,12,124,204,204,204,204,118,0,0},
  {0,0,0,0,120,204,252,192,204,120,0,0},
  {0,56,108,96,96,248,96,96,96,240,0,0},
  {0,0,0,0,118,204,204,204,124,12,204,120},
  {0,224,96,96,108,118,102,102,102,230,0,0},
  {0,24,24,0,120,24,24,24,24,126,0,0},
  {0,12,12,0,60,12,12,12,12,204,204,120},
  {0,224,96,96,102,108,120,108,102,230,0,0},
  {0,120,24,24,24,24,24,24,24,126,0,0},
  {0,0,0,0,252,214,214,214,214,198,0,0},
  {0,0,0,0,248,204,204,204,204,204,0,0},
  {0,0,0,0,120,204,204,204,204,120,0,0},
  {0,0,0,0,220,102,102,102,102,124,96,240},
  {0,0,0,0,118,204,204,204,204,124,12,30},
  {0,0,0,0,236,110,118,96,96,240,0,0},
  {0,0,0,0,120,204,96,24,204,120,0,0},
  {0,0,32,96,252,96,96,96,108,56,0,0},
  {0,0,0,0,204,204,204,204,204,118,0,0},
  {0,0,0,0,204,204,204,204,120,48,0,0},
  {0,0,0,0,198,198,214,214,108,108,0,0},
  {0,0,0,0,198,108,56,56,108,198,0,0},
  {0,0,0,0,102,102,102,102,60,12,24,240},
  {0,0,0,0,252,140,24,96,196,252,0,0},
  {0,28,48,48,96,192,96,48,48,28,0,0},
  {0,24,24,24,24,0,24,24,24,24,0,0},
  {0,224,48,48,24,12,24,48,48,224,0,0},
  {0,115,218,206,0,0,0,0,0,0,0,0},
  {0,0,0,16,56,108,198,198,254,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,255,0},
  {0,0,0,0,0,0,0,0,0,0,255,0},
  {0,0,0,0,0,0,0,0,56,56,96,0},
  {14,27,24,24,126,24,24,24,216,112,0,0},
  {0,0,0,0,0,0,0,0,56,56,96,0},
  {0,0,0,0,0,0,0,0,56,56,0,0},
  {0,0,0,24,24,126,24,24,0,0,0,0},
  {24,24,24,24,255,0,0,255,24,24,24,24},
  {16,56,108,198,0,0,0,0,0,0,0,0},
  {0,0,0,196,204,24,48,96,204,140,0,0},
  {0,120,204,204,192,112,24,204,204,120,0,0},
  {0,12,24,48,96,192,96,48,24,12,0,0},
  {0,56,108,198,198,198,198,198,108,56,0,0},
  {0,0,0,0,0,0,0,0,0,0,255,0},
  {0,254,206,152,24,48,96,98,198,254,0,0},
  {0,0,0,0,0,0,0,0,0,0,255,0},
  {0,0,0,0,0,0,0,0,0,0,255,0},
  {48,48,24,0,0,0,0,0,0,0,0,0},
  {0,48,48,48,96,0,0,0,0,0,0,0},
  {0,102,102,102,36,0,0,0,0,0,0,0},
  {0,102,102,102,36,0,0,0,0,0,0,0},
  {0,0,0,0,0,254,0,0,0,0,0,0},
  {0,0,0,0,0,254,0,0,0,0,0,0},
  {0,115,218,206,0,0,0,0,0,0,0,0},
  {0,252,180,48,48,48,48,48,48,120,0,0},
  {0,0,0,0,120,204,96,24,204,120,0,0},
  {0,96,48,24,12,6,12,24,48,96,0,0},
  {0,0,0,0,120,204,204,204,204,120,0,0},
  {0,0,0,0,0,0,0,0,0,0,255,0},
  {0,0,0,0,252,140,24,96,196,252,0,0},
  {0,204,204,204,204,120,48,48,48,120,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,48,48,0,48,48,120,120,120,48,0,0},
  {0,48,48,120,204,192,192,204,120,48,48,0},
  {60,102,96,96,96,252,96,96,192,254,0,0},
  {0,0,24,219,126,231,231,126,219,24,0,0},
  {204,204,204,204,120,252,48,252,48,48,0,0},
  {240,240,240,240,240,240,240,240,240,240,240,240},
  {0,126,99,48,60,102,102,60,12,198,126,0},
  {0,102,102,102,36,0,0,0,0,0,0,0},
  {0,0,0,0,120,204,192,192,204,120,0,0},
  {0,120,204,204,126,0,254,0,0,0,0,0},
  {0,0,0,0,51,102,204,204,102,51,0,0},
  {0,0,0,0,0,252,12,12,12,0,0,0},
  {0,0,0,0,0,254,0,0,0,0,0,0},
  {0,0,0,0,236,110,118,96,96,240,0,0},
  {0,0,0,0,0,0,0,0,0,0,255,0},
  {0,60,102,102,102,60,0,0,0,0,0,0},
  {0,0,48,48,252,48,48,0,252,0,0,0},
  {0,120,12,24,48,124,0,0,0,0,0,0},
  {0,120,204,12,12,56,12,12,204,120,0,0},
  {0,48,48,48,96,0,0,0,0,0,0,0},
  {0,0,0,0,102,102,102,102,102,123,96,192},
  {0,127,219,219,219,123,27,27,27,27,0,0},
  {0,0,0,0,0,24,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,56,56,96,0},
  {0,16,48,240,48,48,48,48,48,252,0,0},
  {0,120,204,204,120,0,254,0,0,0,0,0},
  {0,0,0,0,204,102,51,51,102,204,0,0},
  {0,99,230,108,120,55,111,219,179,63,3,0},
  {0,66,198,204,216,48,110,195,134,12,31,0},
  {0,0,0,0,0,0,0,0,0,0,255,0},
  {0,48,48,0,48,96,192,192,204,120,0,0},
  {0,48,120,204,204,204,252,204,204,204,0,0},
  {0,48,120,204,204,204,252,204,204,204,0,0},
  {0,48,120,204,204,204,252,204,204,204,0,0},
  {0,48,120,204,204,204,252,204,204,204,0,0},
  {0,204,0,48,120,204,204,252,204,204,0,0},
  {120,204,204,120,120,204,204,252,204,204,0,0},
  {0,62,120,216,216,254,216,216,216,222,0,0},
  {0,120,204,204,192,192,192,204,204,120,48,240},
  {0,254,98,96,100,124,100,96,98,254,0,0},
  {12,24,48,252,196,192,248,192,196,252,0,0},
  {0,254,98,96,100,124,100,96,98,254,0,0},
  {0,254,98,96,100,124,100,96,98,254,0,0},
  {0,120,48,48,48,48,48,48,48,120,0,0},
  {0,120,48,48,48,48,48,48,48,120,0,0},
  {0,120,48,48,48,48,48,48,48,120,0,0},
  {0,120,48,48,48,48,48,48,48,120,0,0},
  {0,248,108,102,102,102,102,102,108,248,0,0},
  {118,220,0,198,230,246,222,206,198,198,0,0},
  {0,56,108,198,198,198,198,198,108,56,0,0},
  {0,56,108,198,198,198,198,198,108,56,0,0},
  {0,56,108,198,198,198,198,198,108,56,0,0},
  {0,56,108,198,198,198,198,198,108,56,0,0},
  {204,0,120,204,204,204,204,204,204,120,0,0},
  {0,0,0,0,198,108,56,56,108,198,0,0},
  {0,56,108,198,198,198,198,198,108,56,0,0},
  {0,204,204,204,204,204,204,204,204,120,0,0},
  {0,204,204,204,204,204,204,204,204,120,0,0},
  {0,204,204,204,204,204,204,204,204,120,0,0},
  {204,0,204,204,204,204,204,204,204,120,0,0},
  {0,204,204,204,204,120,48,48,48,120,0,0},
  {0,0,0,0,0,0,0,0,0,0,255,0},
  {0,120,204,204,216,204,204,204,248,192,96,0},
  {192,96,48,0,120,12,124,204,204,118,0,0},
  {12,24,48,0,120,12,124,204,204,118,0,0},
  {48,120,204,0,120,12,124,204,204,118,0,0},
  {0,0,0,0,120,12,124,204,204,118,0,0},
  {0,204,204,0,120,12,124,204,204,118,0,0},
  {56,108,108,56,248,12,124,204,204,118,0,0},
  {0,0,0,0,254,27,127,216,216,239,0,0},
  {0,0,0,0,120,204,192,192,204,120,48,240},
  {192,96,48,0,120,204,252,192,192,124,0,0},
  {12,24,48,0,120,204,252,192,204,120,0,0},
  {48,120,204,0,120,204,252,192,192,124,0,0},
  {0,204,204,0,120,204,252,192,192,124,0,0},
  {96,48,24,0,120,24,24,24,24,126,0,0},
  {12,24,48,0,120,24,24,24,24,126,0,0},
  {16,56,108,0,120,24,24,24,24,126,0,0},
  {0,108,108,0,120,24,24,24,24,126,0,0},
  {0,28,12,12,124,204,204,204,204,118,0,0},
  {0,118,220,0,248,204,204,204,204,204,0,0},
  {192,96,48,0,120,204,204,204,204,120,0,0},
  {12,24,48,0,120,204,204,204,204,120,0,0},
  {48,120,204,0,120,204,204,204,204,120,0,0},
  {0,0,0,0,120,204,204,204,204,120,0,0},
  {0,204,204,0,120,204,204,204,204,120,0,0},
  {0,0,48,48,0,252,0,48,48,0,0,0},
  {0,0,0,0,120,204,204,204,204,120,0,0},
  {192,96,48,0,204,204,204,204,204,118,0,0},
  {12,24,48,0,204,204,204,204,204,118,0,0},
  {48,120,204,0,204,204,204,204,204,118,0,0},
  {0,204,204,0,204,204,204,204,204,118,0,0},
  {0,0,0,0,102,102,102,102,60,12,24,240},
  {0,0,0,0,0,0,0,0,0,0,255,0},
  {0,102,102,0,102,102,102,102,60,12,24,240},
  {0,0,0,0,0,0,0,0,0,0,0,0}};
