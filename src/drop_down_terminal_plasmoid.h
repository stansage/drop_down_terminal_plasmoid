/*
    SPDX-FileCopyrightText: %{CURRENT_YEAR} %{AUTHOR} <%{EMAIL}>
    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef DROP_DOWN_TERMINAL_PLASMOID_H
#define DROP_DOWN_TERMINAL_PLASMOID_H

#include <Plasma/Applet>

class drop_down_terminal_plasmoid : public Plasma::Applet
{
    Q_OBJECT
    Q_PROPERTY(QString nativeText READ nativeText CONSTANT)

public:
    explicit drop_down_terminal_plasmoid(QObject *parent, const KPluginMetaData &data, const QVariantList &args);
    ~drop_down_terminal_plasmoid();

    QString nativeText() const;

private:
    QString m_nativeText;
};

#endif
