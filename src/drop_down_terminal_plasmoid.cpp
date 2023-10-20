/*
    SPDX-FileCopyrightText: %{CURRENT_YEAR} %{AUTHOR} <%{EMAIL}>
    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "drop_down_terminal_plasmoid.h"

#include <KLocalizedString>

drop_down_terminal_plasmoid::drop_down_terminal_plasmoid(QObject *parent, const KPluginMetaData &data, const QVariantList &args)
    : Plasma::Applet(parent, data, args),
      m_nativeText(i18n("Text coming from C++ plugin"))
{
}

drop_down_terminal_plasmoid::~drop_down_terminal_plasmoid()
{
}

QString drop_down_terminal_plasmoid::nativeText() const
{
    return m_nativeText;
}

K_PLUGIN_CLASS(drop_down_terminal_plasmoid)

#include "drop_down_terminal_plasmoid.moc"
#include "moc_drop_down_terminal_plasmoid.cpp"
