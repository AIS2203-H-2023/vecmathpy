
set(sources
        "vecmath/vector3.cpp"
        "vecmath/matrix4.cpp"
        )

add_library(vecmath ${sources})
target_include_directories(vecmath
        PUBLIC
        "${CMAKE_SOURCE_DIR}/include"
        )

set(csources
        "vecmath/vecmath.cpp"
        )

add_library(vecmathc SHARED ${csources})
target_link_libraries(vecmathc PRIVATE vecmath)
