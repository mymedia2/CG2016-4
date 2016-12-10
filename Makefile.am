# обязательные опции, отключаем проверку стиля GNU
AUTOMAKE_OPTIONS = subdir-objects foreign

# имя бинарника
bin_PROGRAMS = bin/RayTracer

# список файлов с исходниками
bin_RayTracer_SOURCES = src/Main.cpp src/Scene.cpp src/Tracer.cpp \
                        src/stdafx.h src/Scene.h src/Tracer.h src/Types.h

# кладём в архив сам бинарник
EXTRA_DIST = bin/RayTracer

# закидываем в архив библиотеку
DIST_SUBDIRS = src/glm

# не забываем положить в архив картинки, если нужно
imgdir = $(pkgdatadir)/img
dist_img_DATA = # ...

# конфигурационный файл
confdir = $(sysconfdir)/$(PACKAGE)
dist_conf_DATA = bin/config.txt

# указываем пути к данным в макросах IMG_DIR и CONF_DIR
override CPPFLAGS += -DIMG_DIR='"$(imgdir)"' -DCONF_DIR='"$(confdir)"'

# добавляем флаги для библиотеки Magick++
bin_RayTracer_CPPFLAGS = $(MAGICK_CFLAGS)
bin_RayTracer_LDADD = $(MAGICK_LIBS)

# генерация предкомпилированного заголовка
%.h.gch: %.h
	$(CXXCOMPILE) $(MAGICK_CFLAGS) -o $@ $<
$(bin_RayTracer_OBJECTS): src/stdafx.h.gch
CLEANFILES = src/stdafx.h.gch
