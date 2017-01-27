cmake_minimum_required(VERSION 2.8.3)
project(scaler)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

find_package(PkgConfig REQUIRED)
pkg_search_module(LIBUSB1 REQUIRED libusb-1.0)


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES my_minimal_nodes
#  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(SYSTEM ${catkin_INCLUDE_DIRS} ${LIBUSB_1_INCLUDE_DIRS})

SET(CMAKE_CXX_FLAGS "-lusb-1.0")

## Declare a C++ executable
add_executable(usbscaler src/my_minimal_publisher.cpp src/usbscale.c)
#add_executable(my_minimal_subscriber src/my_minimal_subscriber.cpp)

## Add cmake target dependencies of the executable
## same as for the library above
# add_dependencies(my_minimal_nodes_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
target_link_libraries(usbscaler ${catkin_LIBRARIES} ${LIBUSB_1_INCLUDE_DIRS} usb-1.0 -lm)

#target_link_libraries(my_minimal_subscriber ${catkin_LIBRARIES})
#  ${catkin_LIBRARIES}
# )

