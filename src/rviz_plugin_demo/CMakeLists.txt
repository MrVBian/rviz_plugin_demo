cmake_minimum_required(VERSION 3.5)
project(rviz_plugin_demo)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


set(CMAKE_AUTOMOC ON)#cmake自动处理Moc文件

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rviz_common REQUIRED)
find_package(pluginlib REQUIRED)
find_package(Qt5 COMPONENTS Widgets Core REQUIRED)

set (THIS_PACKAGE_INCLUDE_DEPENDS
  rclcpp   
  rviz_common 
  pluginlib
  Qt5
)

include_directories(
  include
)

#动态链接库
add_library( ${PROJECT_NAME} SHARED
  src/rviz_plugin_demo.cpp
  include/rviz_plugin_demo/rviz_plugin_demo.h
  include/rviz_plugin_demo/ui_rviz_plugin_demo.h
)

ament_target_dependencies(${PROJECT_NAME} ${THIS_PACKAGE_INCLUDE_DEPENDS})

target_include_directories(${PROJECT_NAME} PUBLIC
  ${Qt5Widgets_INCLUDE_DIRS}
)

target_link_libraries(
  ${PROJECT_NAME} Qt5::Widgets
)


#导出插件描述文件
pluginlib_export_plugin_description_file(rviz_common plugin_description.xml)

install(
  TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
)

# 在ament中导出项目的头文件、库、目标和依赖项
ament_export_include_directories(include) # 将include目录中的头文件导出
ament_export_libraries(${PROJECT_NAME}) # 将项目名称指定的库导出
ament_export_targets(${PROJECT_NAME} ) # 将项目名称指定的目标导出
ament_export_dependencies(${THIS_PACKAGE_INCLUDE_DEPENDS}) # 将此包的依赖项导出

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
