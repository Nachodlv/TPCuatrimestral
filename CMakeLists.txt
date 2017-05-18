cmake_minimum_required(VERSION 3.6)
project(TPCuatrimestral)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Exercise1/Appliance.c
        Exercise1/Appliance.h
        Exercise1/Cart.c
        Exercise1/Cart.h
        Exercise1/Catalogue.c
        Exercise1/Catalogue.h
        Exercise1/Invoice.c
        Exercise1/Invoice.h
        Exercise1/Stock.c
        Exercise1/Stock.h
        Exercise1/Label.c
        Exercise1/Label.h
        Exercise1/LineCart.c
        Exercise1/LineCart.h
        Exercise1/Manufacturer.c
        Exercise1/Manufacturer.h
        Exercise1/Provider.c
        Exercise1/Provider.h
        Exercise1/InvoiceLine.c
        Exercise1/InvoiceLine.h
        Exercise1/ExecuteExercise1.c
        Exercise1/ExecuteExercise1.h
        .gitignore
        CMakeLists.txt
        main.c
        README.md
        Exercise2/RegisteredUser.c Exercise2/RegisteredUser.h Exercise2/Sale.c Exercise2/Sale.h Exercise2/SaleLine.c
        Exercise2/SaleLine.h Exercise2/Product.c Exercise2/Product.h Exercise2/Manufacturer.c Exercise2/Manufacturer.h
        Exercise2/Provider.c Exercise2/Provider.h Exercise2/Camera.c Exercise2/Camera.h Exercise2/Accesory.c Exercise2/Accesory.h
        Exercise2/CameraAndAccesoryTable.c Exercise2/CameraAndAccesoryTable.h Exercise2/ExecuteExercise2.c Exercise2/ExecuteExercise2.h)

add_executable(TPCuatrimestral ${SOURCE_FILES})