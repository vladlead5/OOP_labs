cmake_minimum_required(VERSION 3.10)
project(lab_5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем флаги компиляции для AddressSanitizer
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer -g")

# Флаг для компиляции с предупреждением об использовании неинициализированных переменных
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=maybe-uninitialized")

# Указываем директорию с заголовочными файлами
include_directories(include)

# Создаём исполняемый файл main и добавляем заголовочные файлы
add_executable(main_lab_5 main.cpp)

# Подключаем GoogleTest через FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
  TLS_VERIFY false
)

# Устанавливаем флаги для GoogleTest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Включаем поддержку тестов
enable_testing()

# Создаём исполняемый файл для тестов
add_executable(tests_lab_5 tests/test_list.cpp)
target_link_libraries(tests_lab_5 gtest_main)

# Линкуем AddressSanitizer к тестам
target_compile_options(tests_lab_5 PRIVATE -fsanitize=address -fno-omit-frame-pointer -g)
target_link_options(tests_lab_5 PRIVATE -fsanitize=address)

# Добавляем тесты
add_test(NAME MyProjectTests COMMAND tests_lab_5)