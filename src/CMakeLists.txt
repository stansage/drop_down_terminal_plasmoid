# TODO: adapt "org.kde.plasma" here & elsewhere if needed (see README)
add_definitions(-DTRANSLATION_DOMAIN=\"plasma_applet_org.kde.plasma.drop_down_terminal_plasmoid\")

add_library(org.kde.plasma.drop_down_terminal_plasmoid MODULE drop_down_terminal_plasmoid.cpp)

target_link_libraries(org.kde.plasma.drop_down_terminal_plasmoid
                      Qt5::Gui
                      KF5::Plasma
                      KF5::I18n)


install(TARGETS org.kde.plasma.drop_down_terminal_plasmoid DESTINATION ${KDE_INSTALL_PLUGINDIR}/plasma/applets)

plasma_install_package(package org.kde.plasma.drop_down_terminal_plasmoid)
