cmake_minimum_required(VERSION 3.6)
project(TPCuatrimestral)

#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)
set(SOURCE_FILES
        .gitignore
        CMakeLists.txt
        main.c
        README.md

        src/Exercise1/Appliance.c
        src/Exercise1/Appliance.h
        src/Exercise1/Cart.c
        src/Exercise1/Cart.h
        src/Exercise1/Catalogue.c
        src/Exercise1/Catalogue.h
        src/Exercise1/Invoice.c
        src/Exercise1/Invoice.h
        src/Exercise1/Stock.c
        src/Exercise1/Stock.h
        src/Exercise1/Label.c
        src/Exercise1/Label.h
        src/Exercise1/LineCart.c
        src/Exercise1/LineCart.h
        src/Exercise1/Manufacturer.c
        src/Exercise1/Manufacturer.h
        src/Exercise1/Provider.c
        src/Exercise1/Provider.h
        src/Exercise1/InvoiceLine.c
        src/Exercise1/InvoiceLine.h
        src/Exercise1/ExecuteExercise1.c
        src/Exercise1/ExecuteExercise1.h

        src/Exercise2/RegisteredUser.c
        src/Exercise2/RegisteredUser.h
        src/Exercise2/Sale.c
        src/Exercise2/Sale.h
        src/Exercise2/SaleLine.c
        src/Exercise2/SaleLine.h
        src/Exercise2/Product.c
        src/Exercise2/Product.h
        src/Exercise2/Manufacturer.c
        src/Exercise2/Manufacturer.h
        src/Exercise2/Provider.c
        src/Exercise2/Provider.h
        src/Exercise2/Camera.c
        src/Exercise2/Camera.h
        src/Exercise2/Accesory.c
        src/Exercise2/Accesory.h
        src/Exercise2/CameraAndAccesoryTable.c
        src/Exercise2/CameraAndAccesoryTable.h
        src/Exercise2/ExecuteExercise2.c
        src/Exercise2/ExecuteExercise2.h

        src/Exercise3/Library.c
        src/Exercise3/Library.h
        src/Exercise3/ExecuteExercise3.c
        src/Exercise3/ExecuteExercise3.h
        src/Exercise3/Material.c
        src/Exercise3/Material.h
        src/Exercise3/Person.c
        src/Exercise3/Person.h
        src/Exercise3/Borrow.c
        src/Exercise3/Borrow.h

        src/Exercise4/Room.c
        src/Exercise4/Room.h
        src/Exercise4/Client.c
        src/Exercise4/Client.h
        src/Exercise4/Hotel.c
        src/Exercise4/Hotel.h
        src/Exercise4/Invoice.h
        src/Exercise4/Invoice.c
        src/Exercise4/Receptionist.c
        src/Exercise4/Receptionist.h
        src/Exercise4/Reservation.c
        src/Exercise4/Reservation.h
        src/Exercise4/ExecuteExercise4.c
        src/Exercise4/ExecuteExercise4.h

        src/Exercise5/Id.c
        src/Exercise5/Id.h
        src/Exercise5/Client.c
        src/Exercise5/Client.h
        src/Exercise5/Admin.c
        src/Exercise5/Admin.h
        src/Exercise5/Movie.c
        src/Exercise5/Movie.h
        src/Exercise5/Excess.c
        src/Exercise5/Excess.h
        src/Exercise5/DataBase.c
        src/Exercise5/DataBase.h
        src/Exercise5/ExecuteExercise5.c
        src/Exercise5/ExecuteExercise5.h)

add_executable(TPCuatrimestral ${SOURCE_FILES})