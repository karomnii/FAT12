#
# DANTE :: System Automatycznych Testów Jednostkowych oraz Akceptacyjnych
# Tomasz Jaworski, 2018-2020
#
# Plik wygenerowany automatycznie
# Znacznik czasowy: 2024-01-29 20:49:53.532384
#

cmake_minimum_required(VERSION 3.17)
project(project1 C)

# Przyjmij standard C11
set(CMAKE_C_STANDARD 11)

# Ustaw opcje kompilatora (z raportu Dante)
add_compile_options(
      "-fmax-errors=5"
      "-xc"
      "-D_ANSI_OUTPUT"
      "-fdiagnostics-color"
      "-Werror=vla"
      "-Wno-error=unused-parameter"
      "-DINSIDE_DANTE"
      "-Wall"
      "-ggdb3"
      "-Wno-error=implicit-fallthrough"
      "-Wno-parentheses"
      "-Wno-error=parentheses"
      "-Werror"
      "-pedantic"
      "-D_GNU_SOURCE"
      "-std=c11"
      "-Wextra"

)

# Ustaw opcje konsolidatora (z raportu Dante)
add_link_options(
        "-Wl,-cref"
        "-Wl,-wrap,main"
        "-ggdb3"
        "-Wl,-Map=main.map"
)

# Utwórz target 'project1' i dodaj do niego pliki źródlowe:
add_executable(project1
        "file_reader.c"
        "main.c"
        "unit_helper_v2.c"
        "unit_test_v2.c"
        "rdebug.c"
)

# Dołącz niezbędne biblioteki
target_link_libraries(project1
        "m"
)