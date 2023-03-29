cmake_minimum_required(VERSION 3.16)

project(voronoi)

find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED)

include_directories(
    include
    ${OpenCV_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS}
    )

add_executable(${PROJECT_NAME} voronoi.cpp)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} ${Boost_LIBRARIES})

# add_executable(four_dimensional fourd.cpp)
# target_link_libraries(four_dimensional ${OpenCV_LIBS} ${Boost_LIBRARIES})

add_executable(vor voronoi2.cpp)
target_link_libraries(vor ${OpenCV_LIBS} ${Boost_LIBRARIES})