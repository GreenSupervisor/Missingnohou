#
# Makefile taken from Ubuntu Forums User "dwhitney67" (http://ubuntuforums.org/showthread.php?t=1204739)
#


APP      = Missingnohou

SRCEXT   = cpp
SRCDIR   = src
OBJDIR   = obj

SRCS    := $(shell find $(SRCDIR) -name '*.$(SRCEXT)')
SRCDIRS := $(shell find . -name '*.$(SRCEXT)' -exec dirname {} \; | uniq)
OBJS    := $(patsubst %.$(SRCEXT),$(OBJDIR)/%.o,$(SRCS))

DEBUG    = -g
INCLUDES = -I./inc
CFLAGS   = -Wall -pedantic -ansi -c $(DEBUG) $(INCLUDES)
LDFLAGS  =
LIBS = -lsfml-graphics -lsfml-window -lsfml-system


ifeq ($(SRCEXT), cpp)
CC       = $(CXX)
else
CFLAGS  += -std=gnu99
endif

.PHONY: all clean distclean


all: $(APP)

$(APP): buildrepo $(OBJS)
	@mkdir -p `dirname $@`
	@echo "Linking $@..."
	@$(CC) $(OBJS) $(LDFLAGS) $(LIBS) -o $@

$(OBJDIR)/%.o: %.$(SRCEXT)
	@echo "Generating dependencies for $<..."
	@$(call make-depend,$<,$@,$(subst .o,.d,$@))
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) -r $(OBJDIR) $(APP)


buildrepo:
	@$(call make-repo)

define make-repo
   for dir in $(SRCDIRS); \
   do \
	mkdir -p $(OBJDIR)/$$dir; \
   done
endef


# usage: $(call make-depend,source-file,object-file,depend-file)
# define make-depend
#   $(CC) -MM       \
#           -MF $3    \
#                   -MP       \
#                           -MT $2    \
#                                   $(CFLAGS) \
#                                           $1
#                                           endef
