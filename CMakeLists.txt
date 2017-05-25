cmake_minimum_required(VERSION 3.6)
project(TPCuatrimestral)

#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)
set(SOURCE_FILES
        .gitignore
        CMakeLists.txt
        main.c
        README.md

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

        Exercise2/RegisteredUser.c
        Exercise2/RegisteredUser.h
        Exercise2/Sale.c
        Exercise2/Sale.h
        Exercise2/SaleLine.c
        Exercise2/SaleLine.h
        Exercise2/Product.c
        Exercise2/Product.h
        Exercise2/Manufacturer.c
        Exercise2/Manufacturer.h
        Exercise2/Provider.c
        Exercise2/Provider.h
        Exercise2/Camera.c
        Exercise2/Camera.h
        Exercise2/Accesory.c
        Exercise2/Accesory.h
        Exercise2/CameraAndAccesoryTable.c
        Exercise2/CameraAndAccesoryTable.h
        Exercise2/ExecuteExercise2.c
        Exercise2/ExecuteExercise2.h

        Exercise3/Library.c
        Exercise3/Library.h
        Exercise3/ExecuteExercise3.c
        Exercise3/ExecuteExercise3.h
        Exercise3/Material.c
        Exercise3/Material.h
        Exercise3/Person.c
        Exercise3/Person.h
        Exercise3/Borrow.c
        Exercise3/Borrow.h

        Exercise4/Client.c
        Exercise4/Client.h
        Exercise4/Hotel.c
        Exercise4/Hotel.h
        Exercise4/Invoice.h
        Exercise4/Invoice.c
        Exercise4/Receptionist.c
        Exercise4/Receptionist.h
        Exercise4/Reservation.c
        Exercise4/Reservation.h
        Exercise4/Room.c
        Exercise4/Room.h
        )

add_executable(TPCuatrimestral ${SOURCE_FILES})