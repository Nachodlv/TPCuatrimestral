cmake_minimum_required(VERSION 3.6)
project(TPCuatrimestral)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Exercise1/ExecuteExercise1.c
        Exercise1/ExecuteExercise1.h
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
        .gitignore
        CMakeLists.txt
        main.c
        README.md
        Exercise1/InvoiceLine.c
        Exercise1/InvoiceLine.h)

add_executable(TPCuatrimestral ${SOURCE_FILES})