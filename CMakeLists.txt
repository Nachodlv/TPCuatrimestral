cmake_minimum_required(VERSION 3.6)
project(TPCuatrimestral)

set(CMAKE_C_STANDARD 90)

set(SOURCE_FILES main.c Exercise1/Appliance.c Exercise1/Appliance.h Exercise1/InvoiceLine.c Exercise1/InvoiceLine.h Exercise1/Provider.c Exercise1/Provider.h Exercise1/Manufacturer.c Exercise1/Manufacturer.h Exercise1/Label.c Exercise1/Label.h Exercise1/LineCart.c Exercise1/LineCart.h Exercise1/Cart.c Exercise1/Cart.h Exercise1/Invoice.c Exercise1/Invoice.h Exercise1/Catalogue.c Exercise1/Catalogue.h)
add_executable(TPCuatrimestral ${SOURCE_FILES})