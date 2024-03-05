add_executable(
  core_test
  "abstract_test/consumer/actual_factorial_test.cpp"
  "basic/suite1.cpp"
  "basic/suite2.cpp"
  "basic/adder.cpp"
  "basic/wrapper.cpp"
  "death_test/exiter.cpp"
  "main.cpp"
  "matchers/interval.cpp"
  "matchers/simple.cpp"
  "matchers/tuple.cpp"
  "setup_teardown/spy.cpp")

target_link_libraries(
  core_test
  GTest::gtest_main GTest::gmock_main core
)

include(GoogleTest)
gtest_discover_tests(core_test)
