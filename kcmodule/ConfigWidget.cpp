/***************************************************************************
 *   Copyright (C) 2008 by Dario Freddi <drf@kdemod.ath.cx>                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 ***************************************************************************/

#include "ConfigWidget.h"

#include "PowerDevilSettings.h"

ConfigWidget::ConfigWidget( QWidget *parent )
        : QWidget( parent ),
        m_generalPage( new GeneralPage(this) ),
        m_assignmentPage( new AssignmentPage(this) ),
        m_editPage( new EditPage(this) ),
        m_capabilitiesPage( new CapabilitiesPage(this) )
{
    setupUi( this );

    pageWidget->addPage(m_generalPage, i18n("General Settings"));
    pageWidget->addPage(m_assignmentPage, i18n("Assign Profiles"));
    pageWidget->addPage(m_editPage, i18n("Edit Profiles"));
    pageWidget->addPage(m_capabilitiesPage, i18n("Capabilities"));

    connect(m_generalPage, SIGNAL(changed(bool)), SIGNAL(changed(bool)));
    connect(m_assignmentPage, SIGNAL(changed(bool)), SIGNAL(changed(bool)));
    connect(m_editPage, SIGNAL(changed(bool)), SIGNAL(changed(bool)));
    connect(m_capabilitiesPage, SIGNAL(changed(bool)), SIGNAL(changed(bool)));

    connect(m_editPage, SIGNAL(profilesChanged()), SIGNAL(profilesChanged()));
    connect(m_editPage, SIGNAL(profilesChanged()), m_assignmentPage, SLOT(reloadAvailableProfiles()));
}

ConfigWidget::~ConfigWidget()
{
}

void ConfigWidget::load()
{
    m_generalPage->load();
    m_assignmentPage->load();
    m_editPage->load();
}

void ConfigWidget::save()
{
    m_generalPage->save();
    m_assignmentPage->save();
    m_editPage->save();
}

#include "ConfigWidget.moc"
