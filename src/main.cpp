/*
 * Copyright (C) 2008-2009 Alexei Chaloupov <alexei.chaloupov@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301  USA
 */
/****************************************************************************
**
** Copyright (C) 2007-2008 Trolltech ASA. All rights reserved.
**
** This file is part of the demonstration applications of the Qt Toolkit.
**
** Licensees holding a valid Qt License Agreement may use this file in
** accordance with the rights, responsibilities and obligations
** contained therein.  Please consult your licensing agreement or
** contact sales@trolltech.com if any conditions of this licensing
** agreement are not clear to you.
**
** Further information about Qt licensing is available at:
** http://www.trolltech.com/products/qt/licensing.html or by
** contacting info@trolltech.com.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/

#include "browserapplication.h"

#ifndef QT_SHARED
    #include <QtPlugin>

    Q_IMPORT_PLUGIN(qico)
    Q_IMPORT_PLUGIN(qcncodecs)
    Q_IMPORT_PLUGIN(qjpcodecs)
    Q_IMPORT_PLUGIN(qkrcodecs)
    Q_IMPORT_PLUGIN(qtwcodecs)
#endif



int main(int argc, char **argv)
{
    Q_INIT_RESOURCE(data);
    Q_INIT_RESOURCE(icons);

#ifndef QT_SHARED
    Q_INIT_RESOURCE(WebCore);
    Q_INIT_RESOURCE(WebKit);

# ifdef QTWEBKIT_23
    Q_INIT_RESOURCE(InspectorBackendCommands);
# else
    Q_INIT_RESOURCE(InspectorBackendStub);
# endif
#endif

    BrowserApplication application(argc, argv);
    if (!application.isTheOnlyBrowser())
        return 0;

    application.newMainWindow();

    return application.exec();
}

