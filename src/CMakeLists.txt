include(FindPkgConfig)

link_directories(
        ${GTKMM_LIBRARY_DIRS}
)

include_directories(
        ${GTKMM_INCLUDE_DIRS}
)

add_executable(SurfaceCutCurve
        main.cpp)

target_link_libraries(SurfaceCutCurve
        ${GTKMM_LIBRARIES}
        )
