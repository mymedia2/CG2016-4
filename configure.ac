# начальная секция
AC_PREREQ(2.69)
AC_INIT(RayTracer, 0.1, guriev-ns@ya.ru)
AC_CONFIG_SRCDIR([src/Main.cpp])
AM_INIT_AUTOMAKE
AC_LANG_CPLUSPLUS  # применяются настройки для C++
: ${CXXFLAGS=""}   # убираем флаги по умолчанию

# параметр для статической сборки
AC_ARG_WITH([static],
  AS_HELP_STRING([--with-static], [Компоновать библиотеки статически], 26, 99),
[
  PKG_CHECK_MODULES_STATIC([MAGICK], [Magick++])
  AX_APPEND_COMPILE_FLAGS([-pthread])
  AX_APPEND_LINK_FLAGS([-static -static-libstdc++])
],
[
  PKG_CHECK_MODULES([MAGICK], [Magick++])
])

# параметр компиляции для отладки
AC_ARG_ENABLE([debug],
  AS_HELP_STRING([--enable-debug], [Компилировать в отладочном режиме], 26, 99),
[
  # отключаем оптимизации, добавляем отладочные символы в формате GDB
  AX_APPEND_COMPILE_FLAGS([-O0 -ggdb3])
],
[
  AX_APPEND_COMPILE_FLAGS([-O2 -flto])  # включаем межмодульные оптимизации
  AX_APPEND_LINK_FLAGS([-s])            # сжимаем бинарник, удаляя символы
])

# проверка программ
AC_PROG_CXX               # компилятор С++
AX_CXX_COMPILE_STDCXX_14  # указание версии С++

# проверка заголовков
AC_CHECK_HEADER([Magick++.h], [], [
  AC_MSG_ERROR([Отсутствует заголовок для Magick++])
])

# указание выходных файлов
AC_CONFIG_FILES([Makefile src/glm/Makefile])
AC_OUTPUT
