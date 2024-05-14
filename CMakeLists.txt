cmake_minimum_required(VERSION 3.10)
project(DeliveryApp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# GTK+ includes and libraries (Assuming you are still using GTK)
set(GTK_INCLUDES /opt/homebrew/include/gtk-3.0
                 /opt/homebrew/include/pango-1.0
                 /opt/homebrew/include/glib-2.0
                 /opt/homebrew/include/cairo
                 /opt/homebrew/include/gdk-pixbuf-2.0
                 /opt/homebrew/include/atk-1.0
                 /opt/homebrew/lib/glib-2.0/include
                 /opt/homebrew/lib/gtk-3.0/include
                 /opt/homebrew/lib/pango-1.0/include
                 /opt/homebrew/lib/cairo/include
                 /opt/homebrew/lib/gdk-pixbuf-2.0/include
                 /opt/homebrew/lib/atk-1.0/include)
set(GTK_LIBS -L/opt/homebrew/lib
             -lgtk-3 -lgdk-3 -lpangocairo-1.0 -lpango-1.0 -lcairo
             -lgdk_pixbuf-2.0 -latk-1.0 -lcairo -lpthread -lgio-2.0
             -lgobject-2.0 -lglib-2.0)

# Harfbuzz includes and libraries
set(HARFBUZZ_INCLUDES /opt/homebrew/include/harfbuzz)
set(HARFBUZZ_LIBS -L/opt/homebrew/lib -lharfbuzz)

# Source files
set(SOURCES main.cpp DeliveryManager.cpp Location.cpp)

# Executable
add_executable(main ${SOURCES})

# Include directories
target_include_directories(main PUBLIC ${GTK_INCLUDES} ${HARFBUZZ_INCLUDES})

# Link libraries
target_link_libraries(main ${GTK_LIBS} ${HARFBUZZ_LIBS})

# This is to suppress warnings about unused variables
set_property(TARGET main PROPERTY CXX_STANDARD 14)
