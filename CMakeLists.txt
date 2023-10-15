cmake_minimum_required(VERSION 3.5)

project(FoodManagementSystem VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        ingredient.h
        ingredient.cpp
        ingredient.ui
        addingredient.h
        addingredient.cpp
        addingredient.ui
        removeingredient.h
        removeingredient.cpp
        removeingredient.ui
        databaseheader.h
        recipe.h
        recipe.cpp
        recipe.ui
        addrecipe.h
        addrecipe.cpp
        addrecipe.ui
        removerecipe.h
        removerecipe.cpp
        removerecipe.ui
        mealplan.h
        mealplan.cpp
        mealplan.ui
        list.h
        list.cpp
        list.ui
 )

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(FoodManagementSystem
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        removeingredient.h removeingredient.cpp removeingredient.ui
        recipe.h recipe.cpp recipe.ui
        addrecipe.h addrecipe.cpp addrecipe.ui
        removerecipe.h removerecipe.cpp removerecipe.ui
        mealplan.h mealplan.cpp mealplan.ui
        list.h list.cpp list.ui
        storage.h storage.cpp
        shoppinglist.h shoppinglist.cpp
        addtoshoppinglist.h addtoshoppinglist.cpp addtoshoppinglist.ui
        removefromshoppinglist.h removefromshoppinglist.cpp removefromshoppinglist.ui
        onlineshopping.h onlineshopping.cpp
        marketpurchasing.h marketpurchasing.cpp
        addtostorage.h addtostorage.cpp addtostorage.ui
        removefromstorage.h removefromstorage.cpp removefromstorage.ui
        resource.qrc




    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET FoodManagementSystem APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(FoodManagementSystem SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(FoodManagementSystem
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(FoodManagementSystem PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.FoodManagementSystem)
endif()
set_target_properties(FoodManagementSystem PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

#include(GNUInstallDirs)
install(TARGETS FoodManagementSystem
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(FoodManagementSystem)
endif()
