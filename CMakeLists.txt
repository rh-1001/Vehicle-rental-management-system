cmake_minimum_required(VERSION 3.19)
project(VehicleRentalManagementSystem LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(VehicleRentalManagementSystem
    main.cpp
    vehicle.h vehicle.cpp
    car.h car.cpp
    motorcycle.h motorcycle.cpp
    vehiclemanager.h vehiclemanager.cpp
    storage
)

target_link_libraries(VehicleRentalManagementSystem
    PRIVATE
        Qt::Core
)

install(TARGETS VehicleRentalManagementSystem
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
