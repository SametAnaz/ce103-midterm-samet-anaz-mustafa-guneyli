if(EXISTS "C:/Users/musta/OneDrive/Desktop/algo1/ce103-midterm-samet-anaz-mustafa-guneyli/build_win/src/tests/forestry/forestry_tests[1]_tests.cmake")
  include("C:/Users/musta/OneDrive/Desktop/algo1/ce103-midterm-samet-anaz-mustafa-guneyli/build_win/src/tests/forestry/forestry_tests[1]_tests.cmake")
else()
  add_test(forestry_tests_NOT_BUILT forestry_tests_NOT_BUILT)
endif()
