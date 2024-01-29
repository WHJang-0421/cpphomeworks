# TODO: Add your libraries here
# You must have the following libraries:
# - stb_image_data_view
# - drawer
# - image
# - pixelate_image
add_library(stb_image_data_view stb_image_data_view.cpp)
target_link_libraries(stb_image_data_view PUBLIC cxx_setup ftxui::screen stb::stb)
add_library(image image.cpp)
target_link_libraries(image PUBLIC stb_image_data_view)
add_library(pixelate_image pixelate_image.cpp)
target_link_libraries(pixelate_image PUBLIC image)
add_library(drawer drawer.cpp)
target_link_libraries(drawer PUBLIC image)

if(BUILD_TESTING)
  include(GoogleTest)

  add_executable(pixelator_test pixelator_test.cpp)
  target_link_libraries(pixelator_test PRIVATE pixelate_image drawer GTest::gtest_main)
  gtest_discover_tests(pixelator_test)
endif()
